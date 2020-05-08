#include "src/expr_value_class.hpp"

namespace fling_hdl
{

ExprValue::ExprValue(const BigNum& to_conv, bool s_is_signed)
	: _is_signed(s_is_signed)
{
	BigNum temp = to_conv;

	while (temp != 0)
	{
		_vec.push_back((temp & 1) != 0 ? FourState::One
			: FourState::Zero);
		temp /= 2;
	}
}
ExprValue::ExprValue(const BigNum& to_conv, bool s_is_signed,
	size_t s_size)
	: _is_signed(s_is_signed)
{
	_vec.resize(s_size);

	BigNum temp = 1;
	for (size_t i=0; i<size(); ++i)
	{
		_vec.at(i) = (to_conv & temp) != 0 ? FourState::One
			: FourState::Zero;
		temp *= 2;
	}
}
ExprValue::operator BigNum() const
{
	if ((!is_signed()) || (is_signed() && _vec.back() != FourState::One))
	{
		BigNum ret = 0, temp = 1;
		for (size_t i=0; i<size(); ++i)
		{
			if (at(i) == FourState::One)
			{
				ret |= temp; 
			}
			temp *= 2;
		}
		return ret;
	}
	else
	{
		ExprValue unsgn_copy(*this);
		unsgn_copy._is_signed = false;

		return -BigNum(ExprValue((~BigNum(unsgn_copy)) + 1, false,
			size()));
	}
}

bool ExprValue::can_cast_to_big_num() const
{
	for (const auto& fs: vec())
	{
		if ((fs == FourState::Unknown) || (fs == FourState::HighImped))
		{
			return false;
		}
	}
	return true;
}

} // namespace fling_hdl
