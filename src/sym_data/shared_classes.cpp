#include "sym_data_classes.hpp"

namespace fling_hdl
{

namespace sym_data
{

//--------
Base::Base()
{
}
Base::~Base()
{
}
//--------

//--------
Typenm::Typenm(Symbol* s_partial_typenm, Kind s_kind)
	: _partial_typenm(s_partial_typenm), _kind(s_kind)
{
}
Typenm::~Typenm()
{
}

MembInfo::MembInfo()
{
}
MembInfo::MembInfo(AccSpec s_acc_spec)
	: _is_memb(true), _acc_spec(s_acc_spec)
{
}
MembInfo::~MembInfo()
{
}

VarEtcData::VarEtcData(const Typenm& s_typenm,
	const AstBaseWptr& s_expr)
	: _typenm(s_typenm), _expr(s_expr)
{
}
VarEtcData::~VarEtcData()
{
}
//--------

} // namespace sym_data

} // namespace fling_hdl
