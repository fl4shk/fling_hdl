#include "sym_data_classes.hpp"

namespace fling_hdl
{

namespace sym_data
{

//--------
AliasValue::AliasValue(const Data& s_data)
	: VarEtcBase(s_data)
{
}
AliasValue::AliasValue(const Data& s_data, AccSpec s_memb_info_acc_spec)
	: VarEtcBase(s_data, s_memb_info_acc_spec)
{
}

AliasType::AliasType(const Typenm& s_typenm)
	: Base(), _typenm(s_typenm)
{
}
AliasType::AliasType(const Typenm& s_typenm, AccSpec s_memb_info_acc_spec)
	: Base(), _typenm(s_typenm), _memb_info(s_memb_info_acc_spec)
{
}

AliasModule::AliasModule(Symbol* s_modnm)
	: Base(), _modnm(s_modnm)
{
}
AliasModule::AliasModule(Symbol* s_modnm, AccSpec s_memb_info_acc_spec)
	: Base(), _modnm(s_modnm), _memb_info(s_memb_info_acc_spec)
{
}
//--------

} // namespace sym_data

} // namespace fling_hdl
