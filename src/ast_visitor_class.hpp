#ifndef src_ast_visitor_class_hpp
#define src_ast_visitor_class_hpp

// src/ast_visitor_class.hpp

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

};

class AstVisitor
{
public:		// functions
	inline AstVisitor() = default;
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(AstVisitor);
	virtual inline ~AstVisitor() = default;

	#define GEN_VISIT_FUNC(name) \
		virtual void visit##name(ast::name* node) = 0;
	LIST_OF_AST_NODE_CLASSES(GEN_VISIT_FUNC)
	#undef GEN_VISIT_FUNC


};

} // namespace fling_hdl

#endif		// src_ast_visitor_class_hpp
