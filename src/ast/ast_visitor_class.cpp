#include "ast_visitor_class.hpp"
#include "ast_node_classes.hpp"
#include "../liborangepower_src/cpp_magic.hpp"

namespace fling_hdl
{

using namespace ast;

#define _INNER_ACCEPT(item) \
	_inner_accept_children(#item, n->item)
#define ACCEPT(...) \
	EVAL(MAP(_INNER_ACCEPT, SEMICOLON, __VA_ARGS__))

//DeclModule* temp = nullptr;

//--------
void AstVisitor::_inner_accept_children(const string& memb_name, 
	const BaseUptr& node)
{
	//if (temp != nullptr)
	//{
	//	printout("I have temp.\n");
	//}

	if (node)
	{
		_memb_name = memb_name;
		node->accept(this);
	}
}

void AstVisitor::_inner_accept_children(const string& memb_name,
	const BaseUptrList& node_list)
{
	//if (temp != nullptr)
	//{
	//	printout("I have temp.\n");
	//}

	size_t i = 0;
	for (const auto& p: node_list)
	{
		_memb_name = sconcat(memb_name, "[", i, "]");
		p.data->accept(this);
		++i;
	}
}
//--------

#define BUILD_CHILDREN(type, ...) \
	void AstVisitor::_accept_children \
		(type* n) \
	{ \
		IF (HAS_ARGS(__VA_ARGS__)) \
		( \
			ACCEPT(__VA_ARGS__); \
		) \
	}

#include "ast_build_children_macro_calls.hpp"

} // namespace fling_hdl
