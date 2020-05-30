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

//#ifndef src_parser_class_defines_hpp
//#define src_parser_class_defines_hpp

// src/parser_class_defines.hpp


#define make_ast(type) \
	new type(_curr_ast_parent, lex_file_pos())

#define DEFER_PUSH_NODE(name, type) \
	auto name = make_ast(type); \
	AstNodeDeferredPusher deferred_pusher_ ## name (this, name)
#define DEFER_PUSH_LIST(name) \
	BaseUptrList name; \
	AstNodeListDeferredPusher deferred_pusher_ ## name (this, &name)
#define DEFER_PUSH_IDENT_LIST(name) \
	IdentList name; \
	IdentListDeferredPusher deferred_pusher_ ## name (this, &name)

#define PROLOGUE_AND_EPILOGUE(str) \
	ParserBase::PrologueAndEpilogue p_and_e (this, #str)

#define _INNER_PARSE_IFELSE(func) \
	if (ATTEMPT_PARSE(func)) \
	{ \
	}
#define PARSE_IFELSE(...) \
	EVAL(MAP(_INNER_PARSE_IFELSE, ELSE, __VA_ARGS__))

#define _MEMB_FUNC(func) \
	&Parser::func

#define ATTEMPT_PARSE(func) \
	_attempt_parse(_MEMB_FUNC(func))
#define ATTEMPT_TOK_PARSE(tok) \
	ATTEMPT_PARSE(TOK_PARSE_FUNC(tok))
#define GET_VALID_TOK_SET(...) \
	_get_valid_tok_set(EVAL(MAP(_MEMB_FUNC, COMMA, __VA_ARGS__)))
#define START_PARSE_IFELSE(X) \
	X(PARSE_IFELSE) \
	else \
	{ \
		_expect_wanted_tok(); \
	}


//--------
#define _INNER_JUST_PARSE_AND_POP_AST_NODE(to_set, func) \
	func (); \
	to_set = _pop_ast_node()
#define JUST_PARSE_AND_POP_AST_NODE(...) \
	EVAL(MAP_PAIRS(_INNER_JUST_PARSE_AND_POP_AST_NODE, SEMICOLON, \
		__VA_ARGS__))
//--------

//--------
#define _INNER_PARSE_AND_POP_AST_NODE_IF(to_set, func) \
	if (ATTEMPT_PARSE(func)) \
	{ \
		to_set = _pop_ast_node(); \
	}
#define _MULTI_PARSE_AND_POP_AST_NODE_IF(sep, ...) \
	EVAL(MAP_PAIRS(_INNER_PARSE_AND_POP_AST_NODE_IF, sep, __VA_ARGS__))

#define PARSE_AND_POP_AST_NODE_IFELSE(...) \
	_MULTI_PARSE_AND_POP_AST_NODE_IF(ELSE, __VA_ARGS__)
#define PARSE_AND_POP_AST_NODE_IF(...) \
	_MULTI_PARSE_AND_POP_AST_NODE_IF(SEMICOLON, __VA_ARGS__)
//--------


//--------
#define _INNER_JUST_PARSE_AND_POP_AST_LIST(to_set, func) \
	func (); \
	to_set = _pop_ast_list()
#define JUST_PARSE_AND_POP_AST_LIST(...) \
	EVAL(MAP_PAIRS(_INNER_JUST_PARSE_AND_POP_AST_LIST, SEMICOLON, \
		__VA_ARGS__))
//--------

//--------
#define _INNER_PARSE_AND_POP_AST_LIST_IF(to_set, func) \
	if (ATTEMPT_PARSE(func)) \
	{ \
		to_set = _pop_ast_list(); \
	}

#define _MULTI_PARSE_AND_POP_AST_LIST_IF(sep, ...) \
	EVAL(MAP_PAIRS(_INNER_PARSE_AND_POP_AST_LIST_IF, sep, __VA_ARGS__))
#define PARSE_AND_POP_AST_LIST_IFELSE(...) \
	_MULTI_PARSE_AND_POP_AST_LIST_IF(ELSE, __VA_ARGS__)
#define PARSE_AND_POP_AST_LIST_IF(...) \
	_MULTI_PARSE_AND_POP_AST_LIST_IF(SEMICOLON, __VA_ARGS__)
//--------

//--------
#define _INNER_JUST_PARSE_AND_POP_IDENT_LIST(to_set, func) \
	func (); \
	to_set = _pop_ident_list()
#define JUST_PARSE_AND_POP_IDENT_LIST(...) \
	EVAL(MAP_PAIRS(_INNER_JUST_PARSE_AND_POP_IDENT_LIST, SEMICOLON, \
		__VA_ARGS__))
//--------

//--------
#define _INNER_PARSE_AND_POP_IDENT_LIST_IF(to_set, func) \
	if (ATTEMPT_PARSE(func)) \
	{ \
		to_set = _pop_ident_list(); \
	}
#define _MULTI_PARSE_AND_POP_IDENT_LIST_IF(sep, ...) \
	EVAL(MAP_PAIRS(_INNER_PARSE_AND_POP_IDENT_LIST_IF, sep, __VA_ARGS__))
#define PARSE_AND_POP_IDENT_LIST_IFELSE(...) \
	_MULTI_PARSE_AND_POP_IDENT_LIST_IF(ELSE, __VA_ARGS__)
#define PARSE_AND_POP_IDENT_LIST_IF(...) \
	_MULTI_PARSE_AND_POP_IDENT_LIST_IF(SEMICOLON, __VA_ARGS__)
//--------





#define _INNER_TOK_CSL(tok) \
	Tok::tok

#define TOK_CSL(...) \
	EVAL(MAP(_INNER_TOK_CSL, COMMA, __VA_ARGS__))

#define CMP_LEX_TOK(...) \
	_cmp_lex_tok(TOK_CSL(__VA_ARGS__))
#define CMP_PREV_LEX_TOK(...) \
	_cmp_prev_lex_tok(TOK_CSL(__VA_ARGS__))

#define TOK_SET(...) \
	TokSet({TOK_CSL(__VA_ARGS__)})

#define TOK_PARSE_FUNC(tok) \
	_parseTok##tok

#define _INNER_INSERT_WANTED_TOK(tok) \
	_wanted_tok_set.insert(_INNER_TOK_CSL(tok))
#define INSERT_WANTED_TOK(...) \
	EVAL(MAP(_INNER_INSERT_WANTED_TOK, SEMICOLON, __VA_ARGS__))

#define EXPECT(...) \
	_expect(TOK_CSL(__VA_ARGS__))
//#define EXPECT_WANTED_TOK(...) _expect_wanted_tok(TOK_SET(__VA_ARGS__))

#define EXPECT_AND_GRAB_TOK(name, ...) \
	EXPECT(__VA_ARGS__); \
	const auto name = prev_lex_tok()
#define EXPECT_IDENT_AND_GRAB_S(name) \
	EXPECT(MiscIdent); \
	name = prev_lex_s()


//#endif		// src_parser_class_defines_hpp
