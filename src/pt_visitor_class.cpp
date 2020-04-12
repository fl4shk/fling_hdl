#include "pt_visitor_class.hpp"

namespace fling_hdl
{

using namespace ast;

#define JUST_ACCEPT(pt_node) \
	ctx->pt_node()->accept(this)

#define _INNER_ACCEPT_IFELSE(pt_node) \
	if (ctx->pt_node()) \
	{ \
		JUST_ACCEPT(pt_node); \
	}
#define ACCEPT_IFELSE(...) \
	EVAL(MAP(_INNER_ACCEPT_IFELSE, ELSE, __VA_ARGS__))


#define CHECK(pt_node) \
	if (ctx->pt_node())

#define _INNER_JUST_ACCEPT_AND_POP_AST(to_set, pt_node) \
	JUST_ACCEPT(pt_node); \
	to_set = _pop_ast();
#define _INNER_ACCEPT_AND_POP_AST_IF(to_set, pt_node) \
	CHECK(pt_node) \
	{ \
		_INNER_JUST_ACCEPT_AND_POP_AST(to_set, pt_node); \
	}
#define JUST_ACCEPT_AND_POP_AST(...) \
	EVAL(MAP_PAIRS(_INNER_JUST_ACCEPT_AND_POP_AST, SEMICOLON, __VA_ARGS__))
#define _MULTI_ACCEPT_AND_POP_AST_IF(sep, ...) \
	EVAL(MAP_PAIRS(_INNER_ACCEPT_AND_POP_AST_IF, sep, __VA_ARGS__))
#define ACCEPT_AND_POP_AST_IFELSE(...) \
	_MULTI_ACCEPT_AND_POP_AST_IF(ELSE, __VA_ARGS__)
#define ACCEPT_AND_POP_AST_IF(...) \
	_MULTI_ACCEPT_AND_POP_AST_IF(SEMICOLON, __VA_ARGS__)

#define _INNER_JUST_ACCEPT_AND_POP_AST_LIST(to_set, pt_node) \
	JUST_ACCEPT(pt_node); \
	to_set = move(_pop_ast_list())
#define _INNER_ACCEPT_AND_POP_AST_LIST_IF(to_set, pt_node) \
	CHECK(pt_node) \
	{ \
		_INNER_JUST_ACCEPT_AND_POP_AST_LIST(to_set, pt_node); \
	}
#define JUST_ACCEPT_AND_POP_AST_LIST(...) \
	EVAL(MAP_PAIRS(_INNER_JUST_ACCEPT_AND_POP_AST_LIST, SEMICOLON, \
		__VA_ARGS__))
#define _MULTI_ACCEPT_AND_POP_AST_LIST_IF(sep, ...) \
	EVAL(MAP_PAIRS(_INNER_ACCEPT_AND_POP_AST_LIST_IF, sep, __VA_ARGS__))
#define ACCEPT_AND_POP_AST_LIST_IFELSE(...) \
	_MULTI_ACCEPT_AND_POP_AST_LIST_IF(ELSE, __VA_ARGS__)
#define ACCEPT_AND_POP_AST_LIST_IF(...) \
	_MULTI_ACCEPT_AND_POP_AST_LIST_IF(SEMICOLON, __VA_ARGS__)

#define _INNER_JUST_ACCEPT_AND_POP_NUM(to_set, pt_node) \
	JUST_ACCEPT(pt_node); \
	to_set = _pop_num();
#define _INNER_ACCEPT_AND_POP_NUM_IF(to_set, pt_node) \
	CHECK(pt_node) \
	{ \
		_INNER_JUST_ACCEPT_AND_POP_NUM(to_set, pt_node); \
	}
#define JUST_ACCEPT_AND_POP_NUM(...) \
	EVAL(MAP_PAIRS(_INNER_JUST_ACCEPT_AND_POP_NUM, SEMICOLON, __VA_ARGS__))
#define ACCEPT_AND_POP_NUM_IF(...) \
	EVAL(MAP_PAIRS(_INNER_ACCEPT_AND_POP_NUM_IF, SEMICOLON, __VA_ARGS__))

#define _INNER_JUST_ACCEPT_AND_POP_STR(to_set, pt_node) \
	JUST_ACCEPT(pt_node); \
	to_set = _pop_str();
#define _INNER_ACCEPT_AND_POP_STR_IF(to_set, pt_node) \
	CHECK(pt_node) \
	{ \
		_INNER_JUST_ACCEPT_AND_POP_STR(to_set, pt_node); \
	}
#define JUST_ACCEPT_AND_POP_STR(...) \
	EVAL(MAP_PAIRS(_INNER_JUST_ACCEPT_AND_POP_STR, SEMICOLON, __VA_ARGS__))
#define ACCEPT_AND_POP_STR_IF(...) \
	EVAL(MAP_PAIRS(_INNER_ACCEPT_AND_POP_STR_IF, SEMICOLON, __VA_ARGS__))


template<typename EnumType, typename... RemArgTypes>
inline bool _conv_pt_to_enum(EnumType& ret, bool cmp, EnumType check,
	RemArgTypes&&... rem_args)
{
	if (cmp)
	{
		ret = check;
		return true;
	}
	else if constexpr (sizeof...(rem_args) > 0)
	{
		return _conv_pt_to_enum(ret, rem_args...);
	}
	else
	{
		return false;
	}
}

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

#define FOR_PT(p, pt_node) \
	for (const auto& p: ctx->pt_node())

AstEtc::AstEtc(const string& s_filename)
	: _filename(s_filename)
{
	//antlr4::ANTLRInputStream input(get_istream_as_str(std::ifstream
	//	(s_filename, std::ios_base::in)));
	//FlingHdlGrammarLexer lexer(&input);
	//antlr4::CommonTokenStream tokens(&lexer);
	//tokens.fill();

	//FlingHdlGrammarParser parser(&tokens);
	//parser.removeErrorListeners();
	//unique_ptr<PtVisitorErrorListener>
	//	pt_visitor_error_listener(new PtVisitorErrorListener());
	//parser.addErrorListener(pt_visitor_error_listener.get());

	_input.reset(new antlr4::ANTLRInputStream(get_istream_as_str
		(std::ifstream (s_filename, std::ios_base::in))));
	_lexer.reset(new Lexer(_input.get()));
	_token_stream.reset(new antlr4::CommonTokenStream(_lexer.get()));
	_token_stream->fill();

	_parser.reset(new Parser(_token_stream.get()));
	_parser->removeErrorListeners();
	_error_listener.reset(new PtVisitorErrorListener());
	_parser->addErrorListener(_error_listener.get());
	_program_ctx = _parser->flingProgram();
}

PtVisitor::PtVisitor(set<string>* s_filename_set)
{
	_filename_set = s_filename_set;
	//_program_ctx = parser.flingProgram();


	for (const auto& s_filename: *_filename_set)
	{
		_ast_etc_map[s_filename] = AstEtc(s_filename);
	}
}
PtVisitor::~PtVisitor()
{
}
int PtVisitor::run()
{
	for (auto& p: _ast_etc_map)
	{
		_filename = p.second.filename();
		_ast = new Program(nullptr, FilePos(_filename,
			p.second.program_ctx()));
		_curr_ast_parent = _ast;
		p.second.ast().reset(_ast);
		p.second.set_max_ast_level(0);
		p.second.program_ctx()->accept(this);
	}
	return 0;
}

//--------
antlrcpp::Any PtVisitor::visitFlingProgram
	(Parser::FlingProgramContext *ctx)
{
	FOR_PT(p, flingProgram_Item)
	{
		p->accept(this);
		_ast->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingProgram_Item
	(Parser::FlingProgram_ItemContext *ctx)
{
	ACCEPT_IFELSE
		(flingDeclPackage,
		flingDeclModule,
		flingDeclType,
		flingDeclSubprog,
		flingDeclAlias,
		flingDeclConst)
	else
	{
		internal_err(visitFlingProgram_Item);
	}
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingDeclPackage
	(Parser::FlingDeclPackageContext *ctx)
{
	DEFER_PUSH(node, DeclPackage);

	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);

	FOR_PT(p, flingDeclPackage_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclPackage_Item
	(Parser::FlingDeclPackage_ItemContext *ctx)
{
	ACCEPT_IFELSE
		(flingDeclPackage,
		flingDeclModule,
		flingDeclType,
		flingDeclSubprog,
		flingDeclAlias,
		flingDeclConst)
	else
	{
		internal_err(visitFlingDeclPackage_Item);
	}
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingDeclParamList
	(Parser::FlingDeclParamListContext *ctx)
{
	DEFER_PUSH(node, ParamOrArgList);

	FOR_PT(p, flingDeclParamList_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclParamList_Item
	(Parser::FlingDeclParamList_ItemContext *ctx)
{
	DEFER_PUSH(node, DeclParamList_Item);

	JUST_ACCEPT_AND_POP_AST(node->ident_list, flingIdentList);
	using Kind = DeclParamList_Item::Kind;

	CHECK(flingTypenameOrModname)
	{
		CHECK(KwParpk)
		{
			node->kind = Kind::ParpkVar;
		}
		else
		{
			node->kind = Kind::Var;
			JUST_ACCEPT_AND_POP_AST(node->opt_typename_or_modname,
				flingTypenameOrModname);
			ACCEPT_AND_POP_AST_LIST_IF(node->opt_expr_list, flingExprList);
		}
	}
	else CHECK(KwType)
	{
		CHECK(KwParpk)
		{
			node->kind = Kind::ParpkType;
		}
		else
		{
			node->kind = Kind::Type;

			ACCEPT_AND_POP_AST_LIST_IF(node->opt_typename_or_modname_list,
				flingTypenameOrModnameList);
		}
	}
	else CHECK(KwModule)
	{
		CHECK(KwParpk)
		{
			node->kind = Kind::ParpkModule;
		}
		else
		{
			node->kind = Kind::Module;
			ACCEPT_AND_POP_AST_LIST_IF(node->opt_typename_or_modname_list,
				flingTypenameOrModnameList);
		}
	}
	else
	{
		internal_err(visitFlingDeclParamList_Item);
	}

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingDeclArgList
	(Parser::FlingDeclArgListContext *ctx)
{
	DEFER_PUSH(node, ParamOrArgList);

	FOR_PT(p, flingDeclArgList_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclArgList_Item
	(Parser::FlingDeclArgList_ItemContext *ctx)
{
	DEFER_PUSH(node, DeclArgList_Item);

	JUST_ACCEPT_AND_POP_AST(node->ident_list, flingIdentList);

	using Kind = DeclArgList_Item::Kind;
	CHECK(KwParpk)
	{
		if (!_conv_pt_to_enum(node->kind,
			ctx->KwInput(), Kind::ParpkInput,
			ctx->KwOutput(), Kind::ParpkOutput,
			ctx->KwInout(), Kind::ParpkInout,
			ctx->KwInterface(), Kind::ParpkInterface))
		{
			internal_err(visitFlingDeclArgList_Item);
		}
	}
	else
	{
		if (!_conv_pt_to_enum(node->kind,
			ctx->KwInput(), Kind::Input,
			ctx->KwOutput(), Kind::Output,
			ctx->KwInout(), Kind::Inout,
			ctx->KwInterface(), Kind::Interface))
		{
			internal_err(visitFlingDeclArgList_Item);
		}
	}
	JUST_ACCEPT_AND_POP_AST(node->typename_or_modname,
		flingTypenameOrModname);

	ACCEPT_AND_POP_AST_LIST_IF(node->opt_expr_list, flingExprList);

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingInstParamList
	(Parser::FlingInstParamListContext *ctx)
{
	DEFER_PUSH(node, ParamOrArgList);

	ACCEPT_AND_POP_AST_LIST_IFELSE
		(node->item_list, flingInstParamList_Pos,
		node->item_list, flingInstParamList_Named)
	else
	{
		internal_err(visitFlingInstParamList);
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingInstParamList_Pos
	(Parser::FlingInstParamList_PosContext *ctx)
{
	DEFER_PUSH_LIST(list);

	FOR_PT(p, flingInstParamList_Pos_Item)
	{
		p->accept(this);
		list.push_back(_pop_ast());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingInstParamList_Pos_Item
	(Parser::FlingInstParamList_Pos_ItemContext *ctx)
{
	ACCEPT_IFELSE
		(flingExpr,
		flingTypenameOrModname,
		flingInstParamList_Pos_Item_Parpk,
		flingInstParamList_Pos_Item_Unparpk)
	else
	{
		internal_err(visitFlingInstParamList_Pos_Item);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingInstParamList_Pos_Item_Parpk
	(Parser::FlingInstParamList_Pos_Item_ParpkContext *ctx)
{
	DEFER_PUSH(node, InstParamOrArgList_PosItemParpk);

	ACCEPT_AND_POP_AST_LIST_IFELSE
		(node->item_list, flingExprList,
		node->item_list, flingTypenameOrModnameList)
	else
	{
		internal_err(visitFlingInstParamList_Pos_Item_Parpk);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingInstParamList_Pos_Item_Unparpk
	(Parser::FlingInstParamList_Pos_Item_UnparpkContext *ctx)
{
	DEFER_PUSH(node, InstParamOrArgList_PosItemUnparpk);
	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingInstParamList_Named
	(Parser::FlingInstParamList_NamedContext *ctx)
{
	DEFER_PUSH_LIST(list);

	FOR_PT(p, flingInstParamList_Named_Item)
	{
		p->accept(this);
		list.push_back(_pop_ast());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingInstParamList_Named_Item
	(Parser::FlingInstParamList_Named_ItemContext *ctx)
{
	DEFER_PUSH(node, InstParamList_NamedItem);

	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);
	JUST_ACCEPT_AND_POP_AST(node->item, flingInstParamList_Pos_Item);

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingInstArgList
	(Parser::FlingInstArgListContext *ctx)
{
	DEFER_PUSH(node, ParamOrArgList);

	ACCEPT_AND_POP_AST_LIST_IFELSE
		(node->item_list, flingInstArgList_Pos,
		node->item_list, flingInstArgList_Named)
	else
	{
		internal_err(visitFlingInstArgList);
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingInstArgList_Pos
	(Parser::FlingInstArgList_PosContext *ctx)
{
	DEFER_PUSH_LIST(list);

	FOR_PT(p, flingInstArgList_Pos_Item)
	{
		p->accept(this);
		list.push_back(_pop_ast());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingInstArgList_Pos_Item
	(Parser::FlingInstArgList_Pos_ItemContext *ctx)
{
	ACCEPT_IFELSE
		(flingExpr,
		flingInstArgList_Pos_Item_Parpk,
		flingInstArgList_Pos_Item_Unparpk)
	else
	{
		internal_err(visitFlingInstArgList_Pos_Item);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingInstArgList_Pos_Item_Parpk
	(Parser::FlingInstArgList_Pos_Item_ParpkContext *ctx)
{
	DEFER_PUSH(node, InstParamOrArgList_PosItemParpk);

	JUST_ACCEPT_AND_POP_AST_LIST(node->item_list, flingExprList);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingInstArgList_Pos_Item_Unparpk
	(Parser::FlingInstArgList_Pos_Item_UnparpkContext *ctx)
{
	DEFER_PUSH(node, InstParamOrArgList_PosItemUnparpk);

	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingInstArgList_Named
	(Parser::FlingInstArgList_NamedContext *ctx)
{
	DEFER_PUSH_LIST(list);

	FOR_PT(p, flingInstArgList_Named_Item)
	{
		p->accept(this);
		list.push_back(_pop_ast());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingInstArgList_Named_Item
	(Parser::FlingInstArgList_Named_ItemContext *ctx)
{
	DEFER_PUSH(node, InstArgList_NamedItem);

	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);
	JUST_ACCEPT_AND_POP_AST(node->item, flingInstArgList_Pos_Item);

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingDeclModule
	(Parser::FlingDeclModuleContext *ctx)
{
	DEFER_PUSH(node, DeclModule);

	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);
	ACCEPT_AND_POP_AST_IF(node->opt_param_list, flingDeclParamList);
	JUST_ACCEPT_AND_POP_AST(node->arg_list, flingDeclArgList);
	ACCEPT_AND_POP_AST_IF(node->opt_import_list, flingImportList);
	JUST_ACCEPT_AND_POP_AST_LIST(node->item_list, flingDeclModule_Scope);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclModule_Scope
	(Parser::FlingDeclModule_ScopeContext *ctx)
{
	DEFER_PUSH_LIST(list);

	FOR_PT(p, flingDeclModule_Item)
	{
		p->accept(this);
		list.push_back(_pop_ast());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclModule_Item
	(Parser::FlingDeclModule_ItemContext *ctx)
{
	ACCEPT_IFELSE
		(flingInstModule,
		flingExpr,
		flingDeclModule_Gen,
		flingContAssign,
		flingImportList,

		flingBehav,
		flingDeclWire,
		flingDeclVar,
		flingDeclConst,

		flingDeclType,
		flingDeclSubprog,
		flingDeclAlias)
	else
	{
		internal_err(visitFlingDeclModule_Item);
	}
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingInstModule
	(Parser::FlingInstModuleContext *ctx)
{
	DEFER_PUSH(node, InstModule);

	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);
	JUST_ACCEPT_AND_POP_AST
		(node->typename_or_modname, flingTypenameOrModname,
		node->arg_list, flingInstArgList);

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingDeclModule_Gen
	(Parser::FlingDeclModule_GenContext *ctx)
{
	ACCEPT_IFELSE
		(flingDeclModule_Gen_If,
		flingDeclModule_Gen_Switch,
		flingDeclModule_Gen_For)
	else
	{
		internal_err(visitFlingDeclModule_Gen);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclModule_Gen_If
	(Parser::FlingDeclModule_Gen_IfContext *ctx)
{
	DEFER_PUSH(node, GenIf);

	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);
	JUST_ACCEPT_AND_POP_AST_LIST(node->item_list, flingDeclModule_Scope);

	FOR_PT(p, flingDeclModule_Gen_If_Elif)
	{
		p->accept(this);
		node->elif_list.push_back(_pop_ast());
	}

	ACCEPT_AND_POP_AST_IF(node->opt_else, flingDeclModule_Gen_If_Else);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclModule_Gen_If_Elif
	(Parser::FlingDeclModule_Gen_If_ElifContext *ctx)
{
	DEFER_PUSH(node, GenIf_Elif);
	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);
	JUST_ACCEPT_AND_POP_AST_LIST(node->item_list, flingDeclModule_Scope);
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclModule_Gen_If_Else
	(Parser::FlingDeclModule_Gen_If_ElseContext *ctx)
{
	DEFER_PUSH(node, GenIf_Else);
	JUST_ACCEPT_AND_POP_AST_LIST(node->item_list, flingDeclModule_Scope);
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclModule_Gen_Switch
	(Parser::FlingDeclModule_Gen_SwitchContext *ctx)
{
	DEFER_PUSH(node, GenSwitch);

	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);

	FOR_PT(p, flingDeclModule_Gen_Switch_Case)
	{
		p->accept(this);
		node->opt_case_list.push_back(_pop_ast());
	}

	ACCEPT_AND_POP_AST_IF
		(node->opt_default, flingDeclModule_Gen_Switch_Default);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclModule_Gen_Switch_Default
	(Parser::FlingDeclModule_Gen_Switch_DefaultContext *ctx)
{
	DEFER_PUSH(node, GenSwitch_Default);
	JUST_ACCEPT_AND_POP_AST_LIST(node->item_list, flingDeclModule_Scope);
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclModule_Gen_Switch_Case
	(Parser::FlingDeclModule_Gen_Switch_CaseContext *ctx)
{
	DEFER_PUSH(node, GenSwitch_Case);
	JUST_ACCEPT_AND_POP_AST_LIST
		(node->expr_list, flingExprList,
		node->item_list, flingDeclModule_Scope);
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclModule_Gen_For
	(Parser::FlingDeclModule_Gen_ForContext *ctx)
{
	DEFER_PUSH(node, GenFor);
	ctx->flingIdent().at(0)->accept(this);
	node->label = _pop_str();

	ctx->flingIdent().at(1)->accept(this);
	node->ident = _pop_str();

	JUST_ACCEPT_AND_POP_AST(node->expr, flingExpr);
	JUST_ACCEPT_AND_POP_AST_LIST(node->item_list, flingDeclModule_Scope);
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingContAssign
	(Parser::FlingContAssignContext *ctx)
{
	DEFER_PUSH(node, ContAssign);
	_vec_just_accept_and_pop_ast(ctx->flingExpr(), node->left,
		node->right);
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingBehav
	(Parser::FlingBehavContext *ctx)
{
	DEFER_PUSH(node, Behav);
	using Kind = Behav::Kind;
	if (!_conv_pt_to_enum(node->kind,
		ctx->KwInitial(), Kind::Initial,
		ctx->KwComb(), Kind::Comb,
		ctx->KwSeq(), Kind::Seq))
	{
		internal_err(visitFlingBehav);
	}
	ACCEPT_AND_POP_AST_LIST_IF(node->opt_edge_list,
		flingBehav_Seq_EdgeList);
	JUST_ACCEPT_AND_POP_AST(node->scope, flingBehav_Scope);
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingBehav_Seq_EdgeList
	(Parser::FlingBehav_Seq_EdgeListContext *ctx)
{
	DEFER_PUSH_LIST(list);

	FOR_PT(p, flingBehav_Seq_EdgeList_Item)
	{
		p->accept(this);
		list.push_back(_pop_ast());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Seq_EdgeList_Item
	(Parser::FlingBehav_Seq_EdgeList_ItemContext *ctx)
{
	DEFER_PUSH(node, Behav_SeqEdgeListItem);

	using Kind = Behav_SeqEdgeListItem::Kind;
	if (!_conv_pt_to_enum(node->kind,
		ctx->KwPosedge(), Kind::Posedge,
		ctx->KwNegedge(), Kind::Negedge))
	{
		internal_err(visitFlingBehav_Seq_EdgeList_Item);
	}

	JUST_ACCEPT_AND_POP_AST(node->expr, flingExpr);

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingBehav_Scope
	(Parser::FlingBehav_ScopeContext *ctx)
{
	DEFER_PUSH(node, Behav_Scope);

	FOR_PT(p, flingBehav_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item
	(Parser::FlingBehav_ItemContext *ctx)
{
	ACCEPT_IFELSE
		(flingBehav_Scope,
		flingDeclAlias,
		flingDeclVar,
		flingDeclConst,
		flingDeclType,

		flingBehav_Item_BlkAssign,
		flingBehav_Item_NonBlkAssign,

		flingBehav_Item_Gen,

		flingBehav_Item_If,
		flingBehav_Item_SwitchOrSwitchz,
		flingBehav_Item_For,
		flingBehav_Item_While,

		flingExpr)
	else
	{
		internal_err(visitFlingBehav_Item);
	}
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingBehav_Item_Gen
	(Parser::FlingBehav_Item_GenContext *ctx)
{
	ACCEPT_IFELSE
		(flingBehav_Item_Gen_If,
		flingBehav_Item_Gen_Switch,
		flingBehav_Item_Gen_For)
	else
	{
		internal_err(visitFlingBehav_Item_Gen);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_Gen_If
	(Parser::FlingBehav_Item_Gen_IfContext *ctx)
{
	DEFER_PUSH(node, GenIf);

	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);
	FOR_PT(p, flingBehav_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}

	FOR_PT(p, flingBehav_Item_Gen_If_Elif)
	{
		p->accept(this);
		node->elif_list.push_back(_pop_ast());
	}

	ACCEPT_AND_POP_AST_IF(node->opt_else, flingBehav_Item_Gen_If_Else);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_Gen_If_Elif
	(Parser::FlingBehav_Item_Gen_If_ElifContext *ctx)
{
	DEFER_PUSH(node, GenIf_Elif);
	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);
	FOR_PT(p, flingBehav_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_Gen_If_Else
	(Parser::FlingBehav_Item_Gen_If_ElseContext *ctx)
{
	DEFER_PUSH(node, GenIf_Else);
	FOR_PT(p, flingBehav_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_Gen_Switch
	(Parser::FlingBehav_Item_Gen_SwitchContext *ctx)
{
	DEFER_PUSH(node, GenSwitch);

	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);

	FOR_PT(p, flingBehav_Item_Gen_Switch_Case)
	{
		p->accept(this);
		node->opt_case_list.push_back(_pop_ast());
	}

	ACCEPT_AND_POP_AST_IF
		(node->opt_default, flingBehav_Item_Gen_Switch_Default);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_Gen_Switch_Default
	(Parser::FlingBehav_Item_Gen_Switch_DefaultContext *ctx)
{
	DEFER_PUSH(node, GenSwitch_Default);
	FOR_PT(p, flingBehav_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_Gen_Switch_Case
	(Parser::FlingBehav_Item_Gen_Switch_CaseContext *ctx)
{
	DEFER_PUSH(node, GenSwitch_Case);
	JUST_ACCEPT_AND_POP_AST_LIST
		(node->expr_list, flingExprList);
	FOR_PT(p, flingBehav_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_Gen_For
	(Parser::FlingBehav_Item_Gen_ForContext *ctx)
{
	DEFER_PUSH(node, GenFor);
	ctx->flingIdent().at(0)->accept(this);
	node->label = _pop_str();

	ctx->flingIdent().at(1)->accept(this);
	node->ident = _pop_str();

	JUST_ACCEPT_AND_POP_AST(node->expr, flingExpr);
	FOR_PT(p, flingBehav_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingBehav_Item_If
	(Parser::FlingBehav_Item_IfContext *ctx)
{
	DEFER_PUSH(node, If);

	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);
	JUST_ACCEPT_AND_POP_AST(node->scope, flingBehav_Scope);

	FOR_PT(p, flingBehav_Item_If_Elif)
	{
		p->accept(this);
		node->elif_list.push_back(_pop_ast());
	}

	ACCEPT_AND_POP_AST_IF(node->opt_else, flingBehav_Item_If_Else);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_If_Elif
	(Parser::FlingBehav_Item_If_ElifContext *ctx)
{
	DEFER_PUSH(node, If_Elif);

	JUST_ACCEPT_AND_POP_AST
		(node->cond, flingExpr,
		node->scope, flingBehav_Scope);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_If_Else
	(Parser::FlingBehav_Item_If_ElseContext *ctx)
{
	DEFER_PUSH(node, If_Else);

	JUST_ACCEPT_AND_POP_AST(node->scope, flingBehav_Scope);

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingBehav_Item_SwitchOrSwitchz
	(Parser::FlingBehav_Item_SwitchOrSwitchzContext *ctx)
{
	Switch* node;
	CHECK(KwSwitch)
	{
		node = make_ast(Switch);
	}
	else // CHECK(KwSwitchz)
	{
		node = make_ast(Switchz);
	}
	AstNodeDeferredPusher deferred_pusher(this, node);

	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);

	FOR_PT(p, flingBehav_Item_SwitchOrSwitchz_Case)
	{
		p->accept(this);
		node->opt_case_list.push_back(_pop_ast());
	}

	ACCEPT_AND_POP_AST_IF(node->opt_default,
		flingBehav_Item_SwitchOrSwitchz_Default);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_SwitchOrSwitchz_Default
	(Parser::FlingBehav_Item_SwitchOrSwitchz_DefaultContext *ctx)
{
	DEFER_PUSH(node, SwitchOrSwitchz_Default);

	JUST_ACCEPT_AND_POP_AST(node->scope, flingBehav_Scope);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_SwitchOrSwitchz_Case
	(Parser::FlingBehav_Item_SwitchOrSwitchz_CaseContext *ctx)
{
	DEFER_PUSH(node, SwitchOrSwitchz_Case);

	JUST_ACCEPT_AND_POP_AST_LIST(node->expr_list, flingExprList);
	JUST_ACCEPT_AND_POP_AST(node->scope, flingBehav_Scope);

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingBehav_Item_For
	(Parser::FlingBehav_Item_ForContext *ctx)
{
	DEFER_PUSH(node, For);

	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);
	JUST_ACCEPT_AND_POP_AST
		(node->expr, flingExpr,
		node->scope, flingBehav_Scope);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_While
	(Parser::FlingBehav_Item_WhileContext *ctx)
{
	DEFER_PUSH(node, While);

	JUST_ACCEPT_AND_POP_AST
		(node->expr, flingExpr,
		node->scope, flingBehav_Scope);

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingBehav_Item_NonBlkAssign
	(Parser::FlingBehav_Item_NonBlkAssignContext *ctx)
{
	DEFER_PUSH(node, NonBlkAssign);

	_vec_just_accept_and_pop_ast(ctx->flingExpr(), node->left,
		node->right);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_BlkAssign
	(Parser::FlingBehav_Item_BlkAssignContext *ctx)
{
	DEFER_PUSH(node, BlkAssign);

	_vec_just_accept_and_pop_ast(ctx->flingExpr(), node->left,
		node->right);

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingDeclWire
	(Parser::FlingDeclWireContext *ctx)
{
	DEFER_PUSH(node, DeclWire);

	JUST_ACCEPT_AND_POP_AST
		(node->ident_list, flingIdentList,
		node->typename_or_modname, flingTypenameOrModname);
	ACCEPT_AND_POP_AST_LIST_IF(node->opt_expr_list, flingExprList);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclVar
	(Parser::FlingDeclVarContext *ctx)
{
	DEFER_PUSH(node, DeclVar);

	JUST_ACCEPT_AND_POP_AST
		(node->ident_list, flingIdentList,
		node->typename_or_modname, flingTypenameOrModname);
	ACCEPT_AND_POP_AST_LIST_IF(node->opt_expr_list, flingExprList);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclConst
	(Parser::FlingDeclConstContext *ctx)
{
	DEFER_PUSH(node, DeclConst);

	JUST_ACCEPT_AND_POP_AST
		(node->ident_list, flingIdentList,
		node->typename_or_modname, flingTypenameOrModname);
	JUST_ACCEPT_AND_POP_AST_LIST(node->expr_list, flingExprList);

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingDeclType
	(Parser::FlingDeclTypeContext *ctx)
{
	ACCEPT_IFELSE
		(flingDeclEnum,
		flingDeclClass,
		flingDeclMixin)
	else
	{
		internal_err(visitFlingDeclType);
	}
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingDeclEnum
	(Parser::FlingDeclEnumContext *ctx)
{
	DEFER_PUSH(node, DeclEnum);

	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);
	ACCEPT_AND_POP_AST_IF(node->opt_typename_or_modname,
		flingTypenameOrModname);
	JUST_ACCEPT_AND_POP_AST(node->ident_list, flingIdentList);

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingDeclClass
	(Parser::FlingDeclClassContext *ctx)
{
	DEFER_PUSH(node, DeclClass);

	node->is_base = ctx->KwBase();
	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);
	ACCEPT_AND_POP_AST_IF(node->opt_param_list, flingDeclParamList);
	ACCEPT_AND_POP_AST_LIST_IF
		(node->opt_extends, flingDeclClsOrMxn_Extends);

	FOR_PT(p, flingDeclClass_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}

	node->is_signed = ctx->KwSigned();
	node->is_packed = ctx->KwPacked();

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClsOrMxn_Extends
	(Parser::FlingDeclClsOrMxn_ExtendsContext *ctx)
{
	JUST_ACCEPT(flingTypenameOrModnameList);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClass_Item
	(Parser::FlingDeclClass_ItemContext *ctx)
{
	ACCEPT_IFELSE
		(flingDeclClass_Item_DeclVar,
		flingDeclClass_Item_Gen,
		flingDeclClsOrMxn_Item)
	else
	{
		internal_err(visitFlingDeclClass_Item);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClass_Item_DeclVar
	(Parser::FlingDeclClass_Item_DeclVarContext *ctx)
{
	DEFER_PUSH(node, DeclClass_DeclVar);

	CHECK(flingDeclClsOrMxn_AccessSpecifier)
	{
		JUST_ACCEPT(flingDeclClsOrMxn_AccessSpecifier);
		node->acc_spec = static_cast<AccSpec>(conv_bignum_to<size_t>
			(_pop_num()));
	}
	node->is_static = ctx->KwStatic();
	JUST_ACCEPT_AND_POP_AST(node->decl_var, flingDeclVar);

	return nullptr;
}
//--------


//--------
antlrcpp::Any PtVisitor::visitFlingDeclClass_Item_Gen
	(Parser::FlingDeclClass_Item_GenContext *ctx)
{
	ACCEPT_IFELSE
		(flingDeclClass_Item_Gen_If,
		flingDeclClass_Item_Gen_Switch,
		flingDeclClass_Item_Gen_For)
	else
	{
		internal_err(visitFlingDeclClass_Item_Gen);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClass_Item_Gen_If
	(Parser::FlingDeclClass_Item_Gen_IfContext *ctx)
{
	DEFER_PUSH(node, GenIf);

	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);
	FOR_PT(p, flingDeclClass_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}

	FOR_PT(p, flingDeclClass_Item_Gen_If_Elif)
	{
		p->accept(this);
		node->elif_list.push_back(_pop_ast());
	}

	ACCEPT_AND_POP_AST_IF(node->opt_else, flingDeclClass_Item_Gen_If_Else);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClass_Item_Gen_If_Elif
	(Parser::FlingDeclClass_Item_Gen_If_ElifContext *ctx)
{
	DEFER_PUSH(node, GenIf_Elif);
	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);
	FOR_PT(p, flingDeclClass_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClass_Item_Gen_If_Else
	(Parser::FlingDeclClass_Item_Gen_If_ElseContext *ctx)
{
	DEFER_PUSH(node, GenIf_Else);
	FOR_PT(p, flingDeclClass_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClass_Item_Gen_Switch
	(Parser::FlingDeclClass_Item_Gen_SwitchContext *ctx)
{
	DEFER_PUSH(node, GenSwitch);

	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);

	FOR_PT(p, flingDeclClass_Item_Gen_Switch_Case)
	{
		p->accept(this);
		node->opt_case_list.push_back(_pop_ast());
	}

	ACCEPT_AND_POP_AST_IF
		(node->opt_default, flingDeclClass_Item_Gen_Switch_Default);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClass_Item_Gen_Switch_Default
	(Parser::FlingDeclClass_Item_Gen_Switch_DefaultContext *ctx)
{
	DEFER_PUSH(node, GenSwitch_Default);
	FOR_PT(p, flingDeclClass_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClass_Item_Gen_Switch_Case
	(Parser::FlingDeclClass_Item_Gen_Switch_CaseContext *ctx)
{
	DEFER_PUSH(node, GenSwitch_Case);
	JUST_ACCEPT_AND_POP_AST_LIST
		(node->expr_list, flingExprList);
	FOR_PT(p, flingDeclClass_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClass_Item_Gen_For
	(Parser::FlingDeclClass_Item_Gen_ForContext *ctx)
{
	DEFER_PUSH(node, GenFor);
	ctx->flingIdent().at(0)->accept(this);
	node->label = _pop_str();

	ctx->flingIdent().at(1)->accept(this);
	node->ident = _pop_str();

	JUST_ACCEPT_AND_POP_AST(node->expr, flingExpr);
	FOR_PT(p, flingDeclClass_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingDeclClsOrMxn_Item
	(Parser::FlingDeclClsOrMxn_ItemContext *ctx)
{
	ACCEPT_IFELSE
		(flingDeclClsOrMxn_Item_DeclType,
		flingDeclClsOrMxn_Item_DeclAliasOrConst,
		flingDeclClsOrMxn_Item_DeclSubprog,

		flingImportList)
	else
	{
		internal_err(visitFlingDeclClsOrMxn_Item);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClsOrMxn_Item_DeclType
	(Parser::FlingDeclClsOrMxn_Item_DeclTypeContext *ctx)
{
	DEFER_PUSH(node, DeclClsOrMxn_DeclType);

	CHECK(flingDeclClsOrMxn_AccessSpecifier)
	{
		JUST_ACCEPT(flingDeclClsOrMxn_AccessSpecifier);
		node->acc_spec = static_cast<AccSpec>(conv_bignum_to<size_t>
			(_pop_num()));
	}
	JUST_ACCEPT_AND_POP_AST(node->decl_type, flingDeclType);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClsOrMxn_Item_DeclAliasOrConst
	(Parser::FlingDeclClsOrMxn_Item_DeclAliasOrConstContext *ctx)
{
	DEFER_PUSH(node, DeclClsOrMxn_DeclAliasOrConst);

	CHECK(flingDeclClsOrMxn_AccessSpecifier)
	{
		JUST_ACCEPT(flingDeclClsOrMxn_AccessSpecifier);
		node->acc_spec = static_cast<AccSpec>(conv_bignum_to<size_t>
			(_pop_num()));
	}

	node->is_static = ctx->KwStatic();
	CHECK(flingDeclAlias)
	{
		JUST_ACCEPT_AND_POP_AST(node->decl_alias_or_const, flingDeclAlias);
	}
	else CHECK(flingDeclConst)
	{
		JUST_ACCEPT_AND_POP_AST(node->decl_alias_or_const, flingDeclConst);
	}
	else
	{
		internal_err(visitFlingDeclClsOrMxn_Item_DeclAliasOrConst);
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClsOrMxn_AccessSpecifier
	(Parser::FlingDeclClsOrMxn_AccessSpecifierContext *ctx)
{
	CHECK(KwPub)
	{
		_push_num(static_cast<size_t>(AccSpec::Pub));
	}
	else CHECK(KwProt)
	{
		_push_num(static_cast<size_t>(AccSpec::Prot));
	}
	else CHECK(KwPriv)
	{
		_push_num(static_cast<size_t>(AccSpec::Priv));
	}
	else
	{
		internal_err(visitFlingDeclClsOrMxn_AccessSpecifier);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClsOrMxn_Item_DeclSubprog
	(Parser::FlingDeclClsOrMxn_Item_DeclSubprogContext *ctx)
{
	ACCEPT_IFELSE
		(flingDeclClsOrMxn_Item_DeclSubprog_FullDefn,
		flingDeclClsOrMxn_Item_DeclSubprog_Abstract)
	else
	{
		internal_err(visitFlingDeclClsOrMxn_Item_DeclSubprog);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClsOrMxn_Item_DeclSubprog_FullDefn
	(Parser::FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext *ctx)
{
	DEFER_PUSH(node, DeclClsOrMxn_DeclSubprogFullDefn);

	CHECK(flingDeclClsOrMxn_AccessSpecifier)
	{
		JUST_ACCEPT(flingDeclClsOrMxn_AccessSpecifier);
		node->acc_spec = static_cast<AccSpec>(conv_bignum_to<size_t>
			(_pop_num()));
	}

	node->is_virtual = ctx->KwVirtual();
	node->is_static = ctx->KwStatic();
	node->is_const = ctx->KwConst();

	ACCEPT_AND_POP_AST_IFELSE
		(node->subprog, flingDeclFunc,
		node->subprog, flingDeclTask,
		node->subprog, flingDeclProc)
	else
	{
		internal_err(visitFlingDeclClsOrMxn_Item_DeclSubprog_FullDefn);
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClsOrMxn_Item_DeclSubprog_Abstract
	(Parser::FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext *ctx)
{
	DEFER_PUSH(node, DeclClsOrMxn_DeclSubprogAbstract);

	CHECK(flingDeclClsOrMxn_AccessSpecifier)
	{
		JUST_ACCEPT(flingDeclClsOrMxn_AccessSpecifier);
		node->acc_spec = static_cast<AccSpec>(conv_bignum_to<size_t>
			(_pop_num()));
	}

	node->is_const = ctx->KwConst();

	ACCEPT_AND_POP_AST_IFELSE
		(node->header, flingDeclFunc_Header,
		node->header, flingDeclTask_Header)
	else
	{
		internal_err(visitFlingDeclClsOrMxn_Item_DeclSubprog_Abstract);
	}

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingDeclMixin
	(Parser::FlingDeclMixinContext *ctx)
{
	DEFER_PUSH(node, DeclMixin);

	node->is_base = ctx->KwBase();
	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);

	ACCEPT_AND_POP_AST_IF(node->opt_param_list, flingDeclParamList);
	ACCEPT_AND_POP_AST_LIST_IF(node->opt_extends,
		flingDeclClsOrMxn_Extends);

	FOR_PT(p, flingDeclMixin_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclMixin_Item
	(Parser::FlingDeclMixin_ItemContext *ctx)
{
	ACCEPT_IFELSE
		(flingDeclMixin_Item_Gen,
		flingDeclClsOrMxn_Item)
	else
	{
		internal_err(visitFlingDeclMixin_Item);
	}
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingDeclMixin_Item_Gen
	(Parser::FlingDeclMixin_Item_GenContext *ctx)
{
	ACCEPT_IFELSE
		(flingDeclMixin_Item_Gen_If,
		flingDeclMixin_Item_Gen_Switch,
		flingDeclMixin_Item_Gen_For)
	else
	{
		internal_err(visitFlingDeclMixin_Item_Gen);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclMixin_Item_Gen_If
	(Parser::FlingDeclMixin_Item_Gen_IfContext *ctx)
{
	DEFER_PUSH(node, GenIf);

	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);
	FOR_PT(p, flingDeclMixin_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}

	FOR_PT(p, flingDeclMixin_Item_Gen_If_Elif)
	{
		p->accept(this);
		node->elif_list.push_back(_pop_ast());
	}

	ACCEPT_AND_POP_AST_IF(node->opt_else, flingDeclMixin_Item_Gen_If_Else);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclMixin_Item_Gen_If_Elif
	(Parser::FlingDeclMixin_Item_Gen_If_ElifContext *ctx)
{
	DEFER_PUSH(node, GenIf_Elif);
	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);
	FOR_PT(p, flingDeclMixin_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclMixin_Item_Gen_If_Else
	(Parser::FlingDeclMixin_Item_Gen_If_ElseContext *ctx)
{
	DEFER_PUSH(node, GenIf_Else);
	FOR_PT(p, flingDeclMixin_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclMixin_Item_Gen_Switch
	(Parser::FlingDeclMixin_Item_Gen_SwitchContext *ctx)
{
	DEFER_PUSH(node, GenSwitch);

	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);

	FOR_PT(p, flingDeclMixin_Item_Gen_Switch_Case)
	{
		p->accept(this);
		node->opt_case_list.push_back(_pop_ast());
	}

	ACCEPT_AND_POP_AST_IF
		(node->opt_default, flingDeclMixin_Item_Gen_Switch_Default);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclMixin_Item_Gen_Switch_Default
	(Parser::FlingDeclMixin_Item_Gen_Switch_DefaultContext *ctx)
{
	DEFER_PUSH(node, GenSwitch_Default);
	FOR_PT(p, flingDeclMixin_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclMixin_Item_Gen_Switch_Case
	(Parser::FlingDeclMixin_Item_Gen_Switch_CaseContext *ctx)
{
	DEFER_PUSH(node, GenSwitch_Case);
	JUST_ACCEPT_AND_POP_AST_LIST
		(node->expr_list, flingExprList);
	FOR_PT(p, flingDeclMixin_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclMixin_Item_Gen_For
	(Parser::FlingDeclMixin_Item_Gen_ForContext *ctx)
{
	DEFER_PUSH(node, GenFor);
	ctx->flingIdent().at(0)->accept(this);
	node->label = _pop_str();

	ctx->flingIdent().at(1)->accept(this);
	node->ident = _pop_str();

	JUST_ACCEPT_AND_POP_AST(node->expr, flingExpr);
	FOR_PT(p, flingDeclMixin_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingDeclSubprog
	(Parser::FlingDeclSubprogContext *ctx)
{
	ACCEPT_IFELSE
		(flingDeclFunc,
		flingDeclTask,
		flingDeclProc)
	else
	{
		internal_err(visitFlingDeclSubprog);
	}
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingDeclFunc
	(Parser::FlingDeclFuncContext *ctx)
{
	DEFER_PUSH(node, DeclFunc);

	JUST_ACCEPT_AND_POP_AST
		(node->header, flingDeclFunc_Header,
		node->scope, flingDeclFunc_Scope);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Header
	(Parser::FlingDeclFunc_HeaderContext *ctx)
{
	DEFER_PUSH(node, DeclFunc_Header);

	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);
	ACCEPT_AND_POP_AST_IF(node->opt_param_list, flingDeclParamList);
	JUST_ACCEPT_AND_POP_AST
		(node->arg_list, flingDeclArgList,
		node->return_typename, flingTypenameOrModname);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Scope
	(Parser::FlingDeclFunc_ScopeContext *ctx)
{
	DEFER_PUSH(node, Behav_Scope);

	FOR_PT(p, flingDeclFunc_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item
	(Parser::FlingDeclFunc_ItemContext *ctx)
{
	CHECK(flingExpr)
	{
		CHECK(KwReturn)
		{
			DEFER_PUSH(node, DeclFunc_Return);

			JUST_ACCEPT_AND_POP_AST(node->expr, flingExpr);
		}
		else CHECK(KwDefer)
		{
			DEFER_PUSH(node, DeclFunc_Defer);

			JUST_ACCEPT_AND_POP_AST(node->expr, flingExpr);
		}
		else
		{
			JUST_ACCEPT(flingExpr);
		}
	}
	else ACCEPT_IFELSE
		(flingDeclFunc_Scope,
		flingDeclAlias,
		flingDeclVar,
		flingDeclConst,
		flingDeclType,

		flingBehav_Item_BlkAssign,

		flingDeclFunc_Item_Gen,

		flingDeclFunc_Item_If,
		flingDeclFunc_Item_SwitchOrSwitchz,
		flingDeclFunc_Item_For,
		flingDeclFunc_Item_While)
	else
	{
		internal_err(visitFlingDeclFunc_Item);
	}
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_Gen
	(Parser::FlingDeclFunc_Item_GenContext *ctx)
{
	ACCEPT_IFELSE
		(flingDeclFunc_Item_Gen_If,
		flingDeclFunc_Item_Gen_Switch,
		flingDeclFunc_Item_Gen_For)
	else
	{
		internal_err(visitFlingDeclFunc_Item_Gen);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_Gen_If
	(Parser::FlingDeclFunc_Item_Gen_IfContext *ctx)
{
	DEFER_PUSH(node, GenIf);

	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);
	FOR_PT(p, flingDeclFunc_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}

	FOR_PT(p, flingDeclFunc_Item_Gen_If_Elif)
	{
		p->accept(this);
		node->elif_list.push_back(_pop_ast());
	}

	ACCEPT_AND_POP_AST_IF(node->opt_else, flingDeclFunc_Item_Gen_If_Else);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_Gen_If_Elif
	(Parser::FlingDeclFunc_Item_Gen_If_ElifContext *ctx)
{
	DEFER_PUSH(node, GenIf_Elif);
	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);
	FOR_PT(p, flingDeclFunc_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_Gen_If_Else
	(Parser::FlingDeclFunc_Item_Gen_If_ElseContext *ctx)
{
	DEFER_PUSH(node, GenIf_Else);
	FOR_PT(p, flingDeclFunc_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_Gen_Switch
	(Parser::FlingDeclFunc_Item_Gen_SwitchContext *ctx)
{
	DEFER_PUSH(node, GenSwitch);

	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);

	FOR_PT(p, flingDeclFunc_Item_Gen_Switch_Case)
	{
		p->accept(this);
		node->opt_case_list.push_back(_pop_ast());
	}

	ACCEPT_AND_POP_AST_IF
		(node->opt_default, flingDeclFunc_Item_Gen_Switch_Default);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_Gen_Switch_Default
	(Parser::FlingDeclFunc_Item_Gen_Switch_DefaultContext *ctx)
{
	DEFER_PUSH(node, GenSwitch_Default);
	FOR_PT(p, flingDeclFunc_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_Gen_Switch_Case
	(Parser::FlingDeclFunc_Item_Gen_Switch_CaseContext *ctx)
{
	DEFER_PUSH(node, GenSwitch_Case);
	JUST_ACCEPT_AND_POP_AST_LIST
		(node->expr_list, flingExprList);
	FOR_PT(p, flingDeclFunc_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_Gen_For
	(Parser::FlingDeclFunc_Item_Gen_ForContext *ctx)
{
	DEFER_PUSH(node, GenFor);
	ctx->flingIdent().at(0)->accept(this);
	node->label = _pop_str();

	ctx->flingIdent().at(1)->accept(this);
	node->ident = _pop_str();

	JUST_ACCEPT_AND_POP_AST(node->expr, flingExpr);
	FOR_PT(p, flingDeclFunc_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_If
	(Parser::FlingDeclFunc_Item_IfContext *ctx)
{
	DEFER_PUSH(node, If);

	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);
	JUST_ACCEPT_AND_POP_AST(node->scope, flingDeclFunc_Scope);

	FOR_PT(p, flingDeclFunc_Item_If_Elif)
	{
		p->accept(this);
		node->elif_list.push_back(_pop_ast());
	}

	ACCEPT_AND_POP_AST_IF(node->opt_else, flingDeclFunc_Item_If_Else);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_If_Elif
	(Parser::FlingDeclFunc_Item_If_ElifContext *ctx)
{
	DEFER_PUSH(node, If_Elif);

	JUST_ACCEPT_AND_POP_AST
		(node->cond, flingExpr,
		node->scope, flingDeclFunc_Scope);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_If_Else
	(Parser::FlingDeclFunc_Item_If_ElseContext *ctx)
{
	DEFER_PUSH(node, If_Else);

	JUST_ACCEPT_AND_POP_AST(node->scope, flingDeclFunc_Scope);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_SwitchOrSwitchz
	(Parser::FlingDeclFunc_Item_SwitchOrSwitchzContext *ctx)
{
	Switch* node;
	CHECK(KwSwitch)
	{
		node = make_ast(Switch);
	}
	else // CHECK(KwSwitchz)
	{
		node = make_ast(Switchz);
	}
	AstNodeDeferredPusher deferred_pusher(this, node);

	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);

	FOR_PT(p, flingDeclFunc_Item_SwitchOrSwitchz_Case)
	{
		p->accept(this);
		node->opt_case_list.push_back(_pop_ast());
	}

	ACCEPT_AND_POP_AST_IF(node->opt_default,
		flingDeclFunc_Item_SwitchOrSwitchz_Default);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_SwitchOrSwitchz_Default
	(Parser::FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext *ctx)
{
	DEFER_PUSH(node, SwitchOrSwitchz_Default);

	JUST_ACCEPT_AND_POP_AST(node->scope, flingDeclFunc_Scope);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_SwitchOrSwitchz_Case
	(Parser::FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext *ctx)
{
	DEFER_PUSH(node, SwitchOrSwitchz_Case);

	JUST_ACCEPT_AND_POP_AST_LIST(node->expr_list, flingExprList);
	JUST_ACCEPT_AND_POP_AST(node->scope, flingDeclFunc_Scope);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_For
	(Parser::FlingDeclFunc_Item_ForContext *ctx)
{
	DEFER_PUSH(node, For);

	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);
	JUST_ACCEPT_AND_POP_AST
		(node->expr, flingExpr,
		node->scope, flingDeclFunc_Scope);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_While
	(Parser::FlingDeclFunc_Item_WhileContext *ctx)
{
	DEFER_PUSH(node, While);

	JUST_ACCEPT_AND_POP_AST
		(node->expr, flingExpr,
		node->scope, flingDeclFunc_Scope);

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingDeclTask
	(Parser::FlingDeclTaskContext *ctx)
{
	DEFER_PUSH(node, DeclTask);

	JUST_ACCEPT_AND_POP_AST
		(node->header, flingDeclTask_Header,
		node->scope, flingDeclTask_Scope);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Header
	(Parser::FlingDeclTask_HeaderContext *ctx)
{
	DEFER_PUSH(node, DeclTask_Header);

	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);
	ACCEPT_AND_POP_AST_IF(node->opt_param_list, flingDeclParamList);
	JUST_ACCEPT_AND_POP_AST(node->arg_list, flingDeclArgList);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Scope
	(Parser::FlingDeclTask_ScopeContext *ctx)
{
	DEFER_PUSH(node, Behav_Scope);

	FOR_PT(p, flingDeclTask_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item
	(Parser::FlingDeclTask_ItemContext *ctx)
{
	ACCEPT_IFELSE
		(flingDeclTask_Scope,
		flingDeclAlias,

		flingDeclVar,
		flingDeclConst,
		flingDeclType,

		flingBehav_Item_BlkAssign,
		flingBehav_Item_NonBlkAssign,

		flingDeclTask_Item_Gen,

		flingDeclTask_Item_If,
		flingDeclTask_Item_SwitchOrSwitchz,
		flingDeclTask_Item_For,
		flingDeclTask_Item_While,

		// Call a `func` or a `task`
		flingExpr)
	else
	{
		internal_err(visitFlingDeclTask_Item);
	}
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_Gen
	(Parser::FlingDeclTask_Item_GenContext *ctx)
{
	ACCEPT_IFELSE
		(flingDeclTask_Item_Gen_If,
		flingDeclTask_Item_Gen_Switch,
		flingDeclTask_Item_Gen_For)
	else
	{
		internal_err(visitFlingDeclTask_Item_Gen);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_Gen_If
	(Parser::FlingDeclTask_Item_Gen_IfContext *ctx)
{
	DEFER_PUSH(node, GenIf);

	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);
	FOR_PT(p, flingDeclTask_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}

	FOR_PT(p, flingDeclTask_Item_Gen_If_Elif)
	{
		p->accept(this);
		node->elif_list.push_back(_pop_ast());
	}

	ACCEPT_AND_POP_AST_IF(node->opt_else, flingDeclTask_Item_Gen_If_Else);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_Gen_If_Elif
	(Parser::FlingDeclTask_Item_Gen_If_ElifContext *ctx)
{
	DEFER_PUSH(node, GenIf_Elif);
	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);
	FOR_PT(p, flingDeclTask_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_Gen_If_Else
	(Parser::FlingDeclTask_Item_Gen_If_ElseContext *ctx)
{
	DEFER_PUSH(node, GenIf_Else);
	FOR_PT(p, flingDeclTask_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_Gen_Switch
	(Parser::FlingDeclTask_Item_Gen_SwitchContext *ctx)
{
	DEFER_PUSH(node, GenSwitch);

	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);

	FOR_PT(p, flingDeclTask_Item_Gen_Switch_Case)
	{
		p->accept(this);
		node->opt_case_list.push_back(_pop_ast());
	}

	ACCEPT_AND_POP_AST_IF
		(node->opt_default, flingDeclTask_Item_Gen_Switch_Default);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_Gen_Switch_Default
	(Parser::FlingDeclTask_Item_Gen_Switch_DefaultContext *ctx)
{
	DEFER_PUSH(node, GenSwitch_Default);
	FOR_PT(p, flingDeclTask_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_Gen_Switch_Case
	(Parser::FlingDeclTask_Item_Gen_Switch_CaseContext *ctx)
{
	DEFER_PUSH(node, GenSwitch_Case);
	JUST_ACCEPT_AND_POP_AST_LIST
		(node->expr_list, flingExprList);
	FOR_PT(p, flingDeclTask_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_Gen_For
	(Parser::FlingDeclTask_Item_Gen_ForContext *ctx)
{
	DEFER_PUSH(node, GenFor);
	ctx->flingIdent().at(0)->accept(this);
	node->label = _pop_str();

	ctx->flingIdent().at(1)->accept(this);
	node->ident = _pop_str();

	JUST_ACCEPT_AND_POP_AST(node->expr, flingExpr);
	FOR_PT(p, flingDeclTask_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_If
	(Parser::FlingDeclTask_Item_IfContext *ctx)
{
	DEFER_PUSH(node, If);

	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);
	JUST_ACCEPT_AND_POP_AST(node->scope, flingDeclTask_Scope);

	FOR_PT(p, flingDeclTask_Item_If_Elif)
	{
		p->accept(this);
		node->elif_list.push_back(_pop_ast());
	}

	ACCEPT_AND_POP_AST_IF(node->opt_else, flingDeclTask_Item_If_Else);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_If_Elif
	(Parser::FlingDeclTask_Item_If_ElifContext *ctx)
{
	DEFER_PUSH(node, If_Elif);

	JUST_ACCEPT_AND_POP_AST
		(node->cond, flingExpr,
		node->scope, flingDeclTask_Scope);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_If_Else
	(Parser::FlingDeclTask_Item_If_ElseContext *ctx)
{
	DEFER_PUSH(node, If_Else);

	JUST_ACCEPT_AND_POP_AST(node->scope, flingDeclTask_Scope);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_SwitchOrSwitchz
	(Parser::FlingDeclTask_Item_SwitchOrSwitchzContext *ctx)
{
	Switch* node;
	CHECK(KwSwitch)
	{
		node = make_ast(Switch);
	}
	else // CHECK(KwSwitchz)
	{
		node = make_ast(Switchz);
	}
	AstNodeDeferredPusher deferred_pusher(this, node);

	JUST_ACCEPT_AND_POP_AST(node->cond, flingExpr);

	FOR_PT(p, flingDeclTask_Item_SwitchOrSwitchz_Case)
	{
		p->accept(this);
		node->opt_case_list.push_back(_pop_ast());
	}

	ACCEPT_AND_POP_AST_IF(node->opt_default,
		flingDeclTask_Item_SwitchOrSwitchz_Default);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_SwitchOrSwitchz_Default
	(Parser::FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext *ctx)
{
	DEFER_PUSH(node, SwitchOrSwitchz_Default);

	JUST_ACCEPT_AND_POP_AST(node->scope, flingDeclTask_Scope);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_SwitchOrSwitchz_Case
	(Parser::FlingDeclTask_Item_SwitchOrSwitchz_CaseContext *ctx)
{
	DEFER_PUSH(node, SwitchOrSwitchz_Case);

	JUST_ACCEPT_AND_POP_AST_LIST(node->expr_list, flingExprList);
	JUST_ACCEPT_AND_POP_AST(node->scope, flingDeclTask_Scope);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_For
	(Parser::FlingDeclTask_Item_ForContext *ctx)
{
	DEFER_PUSH(node, For);

	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);
	JUST_ACCEPT_AND_POP_AST
		(node->expr, flingExpr,
		node->scope, flingDeclTask_Scope);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_While
	(Parser::FlingDeclTask_Item_WhileContext *ctx)
{
	DEFER_PUSH(node, While);

	JUST_ACCEPT_AND_POP_AST
		(node->expr, flingExpr,
		node->scope, flingDeclTask_Scope);

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingDeclProc
	(Parser::FlingDeclProcContext *ctx)
{
	DEFER_PUSH(node, DeclProc);

	JUST_ACCEPT_AND_POP_AST(node->header, flingDeclProc_Header);
	JUST_ACCEPT_AND_POP_AST_LIST(node->item_list, flingDeclModule_Scope);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclProc_Header
	(Parser::FlingDeclProc_HeaderContext *ctx)
{
	DEFER_PUSH(node, DeclProc_Header);

	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);
	ACCEPT_AND_POP_AST_IF(node->opt_param_list, flingDeclParamList);
	JUST_ACCEPT_AND_POP_AST(node->arg_list, flingDeclProc_ArgList);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclProc_ArgList
	(Parser::FlingDeclProc_ArgListContext *ctx)
{
	DEFER_PUSH(node, ParamOrArgList);

	FOR_PT(p, flingDeclProc_ArgList_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclProc_ArgList_Item
	(Parser::FlingDeclProc_ArgList_ItemContext *ctx)
{
	DEFER_PUSH(node, DeclArgList_Item);

	JUST_ACCEPT_AND_POP_AST(node->ident_list, flingIdentList);
	using Kind = DeclArgList_Item::Kind;

	CHECK(KwParpk)
	{
		if (!_conv_pt_to_enum(node->kind,
			ctx->KwInput(), Kind::ParpkInput,
			ctx->KwInout(), Kind::ParpkInout))
		{
			internal_err(visitFlingDeclProc_ArgList_Item);
		}
	}
	else
	{
		if (!_conv_pt_to_enum(node->kind,
			ctx->KwInput(), Kind::Input,
			ctx->KwInout(), Kind::Inout))
		{
			internal_err(visitFlingDeclProc_ArgList_Item);
		}
	}
	JUST_ACCEPT_AND_POP_AST(node->typename_or_modname,
		flingTypenameOrModname);

	ACCEPT_AND_POP_AST_LIST_IF(node->opt_expr_list, flingExprList);

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingDeclAlias
	(Parser::FlingDeclAliasContext *ctx)
{
	ACCEPT_IFELSE
		(flingDeclAlias_Value,
		flingDeclAlias_Type,
		flingDeclAlias_Module)
	else
	{
		internal_err(visitFlingDeclAlias);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclAlias_Value
	(Parser::FlingDeclAlias_ValueContext *ctx)
{
	DEFER_PUSH(node, DeclAlias_Value);

	JUST_ACCEPT_AND_POP_AST
		(node->ident_list, flingIdentList,
		node->typename_or_modname, flingTypenameOrModname);
	JUST_ACCEPT_AND_POP_AST_LIST(node->expr_list, flingExprList);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclAlias_Type
	(Parser::FlingDeclAlias_TypeContext *ctx)
{
	DEFER_PUSH(node, DeclAlias_Type);

	JUST_ACCEPT_AND_POP_AST(node->ident_list, flingIdentList);
	JUST_ACCEPT_AND_POP_AST_LIST(node->typename_or_modname_list,
		flingTypenameOrModnameList);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclAlias_Module
	(Parser::FlingDeclAlias_ModuleContext *ctx)
{
	DEFER_PUSH(node, DeclAlias_Module);

	JUST_ACCEPT_AND_POP_AST(node->ident_list, flingIdentList);
	JUST_ACCEPT_AND_POP_AST_LIST(node->typename_or_modname_list,
		flingTypenameOrModnameList);

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingIdent
	(Parser::FlingIdentContext *ctx)
{
	// Not sure if this is correct
	_push_str(ctx->getStart()->getText());
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingIdentList
	(Parser::FlingIdentListContext *ctx)
{
	DEFER_PUSH(node, IdentList);

	FOR_PT(p, flingIdent)
	{
		p->accept(this);
		node->data.push_back(_pop_str());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingScopedIdent
	(Parser::FlingScopedIdentContext *ctx)
{
	DEFER_PUSH(node, ScopedIdent);

	FOR_PT(p, flingIdent)
	{
		p->accept(this);
		node->data.push_back(_pop_str());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExprList
	(Parser::FlingExprListContext *ctx)
{
	DEFER_PUSH_LIST(list);

	FOR_PT(p, flingExpr)
	{
		p->accept(this);
		list.push_back(_pop_ast());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingTypenameOrModnameList
	(Parser::FlingTypenameOrModnameListContext *ctx)
{
	DEFER_PUSH_LIST(list);

	FOR_PT(p, flingTypenameOrModname)
	{
		p->accept(this);
		list.push_back(_pop_ast());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingImportList
	(Parser::FlingImportListContext *ctx)
{
	DEFER_PUSH(node, ImportList);

	FOR_PT(p, flingImportList_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingImportList_Item
	(Parser::FlingImportList_ItemContext *ctx)
{
	DEFER_PUSH(node, ImportList_Item);

	JUST_ACCEPT_AND_POP_AST(node->scoped_ident, flingScopedIdent);
	node->has_all = ctx->KwAll();

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingTypenameOrModname
	(Parser::FlingTypenameOrModnameContext *ctx)
{
	ACCEPT_IFELSE
		(flingTypenameOrModname_Typeof,
		flingTypenameOrModname_Cstm,
		flingTypenameOrModname_Builtin)
	else
	{
		DEFER_PUSH(node, TypenameOrModname_Special);
		node->is_dyn = ctx->KwDyn();
		node->is_weakref = ctx->KwWeakref();

		using Kind = TypenameOrModname_Special::Kind;
		if (!_conv_pt_to_enum(node->kind,
			ctx->KwSelfT(), Kind::SelfT,
			ctx->KwRetT(), Kind::RetT))
		{
			internal_err(visitFlingTypenameOrModname);
		}
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingTypenameOrModname_Cstm
	(Parser::FlingTypenameOrModname_CstmContext *ctx)
{
	DEFER_PUSH(node, TypenameOrModname_Cstm);

	node->is_dyn = ctx->KwDyn();
	node->is_weakref = ctx->KwWeakref();

	FOR_PT(p, flingTypenameOrModname_Cstm_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}

	FOR_PT(p, flingTypenameOrModname_ArrDim)
	{
		p->accept(this);
		node->arr_dim_list.push_back(_pop_ast());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingTypenameOrModname_Typeof
	(Parser::FlingTypenameOrModname_TypeofContext *ctx)
{
	DEFER_PUSH(node, TypenameOrModname_Typeof);

	JUST_ACCEPT_AND_POP_AST(node->expr, flingExpr);

	FOR_PT(p, flingTypenameOrModname_Cstm_Item)
	{
		p->accept(this);
		node->item_list.push_back(_pop_ast());
	}

	FOR_PT(p, flingTypenameOrModname_ArrDim)
	{
		p->accept(this);
		node->arr_dim_list.push_back(_pop_ast());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingTypenameOrModname_Cstm_Item
	(Parser::FlingTypenameOrModname_Cstm_ItemContext *ctx)
{
	DEFER_PUSH(node, TypenameOrModname_Cstm_Item);

	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);
	ACCEPT_AND_POP_AST_IF(node->opt_param_list, flingInstParamList);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingTypenameOrModname_ArrDim
	(Parser::FlingTypenameOrModname_ArrDimContext *ctx)
{
	ACCEPT_IFELSE
		(flingExpr,
		flingTypenameOrModname)
	else
	{
		internal_err(visitFlingTypenameOrModname_ArrDim);
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingTypenameOrModname_Builtin
	(Parser::FlingTypenameOrModname_BuiltinContext *ctx)
{
	DEFER_PUSH(node, TypenameOrModname_Builtin);

	node->is_dyn = ctx->KwDyn();
	node->is_weakref = ctx->KwWeakref();

	using Kind = TypenameOrModname_Builtin::Kind;

	if (!_conv_pt_to_enum(node->kind,
		ctx->KwSigned(), Kind::SignedLogic,
		ctx->KwLogic(), Kind::Logic,

		ctx->KwInteger(), Kind::Integer,
		ctx->KwSizeT(), Kind::SizeT,
		ctx->KwRange(), Kind::Range,
		ctx->KwString(), Kind::String,

		ctx->KwU8(), Kind::U8,
		ctx->KwI8(), Kind::I8,
		ctx->KwU16(), Kind::U16,
		ctx->KwI16(), Kind::I16,
		ctx->KwU32(), Kind::U32,
		ctx->KwI32(), Kind::I32,
		ctx->KwU64(), Kind::U64,
		ctx->KwI64(), Kind::I64,
		ctx->KwU128(), Kind::U128,
		ctx->KwI128(), Kind::I128,

		ctx->KwAuto(), Kind::Auto,
		ctx->KwVoid(), Kind::Void))
	{
		internal_err(visitFlingTypenameOrModname_Builtin);
	}

	ACCEPT_AND_POP_AST_IF(node->opt_param_list, flingInstParamList);

	FOR_PT(p, flingTypenameOrModname_ArrDim)
	{
		p->accept(this);
		node->arr_dim_list.push_back(_pop_ast());
	}

	return nullptr;
}
//--------

//--------
#define VISIT_BINOP(punct, type, pt_node) \
	CHECK(punct) \
	{ \
		DEFER_PUSH(node, type); \
		\
		JUST_ACCEPT(pt_node); \
		node->left = _pop_ast(); \
		\
		JUST_ACCEPT(flingExpr); \
		node->right = _pop_ast(); \
	}

antlrcpp::Any PtVisitor::visitFlingExpr
	(Parser::FlingExprContext *ctx)
{
	CHECK(KwMux)
	{
		DEFER_PUSH(node, ExprMux);

		_vec_just_accept_and_pop_ast(ctx->flingExpr(), 
			node->cond, node->when_true, node->when_false);
	}
	else
	{
		JUST_ACCEPT(flingExpr_Mux);
	}
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingExpr_Mux
	(Parser::FlingExpr_MuxContext *ctx)
{
	VISIT_BINOP(PunctLogOr, ExprLogOr, flingExpr_LogOr)
	else
	{
		JUST_ACCEPT(flingExpr_LogOr);
	}
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingExpr_LogOr
	(Parser::FlingExpr_LogOrContext *ctx)
{
	VISIT_BINOP(PunctLogAnd, ExprLogAnd, flingExpr_LogAnd)
	else
	{
		JUST_ACCEPT(flingExpr_LogAnd);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_LogAnd
	(Parser::FlingExpr_LogAndContext *ctx)
{
	#define X(punct, type) \
		VISIT_BINOP(punct, type, flingExpr_BitOr_Or_BitNor)
	EVAL(MAP_PAIRS(X, ELSE,
		PunctBitOr, ExprBinopBitOr,
		PunctBitNor, ExprBinopBitNor))
	#undef X
	else
	{
		JUST_ACCEPT(flingExpr_BitOr_Or_BitNor);
	}
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingExpr_BitOr_Or_BitNor
	(Parser::FlingExpr_BitOr_Or_BitNorContext *ctx)
{
	#define X(punct, type) \
		VISIT_BINOP(punct, type, flingExpr_BitAnd_Or_BitNand)
	EVAL(MAP_PAIRS(X, ELSE,
		PunctBitAnd, ExprBinopBitAnd,
		PunctBitNand, ExprBinopBitNand))
	#undef X
	else
	{
		JUST_ACCEPT(flingExpr_BitAnd_Or_BitNand);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_BitAnd_Or_BitNand
	(Parser::FlingExpr_BitAnd_Or_BitNandContext *ctx)
{
	#define X(punct, type) \
		VISIT_BINOP(punct, type, flingExpr_BitXor_Or_BitXnor)
	EVAL(MAP_PAIRS(X, ELSE,
		PunctBitXor, ExprBinopBitXor,
		PunctBitXnor, ExprBinopBitXnor))
	#undef X
	else
	{
		JUST_ACCEPT(flingExpr_BitXor_Or_BitXnor);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_BitXor_Or_BitXnor
	(Parser::FlingExpr_BitXor_Or_BitXnorContext *ctx)
{
	#define X(punct, type) \
		VISIT_BINOP(punct, type, flingExpr_CmpEqEtc)
	EVAL(MAP_PAIRS(X, ELSE,
		PunctCmpEq, ExprCmpEq,
		PunctCmpNe, ExprCmpNe,
		PunctCaseCmpEq, ExprCaseCmpEq,
		PunctCaseCmpNe, ExprCaseCmpNe))
	#undef X
	else
	{
		JUST_ACCEPT(flingExpr_CmpEqEtc);
	}
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingExpr_CmpEqEtc
	(Parser::FlingExpr_CmpEqEtcContext *ctx)
{
	#define X(punct, type) \
		VISIT_BINOP(punct, type, flingExpr_CmpLtEtc)
	EVAL(MAP_PAIRS(X, ELSE,
		PunctCmpLt, ExprCmpLt,
		PunctCmpLe, ExprCmpLe,
		PunctCmpGt, ExprCmpGt,
		PunctCmpGe, ExprCmpGe))
	#undef X
	else
	{
		JUST_ACCEPT(flingExpr_CmpLtEtc);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_CmpLtEtc
	(Parser::FlingExpr_CmpLtEtcContext *ctx)
{
	#define X(punct, type) \
		VISIT_BINOP(punct, type, flingExpr_BitShift)
	EVAL(MAP_PAIRS(X, ELSE,
		KwLsl, ExprBitLsl,
		KwLsr, ExprBitLsr,
		KwAsr, ExprBitAsr))
	#undef X
	else
	{
		JUST_ACCEPT(flingExpr_BitShift);
	}
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingExpr_BitShift
	(Parser::FlingExpr_BitShiftContext *ctx)
{
	#define X(punct, type) \
		VISIT_BINOP(punct, type, flingExpr_BinaryPlus_Or_BinaryMinus)
	EVAL(MAP_PAIRS(X, ELSE,
		PunctPlus, ExprBinopPlus,
		PunctMinus, ExprBinopMinus))
	#undef X
	else
	{
		JUST_ACCEPT(flingExpr_BinaryPlus_Or_BinaryMinus);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_BinaryPlus_Or_BinaryMinus
	(Parser::FlingExpr_BinaryPlus_Or_BinaryMinusContext *ctx)
{
	#define X(punct, type) \
		VISIT_BINOP(punct, type, flingExpr_Mul_Or_Div_Or_Mod)
	EVAL(MAP_PAIRS(X, ELSE,
		PunctMul, ExprMul,
		PunctDiv, ExprDiv,
		PunctMod, ExprMod))
	#undef X
	else
	{
		JUST_ACCEPT(flingExpr_Mul_Or_Div_Or_Mod);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_Mul_Or_Div_Or_Mod
	(Parser::FlingExpr_Mul_Or_Div_Or_ModContext *ctx)
{
	#define X(punct, type) \
		CHECK(punct) \
		{ \
			DEFER_PUSH(node, type); \
			\
			JUST_ACCEPT(flingExpr); \
			node->to_feed = _pop_ast(); \
		}
	EVAL(MAP_PAIRS(X, ELSE,
		PunctPlus, ExprUnopPlus,
		PunctMinus, ExprUnopMinus,
		PunctLogNot, ExprLogNot,
		PunctBitNot, ExprBitNot,

		PunctBitOr, ExprUnopBitOr,
		PunctBitNor, ExprUnopBitNor,

		PunctBitAnd, ExprUnopBitAnd,
		PunctBitNand, ExprUnopBitNand,

		PunctBitXor, ExprUnopBitXor,
		PunctBitXnor, ExprUnopBitXnor))
	#undef X
	else
	{
		JUST_ACCEPT(flingExpr_Unary);
	}
	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingExpr_Unary
	(Parser::FlingExpr_UnaryContext *ctx)
{
	ACCEPT_IFELSE
		(flingExpr_Unary_ItemFromMajority,
		flingExpr_Range,
		flingExpr_Cast,
		flingExpr_CallSubprog_PseudoOper)
	else
	{
		internal_err(visitFlingExpr_Unary);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_Unary_ItemFromMajority
	(Parser::FlingExpr_Unary_ItemFromMajorityContext *ctx)
{
	ACCEPT_IFELSE
		(flingExpr_Literal,
		flingExpr_Sized,
		flingExpr_Cat,
		flingExpr_Repl,
		flingExpr_KwDollarFuncOf,
		flingExpr_IdentEtc,
		flingExpr)
	else
	{
		internal_err(visitFlingExpr_Unary_ItemFromMajority);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_Literal
	(Parser::FlingExpr_LiteralContext *ctx)
{
	DEFER_PUSH(node, ExprLiteral);

	using Kind = ExprLiteral::Kind;

	if (!_conv_pt_to_enum(node->kind,
		ctx->LitDecNum(), Kind::DecNum,
		ctx->LitHexNum(), Kind::HexNum,
		ctx->LitOctNum(), Kind::OctNum,
		ctx->LitBinNum(), Kind::BinNum,
		ctx->LitString(), Kind::String,
		ctx->KwHighZ(), Kind::HighZ,
		ctx->KwUnkX(), Kind::UnkX,
		ctx->KwNull(), Kind::Null))
	{
		internal_err(visitFlingExpr_Literal);
	}

	node->text = ctx->getStart()->getText();

	ACCEPT_AND_POP_AST_IF(node->opt_size, flingExpr);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_Sized
	(Parser::FlingExpr_SizedContext *ctx)
{
	DEFER_PUSH(node, ExprSized);

	if (ctx->flingExpr().size() == 1)
	{
		_vec_just_accept_and_pop_ast(ctx->flingExpr(),
			node->src);
	}
	else if (ctx->flingExpr().size() == 2)
	{
		_vec_just_accept_and_pop_ast(ctx->flingExpr(),
			node->dst_size, node->src);
	}
	else
	{
		internal_err(visitFlingExpr_Sized);
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_Range
	(Parser::FlingExpr_RangeContext *ctx)
{
	ACCEPT_IFELSE
		(flingExpr_Range_DotDot,
		flingExpr_Range_CallFunc)
	else
	{
		internal_err(visitFlingExpr_Range);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_Range_DotDot
	(Parser::FlingExpr_Range_DotDotContext *ctx)
{
	DEFER_PUSH(node, ExprRange);

	JUST_ACCEPT_AND_POP_AST
		(node->left, flingExpr_Unary_ItemFromMajority,
		node->right, flingExpr);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_Range_CallFunc
	(Parser::FlingExpr_Range_CallFuncContext *ctx)
{
	DEFER_PUSH(node, ExprRange);

	if (ctx->flingExpr().size() == 1)
	{
		_vec_just_accept_and_pop_ast(ctx->flingExpr(),
			node->left);
	}
	else if (ctx->flingExpr().size() == 2)
	{
		_vec_just_accept_and_pop_ast(ctx->flingExpr(),
			node->left, node->right);
	}
	else
	{
		internal_err(visitFlingExpr_Range_CallFunc);
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_Cat
	(Parser::FlingExpr_CatContext *ctx)
{
	DEFER_PUSH(node, ExprCat);

	JUST_ACCEPT_AND_POP_AST_LIST(node->item_list, flingExprList);
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_Repl
	(Parser::FlingExpr_ReplContext *ctx)
{
	DEFER_PUSH(node, ExprRepl);

	_vec_just_accept_and_pop_ast(ctx->flingExpr(),
		node->amount, node->to_repl);

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingExpr_KwDollarFuncOf
	(Parser::FlingExpr_KwDollarFuncOfContext *ctx)
{
	ACCEPT_IFELSE
		(flingExpr_KwDollarFuncOf_NonPow,
		flingExpr_KwDollarFuncOf_Pow)
	else
	{
		internal_err(visitFlingExpr_KwDollarFuncOf);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_KwDollarFuncOf_NonPow
	(Parser::FlingExpr_KwDollarFuncOf_NonPowContext *ctx)
{
	CHECK(KwDollarSigned)
	{
		DEFER_PUSH(node, ExprDollarSigned);
		JUST_ACCEPT_AND_POP_AST(node->to_feed, flingExpr);
	}
	else CHECK(KwDollarUnsigned)
	{
		DEFER_PUSH(node, ExprDollarUnsigned);
		JUST_ACCEPT_AND_POP_AST(node->to_feed, flingExpr);
	}
	else CHECK(KwDollarClog2)
	{
		DEFER_PUSH(node, ExprDollarClog2);
		JUST_ACCEPT_AND_POP_AST(node->to_feed, flingExpr);
	}
	else CHECK(KwDollarIsvtype)
	{
		DEFER_PUSH(node, ExprDollarIsvtype);
		JUST_ACCEPT_AND_POP_AST(node->to_feed, flingExpr);
	}
	else
	{
		internal_err(visitFlingExpr_KwDollarFuncOf_NonPow);
	}
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_KwDollarFuncOf_Pow
	(Parser::FlingExpr_KwDollarFuncOf_PowContext *ctx)
{
	DEFER_PUSH(node, ExprDollarPow);

	_vec_just_accept_and_pop_ast(ctx->flingExpr(),
		node->left, node->right);

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingExpr_IdentEtc
	(Parser::FlingExpr_IdentEtcContext *ctx)
{
	DEFER_PUSH(node, ExprIdentEtc);


	ACCEPT_AND_POP_AST_IF
		(node->opt_typename_or_modname, flingTypenameOrModname);
	CHECK(flingExpr_IdentEtc_FirstItem)
	{

		JUST_ACCEPT_AND_POP_AST
			(node->first_item, flingExpr_IdentEtc_FirstItem);

		FOR_PT(p, flingExpr_IdentEtc_NonSelfItem)
		{
			p->accept(this);
			node->opt_later_item_list.push_back(_pop_ast());
		}
	}
	CHECK(flingExpr_IdentEtc_DollarFuncSuffix)
	{
		BigNum num;
		JUST_ACCEPT_AND_POP_NUM(num, flingExpr_IdentEtc_DollarFuncSuffix);
		node->suff_kind = static_cast<ExprIdentEtc::SuffKind>
			(conv_bignum_to<size_t>(num));
	}
	else
	{
		node->suff_kind = ExprIdentEtc::SuffKind::None;
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_IdentEtc_DollarFuncSuffix
	(Parser::FlingExpr_IdentEtc_DollarFuncSuffixContext *ctx)
{
	using SuffKind = ExprIdentEtc::SuffKind;
	SuffKind to_push;

	if (!_conv_pt_to_enum(to_push,
		ctx->KwDollarSize(), SuffKind::DollarSize,
		ctx->KwDollarRange(), SuffKind::DollarRange,
		ctx->KwDollarHigh(), SuffKind::DollarHigh,
		ctx->KwDollarLow(), SuffKind::DollarLow))
	{
		internal_err(visitFlingExpr_IdentEtc_DollarFuncSuffix);
	}

	_push_num(static_cast<size_t>(to_push));

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_IdentEtc_FirstItem
	(Parser::FlingExpr_IdentEtc_FirstItemContext *ctx)
{
	DEFER_PUSH(node, ExprIdentEtc_FirstItem);

	using Kind = ExprIdentEtc_FirstItem::Kind;

	if (!_conv_pt_to_enum(node->kind,
		ctx->KwSelf(), Kind::Self,
		ctx->flingExpr_IdentEtc_NonSelfItem(), Kind::NonSelf))
	{
		internal_err(visitFlingExpr_IdentEtc_FirstItem);
	}

	ACCEPT_AND_POP_AST_IF
		(node->opt_non_self_item, flingExpr_IdentEtc_NonSelfItem);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_IdentEtc_NonSelfItem
	(Parser::FlingExpr_IdentEtc_NonSelfItemContext *ctx)
{
	DEFER_PUSH(node, ExprIdentEtc_NonSelfItem);

	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);
	ACCEPT_AND_POP_AST_IF
		(node->opt_param_list, flingInstParamList,
		node->opt_arg_list, flingInstArgList);

	FOR_PT(p, flingExpr_IdentEtc_Item_End)
	{
		p->accept(this);
		node->end_item_list.push_back(_pop_ast());
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_IdentEtc_Item_End
	(Parser::FlingExpr_IdentEtc_Item_EndContext *ctx)
{
	DEFER_PUSH(node, ExprIdentEtc_ItemEnd);

	using Kind = ExprIdentEtc_ItemEnd::Kind;
	if (!_conv_pt_to_enum(node->kind,
		ctx->flingExpr_IdentEtc_Item_End_Index(), Kind::ArrIndex,
		ctx->KwDollarFirstel(), Kind::DollarFirstel,
		ctx->KwDollarLastel(), Kind::DollarLastel))
	{
		internal_err(visitFlingExpr_IdentEtc_Item_End);
	}

	ACCEPT_AND_POP_AST_IF
		(node->opt_index, flingExpr_IdentEtc_Item_End_Index);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_IdentEtc_Item_End_Index
	(Parser::FlingExpr_IdentEtc_Item_End_IndexContext *ctx)
{
	DEFER_PUSH(node, ExprIdentEtc_ItemEndIndex);

	using Kind = ExprIdentEtc_ItemEndIndex::Kind;

	auto&& expr = ctx->flingExpr();

	_conv_pt_to_enum(node->kind,
		ctx->PunctPlusColon(), Kind::PlusColon,
		ctx->PunctMinusColon(), Kind::MinusColon);

	expr.at(0)->accept(this);
	node->left = _pop_ast();

	if (node->kind != Kind::Single)
	{
		expr.at(1)->accept(this);
		node->opt_right = _pop_ast();
	}

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingExpr_Cast
	(Parser::FlingExpr_CastContext *ctx)
{
	DEFER_PUSH(node, ExprCast);

	ACCEPT_IFELSE
		(flingExpr_Unary_ItemFromMajority,
		flingExpr_Range_CallFunc,
		flingExpr_CallSubprog_PseudoOper)
	else
	{
		internal_err(visitFlingExpr_Cast);
	}
	node->to_cast = _pop_ast();
	JUST_ACCEPT_AND_POP_AST
		(node->typename_or_modname, flingTypenameOrModname);

	return nullptr;
}
//--------

//--------
antlrcpp::Any PtVisitor::visitFlingExpr_CallSubprog_PseudoOper
	(Parser::FlingExpr_CallSubprog_PseudoOperContext *ctx)
{
	DEFER_PUSH(node, ExprCallSubprog_PseudoOper);

	ACCEPT_IFELSE
		(flingExpr_Unary_ItemFromMajority,
		flingExpr_Range_CallFunc)
	else
	{
		internal_err(visitFlingExpr_CallSubprog_PseudoOper);
	}
	node->left = _pop_ast();

	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);
	ACCEPT_AND_POP_AST_IF(node->opt_param_list, flingInstParamList);
	JUST_ACCEPT_AND_POP_AST(node->right, flingExpr);

	return nullptr;
}
//--------

} // namespace fling_hdl
