#include "multi_pass_ast_visitor_class.hpp"

namespace fling_hdl
{

MultiPassAstVisitor::MultiPassAstVisitor(AstEtcMapPair* s_ast_etc_map_pair)
	: _ast_etc_map_pair(s_ast_etc_map_pair)
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

		if (should_perf_ast_etc_map_move())
		{
			_ast_etc_map_pair->first = move(_ast_etc_map_pair->second);
		}

		for (const auto& p: _ast_etc_map_pair->first)
		{
			p.second.ast()->accept(this);
		}

		++_pass;
	} while (!done());
}

bool MultiPassAstVisitor::should_perf_ast_etc_map_move() const
{
	return true;
}

} // namespace fling_hdl
