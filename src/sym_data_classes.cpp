#include "sym_data_classes.hpp"

namespace fling_hdl
{

namespace sym_data
{

//--------
Base::Base(const AstBaseWptr& s_defn)
	: _defn(s_defn)
{
}
Base::~Base()
{
}
//--------

//--------
VarEtcData::VarEtcData(const FullType& s_full_type,
	const AstBaseWptr& s_expr)
	: _full_type(s_full_type), _expr(s_expr)
{
}
VarEtcData::~VarEtcData()
{
}

VarEtcBase::VarEtcBase(const AstBaseWptr& s_defn, const Data& s_data)
	: Base(s_defn), _data(s_data)
{
}
VarEtcBase::~VarEtcBase()
{
}
//--------

//--------
VarEtc::VarEtc(const AstBaseWptr& s_defn, const Data& s_data, Kind s_kind)
	: VarEtcBase(s_defn, s_data), _kind(s_kind)
{
}
VarEtc::~VarEtc()
{
}

MembVarEtc::MembVarEtc(const AstBaseWptr& s_defn, const Data& s_data,
	Kind s_kind, AccSpec s_acc_spec)
	: VarEtcBase(s_defn, s_data), _kind(s_kind),
	_acc_spec(s_acc_spec)
{
}
MembVarEtc::~MembVarEtc()
{
}
//--------

//--------
DeclParamItemVar::DeclParamItemVar(const AstBaseWptr& s_defn,
	const Data& s_data, Kind s_kind)
	: VarEtcBase(s_defn, s_data), _kind(s_kind)
{
}
DeclParamItemVar::~DeclParamItemVar()
{
}

DeclParamItemType::DeclParamItemType(const AstBaseWptr& s_defn,
	const FullType& s_full_type, Kind s_kind)
	: Base(s_defn), _full_type(s_full_type), _kind(s_kind)
{
}
DeclParamItemType::~DeclParamItemType()
{
}

DeclParamItemModule::DeclParamItemModule(const AstBaseWptr& s_defn,
	Symbol* s_module, Kind s_kind)
	: Base(s_defn), _module(s_module), _kind(s_kind)
{
}
DeclParamItemModule::~DeclParamItemModule()
{
}

DeclArgItemVar::DeclArgItemVar(const AstBaseWptr& s_defn,
	const Data& s_data, Kind s_kind)
	: VarEtcBase(s_defn, s_data), _kind(s_kind)
{
}
DeclArgItemVar::~DeclArgItemVar()
{
}
//--------

//--------
AliasValue::AliasValue(const AstBaseWptr& s_defn, const Data& s_data)
	: VarEtcBase(s_defn, s_data)
{
}
AliasValue::~AliasValue()
{
}

AliasType::AliasType(const AstBaseWptr& s_defn,
	const FullType& s_full_type)
	: Base(s_defn), _full_type(s_full_type)
{
}
AliasType::~AliasType()
{
}
//--------

} // namespace sym_data

} // namespace fling_hdl
