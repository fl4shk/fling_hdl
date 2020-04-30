#ifndef src_single_pass_ast_visitor_class_hpp
#define src_single_pass_ast_visitor_class_hpp

// src/single_pass_ast_visitor_class.hpp

#include "misc_includes.hpp"
#include "ast_visitor_class.hpp"
#include "pt_visitor_class.hpp"

namespace fling_hdl
{

class SinglePassAstVisitor: public AstVisitor
{
protected:		// variables
	AstEtcMap* _ast_etc_map = nullptr;

public:		// functions
	SinglePassAstVisitor(AstEtcMap* s_ast_etc_map);
	virtual ~SinglePassAstVisitor();

	virtual int run();
};

} // namespace fling_hdl


#endif		// src_single_pass_ast_visitor_class_hpp
