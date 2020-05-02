#ifndef src_sym_data_class_or_mixin_classes_hpp
#define src_sym_data_class_or_mixin_classes_hpp

// src/sym_data/class_or_mixin_classes.hpp

#include "../misc_includes.hpp"

namespace fling_hdl
{

namespace sym_data
{

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
	virtual inline ~Mixin() = default;

	GEN_GETTER_BY_CON_REF(data);
};

class Class final: public Mixin
{
private:		// variables
	bool _is_signed, _is_packed;

public:		// functions
	Class(const Data& s_data, bool s_is_signed, bool s_is_packed);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Class);
	virtual inline ~Class() = default;

	EVAL(MAP(GEN_GETTER_BY_VAL, SEMICOLON,
		is_signed,
		is_packed));
};
//--------

} // namespace sym_data

} // namespace fling_hdl


#endif		// src_sym_data_class_or_mixin_classes_hpp
