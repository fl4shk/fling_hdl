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
ParamOrArgListBase::~ParamOrArgListBase()
{
}
//--------

//--------
DeclParamOrArgList::DeclParamOrArgList(Kind s_kind, OrderVec&& s_order_vec)
	: ParamOrArgListBase(s_kind), _order_vec(move(s_order_vec))
{
}
DeclParamOrArgList::~DeclParamOrArgList()
{
}

DeclParamItemVar::DeclParamItemVar(const Data& s_data, Kind s_kind)
	: VarEtcBase(s_data), _kind(s_kind)
{
}
DeclParamItemVar::~DeclParamItemVar()
{
}

DeclParamItemType::DeclParamItemType(const Typenm& s_typenm, Kind s_kind)
	: Base(), _typenm(s_typenm), _kind(s_kind)
{
}
DeclParamItemType::~DeclParamItemType()
{
}

DeclParamItemModnm::DeclParamItemModnm(Symbol* s_modnm, Kind s_kind)
	: Base(), _modnm(s_modnm), _kind(s_kind)
{
}
DeclParamItemModnm::~DeclParamItemModnm()
{
}

DeclArgItemVar::DeclArgItemVar(const Data& s_data, Kind s_kind)
	: VarEtcBase(s_data), _kind(s_kind)
{
}
DeclArgItemVar::~DeclArgItemVar()
{
}
//--------

//--------
InstParamOrArgList::InstParamOrArgList(Kind s_kind)
	: ParamOrArgListBase(s_kind)
{
}
InstParamOrArgList::~InstParamOrArgList()
{
}

InstParamItemVar::InstParamItemVar(const Data& s_data)
	: VarEtcBase(s_data)
{
}
InstParamItemVar::~InstParamItemVar()
{
}
//--------
} // namespace sym_data

} // namespace fling_hdl
