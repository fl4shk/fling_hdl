// This file is part of Fling HDL.
//
// Copyright 2020 Andrew Clark (FL4SHK)
//
// Fling HDL is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Fling HDL is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Fling HDL.  If not, see <https://www.gnu.org/licenses/>.

#include "logic_value_class.hpp"

namespace fling_hdl
{

LogicValue::LogicValue(const BitVec& s_vec, bool s_is_signed)
	: _vec(s_vec), _is_signed(s_is_signed)
{
}
LogicValue::LogicValue(BitVec&& s_vec, bool s_is_signed)
	: _vec(move(s_vec)), _is_signed(s_is_signed)
{
}
LogicValue::LogicValue(const BigNum& s_num, size_t s_size)
	: _is_signed(s_num < 0)
{
	BigNum temp = s_num;

	if (is_signed())
	{
		temp = -temp;
	}

	BitVec temp_vec;

	if (s_size == 0)
	{
		while (temp != BigNum(0))
		{
			if ((temp % BigNum(2)) == 1)
			{
				temp_vec.push_back(Bit::One);
			}
			else // if ((temp % BigNum(2)) == 0)
			{
				temp_vec.push_back(Bit::Zero);
			}

			temp /= 2;
		}
	}
	else // if (s_size > 0)
	{
		for (size_t i=0; i<s_size; ++i)
		{
			if ((temp % BigNum(2)) == 1)
			{
				temp_vec.push_back(Bit::One);
			}
			else // if ((temp % BigNum(2)) == 0)
			{
				temp_vec.push_back(Bit::Zero);
			}

			temp /= 2;
		}
	}

	for (auto iter=temp_vec.crbegin(); iter!=temp_vec.crend(); ++iter)
	{
		_vec.push_back(*iter);
	}
}

optional<BigNum> LogicValue::to_bignum() const
{
	BigNum ret = 0;

	for (auto iter=vec().crbegin(); iter!=vec().crend(); ++iter)
	{
		const auto& bit = *iter;
		ret = (ret * 2);

		if (bit == Bit::One)
		{
			++ret;
		}
		else if ((bit == Bit::HighImped) || (bit == Bit::Unknown))
		{
			return std::nullopt;
		}
	}

	if (is_signed())
	{
		ret = -ret;
	}

	return ret;
}
void LogicValue::resize(size_t n_size)
{
	if (size() < n_size)
	{
		if (!is_signed())
		{
			_vec.resize(n_size, Bit::Zero);
		}
		else // if (is_signed())
		{
			_vec.resize(n_size, vec().back());
		}
	}
	else if (size() > n_size)
	{
		_vec.resize(n_size);
	}
}

} // namespace fling_hdl
