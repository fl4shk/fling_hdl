#include "compiler_class.hpp"

namespace fling_hdl
{

Compiler::Compiler(int s_argc, char** s_argv)
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
	_opt.dot = false;


	OptArg oa;

	do
	{
		oa = OptArg(string(_argv[i]), 2, '-');

		if (oa.valid())
		{
			if (oa.opt() == "--dot")
			{
				_opt.dot = true;
			}
			else if (oa.opt() == "--outdir")
			{
				_opt.outdir = oa.val();
			}
			else
			{
				printerr("Error:  invalid option \"", _argv[i], "\".\n");
				usage();
			}
		}

		++i;
	} while ((i < _argc) && (oa.valid()));

	// If all of the arguments were options
	if (i == _argc)
	{
		usage();
	}

	for (; i<_argc; ++i)
	{
		const string arg(_argv[i]);
		if (filename_set().count(arg) > 0)
		{
			printerr("Warning:  duplicate source filename \"", arg,
				"\".\n");
		}
		else
		{
			_filename_set.insert(arg);
		}
	}
}
Compiler::~Compiler()
{
}
int Compiler::run()
{
	return 0;
}

} // namespace fling_hdl
