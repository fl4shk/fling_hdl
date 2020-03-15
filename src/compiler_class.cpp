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
antlrcpp::Any Compiler::visitFlingProgram_Item
	(Parser::FlingProgram_ItemContext *ctx)
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
antlrcpp::Any Compiler::visitFlingGen
	(Parser::FlingGenContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingGen_If
	(Parser::FlingGen_IfContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingGen_If_Elif
	(Parser::FlingGen_If_ElifContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingGen_If_Else
	(Parser::FlingGen_If_ElseContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingGen_Switch
	(Parser::FlingGen_SwitchContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingGen_Switch_Default
	(Parser::FlingGen_Switch_DefaultContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingGen_Switch_Case
	(Parser::FlingGen_Switch_CaseContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingGen_For
	(Parser::FlingGen_ForContext *ctx)
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
antlrcpp::Any Compiler::visitFlingBehav_Item_If
	(Parser::FlingBehav_Item_IfContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_Item_If_Elif
	(Parser::FlingBehav_Item_If_ElifContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_Item_If_Else
	(Parser::FlingBehav_Item_If_ElseContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_Item_SwitchOrSwitchz
	(Parser::FlingBehav_Item_SwitchOrSwitchzContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_Item_SwitchOrSwitchz_Default
	(Parser::FlingBehav_Item_SwitchOrSwitchz_DefaultContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_Item_SwitchOrSwitchz_Case
	(Parser::FlingBehav_Item_SwitchOrSwitchz_CaseContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_Item_For
	(Parser::FlingBehav_Item_ForContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_Item_While
	(Parser::FlingBehav_Item_WhileContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_Item_NonBlkAssign
	(Parser::FlingBehav_Item_NonBlkAssignContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingBehav_Item_BlkAssign
	(Parser::FlingBehav_Item_BlkAssignContext *ctx)
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
antlrcpp::Any Compiler::visitFlingDeclEnum
	(Parser::FlingDeclEnumContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclClass
	(Parser::FlingDeclClassContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclClsOrMxn_Extends
	(Parser::FlingDeclClsOrMxn_ExtendsContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclClass_Item
	(Parser::FlingDeclClass_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclClass_Item_DeclVar
	(Parser::FlingDeclClass_Item_DeclVarContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclClsOrMxn_Item
	(Parser::FlingDeclClsOrMxn_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclClsOrMxn_Item_DeclType
	(Parser::FlingDeclClsOrMxn_Item_DeclTypeContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclClsOrMxn_Item_DeclAliasOrConst
	(Parser::FlingDeclClsOrMxn_Item_DeclAliasOrConstContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclClsOrMxn_AccessSpecifier
	(Parser::FlingDeclClsOrMxn_AccessSpecifierContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclClsOrMxn_Item_DeclSubprog
	(Parser::FlingDeclClsOrMxn_Item_DeclSubprogContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclClsOrMxn_Item_DeclSubprog_FullDefn
	(Parser::FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclClsOrMxn_Item_DeclSubprog_Abstract
	(Parser::FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclMixin
	(Parser::FlingDeclMixinContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclSubprog
	(Parser::FlingDeclSubprogContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclFunc
	(Parser::FlingDeclFuncContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclFunc_Header
	(Parser::FlingDeclFunc_HeaderContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclFunc_Scope
	(Parser::FlingDeclFunc_ScopeContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclFunc_Item
	(Parser::FlingDeclFunc_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclFunc_Item_If
	(Parser::FlingDeclFunc_Item_IfContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclFunc_Item_If_Elif
	(Parser::FlingDeclFunc_Item_If_ElifContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclFunc_Item_If_Else
	(Parser::FlingDeclFunc_Item_If_ElseContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclFunc_Item_SwitchOrSwitchz
	(Parser::FlingDeclFunc_Item_SwitchOrSwitchzContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclFunc_Item_SwitchOrSwitchz_Default
	(Parser::FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclFunc_Item_SwitchOrSwitchz_Case
	(Parser::FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclFunc_Item_For
	(Parser::FlingDeclFunc_Item_ForContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclFunc_Item_While
	(Parser::FlingDeclFunc_Item_WhileContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclTask
	(Parser::FlingDeclTaskContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclTask_Header
	(Parser::FlingDeclTask_HeaderContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclTask_Scope
	(Parser::FlingDeclTask_ScopeContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclTask_Item
	(Parser::FlingDeclTask_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclTask_Item_If
	(Parser::FlingDeclTask_Item_IfContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclTask_Item_If_Elif
	(Parser::FlingDeclTask_Item_If_ElifContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclTask_Item_If_Else
	(Parser::FlingDeclTask_Item_If_ElseContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclTask_Item_SwitchOrSwitchz
	(Parser::FlingDeclTask_Item_SwitchOrSwitchzContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclTask_Item_SwitchOrSwitchz_Default
	(Parser::FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclTask_Item_SwitchOrSwitchz_Case
	(Parser::FlingDeclTask_Item_SwitchOrSwitchz_CaseContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclTask_Item_For
	(Parser::FlingDeclTask_Item_ForContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclTask_Item_While
	(Parser::FlingDeclTask_Item_WhileContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclProc
	(Parser::FlingDeclProcContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclProc_Header
	(Parser::FlingDeclProc_HeaderContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclProc_ArgList
	(Parser::FlingDeclProc_ArgListContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclProc_ArgList_Item
	(Parser::FlingDeclProc_ArgList_ItemContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclAlias
	(Parser::FlingDeclAliasContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclAlias_Value
	(Parser::FlingDeclAlias_ValueContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclAlias_Type
	(Parser::FlingDeclAlias_TypeContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingDeclAlias_Module
	(Parser::FlingDeclAlias_ModuleContext *ctx)
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
antlrcpp::Any Compiler::visitFlingTypenameOrModname_ArrDim
	(Parser::FlingTypenameOrModname_ArrDimContext *ctx)
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
antlrcpp::Any Compiler::visitFlingExpr_Unary_ItemWithoutRange
	(Parser::FlingExpr_Unary_ItemWithoutRangeContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_Literal
	(Parser::FlingExpr_LiteralContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_Sized
	(Parser::FlingExpr_SizedContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_Range
	(Parser::FlingExpr_RangeContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_Cat
	(Parser::FlingExpr_CatContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_Repl
	(Parser::FlingExpr_ReplContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_KwDollarFuncOf
	(Parser::FlingExpr_KwDollarFuncOfContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_KwDollarFuncOf_NonPow
	(Parser::FlingExpr_KwDollarFuncOfContext_NonPow *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_KwDollarFuncOf_Pow
	(Parser::FlingExpr_KwDollarFuncOfContext_Pow *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_IdentEtcAndOptKwDollarFuncOf
	(Parser::FlingExpr_IdentEtcAndOptKwDollarFuncOfContext *ctx)
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
antlrcpp::Any Compiler::visitFlingExpr_CallSubprog_Regular
	(Parser::FlingExpr_CallSubprog_RegularContext *ctx)
{
	return nullptr;
}
antlrcpp::Any Compiler::visitFlingExpr_CallSubprog_PseudoOper
	(Parser::FlingExpr_CallSubprog_PseudoOperContext *ctx)
{
	return nullptr;
}

} // namespace fling_hdl
