#ifndef src_sem_analyzer_and_eval_class_hpp
#define src_sem_analyzer_and_eval_class_hpp

// src/sem_analyzer_and_eval_class.hpp

#include "misc_includes.hpp"
#include "sym_classes.hpp"
#include "ast_visitor_class.hpp"
#include "pt_visitor_class.hpp"

namespace fling_hdl
{

class SemAnalyzerAndEval final: public AstVisitor
{
protected:		// variables
	AstEtcMap* _ast_etc_map = nullptr;

public:		// functions
	SemAnalyzerAndEval(AstEtcMap* s_ast_etc_map);
	virtual ~SemAnalyzerAndEval();

protected:		// functions
	#define GEN_VISIT_FUNCS(name) \
		virtual void visit##name(ast::name* n);
	LIST_OF_AST_NODE_CLASSES(GEN_VISIT_FUNCS)
	#undef GEN_VISIT_FUNCS
};

} // namespace fling_hdl

#endif		// src_sem_analyzer_and_eval_class_hpp
