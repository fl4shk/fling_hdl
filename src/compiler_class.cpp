#include "src/compiler_class.hpp"

namespace fling_hdl
{

Compiler::Compiler(FlingHdlGrammarParser& parser)
{
	_program_ctx = parser.flingProgram();
}
int Compiler::run()
{
	return 0;
}

} // namespace fling_hdl
