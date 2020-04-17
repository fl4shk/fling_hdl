#include "master_class.hpp"
//#include "interpreter_class.hpp"

namespace fling_hdl
{

Master::Master(int s_argc, char** s_argv)
	: _argc(s_argc), _argv(s_argv)
{
	if (_argc < 2)
	{
		_usage();
	}

	// Skip the first argument.  We don't need the process name from
	// this point forward.
	int i = 1;

	// Handle options
	{
		OptArg oa;

		_opt = Opt();

		using RunType = Opt::RunType;

		auto handle_run_type_opt = [&](const RunType& run_type,
			int need_val) -> void
		{
			if (opt().run_type != RunType::OutVerilog)
			{
				if (opt().run_type == run_type)
				{
					printerr("Error:  ", oa.errwarn_msg_dup(),
						"\n");
				}
				else
				{
					printerr("Error:  run type is already set.\n");
				}
				_usage();
			}

			if ((need_val > 0) && (oa.val().size() == 0))
			{
				printerr("Error:  ", oa.errwarn_msg_no_val(), "\n");
				_usage();
			}
			else if ((need_val < 0) && (oa.val().size() != 0))
			{
				printerr("Error:  ", oa.errwarn_msg_has_val(), "\n");
				_usage();
			}
			// else if (need_val == 0) we can take a value for this
			// option, but we don't require it.

			_opt.run_type = run_type;
		};

		do
		{
			const string arg(_argv[i]);
			oa = OptArg(arg, 2, '-');

			if (oa.valid())
			{
				if (oa.opt() == "--odir")
				{
					if (opt().out_dir.size() != 0)
					{
						printerr("Error:  ", oa.errwarn_msg_dup(), "\n");
						_usage();
					}
					else if (oa.val().size() == 0)
					{
						printerr("Error:  ", oa.errwarn_msg_no_val(),
							"\n");
						_usage();
					}
					_opt.out_dir = oa.val();
				}
				else if (oa.opt() == "--top")
				{
					if (opt().top_ident.size() != 0)
					{
						printerr("Error:  ", oa.errwarn_msg_dup(), "\n");
						_usage();
					}
					else if (oa.val().size() == 0)
					{
						printerr("Error:  ", oa.errwarn_msg_no_val(),
							"\n");
						_usage();
					}
					_opt.top_ident = oa.val();
				}
				else if (oa.opt() == "--dot")
				{
					handle_run_type_opt(RunType::OutDot, -1);
					_opt.need_top_ident = false;
				}
				else if (oa.opt() == "--int")
				{
					handle_run_type_opt(RunType::Interpret, -1);

					_opt.need_out_dir = false;

					for (size_t i=0; i<opt().top_ident.size(); ++i)
					{
						const auto& c = opt().top_ident.at(i);
						if (!(isalnum(c) || (c == '_')))
						{
							printerr("Error:  Global function identifier ",
								"required for option \"", oa.opt(),
								"\".\n");
							_usage();
						}
					}
				}
				else
				{
					printerr("Error:  invalid option \"", arg, "\".\n");
					// TODO:  Add `--help` option.
					//printerr("Perhaps run this command:  ", _argv[0], 
					//	" --help\n");
					_usage();
				}
				++i;
			}

		} while ((i < _argc) && (oa.valid()));
	}

	// If all of the arguments were options
	if (i == _argc)
	{
		printerr("Error:  no source files provided.\n");
		_usage();
	}
	// If there was no output directory provided.
	if (opt().need_out_dir && (opt().out_dir.size() == 0))
	{
		printerr("Error:  no output directory provided ",
			"(--odir=<directory>).\n");
		_usage();
	}
	// If there was no top identifier provided.
	if (opt().need_top_ident && (opt().top_ident.size() == 0))
	{
		printerr("Error:  no top identifier provided ",
			"(--top=<module_name,func_name,etc.>).\n");
		_usage();
	}

	for (; i<_argc; ++i)
	{
		const string arg(_argv[i]);

		if (src_filename_set().count(arg) > 0)
		{
			printerr("Warning:  duplicate source filename \"", arg,
				"\" provided.\n");
		}
		else
		{
			_src_filename_set.insert(arg);
		}
	}
}
Master::~Master()
{
}
int Master::run()
{
	PtVisitor pt_visitor(&_src_filename_set);
	pt_visitor.run();
	const auto& ast_etc_map = pt_visitor.ast_etc_map();

	using RunType = Opt::RunType;

	if (opt().run_type == RunType::OutDot)
	{
		_create_ofile_dirs(".dot", ast_etc_map);

		for (const auto& p: _src_filename_to_dst_filename_map)
		{
			AstToDotConverter().convert(p.second, ast_etc_map.at(p.first));
		}
	}
	else if (opt().run_type == RunType::Interpret)
	{
		//return Interpreter(&pt_visitor).run();
	}
	else // if (opt().run_type == RunType::OutVerilog)
	{
		// Still need to plan out what to do with the initial ASTs.
		printerr("Error:  Unimplemented Verilog output mode.\n");
		_usage();
	}

	return 0;
}
void Master::_create_ofile_dirs(const string& ofile_ext,
	const AstEtcMap& ast_etc_map)
{
	for (const auto& p: ast_etc_map)
	{
		_src_filename_to_dst_filename_map[p.first]
			= opt().create_ofile_dirs(p.first, ofile_ext);
	}
}

} // namespace fling_hdl
