#include "lexer_class.hpp"

namespace fling_hdl
{

Lexer::Lexer(const string& s_filename, string* s_text)
	: Base(s_filename, s_text)
{
}

void Lexer::_inner_next_tok()
{
	if (c() == '/')
	{
		_next_char();

		if (c() == '/')
		{
			_next_char();
			_set_tok(Tok::LexLineComment);

			while (c() != '\n')
			{
				_next_char();
			}
		}
		else
		{
			_set_tok(Tok::PunctDiv);
		}
	}
	else if (c() == '.')
	{
		_next_char();

		if (c() == '.')
		{
			_next_char();
			_set_tok(Tok::PunctRangeSeparator);
		}
		else
		{
			_set_tok(Tok::PunctMemberAccess);
		}
	}
	else if (c() == '|')
	{
		_next_char();

		if (c() == '|')
		{
			_next_char();
			_set_tok(Tok::PunctLogor);
		}
	}
	else if (isdigit(c()))
	{
		const auto first_c = c();

		_next_char();

		// Hexadecimal number
		if ((first_c == '0') && (c() == 'x'))
		{
			_inner_next_tok_when_lit_num(Tok::LitHexNum, &isxdigit);
		}

		// Octal number
		else if ((first_c == '0') && (c() == 'o'))
		{
			_inner_next_tok_when_lit_num(Tok::LitOctNum,
				[](int c) -> int
				{
					return (c >= '0') && (c <= '7');
				});
		}

		// Binary number
		else if ((first_c == '0') && (c() == 'b'))
		{
			_inner_next_tok_when_lit_num(Tok::LitBinNum,
				[](char c) -> bool
				{
					return (c() >= '0') && (c() <= '1');
				});
		}

		// Decimal number
		else
		{
			_set_tok(Tok::LitDecNum);

			state()._s = "";
			state()._s += static_cast<char>(first_c);

			while (isdigit(c()))
			{
				state()._s += static_cast<char(c());
				_next_char();
			}
		}
	}
	else
	{
		_set_tok(Tok::MiscOther);
	}
}

} // namespace fling_hdl
