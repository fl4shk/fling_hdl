//#ifndef src_parser_class_defines_hpp
//#define src_parser_class_defines_hpp

// src/parser_class_defines.hpp


#define make_ast(type) \
	new type(_curr_ast_parent, FilePos(_filename, ctx));

#define DEFER_PUSH(name, type) \
	auto name = make_ast(type); \
	AstNodeDeferredPusher deferred_pusher_ ## name (this, name)
#define DEFER_PUSH_LIST(name) \
	BaseSptrList name; \
	AstNodeListDeferredPusher deferred_pusher_ ## name (this, &name)

#define internal_err(func) \
	_internal_err(ctx, #func)


#define _INNER_TOK_CSL(tok) \
	Tok::tok
#define TOK_CSL(...) \
	EVAL(MAP(_INNER_TOK, COMMA, __VA_ARGS__))

#define CMP_LEX_TOK(...) \
	_cmp_lex_tok(TOK_CSL(__VA_ARGS__))
#define CMP_PREV_LEX_TOK(...) \
	_cmp_prev_lex_tok(TOK_CSL(__VA_ARGS__))

#define TOK_SET(...) \
	TokSet({TOK_CSL(__VA_ARGS__)})

#define JUST_EXPECT(...) \
	_expect(TOK_CSL(__VA_ARGS__))

#define EXPECT_AND_GRAB_TOK(name, ...) \
	JUST_EXPECT(__VA_ARGS__); \
	const auto name = prev_lex_tok()
#define EXPECT_IDENT_AND_GRAB_S(name) \
	JUST_EXPECT(MiscIdent); \
	const auto& name = prev_lex_s()

#define _INNER_RGR_INSERT(tok, func) \
	/* Gurantee that the grammar is LL(1) */ \
	if (_rgr_ret_map().count(Tok::tok) > 0) \
	{ \
		lex_file_pos().err(sconcat("rgr_insert():  ", strappcom2(#tok, \
			#func), "Eek!\n")); \
	} \
	\
	_rgr_ret_map()[Tok::tok] = func

#define RGR_INSERT(...) \
	EVAL(MAP_PAIRS(_INNER_RGR_INSERT, SEMICOLON, __VA_ARGS__))

#define BASIC_RG_RULES_PARSE(func) \
	_rg_rules_parse(&Parser::func)
#define FANCY_RG_RULES_PARSE(func, ...) \
	_rg_rules_parse(&Parser::func, TOK_SET(__VA_ARGS__))

#define MAKE_BASIC_RG_RULES_PARSE(parse_ret, func) \
	const auto& parse_ret = BASIC_RG_RULES_PARSE(func)
#define MAKE_FANCY_RG_RULES_PARSE(parse_ret, func, ...) \
	const auto& parse_ret = FANCY_RG_RULES_PARSE(func, __VA_ARGS__)




//#endif		// src_parser_class_defines_hpp
