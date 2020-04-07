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

	if (argc < 2)
	{
		usage();
	}

	// Skip the first argument.  We don't need the process name from
	// this point forward.
	char** arg = _argv + 1;

	// Handle options
	_opt.dot = false;


	OptArg oa;
	do
	{
		oa = OptArg(string(*arg), 2, "--");

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
				usage();
			}
		}
	} while (oa.valid());
}
Compiler::~Compiler()
{
}
int Compiler::run()
{
	return 0;
}

} // namespace fling_hdl
