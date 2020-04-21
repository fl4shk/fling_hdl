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
VarEtcBase::VarEtcBase(const AstBaseWptr& s_defn, TypeKind s_type_kind,
	Symbol* s_type, const AstBaseWptr& s_expr)
	: Base(s_defn), _type_kind(s_type_kind),  _type(s_type), _expr(s_expr)
{
}
VarEtcBase::~VarEtcBase()
{
}
//--------

//--------
VarEtc::VarEtc(const AstBaseWptr& s_defn, TypeKind s_type_kind,
	Symbol* s_type, const AstBaseWptr& s_expr, Kind s_kind)
	: VarEtcBase(s_defn, s_type_kind, s_type, s_expr), _kind(s_kind)
{
}
VarEtc::~VarEtc()
{
}

MembVarEtc::MembVarEtc(const AstBaseWptr& s_defn, TypeKind s_type_kind,
	Symbol* s_type, const AstBaseWptr& s_expr, Kind s_kind,
	AccSpec s_acc_spec, bool s_is_static)
	: VarEtcBase(s_defn, s_type_kind, s_type, s_expr), _kind(s_kind),
	_acc_spec(s_acc_spec), _is_static(s_is_static)
{
}
MembVarEtc::~MembVarEtc()
{
}
//--------

//--------
DeclParamItemVar::DeclParamItemVar(const AstBaseWptr& s_defn,
	TypeKind s_type_kind, Symbol* s_type, const AstBaseWptr& s_expr,
	Kind s_kind)
	: VarEtcBase(s_defn, s_type_kind, s_type, s_expr), _kind(s_kind)
{
}
DeclParamItemVar::~DeclParamItemVar()
{
}

DeclParamItemType::DeclParamItemType(const AstBaseWptr& s_defn,
	TypeKind s_type_kind, Symbol* s_type, Kind s_kind)
	: Base(s_defn), _type_kind(s_type_kind), _type(s_type), _kind(s_kind)
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
	TypeKind s_type_kind, Symbol* s_type, const AstBaseWptr& s_expr,
	Kind s_kind)
	: VarEtcBase(s_defn, s_type_kind, s_type, s_expr), _kind(s_kind)
{
}
DeclArgItemVar::~DeclArgItemVar()
{
}
//--------

} // namespace sym_data

} // namespace fling_hdl
