#ifndef src_lexer_class_hpp
#define src_lexer_class_hpp

// src/lexer_class.hpp

#include "misc_includes.hpp"

namespace fling_hdl
{

enum class Tok
{
	//--------
	LexLineComment,
	//--------

	//--------
	PunctRangeSeparator,
	//--------

	//--------
	LitDecNum,
	LitHexNum,
	LitOctNum,
	LitBinNum,
	LitFloatNum,

	//LitString,
	//--------

	//--------
	PunctNonBlkAssign,
	PunctBlkAssign,
	//--------

	//--------
	PunctLogor,
	PunctLogand,

	PunctCmpEq,
	PunctCmpNe,
	PunctCaseCmpEq,
	PunctCaseCmpNe,

	PunctCmpLt,
	PunctCmpGt,
	PunctCmpLe,
	PunctCmpGe,

	PunctPlus,
	PunctMinus,

	PunctMul,
	PunctDiv,
	PunctMod,

	PunctBitor,
	PunctBitnor,

	PunctBitand,
	PunctBitnand,

	PunctBitxor,
	PunctBitxnor,

	KwLsl,
	KwLsr,
	KwAsr,

	PunctBitnot,
	PunctLognot,
	//--------

	//--------
	PunctMapTo,
	//--------

	//--------
	PunctSliceStart,
	//--------

	//--------
	PunctMemberAccess,
	PunctScopeAccess,
	//--------

	//--------
	PunctLparen,
	PunctRparen,
	PunctLbracket,
	PunctRbracket,
	PunctLbrace,
	PunctRbrace,
	PunctSemicolon,
	PunctColon,
	PunctPlusColon,
	PunctMinusColon,
	PunctComma,
	//--------

	//--------
	KwPackage,

	KwImport,
	KwAll,

	KwModule,
	KwModinst,

	KwType,

	KwInput,
	KwOutput,
	KwInout,

	//KwInterface,
	//KwModport,

	KwFunc,
	KwTask,
	//KwProc,

	//KwParpk,
	//KwUnparpk,

	KwGen,

	KwIf,
	KwElse,

	KwSwitch,
	KwSwitchz,
	KwCase,
	KwDefault,

	KwFor,
	KwWhile,

	//KwBreak,
	//KwContinue,
	//KwReturn,

	KwStruct,
	//KwPacked,
	KwEnum,


	KwConst,
	KwVar,
	KwWire,

	KwAssign,

	KwComb,
	KwSeq,

	KwPosedge,
	KwNegedge,

	KwAlias,

	KwMux,
	KwCat,
	KwRepl,

	KwLogic,
	KwUnsigned,
	KwSigned,

	KwInteger,

	KwRange,

	//KwTypeof,
	//KwAuto,

	//KwSelfT,
	//KwRetT,
	//--------

	//--------
	KwDollarSize,
	KwDollarRange,
	KwDollarHigh,
	KwDollarLow,

	//KwDollarHighel,
	//KwDollarLowel,

	KwDollarUnsigned,
	KwDollarSigned,

	KwDollarIsUnsigned,
	KwDollarIsSigned,
	//KwDollarIsUnknown,

	KwDollarPow,
	//--------

	//--------
	//KwAssert,
	//KwAssume,
	//KwCover,
	//KwProperty,

	//KwDollarIsformal,

	//KwDollarStable,
	//KwDollarPast,
	//KwDollarRose,
	//KwDollarFell,
	//--------

	//--------
	MiscIdent,
	MiscOther,
	//--------

	//--------
	MiscDone,
	//--------
};

class Lexer final: public gLexerBase<Tok>
{
public:		// types
	using Base = gLexerBase<Tok>;

	typedef int (*IsSomeDigitFunc)(int);

public:		// functions
	Lexer(const string& s_filename, string* s_text);
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
		state()._s = "";

		if (func(c()))
		{
			_set_tok(tok);

			state()._s += static_cast<char>(c());

			while (func(c()))
			{
				_next_char();
				state()._s += static_cast<char>(c());
			}
		}
		else
		{
			_set_tok(Tok::MiscOther);
		}
	}
};

} // namespace fling_hdl


#endif		// src_lexer_class_hpp
