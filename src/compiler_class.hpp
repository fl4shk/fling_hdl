#ifndef src_compiler_class_hpp
#define src_compiler_class_hpp

// src/compiler_class.hpp

#include "misc_includes.hpp"
#include "ANTLRErrorListener.h"
#include "gen_src/FlingHdlGrammarLexer.h"
#include "gen_src/FlingHdlGrammarParser.h"
#include "gen_src/FlingHdlGrammarVisitor.h"

namespace fling_hdl
{

class Compiler : public FlingHdlGrammarVisitor
{
public:		// typedefs
	using ParserRuleContext = antlr4::ParserRuleContext;

private:		// variables
	using Parser = FlingHdlGrammarParser;
	Parser::FlingProgramContext* _program_ctx = nullptr;

	std::stack<string> _str_stack;
	std::stack<BigNum> _num_stack;

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

public:		// functions
	Compiler(FlingHdlGrammarParser& parser);
	virtual ~Compiler();
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
			auto tok = ctx->getStart();
			const size_t line = tok->getLine();
			const size_t pos_in_line = tok->getCharPositionInLine();
			//printerr("Error in file \"", *__file_name, "\", on line ",
			//	line, ", position ", pos_in_line, ":  ", msg, "\n");
			printerr("Error on line ", line, ", position ", pos_in_line, 
				":  ", msg, "\n");
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
			auto tok = ctx->getStart();
			const size_t line = tok->getLine();
			const size_t pos_in_line = tok->getCharPositionInLine();
			//printerr("Error in file \"", *__file_name, "\", on line ",
			//	line, ", position ", pos_in_line, ":  ", msg, "\n");
			printerr("Warning on line ", line, ", position ", pos_in_line, 
				":  ", msg, "\n");
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
	antlrcpp::Any visitFlingBehav_If
		(Parser::FlingBehav_IfContext *ctx);
	antlrcpp::Any visitFlingBehav_If_Elif
		(Parser::FlingBehav_If_ElifContext *ctx);
	antlrcpp::Any visitFlingBehav_If_Else
		(Parser::FlingBehav_If_ElseContext *ctx);
	antlrcpp::Any visitFlingBehav_SwitchOrSwitchz
		(Parser::FlingBehav_SwitchOrSwitchzContext *ctx);
	antlrcpp::Any visitFlingBehav_SwitchOrSwitchz_Default
		(Parser::FlingBehav_SwitchOrSwitchz_DefaultContext *ctx);
	antlrcpp::Any visitFlingBehav_SwitchOrSwitchz_Case
		(Parser::FlingBehav_SwitchOrSwitchz_CaseContext *ctx);
	antlrcpp::Any visitFlingBehav_For
		(Parser::FlingBehav_ForContext *ctx);
	antlrcpp::Any visitFlingBehav_While
		(Parser::FlingBehav_WhileContext *ctx);
	antlrcpp::Any visitFlingBehav_NonBlkAssign
		(Parser::FlingBehav_NonBlkAssignContext *ctx);
	antlrcpp::Any visitFlingBehav_BlkAssign
		(Parser::FlingBehav_BlkAssignContext *ctx);
	antlrcpp::Any visitFlingDeclWire
		(Parser::FlingDeclWireContext *ctx);
	antlrcpp::Any visitFlingDeclVar
		(Parser::FlingDeclVarContext *ctx);
	antlrcpp::Any visitFlingDeclConst
		(Parser::FlingDeclConstContext *ctx);
	antlrcpp::Any visitFlingDeclType
		(Parser::FlingDeclTypeContext *ctx);
	antlrcpp::Any visitFlingDeclType_Enum
		(Parser::FlingDeclType_EnumContext *ctx);
	antlrcpp::Any visitFlingDeclType_Class
		(Parser::FlingDeclType_ClassContext *ctx);
	antlrcpp::Any visitFlingDeclType_ClassOrMixin_Extends
		(Parser::FlingDeclType_ClassOrMixin_ExtendsContext *ctx);
	antlrcpp::Any visitFlingDeclType_Class_Item
		(Parser::FlingDeclType_Class_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclType_ClassOrMixin_Item
		(Parser::FlingDeclType_ClassOrMixin_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclType_ClassOrMixin_AccessSpecifier
		(Parser::FlingDeclType_ClassOrMixin_AccessSpecifierContext *ctx);
	antlrcpp::Any visitFlingDeclType_ClassOrMixin_Item_DeclSubprog
		(Parser::FlingDeclType_ClassOrMixin_Item_DeclSubprogContext *ctx);
	antlrcpp::Any visitFlingDeclType_Mixin
		(Parser::FlingDeclType_MixinContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog
		(Parser::FlingDeclSubprogContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Func
		(Parser::FlingDeclSubprog_FuncContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Func_Header
		(Parser::FlingDeclSubprog_Func_HeaderContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Func_Scope
		(Parser::FlingDeclSubprog_Func_ScopeContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Func_Item
		(Parser::FlingDeclSubprog_Func_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Func_If
		(Parser::FlingDeclSubprog_Func_IfContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Func_If_Elif
		(Parser::FlingDeclSubprog_Func_If_ElifContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Func_If_Else
		(Parser::FlingDeclSubprog_Func_If_ElseContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Func_SwitchOrSwitchz
		(Parser::FlingDeclSubprog_Func_SwitchOrSwitchzContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Func_SwitchOrSwitchz_Default
		(Parser::FlingDeclSubprog_Func_SwitchOrSwitchz_DefaultContext
		*ctx);
	antlrcpp::Any visitFlingDeclSubprog_Func_SwitchOrSwitchz_Case
		(Parser::FlingDeclSubprog_Func_SwitchOrSwitchz_CaseContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Func_For
		(Parser::FlingDeclSubprog_Func_ForContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Func_While
		(Parser::FlingDeclSubprog_Func_WhileContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Task
		(Parser::FlingDeclSubprog_TaskContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Task_Header
		(Parser::FlingDeclSubprog_Task_HeaderContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Task_Scope
		(Parser::FlingDeclSubprog_Task_ScopeContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Task_Item
		(Parser::FlingDeclSubprog_Task_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Task_If
		(Parser::FlingDeclSubprog_Task_IfContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Task_If_Elif
		(Parser::FlingDeclSubprog_Task_If_ElifContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Task_If_Else
		(Parser::FlingDeclSubprog_Task_If_ElseContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Task_SwitchOrSwitchz
		(Parser::FlingDeclSubprog_Task_SwitchOrSwitchzContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Task_SwitchOrSwitchz_Default
		(Parser::FlingDeclSubprog_Task_SwitchOrSwitchz_DefaultContext
		*ctx);
	antlrcpp::Any visitFlingDeclSubprog_Task_SwitchOrSwitchz_Case
		(Parser::FlingDeclSubprog_Task_SwitchOrSwitchz_CaseContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Task_For
		(Parser::FlingDeclSubprog_Task_ForContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Task_While
		(Parser::FlingDeclSubprog_Task_WhileContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Proc
		(Parser::FlingDeclSubprog_ProcContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Proc_Header
		(Parser::FlingDeclSubprog_Proc_HeaderContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Proc_ArgList
		(Parser::FlingDeclSubprog_Proc_ArgListContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog_Proc_ArgList_Item
		(Parser::FlingDeclSubprog_Proc_ArgList_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclAlias
		(Parser::FlingDeclAliasContext *ctx);
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
	antlrcpp::Any visitFlingTypenameOrModname_Cstm_ArrDim
		(Parser::FlingTypenameOrModname_Cstm_ArrDimContext *ctx);
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
	antlrcpp::Any visitFlingExpr_LitNum
		(Parser::FlingExpr_LitNumContext *ctx);
	antlrcpp::Any visitFlingExpr_LitRange
		(Parser::FlingExpr_LitRangeContext *ctx);
	antlrcpp::Any visitFlingExpr_LitRange_Item
		(Parser::FlingExpr_LitRange_ItemContext *ctx);
	antlrcpp::Any visitFlingExpr_IdentEtc
		(Parser::FlingExpr_IdentEtcContext *ctx);
	antlrcpp::Any visitFlingExpr_IdentEtc_Item
		(Parser::FlingExpr_IdentEtc_ItemContext *ctx);
	antlrcpp::Any visitFlingExpr_IdentEtc_Item_End
		(Parser::FlingExpr_IdentEtc_Item_EndContext *ctx);
	antlrcpp::Any visitFlingExpr_CallSubprog
		(Parser::FlingExpr_CallSubprogContext *ctx);
};

} // namespace fling_hdl


#endif		// src_compiler_class_hpp
