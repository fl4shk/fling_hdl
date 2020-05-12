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
