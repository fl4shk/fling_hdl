#include "compiler_class.hpp"

namespace fling_hdl
{

Compiler::Compiler(int s_argc, char** s_argv)
	: _argc(s_argc), _argv(s_argv)
{
}

Compiler::~Compiler()
{
}

int Compiler::run()
{
	return 0;
}

} // namespace fling_hdl
