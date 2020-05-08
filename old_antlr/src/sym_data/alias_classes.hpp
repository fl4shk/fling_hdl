#ifndef src_sym_data_alias_classes_hpp
#define src_sym_data_alias_classes_hpp

// src/sym_data/alias_classes.hpp

#include "../misc_includes.hpp"

namespace fling_hdl
{

namespace sym_data
{

//--------
class AliasValue final: public VarEtcBase
{
public:		// functions
	AliasValue(const Data& s_data);
	AliasValue(const Data& s_data, AccSpec s_memb_info_acc_spec);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(AliasValue);
	virtual inline ~AliasValue() = default;
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
	virtual inline ~AliasType() = default;

	EVAL(MAP(GEN_GETTER_BY_CON_REF, SEMICOLON,
		typenm,
		memb_info));
};

class AliasModule final: public Base
{
public:		// types
	using AccSpec = ast::AccSpec;

private:		// variables
	Symbol* _modnm = nullptr;
	MembInfo _memb_info;

public:		// functions
	AliasModule(Symbol* s_modnm);
	AliasModule(Symbol* s_modnm, AccSpec s_memb_info_acc_spec); 
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(AliasModule);
	virtual inline ~AliasModule() = default;

	GEN_GETTER_BY_VAL(modnm);
	GEN_GETTER_BY_CON_REF(memb_info);
};
//--------

} // namespace sym_data

} // namespace fling_hdl

#endif		// src_sym_data_alias_classes_hpp
