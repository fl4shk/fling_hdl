#ifndef src_ast_param_gen_expander_class_hpp
#define src_ast_param_gen_expander_class_hpp

// src/ast_param_gen_expander_class.hpp

#include "misc_includes.hpp"
#include "symbol_table_class.hpp"
#include "ast_visitor_class.hpp"
#include "pt_visitor_class.hpp"

//namespace fling_hdl
//{
//
//// This class builds up data structures referencing the AST.  It also
//// expands the AST (builds new ones) such that there are no more templates,
//// `gen` statements, or unevaluated `const`s.
////
//// To do this in a memory-efficient way, I believe we want to only generate
//// one template instance per the actual values of the arguments used.  Thus
//// we can use an std::map to store template instances.  How about an
//// std::map for every template definition in the provided source code?
////
//// `map<ast::Base*, map<sym::InstParamArgs*, ast::Base*>>`
//// Honestly, I'd actually like to use weak_ptr's here, but there's no
//// `std::hash` for them from what I can tell.
//class AstParamGenExpander final: public AstVisitor
//{
//public:		// types
//	//// Each state is likely to need multiple passes.
//	//enum class State
//	//{
//	//	// Build initial data structures that simply reference the AST.
//	//	// Also, perform some semantic analysis.  The semantic analysis
//	//	// that we perform here will largely be checking for duplicate
//	//	// symbol identifiers.
//	//	BuildAstRefs,
//
//	//	// Expand AST nodes.  This means eliminating template parameters,
//	//	// `gen`, etc.
//	//	// This stage may also need to include generating more of the data
//	//	// structures that reference the new AST nodes.
//	//	// This may mean that we don't actually need this enum?
//	//	Expand,
//	//};
//
//private:		// variables
//	AstEtcMap* _ast_etc_map = nullptr;
//	SymbolTable* _sym_table = nullptr;
//	BigNum _pass;
//	bool _done;
//
//public:		// functions
//	AstParamGenExpander(AstEtcMap* s_ast_etc_map, SymbolTable* s_sym_table);
//	virtual ~AstParamGenExpander();
//
//	int run();
//
//	GEN_GETTER_BY_CON_REF(pass);
//	GEN_GETTER_BY_VAL(done);
//
//private:		// functions
//	#define GEN_VISIT_FUNCS(name) \
//		virtual void visit##name(ast::name* n);
//	LIST_OF_AST_NODE_CLASSES(GEN_VISIT_FUNCS)
//	#undef GEN_VISIT_FUNCS
//};
//
//} // namespace fling_hdl

#endif		// src_ast_param_gen_expander_class_hpp
