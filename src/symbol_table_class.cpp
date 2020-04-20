#include "symbol_table_class.hpp"

namespace fling_hdl
{

Symbol::Symbol()
{
}
Symbol::Symbol(const string& s_name)
	: _name(s_name)
{
}
Symbol::~Symbol()
{
}


SymbolTable::SymbolTable()
{
}
SymbolTable::~SymbolTable()
{
}

} // namespace fling_hdl
