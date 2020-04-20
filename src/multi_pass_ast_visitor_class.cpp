#include "multi_pass_ast_visitor_class.hpp"

namespace fling_hdl
{

MultiPassAstVisitor::MultiPassAstVisitor(AstEtcMap* s_ast_etc_map)
	: _ast_etc_map(s_ast_etc_map)
{
}
MultiPassAstVisitor::~MultiPassAstVisitor()
{
}

int MultiPassAstVisitor::run()
{
	_pass = 0;
	do
	{
		_done = true;

		for (const auto& p: *_ast_etc_map)
		{
			p.second.ast()->accept(this);
		}

		++_pass;
	} while (!done());
}

} // namespace fling_hdl
