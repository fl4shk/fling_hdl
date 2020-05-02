#include "sym_data_classes.hpp"

namespace fling_hdl
{

namespace sym_data
{

//--------
ClsOrMxnData::ClsOrMxnData(bool s_is_base, bool s_is_complete,
	SymSet&& s_extends_set)
	: _is_base(s_is_base), _is_complete(s_is_complete),
	_extends_set(move(s_extends_set))
{
}
ClsOrMxnData::ClsOrMxnData(bool s_is_base, bool s_is_complete,
	SymSet&& s_extends_set, AccSpec s_memb_info_acc_spec)
	: _is_base(s_is_base), _is_complete(s_is_complete),
	_extends_set(move(s_extends_set)), _memb_info(s_memb_info_acc_spec)
{
}
ClsOrMxnData::~ClsOrMxnData()
{
}

Mixin::Mixin(const Data& s_data)
	: _data(s_data)
{
}
Mixin::~Mixin()
{
}

Class::Class(const Data& s_data, bool s_is_signed, bool s_is_packed)
	: Mixin(s_data), _is_signed(s_is_signed), _is_packed(s_is_packed)
{
}
Class::~Class()
{
}
//--------

} // namespace sym_data

} // namespace fling_hdl
