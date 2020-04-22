#ifndef src_sym_data_classes_hpp
#define src_sym_data_classes_hpp

// src/sym_data_classes.hpp

#include "misc_includes.hpp"
#include "ast_node_classes.hpp"

namespace fling_hdl
{

class Symbol;

namespace sym_data
{

//--------
class Base
{
public:		// types
	using AstBaseWptr = ast::BaseWptr;

protected:		// variables
	// This is just a reference to the definition of the Symbol.
	AstBaseWptr _defn;

public:		// functions
	Base(const AstBaseWptr& s_defn);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Base);
	virtual ~Base();

	GEN_GETTER_BY_CON_REF(defn);
};
//--------

//--------
class Typenm final
{
public:		// types
	enum class Kind
	{
		Regular,
		Dyn,
		Weakref,
	};

private:		// variables
	Symbol* _partial_typenm = nullptr;
	Kind _kind = Kind::Regular;

public:		// functions
	Typenm(Symbol* s_partial_typenm, Kind s_kind);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Typenm);
	~Typenm();

	EVAL(MAP(GEN_GETTER_BY_VAL, SEMICOLON,
		partial_typenm,
		kind));
};

class VarEtcData final
{
public:		// types
	using AstBaseWptr = Base::AstBaseWptr;

private:		// variables
	Typenm _typenm;

	// The expression this has been set to.  A `VarEtcBase` will not
	// always have one of these (i.e. it may just contain a `nullptr`).
	AstBaseWptr _expr;

public:		// functions
	VarEtcData(const Typenm& s_typenm, const AstBaseWptr& s_expr);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(VarEtcData);
	~VarEtcData();

	EVAL(MAP(GEN_GETTER_BY_CON_REF, SEMICOLON,
		typenm,
		expr));
};
//--------

//--------
class VarEtcBase: public Base
{
public:		// types
	using Data = VarEtcData;

protected:		// variables
	Data _data;

public:		// functions
	VarEtcBase(const AstBaseWptr& s_defn, const Data& s_data);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(VarEtcBase);
	virtual ~VarEtcBase();

	GEN_GETTER_BY_CON_REF(data);
};
//--------

//--------
class VarEtc: public VarEtcBase
{
public:		// types
	enum class Kind
	{
		Wire,
		Var,
		Const,
	};

protected:		// variables
	Kind _kind;

public:		// functions
	VarEtc(const AstBaseWptr& s_defn, const Data& s_data, Kind s_kind);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(VarEtc);
	virtual ~VarEtc();

	GEN_GETTER_BY_VAL(kind);
};

class MembVarEtc: public VarEtcBase
{
public:		// types
	enum class Kind
	{
		Var,
		Const,
	};

	using AccSpec = ast::AccSpec;

protected:		// variables
	Kind _kind;
	AccSpec _acc_spec;

public:		// functions
	MembVarEtc(const AstBaseWptr& s_defn, const Data& s_data, Kind s_kind,
		AccSpec s_acc_spec);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(MembVarEtc);
	virtual ~MembVarEtc();

	EVAL(MAP(GEN_GETTER_BY_VAL, SEMICOLON,
		kind,
		acc_spec));
};
//--------

//--------
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
	DeclParamItemVar(const AstBaseWptr& s_defn, const Data& s_data,
		Kind s_kind);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(DeclParamItemVar);
	virtual ~DeclParamItemVar();

	GEN_GETTER_BY_VAL(kind);
};

class DeclParamItemType final: public Base
{
public:		// types
	enum class Kind
	{
		Type,
		ParpkType,
	};

private:		// variables
	Typenm _typenm;
	Kind _kind;

public:		// functions
	DeclParamItemType(const AstBaseWptr& s_defn,
		const Typenm& s_typenm, Kind s_kind);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(DeclParamItemType);
	virtual ~DeclParamItemType();

	GEN_GETTER_BY_CON_REF(typenm);
	GEN_GETTER_BY_VAL(kind);
};

class DeclParamItemModule final: public Base
{
public:		// types
	enum class Kind
	{
		Module,
		ParpkModule,
	};

private:		// variables
	Symbol* _module = nullptr;
	Kind _kind;

public:		// functions
	DeclParamItemModule(const AstBaseWptr& s_defn, Symbol* s_module,
		Kind s_kind);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(DeclParamItemModule);
	virtual ~DeclParamItemModule();

	EVAL(MAP(GEN_GETTER_BY_VAL, SEMICOLON,
		module,
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
	DeclArgItemVar(const AstBaseWptr& s_defn, const Data& s_data,
		Kind s_kind);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(DeclArgItemVar);
	virtual ~DeclArgItemVar();

	GEN_GETTER_BY_VAL(kind);
};
//--------

//--------
class AliasValue final: public VarEtcBase
{
public:		// functions
	AliasValue(const AstBaseWptr& s_defn, const Data& s_data);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(AliasValue);
	virtual ~AliasValue();
};

class AliasType final: public Base
{
private:		// variables
	Typenm _typenm;

public:		// functions
	AliasType(const AstBaseWptr& s_defn, const Typenm& s_typenm);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(AliasType);
	virtual ~AliasType();

	GEN_GETTER_BY_CON_REF(typenm);
};

class AliasModule final: public Base
{
private:		// variables
	Symbol* _module = nullptr;

public:		// functions
	AliasModule(const AstBaseWptr& s_defn, Symbol* s_module);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(AliasModule);
	virtual ~AliasModule();

	GEN_GETTER_BY_VAL(module);
};
//--------

//--------
class Mixin: public Base
{
};
//--------

} // namespace sym_data

} // namespace fling_hdl

#endif		// src_sym_data_classes_hpp
