//#ifndef src_parser_class_defines_hpp
//#define src_parser_class_defines_hpp

// src/parser_class_defines.hpp


#define make_ast(type) \
	new type(_curr_ast_parent, lex_file_pos())

#define DEFER_PUSH(name, type) \
	auto name = make_ast(type); \
	AstNodeDeferredPusher deferred_pusher_ ## name (this, name)
#define DEFER_PUSH_LIST(name) \
	BaseSptrList name; \
	AstNodeListDeferredPusher deferred_pusher_ ## name (this, &name)

#define PROLOGUE_AND_EPILOGUE(str) \
	ParserBase::PrologueAndEpilogue prologue_and_epilogue (this, #str)

#define _INNER_PARSE_IFELSE(func) \
	if (CHECK_PARSE(func)) \
	{ \
		func (); \
	}
#define PARSE_IFELSE(...) \
	EVAL(MAP(_INNER_PARSE_IFELSE, ELSE, __VA_ARGS__))

#define _MEMB_FUNC(func) \
	&Parser::func

#define CHECK_PARSE(func) \
	_check_parse(_MEMB_FUNC(func))
#define ATTEMPT_PARSE(func) \
	_attempt_parse(_MEMB_FUNC(func))
#define GET_VALID_TOK_SET(...) \
	_get_valid_tok_set(EVAL(MAP(_MEMB_FUNC, COMMA, __VA_ARGS__)))


#define _INNER_JUST_PARSE_AND_POP_AST(to_set, func) \
	func (); \
	_pop_ast(to_set)
#define _INNER_PARSE_AND_POP_AST_IF(to_set, func) \
	if (CHECK_PARSE(func)) \
	{ \
		_INNER_JUST_PARSE_AND_POP_AST(to_set, func); \
	}
#define JUST_PARSE_AND_POP_AST(...) \
	EVAL(MAP_PAIRS(_INNER_JUST_PARSE_AND_POP_AST, SEMICOLON, __VA_ARGS__))
#define _MULTI_PARSE_AND_POP_AST_IF(sep, ...) \
	EVAL(MAP_PAIRS(_INNER_PARSE_AND_POP_AST_IF, sep, __VA_ARGS__))

#define PARSE_AND_POP_AST_IFELSE(...) \
	_MULTI_PARSE_AND_POP_AST_IF(ELSE, __VA_ARGS__)
#define PARSE_AND_POP_AST_IF(...) \
	_MULTI_PARSE_AND_POP_AST_IF(SEMICOLON, __VA_ARGS__)

#define _INNER_JUST_PARSE_AND_POP_AST_LIST(to_set, func) \
	func (); \
	_pop_ast_list(to_set)
#define _INNER_PARSE_AND_POP_AST_LIST_IF(to_set, func) \
	if (CHECK_PARSE(func)) \
	{ \
		_INNER_JUST_PARSE_AND_POP_AST_LIST(to_set, func); \
	}
#define JUST_PARSE_AND_POP_AST_LIST(...) \
	EVAL(MAP_PAIRS(_INNER_JUST_PARSE_AND_POP_AST_LIST, SEMICOLON, \
		__VA_ARGS__))
#define _MULTI_PARSE_AND_POP_AST_LIST_IF(sep, ...) \
	EVAL(MAP_PAIRS(_INNER_PARSE_AND_POP_AST_LIST_IF, sep, __VA_ARGS__))
#define PARSE_AND_POP_AST_LIST_IFELSE(...) \
	_MULTI_PARSE_AND_POP_AST_LIST_IF(ELSE, __VA_ARGS__)
#define PARSE_AND_POP_AST_LIST_IF(...) \
	_MULTI_PARSE_AND_POP_AST_LIST_IF(SEMICOLON, __VA_ARGS__)

#define _INNER_JUST_PARSE_AND_POP_STR_VEC(to_set, func) \
	func (); \
	_pop_str_vec(to_set)
#define _INNER_PARSE_AND_POP_STR_VEC_IF(to_set, func) \
	if (CHECK_PARSE(func)) \
	{ \
		_INNER_JUST_PARSE_AND_POP_STR_VEC(to_set, func); \
	}
#define JUST_PARSE_AND_POP_STR_VEC(...) \
	EVAL(MAP_PAIRS(_INNER_JUST_PARSE_AND_POP_STR_VEC, SEMICOLON, \
		__VA_ARGS__))
#define _MULTI_PARSE_AND_POP_STR_VEC_IF(sep, ...) \
	EVAL(MAP_PAIRS(_INNER_PARSE_AND_POP_STR_VEC_IF, sep, __VA_ARGS__))
#define PARSE_AND_POP_STR_VEC_IFELSE(...) \
	_MULTI_PARSE_AND_POP_STR_VEC_IF(ELSE, __VA_ARGS__)
#define PARSE_AND_POP_STR_VEC_IF(...) \
	_MULTI_PARSE_AND_POP_STR_VEC_IF(SEMICOLON, __VA_ARGS__)





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

#define EXPECT_AND_GRAB_TOK(name, ...) \
	EXPECT(__VA_ARGS__); \
	const auto name = prev_lex_tok()
#define EXPECT_IDENT_AND_GRAB_S(name) \
	EXPECT(MiscIdent); \
	name = prev_lex_s()

#define MAKE_AST_NODE_AND_POP(name) \
	BaseUptr name; \
	_pop_ast(name)

#define MAKE_AST_LIST_AND_POP(name) \
	BaseUptrList name; \
	_pop_ast_list(name)


//#endif		// src_parser_class_defines_hpp
