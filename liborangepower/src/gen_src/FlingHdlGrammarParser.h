
// Generated from FlingHdlGrammar.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  FlingHdlGrammarParser : public antlr4::Parser {
public:
  enum {
    LexWhitespace = 1, LexLineComment = 2, LitDecNum = 3, LitHexNum = 4, 
    LitOctNum = 5, LitBinNum = 6, LitFloatNum = 7, LitString = 8, PunctRangeSeparator = 9, 
    PunctNonBlkAssign = 10, PunctBlkAssign = 11, PunctLogOr = 12, PunctLogAnd = 13, 
    PunctCmpEq = 14, PunctCmpNe = 15, PunctCaseCmpEq = 16, PunctCaseCmpNe = 17, 
    PunctCmpLt = 18, PunctCmpGt = 19, PunctCmpLe = 20, PunctCmpGe = 21, 
    PunctPlus = 22, PunctMinus = 23, PunctMul = 24, PunctDiv = 25, PunctMod = 26, 
    PunctBitOr = 27, PunctBitNor = 28, PunctBitAnd = 29, PunctBitNand = 30, 
    PunctBitXor = 31, PunctBitXnor = 32, KwLsl = 33, KwLsr = 34, KwAsr = 35, 
    PunctBitNot = 36, PunctLogNot = 37, PunctMapTo = 38, PunctMemberAccess = 39, 
    PunctScopeAccess = 40, PunctLParen = 41, PunctRParen = 42, PunctLBracket = 43, 
    PunctRBracket = 44, PunctLBrace = 45, PunctRBrace = 46, PunctSemicolon = 47, 
    PunctColon = 48, PunctComma = 49, KwIf = 50, KwElif = 51, KwElse = 52, 
    KwMux = 53, KwSwitch = 54, KwSwitchz = 55, KwDefault = 56, KwFor = 57, 
    KwWhile = 58, KwBreak = 59, KwContinue = 60, KwModule = 61, KwPackage = 62, 
    KwInput = 63, KwOutput = 64, KwInout = 65, KwInterface = 66, KwGen = 67, 
    KwInitial = 68, KwComb = 69, KwSeq = 70, KwPosedge = 71, KwNegedge = 72, 
    KwFunc = 73, KwTask = 74, KwImport = 75, KwAll = 76, KwWire = 77, KwLogic = 78, 
    KwConst = 79, KwSigned = 80, KwInteger = 81, KwSizeT = 82, KwU8 = 83, 
    KwI8 = 84, KwU16 = 85, KwI16 = 86, KwU32 = 87, KwI32 = 88, KwU64 = 89, 
    KwI64 = 90, KwU128 = 91, KwI128 = 92, KwReturn = 93, KwRetT = 94, KwAuto = 95, 
    KwRange = 96, KwHighZ = 97, KwUnkX = 98, KwSized = 99, KwCat = 100, 
    KwRepl = 101, KwAs = 102, KwDollarSize = 103, KwDollarRange = 104, KwDollarHigh = 105, 
    KwDollarLow = 106, KwDollarFirstel = 107, KwDollarLastel = 108, KwDollarSigned = 109, 
    KwDollarUnsigned = 110, KwDollarPow = 111, KwDollarClog2 = 112, KwAssert = 113, 
    KwAssume = 114, KwCover = 115, KwVoid = 116, KwType = 117, KwTypeof = 118, 
    KwAlias = 119, KwEnum = 120, KwClass = 121, KwPacked = 122, KwMixin = 123, 
    KwExtends = 124, KwVirtual = 125, KwAbstract = 126, KwIsvtype = 127, 
    KwBase = 128, KwStatic = 129, KwProc = 130, KwSelf = 131, KwSelfT = 132, 
    KwPub = 133, KwProt = 134, KwPriv = 135, KwString = 136, KwFloat = 137, 
    MiscReservedIdent = 138, MiscIdent = 139, MiscOther = 140
  };

  enum {
    RuleFlingProgram = 0, RuleFlingProgram_Item = 1, RuleFlingDeclPackage = 2, 
    RuleFlingDeclPackage_Item = 3, RuleFlingDeclParamList = 4, RuleFlingDeclParamList_Item = 5, 
    RuleFlingDeclArgList = 6, RuleFlingDeclArgList_Item = 7, RuleFlingInstParamList = 8, 
    RuleFlingInstParamList_Pos = 9, RuleFlingInstParamList_Pos_Item = 10, 
    RuleFlingInstParamList_Named = 11, RuleFlingInstParamList_Named_Item = 12, 
    RuleFlingInstArgList = 13, RuleFlingInstArgList_Pos = 14, RuleFlingInstArgList_Named = 15, 
    RuleFlingInstArgList_Named_Item = 16, RuleFlingDeclModule = 17, RuleFlingDeclModule_Scope = 18, 
    RuleFlingDeclModule_Item = 19, RuleFlingInstModule = 20, RuleFlingGen = 21, 
    RuleFlingGen_If = 22, RuleFlingGen_If_Elif = 23, RuleFlingGen_If_Else = 24, 
    RuleFlingGen_Switch = 25, RuleFlingGen_Switch_Default = 26, RuleFlingGen_Switch_Case = 27, 
    RuleFlingGen_For = 28, RuleFlingContAssign = 29, RuleFlingBehav = 30, 
    RuleFlingBehav_Seq_EdgeList = 31, RuleFlingBehav_Seq_EdgeList_Item = 32, 
    RuleFlingBehav_Scope = 33, RuleFlingBehav_Item = 34, RuleFlingBehav_Item_If = 35, 
    RuleFlingBehav_Item_If_Elif = 36, RuleFlingBehav_Item_If_Else = 37, 
    RuleFlingBehav_Item_SwitchOrSwitchz = 38, RuleFlingBehav_Item_SwitchOrSwitchz_Default = 39, 
    RuleFlingBehav_Item_SwitchOrSwitchz_Case = 40, RuleFlingBehav_Item_For = 41, 
    RuleFlingBehav_Item_While = 42, RuleFlingBehav_Item_NonBlkAssign = 43, 
    RuleFlingBehav_Item_BlkAssign = 44, RuleFlingDeclWire = 45, RuleFlingDeclVar = 46, 
    RuleFlingDeclConst = 47, RuleFlingDeclType = 48, RuleFlingDeclEnum = 49, 
    RuleFlingDeclClass = 50, RuleFlingDeclClsOrMxn_Extends = 51, RuleFlingDeclClass_Item = 52, 
    RuleFlingDeclClass_Item_DeclVar = 53, RuleFlingDeclClsOrMxn_Item = 54, 
    RuleFlingDeclClsOrMxn_Item_DeclType = 55, RuleFlingDeclClsOrMxn_Item_DeclAliasOrConst = 56, 
    RuleFlingDeclClsOrMxn_AccessSpecifier = 57, RuleFlingDeclClsOrMxn_Item_DeclSubprog = 58, 
    RuleFlingDeclClsOrMxn_Item_DeclSubprog_FullDefn = 59, RuleFlingDeclClsOrMxn_Item_DeclSubprog_Abstract = 60, 
    RuleFlingDeclMixin = 61, RuleFlingDeclSubprog = 62, RuleFlingDeclFunc = 63, 
    RuleFlingDeclFunc_Header = 64, RuleFlingDeclFunc_Scope = 65, RuleFlingDeclFunc_Item = 66, 
    RuleFlingDeclFunc_Item_If = 67, RuleFlingDeclFunc_Item_If_Elif = 68, 
    RuleFlingDeclFunc_Item_If_Else = 69, RuleFlingDeclFunc_Item_SwitchOrSwitchz = 70, 
    RuleFlingDeclFunc_Item_SwitchOrSwitchz_Default = 71, RuleFlingDeclFunc_Item_SwitchOrSwitchz_Case = 72, 
    RuleFlingDeclFunc_Item_For = 73, RuleFlingDeclFunc_Item_While = 74, 
    RuleFlingDeclTask = 75, RuleFlingDeclTask_Header = 76, RuleFlingDeclTask_Scope = 77, 
    RuleFlingDeclTask_Item = 78, RuleFlingDeclTask_Item_If = 79, RuleFlingDeclTask_Item_If_Elif = 80, 
    RuleFlingDeclTask_Item_If_Else = 81, RuleFlingDeclTask_Item_SwitchOrSwitchz = 82, 
    RuleFlingDeclTask_Item_SwitchOrSwitchz_Default = 83, RuleFlingDeclTask_Item_SwitchOrSwitchz_Case = 84, 
    RuleFlingDeclTask_Item_For = 85, RuleFlingDeclTask_Item_While = 86, 
    RuleFlingDeclProc = 87, RuleFlingDeclProc_Header = 88, RuleFlingDeclProc_ArgList = 89, 
    RuleFlingDeclProc_ArgList_Item = 90, RuleFlingDeclAlias = 91, RuleFlingDeclAlias_Value = 92, 
    RuleFlingDeclAlias_Type = 93, RuleFlingDeclAlias_Module = 94, RuleFlingIdent = 95, 
    RuleFlingIdentList = 96, RuleFlingScopedIdent = 97, RuleFlingExprList = 98, 
    RuleFlingTypenameOrModnameList = 99, RuleFlingImportList = 100, RuleFlingTypenameOrModname = 101, 
    RuleFlingTypenameOrModname_Cstm = 102, RuleFlingTypenameOrModname_Cstm_Item = 103, 
    RuleFlingTypenameOrModname_ArrDim = 104, RuleFlingTypenameOrModname_Builtin = 105, 
    RuleFlingExpr = 106, RuleFlingExpr_Mux = 107, RuleFlingExpr_LogOr = 108, 
    RuleFlingExpr_LogAnd = 109, RuleFlingExpr_BitOr_Or_BitNor = 110, RuleFlingExpr_BitAnd_Or_BitNand = 111, 
    RuleFlingExpr_BitXor_Or_BitXnor = 112, RuleFlingExpr_CmpEqEtc = 113, 
    RuleFlingExpr_CmpLtEtc = 114, RuleFlingExpr_BitShift = 115, RuleFlingExpr_BinaryPlus_Or_BinaryMinus = 116, 
    RuleFlingExpr_Mul_Or_Div_Or_Mod = 117, RuleFlingExpr_Unary = 118, RuleFlingExpr_Unary_ItemFromMajority = 119, 
    RuleFlingExpr_Literal = 120, RuleFlingExpr_Sized = 121, RuleFlingExpr_Range = 122, 
    RuleFlingExpr_Range_DotDot = 123, RuleFlingExpr_Range_CallFunc = 124, 
    RuleFlingExpr_Cat = 125, RuleFlingExpr_Repl = 126, RuleFlingExpr_KwDollarFuncOf = 127, 
    RuleFlingExpr_KwDollarFuncOf_NonPow = 128, RuleFlingExpr_KwDollarFuncOf_Pow = 129, 
    RuleFlingExpr_IdentEtc = 130, RuleFlingExpr_IdentEtc_Item = 131, RuleFlingExpr_IdentEtc_Item_End = 132, 
    RuleFlingExpr_CallSubprog_PseudoOper = 133
  };

  FlingHdlGrammarParser(antlr4::TokenStream *input);
  ~FlingHdlGrammarParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FlingProgramContext;
  class FlingProgram_ItemContext;
  class FlingDeclPackageContext;
  class FlingDeclPackage_ItemContext;
  class FlingDeclParamListContext;
  class FlingDeclParamList_ItemContext;
  class FlingDeclArgListContext;
  class FlingDeclArgList_ItemContext;
  class FlingInstParamListContext;
  class FlingInstParamList_PosContext;
  class FlingInstParamList_Pos_ItemContext;
  class FlingInstParamList_NamedContext;
  class FlingInstParamList_Named_ItemContext;
  class FlingInstArgListContext;
  class FlingInstArgList_PosContext;
  class FlingInstArgList_NamedContext;
  class FlingInstArgList_Named_ItemContext;
  class FlingDeclModuleContext;
  class FlingDeclModule_ScopeContext;
  class FlingDeclModule_ItemContext;
  class FlingInstModuleContext;
  class FlingGenContext;
  class FlingGen_IfContext;
  class FlingGen_If_ElifContext;
  class FlingGen_If_ElseContext;
  class FlingGen_SwitchContext;
  class FlingGen_Switch_DefaultContext;
  class FlingGen_Switch_CaseContext;
  class FlingGen_ForContext;
  class FlingContAssignContext;
  class FlingBehavContext;
  class FlingBehav_Seq_EdgeListContext;
  class FlingBehav_Seq_EdgeList_ItemContext;
  class FlingBehav_ScopeContext;
  class FlingBehav_ItemContext;
  class FlingBehav_Item_IfContext;
  class FlingBehav_Item_If_ElifContext;
  class FlingBehav_Item_If_ElseContext;
  class FlingBehav_Item_SwitchOrSwitchzContext;
  class FlingBehav_Item_SwitchOrSwitchz_DefaultContext;
  class FlingBehav_Item_SwitchOrSwitchz_CaseContext;
  class FlingBehav_Item_ForContext;
  class FlingBehav_Item_WhileContext;
  class FlingBehav_Item_NonBlkAssignContext;
  class FlingBehav_Item_BlkAssignContext;
  class FlingDeclWireContext;
  class FlingDeclVarContext;
  class FlingDeclConstContext;
  class FlingDeclTypeContext;
  class FlingDeclEnumContext;
  class FlingDeclClassContext;
  class FlingDeclClsOrMxn_ExtendsContext;
  class FlingDeclClass_ItemContext;
  class FlingDeclClass_Item_DeclVarContext;
  class FlingDeclClsOrMxn_ItemContext;
  class FlingDeclClsOrMxn_Item_DeclTypeContext;
  class FlingDeclClsOrMxn_Item_DeclAliasOrConstContext;
  class FlingDeclClsOrMxn_AccessSpecifierContext;
  class FlingDeclClsOrMxn_Item_DeclSubprogContext;
  class FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext;
  class FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext;
  class FlingDeclMixinContext;
  class FlingDeclSubprogContext;
  class FlingDeclFuncContext;
  class FlingDeclFunc_HeaderContext;
  class FlingDeclFunc_ScopeContext;
  class FlingDeclFunc_ItemContext;
  class FlingDeclFunc_Item_IfContext;
  class FlingDeclFunc_Item_If_ElifContext;
  class FlingDeclFunc_Item_If_ElseContext;
  class FlingDeclFunc_Item_SwitchOrSwitchzContext;
  class FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext;
  class FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext;
  class FlingDeclFunc_Item_ForContext;
  class FlingDeclFunc_Item_WhileContext;
  class FlingDeclTaskContext;
  class FlingDeclTask_HeaderContext;
  class FlingDeclTask_ScopeContext;
  class FlingDeclTask_ItemContext;
  class FlingDeclTask_Item_IfContext;
  class FlingDeclTask_Item_If_ElifContext;
  class FlingDeclTask_Item_If_ElseContext;
  class FlingDeclTask_Item_SwitchOrSwitchzContext;
  class FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext;
  class FlingDeclTask_Item_SwitchOrSwitchz_CaseContext;
  class FlingDeclTask_Item_ForContext;
  class FlingDeclTask_Item_WhileContext;
  class FlingDeclProcContext;
  class FlingDeclProc_HeaderContext;
  class FlingDeclProc_ArgListContext;
  class FlingDeclProc_ArgList_ItemContext;
  class FlingDeclAliasContext;
  class FlingDeclAlias_ValueContext;
  class FlingDeclAlias_TypeContext;
  class FlingDeclAlias_ModuleContext;
  class FlingIdentContext;
  class FlingIdentListContext;
  class FlingScopedIdentContext;
  class FlingExprListContext;
  class FlingTypenameOrModnameListContext;
  class FlingImportListContext;
  class FlingTypenameOrModnameContext;
  class FlingTypenameOrModname_CstmContext;
  class FlingTypenameOrModname_Cstm_ItemContext;
  class FlingTypenameOrModname_ArrDimContext;
  class FlingTypenameOrModname_BuiltinContext;
  class FlingExprContext;
  class FlingExpr_MuxContext;
  class FlingExpr_LogOrContext;
  class FlingExpr_LogAndContext;
  class FlingExpr_BitOr_Or_BitNorContext;
  class FlingExpr_BitAnd_Or_BitNandContext;
  class FlingExpr_BitXor_Or_BitXnorContext;
  class FlingExpr_CmpEqEtcContext;
  class FlingExpr_CmpLtEtcContext;
  class FlingExpr_BitShiftContext;
  class FlingExpr_BinaryPlus_Or_BinaryMinusContext;
  class FlingExpr_Mul_Or_Div_Or_ModContext;
  class FlingExpr_UnaryContext;
  class FlingExpr_Unary_ItemFromMajorityContext;
  class FlingExpr_LiteralContext;
  class FlingExpr_SizedContext;
  class FlingExpr_RangeContext;
  class FlingExpr_Range_DotDotContext;
  class FlingExpr_Range_CallFuncContext;
  class FlingExpr_CatContext;
  class FlingExpr_ReplContext;
  class FlingExpr_KwDollarFuncOfContext;
  class FlingExpr_KwDollarFuncOf_NonPowContext;
  class FlingExpr_KwDollarFuncOf_PowContext;
  class FlingExpr_IdentEtcContext;
  class FlingExpr_IdentEtc_ItemContext;
  class FlingExpr_IdentEtc_Item_EndContext;
  class FlingExpr_CallSubprog_PseudoOperContext; 

  class  FlingProgramContext : public antlr4::ParserRuleContext {
  public:
    FlingProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<FlingProgram_ItemContext *> flingProgram_Item();
    FlingProgram_ItemContext* flingProgram_Item(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingProgramContext* flingProgram();

  class  FlingProgram_ItemContext : public antlr4::ParserRuleContext {
  public:
    FlingProgram_ItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingDeclPackageContext *flingDeclPackage();
    FlingDeclModuleContext *flingDeclModule();
    FlingDeclTypeContext *flingDeclType();
    FlingDeclSubprogContext *flingDeclSubprog();
    FlingDeclAliasContext *flingDeclAlias();
    FlingDeclConstContext *flingDeclConst();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingProgram_ItemContext* flingProgram_Item();

  class  FlingDeclPackageContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclPackageContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwPackage();
    FlingIdentContext *flingIdent();
    antlr4::tree::TerminalNode *PunctLBrace();
    antlr4::tree::TerminalNode *PunctRBrace();
    std::vector<FlingDeclPackage_ItemContext *> flingDeclPackage_Item();
    FlingDeclPackage_ItemContext* flingDeclPackage_Item(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclPackageContext* flingDeclPackage();

  class  FlingDeclPackage_ItemContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclPackage_ItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingDeclPackageContext *flingDeclPackage();
    FlingDeclModuleContext *flingDeclModule();
    FlingDeclTypeContext *flingDeclType();
    FlingDeclSubprogContext *flingDeclSubprog();
    FlingDeclAliasContext *flingDeclAlias();
    FlingDeclConstContext *flingDeclConst();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclPackage_ItemContext* flingDeclPackage_Item();

  class  FlingDeclParamListContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclParamListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PunctCmpLt();
    std::vector<FlingDeclParamList_ItemContext *> flingDeclParamList_Item();
    FlingDeclParamList_ItemContext* flingDeclParamList_Item(size_t i);
    antlr4::tree::TerminalNode *PunctCmpGt();
    std::vector<antlr4::tree::TerminalNode *> PunctSemicolon();
    antlr4::tree::TerminalNode* PunctSemicolon(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclParamListContext* flingDeclParamList();

  class  FlingDeclParamList_ItemContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclParamList_ItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingIdentListContext *flingIdentList();
    antlr4::tree::TerminalNode *PunctColon();
    FlingTypenameOrModnameContext *flingTypenameOrModname();
    antlr4::tree::TerminalNode *KwType();
    antlr4::tree::TerminalNode *KwModule();
    antlr4::tree::TerminalNode *PunctBlkAssign();
    FlingExprListContext *flingExprList();
    FlingTypenameOrModnameListContext *flingTypenameOrModnameList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclParamList_ItemContext* flingDeclParamList_Item();

  class  FlingDeclArgListContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclArgListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PunctLParen();
    antlr4::tree::TerminalNode *PunctRParen();
    std::vector<FlingDeclArgList_ItemContext *> flingDeclArgList_Item();
    FlingDeclArgList_ItemContext* flingDeclArgList_Item(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PunctSemicolon();
    antlr4::tree::TerminalNode* PunctSemicolon(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclArgListContext* flingDeclArgList();

  class  FlingDeclArgList_ItemContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclArgList_ItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingIdentListContext *flingIdentList();
    antlr4::tree::TerminalNode *PunctColon();
    FlingTypenameOrModnameContext *flingTypenameOrModname();
    antlr4::tree::TerminalNode *KwInput();
    antlr4::tree::TerminalNode *KwOutput();
    antlr4::tree::TerminalNode *KwInout();
    antlr4::tree::TerminalNode *KwInterface();
    antlr4::tree::TerminalNode *PunctBlkAssign();
    FlingExprListContext *flingExprList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclArgList_ItemContext* flingDeclArgList_Item();

  class  FlingInstParamListContext : public antlr4::ParserRuleContext {
  public:
    FlingInstParamListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PunctCmpLt();
    antlr4::tree::TerminalNode *PunctCmpGt();
    FlingInstParamList_PosContext *flingInstParamList_Pos();
    FlingInstParamList_NamedContext *flingInstParamList_Named();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingInstParamListContext* flingInstParamList();

  class  FlingInstParamList_PosContext : public antlr4::ParserRuleContext {
  public:
    FlingInstParamList_PosContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FlingInstParamList_Pos_ItemContext *> flingInstParamList_Pos_Item();
    FlingInstParamList_Pos_ItemContext* flingInstParamList_Pos_Item(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PunctComma();
    antlr4::tree::TerminalNode* PunctComma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingInstParamList_PosContext* flingInstParamList_Pos();

  class  FlingInstParamList_Pos_ItemContext : public antlr4::ParserRuleContext {
  public:
    FlingInstParamList_Pos_ItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExprContext *flingExpr();
    FlingTypenameOrModnameContext *flingTypenameOrModname();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingInstParamList_Pos_ItemContext* flingInstParamList_Pos_Item();

  class  FlingInstParamList_NamedContext : public antlr4::ParserRuleContext {
  public:
    FlingInstParamList_NamedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FlingInstParamList_Named_ItemContext *> flingInstParamList_Named_Item();
    FlingInstParamList_Named_ItemContext* flingInstParamList_Named_Item(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PunctComma();
    antlr4::tree::TerminalNode* PunctComma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingInstParamList_NamedContext* flingInstParamList_Named();

  class  FlingInstParamList_Named_ItemContext : public antlr4::ParserRuleContext {
  public:
    FlingInstParamList_Named_ItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingIdentContext *flingIdent();
    antlr4::tree::TerminalNode *PunctMapTo();
    FlingInstParamList_Pos_ItemContext *flingInstParamList_Pos_Item();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingInstParamList_Named_ItemContext* flingInstParamList_Named_Item();

  class  FlingInstArgListContext : public antlr4::ParserRuleContext {
  public:
    FlingInstArgListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PunctLParen();
    antlr4::tree::TerminalNode *PunctRParen();
    FlingInstArgList_PosContext *flingInstArgList_Pos();
    FlingInstArgList_NamedContext *flingInstArgList_Named();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingInstArgListContext* flingInstArgList();

  class  FlingInstArgList_PosContext : public antlr4::ParserRuleContext {
  public:
    FlingInstArgList_PosContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExprListContext *flingExprList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingInstArgList_PosContext* flingInstArgList_Pos();

  class  FlingInstArgList_NamedContext : public antlr4::ParserRuleContext {
  public:
    FlingInstArgList_NamedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FlingInstArgList_Named_ItemContext *> flingInstArgList_Named_Item();
    FlingInstArgList_Named_ItemContext* flingInstArgList_Named_Item(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PunctComma();
    antlr4::tree::TerminalNode* PunctComma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingInstArgList_NamedContext* flingInstArgList_Named();

  class  FlingInstArgList_Named_ItemContext : public antlr4::ParserRuleContext {
  public:
    FlingInstArgList_Named_ItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingIdentContext *flingIdent();
    antlr4::tree::TerminalNode *PunctMapTo();
    FlingExprContext *flingExpr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingInstArgList_Named_ItemContext* flingInstArgList_Named_Item();

  class  FlingDeclModuleContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclModuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwModule();
    FlingIdentContext *flingIdent();
    FlingDeclArgListContext *flingDeclArgList();
    FlingDeclModule_ScopeContext *flingDeclModule_Scope();
    FlingDeclParamListContext *flingDeclParamList();
    FlingImportListContext *flingImportList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclModuleContext* flingDeclModule();

  class  FlingDeclModule_ScopeContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclModule_ScopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PunctLBrace();
    antlr4::tree::TerminalNode *PunctRBrace();
    std::vector<FlingDeclModule_ItemContext *> flingDeclModule_Item();
    FlingDeclModule_ItemContext* flingDeclModule_Item(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclModule_ScopeContext* flingDeclModule_Scope();

  class  FlingDeclModule_ItemContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclModule_ItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingInstModuleContext *flingInstModule();
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *PunctSemicolon();
    FlingGenContext *flingGen();
    FlingContAssignContext *flingContAssign();
    FlingImportListContext *flingImportList();
    FlingBehavContext *flingBehav();
    FlingDeclWireContext *flingDeclWire();
    FlingDeclVarContext *flingDeclVar();
    FlingDeclConstContext *flingDeclConst();
    FlingDeclTypeContext *flingDeclType();
    FlingDeclSubprogContext *flingDeclSubprog();
    FlingDeclAliasContext *flingDeclAlias();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclModule_ItemContext* flingDeclModule_Item();

  class  FlingInstModuleContext : public antlr4::ParserRuleContext {
  public:
    FlingInstModuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingIdentContext *flingIdent();
    antlr4::tree::TerminalNode *PunctColon();
    antlr4::tree::TerminalNode *KwModule();
    FlingTypenameOrModnameContext *flingTypenameOrModname();
    FlingInstArgListContext *flingInstArgList();
    antlr4::tree::TerminalNode *PunctSemicolon();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingInstModuleContext* flingInstModule();

  class  FlingGenContext : public antlr4::ParserRuleContext {
  public:
    FlingGenContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingGen_IfContext *flingGen_If();
    FlingGen_SwitchContext *flingGen_Switch();
    FlingGen_ForContext *flingGen_For();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingGenContext* flingGen();

  class  FlingGen_IfContext : public antlr4::ParserRuleContext {
  public:
    FlingGen_IfContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwGen();
    antlr4::tree::TerminalNode *KwIf();
    FlingExprContext *flingExpr();
    FlingDeclModule_ScopeContext *flingDeclModule_Scope();
    std::vector<FlingGen_If_ElifContext *> flingGen_If_Elif();
    FlingGen_If_ElifContext* flingGen_If_Elif(size_t i);
    FlingGen_If_ElseContext *flingGen_If_Else();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingGen_IfContext* flingGen_If();

  class  FlingGen_If_ElifContext : public antlr4::ParserRuleContext {
  public:
    FlingGen_If_ElifContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwGen();
    antlr4::tree::TerminalNode *KwElif();
    FlingExprContext *flingExpr();
    FlingDeclModule_ScopeContext *flingDeclModule_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingGen_If_ElifContext* flingGen_If_Elif();

  class  FlingGen_If_ElseContext : public antlr4::ParserRuleContext {
  public:
    FlingGen_If_ElseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwGen();
    antlr4::tree::TerminalNode *KwElse();
    FlingDeclModule_ScopeContext *flingDeclModule_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingGen_If_ElseContext* flingGen_If_Else();

  class  FlingGen_SwitchContext : public antlr4::ParserRuleContext {
  public:
    FlingGen_SwitchContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwGen();
    antlr4::tree::TerminalNode *KwSwitch();
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *PunctLBrace();
    antlr4::tree::TerminalNode *PunctRBrace();
    FlingGen_Switch_DefaultContext *flingGen_Switch_Default();
    std::vector<FlingGen_Switch_CaseContext *> flingGen_Switch_Case();
    FlingGen_Switch_CaseContext* flingGen_Switch_Case(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingGen_SwitchContext* flingGen_Switch();

  class  FlingGen_Switch_DefaultContext : public antlr4::ParserRuleContext {
  public:
    FlingGen_Switch_DefaultContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwDefault();
    FlingDeclModule_ScopeContext *flingDeclModule_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingGen_Switch_DefaultContext* flingGen_Switch_Default();

  class  FlingGen_Switch_CaseContext : public antlr4::ParserRuleContext {
  public:
    FlingGen_Switch_CaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExprListContext *flingExprList();
    FlingDeclModule_ScopeContext *flingDeclModule_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingGen_Switch_CaseContext* flingGen_Switch_Case();

  class  FlingGen_ForContext : public antlr4::ParserRuleContext {
  public:
    FlingGen_ForContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwGen();
    antlr4::tree::TerminalNode *PunctLBracket();
    std::vector<FlingIdentContext *> flingIdent();
    FlingIdentContext* flingIdent(size_t i);
    antlr4::tree::TerminalNode *PunctRBracket();
    antlr4::tree::TerminalNode *KwFor();
    antlr4::tree::TerminalNode *PunctColon();
    FlingExprContext *flingExpr();
    FlingDeclModule_ScopeContext *flingDeclModule_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingGen_ForContext* flingGen_For();

  class  FlingContAssignContext : public antlr4::ParserRuleContext {
  public:
    FlingContAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FlingExprContext *> flingExpr();
    FlingExprContext* flingExpr(size_t i);
    antlr4::tree::TerminalNode *PunctNonBlkAssign();
    antlr4::tree::TerminalNode *PunctSemicolon();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingContAssignContext* flingContAssign();

  class  FlingBehavContext : public antlr4::ParserRuleContext {
  public:
    FlingBehavContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingBehav_ScopeContext *flingBehav_Scope();
    antlr4::tree::TerminalNode *KwInitial();
    antlr4::tree::TerminalNode *KwComb();
    antlr4::tree::TerminalNode *KwSeq();
    FlingBehav_Seq_EdgeListContext *flingBehav_Seq_EdgeList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingBehavContext* flingBehav();

  class  FlingBehav_Seq_EdgeListContext : public antlr4::ParserRuleContext {
  public:
    FlingBehav_Seq_EdgeListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FlingBehav_Seq_EdgeList_ItemContext *> flingBehav_Seq_EdgeList_Item();
    FlingBehav_Seq_EdgeList_ItemContext* flingBehav_Seq_EdgeList_Item(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PunctComma();
    antlr4::tree::TerminalNode* PunctComma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingBehav_Seq_EdgeListContext* flingBehav_Seq_EdgeList();

  class  FlingBehav_Seq_EdgeList_ItemContext : public antlr4::ParserRuleContext {
  public:
    FlingBehav_Seq_EdgeList_ItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *KwPosedge();
    antlr4::tree::TerminalNode *KwNegedge();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingBehav_Seq_EdgeList_ItemContext* flingBehav_Seq_EdgeList_Item();

  class  FlingBehav_ScopeContext : public antlr4::ParserRuleContext {
  public:
    FlingBehav_ScopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PunctLBrace();
    antlr4::tree::TerminalNode *PunctRBrace();
    std::vector<FlingBehav_ItemContext *> flingBehav_Item();
    FlingBehav_ItemContext* flingBehav_Item(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingBehav_ScopeContext* flingBehav_Scope();

  class  FlingBehav_ItemContext : public antlr4::ParserRuleContext {
  public:
    FlingBehav_ItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingBehav_ScopeContext *flingBehav_Scope();
    FlingDeclAliasContext *flingDeclAlias();
    FlingDeclVarContext *flingDeclVar();
    FlingDeclConstContext *flingDeclConst();
    FlingDeclTypeContext *flingDeclType();
    FlingBehav_Item_BlkAssignContext *flingBehav_Item_BlkAssign();
    FlingBehav_Item_NonBlkAssignContext *flingBehav_Item_NonBlkAssign();
    FlingBehav_Item_IfContext *flingBehav_Item_If();
    FlingBehav_Item_SwitchOrSwitchzContext *flingBehav_Item_SwitchOrSwitchz();
    FlingBehav_Item_ForContext *flingBehav_Item_For();
    FlingBehav_Item_WhileContext *flingBehav_Item_While();
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *PunctSemicolon();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingBehav_ItemContext* flingBehav_Item();

  class  FlingBehav_Item_IfContext : public antlr4::ParserRuleContext {
  public:
    FlingBehav_Item_IfContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwIf();
    FlingExprContext *flingExpr();
    FlingBehav_ScopeContext *flingBehav_Scope();
    std::vector<FlingBehav_Item_If_ElifContext *> flingBehav_Item_If_Elif();
    FlingBehav_Item_If_ElifContext* flingBehav_Item_If_Elif(size_t i);
    FlingBehav_Item_If_ElseContext *flingBehav_Item_If_Else();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingBehav_Item_IfContext* flingBehav_Item_If();

  class  FlingBehav_Item_If_ElifContext : public antlr4::ParserRuleContext {
  public:
    FlingBehav_Item_If_ElifContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwElif();
    FlingExprContext *flingExpr();
    FlingBehav_ScopeContext *flingBehav_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingBehav_Item_If_ElifContext* flingBehav_Item_If_Elif();

  class  FlingBehav_Item_If_ElseContext : public antlr4::ParserRuleContext {
  public:
    FlingBehav_Item_If_ElseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwElse();
    FlingBehav_ScopeContext *flingBehav_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingBehav_Item_If_ElseContext* flingBehav_Item_If_Else();

  class  FlingBehav_Item_SwitchOrSwitchzContext : public antlr4::ParserRuleContext {
  public:
    FlingBehav_Item_SwitchOrSwitchzContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *PunctLBrace();
    antlr4::tree::TerminalNode *PunctRBrace();
    antlr4::tree::TerminalNode *KwSwitch();
    antlr4::tree::TerminalNode *KwSwitchz();
    FlingBehav_Item_SwitchOrSwitchz_DefaultContext *flingBehav_Item_SwitchOrSwitchz_Default();
    std::vector<FlingBehav_Item_SwitchOrSwitchz_CaseContext *> flingBehav_Item_SwitchOrSwitchz_Case();
    FlingBehav_Item_SwitchOrSwitchz_CaseContext* flingBehav_Item_SwitchOrSwitchz_Case(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingBehav_Item_SwitchOrSwitchzContext* flingBehav_Item_SwitchOrSwitchz();

  class  FlingBehav_Item_SwitchOrSwitchz_DefaultContext : public antlr4::ParserRuleContext {
  public:
    FlingBehav_Item_SwitchOrSwitchz_DefaultContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwDefault();
    FlingBehav_ScopeContext *flingBehav_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingBehav_Item_SwitchOrSwitchz_DefaultContext* flingBehav_Item_SwitchOrSwitchz_Default();

  class  FlingBehav_Item_SwitchOrSwitchz_CaseContext : public antlr4::ParserRuleContext {
  public:
    FlingBehav_Item_SwitchOrSwitchz_CaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExprListContext *flingExprList();
    FlingBehav_ScopeContext *flingBehav_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingBehav_Item_SwitchOrSwitchz_CaseContext* flingBehav_Item_SwitchOrSwitchz_Case();

  class  FlingBehav_Item_ForContext : public antlr4::ParserRuleContext {
  public:
    FlingBehav_Item_ForContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwFor();
    FlingIdentContext *flingIdent();
    antlr4::tree::TerminalNode *PunctColon();
    FlingExprContext *flingExpr();
    FlingBehav_ScopeContext *flingBehav_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingBehav_Item_ForContext* flingBehav_Item_For();

  class  FlingBehav_Item_WhileContext : public antlr4::ParserRuleContext {
  public:
    FlingBehav_Item_WhileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwWhile();
    FlingExprContext *flingExpr();
    FlingBehav_ScopeContext *flingBehav_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingBehav_Item_WhileContext* flingBehav_Item_While();

  class  FlingBehav_Item_NonBlkAssignContext : public antlr4::ParserRuleContext {
  public:
    FlingBehav_Item_NonBlkAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FlingExprContext *> flingExpr();
    FlingExprContext* flingExpr(size_t i);
    antlr4::tree::TerminalNode *PunctNonBlkAssign();
    antlr4::tree::TerminalNode *PunctSemicolon();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingBehav_Item_NonBlkAssignContext* flingBehav_Item_NonBlkAssign();

  class  FlingBehav_Item_BlkAssignContext : public antlr4::ParserRuleContext {
  public:
    FlingBehav_Item_BlkAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FlingExprContext *> flingExpr();
    FlingExprContext* flingExpr(size_t i);
    antlr4::tree::TerminalNode *PunctBlkAssign();
    antlr4::tree::TerminalNode *PunctSemicolon();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingBehav_Item_BlkAssignContext* flingBehav_Item_BlkAssign();

  class  FlingDeclWireContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclWireContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingIdentListContext *flingIdentList();
    antlr4::tree::TerminalNode *PunctColon();
    antlr4::tree::TerminalNode *KwWire();
    FlingTypenameOrModnameContext *flingTypenameOrModname();
    antlr4::tree::TerminalNode *PunctSemicolon();
    antlr4::tree::TerminalNode *PunctBlkAssign();
    FlingExprListContext *flingExprList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclWireContext* flingDeclWire();

  class  FlingDeclVarContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclVarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingIdentListContext *flingIdentList();
    antlr4::tree::TerminalNode *PunctColon();
    FlingTypenameOrModnameContext *flingTypenameOrModname();
    antlr4::tree::TerminalNode *PunctSemicolon();
    antlr4::tree::TerminalNode *PunctBlkAssign();
    FlingExprListContext *flingExprList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclVarContext* flingDeclVar();

  class  FlingDeclConstContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingIdentListContext *flingIdentList();
    antlr4::tree::TerminalNode *PunctColon();
    antlr4::tree::TerminalNode *KwConst();
    FlingTypenameOrModnameContext *flingTypenameOrModname();
    antlr4::tree::TerminalNode *PunctBlkAssign();
    FlingExprListContext *flingExprList();
    antlr4::tree::TerminalNode *PunctSemicolon();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclConstContext* flingDeclConst();

  class  FlingDeclTypeContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingDeclEnumContext *flingDeclEnum();
    FlingDeclClassContext *flingDeclClass();
    FlingDeclMixinContext *flingDeclMixin();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclTypeContext* flingDeclType();

  class  FlingDeclEnumContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclEnumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwEnum();
    FlingIdentContext *flingIdent();
    antlr4::tree::TerminalNode *PunctLBrace();
    FlingIdentListContext *flingIdentList();
    antlr4::tree::TerminalNode *PunctRBrace();
    antlr4::tree::TerminalNode *PunctColon();
    FlingTypenameOrModnameContext *flingTypenameOrModname();
    antlr4::tree::TerminalNode *PunctComma();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclEnumContext* flingDeclEnum();

  class  FlingDeclClassContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclClassContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwClass();
    FlingIdentContext *flingIdent();
    FlingDeclParamListContext *flingDeclParamList();
    antlr4::tree::TerminalNode *PunctLBrace();
    antlr4::tree::TerminalNode *PunctRBrace();
    antlr4::tree::TerminalNode *KwBase();
    antlr4::tree::TerminalNode *KwPacked();
    FlingDeclClsOrMxn_ExtendsContext *flingDeclClsOrMxn_Extends();
    std::vector<FlingDeclClass_ItemContext *> flingDeclClass_Item();
    FlingDeclClass_ItemContext* flingDeclClass_Item(size_t i);
    antlr4::tree::TerminalNode *KwSigned();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclClassContext* flingDeclClass();

  class  FlingDeclClsOrMxn_ExtendsContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclClsOrMxn_ExtendsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwExtends();
    FlingTypenameOrModnameListContext *flingTypenameOrModnameList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclClsOrMxn_ExtendsContext* flingDeclClsOrMxn_Extends();

  class  FlingDeclClass_ItemContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclClass_ItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingDeclClass_Item_DeclVarContext *flingDeclClass_Item_DeclVar();
    FlingDeclClsOrMxn_ItemContext *flingDeclClsOrMxn_Item();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclClass_ItemContext* flingDeclClass_Item();

  class  FlingDeclClass_Item_DeclVarContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclClass_Item_DeclVarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingDeclVarContext *flingDeclVar();
    FlingDeclClsOrMxn_AccessSpecifierContext *flingDeclClsOrMxn_AccessSpecifier();
    antlr4::tree::TerminalNode *KwStatic();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclClass_Item_DeclVarContext* flingDeclClass_Item_DeclVar();

  class  FlingDeclClsOrMxn_ItemContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclClsOrMxn_ItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingDeclClsOrMxn_Item_DeclTypeContext *flingDeclClsOrMxn_Item_DeclType();
    FlingDeclClsOrMxn_Item_DeclAliasOrConstContext *flingDeclClsOrMxn_Item_DeclAliasOrConst();
    FlingDeclClsOrMxn_Item_DeclSubprogContext *flingDeclClsOrMxn_Item_DeclSubprog();
    FlingImportListContext *flingImportList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclClsOrMxn_ItemContext* flingDeclClsOrMxn_Item();

  class  FlingDeclClsOrMxn_Item_DeclTypeContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclClsOrMxn_Item_DeclTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingDeclTypeContext *flingDeclType();
    FlingDeclClsOrMxn_AccessSpecifierContext *flingDeclClsOrMxn_AccessSpecifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclClsOrMxn_Item_DeclTypeContext* flingDeclClsOrMxn_Item_DeclType();

  class  FlingDeclClsOrMxn_Item_DeclAliasOrConstContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclClsOrMxn_Item_DeclAliasOrConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingDeclAliasContext *flingDeclAlias();
    FlingDeclConstContext *flingDeclConst();
    FlingDeclClsOrMxn_AccessSpecifierContext *flingDeclClsOrMxn_AccessSpecifier();
    antlr4::tree::TerminalNode *KwStatic();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclClsOrMxn_Item_DeclAliasOrConstContext* flingDeclClsOrMxn_Item_DeclAliasOrConst();

  class  FlingDeclClsOrMxn_AccessSpecifierContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclClsOrMxn_AccessSpecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwPub();
    antlr4::tree::TerminalNode *KwProt();
    antlr4::tree::TerminalNode *KwPriv();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclClsOrMxn_AccessSpecifierContext* flingDeclClsOrMxn_AccessSpecifier();

  class  FlingDeclClsOrMxn_Item_DeclSubprogContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclClsOrMxn_Item_DeclSubprogContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext *flingDeclClsOrMxn_Item_DeclSubprog_FullDefn();
    FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext *flingDeclClsOrMxn_Item_DeclSubprog_Abstract();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclClsOrMxn_Item_DeclSubprogContext* flingDeclClsOrMxn_Item_DeclSubprog();

  class  FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingDeclSubprogContext *flingDeclSubprog();
    FlingDeclClsOrMxn_AccessSpecifierContext *flingDeclClsOrMxn_AccessSpecifier();
    antlr4::tree::TerminalNode *KwConst();
    antlr4::tree::TerminalNode *KwVirtual();
    antlr4::tree::TerminalNode *KwStatic();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext* flingDeclClsOrMxn_Item_DeclSubprog_FullDefn();

  class  FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwAbstract();
    antlr4::tree::TerminalNode *PunctSemicolon();
    FlingDeclFunc_HeaderContext *flingDeclFunc_Header();
    FlingDeclTask_HeaderContext *flingDeclTask_Header();
    FlingDeclProc_HeaderContext *flingDeclProc_Header();
    FlingDeclClsOrMxn_AccessSpecifierContext *flingDeclClsOrMxn_AccessSpecifier();
    antlr4::tree::TerminalNode *KwConst();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext* flingDeclClsOrMxn_Item_DeclSubprog_Abstract();

  class  FlingDeclMixinContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclMixinContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwMixin();
    FlingIdentContext *flingIdent();
    FlingDeclParamListContext *flingDeclParamList();
    antlr4::tree::TerminalNode *PunctLBrace();
    antlr4::tree::TerminalNode *PunctRBrace();
    antlr4::tree::TerminalNode *KwBase();
    FlingDeclClsOrMxn_ExtendsContext *flingDeclClsOrMxn_Extends();
    std::vector<FlingDeclClsOrMxn_ItemContext *> flingDeclClsOrMxn_Item();
    FlingDeclClsOrMxn_ItemContext* flingDeclClsOrMxn_Item(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclMixinContext* flingDeclMixin();

  class  FlingDeclSubprogContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclSubprogContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingDeclFuncContext *flingDeclFunc();
    FlingDeclTaskContext *flingDeclTask();
    FlingDeclProcContext *flingDeclProc();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclSubprogContext* flingDeclSubprog();

  class  FlingDeclFuncContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclFuncContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingDeclFunc_HeaderContext *flingDeclFunc_Header();
    FlingDeclFunc_ScopeContext *flingDeclFunc_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclFuncContext* flingDeclFunc();

  class  FlingDeclFunc_HeaderContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclFunc_HeaderContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwFunc();
    FlingIdentContext *flingIdent();
    FlingDeclArgListContext *flingDeclArgList();
    antlr4::tree::TerminalNode *PunctColon();
    FlingTypenameOrModnameContext *flingTypenameOrModname();
    FlingDeclParamListContext *flingDeclParamList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclFunc_HeaderContext* flingDeclFunc_Header();

  class  FlingDeclFunc_ScopeContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclFunc_ScopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PunctLBrace();
    antlr4::tree::TerminalNode *PunctRBrace();
    std::vector<FlingDeclFunc_ItemContext *> flingDeclFunc_Item();
    FlingDeclFunc_ItemContext* flingDeclFunc_Item(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclFunc_ScopeContext* flingDeclFunc_Scope();

  class  FlingDeclFunc_ItemContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclFunc_ItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *PunctSemicolon();
    antlr4::tree::TerminalNode *KwReturn();
    FlingDeclFunc_ScopeContext *flingDeclFunc_Scope();
    FlingDeclAliasContext *flingDeclAlias();
    FlingDeclVarContext *flingDeclVar();
    FlingDeclConstContext *flingDeclConst();
    FlingDeclTypeContext *flingDeclType();
    FlingBehav_Item_BlkAssignContext *flingBehav_Item_BlkAssign();
    FlingDeclFunc_Item_IfContext *flingDeclFunc_Item_If();
    FlingDeclFunc_Item_SwitchOrSwitchzContext *flingDeclFunc_Item_SwitchOrSwitchz();
    FlingDeclFunc_Item_ForContext *flingDeclFunc_Item_For();
    FlingDeclFunc_Item_WhileContext *flingDeclFunc_Item_While();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclFunc_ItemContext* flingDeclFunc_Item();

  class  FlingDeclFunc_Item_IfContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclFunc_Item_IfContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwIf();
    FlingExprContext *flingExpr();
    FlingDeclFunc_ScopeContext *flingDeclFunc_Scope();
    std::vector<FlingDeclFunc_Item_If_ElifContext *> flingDeclFunc_Item_If_Elif();
    FlingDeclFunc_Item_If_ElifContext* flingDeclFunc_Item_If_Elif(size_t i);
    FlingDeclFunc_Item_If_ElseContext *flingDeclFunc_Item_If_Else();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclFunc_Item_IfContext* flingDeclFunc_Item_If();

  class  FlingDeclFunc_Item_If_ElifContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclFunc_Item_If_ElifContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwElif();
    FlingExprContext *flingExpr();
    FlingDeclFunc_ScopeContext *flingDeclFunc_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclFunc_Item_If_ElifContext* flingDeclFunc_Item_If_Elif();

  class  FlingDeclFunc_Item_If_ElseContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclFunc_Item_If_ElseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwElse();
    FlingDeclFunc_ScopeContext *flingDeclFunc_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclFunc_Item_If_ElseContext* flingDeclFunc_Item_If_Else();

  class  FlingDeclFunc_Item_SwitchOrSwitchzContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclFunc_Item_SwitchOrSwitchzContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *PunctLBrace();
    antlr4::tree::TerminalNode *PunctRBrace();
    antlr4::tree::TerminalNode *KwSwitch();
    antlr4::tree::TerminalNode *KwSwitchz();
    FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext *flingDeclFunc_Item_SwitchOrSwitchz_Default();
    std::vector<FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext *> flingDeclFunc_Item_SwitchOrSwitchz_Case();
    FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext* flingDeclFunc_Item_SwitchOrSwitchz_Case(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclFunc_Item_SwitchOrSwitchzContext* flingDeclFunc_Item_SwitchOrSwitchz();

  class  FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwDefault();
    FlingDeclFunc_ScopeContext *flingDeclFunc_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext* flingDeclFunc_Item_SwitchOrSwitchz_Default();

  class  FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExprListContext *flingExprList();
    FlingDeclFunc_ScopeContext *flingDeclFunc_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext* flingDeclFunc_Item_SwitchOrSwitchz_Case();

  class  FlingDeclFunc_Item_ForContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclFunc_Item_ForContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwFor();
    FlingIdentContext *flingIdent();
    antlr4::tree::TerminalNode *PunctColon();
    FlingExprContext *flingExpr();
    FlingDeclFunc_ScopeContext *flingDeclFunc_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclFunc_Item_ForContext* flingDeclFunc_Item_For();

  class  FlingDeclFunc_Item_WhileContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclFunc_Item_WhileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwWhile();
    FlingExprContext *flingExpr();
    FlingDeclFunc_ScopeContext *flingDeclFunc_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclFunc_Item_WhileContext* flingDeclFunc_Item_While();

  class  FlingDeclTaskContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclTaskContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingDeclTask_HeaderContext *flingDeclTask_Header();
    FlingDeclTask_ScopeContext *flingDeclTask_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclTaskContext* flingDeclTask();

  class  FlingDeclTask_HeaderContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclTask_HeaderContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwTask();
    FlingIdentContext *flingIdent();
    FlingDeclArgListContext *flingDeclArgList();
    FlingDeclParamListContext *flingDeclParamList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclTask_HeaderContext* flingDeclTask_Header();

  class  FlingDeclTask_ScopeContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclTask_ScopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PunctLBrace();
    antlr4::tree::TerminalNode *PunctRBrace();
    std::vector<FlingDeclTask_ItemContext *> flingDeclTask_Item();
    FlingDeclTask_ItemContext* flingDeclTask_Item(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclTask_ScopeContext* flingDeclTask_Scope();

  class  FlingDeclTask_ItemContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclTask_ItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingDeclTask_ScopeContext *flingDeclTask_Scope();
    FlingDeclAliasContext *flingDeclAlias();
    FlingDeclVarContext *flingDeclVar();
    FlingDeclConstContext *flingDeclConst();
    FlingDeclTypeContext *flingDeclType();
    FlingBehav_Item_BlkAssignContext *flingBehav_Item_BlkAssign();
    FlingBehav_Item_NonBlkAssignContext *flingBehav_Item_NonBlkAssign();
    FlingDeclTask_Item_IfContext *flingDeclTask_Item_If();
    FlingDeclTask_Item_SwitchOrSwitchzContext *flingDeclTask_Item_SwitchOrSwitchz();
    FlingDeclTask_Item_ForContext *flingDeclTask_Item_For();
    FlingDeclTask_Item_WhileContext *flingDeclTask_Item_While();
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *PunctSemicolon();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclTask_ItemContext* flingDeclTask_Item();

  class  FlingDeclTask_Item_IfContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclTask_Item_IfContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwIf();
    FlingExprContext *flingExpr();
    FlingDeclTask_ScopeContext *flingDeclTask_Scope();
    std::vector<FlingDeclTask_Item_If_ElifContext *> flingDeclTask_Item_If_Elif();
    FlingDeclTask_Item_If_ElifContext* flingDeclTask_Item_If_Elif(size_t i);
    FlingDeclTask_Item_If_ElseContext *flingDeclTask_Item_If_Else();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclTask_Item_IfContext* flingDeclTask_Item_If();

  class  FlingDeclTask_Item_If_ElifContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclTask_Item_If_ElifContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwElif();
    FlingExprContext *flingExpr();
    FlingDeclTask_ScopeContext *flingDeclTask_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclTask_Item_If_ElifContext* flingDeclTask_Item_If_Elif();

  class  FlingDeclTask_Item_If_ElseContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclTask_Item_If_ElseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwElse();
    FlingDeclTask_ScopeContext *flingDeclTask_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclTask_Item_If_ElseContext* flingDeclTask_Item_If_Else();

  class  FlingDeclTask_Item_SwitchOrSwitchzContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclTask_Item_SwitchOrSwitchzContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *PunctLBrace();
    antlr4::tree::TerminalNode *PunctRBrace();
    antlr4::tree::TerminalNode *KwSwitch();
    antlr4::tree::TerminalNode *KwSwitchz();
    FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext *flingDeclTask_Item_SwitchOrSwitchz_Default();
    std::vector<FlingDeclTask_Item_SwitchOrSwitchz_CaseContext *> flingDeclTask_Item_SwitchOrSwitchz_Case();
    FlingDeclTask_Item_SwitchOrSwitchz_CaseContext* flingDeclTask_Item_SwitchOrSwitchz_Case(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclTask_Item_SwitchOrSwitchzContext* flingDeclTask_Item_SwitchOrSwitchz();

  class  FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwDefault();
    FlingDeclTask_ScopeContext *flingDeclTask_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext* flingDeclTask_Item_SwitchOrSwitchz_Default();

  class  FlingDeclTask_Item_SwitchOrSwitchz_CaseContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclTask_Item_SwitchOrSwitchz_CaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExprListContext *flingExprList();
    FlingDeclTask_ScopeContext *flingDeclTask_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclTask_Item_SwitchOrSwitchz_CaseContext* flingDeclTask_Item_SwitchOrSwitchz_Case();

  class  FlingDeclTask_Item_ForContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclTask_Item_ForContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwFor();
    FlingIdentContext *flingIdent();
    antlr4::tree::TerminalNode *PunctColon();
    FlingExprContext *flingExpr();
    FlingDeclTask_ScopeContext *flingDeclTask_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclTask_Item_ForContext* flingDeclTask_Item_For();

  class  FlingDeclTask_Item_WhileContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclTask_Item_WhileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwWhile();
    FlingExprContext *flingExpr();
    FlingDeclTask_ScopeContext *flingDeclTask_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclTask_Item_WhileContext* flingDeclTask_Item_While();

  class  FlingDeclProcContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclProcContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingDeclProc_HeaderContext *flingDeclProc_Header();
    FlingDeclModule_ScopeContext *flingDeclModule_Scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclProcContext* flingDeclProc();

  class  FlingDeclProc_HeaderContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclProc_HeaderContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwProc();
    FlingIdentContext *flingIdent();
    FlingDeclProc_ArgListContext *flingDeclProc_ArgList();
    FlingDeclParamListContext *flingDeclParamList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclProc_HeaderContext* flingDeclProc_Header();

  class  FlingDeclProc_ArgListContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclProc_ArgListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PunctLParen();
    std::vector<FlingDeclProc_ArgList_ItemContext *> flingDeclProc_ArgList_Item();
    FlingDeclProc_ArgList_ItemContext* flingDeclProc_ArgList_Item(size_t i);
    antlr4::tree::TerminalNode *PunctRParen();
    std::vector<antlr4::tree::TerminalNode *> PunctSemicolon();
    antlr4::tree::TerminalNode* PunctSemicolon(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclProc_ArgListContext* flingDeclProc_ArgList();

  class  FlingDeclProc_ArgList_ItemContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclProc_ArgList_ItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingIdentListContext *flingIdentList();
    antlr4::tree::TerminalNode *PunctColon();
    FlingTypenameOrModnameContext *flingTypenameOrModname();
    antlr4::tree::TerminalNode *KwInput();
    antlr4::tree::TerminalNode *KwInout();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclProc_ArgList_ItemContext* flingDeclProc_ArgList_Item();

  class  FlingDeclAliasContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclAliasContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingDeclAlias_ValueContext *flingDeclAlias_Value();
    FlingDeclAlias_TypeContext *flingDeclAlias_Type();
    FlingDeclAlias_ModuleContext *flingDeclAlias_Module();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclAliasContext* flingDeclAlias();

  class  FlingDeclAlias_ValueContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclAlias_ValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwAlias();
    FlingIdentListContext *flingIdentList();
    antlr4::tree::TerminalNode *PunctColon();
    FlingTypenameOrModnameContext *flingTypenameOrModname();
    antlr4::tree::TerminalNode *PunctBlkAssign();
    FlingExprListContext *flingExprList();
    antlr4::tree::TerminalNode *PunctSemicolon();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclAlias_ValueContext* flingDeclAlias_Value();

  class  FlingDeclAlias_TypeContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclAlias_TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwAlias();
    FlingIdentListContext *flingIdentList();
    antlr4::tree::TerminalNode *PunctColon();
    antlr4::tree::TerminalNode *KwType();
    antlr4::tree::TerminalNode *PunctBlkAssign();
    FlingTypenameOrModnameListContext *flingTypenameOrModnameList();
    antlr4::tree::TerminalNode *PunctSemicolon();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclAlias_TypeContext* flingDeclAlias_Type();

  class  FlingDeclAlias_ModuleContext : public antlr4::ParserRuleContext {
  public:
    FlingDeclAlias_ModuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwAlias();
    FlingIdentListContext *flingIdentList();
    antlr4::tree::TerminalNode *PunctColon();
    antlr4::tree::TerminalNode *KwModule();
    antlr4::tree::TerminalNode *PunctBlkAssign();
    FlingTypenameOrModnameListContext *flingTypenameOrModnameList();
    antlr4::tree::TerminalNode *PunctSemicolon();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingDeclAlias_ModuleContext* flingDeclAlias_Module();

  class  FlingIdentContext : public antlr4::ParserRuleContext {
  public:
    FlingIdentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MiscIdent();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingIdentContext* flingIdent();

  class  FlingIdentListContext : public antlr4::ParserRuleContext {
  public:
    FlingIdentListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FlingIdentContext *> flingIdent();
    FlingIdentContext* flingIdent(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PunctComma();
    antlr4::tree::TerminalNode* PunctComma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingIdentListContext* flingIdentList();

  class  FlingScopedIdentContext : public antlr4::ParserRuleContext {
  public:
    FlingScopedIdentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FlingIdentContext *> flingIdent();
    FlingIdentContext* flingIdent(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PunctScopeAccess();
    antlr4::tree::TerminalNode* PunctScopeAccess(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingScopedIdentContext* flingScopedIdent();

  class  FlingExprListContext : public antlr4::ParserRuleContext {
  public:
    FlingExprListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FlingExprContext *> flingExpr();
    FlingExprContext* flingExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PunctComma();
    antlr4::tree::TerminalNode* PunctComma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExprListContext* flingExprList();

  class  FlingTypenameOrModnameListContext : public antlr4::ParserRuleContext {
  public:
    FlingTypenameOrModnameListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FlingTypenameOrModnameContext *> flingTypenameOrModname();
    FlingTypenameOrModnameContext* flingTypenameOrModname(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PunctComma();
    antlr4::tree::TerminalNode* PunctComma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingTypenameOrModnameListContext* flingTypenameOrModnameList();

  class  FlingImportListContext : public antlr4::ParserRuleContext {
  public:
    FlingImportListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwImport();
    std::vector<FlingScopedIdentContext *> flingScopedIdent();
    FlingScopedIdentContext* flingScopedIdent(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PunctComma();
    antlr4::tree::TerminalNode* PunctComma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingImportListContext* flingImportList();

  class  FlingTypenameOrModnameContext : public antlr4::ParserRuleContext {
  public:
    FlingTypenameOrModnameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingTypenameOrModname_CstmContext *flingTypenameOrModname_Cstm();
    antlr4::tree::TerminalNode *KwSelfT();
    antlr4::tree::TerminalNode *KwRetT();
    antlr4::tree::TerminalNode *KwTypeof();
    antlr4::tree::TerminalNode *PunctLParen();
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *PunctRParen();
    FlingTypenameOrModname_BuiltinContext *flingTypenameOrModname_Builtin();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingTypenameOrModnameContext* flingTypenameOrModname();

  class  FlingTypenameOrModname_CstmContext : public antlr4::ParserRuleContext {
  public:
    FlingTypenameOrModname_CstmContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FlingTypenameOrModname_Cstm_ItemContext *> flingTypenameOrModname_Cstm_Item();
    FlingTypenameOrModname_Cstm_ItemContext* flingTypenameOrModname_Cstm_Item(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PunctScopeAccess();
    antlr4::tree::TerminalNode* PunctScopeAccess(size_t i);
    std::vector<FlingTypenameOrModname_ArrDimContext *> flingTypenameOrModname_ArrDim();
    FlingTypenameOrModname_ArrDimContext* flingTypenameOrModname_ArrDim(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingTypenameOrModname_CstmContext* flingTypenameOrModname_Cstm();

  class  FlingTypenameOrModname_Cstm_ItemContext : public antlr4::ParserRuleContext {
  public:
    FlingTypenameOrModname_Cstm_ItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingIdentContext *flingIdent();
    FlingInstParamListContext *flingInstParamList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingTypenameOrModname_Cstm_ItemContext* flingTypenameOrModname_Cstm_Item();

  class  FlingTypenameOrModname_ArrDimContext : public antlr4::ParserRuleContext {
  public:
    FlingTypenameOrModname_ArrDimContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PunctLBracket();
    antlr4::tree::TerminalNode *PunctRBracket();
    FlingExprContext *flingExpr();
    FlingTypenameOrModnameContext *flingTypenameOrModname();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingTypenameOrModname_ArrDimContext* flingTypenameOrModname_ArrDim();

  class  FlingTypenameOrModname_BuiltinContext : public antlr4::ParserRuleContext {
  public:
    FlingTypenameOrModname_BuiltinContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwLogic();
    antlr4::tree::TerminalNode *KwInteger();
    antlr4::tree::TerminalNode *KwSizeT();
    antlr4::tree::TerminalNode *KwRange();
    antlr4::tree::TerminalNode *KwString();
    antlr4::tree::TerminalNode *KwU8();
    antlr4::tree::TerminalNode *KwI8();
    antlr4::tree::TerminalNode *KwU16();
    antlr4::tree::TerminalNode *KwI16();
    antlr4::tree::TerminalNode *KwU32();
    antlr4::tree::TerminalNode *KwI32();
    antlr4::tree::TerminalNode *KwU64();
    antlr4::tree::TerminalNode *KwI64();
    antlr4::tree::TerminalNode *KwU128();
    antlr4::tree::TerminalNode *KwI128();
    antlr4::tree::TerminalNode *KwAuto();
    std::vector<FlingTypenameOrModname_ArrDimContext *> flingTypenameOrModname_ArrDim();
    FlingTypenameOrModname_ArrDimContext* flingTypenameOrModname_ArrDim(size_t i);
    antlr4::tree::TerminalNode *KwSigned();
    FlingInstParamListContext *flingInstParamList();
    antlr4::tree::TerminalNode *KwVoid();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingTypenameOrModname_BuiltinContext* flingTypenameOrModname_Builtin();

  class  FlingExprContext : public antlr4::ParserRuleContext {
  public:
    FlingExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwMux();
    antlr4::tree::TerminalNode *PunctLParen();
    std::vector<FlingExprContext *> flingExpr();
    FlingExprContext* flingExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PunctComma();
    antlr4::tree::TerminalNode* PunctComma(size_t i);
    antlr4::tree::TerminalNode *PunctRParen();
    FlingExpr_MuxContext *flingExpr_Mux();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExprContext* flingExpr();

  class  FlingExpr_MuxContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_MuxContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExpr_LogOrContext *flingExpr_LogOr();
    antlr4::tree::TerminalNode *PunctLogOr();
    FlingExprContext *flingExpr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_MuxContext* flingExpr_Mux();

  class  FlingExpr_LogOrContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_LogOrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExpr_LogAndContext *flingExpr_LogAnd();
    antlr4::tree::TerminalNode *PunctLogAnd();
    FlingExprContext *flingExpr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_LogOrContext* flingExpr_LogOr();

  class  FlingExpr_LogAndContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_LogAndContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExpr_BitOr_Or_BitNorContext *flingExpr_BitOr_Or_BitNor();
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *PunctBitOr();
    antlr4::tree::TerminalNode *PunctBitNor();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_LogAndContext* flingExpr_LogAnd();

  class  FlingExpr_BitOr_Or_BitNorContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_BitOr_Or_BitNorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExpr_BitAnd_Or_BitNandContext *flingExpr_BitAnd_Or_BitNand();
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *PunctBitAnd();
    antlr4::tree::TerminalNode *PunctBitNand();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_BitOr_Or_BitNorContext* flingExpr_BitOr_Or_BitNor();

  class  FlingExpr_BitAnd_Or_BitNandContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_BitAnd_Or_BitNandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExpr_BitXor_Or_BitXnorContext *flingExpr_BitXor_Or_BitXnor();
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *PunctBitXor();
    antlr4::tree::TerminalNode *PunctBitXnor();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_BitAnd_Or_BitNandContext* flingExpr_BitAnd_Or_BitNand();

  class  FlingExpr_BitXor_Or_BitXnorContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_BitXor_Or_BitXnorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExpr_CmpEqEtcContext *flingExpr_CmpEqEtc();
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *PunctCmpEq();
    antlr4::tree::TerminalNode *PunctCmpNe();
    antlr4::tree::TerminalNode *PunctCaseCmpEq();
    antlr4::tree::TerminalNode *PunctCaseCmpNe();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_BitXor_Or_BitXnorContext* flingExpr_BitXor_Or_BitXnor();

  class  FlingExpr_CmpEqEtcContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_CmpEqEtcContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExpr_CmpLtEtcContext *flingExpr_CmpLtEtc();
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *PunctCmpLt();
    antlr4::tree::TerminalNode *PunctCmpLe();
    antlr4::tree::TerminalNode *PunctCmpGt();
    antlr4::tree::TerminalNode *PunctCmpGe();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_CmpEqEtcContext* flingExpr_CmpEqEtc();

  class  FlingExpr_CmpLtEtcContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_CmpLtEtcContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExpr_BitShiftContext *flingExpr_BitShift();
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *KwLsl();
    antlr4::tree::TerminalNode *KwLsr();
    antlr4::tree::TerminalNode *KwAsr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_CmpLtEtcContext* flingExpr_CmpLtEtc();

  class  FlingExpr_BitShiftContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_BitShiftContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExpr_BinaryPlus_Or_BinaryMinusContext *flingExpr_BinaryPlus_Or_BinaryMinus();
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *PunctPlus();
    antlr4::tree::TerminalNode *PunctMinus();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_BitShiftContext* flingExpr_BitShift();

  class  FlingExpr_BinaryPlus_Or_BinaryMinusContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_BinaryPlus_Or_BinaryMinusContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExpr_Mul_Or_Div_Or_ModContext *flingExpr_Mul_Or_Div_Or_Mod();
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *PunctMul();
    antlr4::tree::TerminalNode *PunctDiv();
    antlr4::tree::TerminalNode *PunctMod();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_BinaryPlus_Or_BinaryMinusContext* flingExpr_BinaryPlus_Or_BinaryMinus();

  class  FlingExpr_Mul_Or_Div_Or_ModContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_Mul_Or_Div_Or_ModContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExprContext *flingExpr();
    FlingExpr_UnaryContext *flingExpr_Unary();
    antlr4::tree::TerminalNode *PunctPlus();
    antlr4::tree::TerminalNode *PunctMinus();
    antlr4::tree::TerminalNode *PunctLogNot();
    antlr4::tree::TerminalNode *PunctBitNot();
    antlr4::tree::TerminalNode *PunctBitOr();
    antlr4::tree::TerminalNode *PunctBitNor();
    antlr4::tree::TerminalNode *PunctBitAnd();
    antlr4::tree::TerminalNode *PunctBitNand();
    antlr4::tree::TerminalNode *PunctBitXor();
    antlr4::tree::TerminalNode *PunctBitXnor();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_Mul_Or_Div_Or_ModContext* flingExpr_Mul_Or_Div_Or_Mod();

  class  FlingExpr_UnaryContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_UnaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExpr_Unary_ItemFromMajorityContext *flingExpr_Unary_ItemFromMajority();
    FlingExpr_RangeContext *flingExpr_Range();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_UnaryContext* flingExpr_Unary();

  class  FlingExpr_Unary_ItemFromMajorityContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_Unary_ItemFromMajorityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExpr_LiteralContext *flingExpr_Literal();
    FlingExpr_SizedContext *flingExpr_Sized();
    FlingExpr_CatContext *flingExpr_Cat();
    FlingExpr_ReplContext *flingExpr_Repl();
    FlingExpr_KwDollarFuncOfContext *flingExpr_KwDollarFuncOf();
    FlingExpr_IdentEtcContext *flingExpr_IdentEtc();
    antlr4::tree::TerminalNode *PunctLParen();
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *PunctRParen();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_Unary_ItemFromMajorityContext* flingExpr_Unary_ItemFromMajority();

  class  FlingExpr_LiteralContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LitDecNum();
    antlr4::tree::TerminalNode *LitHexNum();
    antlr4::tree::TerminalNode *LitOctNum();
    antlr4::tree::TerminalNode *LitBinNum();
    antlr4::tree::TerminalNode *LitFloatNum();
    antlr4::tree::TerminalNode *LitString();
    antlr4::tree::TerminalNode *KwHighZ();
    antlr4::tree::TerminalNode *PunctLParen();
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *PunctRParen();
    antlr4::tree::TerminalNode *KwUnkX();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_LiteralContext* flingExpr_Literal();

  class  FlingExpr_SizedContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_SizedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwSized();
    antlr4::tree::TerminalNode *PunctLParen();
    std::vector<FlingExprContext *> flingExpr();
    FlingExprContext* flingExpr(size_t i);
    antlr4::tree::TerminalNode *PunctComma();
    antlr4::tree::TerminalNode *PunctRParen();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_SizedContext* flingExpr_Sized();

  class  FlingExpr_RangeContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_RangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExpr_Range_DotDotContext *flingExpr_Range_DotDot();
    FlingExpr_Range_CallFuncContext *flingExpr_Range_CallFunc();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_RangeContext* flingExpr_Range();

  class  FlingExpr_Range_DotDotContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_Range_DotDotContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PunctRangeSeparator();
    FlingExprContext *flingExpr();
    FlingExpr_Unary_ItemFromMajorityContext *flingExpr_Unary_ItemFromMajority();
    FlingExpr_Range_CallFuncContext *flingExpr_Range_CallFunc();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_Range_DotDotContext* flingExpr_Range_DotDot();

  class  FlingExpr_Range_CallFuncContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_Range_CallFuncContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwRange();
    antlr4::tree::TerminalNode *PunctLParen();
    std::vector<FlingExprContext *> flingExpr();
    FlingExprContext* flingExpr(size_t i);
    antlr4::tree::TerminalNode *PunctComma();
    antlr4::tree::TerminalNode *PunctRParen();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_Range_CallFuncContext* flingExpr_Range_CallFunc();

  class  FlingExpr_CatContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_CatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwCat();
    antlr4::tree::TerminalNode *PunctLParen();
    FlingExprListContext *flingExprList();
    antlr4::tree::TerminalNode *PunctRParen();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_CatContext* flingExpr_Cat();

  class  FlingExpr_ReplContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_ReplContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwRepl();
    antlr4::tree::TerminalNode *PunctLParen();
    std::vector<FlingExprContext *> flingExpr();
    FlingExprContext* flingExpr(size_t i);
    antlr4::tree::TerminalNode *PunctComma();
    antlr4::tree::TerminalNode *PunctRParen();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_ReplContext* flingExpr_Repl();

  class  FlingExpr_KwDollarFuncOfContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_KwDollarFuncOfContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingExpr_KwDollarFuncOf_NonPowContext *flingExpr_KwDollarFuncOf_NonPow();
    FlingExpr_KwDollarFuncOf_PowContext *flingExpr_KwDollarFuncOf_Pow();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_KwDollarFuncOfContext* flingExpr_KwDollarFuncOf();

  class  FlingExpr_KwDollarFuncOf_NonPowContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_KwDollarFuncOf_NonPowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PunctLParen();
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *PunctRParen();
    antlr4::tree::TerminalNode *KwDollarSigned();
    antlr4::tree::TerminalNode *KwDollarUnsigned();
    antlr4::tree::TerminalNode *KwDollarClog2();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_KwDollarFuncOf_NonPowContext* flingExpr_KwDollarFuncOf_NonPow();

  class  FlingExpr_KwDollarFuncOf_PowContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_KwDollarFuncOf_PowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KwDollarPow();
    antlr4::tree::TerminalNode *PunctLParen();
    std::vector<FlingExprContext *> flingExpr();
    FlingExprContext* flingExpr(size_t i);
    antlr4::tree::TerminalNode *PunctComma();
    antlr4::tree::TerminalNode *PunctRParen();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_KwDollarFuncOf_PowContext* flingExpr_KwDollarFuncOf_Pow();

  class  FlingExpr_IdentEtcContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_IdentEtcContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FlingExpr_IdentEtc_ItemContext *> flingExpr_IdentEtc_Item();
    FlingExpr_IdentEtc_ItemContext* flingExpr_IdentEtc_Item(size_t i);
    FlingTypenameOrModnameContext *flingTypenameOrModname();
    antlr4::tree::TerminalNode *PunctScopeAccess();
    std::vector<antlr4::tree::TerminalNode *> PunctMemberAccess();
    antlr4::tree::TerminalNode* PunctMemberAccess(size_t i);
    antlr4::tree::TerminalNode *KwDollarSize();
    antlr4::tree::TerminalNode *KwDollarRange();
    antlr4::tree::TerminalNode *KwDollarHigh();
    antlr4::tree::TerminalNode *KwDollarLow();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_IdentEtcContext* flingExpr_IdentEtc();

  class  FlingExpr_IdentEtc_ItemContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_IdentEtc_ItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingIdentContext *flingIdent();
    FlingInstArgListContext *flingInstArgList();
    std::vector<FlingExpr_IdentEtc_Item_EndContext *> flingExpr_IdentEtc_Item_End();
    FlingExpr_IdentEtc_Item_EndContext* flingExpr_IdentEtc_Item_End(size_t i);
    FlingInstParamListContext *flingInstParamList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_IdentEtc_ItemContext* flingExpr_IdentEtc_Item();

  class  FlingExpr_IdentEtc_Item_EndContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_IdentEtc_Item_EndContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PunctLBracket();
    FlingExprContext *flingExpr();
    antlr4::tree::TerminalNode *PunctRBracket();
    antlr4::tree::TerminalNode *KwDollarFirstel();
    antlr4::tree::TerminalNode *KwDollarLastel();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_IdentEtc_Item_EndContext* flingExpr_IdentEtc_Item_End();

  class  FlingExpr_CallSubprog_PseudoOperContext : public antlr4::ParserRuleContext {
  public:
    FlingExpr_CallSubprog_PseudoOperContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FlingIdentContext *flingIdent();
    FlingExprContext *flingExpr();
    FlingExpr_Unary_ItemFromMajorityContext *flingExpr_Unary_ItemFromMajority();
    FlingExpr_Range_CallFuncContext *flingExpr_Range_CallFunc();
    FlingInstParamListContext *flingInstParamList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlingExpr_CallSubprog_PseudoOperContext* flingExpr_CallSubprog_PseudoOper();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

