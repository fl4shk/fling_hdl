#include "single_pass_ast_visitor_class.hpp"

namespace fling_hdl
{

SinglePassAstVisitor::SinglePassAstVisitor(AstEtcMap* s_ast_etc_map)
	: _ast_etc_map(s_ast_etc_map)
{
}
SinglePassAstVisitor::~SinglePassAstVisitor()
{
}

int SinglePassAstVisitor::run()
{
	for (const auto& p: *_ast_etc_map)
	{
		p.second.ast()->accept(this);
	}
}

} // namespace fling_hdl
