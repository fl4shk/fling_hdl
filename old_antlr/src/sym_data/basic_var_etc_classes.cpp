#include "sym_data_classes.hpp"

namespace fling_hdl
{

namespace sym_data
{

//--------
VarEtcBase::VarEtcBase(const Data& s_data)
	: Base(), _data(s_data)
{
}
VarEtcBase::VarEtcBase(const Data& s_data,
	AccSpec s_memb_info_acc_spec)
	: Base(), _data(s_data), _memb_info(s_memb_info_acc_spec)
{
}
//--------

//--------
VarEtc::VarEtc(const Data& s_data, Kind s_kind)
	: VarEtcBase(s_data), _kind(s_kind)
{
}
VarEtc::VarEtc(const Data& s_data, AccSpec s_acc_spec, Kind s_kind)
	: VarEtcBase(s_data, s_acc_spec), _kind(s_kind)
{
}
//--------

} // namespace sym_data

} // namespace fling_hdl
