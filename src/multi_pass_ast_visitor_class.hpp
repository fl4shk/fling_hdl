#ifndef src_multi_pass_ast_visitor_class_hpp
#define src_multi_pass_ast_visitor_class_hpp

// src/multi_pass_ast_visitor_class.hpp

#include "misc_includes.hpp"
#include "ast_visitor_class.hpp"
#include "pt_visitor_class.hpp"

namespace fling_hdl
{

class MultiPassAstVisitor: public AstVisitor
{
protected:		// variables
	AstEtcMap* _ast_etc_map = nullptr;
	BigNum _pass;
	bool _done;
public:		// functions
	MultiPassAstVisitor(AstEtcMap* s_ast_etc_map);
	virtual ~MultiPassAstVisitor();

	virtual int run();

	GEN_GETTER_BY_CON_REF(pass);
	GEN_GETTER_BY_VAL(done);
};

} // namespace fling_hdl


#endif		// src_multi_pass_ast_visitor_class_hpp
