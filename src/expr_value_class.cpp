#include "src/expr_value_class.hpp"

namespace fling_hdl
{

ExprValue::ExprValue(const BigNum& to_cast)
{
}
ExprValue::operator BigNum() const
{
	BigNum ret;

	for (const auto& iter: _vec)
	{
	}

	return ret;
}

bool ExprValue::can_be_big_num() const
{
	for (const auto& fs: vec())
	{
		if ((fs == FourState::Unk) || (fs == FourState::HighImp))
		{
			return false;
		}
	}
	return true;
}

} // namespace fling_hdl
