#include "ast_param_gen_expander_class.hpp"
#include "ast_node_classes.hpp"

namespace fling_hdl
{

using namespace ast;

//AstParamGenExpander::AstParamGenExpander(AstEtcMap* s_ast_etc_map,
//	SymbolTable* s_sym_table)
//	: _ast_etc_map(s_ast_etc_map), _sym_table(s_sym_table)
//{
//}
//AstParamGenExpander::~AstParamGenExpander()
//{
//}
//
//int AstParamGenExpander::run()
//{
//	_pass = 0;
//	do
//	{
//		_done = true;
//
//		for (const auto& p: *_ast_etc_map)
//		{
//			p.second.ast()->accept(this);
//		}
//
//		++_pass;
//	} while (!done());
//}

} // namespace fling_hdl
