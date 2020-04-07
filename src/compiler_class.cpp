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

	auto check_substr = [&](const string& s, const string& substr)
		-> string
	{
	}

	// Handle options
	for (char** arg=argv;
		(arg[0]=='-') && (arg[1]=='-');
		++arg)
	{
		const string s_arg(arg);

		if (auto s == "--dot")
		{
			_opt.dot = 1;
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
