#include "src/compiler_class.hpp"

namespace fling_hdl
{

Compiler::Compiler(FlingHdlGrammarParser& parser)
{
	_program_ctx = parser.flingProgram();
}
Compiler::~Compiler()
{
}
int Compiler::run()
{
	return 0;
}

antlrcpp::Any Compiler::visitFlingProgram
	(Parser::FlingProgramContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclPackage
	(Parser::FlingDeclPackageContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclPackage_Item
	(Parser::FlingDeclPackage_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclParamList
	(Parser::FlingDeclParamListContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclParamList_Item
	(Parser::FlingDeclParamList_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclArgList
	(Parser::FlingDeclArgListContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclArgList_Item
	(Parser::FlingDeclArgList_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingInstParamList
	(Parser::FlingInstParamListContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingInstParamList_Pos
	(Parser::FlingInstParamList_PosContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingInstParamList_Pos_Item
	(Parser::FlingInstParamList_Pos_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingInstParamList_Named
	(Parser::FlingInstParamList_NamedContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingInstParamList_Named_Item
	(Parser::FlingInstParamList_Named_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingInstArgList
	(Parser::FlingInstArgListContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingInstArgList_Pos
	(Parser::FlingInstArgList_PosContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingInstArgList_Named
	(Parser::FlingInstArgList_NamedContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingInstArgList_Named_Item
	(Parser::FlingInstArgList_Named_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclModule
	(Parser::FlingDeclModuleContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclModule_Scope
	(Parser::FlingDeclModule_ScopeContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclModule_Item
	(Parser::FlingDeclModule_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingInstModule
	(Parser::FlingInstModuleContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingGenerate
	(Parser::FlingGenerateContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingGenerate_If
	(Parser::FlingGenerate_IfContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingGenerate_If_Elif
	(Parser::FlingGenerate_If_ElifContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingGenerate_If_Else
	(Parser::FlingGenerate_If_ElseContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingGenerate_Switch
	(Parser::FlingGenerate_SwitchContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingGenerate_Switch_Default
	(Parser::FlingGenerate_Switch_DefaultContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingGenerate_Switch_Case
	(Parser::FlingGenerate_Switch_CaseContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingGenerate_For
	(Parser::FlingGenerate_ForContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingContAssign
	(Parser::FlingContAssignContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav
	(Parser::FlingBehavContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_Seq_EdgeList
	(Parser::FlingBehav_Seq_EdgeListContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_Seq_EdgeList_Item
	(Parser::FlingBehav_Seq_EdgeList_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_Scope
	(Parser::FlingBehav_ScopeContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_Item
	(Parser::FlingBehav_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_Item_WithoutScope
	(Parser::FlingBehav_Item_WithoutScopeContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_If
	(Parser::FlingBehav_IfContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_If_Elif
	(Parser::FlingBehav_If_ElifContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_If_Else
	(Parser::FlingBehav_If_ElseContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_SwitchOrSwitchz
	(Parser::FlingBehav_SwitchOrSwitchzContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_SwitchOrSwitchz_Default
	(Parser::FlingBehav_SwitchOrSwitchz_DefaultContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_SwitchOrSwitchz_Case
	(Parser::FlingBehav_SwitchOrSwitchz_CaseContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_For
	(Parser::FlingBehav_ForContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_While
	(Parser::FlingBehav_WhileContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_NonBlkAssign
	(Parser::FlingBehav_NonBlkAssignContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_BlkAssign
	(Parser::FlingBehav_BlkAssignContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclWire
	(Parser::FlingDeclWireContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclVar
	(Parser::FlingDeclVarContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclConst
	(Parser::FlingDeclConstContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclType
	(Parser::FlingDeclTypeContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclType_Enum
	(Parser::FlingDeclType_EnumContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclType_Class
	(Parser::FlingDeclType_ClassContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclType_ClassOrMixin_Extends
	(Parser::FlingDeclType_ClassOrMixin_ExtendsContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclType_Class_Item
	(Parser::FlingDeclType_Class_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclType_ClassOrMixin_Item
	(Parser::FlingDeclType_ClassOrMixin_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclType_ClassOrMixin_AccessSpecifier
	(Parser::FlingDeclType_ClassOrMixin_AccessSpecifierContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclType_ClassOrMixin_Item_DeclSubprog
	(Parser::FlingDeclType_ClassOrMixin_Item_DeclSubprogContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclType_Mixin
	(Parser::FlingDeclType_MixinContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclSubprog
	(Parser::FlingDeclSubprogContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclSubprog_Func
	(Parser::FlingDeclSubprog_FuncContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclSubprog_Func_Header
	(Parser::FlingDeclSubprog_Func_HeaderContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclSubprog_Func_Scope
	(Parser::FlingDeclSubprog_Func_ScopeContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclSubprog_Func_Scope_Item
	(Parser::FlingDeclSubprog_Func_Scope_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclSubprog_Task
	(Parser::FlingDeclSubprog_TaskContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclSubprog_Task_Header
	(Parser::FlingDeclSubprog_Task_HeaderContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclSubprog_Proc
	(Parser::FlingDeclSubprog_ProcContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclSubprog_Proc_Header
	(Parser::FlingDeclSubprog_Proc_HeaderContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclSubprog_Proc_ArgList
	(Parser::FlingDeclSubprog_Proc_ArgListContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclSubprog_Proc_ArgList_Item
	(Parser::FlingDeclSubprog_Proc_ArgList_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclAlias
	(Parser::FlingDeclAliasContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingIdent
	(Parser::FlingIdentContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingIdentList
	(Parser::FlingIdentListContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingScopedIdent
	(Parser::FlingScopedIdentContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExprList
	(Parser::FlingExprListContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingTypenameOrModnameList
	(Parser::FlingTypenameOrModnameListContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingImportList
	(Parser::FlingImportListContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingTypenameOrModname
	(Parser::FlingTypenameOrModnameContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingTypenameOrModname_Cstm
	(Parser::FlingTypenameOrModname_CstmContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingTypenameOrModname_Cstm_Item
	(Parser::FlingTypenameOrModname_Cstm_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingTypenameOrModname_Cstm_ArrDim
	(Parser::FlingTypenameOrModname_Cstm_ArrDimContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingTypenameOrModname_Builtin
	(Parser::FlingTypenameOrModname_BuiltinContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr
	(Parser::FlingExprContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_Mux
	(Parser::FlingExpr_MuxContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_LogOr
	(Parser::FlingExpr_LogOrContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_LogAnd
	(Parser::FlingExpr_LogAndContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_BitOr_Or_BitNor
	(Parser::FlingExpr_BitOr_Or_BitNorContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_BitAnd_Or_BitNand
	(Parser::FlingExpr_BitAnd_Or_BitNandContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_BitXor_Or_BitXnor
	(Parser::FlingExpr_BitXor_Or_BitXnorContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_CmpEqEtc
	(Parser::FlingExpr_CmpEqEtcContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_CmpLtEtc
	(Parser::FlingExpr_CmpLtEtcContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_BitShift
	(Parser::FlingExpr_BitShiftContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_BinaryPlus_Or_BinaryMinus
	(Parser::FlingExpr_BinaryPlus_Or_BinaryMinusContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_Mul_Or_Div_Or_Mod
	(Parser::FlingExpr_Mul_Or_Div_Or_ModContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_Unary
	(Parser::FlingExpr_UnaryContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_LitNum
	(Parser::FlingExpr_LitNumContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_LitRange
	(Parser::FlingExpr_LitRangeContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_LitRange_Item
	(Parser::FlingExpr_LitRange_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_IdentEtc
	(Parser::FlingExpr_IdentEtcContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_IdentEtc_Item
	(Parser::FlingExpr_IdentEtc_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_IdentEtc_Item_End
	(Parser::FlingExpr_IdentEtc_Item_EndContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_CallSubprog
	(Parser::FlingExpr_CallSubprogContext *ctx)
{
	return nullptr;
}

} // namespace fling_hdl
