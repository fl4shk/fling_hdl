#ifndef src_symbol_table_class_hpp
#define src_symbol_table_class_hpp

// src/symbol_table_class.hpp

#include "misc_includes.hpp"
#include "sym_data_classes.hpp"

namespace fling_hdl
{

class Symbol final
{
private:		// variables
	string _name;

	//optional<variant
	//	<sym_data::Wire, sym_data::LocalVar, sym_data::LocalConst,
	//	sym_data::MembVar, sym_data::MembConst>> _data;

public:		// functions
	Symbol();
	Symbol(const string& s_name);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Symbol);
	~Symbol();

};


class SymbolTable final
{
public:		// types
private:		// variables
public:		// functions
	SymbolTable();
	GEN_MOVE_ONLY_CONSTRUCTORS_AND_ASSIGN(SymbolTable);
	~SymbolTable();
};

} // namespace fling_hdl

#endif		// src_symbol_table_class_hpp
