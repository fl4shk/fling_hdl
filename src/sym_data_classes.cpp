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
Typenm::Typenm(Symbol* s_partial_typenm, Kind s_kind)
	: _partial_typenm(s_partial_typenm), _kind(s_kind)
{
}
Typenm::~Typenm()
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

//--------
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
	const Typenm& s_typenm, Kind s_kind)
	: Base(s_defn), _typenm(s_typenm), _kind(s_kind)
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
	const Typenm& s_typenm)
	: Base(s_defn), _typenm(s_typenm)
{
}
AliasType::~AliasType()
{
}

AliasModule::AliasModule(const AstBaseWptr& s_defn, Symbol* s_module)
	: Base(s_defn), _module(s_module)
{
}
AliasModule::~AliasModule()
{
}
//--------

} // namespace sym_data

} // namespace fling_hdl
