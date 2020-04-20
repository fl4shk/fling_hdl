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
class VarEtcBase: public Base
{
protected:		// variables
	Symbol* _type = nullptr;
	AstBaseWptr _expr;

public:		// functions
	VarEtcBase(const AstBaseWptr& s_defn, Symbol* s_type,
		const AstBaseWptr& s_expr);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(VarEtcBase);
	virtual ~VarEtcBase();

	GEN_GETTER_BY_VAL(type);
	GEN_GETTER_BY_CON_REF(expr);
};

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
	VarEtc(const AstBaseWptr& s_defn, Symbol* s_type,
		const AstBaseWptr& s_expr, Kind s_kind);
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
	bool _is_static;

public:		// functions
	MembVarEtc(const AstBaseWptr& s_defn, Symbol* s_type,
		const AstBaseWptr& s_expr, Kind s_kind, AccSpec s_acc_spec,
		bool s_is_static);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(MembVarEtc);
	virtual ~MembVarEtc();

	EVAL(MAP(GEN_GETTER_BY_VAL, SEMICOLON,
		kind,
		acc_spec,
		is_static));
};

//class DeclParamVar final: public Base
//{
//public:		// types
//	using Kind = ast::DeclParamList_Item::Kind;
//
//private:		// variables
//	Kind _kind;
//	Symbol* _type = nullptr;
//
//public:		// functions
//	DeclParamVar(const AstBaseWptr& s_defn, Symbol* s_type,
//		const AstBaseWptr& s_expr);
//};
//
//class DeclArgVar final: public VarEtcBase
//{
//public:		// types
//	using Kind = ast::DeclArgList_Item::Kind;
//
//private:		// variables
//	Kind _kind;
//
//public:		// functions
//	DeclArgVar(const AstBaseWptr& s_defn, Symbol* s_type,
//		const AstBaseWptr& s_expr);
//};
//--------

//--------
//class AliasValue: public Base
//{
//protected:		// variables
//	Symbol* _type = nullptr;
//	AstBaseWptr _expr;
//
//public:		// functions
//};
//
//class AliasType
//--------

} // namespace sym_data

} // namespace fling_hdl

#endif		// src_sym_data_classes_hpp
