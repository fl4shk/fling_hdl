#ifndef src_expr_value_class_hpp
#define src_expr_value_class_hpp

// src/expr_value_class.hpp

#include "misc_includes.hpp"

namespace fling_hdl
{

enum class FourState
{
	Zero,
	One,
	Unk,
	HighImp,
};

class ExprValue final
{
private:		// variables
	vector<FourState> _vec;
	bool _is_signed = false;
public:		// functions
	inline ExprValue() = default;
	ExprValue(const BigNum& to_cast);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(ExprValue);
	inline ~ExprValue() = default;

	operator BigNum () const;
	bool can_be_big_num() const;

	GEN_GETTERS_BY_CON_REF_AND_REF(vec);
	GEN_GETTER_AND_SETTER_BY_VAL(is_signed);
};

} // namespace fling_hdl

#endif		// src_expr_value_class_hpp
