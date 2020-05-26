#include "ast_node_duper_class.hpp"
#include "liborangepower_src/make_deferred_restorer_class_define.hpp"

namespace fling_hdl
{

namespace ast
{

//class DeferredRestorer final
//{
//private:		// variables
//	AstNodeDuper* _duper = nullptr;
//	BaseUptr _saved_visit_node;
//public:		// functions
//	inline DeferredRestorer(AstNodeDuper* s_duper)
//		: _duper(s_duper)
//	{
//		_saved_visit_node = move(_duper->_visit_node);
//	}
//	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(DeferredRestorer);
//	inline ~DeferredRestorer()
//	{
//		_duper->_visit_node = move(_saved_visit_node);
//	}
//};

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
inline void AstNodeDuper::_inner_dup_children(BaseUptr& ret_item,
	const BaseUptr& to_dup_item) const
{
	DeferredRestorer deferred_restorer(this);

	_visit_node = _construct(_visit_node.get(), to_dup_item);
	to_dup_item->accept(this);
	ret_item = move(_visit_node);
}
inline void AstNodeDuper::_inner_dup_children(BaseUptrList& ret_item,
	const BaseUptrList& to_dup_item) const
{
	DeferredRestorer deferred_restorer(this);

	for (const auto& item: to_dup_item)
	{
		_visit_node = _construct(_visit_node.get(), item);
		item->accept(this);
		ret_item.push_back(move(_visit_node));
	}
}
//--------

//--------
#define _INNER_BUILD_DATA(item) \
	temp->item = to_dup->item

#define BUILD_DATA(type, ...) \
	void AstNodeDuper::_dup_data(ast::type* to_dup) \
	{ \
		IF(HAS_ARGS(__VA_ARGS__)) \
		( \
			ast::type* temp = static_cast<ast::type*>(_visit_node.get()); \
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
	void AstNodeDuper::_dup_children(ast::type* to_dup) \
	{ \
		IF(HAS_ARGS(__VA_ARGS__)) \
		( \
			ast::type* temp = static_cast<ast::type*>(_visit_node.get()); \
			EVAL(MAP(_INNER_BUILD_CHILDREN, SEMICOLON, __VA_ARGS__)); \
		) \
	}

#include "ast_build_children_macro_calls.hpp"
#undef _INNER_BUILD_CHILDREN
#undef BUILD_CHILDREN
//--------

} // namespace ast

} // namespace fling_hdl
