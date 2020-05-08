#ifndef src_sym_data_shared_classes_hpp
#define src_sym_data_shared_classes_hpp

// src/sym_data/shared_classes.hpp

#include "../misc_includes.hpp"

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
	virtual inline ~Base() = default;
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
	~Typenm() = default;

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

	~MembInfo() = default;

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
	~VarEtcData() = default;

	EVAL(MAP(GEN_GETTER_BY_CON_REF, SEMICOLON,
		typenm,
		expr));
};
//--------

} // namespace sym_data

} // namespace fling_hdl

#endif		// src_sym_data_shared_classes_hpp
