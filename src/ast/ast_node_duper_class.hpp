#ifndef src_ast_ast_node_duper_class_hpp
#define src_ast_ast_node_duper_class_hpp

// src/ast/ast_node_duper_class.hpp

#include "../misc_includes.hpp"
#include "ast_visitor_class.hpp"
#include "ast_node_classes.hpp"

namespace fling_hdl
{

namespace ast
{

class AstNodeDuper: public AstVisitor
{
public:		// types
	using Base = ast::Base;

protected:		// variables
	BaseUptr _dup_ret;

public:		// functions
	inline AstNodeDuper()
	{
	}
	virtual inline ~AstNodeDuper()
	{
	}

	virtual BaseUptr& dup(Base* s_parent, const BaseUptr& to_dup)
	{
		_dup_ret = _construct(s_parent, to_dup);
		to_dup->accept(this);
		return _dup_ret;
	}


protected:		// dup and visitor functions
	//--------
	virtual BaseUptr _construct(Base* s_parent, const BaseUptr& to_dup)
		const;
	virtual inline BaseUptr _construct(BaseUptr& s_parent,
		const BaseUptr& to_dup) const
	{
		return _construct(s_parent.get(), to_dup);
	}
	//--------

	//--------
	virtual void _inner_dup_children(BaseUptr& ret_item,
		const BaseUptr& to_dup_item) const;
	virtual void _inner_dup_children(BaseUptrList& ret_item,
		const BaseUptrList& to_dup_item) const;
	//--------

	//--------
	#define GEN_VISIT_FUNCS(type) \
		virtual inline void visit##type(ast::type* to_dup) \
		{ \
			_dup_data(_dup_ret, to_dup); \
			_dup_children(_dup_ret, to_dup); \
		} \
		virtual void _dup_data(BaseUptr& ret, ast::type* to_dup); \
		virtual void _dup_children(BaseUptr& ret, ast::type* to_dup); 
	LIST_OF_AST_NODE_CLASSES(GEN_VISIT_FUNCS)
	#undef GEN_VISIT_FUNCS
	//--------
};

} // namespace ast

} // namespace fling_hdl

#endif		// src_ast_ast_node_duper_class_hpp
