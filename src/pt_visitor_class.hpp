#ifndef src_pt_visitor_class_hpp
#define src_pt_visitor_class_hpp

// src/pt_visitor_class.hpp

#include "misc_includes.hpp"

#include "ast_node_classes.hpp"
#include "liborangepower_src/cpp_magic.hpp"

namespace fling_hdl
{

using AstSptr = variant
	<
		#define X(name) \
			shared_ptr<ast::name>,
		LIST_OF_AST_NODE_CLASSES(X)
		#undef X
		std::nullptr_t
	>;

class AstEtc final
{
public:		// types
	using Parser = FlingHdlGrammarParser;
	using ProgramContext = Parser::FlingProgramContext;
private:		// variables
	string _filename;
	ProgramContext* _program_ctx = nullptr;
	shared_ptr<ast::Program> _ast;
public:		// functions
	inline AstEtc() = default;
	inline AstEtc(const string& s_filename, ProgramContext* s_program_ctx)
		: _filename(s_filename), _program_ctx(s_program_ctx)
	{
	}
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(AstEtc);
	inline ~AstEtc() = default;

	GEN_GETTER_BY_CON_REF(filename);
	GEN_GETTER_BY_VAL(program_ctx);
	GEN_GETTERS_BY_CON_REF_AND_REF(ast);
};

class PtVisitor final: public FlingHdlGrammarVisitor
{
public:		// typedefs
	using ParserRuleContext = antlr4::ParserRuleContext;

	using Parser = FlingHdlGrammarParser;
private:		// variables

	int _argc;
	char** _argv;
	map<string, AstEtc> _ast_etc_map;

	// The current filename
	string _filename;
	ast::Program* _ast = nullptr;

	stack<string> _str_stack;
	stack<BigNum> _num_stack;
	
	stack<AstSptr> _ast_stack;

private:		// stack functions
	inline void _push_str(const string& to_push)
	{
		_str_stack.push(to_push);
	}
	inline auto _get_top_str()
	{
		return _str_stack.top();
	}
	inline auto _pop_str()
	{
		auto ret = _str_stack.top();
		_str_stack.pop();
		return ret;
	}

	inline void _push_num(const BigNum& to_push)
	{
		_num_stack.push(to_push);
	}
	inline auto _get_top_num()
	{
		return _num_stack.top();
	}
	inline auto _pop_num()
	{
		auto ret = _num_stack.top();
		_num_stack.pop();
		return ret;
	}

	template<typename Type>
	inline void _push_ast(shared_ptr<Type>&& to_push)
	{
		_ast_stack.push(to_push);
	}
	inline auto _get_top_ast()
	{
		return _ast_stack.top();
	}
	inline auto _pop_ast()
	{
		auto ret = _ast_stack.top();
		_ast_stack.pop();
		return ret;
	}

public:		// functions
	PtVisitor(int s_argc, char** s_argv);
	virtual ~PtVisitor();
	int run();

private:		// error/warning functions
	inline void _err(ParserRuleContext* ctx, const std::string& msg)
	{
		if (ctx == nullptr)
		{
			printerr("Error:  ", msg, "\n");
		}
		else
		{
			ErrWarn(_filename, ctx).err(msg);
		}
		exit(1);
	}
	inline void _err(const std::string& msg)
	{
		//printerr("Error in file \"", *__file_name, "\":  ", msg, "\n");
		printerr("Error:  ", msg, "\n");
		exit(1);
	}


	inline void _warn(ParserRuleContext* ctx, const std::string& msg)
	{
		if (ctx == nullptr)
		{
			printerr("Error:  ", msg, "\n");
		}
		else
		{
			ErrWarn(_filename, ctx).warn(msg);
		}
	}
	inline void _warn(const std::string& msg)
	{
		printerr("Warning:  ", msg, "\n");
	}

private:		// visitor functions
	antlrcpp::Any visitFlingProgram
		(Parser::FlingProgramContext *ctx);
	antlrcpp::Any visitFlingProgram_Item
		(Parser::FlingProgram_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclPackage
		(Parser::FlingDeclPackageContext *ctx);
	antlrcpp::Any visitFlingDeclPackage_Item
		(Parser::FlingDeclPackage_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclParamList
		(Parser::FlingDeclParamListContext *ctx);
	antlrcpp::Any visitFlingDeclParamList_Item
		(Parser::FlingDeclParamList_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclArgList
		(Parser::FlingDeclArgListContext *ctx);
	antlrcpp::Any visitFlingDeclArgList_Item
		(Parser::FlingDeclArgList_ItemContext *ctx);
	antlrcpp::Any visitFlingInstParamList
		(Parser::FlingInstParamListContext *ctx);
	antlrcpp::Any visitFlingInstParamList_Pos
		(Parser::FlingInstParamList_PosContext *ctx);
	antlrcpp::Any visitFlingInstParamList_Pos_Item
		(Parser::FlingInstParamList_Pos_ItemContext *ctx);
	antlrcpp::Any visitFlingInstParamList_Named
		(Parser::FlingInstParamList_NamedContext *ctx);
	antlrcpp::Any visitFlingInstParamList_Named_Item
		(Parser::FlingInstParamList_Named_ItemContext *ctx);
	antlrcpp::Any visitFlingInstArgList
		(Parser::FlingInstArgListContext *ctx);
	antlrcpp::Any visitFlingInstArgList_Pos
		(Parser::FlingInstArgList_PosContext *ctx);
	antlrcpp::Any visitFlingInstArgList_Named
		(Parser::FlingInstArgList_NamedContext *ctx);
	antlrcpp::Any visitFlingInstArgList_Named_Item
		(Parser::FlingInstArgList_Named_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclModule
		(Parser::FlingDeclModuleContext *ctx);
	antlrcpp::Any visitFlingDeclModule_Scope
		(Parser::FlingDeclModule_ScopeContext *ctx);
	antlrcpp::Any visitFlingDeclModule_Item
		(Parser::FlingDeclModule_ItemContext *ctx);
	antlrcpp::Any visitFlingInstModule
		(Parser::FlingInstModuleContext *ctx);
	antlrcpp::Any visitFlingGen
		(Parser::FlingGenContext *ctx);
	antlrcpp::Any visitFlingGen_If
		(Parser::FlingGen_IfContext *ctx);
	antlrcpp::Any visitFlingGen_If_Elif
		(Parser::FlingGen_If_ElifContext *ctx);
	antlrcpp::Any visitFlingGen_If_Else
		(Parser::FlingGen_If_ElseContext *ctx);
	antlrcpp::Any visitFlingGen_Switch
		(Parser::FlingGen_SwitchContext *ctx);
	antlrcpp::Any visitFlingGen_Switch_Default
		(Parser::FlingGen_Switch_DefaultContext *ctx);
	antlrcpp::Any visitFlingGen_Switch_Case
		(Parser::FlingGen_Switch_CaseContext *ctx);
	antlrcpp::Any visitFlingGen_For
		(Parser::FlingGen_ForContext *ctx);
	antlrcpp::Any visitFlingContAssign
		(Parser::FlingContAssignContext *ctx);
	antlrcpp::Any visitFlingBehav
		(Parser::FlingBehavContext *ctx);
	antlrcpp::Any visitFlingBehav_Seq_EdgeList
		(Parser::FlingBehav_Seq_EdgeListContext *ctx);
	antlrcpp::Any visitFlingBehav_Seq_EdgeList_Item
		(Parser::FlingBehav_Seq_EdgeList_ItemContext *ctx);
	antlrcpp::Any visitFlingBehav_Scope
		(Parser::FlingBehav_ScopeContext *ctx);
	antlrcpp::Any visitFlingBehav_Item
		(Parser::FlingBehav_ItemContext *ctx);
	antlrcpp::Any visitFlingBehav_Item_If
		(Parser::FlingBehav_Item_IfContext *ctx);
	antlrcpp::Any visitFlingBehav_Item_If_Elif
		(Parser::FlingBehav_Item_If_ElifContext *ctx);
	antlrcpp::Any visitFlingBehav_Item_If_Else
		(Parser::FlingBehav_Item_If_ElseContext *ctx);
	antlrcpp::Any visitFlingBehav_Item_SwitchOrSwitchz
		(Parser::FlingBehav_Item_SwitchOrSwitchzContext *ctx);
	antlrcpp::Any visitFlingBehav_Item_SwitchOrSwitchz_Default
		(Parser::FlingBehav_Item_SwitchOrSwitchz_DefaultContext *ctx);
	antlrcpp::Any visitFlingBehav_Item_SwitchOrSwitchz_Case
		(Parser::FlingBehav_Item_SwitchOrSwitchz_CaseContext *ctx);
	antlrcpp::Any visitFlingBehav_Item_For
		(Parser::FlingBehav_Item_ForContext *ctx);
	antlrcpp::Any visitFlingBehav_Item_While
		(Parser::FlingBehav_Item_WhileContext *ctx);
	antlrcpp::Any visitFlingBehav_Item_NonBlkAssign
		(Parser::FlingBehav_Item_NonBlkAssignContext *ctx);
	antlrcpp::Any visitFlingBehav_Item_BlkAssign
		(Parser::FlingBehav_Item_BlkAssignContext *ctx);
	antlrcpp::Any visitFlingDeclWire
		(Parser::FlingDeclWireContext *ctx);
	antlrcpp::Any visitFlingDeclVar
		(Parser::FlingDeclVarContext *ctx);
	antlrcpp::Any visitFlingDeclConst
		(Parser::FlingDeclConstContext *ctx);
	antlrcpp::Any visitFlingDeclType
		(Parser::FlingDeclTypeContext *ctx);
	antlrcpp::Any visitFlingDeclEnum
		(Parser::FlingDeclEnumContext *ctx);
	antlrcpp::Any visitFlingDeclClass
		(Parser::FlingDeclClassContext *ctx);
	antlrcpp::Any visitFlingDeclClsOrMxn_Extends
		(Parser::FlingDeclClsOrMxn_ExtendsContext *ctx);
	antlrcpp::Any visitFlingDeclClass_Item
		(Parser::FlingDeclClass_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclClass_Item_DeclVar
		(Parser::FlingDeclClass_Item_DeclVarContext *ctx);
	antlrcpp::Any visitFlingDeclClsOrMxn_Item
		(Parser::FlingDeclClsOrMxn_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclClsOrMxn_Item_DeclType
		(Parser::FlingDeclClsOrMxn_Item_DeclTypeContext *ctx);
	antlrcpp::Any visitFlingDeclClsOrMxn_Item_DeclAliasOrConst
		(Parser::FlingDeclClsOrMxn_Item_DeclAliasOrConstContext *ctx);
	antlrcpp::Any visitFlingDeclClsOrMxn_AccessSpecifier
		(Parser::FlingDeclClsOrMxn_AccessSpecifierContext *ctx);
	antlrcpp::Any visitFlingDeclClsOrMxn_Item_DeclSubprog
		(Parser::FlingDeclClsOrMxn_Item_DeclSubprogContext *ctx);
	antlrcpp::Any visitFlingDeclClsOrMxn_Item_DeclSubprog_FullDefn
		(Parser::FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext *ctx);
	antlrcpp::Any visitFlingDeclClsOrMxn_Item_DeclSubprog_Abstract
		(Parser::FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext *ctx);
	antlrcpp::Any visitFlingDeclMixin
		(Parser::FlingDeclMixinContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog
		(Parser::FlingDeclSubprogContext *ctx);
	antlrcpp::Any visitFlingDeclFunc
		(Parser::FlingDeclFuncContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Header
		(Parser::FlingDeclFunc_HeaderContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Scope
		(Parser::FlingDeclFunc_ScopeContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Item
		(Parser::FlingDeclFunc_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Item_If
		(Parser::FlingDeclFunc_Item_IfContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Item_If_Elif
		(Parser::FlingDeclFunc_Item_If_ElifContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Item_If_Else
		(Parser::FlingDeclFunc_Item_If_ElseContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Item_SwitchOrSwitchz
		(Parser::FlingDeclFunc_Item_SwitchOrSwitchzContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Item_SwitchOrSwitchz_Default
		(Parser::FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Item_SwitchOrSwitchz_Case
		(Parser::FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Item_For
		(Parser::FlingDeclFunc_Item_ForContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Item_While
		(Parser::FlingDeclFunc_Item_WhileContext *ctx);
	antlrcpp::Any visitFlingDeclTask
		(Parser::FlingDeclTaskContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Header
		(Parser::FlingDeclTask_HeaderContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Scope
		(Parser::FlingDeclTask_ScopeContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Item
		(Parser::FlingDeclTask_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Item_If
		(Parser::FlingDeclTask_Item_IfContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Item_If_Elif
		(Parser::FlingDeclTask_Item_If_ElifContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Item_If_Else
		(Parser::FlingDeclTask_Item_If_ElseContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Item_SwitchOrSwitchz
		(Parser::FlingDeclTask_Item_SwitchOrSwitchzContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Item_SwitchOrSwitchz_Default
		(Parser::FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Item_SwitchOrSwitchz_Case
		(Parser::FlingDeclTask_Item_SwitchOrSwitchz_CaseContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Item_For
		(Parser::FlingDeclTask_Item_ForContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Item_While
		(Parser::FlingDeclTask_Item_WhileContext *ctx);
	antlrcpp::Any visitFlingDeclProc
		(Parser::FlingDeclProcContext *ctx);
	antlrcpp::Any visitFlingDeclProc_Header
		(Parser::FlingDeclProc_HeaderContext *ctx);
	antlrcpp::Any visitFlingDeclProc_ArgList
		(Parser::FlingDeclProc_ArgListContext *ctx);
	antlrcpp::Any visitFlingDeclProc_ArgList_Item
		(Parser::FlingDeclProc_ArgList_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclAlias
		(Parser::FlingDeclAliasContext *ctx);
	antlrcpp::Any visitFlingDeclAlias_Value
		(Parser::FlingDeclAlias_ValueContext *ctx);
	antlrcpp::Any visitFlingDeclAlias_Type
		(Parser::FlingDeclAlias_TypeContext *ctx);
	antlrcpp::Any visitFlingDeclAlias_Module
		(Parser::FlingDeclAlias_ModuleContext *ctx);
	antlrcpp::Any visitFlingIdent
		(Parser::FlingIdentContext *ctx);
	antlrcpp::Any visitFlingIdentList
		(Parser::FlingIdentListContext *ctx);
	antlrcpp::Any visitFlingScopedIdent
		(Parser::FlingScopedIdentContext *ctx);
	antlrcpp::Any visitFlingExprList
		(Parser::FlingExprListContext *ctx);
	antlrcpp::Any visitFlingTypenameOrModnameList
		(Parser::FlingTypenameOrModnameListContext *ctx);
	antlrcpp::Any visitFlingImportList
		(Parser::FlingImportListContext *ctx);
	antlrcpp::Any visitFlingTypenameOrModname
		(Parser::FlingTypenameOrModnameContext *ctx);
	antlrcpp::Any visitFlingTypenameOrModname_Cstm
		(Parser::FlingTypenameOrModname_CstmContext *ctx);
	antlrcpp::Any visitFlingTypenameOrModname_Cstm_Item
		(Parser::FlingTypenameOrModname_Cstm_ItemContext *ctx);
	antlrcpp::Any visitFlingTypenameOrModname_ArrDim
		(Parser::FlingTypenameOrModname_ArrDimContext *ctx);
	antlrcpp::Any visitFlingTypenameOrModname_Builtin
		(Parser::FlingTypenameOrModname_BuiltinContext *ctx);
	antlrcpp::Any visitFlingExpr
		(Parser::FlingExprContext *ctx);
	antlrcpp::Any visitFlingExpr_Mux
		(Parser::FlingExpr_MuxContext *ctx);
	antlrcpp::Any visitFlingExpr_LogOr
		(Parser::FlingExpr_LogOrContext *ctx);
	antlrcpp::Any visitFlingExpr_LogAnd
		(Parser::FlingExpr_LogAndContext *ctx);
	antlrcpp::Any visitFlingExpr_BitOr_Or_BitNor
		(Parser::FlingExpr_BitOr_Or_BitNorContext *ctx);
	antlrcpp::Any visitFlingExpr_BitAnd_Or_BitNand
		(Parser::FlingExpr_BitAnd_Or_BitNandContext *ctx);
	antlrcpp::Any visitFlingExpr_BitXor_Or_BitXnor
		(Parser::FlingExpr_BitXor_Or_BitXnorContext *ctx);
	antlrcpp::Any visitFlingExpr_CmpEqEtc
		(Parser::FlingExpr_CmpEqEtcContext *ctx);
	antlrcpp::Any visitFlingExpr_CmpLtEtc
		(Parser::FlingExpr_CmpLtEtcContext *ctx);
	antlrcpp::Any visitFlingExpr_BitShift
		(Parser::FlingExpr_BitShiftContext *ctx);
	antlrcpp::Any visitFlingExpr_BinaryPlus_Or_BinaryMinus
		(Parser::FlingExpr_BinaryPlus_Or_BinaryMinusContext *ctx);
	antlrcpp::Any visitFlingExpr_Mul_Or_Div_Or_Mod
		(Parser::FlingExpr_Mul_Or_Div_Or_ModContext *ctx);
	antlrcpp::Any visitFlingExpr_Unary
		(Parser::FlingExpr_UnaryContext *ctx);
	antlrcpp::Any visitFlingExpr_Unary_ItemWithoutRange
		(Parser::FlingExpr_Unary_ItemWithoutRangeContext *ctx);
	antlrcpp::Any visitFlingExpr_Literal
		(Parser::FlingExpr_LiteralContext *ctx);
	antlrcpp::Any visitFlingExpr_Sized
		(Parser::FlingExpr_SizedContext *ctx);
	antlrcpp::Any visitFlingExpr_Range
		(Parser::FlingExpr_RangeContext *ctx);
	antlrcpp::Any visitFlingExpr_Cat
		(Parser::FlingExpr_CatContext *ctx);
	antlrcpp::Any visitFlingExpr_Repl
		(Parser::FlingExpr_ReplContext *ctx);
	antlrcpp::Any visitFlingExpr_KwDollarFuncOf
		(Parser::FlingExpr_KwDollarFuncOfContext *ctx);
	antlrcpp::Any visitFlingExpr_KwDollarFuncOf_NonPow
		(Parser::FlingExpr_KwDollarFuncOf_NonPowContext *ctx);
	antlrcpp::Any visitFlingExpr_KwDollarFuncOf_Pow
		(Parser::FlingExpr_KwDollarFuncOf_PowContext *ctx);
	antlrcpp::Any visitFlingExpr_IdentEtcAndOptKwDollarFuncOf
		(Parser::FlingExpr_IdentEtcAndOptKwDollarFuncOfContext *ctx);
	antlrcpp::Any visitFlingExpr_IdentEtc
		(Parser::FlingExpr_IdentEtcContext *ctx);
	antlrcpp::Any visitFlingExpr_IdentEtc_Item
		(Parser::FlingExpr_IdentEtc_ItemContext *ctx);
	antlrcpp::Any visitFlingExpr_IdentEtc_Item_End
		(Parser::FlingExpr_IdentEtc_Item_EndContext *ctx);
	antlrcpp::Any visitFlingExpr_CallSubprog
		(Parser::FlingExpr_CallSubprogContext *ctx);
	antlrcpp::Any visitFlingExpr_CallSubprog_Regular
		(Parser::FlingExpr_CallSubprog_RegularContext *ctx);
	antlrcpp::Any visitFlingExpr_CallSubprog_PseudoOper
		(Parser::FlingExpr_CallSubprog_PseudoOperContext *ctx);
};

} // namespace fling_hdl


#endif		// src_pt_visitor_class_hpp
