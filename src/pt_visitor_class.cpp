#include "pt_visitor_class.hpp"
#include "pt_visitor_error_listener_class.hpp"

namespace fling_hdl
{

using namespace ast;

#define RAW_APPEND_CHILD_IF(to_feed, type) \
	if (child->id() == string(#type)) \
	{ \
		/* More like, we need to feed *our* childrens */ \
		to_feed.push_back(move(child)); \
	}
#define MULTI_APPEND_CHILD_IF(...) \
	EVAL(MAP(APPEND_CHILD_IF, ELSE, __VA_ARGS__))

#define JUST_ACCEPT(pt_node) \
	ctx->pt_node()->accept(this)

#define ACCEPT_IF(pt_node) \
	if (ctx->pt_node()) \
	{ \
		JUST_ACCEPT(pt_node); \
	}
#define MULTI_ACCEPT_IF(...) \
	EVAL(MAP(ACCEPT_IF, ELSE, __VA_ARGS__))


#define CHECK(pt_node) \
	if (ctx->pt_node())

#define JUST_ACCEPT_AND_POP_AST(to_set, pt_node) \
	JUST_ACCEPT(pt_node); \
	to_set = _pop_ast();
#define ACCEPT_AND_POP_AST_IF(to_set, pt_node) \
	CHECK(pt_node) \
	{ \
		JUST_ACCEPT_AND_POP_AST(to_set, pt_node); \
	}
#define MULTI_JUST_ACCEPT_AND_POP_AST(...) \
	EVAL(MAP_PAIRS(JUST_ACCEPT_AND_POP_AST, SEMICOLON, __VA_ARGS__))
#define MULTI_ACCEPT_AND_POP_AST_IF(...) \
	EVAL(MAP_PAIRS(ACCEPT_AND_POP_AST_IF, SEMICOLON, __VA_ARGS__))

#define JUST_ACCEPT_AND_POP_AST_LIST(to_set, pt_node) \
	JUST_ACCEPT(pt_node); \
	to_set = move(_pop_ast_list())
#define ACCEPT_AND_POP_AST_LIST_IF(to_set, pt_node) \
	CHECK(pt_node) \
	{ \
		JUST_ACCEPT_AND_POP_AST_LIST(to_set, pt_node); \
	}

#define JUST_ACCEPT_AND_POP_NUM(to_set, pt_node) \
	JUST_ACCEPT(pt_node); \
	to_set = _pop_num();
#define ACCEPT_AND_POP_NUM_IF(to_set, pt_node) \
	CHECK(pt_node) \
	{ \
		JUST_ACCEPT_AND_POP_NUM(to_set, pt_node); \
	}

#define JUST_ACCEPT_AND_POP_STR(to_set, pt_node) \
	JUST_ACCEPT(pt_node); \
	to_set = _pop_str();
#define ACCEPT_AND_POP_STR_IF(to_set, pt_node) \
	CHECK(pt_node) \
	{ \
		JUST_ACCEPT_AND_POP_STR(to_set, pt_node); \
	}


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
	new type(FilePos(_filename, ctx))

#define DEFER_PUSH(name, type) \
	auto name = make_ast(type); \
	AstNodePusher ast_node_pusher_ ## name (this, name)
#define DEFER_PUSH_LIST(name) \
	BaseSptrList name; \
	AstNodeListPusher ast_node_list_pusher_ ## name (this, &name)

#define internal_err(func) \
	_internal_err(ctx, #func)

#define FOR_PT(p, pt_node) \
	for (const auto& p: ctx->pt_node())

PtVisitor::PtVisitor(int s_argc, char** s_argv)
{
	_argc = s_argc;
	_argv = s_argv;
	//_program_ctx = parser.flingProgram();

	if (_argc < 2)
	{
		_err(sconcat("Usage:  ", _argv[0], " output_file_name",
			" source_files..."));
	}

	for (int i=2; i<_argc; ++i)
	{
		const string s_filename = _argv[i];
		antlr4::ANTLRInputStream input(get_istream_as_str(std::ifstream
			(s_filename, std::ios_base::in)));
		FlingHdlGrammarLexer lexer(&input);
		antlr4::CommonTokenStream tokens(&lexer);
		tokens.fill();

		FlingHdlGrammarParser parser(&tokens);
		parser.removeErrorListeners();
		unique_ptr<PtVisitorErrorListener>
			pt_visitor_error_listener(new PtVisitorErrorListener());
		parser.addErrorListener(pt_visitor_error_listener.get());

		_ast_etc_map[s_filename] = AstEtc(s_filename,
			parser.flingProgram());
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
		_ast = new Program(FilePos(_filename,
			p.second.program_ctx()));
		p.second.ast().reset(_ast);
		p.second.program_ctx()->accept(this);
	}
	return 0;
}

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
	MULTI_ACCEPT_IF(flingDeclPackage,
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
	MULTI_ACCEPT_IF(flingDeclPackage,
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
antlrcpp::Any PtVisitor::visitFlingDeclParamList
	(Parser::FlingDeclParamListContext *ctx)
{
	DEFER_PUSH(node, DeclParamList);

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
		node->kind = Kind::Var;
		JUST_ACCEPT_AND_POP_AST(node->opt_typename_or_modname,
			flingTypenameOrModname);
		ACCEPT_AND_POP_AST_LIST_IF(node->opt_expr_list, flingExprList);
	}
	else CHECK(KwType)
	{
		node->kind = Kind::Typename;

		ACCEPT_AND_POP_AST_LIST_IF(node->opt_typename_or_modname_list,
			flingTypenameOrModnameList);
	}
	else CHECK(KwModule)
	{
		node->kind = Kind::Modname;
		ACCEPT_AND_POP_AST_LIST_IF(node->opt_typename_or_modname_list,
			flingTypenameOrModnameList);
	}
	else
	{
		internal_err(visitFlingDeclParamList_Item);
	}

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclArgList
	(Parser::FlingDeclArgListContext *ctx)
{
	DEFER_PUSH(node, DeclArgList);

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
	if (!_conv_pt_to_enum(node->kind,
		ctx->KwInput(), Kind::Input,
		ctx->KwOutput(), Kind::Output,
		ctx->KwInout(), Kind::Inout,
		ctx->KwInterface(), Kind::Interface))
	{
		internal_err(visitFlingDeclArgList_Item);
	}
	JUST_ACCEPT_AND_POP_AST(node->typename_or_modname,
		flingTypenameOrModname);

	ACCEPT_AND_POP_AST_LIST_IF(node->opt_expr_list, flingExprList);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingInstParamList
	(Parser::FlingInstParamListContext *ctx)
{
	DEFER_PUSH(node, InstParamList);

	ACCEPT_AND_POP_AST_LIST_IF(node->opt_item_list, flingInstParamList_Pos)
	else ACCEPT_AND_POP_AST_LIST_IF(node->opt_item_list,
		flingInstParamList_Named)

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
	MULTI_ACCEPT_IF(flingExpr,
		flingTypenameOrModname)
	else
	{
		internal_err(visitFlingInstParamList_Pos_Item);
	}
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
	DEFER_PUSH(node, InstParamList_Named_Item);

	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);
	JUST_ACCEPT_AND_POP_AST(node->item, flingInstParamList_Pos_Item);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingInstArgList
	(Parser::FlingInstArgListContext *ctx)
{
	DEFER_PUSH(node, InstArgList);

	ACCEPT_AND_POP_AST_LIST_IF(node->opt_item_list, flingInstArgList_Pos)
	else ACCEPT_AND_POP_AST_LIST_IF(node->opt_item_list,
		flingInstArgList_Named)

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingInstArgList_Pos
	(Parser::FlingInstArgList_PosContext *ctx)
{
	JUST_ACCEPT(flingExprList);
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
	DEFER_PUSH(node, InstArgList_Named_Item);

	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);
	JUST_ACCEPT_AND_POP_AST(node->expr, flingExpr);

	return nullptr;
}
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
	MULTI_ACCEPT_IF(flingInstModule,
		flingExpr,
		flingGen,
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
antlrcpp::Any PtVisitor::visitFlingInstModule
	(Parser::FlingInstModuleContext *ctx)
{
	DEFER_PUSH(node, InstModule);

	JUST_ACCEPT_AND_POP_STR(node->ident, flingIdent);
	MULTI_JUST_ACCEPT_AND_POP_AST
		(node->typename_or_modname, flingTypenameOrModname,
		node->arg_list, flingInstArgList);

	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingGen
	(Parser::FlingGenContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingGen_If
	(Parser::FlingGen_IfContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingGen_If_Elif
	(Parser::FlingGen_If_ElifContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingGen_If_Else
	(Parser::FlingGen_If_ElseContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingGen_Switch
	(Parser::FlingGen_SwitchContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingGen_Switch_Default
	(Parser::FlingGen_Switch_DefaultContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingGen_Switch_Case
	(Parser::FlingGen_Switch_CaseContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingGen_For
	(Parser::FlingGen_ForContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingContAssign
	(Parser::FlingContAssignContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav
	(Parser::FlingBehavContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Seq_EdgeList
	(Parser::FlingBehav_Seq_EdgeListContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Seq_EdgeList_Item
	(Parser::FlingBehav_Seq_EdgeList_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Scope
	(Parser::FlingBehav_ScopeContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item
	(Parser::FlingBehav_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_If
	(Parser::FlingBehav_Item_IfContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_If_Elif
	(Parser::FlingBehav_Item_If_ElifContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_If_Else
	(Parser::FlingBehav_Item_If_ElseContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_SwitchOrSwitchz
	(Parser::FlingBehav_Item_SwitchOrSwitchzContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_SwitchOrSwitchz_Default
	(Parser::FlingBehav_Item_SwitchOrSwitchz_DefaultContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_SwitchOrSwitchz_Case
	(Parser::FlingBehav_Item_SwitchOrSwitchz_CaseContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_For
	(Parser::FlingBehav_Item_ForContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_While
	(Parser::FlingBehav_Item_WhileContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_NonBlkAssign
	(Parser::FlingBehav_Item_NonBlkAssignContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingBehav_Item_BlkAssign
	(Parser::FlingBehav_Item_BlkAssignContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclWire
	(Parser::FlingDeclWireContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclVar
	(Parser::FlingDeclVarContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclConst
	(Parser::FlingDeclConstContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclType
	(Parser::FlingDeclTypeContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclEnum
	(Parser::FlingDeclEnumContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClass
	(Parser::FlingDeclClassContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClsOrMxn_Extends
	(Parser::FlingDeclClsOrMxn_ExtendsContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClass_Item
	(Parser::FlingDeclClass_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClass_Item_DeclVar
	(Parser::FlingDeclClass_Item_DeclVarContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClsOrMxn_Item
	(Parser::FlingDeclClsOrMxn_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClsOrMxn_Item_DeclType
	(Parser::FlingDeclClsOrMxn_Item_DeclTypeContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClsOrMxn_Item_DeclAliasOrConst
	(Parser::FlingDeclClsOrMxn_Item_DeclAliasOrConstContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClsOrMxn_AccessSpecifier
	(Parser::FlingDeclClsOrMxn_AccessSpecifierContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClsOrMxn_Item_DeclSubprog
	(Parser::FlingDeclClsOrMxn_Item_DeclSubprogContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClsOrMxn_Item_DeclSubprog_FullDefn
	(Parser::FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclClsOrMxn_Item_DeclSubprog_Abstract
	(Parser::FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclMixin
	(Parser::FlingDeclMixinContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclSubprog
	(Parser::FlingDeclSubprogContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc
	(Parser::FlingDeclFuncContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Header
	(Parser::FlingDeclFunc_HeaderContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Scope
	(Parser::FlingDeclFunc_ScopeContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item
	(Parser::FlingDeclFunc_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_If
	(Parser::FlingDeclFunc_Item_IfContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_If_Elif
	(Parser::FlingDeclFunc_Item_If_ElifContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_If_Else
	(Parser::FlingDeclFunc_Item_If_ElseContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_SwitchOrSwitchz
	(Parser::FlingDeclFunc_Item_SwitchOrSwitchzContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_SwitchOrSwitchz_Default
	(Parser::FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_SwitchOrSwitchz_Case
	(Parser::FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_For
	(Parser::FlingDeclFunc_Item_ForContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclFunc_Item_While
	(Parser::FlingDeclFunc_Item_WhileContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask
	(Parser::FlingDeclTaskContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Header
	(Parser::FlingDeclTask_HeaderContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Scope
	(Parser::FlingDeclTask_ScopeContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item
	(Parser::FlingDeclTask_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_If
	(Parser::FlingDeclTask_Item_IfContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_If_Elif
	(Parser::FlingDeclTask_Item_If_ElifContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_If_Else
	(Parser::FlingDeclTask_Item_If_ElseContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_SwitchOrSwitchz
	(Parser::FlingDeclTask_Item_SwitchOrSwitchzContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_SwitchOrSwitchz_Default
	(Parser::FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_SwitchOrSwitchz_Case
	(Parser::FlingDeclTask_Item_SwitchOrSwitchz_CaseContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_For
	(Parser::FlingDeclTask_Item_ForContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclTask_Item_While
	(Parser::FlingDeclTask_Item_WhileContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclProc
	(Parser::FlingDeclProcContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclProc_Header
	(Parser::FlingDeclProc_HeaderContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclProc_ArgList
	(Parser::FlingDeclProc_ArgListContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclProc_ArgList_Item
	(Parser::FlingDeclProc_ArgList_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclAlias
	(Parser::FlingDeclAliasContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclAlias_Value
	(Parser::FlingDeclAlias_ValueContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclAlias_Type
	(Parser::FlingDeclAlias_TypeContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingDeclAlias_Module
	(Parser::FlingDeclAlias_ModuleContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingIdent
	(Parser::FlingIdentContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingIdentList
	(Parser::FlingIdentListContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingScopedIdent
	(Parser::FlingScopedIdentContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExprList
	(Parser::FlingExprListContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingTypenameOrModnameList
	(Parser::FlingTypenameOrModnameListContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingImportList
	(Parser::FlingImportListContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingTypenameOrModname
	(Parser::FlingTypenameOrModnameContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingTypenameOrModname_Cstm
	(Parser::FlingTypenameOrModname_CstmContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingTypenameOrModname_Cstm_Item
	(Parser::FlingTypenameOrModname_Cstm_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingTypenameOrModname_ArrDim
	(Parser::FlingTypenameOrModname_ArrDimContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingTypenameOrModname_Builtin
	(Parser::FlingTypenameOrModname_BuiltinContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr
	(Parser::FlingExprContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_Mux
	(Parser::FlingExpr_MuxContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_LogOr
	(Parser::FlingExpr_LogOrContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_LogAnd
	(Parser::FlingExpr_LogAndContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_BitOr_Or_BitNor
	(Parser::FlingExpr_BitOr_Or_BitNorContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_BitAnd_Or_BitNand
	(Parser::FlingExpr_BitAnd_Or_BitNandContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_BitXor_Or_BitXnor
	(Parser::FlingExpr_BitXor_Or_BitXnorContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_CmpEqEtc
	(Parser::FlingExpr_CmpEqEtcContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_CmpLtEtc
	(Parser::FlingExpr_CmpLtEtcContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_BitShift
	(Parser::FlingExpr_BitShiftContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_BinaryPlus_Or_BinaryMinus
	(Parser::FlingExpr_BinaryPlus_Or_BinaryMinusContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_Mul_Or_Div_Or_Mod
	(Parser::FlingExpr_Mul_Or_Div_Or_ModContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_Unary
	(Parser::FlingExpr_UnaryContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_Unary_ItemFromMajority
	(Parser::FlingExpr_Unary_ItemFromMajorityContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_Literal
	(Parser::FlingExpr_LiteralContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_Sized
	(Parser::FlingExpr_SizedContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_Range
	(Parser::FlingExpr_RangeContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_Range_DotDot
	(Parser::FlingExpr_Range_DotDotContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_Range_CallFunc
	(Parser::FlingExpr_Range_CallFuncContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_Cat
	(Parser::FlingExpr_CatContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_Repl
	(Parser::FlingExpr_ReplContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_KwDollarFuncOf
	(Parser::FlingExpr_KwDollarFuncOfContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_KwDollarFuncOf_NonPow
	(Parser::FlingExpr_KwDollarFuncOf_NonPowContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_KwDollarFuncOf_Pow
	(Parser::FlingExpr_KwDollarFuncOf_PowContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_IdentEtc
	(Parser::FlingExpr_IdentEtcContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_IdentEtc_FirstItem
	(Parser::FlingExpr_IdentEtc_FirstItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_IdentEtc_NonSelfItem
	(Parser::FlingExpr_IdentEtc_NonSelfItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_IdentEtc_Item_End
	(Parser::FlingExpr_IdentEtc_Item_EndContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_IdentEtc_Item_End_Index
	(Parser::FlingExpr_IdentEtc_Item_End_IndexContext *ctx)
{
	return nullptr;
}
antlrcpp::Any PtVisitor::visitFlingExpr_CallSubprog_PseudoOper
	(Parser::FlingExpr_CallSubprog_PseudoOperContext *ctx)
{
	return nullptr;
}

} // namespace fling_hdl
