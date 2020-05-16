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

#define DEFER_RESTORE_PARSE_FUNC_STR(str) \
	ParseFuncStrDeferredRestorer deferred_restorer (this, #str)

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


//#endif		// src_parser_class_defines_hpp
