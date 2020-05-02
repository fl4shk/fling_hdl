#ifndef src_sym_data_basic_var_etc_classes_hpp
#define src_sym_data_basic_var_etc_classes_hpp

// src/sym_data/basic_var_etc_classes.hpp

#include "../misc_includes.hpp"

namespace fling_hdl
{

namespace sym_data
{

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
	virtual inline ~VarEtcBase() = default;

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
	virtual inline ~VarEtc() = default;

	GEN_GETTER_BY_VAL(kind);
};
//--------

} // namespace sym_data

} // namespace fling_hdl


#endif		// src_sym_data_basic_var_etc_classes_hpp
