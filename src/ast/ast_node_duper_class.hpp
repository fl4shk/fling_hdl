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
	friend class DeferredRestorer;

	class DeferredRestorer final
	{
	private:		// variables
		AstNodeDuper* _duper = nullptr;
		BaseUptr _saved_visit_node;
	public:		// functions
		inline DeferredRestorer(AstNodeDuper* s_duper)
			: _duper(s_duper)
		{
			_saved_visit_node = move(_duper->_visit_node);
		}
		GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(DeferredRestorer);
		inline ~DeferredRestorer()
		{
			_duper->_visit_node = move(_saved_visit_node);
		}
	};

protected:		// variables
	BaseUptr _visit_node;

public:		// functions
	inline AstNodeDuper()
	{
	}
	virtual inline ~AstNodeDuper()
	{
	}

	virtual BaseUptr& dup(Base* s_parent, const BaseUptr& to_dup)
	{
		_visit_node = _construct(s_parent, to_dup);
		to_dup->accept(this);
		return _visit_node;
	}


protected:		// dup and visitor functions
	//--------
	virtual BaseUptr _construct(Base* s_parent, const BaseUptr& to_dup)
		const;
	//--------

	//--------
	virtual inline void _inner_dup_children(BaseUptr& ret_item,
		const BaseUptr& to_dup_item);
	virtual inline void _inner_dup_children(BaseUptrList& ret_item,
		const BaseUptrList& to_dup_item);
	//--------

	//--------
	#define GEN_VISIT_FUNCS(type) \
		virtual inline void visit##type(ast::type* to_dup) \
		{ \
			_dup_data(to_dup); \
			_dup_children(to_dup); \
		} \
		virtual void _dup_data(ast::type* to_dup); \
		virtual void _dup_children(ast::type* to_dup); 
	LIST_OF_AST_NODE_CLASSES(GEN_VISIT_FUNCS)
	#undef GEN_VISIT_FUNCS
	//--------
};

} // namespace ast

} // namespace fling_hdl

#endif		// src_ast_ast_node_duper_class_hpp
