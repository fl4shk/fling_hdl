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
	using SymSet = set<Symbol*>;
	using AstBaseWptr = ast::BaseWptr;

public:		// functions
	Base();
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Base);
	virtual ~Base();
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

class MembInfo final
{
public:		// types
	using AccSpec = ast::AccSpec;

private:		// variables
	bool _is_memb = false;
	AccSpec _acc_spec;

public:		// functions
	MembInfo();

	// This constructor sets `_is_memb` to true.
	MembInfo(AccSpec s_acc_spec);

	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(MembInfo);

	~MembInfo();

	EVAL(MAP(GEN_GETTER_BY_VAL, SEMICOLON,
		is_memb,
		acc_spec));
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
	using AccSpec = MembInfo::AccSpec;

protected:		// variables
	Data _data;
	MembInfo _memb_info;

public:		// functions
	VarEtcBase(const Data& s_data);
	VarEtcBase(const Data& s_data, AccSpec s_memb_info_acc_spec);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(VarEtcBase);
	virtual ~VarEtcBase();

	EVAL(MAP(GEN_GETTER_BY_CON_REF, SEMICOLON,
		data,
		memb_info));
};
//--------

//--------
class VarEtc final: public VarEtcBase
{
public:		// types
	enum class Kind
	{
		Wire,
		Var,
		Const,
	};

private:		// variables
	Kind _kind;

public:		// functions
	VarEtc(const Data& s_data, Kind s_kind);
	VarEtc(const Data& s_data, AccSpec s_acc_spec, Kind s_kind);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(VarEtc);
	virtual ~VarEtc();

	GEN_GETTER_BY_VAL(kind);
};
//--------

//--------
class DeclParamOrArgList final: public Base
{
public:		// types
	enum class Kind
	{
		Param,
		Arg,
	};

	using OrderVec = vector<string>;

protected:		// variables
	Kind _kind;
	OrderVec _order_vec;

public:		// functions
	DeclParamOrArgList(Kind s_kind, OrderVec&& s_order_vec);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(DeclParamOrArgList);
	virtual ~DeclParamOrArgList();

	GEN_GETTER_BY_VAL(kind);
	GEN_GETTER_BY_CON_REF(order_vec);
};

class InstParamOrArgListNamed final: public Base
{
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
	DeclParamItemVar(const Data& s_data, Kind s_kind);
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
	DeclParamItemType(const Typenm& s_typenm, Kind s_kind);
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
	DeclParamItemModule(Symbol* s_module, Kind s_kind);
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
	DeclArgItemVar(const Data& s_data, Kind s_kind);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(DeclArgItemVar);
	virtual ~DeclArgItemVar();

	GEN_GETTER_BY_VAL(kind);
};
//--------

//--------
class AliasValue final: public VarEtcBase
{
public:		// functions
	AliasValue(const Data& s_data);
	AliasValue(const Data& s_data, AccSpec s_memb_info_acc_spec);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(AliasValue);
	virtual ~AliasValue();
};

class AliasType final: public Base
{
public:		// types
	using AccSpec = ast::AccSpec;

private:		// variables
	Typenm _typenm;
	MembInfo _memb_info;

public:		// functions
	AliasType(const Typenm& s_typenm);
	AliasType(const Typenm& s_typenm, AccSpec s_memb_info_acc_spec);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(AliasType);
	virtual ~AliasType();

	EVAL(MAP(GEN_GETTER_BY_CON_REF, SEMICOLON,
		typenm,
		memb_info));
};

class AliasModule final: public Base
{
public:		// types
	using AccSpec = ast::AccSpec;

private:		// variables
	Symbol* _module = nullptr;
	MembInfo _memb_info;

public:		// functions
	AliasModule(Symbol* s_module);
	AliasModule(Symbol* s_module, AccSpec s_memb_info_acc_spec); 
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(AliasModule);
	virtual ~AliasModule();

	GEN_GETTER_BY_VAL(module);
	GEN_GETTER_BY_CON_REF(memb_info);
};
//--------

//--------
class ClsOrMxnData final
{
public:		// types
	using AccSpec = ast::AccSpec;
	using SymSet = Base::SymSet;

protected:		// variables
	bool _is_base, _is_complete;
	SymSet _extends_set;

	MembInfo _memb_info;

public:		// functions
	ClsOrMxnData(bool s_is_base, bool s_is_complete,
		SymSet&& s_extends_set);
	ClsOrMxnData(bool s_is_base, bool s_is_complete,
		SymSet&& s_extends_set, AccSpec s_memb_info_acc_spec);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(ClsOrMxnData);
	~ClsOrMxnData();

	EVAL(MAP(GEN_GETTER_BY_VAL,
		is_base,
		is_complete));
	EVAL(MAP(GEN_GETTER_BY_CON_REF, SEMICOLON,
		extends_set,
		memb_info));
};

// This class is also to be used as the base class for `Class`.
class Mixin: public Base
{
public:		// types
	using Data = ClsOrMxnData;

protected:		// variables
	Data _data;

public:		// functions
	Mixin(const Data& s_data);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Mixin);
	virtual ~Mixin();

	GEN_GETTER_BY_CON_REF(data);
};

class Class final: public Mixin
{
private:		// variables
	bool _is_signed, _is_packed;

public:		// functions
	Class(const Data& s_data, bool s_is_signed, bool s_is_packed);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Class);
	virtual ~Class();

	EVAL(MAP(GEN_GETTER_BY_VAL, SEMICOLON,
		is_signed,
		is_packed));
};
//--------

//--------
// Class for unnamed scopes
class Scope: public Base
{
public:		// functions
	Scope();
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Scope);
	virtual ~Scope();
};

// Class for packages, which are the only kinds of symbols that `import`
// statements work with.
class Package final: public Scope
{
public:		// functions
	Package();
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Package);
	virtual ~Package();
};
//--------

//--------
class Module final: public Base
{
public:		// functions
	Module();
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Module);
	virtual ~Module();
};

class InstModule final: public Base
{
private:		// variables
	Symbol* _module = nullptr;

public:		// functions
	InstModule(Symbol* s_module);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(InstModule);
	virtual ~InstModule();
};
//--------

} // namespace sym_data

} // namespace fling_hdl

#endif		// src_sym_data_classes_hpp
