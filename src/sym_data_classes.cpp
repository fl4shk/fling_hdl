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
VarEtcBase::~VarEtcBase()
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
VarEtc::~VarEtc()
{
}
//--------

//--------
DeclParamOrArgList::DeclParamOrArgList(Kind s_kind, OrderVec&& s_order_vec)
	: Base(), _kind(s_kind), _order_vec(move(s_order_vec))
{
}
DeclParamOrArgList::~DeclParamOrArgList()
{
}
//--------

//--------
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

DeclParamItemModule::DeclParamItemModule(Symbol* s_module, Kind s_kind)
	: Base(), _module(s_module), _kind(s_kind)
{
}
DeclParamItemModule::~DeclParamItemModule()
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
AliasValue::AliasValue(const Data& s_data)
	: VarEtcBase(s_data)
{
}
AliasValue::AliasValue(const Data& s_data, AccSpec s_memb_info_acc_spec)
	: VarEtcBase(s_data, s_memb_info_acc_spec)
{
}
AliasValue::~AliasValue()
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
AliasType::~AliasType()
{
}

AliasModule::AliasModule(Symbol* s_module)
	: Base(), _module(s_module)
{
}
AliasModule::AliasModule(Symbol* s_module, AccSpec s_memb_info_acc_spec)
	: Base(), _module(s_module), _memb_info(s_memb_info_acc_spec)
{
}
AliasModule::~AliasModule()
{
}
//--------

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

//--------
Scope::Scope()
	: Base()
{
}
Scope::~Scope()
{
}

Package::Package()
	: Scope()
{
}
Package::~Package()
{
}
//--------

//--------
Module::Module()
	: Base()
{
}
Module::~Module()
{
}

InstModule::InstModule(Symbol* s_module)
	: Base(), _module(s_module)
{
}
InstModule::~InstModule()
{
}
//--------

} // namespace sym_data

} // namespace fling_hdl
