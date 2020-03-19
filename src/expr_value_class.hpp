#ifndef src_expr_value_class_hpp
#define src_expr_value_class_hpp

// src/expr_value_class.hpp

#include "misc_includes.hpp"

namespace fling_hdl
{

enum class FourState: u8
{
	Zero,
	One,
	Unknown,
	HighImped,
};

class ExprValue final
{
private:		// variables
	vector<FourState> _vec;
	bool _is_signed = false;
public:		// functions
	inline ExprValue() = default;
	ExprValue(const BigNum& to_conv, bool s_is_signed);
	ExprValue(const BigNum& to_conv, bool s_is_signed, size_t s_size);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(ExprValue);
	inline ~ExprValue() = default;

	operator BigNum () const;
	bool can_cast_to_big_num() const;

	inline size_t size() const
	{
		return _vec.size();
	}
	inline auto& at(size_t index)
	{
		return _vec.at(index);
	}
	inline const auto& at(size_t index) const
	{
		return _vec.at(index);
	}

	inline void resize(size_t n_size)
	{
		*this = ExprValue(BigNum(*this), is_signed(), n_size);
	}

	GEN_GETTER_BY_CON_REF(vec);
	GEN_GETTER_BY_VAL(is_signed);
};

} // namespace fling_hdl

#endif		// src_expr_value_class_hpp
