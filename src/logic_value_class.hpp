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

#ifndef src_logic_value_class_hpp
#define src_logic_value_class_hpp

// src/logic_value_class.hpp

#include "misc_includes.hpp"
#include "ast/ast_node_classes.hpp"

namespace fling_hdl
{

class LogicValue final
{
public:		// types
	enum class Bit: u8
	{
		Zero,
		One,
		HighImped,
		Unknown,
	};
	using BitVec = vector<Bit>;

private:		// variables
	BitVec _vec;
	bool _is_signed = false;

public:		// functions
	inline LogicValue() = default;
	LogicValue(const BitVec& s_vec, bool s_is_signed=false);
	LogicValue(BitVec&& s_vec, bool s_is_signed=false);
	LogicValue(const BigNum& s_num, size_t s_size=0);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(LogicValue);
	inline ~LogicValue() = default;

	optional<BigNum> to_bignum() const;

	// This handles zero- and sign-extension.
	void resize(size_t n_size);
	inline size_t size() const
	{
		return vec().size();
	}

	inline auto& at(size_t index)
	{
		return _vec.at(index);
	}
	inline const auto& at(size_t index) const
	{
		return vec().at(index);
	}

	GEN_GETTER_BY_CON_REF(vec);
	GEN_GETTER_BY_VAL(is_signed);
};

} // namespace fling_hdl


#endif		// src_logic_value_class_hpp
