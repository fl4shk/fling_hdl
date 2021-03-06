#include "sym_data_classes.hpp"

namespace fling_hdl
{

namespace sym_data
{

//--------
ParamOrArgListBase::ParamOrArgListBase(Kind s_kind)
	: Base(), _kind(s_kind)
{
}
//--------

//--------
DeclParamOrArgList::DeclParamOrArgList(Kind s_kind, OrderVec&& s_order_vec)
	: ParamOrArgListBase(s_kind), _order_vec(move(s_order_vec))
{
}

DeclParamItemVar::DeclParamItemVar(const Data& s_data, Kind s_kind)
	: VarEtcBase(s_data), _kind(s_kind)
{
}

DeclParamItemType::DeclParamItemType(const Typenm& s_typenm, Kind s_kind)
	: ParamItemTypeBase(s_typenm), _kind(s_kind)
{
}

DeclParamItemModule::DeclParamItemModule(Symbol* s_modnm, Kind s_kind)
	: Base(), _modnm(s_modnm), _kind(s_kind)
{
}

DeclArgItemVar::DeclArgItemVar(const Data& s_data, Kind s_kind)
	: VarEtcBase(s_data), _kind(s_kind)
{
}
//--------

//--------
InstParamOrArgList::InstParamOrArgList(Kind s_kind)
	: ParamOrArgListBase(s_kind)
{
}

InstParamItemVar::InstParamItemVar(const Data& s_data)
	: VarEtcBase(s_data)
{
}

InstParamItemType::InstParamItemType(const Typenm& s_typenm)
	: ParamItemTypeBase(s_typenm)
{
}

InstParamItemModule::InstParamItemModule(Symbol* s_modnm)
	: ParamItemModuleBase(s_modnm)
{
}

InstArgItemVar::InstArgItemVar(const Data& s_data)
	: VarEtcBase(s_data)
{
}
//--------
} // namespace sym_data

} // namespace fling_hdl
