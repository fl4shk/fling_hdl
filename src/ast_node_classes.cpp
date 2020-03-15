#include "ast_node_classes.hpp"
#include "ast_visitor_class.hpp"

namespace fling_hdl
{

namespace ast
{

#define BUILD_ACCEPT(name) \
void name::accept(AstVisitor& visitor) \
{ \
	const string egg = #name; \
}

} // namespace ast

} // namespace fling_hdl
