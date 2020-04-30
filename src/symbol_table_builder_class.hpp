#ifndef src_symbol_table_builder_class_hpp
#define src_symbol_table_builder_class_hpp

// src/symbol_table_builder_class.hpp

#include "misc_includes.hpp"
#include "symbol_table_class.hpp"
#include "multi_pass_ast_visitor_class.hpp"

namespace fling_hdl
{

// This class owns the SymbolTable.  It also builds or modifies the it.
// This is done based upon the AST.
// Does this take only one pass?
class SymbolTableBuilder final: public MultiPassAstVisitor
{
public:		// types

private:		// variables
	SymbolTable _sym_table;

public:		// functions
	SymbolTableBuilder(AstEtcMapPair* s_ast_etc_map_pair);
	~SymbolTableBuilder();

	GEN_GETTER_BY_CON_REF(sym_table);

private:		// functions
	virtual bool should_perf_ast_etc_map_move() const;

	#define GEN_VISIT_FUNCS(name) \
		virtual void visit##name(ast::name* n) \
		{ \
			_build_sym_table(n); \
			_accept_children(n); \
		} \
		void _build_sym_table(ast::name* n);
	LIST_OF_AST_NODE_CLASSES(GEN_VISIT_FUNCS)
	#undef GEN_VISIT_FUNCS
};

} // namespace fling_hdl

#endif		// src_symbol_table_builder_class_hpp
