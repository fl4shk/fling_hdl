
// Generated from FlingHdlGrammar.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "FlingHdlGrammarVisitor.h"


/**
 * This class provides an empty implementation of FlingHdlGrammarVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  FlingHdlGrammarBaseVisitor : public FlingHdlGrammarVisitor {
public:

  virtual antlrcpp::Any visitFlingProgram(FlingHdlGrammarParser::FlingProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingProgram_Item(FlingHdlGrammarParser::FlingProgram_ItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclPackage(FlingHdlGrammarParser::FlingDeclPackageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclPackage_Item(FlingHdlGrammarParser::FlingDeclPackage_ItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclParamList(FlingHdlGrammarParser::FlingDeclParamListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclParamList_Item(FlingHdlGrammarParser::FlingDeclParamList_ItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclArgList(FlingHdlGrammarParser::FlingDeclArgListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclArgList_Item(FlingHdlGrammarParser::FlingDeclArgList_ItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingInstParamList(FlingHdlGrammarParser::FlingInstParamListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingInstParamList_Pos(FlingHdlGrammarParser::FlingInstParamList_PosContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingInstParamList_Pos_Item(FlingHdlGrammarParser::FlingInstParamList_Pos_ItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingInstParamList_Named(FlingHdlGrammarParser::FlingInstParamList_NamedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingInstParamList_Named_Item(FlingHdlGrammarParser::FlingInstParamList_Named_ItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingInstArgList(FlingHdlGrammarParser::FlingInstArgListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingInstArgList_Pos(FlingHdlGrammarParser::FlingInstArgList_PosContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingInstArgList_Named(FlingHdlGrammarParser::FlingInstArgList_NamedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingInstArgList_Named_Item(FlingHdlGrammarParser::FlingInstArgList_Named_ItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclModule(FlingHdlGrammarParser::FlingDeclModuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclModule_Scope(FlingHdlGrammarParser::FlingDeclModule_ScopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclModule_Item(FlingHdlGrammarParser::FlingDeclModule_ItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingInstModule(FlingHdlGrammarParser::FlingInstModuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingGen(FlingHdlGrammarParser::FlingGenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingGen_If(FlingHdlGrammarParser::FlingGen_IfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingGen_If_Elif(FlingHdlGrammarParser::FlingGen_If_ElifContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingGen_If_Else(FlingHdlGrammarParser::FlingGen_If_ElseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingGen_Switch(FlingHdlGrammarParser::FlingGen_SwitchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingGen_Switch_Default(FlingHdlGrammarParser::FlingGen_Switch_DefaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingGen_Switch_Case(FlingHdlGrammarParser::FlingGen_Switch_CaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingGen_For(FlingHdlGrammarParser::FlingGen_ForContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingContAssign(FlingHdlGrammarParser::FlingContAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingBehav(FlingHdlGrammarParser::FlingBehavContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingBehav_Seq_EdgeList(FlingHdlGrammarParser::FlingBehav_Seq_EdgeListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingBehav_Seq_EdgeList_Item(FlingHdlGrammarParser::FlingBehav_Seq_EdgeList_ItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingBehav_Scope(FlingHdlGrammarParser::FlingBehav_ScopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingBehav_Item(FlingHdlGrammarParser::FlingBehav_ItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingBehav_Item_If(FlingHdlGrammarParser::FlingBehav_Item_IfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingBehav_Item_If_Elif(FlingHdlGrammarParser::FlingBehav_Item_If_ElifContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingBehav_Item_If_Else(FlingHdlGrammarParser::FlingBehav_Item_If_ElseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingBehav_Item_SwitchOrSwitchz(FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchzContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingBehav_Item_SwitchOrSwitchz_Default(FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_DefaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingBehav_Item_SwitchOrSwitchz_Case(FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_CaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingBehav_Item_For(FlingHdlGrammarParser::FlingBehav_Item_ForContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingBehav_Item_While(FlingHdlGrammarParser::FlingBehav_Item_WhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingBehav_Item_NonBlkAssign(FlingHdlGrammarParser::FlingBehav_Item_NonBlkAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingBehav_Item_BlkAssign(FlingHdlGrammarParser::FlingBehav_Item_BlkAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclWire(FlingHdlGrammarParser::FlingDeclWireContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclVar(FlingHdlGrammarParser::FlingDeclVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclConst(FlingHdlGrammarParser::FlingDeclConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclType(FlingHdlGrammarParser::FlingDeclTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclEnum(FlingHdlGrammarParser::FlingDeclEnumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclClass(FlingHdlGrammarParser::FlingDeclClassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclClsOrMxn_Extends(FlingHdlGrammarParser::FlingDeclClsOrMxn_ExtendsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclClass_Item(FlingHdlGrammarParser::FlingDeclClass_ItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclClass_Item_DeclVar(FlingHdlGrammarParser::FlingDeclClass_Item_DeclVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclClsOrMxn_Item(FlingHdlGrammarParser::FlingDeclClsOrMxn_ItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclClsOrMxn_Item_DeclType(FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclClsOrMxn_Item_DeclAliasOrConst(FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclAliasOrConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclClsOrMxn_AccessSpecifier(FlingHdlGrammarParser::FlingDeclClsOrMxn_AccessSpecifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclClsOrMxn_Item_DeclSubprog(FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprogContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclClsOrMxn_Item_DeclSubprog_FullDefn(FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclClsOrMxn_Item_DeclSubprog_Abstract(FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclMixin(FlingHdlGrammarParser::FlingDeclMixinContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclSubprog(FlingHdlGrammarParser::FlingDeclSubprogContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclFunc(FlingHdlGrammarParser::FlingDeclFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclFunc_Header(FlingHdlGrammarParser::FlingDeclFunc_HeaderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclFunc_Scope(FlingHdlGrammarParser::FlingDeclFunc_ScopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclFunc_Item(FlingHdlGrammarParser::FlingDeclFunc_ItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclFunc_Item_If(FlingHdlGrammarParser::FlingDeclFunc_Item_IfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclFunc_Item_If_Elif(FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElifContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclFunc_Item_If_Else(FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclFunc_Item_SwitchOrSwitchz(FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchzContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclFunc_Item_SwitchOrSwitchz_Default(FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclFunc_Item_SwitchOrSwitchz_Case(FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclFunc_Item_For(FlingHdlGrammarParser::FlingDeclFunc_Item_ForContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclFunc_Item_While(FlingHdlGrammarParser::FlingDeclFunc_Item_WhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclTask(FlingHdlGrammarParser::FlingDeclTaskContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclTask_Header(FlingHdlGrammarParser::FlingDeclTask_HeaderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclTask_Scope(FlingHdlGrammarParser::FlingDeclTask_ScopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclTask_Item(FlingHdlGrammarParser::FlingDeclTask_ItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclTask_Item_If(FlingHdlGrammarParser::FlingDeclTask_Item_IfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclTask_Item_If_Elif(FlingHdlGrammarParser::FlingDeclTask_Item_If_ElifContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclTask_Item_If_Else(FlingHdlGrammarParser::FlingDeclTask_Item_If_ElseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclTask_Item_SwitchOrSwitchz(FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchzContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclTask_Item_SwitchOrSwitchz_Default(FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclTask_Item_SwitchOrSwitchz_Case(FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_CaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclTask_Item_For(FlingHdlGrammarParser::FlingDeclTask_Item_ForContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclTask_Item_While(FlingHdlGrammarParser::FlingDeclTask_Item_WhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclProc(FlingHdlGrammarParser::FlingDeclProcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclProc_Header(FlingHdlGrammarParser::FlingDeclProc_HeaderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclProc_ArgList(FlingHdlGrammarParser::FlingDeclProc_ArgListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclProc_ArgList_Item(FlingHdlGrammarParser::FlingDeclProc_ArgList_ItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclAlias(FlingHdlGrammarParser::FlingDeclAliasContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclAlias_Value(FlingHdlGrammarParser::FlingDeclAlias_ValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclAlias_Type(FlingHdlGrammarParser::FlingDeclAlias_TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingDeclAlias_Module(FlingHdlGrammarParser::FlingDeclAlias_ModuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingIdent(FlingHdlGrammarParser::FlingIdentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingIdentList(FlingHdlGrammarParser::FlingIdentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingScopedIdent(FlingHdlGrammarParser::FlingScopedIdentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExprList(FlingHdlGrammarParser::FlingExprListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingTypenameOrModnameList(FlingHdlGrammarParser::FlingTypenameOrModnameListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingImportList(FlingHdlGrammarParser::FlingImportListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingTypenameOrModname(FlingHdlGrammarParser::FlingTypenameOrModnameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingTypenameOrModname_Cstm(FlingHdlGrammarParser::FlingTypenameOrModname_CstmContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingTypenameOrModname_Cstm_Item(FlingHdlGrammarParser::FlingTypenameOrModname_Cstm_ItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingTypenameOrModname_ArrDim(FlingHdlGrammarParser::FlingTypenameOrModname_ArrDimContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingTypenameOrModname_Builtin(FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr(FlingHdlGrammarParser::FlingExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_Mux(FlingHdlGrammarParser::FlingExpr_MuxContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_LogOr(FlingHdlGrammarParser::FlingExpr_LogOrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_LogAnd(FlingHdlGrammarParser::FlingExpr_LogAndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_BitOr_Or_BitNor(FlingHdlGrammarParser::FlingExpr_BitOr_Or_BitNorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_BitAnd_Or_BitNand(FlingHdlGrammarParser::FlingExpr_BitAnd_Or_BitNandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_BitXor_Or_BitXnor(FlingHdlGrammarParser::FlingExpr_BitXor_Or_BitXnorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_CmpEqEtc(FlingHdlGrammarParser::FlingExpr_CmpEqEtcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_CmpLtEtc(FlingHdlGrammarParser::FlingExpr_CmpLtEtcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_BitShift(FlingHdlGrammarParser::FlingExpr_BitShiftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_BinaryPlus_Or_BinaryMinus(FlingHdlGrammarParser::FlingExpr_BinaryPlus_Or_BinaryMinusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_Mul_Or_Div_Or_Mod(FlingHdlGrammarParser::FlingExpr_Mul_Or_Div_Or_ModContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_Unary(FlingHdlGrammarParser::FlingExpr_UnaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_Unary_ItemFromMajority(FlingHdlGrammarParser::FlingExpr_Unary_ItemFromMajorityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_Literal(FlingHdlGrammarParser::FlingExpr_LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_Sized(FlingHdlGrammarParser::FlingExpr_SizedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_Range(FlingHdlGrammarParser::FlingExpr_RangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_Range_DotDot(FlingHdlGrammarParser::FlingExpr_Range_DotDotContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_Range_CallFunc(FlingHdlGrammarParser::FlingExpr_Range_CallFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_Cat(FlingHdlGrammarParser::FlingExpr_CatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_Repl(FlingHdlGrammarParser::FlingExpr_ReplContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_KwDollarFuncOf(FlingHdlGrammarParser::FlingExpr_KwDollarFuncOfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_KwDollarFuncOf_NonPow(FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_NonPowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_KwDollarFuncOf_Pow(FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_PowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_IdentEtc(FlingHdlGrammarParser::FlingExpr_IdentEtcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_IdentEtc_Item(FlingHdlGrammarParser::FlingExpr_IdentEtc_ItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_IdentEtc_Item_End(FlingHdlGrammarParser::FlingExpr_IdentEtc_Item_EndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlingExpr_CallSubprog_PseudoOper(FlingHdlGrammarParser::FlingExpr_CallSubprog_PseudoOperContext *ctx) override {
    return visitChildren(ctx);
  }


};

