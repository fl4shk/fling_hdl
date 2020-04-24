#include "symbol_table_class.hpp"

namespace fling_hdl
{

//--------
Symbol::Symbol()
{
}
Symbol::Symbol(const string& s_name, const AstBaseWptr& s_defn,
	SymbolTable* s_parent)
	: _name(s_name), _defn(s_defn), _parent(s_parent)
{
}
Symbol::~Symbol()
{
}

SymbolTable* Symbol::scope() const
{
	return parent()->scope_table().at(name()).get();
}
SymTableMap* Symbol::linked_scope_table() const
{
	return parent()->linked_scope_table_map().at(name()).get();
}
string Symbol::full_name() const
{
}
//--------

//--------
SymbolTable::SymbolTable(SymbolTable* s_parent)
	: _parent(s_parent)
{
}
SymbolTable::~SymbolTable()
{
}

Symbol* SymbolTable::insert(const string& s_name,
	const AstBaseWptr& s_defn, bool create_scope,
	bool create_linked_scope_table)
{
	_local_table[s_name] = unique_ptr<Symbol>(new Symbol
		(s_name, s_defn, this));

	if (create_scope)
	{
		_scope_table[s_name] = unique_ptr<SymbolTable>
			(new SymbolTable(this));
	}

	if (create_linked_scope_table)
	{
		_linked_scope_table_map[s_name] = unique_ptr<SymTableMap>
			(new SymTableMap());
	}

	return _local_table.at(s_name).get();
}

Symbol* SymbolTable::find(const string& name) const
{
	if (_local_table.contains(name))
	{
		return _local_table.at(name).get();
	}
	else if (_parent != nullptr)
	{
		return _parent->find(name);
	}
	else
	{
		return nullptr;
	}
}

string SymbolTable::pkg_scope_seq(const vector<string>& vec)
{
	string ret;

	for (size_t i=0; i<vec.size(); ++i)
	{
		ret += vec.at(i);

		if ((i + 1) != vec.size())
		{
			ret += "::";
		}
	}

	return ret;
}

//--------

} // namespace fling_hdl
