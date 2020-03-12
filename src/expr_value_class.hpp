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
public:		// functions
	inline ExprValue() = default;
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(ExprValue);
	inline ExprValue(BigNum
	inline ~ExprValue() = default;

	operator BigNum () const;
	bool can_be_big_num() const;

	GEN_GETTER_BY_CON_REF(vec);
	GEN_GETTER_BY_REF(vec);
};

} // namespace fling_hdl

#endif		// src_expr_value_class_hpp
