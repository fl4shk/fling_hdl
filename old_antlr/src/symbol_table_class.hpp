#ifndef src_symbol_table_class_hpp
#define src_symbol_table_class_hpp

// src/symbol_table_class.hpp

#include "misc_includes.hpp"
#include "sym_data/sym_data_classes.hpp"
#include "sym_data/list_of_sym_data_classes_define.hpp"
#include "ast_node_classes.hpp"

namespace fling_hdl
{

class SymbolTable;

using SymTableMap = map<string, SymbolTable*>;

//--------
class Symbol final
{
public:		// types
	using AstBaseWptr = ast::BaseWptr;

private:		// variables
	string _name;

	// This is just a reference to the definition of the Symbol.
	AstBaseWptr _defn;

	SymbolTable* _parent = nullptr;

	//// Map from some sort of instantiated parameter and argument list to
	//// the 
	//map<sym_data::InstParamAndArgLists, Symbol*> _impl_map;

	//optional<variant
	//	<sym_data::Wire, sym_data::LocalVar, sym_data::LocalConst,
	//	sym_data::MembVar, sym_data::MembConst>> _data;

public:		// functions
	Symbol();
	Symbol(const string& s_name, const AstBaseWptr& s_defn,
		SymbolTable* s_parent);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Symbol);
	inline ~Symbol() = default;

	SymbolTable* scope() const;
	SymTableMap* imported_scope_table() const;

	string full_name() const;

	GEN_GETTER_BY_CON_REF(name);

	EVAL(MAP(GEN_GETTER_BY_VAL, SEMICOLON,
		parent));

	//GEN_GETTERS_BY_CON_REF_AND_REF(data);

private:		// functions
	#define GEN_INNER_FULL_NAME(name) \
		string _inner_full_name(const sym_data::name& d) const;
	LIST_OF_SYM_DATA_CLASSES(GEN_INNER_FULL_NAME)
	#undef GEN_INNER_FULL_NAME
};
//--------

//--------
class SymbolTable final
{
	friend class Symbol;

public:		// types
	using AstBaseWptr = ast::BaseWptr;

	// All scopes besides the global scope have names.
	using LocalSymTable = map<string, unique_ptr<Symbol>>;

	// This is where the scope of a `Symbol` gets stored.
	// See also `Symbol::scope()`, which returns this.
	using ScopeTable = map<string, unique_ptr<SymbolTable>>;

	// This is used for imported packages.
	using ImportedScopeTableMap = map<string, unique_ptr<SymTableMap>>;

private:		// variables
	// This is unused for the global scope.
	//string _name;
	SymbolTable* _parent;

	LocalSymTable _local_table;
	ScopeTable _scope_table;
	ImportedScopeTableMap _imported_scope_table_map;

public:		// functions
	SymbolTable(SymbolTable* s_parent=nullptr);
	GEN_MOVE_ONLY_CONSTRUCTORS_AND_ASSIGN(SymbolTable);
	inline ~SymbolTable() = default;

	// Insert a new `Symbol` into this `SymbolTable`, possibly creating a
	// scope and/or a linked scope table for it.
	Symbol* insert(const string& s_name, const AstBaseWptr& s_defn,
		bool create_scope=false,
		bool create_imported_scope_table=false);

	// This is kept simple, looking up only *one* name, and not some more
	// complex named scopes lookup.  As such, if `alu_pkg::Bus<WIDTH>` is
	// wanted to be looked up, `alu_pkg` is all you can start with when
	// using this function.  Multiple uses of `SymbolTable::find()` will
	// need to be performed.
	Symbol* find(const string& s_name) const;

	static string pkg_scope_seq(const vector<string>& vec);

	GEN_GETTER_BY_VAL(parent);

	EVAL(MAP(GEN_GETTER_BY_CON_REF, SEMICOLON,
		local_table,
		scope_table,
		imported_scope_table_map));
};
//--------


} // namespace fling_hdl

#endif		// src_symbol_table_class_hpp
