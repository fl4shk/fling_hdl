#include "master_class.hpp"

namespace fling_hdl
{

Master::Master(int s_argc, char** s_argv)
	: _argc(s_argc), _argv(s_argv)
{
	auto usage = [&]() -> void
	{
		printerr("Usage:  ", _argv[0], " <options> <input files...>");
		exit(1);
	};

	if (_argc < 2)
	{
		usage();
	}

	// Skip the first argument.  We don't need the process name from
	// this point forward.
	int i = 1;

	// Handle options
	{
		OptArg oa;

		do
		{
			const string arg(_argv[i]);
			oa = OptArg(arg, 2, '-');

			if (oa.valid())
			{
				if (oa.opt() == "--dot")
				{
					if (opt().dot)
					{
						oa.warn_dup();
					}
					_opt.dot = true;
				}
				else if (oa.opt() == "--int")
				{
					if (opt().interpret)
					{
						oa.warn_dup
					}
				}
				else if (oa.opt() == "--odir")
				{
					if (opt().out_dir.size() != 0)
					{
						oa.warn_dup();
					}
					_opt.out_dir = oa.val();
				}
				else
				{
					printerr("Error:  invalid option \"", arg, "\".\n");
					usage();
				}
			}

			++i;
		} while ((i < _argc) && (oa.valid()));
	}

	// If all of the arguments were options
	if (i == _argc)
	{
		printerr("Error:  no source files provided.\n");
		usage();
	}
	// If there was no output directory provided.
	else if (opt().out_dir.size() == 0)
	{
		printerr("Error:  no output directory provided",
			"(--odir=<directory>).\n");
		usage();
	}

	for (; i<_argc; ++i)
	{
		const string arg(_argv[i]);

		if (filename_set().count(arg) > 0)
		{
			printerr("Warning:  duplicate source filename \"", arg,
				"\" provided.\n");
		}
		else
		{
			_filename_set.insert(arg);
		}
	}
}
Master::~Master()
{
}
int Master::run()
{
	PtVisitor pt_visitor(&_filename_set);
	pt_visitor.run();
	const auto& ast_etc_map = pt_visitor.ast_etc_map();

	if (opt().dot)
	{
		for (const auto& p: ast_etc_map)
		{
			fs::path idir_path = p.first;
			idir_path.remove_filename();

			const fs::path ofile_path = sconcat(opt().odir, "/", p.first,
				".dot");
			fs::path full_odir_path = ofile_path;
			full_odir_path.remove_filename();
			fs::create_directory(full_odir_path, idir_path);
			AstToDotConverter().convert(ofile_path, p.first, p.second);
		}
	}
	else if (opt().interpret)
	{
		return Interpreter().run(ast_etc_map);
	}
	else
	{
		// Still need to plan out what to do with the initial ASTs.
		printerr("Error:  Unimplemented non-dot output.\n");
		exit(1);
	}

	return 0;
}

} // namespace fling_hdl
