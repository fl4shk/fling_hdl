#include "ast_flattener_class.hpp"
#include "ast_node_classes.hpp"

namespace fling_hdl
{

using namespace ast;

AstFlattener::AstFlattener(AstEtcMap* s_ast_etc_map)
	: _ast_etc_map(s_ast_etc_map)
{
}
AstFlattener::~AstFlattener()
{
}

void AstFlattener::visitProgram(Program* n)
{
}

} // namespace fling_hdl
