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
	AstEtcMapPair* _ast_etc_map_pair;
	BigNum _pass;
	bool _done;

public:		// functions
	MultiPassAstVisitor(AstEtcMapPair* s_ast_etc_map_pair);
	virtual ~MultiPassAstVisitor();

	virtual int run();

	GEN_GETTER_BY_CON_REF(pass);
	GEN_GETTER_BY_VAL(done);

protected:		// functions
	virtual bool should_perf_ast_etc_map_move() const;
};

} // namespace fling_hdl


#endif		// src_multi_pass_ast_visitor_class_hpp
