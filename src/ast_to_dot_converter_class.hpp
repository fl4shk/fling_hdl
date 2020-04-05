#ifndef src_ast_to_dot_converter_class_hpp
#define src_ast_to_dot_converter_class_hpp

// src/ast_to_dot_converter_class.hpp

#include "misc_includes.hpp"
#include "ast_visitor_class.hpp"
#include "ast_node_classes.hpp"

namespace fling_hdl
{

class AstToDotConverter: public AstVisitor
{
protected:		// variables
	fstream _file;
public:		// functions
	inline AstToDotConverter() = default;
	virtual ~AstToDotConverter() = default;

	virtual void convert(const string& dst_filename,
		const string& src_filename, ast::Base* root);

	#define GEN_VISIT_FUNC(name) \
		virtual void visit##name(ast::name* node);
	LIST_OF_AST_NODE_CLASSES(GEN_VISIT_FUNC)
	#undef GEN_VISIT_FUNC

protected:		// functions


	//virtual void _print_node(const string& node, const string& lab);
	//virtual void _print_connect();
};

} // namespace fling_hdl


#endif		// src_ast_to_dot_converter_class_hpp
