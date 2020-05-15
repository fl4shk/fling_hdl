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


#define JUST_RG_RULES_PARSE(func, tok_set) \
	_rg_rules_parse(this, &Parser::func, tok_set)

#define _INNER_RGR_INSERT(tok, func) \
	/* Gurantee that the grammar is LL(1) */ \
	if (_rgr_ret_map().count(Tok::tok) > 0) \
	{ \
		lex_file_pos().err(sconcat("rgr_insert():  ", strappcom2(#tok, \
			#func), "Eek!\n")); \
	} \
	\
	_rgr_ret_map()[Tok::tok] = &Parser::func

#define RGR_INSERT(...) \
	EVAL(MAP_PAIRS(_INNER_RGR_INSERT, SEMICOLON, __VA_ARGS__))

#define _INNER_JUST_EXPECT(tok) \
	Tok::tok
#define JUST_EXPECT(first_tok, ...) \
	_expect(EVAL(MAP(_INNER_JUST_EXPECT, COMMA, first_tok, __VA_ARGS__)))

#define EXPECT_AND_GRAB_TOK(name, first_tok, ...) \
	JUST_EXPECT(first_tok, __VA_ARGS__); \
	const auto name = prev_lex_tok()
#define EXPECT_IDENT_AND_GRAB_S(name) \
	JUST_EXPECT(MiscIdent); \
	const auto& name = prev_lex_s()
#define EXPECT_AND_GRAB_N(name, tok) \
	JUST_EXPECT(tok); \
	const auto& name = prev_lex_n()

#define WHILE_NOT_TOK(tok) \
	while (lex_tok() != Tok::tok)


//#endif		// src_parser_class_defines_hpp
