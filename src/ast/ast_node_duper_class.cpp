#include "ast_node_duper_class.hpp"

namespace fling_hdl
{

namespace ast
{

//--------
BaseUptr AstNodeDuper::_construct(Base* s_parent, const BaseUptr& to_dup)
	const
{
	#define X(type) \
		if (to_dup->id() == #type) \
		{ \
			return BaseUptr(new type(s_parent, to_dup->fp())); \
		}
	LIST_OF_AST_NODE_CLASSES(X)
	#undef X

	return BaseUptr(nullptr);
}
//--------


//--------
void AstNodeDuper::_inner_dup_children(BaseUptr& ret_item,
	const BaseUptr& to_dup_item) const
{
}
void AstNodeDuper::_inner_dup_children(BaseUptrList& ret_item,
	const BaseUptrList& to_dup_item) const
{
}
//--------





//--------
#define _INNER_BUILD_DATA(item) \
	temp->item = to_dup->item

#define BUILD_DATA(type, ...) \
	void AstNodeDuper::_dup_data(BaseUptr& ret, ast::type* to_dup) \
	{ \
		IF(HAS_ARGS(__VA_ARGS__)) \
		( \
			ast::type* temp = static_cast<ast::type*>(ret.get()); \
			EVAL(MAP(_INNER_BUILD_DATA, SEMICOLON, __VA_ARGS__)); \
		) \
	}

#include "ast_build_data_macro_calls.hpp"
#undef _INNER_BUILD_DATA
#undef BUILD_DATA
//--------

//--------
#define _INNER_BUILD_CHILDREN(item) \
	_inner_dup_children(temp->item, to_dup->item)

#define BUILD_CHILDREN(type, ...) \
	void AstNodeDuper::_dup_children(BaseUptr& ret, \
		ast::type* to_dup) \
	{ \
		IF(HAS_ARGS(__VA_ARGS__)) \
		( \
			ast::type* temp = static_cast<ast::type*>(ret.get()); \
			EVAL(MAP(_INNER_BUILD_CHILDREN, SEMICOLON, __VA_ARGS__)); \
		) \
	}

#include "ast_build_children_macro_calls.hpp"
#undef _INNER_BUILD_CHILDREN
#undef BUILD_CHILDREN
//--------

} // namespace ast

} // namespace fling_hdl
