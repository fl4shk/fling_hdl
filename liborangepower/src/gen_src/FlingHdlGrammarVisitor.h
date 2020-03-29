
// Generated from FlingHdlGrammar.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "FlingHdlGrammarParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by FlingHdlGrammarParser.
 */
class  FlingHdlGrammarVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by FlingHdlGrammarParser.
   */
    virtual antlrcpp::Any visitFlingProgram(FlingHdlGrammarParser::FlingProgramContext *context) = 0;

    virtual antlrcpp::Any visitFlingProgram_Item(FlingHdlGrammarParser::FlingProgram_ItemContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclPackage(FlingHdlGrammarParser::FlingDeclPackageContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclPackage_Item(FlingHdlGrammarParser::FlingDeclPackage_ItemContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclParamList(FlingHdlGrammarParser::FlingDeclParamListContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclParamList_Item(FlingHdlGrammarParser::FlingDeclParamList_ItemContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclArgList(FlingHdlGrammarParser::FlingDeclArgListContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclArgList_Item(FlingHdlGrammarParser::FlingDeclArgList_ItemContext *context) = 0;

    virtual antlrcpp::Any visitFlingInstParamList(FlingHdlGrammarParser::FlingInstParamListContext *context) = 0;

    virtual antlrcpp::Any visitFlingInstParamList_Pos(FlingHdlGrammarParser::FlingInstParamList_PosContext *context) = 0;

    virtual antlrcpp::Any visitFlingInstParamList_Pos_Item(FlingHdlGrammarParser::FlingInstParamList_Pos_ItemContext *context) = 0;

    virtual antlrcpp::Any visitFlingInstParamList_Named(FlingHdlGrammarParser::FlingInstParamList_NamedContext *context) = 0;

    virtual antlrcpp::Any visitFlingInstParamList_Named_Item(FlingHdlGrammarParser::FlingInstParamList_Named_ItemContext *context) = 0;

    virtual antlrcpp::Any visitFlingInstArgList(FlingHdlGrammarParser::FlingInstArgListContext *context) = 0;

    virtual antlrcpp::Any visitFlingInstArgList_Pos(FlingHdlGrammarParser::FlingInstArgList_PosContext *context) = 0;

    virtual antlrcpp::Any visitFlingInstArgList_Named(FlingHdlGrammarParser::FlingInstArgList_NamedContext *context) = 0;

    virtual antlrcpp::Any visitFlingInstArgList_Named_Item(FlingHdlGrammarParser::FlingInstArgList_Named_ItemContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclModule(FlingHdlGrammarParser::FlingDeclModuleContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclModule_Scope(FlingHdlGrammarParser::FlingDeclModule_ScopeContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclModule_Item(FlingHdlGrammarParser::FlingDeclModule_ItemContext *context) = 0;

    virtual antlrcpp::Any visitFlingInstModule(FlingHdlGrammarParser::FlingInstModuleContext *context) = 0;

    virtual antlrcpp::Any visitFlingGen(FlingHdlGrammarParser::FlingGenContext *context) = 0;

    virtual antlrcpp::Any visitFlingGen_If(FlingHdlGrammarParser::FlingGen_IfContext *context) = 0;

    virtual antlrcpp::Any visitFlingGen_If_Elif(FlingHdlGrammarParser::FlingGen_If_ElifContext *context) = 0;

    virtual antlrcpp::Any visitFlingGen_If_Else(FlingHdlGrammarParser::FlingGen_If_ElseContext *context) = 0;

    virtual antlrcpp::Any visitFlingGen_Switch(FlingHdlGrammarParser::FlingGen_SwitchContext *context) = 0;

    virtual antlrcpp::Any visitFlingGen_Switch_Default(FlingHdlGrammarParser::FlingGen_Switch_DefaultContext *context) = 0;

    virtual antlrcpp::Any visitFlingGen_Switch_Case(FlingHdlGrammarParser::FlingGen_Switch_CaseContext *context) = 0;

    virtual antlrcpp::Any visitFlingGen_For(FlingHdlGrammarParser::FlingGen_ForContext *context) = 0;

    virtual antlrcpp::Any visitFlingContAssign(FlingHdlGrammarParser::FlingContAssignContext *context) = 0;

    virtual antlrcpp::Any visitFlingBehav(FlingHdlGrammarParser::FlingBehavContext *context) = 0;

    virtual antlrcpp::Any visitFlingBehav_Seq_EdgeList(FlingHdlGrammarParser::FlingBehav_Seq_EdgeListContext *context) = 0;

    virtual antlrcpp::Any visitFlingBehav_Seq_EdgeList_Item(FlingHdlGrammarParser::FlingBehav_Seq_EdgeList_ItemContext *context) = 0;

    virtual antlrcpp::Any visitFlingBehav_Scope(FlingHdlGrammarParser::FlingBehav_ScopeContext *context) = 0;

    virtual antlrcpp::Any visitFlingBehav_Item(FlingHdlGrammarParser::FlingBehav_ItemContext *context) = 0;

    virtual antlrcpp::Any visitFlingBehav_Item_If(FlingHdlGrammarParser::FlingBehav_Item_IfContext *context) = 0;

    virtual antlrcpp::Any visitFlingBehav_Item_If_Elif(FlingHdlGrammarParser::FlingBehav_Item_If_ElifContext *context) = 0;

    virtual antlrcpp::Any visitFlingBehav_Item_If_Else(FlingHdlGrammarParser::FlingBehav_Item_If_ElseContext *context) = 0;

    virtual antlrcpp::Any visitFlingBehav_Item_SwitchOrSwitchz(FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchzContext *context) = 0;

    virtual antlrcpp::Any visitFlingBehav_Item_SwitchOrSwitchz_Default(FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_DefaultContext *context) = 0;

    virtual antlrcpp::Any visitFlingBehav_Item_SwitchOrSwitchz_Case(FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_CaseContext *context) = 0;

    virtual antlrcpp::Any visitFlingBehav_Item_For(FlingHdlGrammarParser::FlingBehav_Item_ForContext *context) = 0;

    virtual antlrcpp::Any visitFlingBehav_Item_While(FlingHdlGrammarParser::FlingBehav_Item_WhileContext *context) = 0;

    virtual antlrcpp::Any visitFlingBehav_Item_NonBlkAssign(FlingHdlGrammarParser::FlingBehav_Item_NonBlkAssignContext *context) = 0;

    virtual antlrcpp::Any visitFlingBehav_Item_BlkAssign(FlingHdlGrammarParser::FlingBehav_Item_BlkAssignContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclWire(FlingHdlGrammarParser::FlingDeclWireContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclVar(FlingHdlGrammarParser::FlingDeclVarContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclConst(FlingHdlGrammarParser::FlingDeclConstContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclType(FlingHdlGrammarParser::FlingDeclTypeContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclEnum(FlingHdlGrammarParser::FlingDeclEnumContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclClass(FlingHdlGrammarParser::FlingDeclClassContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclClsOrMxn_Extends(FlingHdlGrammarParser::FlingDeclClsOrMxn_ExtendsContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclClass_Item(FlingHdlGrammarParser::FlingDeclClass_ItemContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclClass_Item_DeclVar(FlingHdlGrammarParser::FlingDeclClass_Item_DeclVarContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclClsOrMxn_Item(FlingHdlGrammarParser::FlingDeclClsOrMxn_ItemContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclClsOrMxn_Item_DeclType(FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclTypeContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclClsOrMxn_Item_DeclAliasOrConst(FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclAliasOrConstContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclClsOrMxn_AccessSpecifier(FlingHdlGrammarParser::FlingDeclClsOrMxn_AccessSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclClsOrMxn_Item_DeclSubprog(FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprogContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclClsOrMxn_Item_DeclSubprog_FullDefn(FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclClsOrMxn_Item_DeclSubprog_Abstract(FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclMixin(FlingHdlGrammarParser::FlingDeclMixinContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclSubprog(FlingHdlGrammarParser::FlingDeclSubprogContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclFunc(FlingHdlGrammarParser::FlingDeclFuncContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclFunc_Header(FlingHdlGrammarParser::FlingDeclFunc_HeaderContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclFunc_Scope(FlingHdlGrammarParser::FlingDeclFunc_ScopeContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclFunc_Item(FlingHdlGrammarParser::FlingDeclFunc_ItemContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclFunc_Item_If(FlingHdlGrammarParser::FlingDeclFunc_Item_IfContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclFunc_Item_If_Elif(FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElifContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclFunc_Item_If_Else(FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElseContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclFunc_Item_SwitchOrSwitchz(FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchzContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclFunc_Item_SwitchOrSwitchz_Default(FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclFunc_Item_SwitchOrSwitchz_Case(FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclFunc_Item_For(FlingHdlGrammarParser::FlingDeclFunc_Item_ForContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclFunc_Item_While(FlingHdlGrammarParser::FlingDeclFunc_Item_WhileContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclTask(FlingHdlGrammarParser::FlingDeclTaskContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclTask_Header(FlingHdlGrammarParser::FlingDeclTask_HeaderContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclTask_Scope(FlingHdlGrammarParser::FlingDeclTask_ScopeContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclTask_Item(FlingHdlGrammarParser::FlingDeclTask_ItemContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclTask_Item_If(FlingHdlGrammarParser::FlingDeclTask_Item_IfContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclTask_Item_If_Elif(FlingHdlGrammarParser::FlingDeclTask_Item_If_ElifContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclTask_Item_If_Else(FlingHdlGrammarParser::FlingDeclTask_Item_If_ElseContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclTask_Item_SwitchOrSwitchz(FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchzContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclTask_Item_SwitchOrSwitchz_Default(FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclTask_Item_SwitchOrSwitchz_Case(FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_CaseContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclTask_Item_For(FlingHdlGrammarParser::FlingDeclTask_Item_ForContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclTask_Item_While(FlingHdlGrammarParser::FlingDeclTask_Item_WhileContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclProc(FlingHdlGrammarParser::FlingDeclProcContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclProc_Header(FlingHdlGrammarParser::FlingDeclProc_HeaderContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclProc_ArgList(FlingHdlGrammarParser::FlingDeclProc_ArgListContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclProc_ArgList_Item(FlingHdlGrammarParser::FlingDeclProc_ArgList_ItemContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclAlias(FlingHdlGrammarParser::FlingDeclAliasContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclAlias_Value(FlingHdlGrammarParser::FlingDeclAlias_ValueContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclAlias_Type(FlingHdlGrammarParser::FlingDeclAlias_TypeContext *context) = 0;

    virtual antlrcpp::Any visitFlingDeclAlias_Module(FlingHdlGrammarParser::FlingDeclAlias_ModuleContext *context) = 0;

    virtual antlrcpp::Any visitFlingIdent(FlingHdlGrammarParser::FlingIdentContext *context) = 0;

    virtual antlrcpp::Any visitFlingIdentList(FlingHdlGrammarParser::FlingIdentListContext *context) = 0;

    virtual antlrcpp::Any visitFlingScopedIdent(FlingHdlGrammarParser::FlingScopedIdentContext *context) = 0;

    virtual antlrcpp::Any visitFlingExprList(FlingHdlGrammarParser::FlingExprListContext *context) = 0;

    virtual antlrcpp::Any visitFlingTypenameOrModnameList(FlingHdlGrammarParser::FlingTypenameOrModnameListContext *context) = 0;

    virtual antlrcpp::Any visitFlingImportList(FlingHdlGrammarParser::FlingImportListContext *context) = 0;

    virtual antlrcpp::Any visitFlingTypenameOrModname(FlingHdlGrammarParser::FlingTypenameOrModnameContext *context) = 0;

    virtual antlrcpp::Any visitFlingTypenameOrModname_Cstm(FlingHdlGrammarParser::FlingTypenameOrModname_CstmContext *context) = 0;

    virtual antlrcpp::Any visitFlingTypenameOrModname_Cstm_Item(FlingHdlGrammarParser::FlingTypenameOrModname_Cstm_ItemContext *context) = 0;

    virtual antlrcpp::Any visitFlingTypenameOrModname_ArrDim(FlingHdlGrammarParser::FlingTypenameOrModname_ArrDimContext *context) = 0;

    virtual antlrcpp::Any visitFlingTypenameOrModname_Builtin(FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr(FlingHdlGrammarParser::FlingExprContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_Mux(FlingHdlGrammarParser::FlingExpr_MuxContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_LogOr(FlingHdlGrammarParser::FlingExpr_LogOrContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_LogAnd(FlingHdlGrammarParser::FlingExpr_LogAndContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_BitOr_Or_BitNor(FlingHdlGrammarParser::FlingExpr_BitOr_Or_BitNorContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_BitAnd_Or_BitNand(FlingHdlGrammarParser::FlingExpr_BitAnd_Or_BitNandContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_BitXor_Or_BitXnor(FlingHdlGrammarParser::FlingExpr_BitXor_Or_BitXnorContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_CmpEqEtc(FlingHdlGrammarParser::FlingExpr_CmpEqEtcContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_CmpLtEtc(FlingHdlGrammarParser::FlingExpr_CmpLtEtcContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_BitShift(FlingHdlGrammarParser::FlingExpr_BitShiftContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_BinaryPlus_Or_BinaryMinus(FlingHdlGrammarParser::FlingExpr_BinaryPlus_Or_BinaryMinusContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_Mul_Or_Div_Or_Mod(FlingHdlGrammarParser::FlingExpr_Mul_Or_Div_Or_ModContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_Unary(FlingHdlGrammarParser::FlingExpr_UnaryContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_Unary_ItemFromMajority(FlingHdlGrammarParser::FlingExpr_Unary_ItemFromMajorityContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_Literal(FlingHdlGrammarParser::FlingExpr_LiteralContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_Sized(FlingHdlGrammarParser::FlingExpr_SizedContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_Range(FlingHdlGrammarParser::FlingExpr_RangeContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_Range_DotDot(FlingHdlGrammarParser::FlingExpr_Range_DotDotContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_Range_CallFunc(FlingHdlGrammarParser::FlingExpr_Range_CallFuncContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_Cat(FlingHdlGrammarParser::FlingExpr_CatContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_Repl(FlingHdlGrammarParser::FlingExpr_ReplContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_KwDollarFuncOf(FlingHdlGrammarParser::FlingExpr_KwDollarFuncOfContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_KwDollarFuncOf_NonPow(FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_NonPowContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_KwDollarFuncOf_Pow(FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_PowContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_IdentEtc(FlingHdlGrammarParser::FlingExpr_IdentEtcContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_IdentEtc_Item(FlingHdlGrammarParser::FlingExpr_IdentEtc_ItemContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_IdentEtc_Item_End(FlingHdlGrammarParser::FlingExpr_IdentEtc_Item_EndContext *context) = 0;

    virtual antlrcpp::Any visitFlingExpr_CallSubprog_PseudoOper(FlingHdlGrammarParser::FlingExpr_CallSubprog_PseudoOperContext *context) = 0;


};

