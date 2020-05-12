//#ifndef src_list_of_tokens_define_hpp
//#define src_list_of_tokens_define_hpp

// src/list_of_tokens_define.hpp

//#include "misc_includes.hpp"

#define LIST_OF_TOKENS(X) \
	/* -------- */ \
	X(LexLineComment, "<comment>") \
	/* -------- */ \
	\
	/* -------- */ \
	X(PunctRangeSeparator, "..") \
	/* -------- */ \
	\
	/* -------- */ \
	X(LitDecNum, "<literal decimal number>") \
	X(LitHexNum, "<literal hexadecimal number>") \
	X(LitOctNum, "<literal octal number>") \
	X(LitBinNum, "<literal binary number>") \
	X(LitFloatNum, "<literal floating point number>") \
	\
	X(LitString, "<literal string>") \
	/* -------- */ \
	\
	/* -------- */ \
	X(PunctNonBlkAssign, ":=") \
	X(PunctBlkAssign, "=") \
	/* -------- */ \
	\
	/* -------- */ \
	X(PunctLogor, "||") \
	X(PunctLogand, "&&") \
	\
	X(PunctCmpEq, "==") \
	X(PunctCmpNe, "!=") \
	X(PunctCaseCmpEq, "===") \
	X(PunctCaseCmpNe, "!==") \
	\
	X(PunctCmpLt, "<") \
	X(PunctCmpGt, ">" ) \
	X(PunctCmpLe, "<=") \
	X(PunctCmpGe, ">=") \
	\
	X(PunctPlus, "+") \
	X(PunctMinus, "-") \
	\
	X(PunctMul, "*") \
	X(PunctDiv, "div") \
	X(PunctMod, "mod") \
	\
	X(PunctBitor, "|") \
	X(PunctBitnor, "~|") \
	\
	X(PunctBitand, "&") \
	X(PunctBitnand, "~&") \
	\
	X(PunctBitxor, "^") \
	X(PunctBitxnor, "^~") \
	\
	X(KwLsl, "lsl") \
	X(KwLsr, "lsr") \
	X(KwAsr, "asr") \
	\
	X(PunctBitnot, "~") \
	X(PunctLognot, "!") \
	/* -------- */ \
	\
	/* -------- */ \
	X(PunctMapTo, "=>") \
	/* -------- */ \
	\
	/* -------- */ \
	X(PunctSliceStart, "#[") \
	/* -------- */ \
	\
	/* -------- */ \
	X(PunctMemberAccess, ".") \
	X(PunctScopeAccess, "::") \
	/* -------- */ \
	\
	/* -------- */ \
	X(PunctLparen, "(") \
	X(PunctRparen, ")") \
	X(PunctLbracket, "[") \
	X(PunctRbracket, "]") \
	X(PunctLbrace, "{") \
	X(PunctRbrace, "}") \
	X(PunctSemicolon, ";") \
	X(PunctColon, ":") \
	X(PunctPlusColon, "+:") \
	X(PunctMinusColon, "-:") \
	X(PunctComma, ",") \
	/* -------- */ \
	\
	/* -------- */ \
	X(KwPackage, "package") \
	\
	X(KwImport, "import") \
	X(KwAll, "all") \
	\
	X(KwModule, "module") \
	X(KwModinst, "modinst") \
	\
	X(KwType, "type") \
	\
	X(KwInput, "input") \
	X(KwOutput, "output") \
	X(KwInout, "inout") \
	\
	X(KwInterface, "interface") \
	X(KwModport, "modport") \
	\
	X(KwFunc, "func") \
	X(KwTask, "task") \
	X(KwProc, "proc") \
	\
	X(KwParpk, "parpk") \
	X(KwUnparpk, "unparpk") \
	\
	X(KwGen, "gen") \
	\
	X(KwIf, "if") \
	X(KwElse, "else") \
	\
	X(KwSwitch, "switch") \
	X(KwSwitchz, "switchz") \
	X(KwCase, "case") \
	X(KwDefault, "default") \
	\
	X(KwFor, "for") \
	X(KwWhile, "while") \
	\
	X(KwBreak, "break") \
	X(KwContinue, "continue") \
	X(KwReturn, "return") \
	\
	X(KwStruct, "struct") \
	X(KwPacked, "packed") \
	X(KwEnum, "enum") \
	\
	\
	X(KwConst, "const") \
	X(KwVar, "var") \
	X(KwWire, "wire") \
	\
	X(KwAssign, "assign") \
	\
	X(KwComb, "comb") \
	X(KwSeq, "seq") \
	\
	X(KwPosedge, "posedge") \
	X(KwNegedge, "negedge") \
	\
	X(KwAlias, "alias") \
	\
	X(KwMux, "mux") \
	X(KwCat, "cat") \
	X(KwRepl, "repl") \
	\
	X(KwLogic, "logic") \
	X(KwUnsigned, "unsigned") \
	X(KwSigned, "signed") \
	\
	X(KwInteger, "integer") \
	\
	X(KwRange, "range") \
	\
	X(KwTypeof, "typeof") \
	X(KwAuto, "auto") \
	\
	X(KwSelfT, "self_t") \
	X(KwRetT, "ret_t") \
	/* -------- */ \
	\
	/* -------- */ \
	X(KwDollarSize, "$size") \
	X(KwDollarRange, "$range") \
	X(KwDollarHigh, "$high") \
	X(KwDollarLow, "$low") \
	\
	X(KwDollarHighel, "$highel") \
	X(KwDollarLowel, "$lowel") \
	\
	X(KwDollarUnsigned, "$unsigned") \
	X(KwDollarSigned, "$signed") \
	\
	X(KwDollarIsUnsigned, "$is_unsigned") \
	X(KwDollarIsSigned, "$is_signed") \
	X(KwDollarIsUnknown, "$is_unknown") \
	\
	X(KwDollarPow, "$pow") \
	/* -------- */ \
	\
	/* -------- */ \
	X(KwAssert, "assert") \
	X(KwAssume, "assume") \
	X(KwCover, "cover") \
	X(KwProperty, "property") \
	\
	X(KwDollarIsFormal, "$is_formal") \
	\
	X(KwDollarStable, "$stable") \
	X(KwDollarPast, "$past") \
	X(KwDollarRose, "$rose") \
	X(KwDollarFell, "$fell") \
	/* -------- */ \
	\
	/* -------- */ \
	X(MiscIdent, "<identifier>") \
	X(MiscOther, "<invalid token>") \
	/* -------- */ \
	\
	/* -------- */ \
	X(MiscEof, "<end of file>") \
	/* -------- */ \
	\

//#endif		// src_list_of_tokens_define_hpp
