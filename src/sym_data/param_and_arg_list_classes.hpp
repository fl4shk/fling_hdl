#ifndef src_sym_data_param_and_arg_list_classes_hpp
#define src_sym_data_param_and_arg_list_classes_hpp

// src/sym_data/param_and_arg_list_classes.hpp

#include "../misc_includes.hpp"

namespace fling_hdl
{

namespace sym_data
{

//--------
class ParamOrArgListBase: public Base
{
public:		// types
	enum class Kind
	{
		Param,
		Arg,
	};

protected:		// variables
	Kind _kind;

public:		// functions
	ParamOrArgListBase(Kind s_kind);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(ParamOrArgListBase);
	virtual inline ~ParamOrArgListBase() = default;

	GEN_GETTER_BY_VAL(kind);
};

class ParamItemTypeBase: public Base
{
protected:		// variables
	Typenm _typenm;

public:		// functions
	ParamItemTypeBase(const Typenm& s_typenm);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(ParamItemTypeBase);
	virtual inline ~ParamItemTypeBase() = default;

	GEN_GETTER_BY_CON_REF(typenm);
};

class ParamItemModuleBase: public Base
{
protected:		// variables
	Symbol* _modnm = nullptr;

public:		// functions
	ParamItemModuleBase(Symbol* s_modnm);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(ParamItemModuleBase);
	virtual inline ~ParamItemModuleBase() = default;

	GEN_GETTER_BY_VAL(modnm);
};
//--------

//--------
class DeclParamOrArgList final: public ParamOrArgListBase
{
public:		// types
	using OrderVec = vector<string>;

private:		// variables
	OrderVec _order_vec;

public:		// functions
	DeclParamOrArgList(Kind s_kind, OrderVec&& s_order_vec);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(DeclParamOrArgList);
	virtual inline ~DeclParamOrArgList() = default;

	GEN_GETTER_BY_CON_REF(order_vec);
};

// Specifically, a parameter *variable*
class DeclParamItemVar final: public VarEtcBase
{
public:		// types
	enum class Kind
	{
		Var,
		ParpkVar,
	};

private:		// variables
	Kind _kind;

public:		// functions
	DeclParamItemVar(const Data& s_data, Kind s_kind);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(DeclParamItemVar);
	virtual inline ~DeclParamItemVar() = default;

	GEN_GETTER_BY_VAL(kind);
};

class DeclParamItemType final: public ParamItemTypeBase
{
public:		// types
	enum class Kind
	{
		Type,
		ParpkType,
	};

private:		// variables
	Kind _kind;

public:		// functions
	DeclParamItemType(const Typenm& s_typenm, Kind s_kind);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(DeclParamItemType);
	virtual inline ~DeclParamItemType() = default;

	GEN_GETTER_BY_VAL(kind);
};

class DeclParamItemModule final: public ParamItemModuleBase
{
public:		// types
	enum class Kind
	{
		Module,
		ParpkModule,
	};

private:		// variables
	Kind _kind;

public:		// functions
	DeclParamItemModule(Symbol* s_modnm, Kind s_kind);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(DeclParamItemModule);
	virtual inline ~DeclParamItemModule() = default;

	EVAL(MAP(GEN_GETTER_BY_VAL, SEMICOLON,
		kind));
};

// We only need one class for this.
class DeclArgItemVar final: public VarEtcBase
{
public:		// types
	using Kind = ast::DeclArgList_Item::Kind;

private:		// variables
	Kind _kind;

public:		// functions
	DeclArgItemVar(const Data& s_data, Kind s_kind);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(DeclArgItemVar);
	virtual inline ~DeclArgItemVar() = default;

	GEN_GETTER_BY_VAL(kind);
};
//--------

//--------
class InstParamOrArgList final: public ParamOrArgListBase
{
public:		// functions
	InstParamOrArgList(Kind s_kind);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(InstParamOrArgList);
	virtual inline ~InstParamOrArgList() = default;
};

class InstParamItemVar final: public VarEtcBase
{
public:		// functions
	InstParamItemVar(const Data& s_data);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(InstParamItemVar);
	virtual inline ~InstParamItemVar() = default;
};

class InstParamItemType final: public ParamItemTypeBase
{
public:		// functions
	InstParamItemType(const Typenm& s_typenm);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(InstParamItemType);
	virtual inline ~InstParamItemType() = default;
};

class InstParamItemModule final: public ParamItemModuleBase
{
public:		// functions
	InstParamItemModule(Symbol* s_modnm);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(InstParamItemModule);
	virtual inline ~InstParamItemModule() = default;
};

class InstArgItemVar final: public VarEtcBase
{
public:		// functions
	InstArgItemVar(const Data& s_data);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(InstArgItemVar);
	virtual inline ~InstArgItemVar() = default;
};
//--------

} // namespace sym_data

} // namespace fling_hdl

#endif		// src_sym_data_param_and_arg_list_classes_hpp
