#ifndef src_ast_ast_visitor_class_hpp
#define src_ast_ast_visitor_class_hpp

// src/ast/ast_visitor_class.hpp

#include "misc_includes.hpp"

#include "list_of_ast_node_classes_define.hpp"

namespace fling_hdl
{

namespace ast
{

#define X(name) \
	class name;
LIST_OF_AST_NODE_CLASSES(X)
#undef X

class Base;
using BaseSptr = shared_ptr<Base>;
using BaseSptrList = IndCircLinkList<BaseSptr>;

}

class AstVisitor
{
protected:		// variables
	string _memb_name;

public:		// functions
	inline AstVisitor() = default;
	virtual inline ~AstVisitor() = default;

	GEN_GETTER_BY_CON_REF(memb_name);

	#define GEN_VISIT_FUNC(name) \
		virtual void visit##name(ast::name* node) = 0;
	LIST_OF_AST_NODE_CLASSES(GEN_VISIT_FUNC)
	#undef GEN_VISIT_FUNC

private:		// functions
	void _inner_accept_children(const string& memb_name, 
		const ast::BaseSptr& node);

	void _inner_accept_children(const string& memb_name,
		const ast::BaseSptrList& node_list);

protected:		// children acceptor functions
	#define GEN_ACCEPT_CHILDREN(name) \
		void _accept_children(ast::name* n);
	LIST_OF_AST_NODE_CLASSES(GEN_ACCEPT_CHILDREN)
	#undef GEN_ACCEPT_CHILDREN


};

} // namespace fling_hdl

#endif		// src_ast_ast_visitor_class_hpp
