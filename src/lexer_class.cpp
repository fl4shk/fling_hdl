#include "lexer_class.hpp"

namespace fling_hdl
{

const Lexer::TokToStringMap Lexer::_TOK_TO_STRING_MAP
= {
	#define X(name, str) \
		{Tok::name, str},
	LIST_OF_TOKENS(X)
	#undef X
};

const Lexer::TokToStringMap& Lexer::tok_to_string_map() const
{
	return _TOK_TO_STRING_MAP;
}
void Lexer::_inner_next_tok()
{
	if (c() == EOF)
	{
		_set_tok(Tok::MiscEof, false);
	}
	else if (isdigit(c()))
	{
		const auto first_c = c();

		_next_char();

		// Hexadecimal number
		if ((first_c == '0') && (c() == 'x'))
		{
			_inner_next_tok_when_lit_num(Tok::LitHexNum, &isxdigit);

			// Build `n()`
			BigNum n_n = 0;
			for (size_t i=0; i<s().size(); ++i)
			{
				if ((s().at(i) >= 'a') && (s().at(i) <= 'f'))
				{
					n_n = (n_n * 0x10) + (s().at(i) - 'f' + 0xa);
				}
				else if ((s().at(i) >= 'A') && (s().at(i) <= 'F'))
				{
					n_n = (n_n * 0x10) + (s().at(i) - 'F' + 0xA);
				}
				else // if (isdigit(s().at(i)))
				{
					n_n = (n_n * 0x10) + (s().at(i) - '0');
				}
			}
			state().set_n(n_n);
		}

		// Octal number
		else if ((first_c == '0') && (c() == 'o'))
		{
			_inner_next_tok_when_lit_num(Tok::LitOctNum,
				[](int c) -> int
				{
					return (c >= '0') && (c <= '7');
				});

			// Build `n()`
			BigNum n_n = 0;
			for (size_t i=0; i<s().size(); ++i)
			{
				n_n = (n_n * 8) + (s().at(i) - '0');
			}
			state().set_n(n_n);
		}

		// Binary number
		else if ((first_c == '0') && (c() == 'b'))
		{
			_inner_next_tok_when_lit_num(Tok::LitBinNum,
				[](int c) -> int
				{
					return (c >= '0') && (c <= '1');
				});

			// Build `n()`
			BigNum n_n = 0;
			for (size_t i=0; i<s().size(); ++i)
			{
				n_n = (n_n * 0b10) + (s().at(i) - '0');
			}
			state().set_n(n_n);
		}

		// Decimal number
		else
		{
			_set_tok(Tok::LitDecNum, false);

			string n_s;
			n_s += static_cast<char>(first_c);

			while (isdigit(c()))
			{
				n_s += static_cast<char>(c());
				_next_char();
			}
			state().set_s(n_s);

			// Build `n()`
			BigNum n_n = 0;
			for (size_t i=0; i<s().size(); ++i)
			{
				n_n = (n_n * 10) + (s().at(i) - '0');
			}
			state().set_n(n_n);
		}
	}
	else if (c() == '/')
	{
		_next_char();

		if (c() == '/')
		{
			_next_char();
			_set_tok(Tok::LexLineComment, false);

			while ((c() != '\n') && (c() != EOF))
			{
				_next_char();
			}
			//if (c() == EOF)
			//{
			//	_set_tok(Tok::MiscEof, false);
			//}
		}
		else
		{
			_set_tok(Tok::PunctDiv, false);
		}
	}
	else if (c() == '.')
	{
		_sel_set_tok
			('.', Tok::PunctRangeSeparator,
			Tok::PunctMemberAccess);
	}
	else if (c() == ':')
	{
		_sel_set_tok
			('=', Tok::PunctNonBlkAssign,
			':', Tok::PunctScopeAccess,
			Tok::PunctColon);
	}
	else if (c() == '|')
	{
		_sel_set_tok
			('|', Tok::PunctLogor,
			Tok::PunctBitor);
	}
	else if (c() == '&')
	{
		_sel_set_tok
			('&', Tok::PunctLogand,
			Tok::PunctBitand);
	}
	else if (c() == '=')
	{
		_next_char();

		if (c() == '=')
		{
			_sel_set_tok
				('=', Tok::PunctCaseCmpEq,
				Tok::PunctCmpEq);
		}
		else if (c() == '>')
		{
			_next_char();
			_set_tok(Tok::PunctMapTo, false);
		}
		else
		{
			_set_tok(Tok::PunctBlkAssign, false);
		}
	}
	else if (c() == '!')
	{
		_next_char();

		if (c() == '=')
		{
			_sel_set_tok
				('=', Tok::PunctCaseCmpNe,
				Tok::PunctCmpNe);
		}
		else
		{
			_set_tok(Tok::PunctLognot, false);
		}
	}
	else if (c() == '<')
	{
		_sel_set_tok
			('=', Tok::PunctCmpLe,
			Tok::PunctCmpLt);
	}
	else if (c() == '>')
	{
		_sel_set_tok
			('=', Tok::PunctCmpGe,
			Tok::PunctCmpGt);
	}
	else if (c() == '+')
	{
		_sel_set_tok
			(':', Tok::PunctPlusColon,
			Tok::PunctPlus);
	}
	else if (c() == '-')
	{
		_sel_set_tok
			(':', Tok::PunctMinusColon,
			Tok::PunctMinus);
	}
	else if (c() == '*')
	{
		_sel_set_tok(Tok::PunctMul);
	}
	else if (c() == '%')
	{
		_sel_set_tok(Tok::PunctMod);
	}
	else if (c() == '~')
	{
		_sel_set_tok
			('|', Tok::PunctBitnor,
			'&', Tok::PunctBitnand,
			'^', Tok::PunctBitxnor,
			Tok::PunctBitnot);
	}
	else if (c() == '^')
	{
		_sel_set_tok
			('~', Tok::PunctBitxnor,
			Tok::PunctBitxor);
	}
	else if (c() == '#')
	{
		_sel_set_tok
			('[', Tok::PunctSliceStart,
			Tok::MiscOther);
	}
	else if (c() == '(')
	{
		_sel_set_tok(Tok::PunctLparen);
	}
	else if (c() == ')')
	{
		_sel_set_tok(Tok::PunctRparen);
	}
	else if (c() == '[')
	{
		_sel_set_tok(Tok::PunctLbracket);
	}
	else if (c() == ']')
	{
		_sel_set_tok(Tok::PunctRbracket);
	}
	else if (c() == '{')
	{
		_sel_set_tok(Tok::PunctLbrace);
	}
	else if (c() == '}')
	{
		_sel_set_tok(Tok::PunctRbrace);
	}
	else if (c() == ';')
	{
		_sel_set_tok(Tok::PunctRbrace);
	}
	else if (c() == ',')
	{
		_sel_set_tok(Tok::PunctComma);
	}
	else if (isalpha(c()) || (c() == '_'))
	{
		string n_s;
		n_s += static_cast<char>(c());

		_next_char();

		// Raw ident (allows you to use keywords)
		if (c() == '#')
		{
			n_s = "";
			_next_char();

			_set_tok(Tok::MiscIdent, false);

			while (isalnum(c()) || (c() == '_'))
			{
				n_s += static_cast<char>(c());
				_next_char();
			}

			state().set_s(n_s);
		}

		// Basic ident
		else
		{
			while (isalnum(c()) || (c() == '_'))
			{
				n_s += static_cast<char>(c());
				_next_char();
			}
			state().set_s(n_s);

			if (!_kw_set_tok(map<Tok, string>
				({
					#define X(name, str) \
						{Tok::name, str},
					LIST_OF_KW_TOKENS(X)
					#undef X
				})))
			{
				_set_tok(Tok::MiscIdent, false);
			}
		}
	}
	else if (c() == '$')
	{
		string n_s;
		n_s += static_cast<char>(c());

		_next_char();

		while (isalnum(c()) || (c() == '_'))
		{
			n_s += static_cast<char>(c());
			_next_char();
		}
		state().set_s(n_s);

		if (!_kw_set_tok(map<Tok, string>
			({
				#define X(name, str) \
					{Tok::name, str},
				LIST_OF_KW_DOLLAR_TOKENS(X)
				#undef X
			})))
		{
			_set_tok(Tok::MiscOther, false);
		}
	}
	else
	{
		_set_tok(Tok::MiscOther, false);
	}
}

} // namespace fling_hdl
