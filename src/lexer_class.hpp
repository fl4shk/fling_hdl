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

#ifndef src_lexer_class_hpp
#define src_lexer_class_hpp

// src/lexer_class.hpp

#include "misc_includes.hpp"
#include "list_of_tokens_define.hpp"

namespace fling_hdl
{

enum class Tok
{
	#define X(name, dummy_0) \
		name,
	LIST_OF_TOKENS(X)
	#undef X
};

class Lexer final: public LexerBase<Tok>
{
public:		// types
	using Base = LexerBase<Tok>;

	using IsSomeDigitFunc = int (*)(int);

private:		// variables
	static const TokToStringMap _TOK_TO_STRING_MAP;

public:		// functions
	inline Lexer(const string& s_filename, string* s_text)
		: Base(s_filename, s_text)
	{
	}
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Lexer);
	virtual inline ~Lexer() = default;

	inline void next_tok()
	{
		_next_tok(Tok::LexLineComment);
	}

	virtual const TokToStringMap& tok_to_string_map() const;

private:		// functions
	virtual void _inner_next_tok();
	inline void _inner_next_tok_when_lit_num(Tok tok, IsSomeDigitFunc func)
	{
		_next_char();
		string n_s;

		if (func(c()))
		{
			_set_tok(tok, true);

			n_s += static_cast<char>(c());

			while (func(c()))
			{
				_next_char();
				n_s += static_cast<char>(c());
			}

			state().set_s(n_s);
		}
		else
		{
			_set_tok(Tok::MiscOther, false);
		}
	}
};

} // namespace fling_hdl


#endif		// src_lexer_class_hpp
