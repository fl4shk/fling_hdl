#include "symbol_table_builder_class.hpp"

namespace fling_hdl
{

SymbolTableBuilder::SymbolTableBuilder(AstEtcMap* s_ast_etc_map)
	: MultiPassAstVisitor(s_ast_etc_map)
{
}
SymbolTableBuilder::~SymbolTableBuilder()
{
}

} // namespace fling_hdl
