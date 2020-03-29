
// Generated from FlingHdlGrammar.g4 by ANTLR 4.8


#include "FlingHdlGrammarVisitor.h"

#include "FlingHdlGrammarParser.h"


using namespace antlrcpp;
using namespace antlr4;

FlingHdlGrammarParser::FlingHdlGrammarParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

FlingHdlGrammarParser::~FlingHdlGrammarParser() {
  delete _interpreter;
}

std::string FlingHdlGrammarParser::getGrammarFileName() const {
  return "FlingHdlGrammar.g4";
}

const std::vector<std::string>& FlingHdlGrammarParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& FlingHdlGrammarParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FlingProgramContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingProgramContext::FlingProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingProgramContext::EOF() {
  return getToken(FlingHdlGrammarParser::EOF, 0);
}

std::vector<FlingHdlGrammarParser::FlingProgram_ItemContext *> FlingHdlGrammarParser::FlingProgramContext::flingProgram_Item() {
  return getRuleContexts<FlingHdlGrammarParser::FlingProgram_ItemContext>();
}

FlingHdlGrammarParser::FlingProgram_ItemContext* FlingHdlGrammarParser::FlingProgramContext::flingProgram_Item(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingProgram_ItemContext>(i);
}


size_t FlingHdlGrammarParser::FlingProgramContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingProgram;
}


antlrcpp::Any FlingHdlGrammarParser::FlingProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingProgram(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingProgramContext* FlingHdlGrammarParser::flingProgram() {
  FlingProgramContext *_localctx = _tracker.createInstance<FlingProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, FlingHdlGrammarParser::RuleFlingProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(271);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 61) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 61)) & ((1ULL << (FlingHdlGrammarParser::KwModule - 61))
      | (1ULL << (FlingHdlGrammarParser::KwPackage - 61))
      | (1ULL << (FlingHdlGrammarParser::KwFunc - 61))
      | (1ULL << (FlingHdlGrammarParser::KwTask - 61))
      | (1ULL << (FlingHdlGrammarParser::KwAlias - 61))
      | (1ULL << (FlingHdlGrammarParser::KwEnum - 61))
      | (1ULL << (FlingHdlGrammarParser::KwClass - 61))
      | (1ULL << (FlingHdlGrammarParser::KwMixin - 61)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 128)) & ((1ULL << (FlingHdlGrammarParser::KwBase - 128))
      | (1ULL << (FlingHdlGrammarParser::KwProc - 128))
      | (1ULL << (FlingHdlGrammarParser::MiscIdent - 128)))) != 0)) {
      setState(268);
      flingProgram_Item();
      setState(273);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(274);
    match(FlingHdlGrammarParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingProgram_ItemContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingProgram_ItemContext::FlingProgram_ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingDeclPackageContext* FlingHdlGrammarParser::FlingProgram_ItemContext::flingDeclPackage() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclPackageContext>(0);
}

FlingHdlGrammarParser::FlingDeclModuleContext* FlingHdlGrammarParser::FlingProgram_ItemContext::flingDeclModule() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclModuleContext>(0);
}

FlingHdlGrammarParser::FlingDeclTypeContext* FlingHdlGrammarParser::FlingProgram_ItemContext::flingDeclType() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTypeContext>(0);
}

FlingHdlGrammarParser::FlingDeclSubprogContext* FlingHdlGrammarParser::FlingProgram_ItemContext::flingDeclSubprog() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclSubprogContext>(0);
}

FlingHdlGrammarParser::FlingDeclAliasContext* FlingHdlGrammarParser::FlingProgram_ItemContext::flingDeclAlias() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclAliasContext>(0);
}

FlingHdlGrammarParser::FlingDeclConstContext* FlingHdlGrammarParser::FlingProgram_ItemContext::flingDeclConst() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclConstContext>(0);
}


size_t FlingHdlGrammarParser::FlingProgram_ItemContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingProgram_Item;
}


antlrcpp::Any FlingHdlGrammarParser::FlingProgram_ItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingProgram_Item(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingProgram_ItemContext* FlingHdlGrammarParser::flingProgram_Item() {
  FlingProgram_ItemContext *_localctx = _tracker.createInstance<FlingProgram_ItemContext>(_ctx, getState());
  enterRule(_localctx, 2, FlingHdlGrammarParser::RuleFlingProgram_Item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(282);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FlingHdlGrammarParser::KwPackage: {
        enterOuterAlt(_localctx, 1);
        setState(276);
        flingDeclPackage();
        break;
      }

      case FlingHdlGrammarParser::KwModule: {
        enterOuterAlt(_localctx, 2);
        setState(277);
        flingDeclModule();
        break;
      }

      case FlingHdlGrammarParser::KwEnum:
      case FlingHdlGrammarParser::KwClass:
      case FlingHdlGrammarParser::KwMixin:
      case FlingHdlGrammarParser::KwBase: {
        enterOuterAlt(_localctx, 3);
        setState(278);
        flingDeclType();
        break;
      }

      case FlingHdlGrammarParser::KwFunc:
      case FlingHdlGrammarParser::KwTask:
      case FlingHdlGrammarParser::KwProc: {
        enterOuterAlt(_localctx, 4);
        setState(279);
        flingDeclSubprog();
        break;
      }

      case FlingHdlGrammarParser::KwAlias: {
        enterOuterAlt(_localctx, 5);
        setState(280);
        flingDeclAlias();
        break;
      }

      case FlingHdlGrammarParser::MiscIdent: {
        enterOuterAlt(_localctx, 6);
        setState(281);
        flingDeclConst();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclPackageContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclPackageContext::FlingDeclPackageContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclPackageContext::KwPackage() {
  return getToken(FlingHdlGrammarParser::KwPackage, 0);
}

FlingHdlGrammarParser::FlingIdentContext* FlingHdlGrammarParser::FlingDeclPackageContext::flingIdent() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclPackageContext::PunctLBrace() {
  return getToken(FlingHdlGrammarParser::PunctLBrace, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclPackageContext::PunctRBrace() {
  return getToken(FlingHdlGrammarParser::PunctRBrace, 0);
}

std::vector<FlingHdlGrammarParser::FlingDeclPackage_ItemContext *> FlingHdlGrammarParser::FlingDeclPackageContext::flingDeclPackage_Item() {
  return getRuleContexts<FlingHdlGrammarParser::FlingDeclPackage_ItemContext>();
}

FlingHdlGrammarParser::FlingDeclPackage_ItemContext* FlingHdlGrammarParser::FlingDeclPackageContext::flingDeclPackage_Item(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclPackage_ItemContext>(i);
}


size_t FlingHdlGrammarParser::FlingDeclPackageContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclPackage;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclPackageContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclPackage(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclPackageContext* FlingHdlGrammarParser::flingDeclPackage() {
  FlingDeclPackageContext *_localctx = _tracker.createInstance<FlingDeclPackageContext>(_ctx, getState());
  enterRule(_localctx, 4, FlingHdlGrammarParser::RuleFlingDeclPackage);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(284);
    match(FlingHdlGrammarParser::KwPackage);
    setState(285);
    flingIdent();
    setState(286);
    match(FlingHdlGrammarParser::PunctLBrace);
    setState(290);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 61) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 61)) & ((1ULL << (FlingHdlGrammarParser::KwModule - 61))
      | (1ULL << (FlingHdlGrammarParser::KwPackage - 61))
      | (1ULL << (FlingHdlGrammarParser::KwFunc - 61))
      | (1ULL << (FlingHdlGrammarParser::KwTask - 61))
      | (1ULL << (FlingHdlGrammarParser::KwAlias - 61))
      | (1ULL << (FlingHdlGrammarParser::KwEnum - 61))
      | (1ULL << (FlingHdlGrammarParser::KwClass - 61))
      | (1ULL << (FlingHdlGrammarParser::KwMixin - 61)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 128)) & ((1ULL << (FlingHdlGrammarParser::KwBase - 128))
      | (1ULL << (FlingHdlGrammarParser::KwProc - 128))
      | (1ULL << (FlingHdlGrammarParser::MiscIdent - 128)))) != 0)) {
      setState(287);
      flingDeclPackage_Item();
      setState(292);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(293);
    match(FlingHdlGrammarParser::PunctRBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclPackage_ItemContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclPackage_ItemContext::FlingDeclPackage_ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingDeclPackageContext* FlingHdlGrammarParser::FlingDeclPackage_ItemContext::flingDeclPackage() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclPackageContext>(0);
}

FlingHdlGrammarParser::FlingDeclModuleContext* FlingHdlGrammarParser::FlingDeclPackage_ItemContext::flingDeclModule() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclModuleContext>(0);
}

FlingHdlGrammarParser::FlingDeclTypeContext* FlingHdlGrammarParser::FlingDeclPackage_ItemContext::flingDeclType() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTypeContext>(0);
}

FlingHdlGrammarParser::FlingDeclSubprogContext* FlingHdlGrammarParser::FlingDeclPackage_ItemContext::flingDeclSubprog() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclSubprogContext>(0);
}

FlingHdlGrammarParser::FlingDeclAliasContext* FlingHdlGrammarParser::FlingDeclPackage_ItemContext::flingDeclAlias() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclAliasContext>(0);
}

FlingHdlGrammarParser::FlingDeclConstContext* FlingHdlGrammarParser::FlingDeclPackage_ItemContext::flingDeclConst() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclConstContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclPackage_ItemContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclPackage_Item;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclPackage_ItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclPackage_Item(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclPackage_ItemContext* FlingHdlGrammarParser::flingDeclPackage_Item() {
  FlingDeclPackage_ItemContext *_localctx = _tracker.createInstance<FlingDeclPackage_ItemContext>(_ctx, getState());
  enterRule(_localctx, 6, FlingHdlGrammarParser::RuleFlingDeclPackage_Item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(301);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FlingHdlGrammarParser::KwPackage: {
        enterOuterAlt(_localctx, 1);
        setState(295);
        flingDeclPackage();
        break;
      }

      case FlingHdlGrammarParser::KwModule: {
        enterOuterAlt(_localctx, 2);
        setState(296);
        flingDeclModule();
        break;
      }

      case FlingHdlGrammarParser::KwEnum:
      case FlingHdlGrammarParser::KwClass:
      case FlingHdlGrammarParser::KwMixin:
      case FlingHdlGrammarParser::KwBase: {
        enterOuterAlt(_localctx, 3);
        setState(297);
        flingDeclType();
        break;
      }

      case FlingHdlGrammarParser::KwFunc:
      case FlingHdlGrammarParser::KwTask:
      case FlingHdlGrammarParser::KwProc: {
        enterOuterAlt(_localctx, 4);
        setState(298);
        flingDeclSubprog();
        break;
      }

      case FlingHdlGrammarParser::KwAlias: {
        enterOuterAlt(_localctx, 5);
        setState(299);
        flingDeclAlias();
        break;
      }

      case FlingHdlGrammarParser::MiscIdent: {
        enterOuterAlt(_localctx, 6);
        setState(300);
        flingDeclConst();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclParamListContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclParamListContext::FlingDeclParamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclParamListContext::PunctCmpLt() {
  return getToken(FlingHdlGrammarParser::PunctCmpLt, 0);
}

std::vector<FlingHdlGrammarParser::FlingDeclParamList_ItemContext *> FlingHdlGrammarParser::FlingDeclParamListContext::flingDeclParamList_Item() {
  return getRuleContexts<FlingHdlGrammarParser::FlingDeclParamList_ItemContext>();
}

FlingHdlGrammarParser::FlingDeclParamList_ItemContext* FlingHdlGrammarParser::FlingDeclParamListContext::flingDeclParamList_Item(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclParamList_ItemContext>(i);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclParamListContext::PunctCmpGt() {
  return getToken(FlingHdlGrammarParser::PunctCmpGt, 0);
}

std::vector<tree::TerminalNode *> FlingHdlGrammarParser::FlingDeclParamListContext::PunctSemicolon() {
  return getTokens(FlingHdlGrammarParser::PunctSemicolon);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclParamListContext::PunctSemicolon(size_t i) {
  return getToken(FlingHdlGrammarParser::PunctSemicolon, i);
}


size_t FlingHdlGrammarParser::FlingDeclParamListContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclParamList;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclParamListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclParamList(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclParamListContext* FlingHdlGrammarParser::flingDeclParamList() {
  FlingDeclParamListContext *_localctx = _tracker.createInstance<FlingDeclParamListContext>(_ctx, getState());
  enterRule(_localctx, 8, FlingHdlGrammarParser::RuleFlingDeclParamList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(303);
    match(FlingHdlGrammarParser::PunctCmpLt);
    setState(304);
    flingDeclParamList_Item();
    setState(309);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(305);
        match(FlingHdlGrammarParser::PunctSemicolon);
        setState(306);
        flingDeclParamList_Item(); 
      }
      setState(311);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
    setState(313);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::PunctSemicolon) {
      setState(312);
      match(FlingHdlGrammarParser::PunctSemicolon);
    }
    setState(315);
    match(FlingHdlGrammarParser::PunctCmpGt);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclParamList_ItemContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclParamList_ItemContext::FlingDeclParamList_ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingIdentListContext* FlingHdlGrammarParser::FlingDeclParamList_ItemContext::flingIdentList() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentListContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclParamList_ItemContext::PunctColon() {
  return getToken(FlingHdlGrammarParser::PunctColon, 0);
}

FlingHdlGrammarParser::FlingTypenameOrModnameContext* FlingHdlGrammarParser::FlingDeclParamList_ItemContext::flingTypenameOrModname() {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModnameContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclParamList_ItemContext::KwType() {
  return getToken(FlingHdlGrammarParser::KwType, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclParamList_ItemContext::KwModule() {
  return getToken(FlingHdlGrammarParser::KwModule, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclParamList_ItemContext::PunctBlkAssign() {
  return getToken(FlingHdlGrammarParser::PunctBlkAssign, 0);
}

FlingHdlGrammarParser::FlingExprListContext* FlingHdlGrammarParser::FlingDeclParamList_ItemContext::flingExprList() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprListContext>(0);
}

FlingHdlGrammarParser::FlingTypenameOrModnameListContext* FlingHdlGrammarParser::FlingDeclParamList_ItemContext::flingTypenameOrModnameList() {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModnameListContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclParamList_ItemContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclParamList_Item;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclParamList_ItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclParamList_Item(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclParamList_ItemContext* FlingHdlGrammarParser::flingDeclParamList_Item() {
  FlingDeclParamList_ItemContext *_localctx = _tracker.createInstance<FlingDeclParamList_ItemContext>(_ctx, getState());
  enterRule(_localctx, 10, FlingHdlGrammarParser::RuleFlingDeclParamList_Item);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(317);
    flingIdentList();
    setState(318);
    match(FlingHdlGrammarParser::PunctColon);
    setState(329);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FlingHdlGrammarParser::KwLogic:
      case FlingHdlGrammarParser::KwSigned:
      case FlingHdlGrammarParser::KwInteger:
      case FlingHdlGrammarParser::KwSizeT:
      case FlingHdlGrammarParser::KwU8:
      case FlingHdlGrammarParser::KwI8:
      case FlingHdlGrammarParser::KwU16:
      case FlingHdlGrammarParser::KwI16:
      case FlingHdlGrammarParser::KwU32:
      case FlingHdlGrammarParser::KwI32:
      case FlingHdlGrammarParser::KwU64:
      case FlingHdlGrammarParser::KwI64:
      case FlingHdlGrammarParser::KwU128:
      case FlingHdlGrammarParser::KwI128:
      case FlingHdlGrammarParser::KwRetT:
      case FlingHdlGrammarParser::KwAuto:
      case FlingHdlGrammarParser::KwRange:
      case FlingHdlGrammarParser::KwVoid:
      case FlingHdlGrammarParser::KwTypeof:
      case FlingHdlGrammarParser::KwSelfT:
      case FlingHdlGrammarParser::KwString:
      case FlingHdlGrammarParser::MiscIdent: {
        setState(319);
        flingTypenameOrModname();
        setState(322);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FlingHdlGrammarParser::PunctBlkAssign) {
          setState(320);
          match(FlingHdlGrammarParser::PunctBlkAssign);
          setState(321);
          flingExprList();
        }
        break;
      }

      case FlingHdlGrammarParser::KwModule:
      case FlingHdlGrammarParser::KwType: {
        setState(324);
        _la = _input->LA(1);
        if (!(_la == FlingHdlGrammarParser::KwModule

        || _la == FlingHdlGrammarParser::KwType)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(327);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FlingHdlGrammarParser::PunctBlkAssign) {
          setState(325);
          match(FlingHdlGrammarParser::PunctBlkAssign);
          setState(326);
          flingTypenameOrModnameList();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclArgListContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclArgListContext::FlingDeclArgListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclArgListContext::PunctLParen() {
  return getToken(FlingHdlGrammarParser::PunctLParen, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclArgListContext::PunctRParen() {
  return getToken(FlingHdlGrammarParser::PunctRParen, 0);
}

std::vector<FlingHdlGrammarParser::FlingDeclArgList_ItemContext *> FlingHdlGrammarParser::FlingDeclArgListContext::flingDeclArgList_Item() {
  return getRuleContexts<FlingHdlGrammarParser::FlingDeclArgList_ItemContext>();
}

FlingHdlGrammarParser::FlingDeclArgList_ItemContext* FlingHdlGrammarParser::FlingDeclArgListContext::flingDeclArgList_Item(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclArgList_ItemContext>(i);
}

std::vector<tree::TerminalNode *> FlingHdlGrammarParser::FlingDeclArgListContext::PunctSemicolon() {
  return getTokens(FlingHdlGrammarParser::PunctSemicolon);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclArgListContext::PunctSemicolon(size_t i) {
  return getToken(FlingHdlGrammarParser::PunctSemicolon, i);
}


size_t FlingHdlGrammarParser::FlingDeclArgListContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclArgList;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclArgListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclArgList(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclArgListContext* FlingHdlGrammarParser::flingDeclArgList() {
  FlingDeclArgListContext *_localctx = _tracker.createInstance<FlingDeclArgListContext>(_ctx, getState());
  enterRule(_localctx, 12, FlingHdlGrammarParser::RuleFlingDeclArgList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(331);
    match(FlingHdlGrammarParser::PunctLParen);
    setState(343);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::MiscIdent) {
      setState(332);
      flingDeclArgList_Item();
      setState(337);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(333);
          match(FlingHdlGrammarParser::PunctSemicolon);
          setState(334);
          flingDeclArgList_Item(); 
        }
        setState(339);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      }
      setState(341);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FlingHdlGrammarParser::PunctSemicolon) {
        setState(340);
        match(FlingHdlGrammarParser::PunctSemicolon);
      }
    }
    setState(345);
    match(FlingHdlGrammarParser::PunctRParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclArgList_ItemContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclArgList_ItemContext::FlingDeclArgList_ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingIdentListContext* FlingHdlGrammarParser::FlingDeclArgList_ItemContext::flingIdentList() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentListContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclArgList_ItemContext::PunctColon() {
  return getToken(FlingHdlGrammarParser::PunctColon, 0);
}

FlingHdlGrammarParser::FlingTypenameOrModnameContext* FlingHdlGrammarParser::FlingDeclArgList_ItemContext::flingTypenameOrModname() {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModnameContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclArgList_ItemContext::KwInput() {
  return getToken(FlingHdlGrammarParser::KwInput, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclArgList_ItemContext::KwOutput() {
  return getToken(FlingHdlGrammarParser::KwOutput, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclArgList_ItemContext::KwInout() {
  return getToken(FlingHdlGrammarParser::KwInout, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclArgList_ItemContext::KwInterface() {
  return getToken(FlingHdlGrammarParser::KwInterface, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclArgList_ItemContext::PunctBlkAssign() {
  return getToken(FlingHdlGrammarParser::PunctBlkAssign, 0);
}

FlingHdlGrammarParser::FlingExprListContext* FlingHdlGrammarParser::FlingDeclArgList_ItemContext::flingExprList() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprListContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclArgList_ItemContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclArgList_Item;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclArgList_ItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclArgList_Item(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclArgList_ItemContext* FlingHdlGrammarParser::flingDeclArgList_Item() {
  FlingDeclArgList_ItemContext *_localctx = _tracker.createInstance<FlingDeclArgList_ItemContext>(_ctx, getState());
  enterRule(_localctx, 14, FlingHdlGrammarParser::RuleFlingDeclArgList_Item);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(347);
    flingIdentList();
    setState(348);
    match(FlingHdlGrammarParser::PunctColon);
    setState(349);
    _la = _input->LA(1);
    if (!(((((_la - 63) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 63)) & ((1ULL << (FlingHdlGrammarParser::KwInput - 63))
      | (1ULL << (FlingHdlGrammarParser::KwOutput - 63))
      | (1ULL << (FlingHdlGrammarParser::KwInout - 63))
      | (1ULL << (FlingHdlGrammarParser::KwInterface - 63)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(350);
    flingTypenameOrModname();
    setState(353);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::PunctBlkAssign) {
      setState(351);
      match(FlingHdlGrammarParser::PunctBlkAssign);
      setState(352);
      flingExprList();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingInstParamListContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingInstParamListContext::FlingInstParamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingInstParamListContext::PunctCmpLt() {
  return getToken(FlingHdlGrammarParser::PunctCmpLt, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingInstParamListContext::PunctCmpGt() {
  return getToken(FlingHdlGrammarParser::PunctCmpGt, 0);
}

FlingHdlGrammarParser::FlingInstParamList_PosContext* FlingHdlGrammarParser::FlingInstParamListContext::flingInstParamList_Pos() {
  return getRuleContext<FlingHdlGrammarParser::FlingInstParamList_PosContext>(0);
}

FlingHdlGrammarParser::FlingInstParamList_NamedContext* FlingHdlGrammarParser::FlingInstParamListContext::flingInstParamList_Named() {
  return getRuleContext<FlingHdlGrammarParser::FlingInstParamList_NamedContext>(0);
}


size_t FlingHdlGrammarParser::FlingInstParamListContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingInstParamList;
}


antlrcpp::Any FlingHdlGrammarParser::FlingInstParamListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingInstParamList(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingInstParamListContext* FlingHdlGrammarParser::flingInstParamList() {
  FlingInstParamListContext *_localctx = _tracker.createInstance<FlingInstParamListContext>(_ctx, getState());
  enterRule(_localctx, 16, FlingHdlGrammarParser::RuleFlingInstParamList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(355);
    match(FlingHdlGrammarParser::PunctCmpLt);
    setState(358);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(356);
      flingInstParamList_Pos();
      break;
    }

    case 2: {
      setState(357);
      flingInstParamList_Named();
      break;
    }

    }
    setState(360);
    match(FlingHdlGrammarParser::PunctCmpGt);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingInstParamList_PosContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingInstParamList_PosContext::FlingInstParamList_PosContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FlingHdlGrammarParser::FlingInstParamList_Pos_ItemContext *> FlingHdlGrammarParser::FlingInstParamList_PosContext::flingInstParamList_Pos_Item() {
  return getRuleContexts<FlingHdlGrammarParser::FlingInstParamList_Pos_ItemContext>();
}

FlingHdlGrammarParser::FlingInstParamList_Pos_ItemContext* FlingHdlGrammarParser::FlingInstParamList_PosContext::flingInstParamList_Pos_Item(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingInstParamList_Pos_ItemContext>(i);
}

std::vector<tree::TerminalNode *> FlingHdlGrammarParser::FlingInstParamList_PosContext::PunctComma() {
  return getTokens(FlingHdlGrammarParser::PunctComma);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingInstParamList_PosContext::PunctComma(size_t i) {
  return getToken(FlingHdlGrammarParser::PunctComma, i);
}


size_t FlingHdlGrammarParser::FlingInstParamList_PosContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingInstParamList_Pos;
}


antlrcpp::Any FlingHdlGrammarParser::FlingInstParamList_PosContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingInstParamList_Pos(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingInstParamList_PosContext* FlingHdlGrammarParser::flingInstParamList_Pos() {
  FlingInstParamList_PosContext *_localctx = _tracker.createInstance<FlingInstParamList_PosContext>(_ctx, getState());
  enterRule(_localctx, 18, FlingHdlGrammarParser::RuleFlingInstParamList_Pos);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(362);
    flingInstParamList_Pos_Item();
    setState(367);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FlingHdlGrammarParser::PunctComma) {
      setState(363);
      match(FlingHdlGrammarParser::PunctComma);
      setState(364);
      flingInstParamList_Pos_Item();
      setState(369);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingInstParamList_Pos_ItemContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingInstParamList_Pos_ItemContext::FlingInstParamList_Pos_ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingInstParamList_Pos_ItemContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

FlingHdlGrammarParser::FlingTypenameOrModnameContext* FlingHdlGrammarParser::FlingInstParamList_Pos_ItemContext::flingTypenameOrModname() {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModnameContext>(0);
}


size_t FlingHdlGrammarParser::FlingInstParamList_Pos_ItemContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingInstParamList_Pos_Item;
}


antlrcpp::Any FlingHdlGrammarParser::FlingInstParamList_Pos_ItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingInstParamList_Pos_Item(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingInstParamList_Pos_ItemContext* FlingHdlGrammarParser::flingInstParamList_Pos_Item() {
  FlingInstParamList_Pos_ItemContext *_localctx = _tracker.createInstance<FlingInstParamList_Pos_ItemContext>(_ctx, getState());
  enterRule(_localctx, 20, FlingHdlGrammarParser::RuleFlingInstParamList_Pos_Item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(372);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(370);
      flingExpr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(371);
      flingTypenameOrModname();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingInstParamList_NamedContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingInstParamList_NamedContext::FlingInstParamList_NamedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FlingHdlGrammarParser::FlingInstParamList_Named_ItemContext *> FlingHdlGrammarParser::FlingInstParamList_NamedContext::flingInstParamList_Named_Item() {
  return getRuleContexts<FlingHdlGrammarParser::FlingInstParamList_Named_ItemContext>();
}

FlingHdlGrammarParser::FlingInstParamList_Named_ItemContext* FlingHdlGrammarParser::FlingInstParamList_NamedContext::flingInstParamList_Named_Item(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingInstParamList_Named_ItemContext>(i);
}

std::vector<tree::TerminalNode *> FlingHdlGrammarParser::FlingInstParamList_NamedContext::PunctComma() {
  return getTokens(FlingHdlGrammarParser::PunctComma);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingInstParamList_NamedContext::PunctComma(size_t i) {
  return getToken(FlingHdlGrammarParser::PunctComma, i);
}


size_t FlingHdlGrammarParser::FlingInstParamList_NamedContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingInstParamList_Named;
}


antlrcpp::Any FlingHdlGrammarParser::FlingInstParamList_NamedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingInstParamList_Named(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingInstParamList_NamedContext* FlingHdlGrammarParser::flingInstParamList_Named() {
  FlingInstParamList_NamedContext *_localctx = _tracker.createInstance<FlingInstParamList_NamedContext>(_ctx, getState());
  enterRule(_localctx, 22, FlingHdlGrammarParser::RuleFlingInstParamList_Named);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(374);
    flingInstParamList_Named_Item();
    setState(379);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FlingHdlGrammarParser::PunctComma) {
      setState(375);
      match(FlingHdlGrammarParser::PunctComma);
      setState(376);
      flingInstParamList_Named_Item();
      setState(381);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingInstParamList_Named_ItemContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingInstParamList_Named_ItemContext::FlingInstParamList_Named_ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingIdentContext* FlingHdlGrammarParser::FlingInstParamList_Named_ItemContext::flingIdent() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingInstParamList_Named_ItemContext::PunctMapTo() {
  return getToken(FlingHdlGrammarParser::PunctMapTo, 0);
}

FlingHdlGrammarParser::FlingInstParamList_Pos_ItemContext* FlingHdlGrammarParser::FlingInstParamList_Named_ItemContext::flingInstParamList_Pos_Item() {
  return getRuleContext<FlingHdlGrammarParser::FlingInstParamList_Pos_ItemContext>(0);
}


size_t FlingHdlGrammarParser::FlingInstParamList_Named_ItemContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingInstParamList_Named_Item;
}


antlrcpp::Any FlingHdlGrammarParser::FlingInstParamList_Named_ItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingInstParamList_Named_Item(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingInstParamList_Named_ItemContext* FlingHdlGrammarParser::flingInstParamList_Named_Item() {
  FlingInstParamList_Named_ItemContext *_localctx = _tracker.createInstance<FlingInstParamList_Named_ItemContext>(_ctx, getState());
  enterRule(_localctx, 24, FlingHdlGrammarParser::RuleFlingInstParamList_Named_Item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(382);
    flingIdent();
    setState(383);
    match(FlingHdlGrammarParser::PunctMapTo);
    setState(384);
    flingInstParamList_Pos_Item();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingInstArgListContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingInstArgListContext::FlingInstArgListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingInstArgListContext::PunctLParen() {
  return getToken(FlingHdlGrammarParser::PunctLParen, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingInstArgListContext::PunctRParen() {
  return getToken(FlingHdlGrammarParser::PunctRParen, 0);
}

FlingHdlGrammarParser::FlingInstArgList_PosContext* FlingHdlGrammarParser::FlingInstArgListContext::flingInstArgList_Pos() {
  return getRuleContext<FlingHdlGrammarParser::FlingInstArgList_PosContext>(0);
}

FlingHdlGrammarParser::FlingInstArgList_NamedContext* FlingHdlGrammarParser::FlingInstArgListContext::flingInstArgList_Named() {
  return getRuleContext<FlingHdlGrammarParser::FlingInstArgList_NamedContext>(0);
}


size_t FlingHdlGrammarParser::FlingInstArgListContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingInstArgList;
}


antlrcpp::Any FlingHdlGrammarParser::FlingInstArgListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingInstArgList(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingInstArgListContext* FlingHdlGrammarParser::flingInstArgList() {
  FlingInstArgListContext *_localctx = _tracker.createInstance<FlingInstArgListContext>(_ctx, getState());
  enterRule(_localctx, 26, FlingHdlGrammarParser::RuleFlingInstArgList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(386);
    match(FlingHdlGrammarParser::PunctLParen);
    setState(389);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(387);
      flingInstArgList_Pos();
      break;
    }

    case 2: {
      setState(388);
      flingInstArgList_Named();
      break;
    }

    }
    setState(391);
    match(FlingHdlGrammarParser::PunctRParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingInstArgList_PosContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingInstArgList_PosContext::FlingInstArgList_PosContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExprListContext* FlingHdlGrammarParser::FlingInstArgList_PosContext::flingExprList() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprListContext>(0);
}


size_t FlingHdlGrammarParser::FlingInstArgList_PosContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingInstArgList_Pos;
}


antlrcpp::Any FlingHdlGrammarParser::FlingInstArgList_PosContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingInstArgList_Pos(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingInstArgList_PosContext* FlingHdlGrammarParser::flingInstArgList_Pos() {
  FlingInstArgList_PosContext *_localctx = _tracker.createInstance<FlingInstArgList_PosContext>(_ctx, getState());
  enterRule(_localctx, 28, FlingHdlGrammarParser::RuleFlingInstArgList_Pos);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(393);
    flingExprList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingInstArgList_NamedContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingInstArgList_NamedContext::FlingInstArgList_NamedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FlingHdlGrammarParser::FlingInstArgList_Named_ItemContext *> FlingHdlGrammarParser::FlingInstArgList_NamedContext::flingInstArgList_Named_Item() {
  return getRuleContexts<FlingHdlGrammarParser::FlingInstArgList_Named_ItemContext>();
}

FlingHdlGrammarParser::FlingInstArgList_Named_ItemContext* FlingHdlGrammarParser::FlingInstArgList_NamedContext::flingInstArgList_Named_Item(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingInstArgList_Named_ItemContext>(i);
}

std::vector<tree::TerminalNode *> FlingHdlGrammarParser::FlingInstArgList_NamedContext::PunctComma() {
  return getTokens(FlingHdlGrammarParser::PunctComma);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingInstArgList_NamedContext::PunctComma(size_t i) {
  return getToken(FlingHdlGrammarParser::PunctComma, i);
}


size_t FlingHdlGrammarParser::FlingInstArgList_NamedContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingInstArgList_Named;
}


antlrcpp::Any FlingHdlGrammarParser::FlingInstArgList_NamedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingInstArgList_Named(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingInstArgList_NamedContext* FlingHdlGrammarParser::flingInstArgList_Named() {
  FlingInstArgList_NamedContext *_localctx = _tracker.createInstance<FlingInstArgList_NamedContext>(_ctx, getState());
  enterRule(_localctx, 30, FlingHdlGrammarParser::RuleFlingInstArgList_Named);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    flingInstArgList_Named_Item();
    setState(400);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FlingHdlGrammarParser::PunctComma) {
      setState(396);
      match(FlingHdlGrammarParser::PunctComma);
      setState(397);
      flingInstArgList_Named_Item();
      setState(402);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingInstArgList_Named_ItemContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingInstArgList_Named_ItemContext::FlingInstArgList_Named_ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingIdentContext* FlingHdlGrammarParser::FlingInstArgList_Named_ItemContext::flingIdent() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingInstArgList_Named_ItemContext::PunctMapTo() {
  return getToken(FlingHdlGrammarParser::PunctMapTo, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingInstArgList_Named_ItemContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}


size_t FlingHdlGrammarParser::FlingInstArgList_Named_ItemContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingInstArgList_Named_Item;
}


antlrcpp::Any FlingHdlGrammarParser::FlingInstArgList_Named_ItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingInstArgList_Named_Item(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingInstArgList_Named_ItemContext* FlingHdlGrammarParser::flingInstArgList_Named_Item() {
  FlingInstArgList_Named_ItemContext *_localctx = _tracker.createInstance<FlingInstArgList_Named_ItemContext>(_ctx, getState());
  enterRule(_localctx, 32, FlingHdlGrammarParser::RuleFlingInstArgList_Named_Item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(403);
    flingIdent();
    setState(404);
    match(FlingHdlGrammarParser::PunctMapTo);
    setState(405);
    flingExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclModuleContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclModuleContext::FlingDeclModuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclModuleContext::KwModule() {
  return getToken(FlingHdlGrammarParser::KwModule, 0);
}

FlingHdlGrammarParser::FlingIdentContext* FlingHdlGrammarParser::FlingDeclModuleContext::flingIdent() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentContext>(0);
}

FlingHdlGrammarParser::FlingDeclArgListContext* FlingHdlGrammarParser::FlingDeclModuleContext::flingDeclArgList() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclArgListContext>(0);
}

FlingHdlGrammarParser::FlingDeclModule_ScopeContext* FlingHdlGrammarParser::FlingDeclModuleContext::flingDeclModule_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclModule_ScopeContext>(0);
}

FlingHdlGrammarParser::FlingDeclParamListContext* FlingHdlGrammarParser::FlingDeclModuleContext::flingDeclParamList() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclParamListContext>(0);
}

FlingHdlGrammarParser::FlingImportListContext* FlingHdlGrammarParser::FlingDeclModuleContext::flingImportList() {
  return getRuleContext<FlingHdlGrammarParser::FlingImportListContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclModuleContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclModule;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclModuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclModule(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclModuleContext* FlingHdlGrammarParser::flingDeclModule() {
  FlingDeclModuleContext *_localctx = _tracker.createInstance<FlingDeclModuleContext>(_ctx, getState());
  enterRule(_localctx, 34, FlingHdlGrammarParser::RuleFlingDeclModule);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(407);
    match(FlingHdlGrammarParser::KwModule);
    setState(408);
    flingIdent();
    setState(410);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::PunctCmpLt) {
      setState(409);
      flingDeclParamList();
    }
    setState(412);
    flingDeclArgList();
    setState(414);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::KwImport) {
      setState(413);
      flingImportList();
    }
    setState(416);
    flingDeclModule_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclModule_ScopeContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclModule_ScopeContext::FlingDeclModule_ScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclModule_ScopeContext::PunctLBrace() {
  return getToken(FlingHdlGrammarParser::PunctLBrace, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclModule_ScopeContext::PunctRBrace() {
  return getToken(FlingHdlGrammarParser::PunctRBrace, 0);
}

std::vector<FlingHdlGrammarParser::FlingDeclModule_ItemContext *> FlingHdlGrammarParser::FlingDeclModule_ScopeContext::flingDeclModule_Item() {
  return getRuleContexts<FlingHdlGrammarParser::FlingDeclModule_ItemContext>();
}

FlingHdlGrammarParser::FlingDeclModule_ItemContext* FlingHdlGrammarParser::FlingDeclModule_ScopeContext::flingDeclModule_Item(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclModule_ItemContext>(i);
}


size_t FlingHdlGrammarParser::FlingDeclModule_ScopeContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclModule_Scope;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclModule_ScopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclModule_Scope(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclModule_ScopeContext* FlingHdlGrammarParser::flingDeclModule_Scope() {
  FlingDeclModule_ScopeContext *_localctx = _tracker.createInstance<FlingDeclModule_ScopeContext>(_ctx, getState());
  enterRule(_localctx, 36, FlingHdlGrammarParser::RuleFlingDeclModule_Scope);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(418);
    match(FlingHdlGrammarParser::PunctLBrace);
    setState(422);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FlingHdlGrammarParser::LitDecNum)
      | (1ULL << FlingHdlGrammarParser::LitHexNum)
      | (1ULL << FlingHdlGrammarParser::LitOctNum)
      | (1ULL << FlingHdlGrammarParser::LitBinNum)
      | (1ULL << FlingHdlGrammarParser::LitFloatNum)
      | (1ULL << FlingHdlGrammarParser::LitString)
      | (1ULL << FlingHdlGrammarParser::PunctPlus)
      | (1ULL << FlingHdlGrammarParser::PunctMinus)
      | (1ULL << FlingHdlGrammarParser::PunctBitOr)
      | (1ULL << FlingHdlGrammarParser::PunctBitNor)
      | (1ULL << FlingHdlGrammarParser::PunctBitAnd)
      | (1ULL << FlingHdlGrammarParser::PunctBitNand)
      | (1ULL << FlingHdlGrammarParser::PunctBitXor)
      | (1ULL << FlingHdlGrammarParser::PunctBitXnor)
      | (1ULL << FlingHdlGrammarParser::PunctBitNot)
      | (1ULL << FlingHdlGrammarParser::PunctLogNot)
      | (1ULL << FlingHdlGrammarParser::PunctLParen)
      | (1ULL << FlingHdlGrammarParser::KwMux))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (FlingHdlGrammarParser::KwGen - 67))
      | (1ULL << (FlingHdlGrammarParser::KwInitial - 67))
      | (1ULL << (FlingHdlGrammarParser::KwComb - 67))
      | (1ULL << (FlingHdlGrammarParser::KwSeq - 67))
      | (1ULL << (FlingHdlGrammarParser::KwFunc - 67))
      | (1ULL << (FlingHdlGrammarParser::KwTask - 67))
      | (1ULL << (FlingHdlGrammarParser::KwImport - 67))
      | (1ULL << (FlingHdlGrammarParser::KwLogic - 67))
      | (1ULL << (FlingHdlGrammarParser::KwSigned - 67))
      | (1ULL << (FlingHdlGrammarParser::KwInteger - 67))
      | (1ULL << (FlingHdlGrammarParser::KwSizeT - 67))
      | (1ULL << (FlingHdlGrammarParser::KwU8 - 67))
      | (1ULL << (FlingHdlGrammarParser::KwI8 - 67))
      | (1ULL << (FlingHdlGrammarParser::KwU16 - 67))
      | (1ULL << (FlingHdlGrammarParser::KwI16 - 67))
      | (1ULL << (FlingHdlGrammarParser::KwU32 - 67))
      | (1ULL << (FlingHdlGrammarParser::KwI32 - 67))
      | (1ULL << (FlingHdlGrammarParser::KwU64 - 67))
      | (1ULL << (FlingHdlGrammarParser::KwI64 - 67))
      | (1ULL << (FlingHdlGrammarParser::KwU128 - 67))
      | (1ULL << (FlingHdlGrammarParser::KwI128 - 67))
      | (1ULL << (FlingHdlGrammarParser::KwRetT - 67))
      | (1ULL << (FlingHdlGrammarParser::KwAuto - 67))
      | (1ULL << (FlingHdlGrammarParser::KwRange - 67))
      | (1ULL << (FlingHdlGrammarParser::KwHighZ - 67))
      | (1ULL << (FlingHdlGrammarParser::KwUnkX - 67))
      | (1ULL << (FlingHdlGrammarParser::KwSized - 67))
      | (1ULL << (FlingHdlGrammarParser::KwCat - 67))
      | (1ULL << (FlingHdlGrammarParser::KwRepl - 67))
      | (1ULL << (FlingHdlGrammarParser::KwDollarSigned - 67))
      | (1ULL << (FlingHdlGrammarParser::KwDollarUnsigned - 67))
      | (1ULL << (FlingHdlGrammarParser::KwDollarPow - 67))
      | (1ULL << (FlingHdlGrammarParser::KwDollarClog2 - 67))
      | (1ULL << (FlingHdlGrammarParser::KwVoid - 67))
      | (1ULL << (FlingHdlGrammarParser::KwTypeof - 67))
      | (1ULL << (FlingHdlGrammarParser::KwAlias - 67))
      | (1ULL << (FlingHdlGrammarParser::KwEnum - 67))
      | (1ULL << (FlingHdlGrammarParser::KwClass - 67))
      | (1ULL << (FlingHdlGrammarParser::KwMixin - 67))
      | (1ULL << (FlingHdlGrammarParser::KwBase - 67))
      | (1ULL << (FlingHdlGrammarParser::KwProc - 67)))) != 0) || ((((_la - 132) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 132)) & ((1ULL << (FlingHdlGrammarParser::KwSelfT - 132))
      | (1ULL << (FlingHdlGrammarParser::KwString - 132))
      | (1ULL << (FlingHdlGrammarParser::MiscIdent - 132)))) != 0)) {
      setState(419);
      flingDeclModule_Item();
      setState(424);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(425);
    match(FlingHdlGrammarParser::PunctRBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclModule_ItemContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclModule_ItemContext::FlingDeclModule_ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingInstModuleContext* FlingHdlGrammarParser::FlingDeclModule_ItemContext::flingInstModule() {
  return getRuleContext<FlingHdlGrammarParser::FlingInstModuleContext>(0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingDeclModule_ItemContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclModule_ItemContext::PunctSemicolon() {
  return getToken(FlingHdlGrammarParser::PunctSemicolon, 0);
}

FlingHdlGrammarParser::FlingGenContext* FlingHdlGrammarParser::FlingDeclModule_ItemContext::flingGen() {
  return getRuleContext<FlingHdlGrammarParser::FlingGenContext>(0);
}

FlingHdlGrammarParser::FlingContAssignContext* FlingHdlGrammarParser::FlingDeclModule_ItemContext::flingContAssign() {
  return getRuleContext<FlingHdlGrammarParser::FlingContAssignContext>(0);
}

FlingHdlGrammarParser::FlingImportListContext* FlingHdlGrammarParser::FlingDeclModule_ItemContext::flingImportList() {
  return getRuleContext<FlingHdlGrammarParser::FlingImportListContext>(0);
}

FlingHdlGrammarParser::FlingBehavContext* FlingHdlGrammarParser::FlingDeclModule_ItemContext::flingBehav() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehavContext>(0);
}

FlingHdlGrammarParser::FlingDeclWireContext* FlingHdlGrammarParser::FlingDeclModule_ItemContext::flingDeclWire() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclWireContext>(0);
}

FlingHdlGrammarParser::FlingDeclVarContext* FlingHdlGrammarParser::FlingDeclModule_ItemContext::flingDeclVar() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclVarContext>(0);
}

FlingHdlGrammarParser::FlingDeclConstContext* FlingHdlGrammarParser::FlingDeclModule_ItemContext::flingDeclConst() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclConstContext>(0);
}

FlingHdlGrammarParser::FlingDeclTypeContext* FlingHdlGrammarParser::FlingDeclModule_ItemContext::flingDeclType() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTypeContext>(0);
}

FlingHdlGrammarParser::FlingDeclSubprogContext* FlingHdlGrammarParser::FlingDeclModule_ItemContext::flingDeclSubprog() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclSubprogContext>(0);
}

FlingHdlGrammarParser::FlingDeclAliasContext* FlingHdlGrammarParser::FlingDeclModule_ItemContext::flingDeclAlias() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclAliasContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclModule_ItemContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclModule_Item;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclModule_ItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclModule_Item(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclModule_ItemContext* FlingHdlGrammarParser::flingDeclModule_Item() {
  FlingDeclModule_ItemContext *_localctx = _tracker.createInstance<FlingDeclModule_ItemContext>(_ctx, getState());
  enterRule(_localctx, 38, FlingHdlGrammarParser::RuleFlingDeclModule_Item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(441);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(427);
      flingInstModule();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(428);
      flingExpr();
      setState(429);
      match(FlingHdlGrammarParser::PunctSemicolon);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(431);
      flingGen();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(432);
      flingContAssign();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(433);
      flingImportList();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(434);
      flingBehav();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(435);
      flingDeclWire();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(436);
      flingDeclVar();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(437);
      flingDeclConst();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(438);
      flingDeclType();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(439);
      flingDeclSubprog();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(440);
      flingDeclAlias();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingInstModuleContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingInstModuleContext::FlingInstModuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingIdentContext* FlingHdlGrammarParser::FlingInstModuleContext::flingIdent() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingInstModuleContext::PunctColon() {
  return getToken(FlingHdlGrammarParser::PunctColon, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingInstModuleContext::KwModule() {
  return getToken(FlingHdlGrammarParser::KwModule, 0);
}

FlingHdlGrammarParser::FlingTypenameOrModnameContext* FlingHdlGrammarParser::FlingInstModuleContext::flingTypenameOrModname() {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModnameContext>(0);
}

FlingHdlGrammarParser::FlingInstArgListContext* FlingHdlGrammarParser::FlingInstModuleContext::flingInstArgList() {
  return getRuleContext<FlingHdlGrammarParser::FlingInstArgListContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingInstModuleContext::PunctSemicolon() {
  return getToken(FlingHdlGrammarParser::PunctSemicolon, 0);
}


size_t FlingHdlGrammarParser::FlingInstModuleContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingInstModule;
}


antlrcpp::Any FlingHdlGrammarParser::FlingInstModuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingInstModule(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingInstModuleContext* FlingHdlGrammarParser::flingInstModule() {
  FlingInstModuleContext *_localctx = _tracker.createInstance<FlingInstModuleContext>(_ctx, getState());
  enterRule(_localctx, 40, FlingHdlGrammarParser::RuleFlingInstModule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(443);
    flingIdent();
    setState(444);
    match(FlingHdlGrammarParser::PunctColon);
    setState(445);
    match(FlingHdlGrammarParser::KwModule);
    setState(446);
    flingTypenameOrModname();
    setState(447);
    flingInstArgList();
    setState(448);
    match(FlingHdlGrammarParser::PunctSemicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingGenContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingGenContext::FlingGenContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingGen_IfContext* FlingHdlGrammarParser::FlingGenContext::flingGen_If() {
  return getRuleContext<FlingHdlGrammarParser::FlingGen_IfContext>(0);
}

FlingHdlGrammarParser::FlingGen_SwitchContext* FlingHdlGrammarParser::FlingGenContext::flingGen_Switch() {
  return getRuleContext<FlingHdlGrammarParser::FlingGen_SwitchContext>(0);
}

FlingHdlGrammarParser::FlingGen_ForContext* FlingHdlGrammarParser::FlingGenContext::flingGen_For() {
  return getRuleContext<FlingHdlGrammarParser::FlingGen_ForContext>(0);
}


size_t FlingHdlGrammarParser::FlingGenContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingGen;
}


antlrcpp::Any FlingHdlGrammarParser::FlingGenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingGen(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingGenContext* FlingHdlGrammarParser::flingGen() {
  FlingGenContext *_localctx = _tracker.createInstance<FlingGenContext>(_ctx, getState());
  enterRule(_localctx, 42, FlingHdlGrammarParser::RuleFlingGen);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(453);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(450);
      flingGen_If();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(451);
      flingGen_Switch();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(452);
      flingGen_For();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingGen_IfContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingGen_IfContext::FlingGen_IfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingGen_IfContext::KwGen() {
  return getToken(FlingHdlGrammarParser::KwGen, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingGen_IfContext::KwIf() {
  return getToken(FlingHdlGrammarParser::KwIf, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingGen_IfContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

FlingHdlGrammarParser::FlingDeclModule_ScopeContext* FlingHdlGrammarParser::FlingGen_IfContext::flingDeclModule_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclModule_ScopeContext>(0);
}

std::vector<FlingHdlGrammarParser::FlingGen_If_ElifContext *> FlingHdlGrammarParser::FlingGen_IfContext::flingGen_If_Elif() {
  return getRuleContexts<FlingHdlGrammarParser::FlingGen_If_ElifContext>();
}

FlingHdlGrammarParser::FlingGen_If_ElifContext* FlingHdlGrammarParser::FlingGen_IfContext::flingGen_If_Elif(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingGen_If_ElifContext>(i);
}

FlingHdlGrammarParser::FlingGen_If_ElseContext* FlingHdlGrammarParser::FlingGen_IfContext::flingGen_If_Else() {
  return getRuleContext<FlingHdlGrammarParser::FlingGen_If_ElseContext>(0);
}


size_t FlingHdlGrammarParser::FlingGen_IfContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingGen_If;
}


antlrcpp::Any FlingHdlGrammarParser::FlingGen_IfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingGen_If(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingGen_IfContext* FlingHdlGrammarParser::flingGen_If() {
  FlingGen_IfContext *_localctx = _tracker.createInstance<FlingGen_IfContext>(_ctx, getState());
  enterRule(_localctx, 44, FlingHdlGrammarParser::RuleFlingGen_If);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(455);
    match(FlingHdlGrammarParser::KwGen);
    setState(456);
    match(FlingHdlGrammarParser::KwIf);
    setState(457);
    flingExpr();
    setState(458);
    flingDeclModule_Scope();
    setState(462);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(459);
        flingGen_If_Elif(); 
      }
      setState(464);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
    setState(466);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      setState(465);
      flingGen_If_Else();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingGen_If_ElifContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingGen_If_ElifContext::FlingGen_If_ElifContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingGen_If_ElifContext::KwGen() {
  return getToken(FlingHdlGrammarParser::KwGen, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingGen_If_ElifContext::KwElif() {
  return getToken(FlingHdlGrammarParser::KwElif, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingGen_If_ElifContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

FlingHdlGrammarParser::FlingDeclModule_ScopeContext* FlingHdlGrammarParser::FlingGen_If_ElifContext::flingDeclModule_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclModule_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingGen_If_ElifContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingGen_If_Elif;
}


antlrcpp::Any FlingHdlGrammarParser::FlingGen_If_ElifContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingGen_If_Elif(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingGen_If_ElifContext* FlingHdlGrammarParser::flingGen_If_Elif() {
  FlingGen_If_ElifContext *_localctx = _tracker.createInstance<FlingGen_If_ElifContext>(_ctx, getState());
  enterRule(_localctx, 46, FlingHdlGrammarParser::RuleFlingGen_If_Elif);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(468);
    match(FlingHdlGrammarParser::KwGen);
    setState(469);
    match(FlingHdlGrammarParser::KwElif);
    setState(470);
    flingExpr();
    setState(471);
    flingDeclModule_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingGen_If_ElseContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingGen_If_ElseContext::FlingGen_If_ElseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingGen_If_ElseContext::KwGen() {
  return getToken(FlingHdlGrammarParser::KwGen, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingGen_If_ElseContext::KwElse() {
  return getToken(FlingHdlGrammarParser::KwElse, 0);
}

FlingHdlGrammarParser::FlingDeclModule_ScopeContext* FlingHdlGrammarParser::FlingGen_If_ElseContext::flingDeclModule_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclModule_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingGen_If_ElseContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingGen_If_Else;
}


antlrcpp::Any FlingHdlGrammarParser::FlingGen_If_ElseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingGen_If_Else(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingGen_If_ElseContext* FlingHdlGrammarParser::flingGen_If_Else() {
  FlingGen_If_ElseContext *_localctx = _tracker.createInstance<FlingGen_If_ElseContext>(_ctx, getState());
  enterRule(_localctx, 48, FlingHdlGrammarParser::RuleFlingGen_If_Else);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(473);
    match(FlingHdlGrammarParser::KwGen);
    setState(474);
    match(FlingHdlGrammarParser::KwElse);
    setState(475);
    flingDeclModule_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingGen_SwitchContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingGen_SwitchContext::FlingGen_SwitchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingGen_SwitchContext::KwGen() {
  return getToken(FlingHdlGrammarParser::KwGen, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingGen_SwitchContext::KwSwitch() {
  return getToken(FlingHdlGrammarParser::KwSwitch, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingGen_SwitchContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingGen_SwitchContext::PunctLBrace() {
  return getToken(FlingHdlGrammarParser::PunctLBrace, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingGen_SwitchContext::PunctRBrace() {
  return getToken(FlingHdlGrammarParser::PunctRBrace, 0);
}

FlingHdlGrammarParser::FlingGen_Switch_DefaultContext* FlingHdlGrammarParser::FlingGen_SwitchContext::flingGen_Switch_Default() {
  return getRuleContext<FlingHdlGrammarParser::FlingGen_Switch_DefaultContext>(0);
}

std::vector<FlingHdlGrammarParser::FlingGen_Switch_CaseContext *> FlingHdlGrammarParser::FlingGen_SwitchContext::flingGen_Switch_Case() {
  return getRuleContexts<FlingHdlGrammarParser::FlingGen_Switch_CaseContext>();
}

FlingHdlGrammarParser::FlingGen_Switch_CaseContext* FlingHdlGrammarParser::FlingGen_SwitchContext::flingGen_Switch_Case(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingGen_Switch_CaseContext>(i);
}


size_t FlingHdlGrammarParser::FlingGen_SwitchContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingGen_Switch;
}


antlrcpp::Any FlingHdlGrammarParser::FlingGen_SwitchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingGen_Switch(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingGen_SwitchContext* FlingHdlGrammarParser::flingGen_Switch() {
  FlingGen_SwitchContext *_localctx = _tracker.createInstance<FlingGen_SwitchContext>(_ctx, getState());
  enterRule(_localctx, 50, FlingHdlGrammarParser::RuleFlingGen_Switch);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(477);
    match(FlingHdlGrammarParser::KwGen);
    setState(478);
    match(FlingHdlGrammarParser::KwSwitch);
    setState(479);
    flingExpr();
    setState(480);
    match(FlingHdlGrammarParser::PunctLBrace);
    setState(497);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      setState(482);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FlingHdlGrammarParser::KwDefault) {
        setState(481);
        flingGen_Switch_Default();
      }
      setState(487);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << FlingHdlGrammarParser::LitDecNum)
        | (1ULL << FlingHdlGrammarParser::LitHexNum)
        | (1ULL << FlingHdlGrammarParser::LitOctNum)
        | (1ULL << FlingHdlGrammarParser::LitBinNum)
        | (1ULL << FlingHdlGrammarParser::LitFloatNum)
        | (1ULL << FlingHdlGrammarParser::LitString)
        | (1ULL << FlingHdlGrammarParser::PunctPlus)
        | (1ULL << FlingHdlGrammarParser::PunctMinus)
        | (1ULL << FlingHdlGrammarParser::PunctBitOr)
        | (1ULL << FlingHdlGrammarParser::PunctBitNor)
        | (1ULL << FlingHdlGrammarParser::PunctBitAnd)
        | (1ULL << FlingHdlGrammarParser::PunctBitNand)
        | (1ULL << FlingHdlGrammarParser::PunctBitXor)
        | (1ULL << FlingHdlGrammarParser::PunctBitXnor)
        | (1ULL << FlingHdlGrammarParser::PunctBitNot)
        | (1ULL << FlingHdlGrammarParser::PunctLogNot)
        | (1ULL << FlingHdlGrammarParser::PunctLParen)
        | (1ULL << FlingHdlGrammarParser::KwMux))) != 0) || ((((_la - 78) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 78)) & ((1ULL << (FlingHdlGrammarParser::KwLogic - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwInteger - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSizeT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU8 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI8 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU16 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI16 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU32 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI32 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU64 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI64 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU128 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI128 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRetT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwAuto - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRange - 78))
        | (1ULL << (FlingHdlGrammarParser::KwHighZ - 78))
        | (1ULL << (FlingHdlGrammarParser::KwUnkX - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSized - 78))
        | (1ULL << (FlingHdlGrammarParser::KwCat - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRepl - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarSigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarUnsigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarPow - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarClog2 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwVoid - 78))
        | (1ULL << (FlingHdlGrammarParser::KwTypeof - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSelfT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwString - 78))
        | (1ULL << (FlingHdlGrammarParser::MiscIdent - 78)))) != 0)) {
        setState(484);
        flingGen_Switch_Case();
        setState(489);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      setState(491); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(490);
        flingGen_Switch_Case();
        setState(493); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << FlingHdlGrammarParser::LitDecNum)
        | (1ULL << FlingHdlGrammarParser::LitHexNum)
        | (1ULL << FlingHdlGrammarParser::LitOctNum)
        | (1ULL << FlingHdlGrammarParser::LitBinNum)
        | (1ULL << FlingHdlGrammarParser::LitFloatNum)
        | (1ULL << FlingHdlGrammarParser::LitString)
        | (1ULL << FlingHdlGrammarParser::PunctPlus)
        | (1ULL << FlingHdlGrammarParser::PunctMinus)
        | (1ULL << FlingHdlGrammarParser::PunctBitOr)
        | (1ULL << FlingHdlGrammarParser::PunctBitNor)
        | (1ULL << FlingHdlGrammarParser::PunctBitAnd)
        | (1ULL << FlingHdlGrammarParser::PunctBitNand)
        | (1ULL << FlingHdlGrammarParser::PunctBitXor)
        | (1ULL << FlingHdlGrammarParser::PunctBitXnor)
        | (1ULL << FlingHdlGrammarParser::PunctBitNot)
        | (1ULL << FlingHdlGrammarParser::PunctLogNot)
        | (1ULL << FlingHdlGrammarParser::PunctLParen)
        | (1ULL << FlingHdlGrammarParser::KwMux))) != 0) || ((((_la - 78) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 78)) & ((1ULL << (FlingHdlGrammarParser::KwLogic - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwInteger - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSizeT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU8 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI8 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU16 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI16 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU32 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI32 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU64 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI64 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU128 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI128 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRetT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwAuto - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRange - 78))
        | (1ULL << (FlingHdlGrammarParser::KwHighZ - 78))
        | (1ULL << (FlingHdlGrammarParser::KwUnkX - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSized - 78))
        | (1ULL << (FlingHdlGrammarParser::KwCat - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRepl - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarSigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarUnsigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarPow - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarClog2 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwVoid - 78))
        | (1ULL << (FlingHdlGrammarParser::KwTypeof - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSelfT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwString - 78))
        | (1ULL << (FlingHdlGrammarParser::MiscIdent - 78)))) != 0));
      setState(495);
      flingGen_Switch_Default();
      break;
    }

    }
    setState(499);
    match(FlingHdlGrammarParser::PunctRBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingGen_Switch_DefaultContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingGen_Switch_DefaultContext::FlingGen_Switch_DefaultContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingGen_Switch_DefaultContext::KwDefault() {
  return getToken(FlingHdlGrammarParser::KwDefault, 0);
}

FlingHdlGrammarParser::FlingDeclModule_ScopeContext* FlingHdlGrammarParser::FlingGen_Switch_DefaultContext::flingDeclModule_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclModule_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingGen_Switch_DefaultContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingGen_Switch_Default;
}


antlrcpp::Any FlingHdlGrammarParser::FlingGen_Switch_DefaultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingGen_Switch_Default(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingGen_Switch_DefaultContext* FlingHdlGrammarParser::flingGen_Switch_Default() {
  FlingGen_Switch_DefaultContext *_localctx = _tracker.createInstance<FlingGen_Switch_DefaultContext>(_ctx, getState());
  enterRule(_localctx, 52, FlingHdlGrammarParser::RuleFlingGen_Switch_Default);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(501);
    match(FlingHdlGrammarParser::KwDefault);
    setState(502);
    flingDeclModule_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingGen_Switch_CaseContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingGen_Switch_CaseContext::FlingGen_Switch_CaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExprListContext* FlingHdlGrammarParser::FlingGen_Switch_CaseContext::flingExprList() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprListContext>(0);
}

FlingHdlGrammarParser::FlingDeclModule_ScopeContext* FlingHdlGrammarParser::FlingGen_Switch_CaseContext::flingDeclModule_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclModule_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingGen_Switch_CaseContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingGen_Switch_Case;
}


antlrcpp::Any FlingHdlGrammarParser::FlingGen_Switch_CaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingGen_Switch_Case(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingGen_Switch_CaseContext* FlingHdlGrammarParser::flingGen_Switch_Case() {
  FlingGen_Switch_CaseContext *_localctx = _tracker.createInstance<FlingGen_Switch_CaseContext>(_ctx, getState());
  enterRule(_localctx, 54, FlingHdlGrammarParser::RuleFlingGen_Switch_Case);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(504);
    flingExprList();
    setState(505);
    flingDeclModule_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingGen_ForContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingGen_ForContext::FlingGen_ForContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingGen_ForContext::KwGen() {
  return getToken(FlingHdlGrammarParser::KwGen, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingGen_ForContext::PunctLBracket() {
  return getToken(FlingHdlGrammarParser::PunctLBracket, 0);
}

std::vector<FlingHdlGrammarParser::FlingIdentContext *> FlingHdlGrammarParser::FlingGen_ForContext::flingIdent() {
  return getRuleContexts<FlingHdlGrammarParser::FlingIdentContext>();
}

FlingHdlGrammarParser::FlingIdentContext* FlingHdlGrammarParser::FlingGen_ForContext::flingIdent(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentContext>(i);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingGen_ForContext::PunctRBracket() {
  return getToken(FlingHdlGrammarParser::PunctRBracket, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingGen_ForContext::KwFor() {
  return getToken(FlingHdlGrammarParser::KwFor, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingGen_ForContext::PunctColon() {
  return getToken(FlingHdlGrammarParser::PunctColon, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingGen_ForContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

FlingHdlGrammarParser::FlingDeclModule_ScopeContext* FlingHdlGrammarParser::FlingGen_ForContext::flingDeclModule_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclModule_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingGen_ForContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingGen_For;
}


antlrcpp::Any FlingHdlGrammarParser::FlingGen_ForContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingGen_For(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingGen_ForContext* FlingHdlGrammarParser::flingGen_For() {
  FlingGen_ForContext *_localctx = _tracker.createInstance<FlingGen_ForContext>(_ctx, getState());
  enterRule(_localctx, 56, FlingHdlGrammarParser::RuleFlingGen_For);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(507);
    match(FlingHdlGrammarParser::KwGen);
    setState(508);
    match(FlingHdlGrammarParser::PunctLBracket);
    setState(509);
    flingIdent();
    setState(510);
    match(FlingHdlGrammarParser::PunctRBracket);
    setState(511);
    match(FlingHdlGrammarParser::KwFor);
    setState(512);
    flingIdent();
    setState(513);
    match(FlingHdlGrammarParser::PunctColon);
    setState(514);
    flingExpr();
    setState(515);
    flingDeclModule_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingContAssignContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingContAssignContext::FlingContAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FlingHdlGrammarParser::FlingExprContext *> FlingHdlGrammarParser::FlingContAssignContext::flingExpr() {
  return getRuleContexts<FlingHdlGrammarParser::FlingExprContext>();
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingContAssignContext::flingExpr(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(i);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingContAssignContext::PunctNonBlkAssign() {
  return getToken(FlingHdlGrammarParser::PunctNonBlkAssign, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingContAssignContext::PunctSemicolon() {
  return getToken(FlingHdlGrammarParser::PunctSemicolon, 0);
}


size_t FlingHdlGrammarParser::FlingContAssignContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingContAssign;
}


antlrcpp::Any FlingHdlGrammarParser::FlingContAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingContAssign(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingContAssignContext* FlingHdlGrammarParser::flingContAssign() {
  FlingContAssignContext *_localctx = _tracker.createInstance<FlingContAssignContext>(_ctx, getState());
  enterRule(_localctx, 58, FlingHdlGrammarParser::RuleFlingContAssign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(517);
    flingExpr();
    setState(518);
    match(FlingHdlGrammarParser::PunctNonBlkAssign);
    setState(519);
    flingExpr();
    setState(520);
    match(FlingHdlGrammarParser::PunctSemicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingBehavContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingBehavContext::FlingBehavContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingBehav_ScopeContext* FlingHdlGrammarParser::FlingBehavContext::flingBehav_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_ScopeContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehavContext::KwInitial() {
  return getToken(FlingHdlGrammarParser::KwInitial, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehavContext::KwComb() {
  return getToken(FlingHdlGrammarParser::KwComb, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehavContext::KwSeq() {
  return getToken(FlingHdlGrammarParser::KwSeq, 0);
}

FlingHdlGrammarParser::FlingBehav_Seq_EdgeListContext* FlingHdlGrammarParser::FlingBehavContext::flingBehav_Seq_EdgeList() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_Seq_EdgeListContext>(0);
}


size_t FlingHdlGrammarParser::FlingBehavContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingBehav;
}


antlrcpp::Any FlingHdlGrammarParser::FlingBehavContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingBehav(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingBehavContext* FlingHdlGrammarParser::flingBehav() {
  FlingBehavContext *_localctx = _tracker.createInstance<FlingBehavContext>(_ctx, getState());
  enterRule(_localctx, 60, FlingHdlGrammarParser::RuleFlingBehav);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(526);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FlingHdlGrammarParser::KwInitial: {
        setState(522);
        match(FlingHdlGrammarParser::KwInitial);
        break;
      }

      case FlingHdlGrammarParser::KwComb: {
        setState(523);
        match(FlingHdlGrammarParser::KwComb);
        break;
      }

      case FlingHdlGrammarParser::KwSeq: {
        setState(524);
        match(FlingHdlGrammarParser::KwSeq);
        setState(525);
        flingBehav_Seq_EdgeList();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(528);
    flingBehav_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingBehav_Seq_EdgeListContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingBehav_Seq_EdgeListContext::FlingBehav_Seq_EdgeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FlingHdlGrammarParser::FlingBehav_Seq_EdgeList_ItemContext *> FlingHdlGrammarParser::FlingBehav_Seq_EdgeListContext::flingBehav_Seq_EdgeList_Item() {
  return getRuleContexts<FlingHdlGrammarParser::FlingBehav_Seq_EdgeList_ItemContext>();
}

FlingHdlGrammarParser::FlingBehav_Seq_EdgeList_ItemContext* FlingHdlGrammarParser::FlingBehav_Seq_EdgeListContext::flingBehav_Seq_EdgeList_Item(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_Seq_EdgeList_ItemContext>(i);
}

std::vector<tree::TerminalNode *> FlingHdlGrammarParser::FlingBehav_Seq_EdgeListContext::PunctComma() {
  return getTokens(FlingHdlGrammarParser::PunctComma);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehav_Seq_EdgeListContext::PunctComma(size_t i) {
  return getToken(FlingHdlGrammarParser::PunctComma, i);
}


size_t FlingHdlGrammarParser::FlingBehav_Seq_EdgeListContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingBehav_Seq_EdgeList;
}


antlrcpp::Any FlingHdlGrammarParser::FlingBehav_Seq_EdgeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingBehav_Seq_EdgeList(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingBehav_Seq_EdgeListContext* FlingHdlGrammarParser::flingBehav_Seq_EdgeList() {
  FlingBehav_Seq_EdgeListContext *_localctx = _tracker.createInstance<FlingBehav_Seq_EdgeListContext>(_ctx, getState());
  enterRule(_localctx, 62, FlingHdlGrammarParser::RuleFlingBehav_Seq_EdgeList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(530);
    flingBehav_Seq_EdgeList_Item();
    setState(535);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FlingHdlGrammarParser::PunctComma) {
      setState(531);
      match(FlingHdlGrammarParser::PunctComma);
      setState(532);
      flingBehav_Seq_EdgeList_Item();
      setState(537);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingBehav_Seq_EdgeList_ItemContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingBehav_Seq_EdgeList_ItemContext::FlingBehav_Seq_EdgeList_ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingBehav_Seq_EdgeList_ItemContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehav_Seq_EdgeList_ItemContext::KwPosedge() {
  return getToken(FlingHdlGrammarParser::KwPosedge, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehav_Seq_EdgeList_ItemContext::KwNegedge() {
  return getToken(FlingHdlGrammarParser::KwNegedge, 0);
}


size_t FlingHdlGrammarParser::FlingBehav_Seq_EdgeList_ItemContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingBehav_Seq_EdgeList_Item;
}


antlrcpp::Any FlingHdlGrammarParser::FlingBehav_Seq_EdgeList_ItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingBehav_Seq_EdgeList_Item(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingBehav_Seq_EdgeList_ItemContext* FlingHdlGrammarParser::flingBehav_Seq_EdgeList_Item() {
  FlingBehav_Seq_EdgeList_ItemContext *_localctx = _tracker.createInstance<FlingBehav_Seq_EdgeList_ItemContext>(_ctx, getState());
  enterRule(_localctx, 64, FlingHdlGrammarParser::RuleFlingBehav_Seq_EdgeList_Item);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(538);
    _la = _input->LA(1);
    if (!(_la == FlingHdlGrammarParser::KwPosedge

    || _la == FlingHdlGrammarParser::KwNegedge)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(539);
    flingExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingBehav_ScopeContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingBehav_ScopeContext::FlingBehav_ScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehav_ScopeContext::PunctLBrace() {
  return getToken(FlingHdlGrammarParser::PunctLBrace, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehav_ScopeContext::PunctRBrace() {
  return getToken(FlingHdlGrammarParser::PunctRBrace, 0);
}

std::vector<FlingHdlGrammarParser::FlingBehav_ItemContext *> FlingHdlGrammarParser::FlingBehav_ScopeContext::flingBehav_Item() {
  return getRuleContexts<FlingHdlGrammarParser::FlingBehav_ItemContext>();
}

FlingHdlGrammarParser::FlingBehav_ItemContext* FlingHdlGrammarParser::FlingBehav_ScopeContext::flingBehav_Item(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_ItemContext>(i);
}


size_t FlingHdlGrammarParser::FlingBehav_ScopeContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingBehav_Scope;
}


antlrcpp::Any FlingHdlGrammarParser::FlingBehav_ScopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingBehav_Scope(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingBehav_ScopeContext* FlingHdlGrammarParser::flingBehav_Scope() {
  FlingBehav_ScopeContext *_localctx = _tracker.createInstance<FlingBehav_ScopeContext>(_ctx, getState());
  enterRule(_localctx, 66, FlingHdlGrammarParser::RuleFlingBehav_Scope);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(541);
    match(FlingHdlGrammarParser::PunctLBrace);
    setState(545);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FlingHdlGrammarParser::LitDecNum)
      | (1ULL << FlingHdlGrammarParser::LitHexNum)
      | (1ULL << FlingHdlGrammarParser::LitOctNum)
      | (1ULL << FlingHdlGrammarParser::LitBinNum)
      | (1ULL << FlingHdlGrammarParser::LitFloatNum)
      | (1ULL << FlingHdlGrammarParser::LitString)
      | (1ULL << FlingHdlGrammarParser::PunctPlus)
      | (1ULL << FlingHdlGrammarParser::PunctMinus)
      | (1ULL << FlingHdlGrammarParser::PunctBitOr)
      | (1ULL << FlingHdlGrammarParser::PunctBitNor)
      | (1ULL << FlingHdlGrammarParser::PunctBitAnd)
      | (1ULL << FlingHdlGrammarParser::PunctBitNand)
      | (1ULL << FlingHdlGrammarParser::PunctBitXor)
      | (1ULL << FlingHdlGrammarParser::PunctBitXnor)
      | (1ULL << FlingHdlGrammarParser::PunctBitNot)
      | (1ULL << FlingHdlGrammarParser::PunctLogNot)
      | (1ULL << FlingHdlGrammarParser::PunctLParen)
      | (1ULL << FlingHdlGrammarParser::PunctLBrace)
      | (1ULL << FlingHdlGrammarParser::KwIf)
      | (1ULL << FlingHdlGrammarParser::KwMux)
      | (1ULL << FlingHdlGrammarParser::KwSwitch)
      | (1ULL << FlingHdlGrammarParser::KwSwitchz)
      | (1ULL << FlingHdlGrammarParser::KwFor)
      | (1ULL << FlingHdlGrammarParser::KwWhile))) != 0) || ((((_la - 78) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 78)) & ((1ULL << (FlingHdlGrammarParser::KwLogic - 78))
      | (1ULL << (FlingHdlGrammarParser::KwSigned - 78))
      | (1ULL << (FlingHdlGrammarParser::KwInteger - 78))
      | (1ULL << (FlingHdlGrammarParser::KwSizeT - 78))
      | (1ULL << (FlingHdlGrammarParser::KwU8 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwI8 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwU16 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwI16 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwU32 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwI32 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwU64 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwI64 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwU128 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwI128 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwRetT - 78))
      | (1ULL << (FlingHdlGrammarParser::KwAuto - 78))
      | (1ULL << (FlingHdlGrammarParser::KwRange - 78))
      | (1ULL << (FlingHdlGrammarParser::KwHighZ - 78))
      | (1ULL << (FlingHdlGrammarParser::KwUnkX - 78))
      | (1ULL << (FlingHdlGrammarParser::KwSized - 78))
      | (1ULL << (FlingHdlGrammarParser::KwCat - 78))
      | (1ULL << (FlingHdlGrammarParser::KwRepl - 78))
      | (1ULL << (FlingHdlGrammarParser::KwDollarSigned - 78))
      | (1ULL << (FlingHdlGrammarParser::KwDollarUnsigned - 78))
      | (1ULL << (FlingHdlGrammarParser::KwDollarPow - 78))
      | (1ULL << (FlingHdlGrammarParser::KwDollarClog2 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwVoid - 78))
      | (1ULL << (FlingHdlGrammarParser::KwTypeof - 78))
      | (1ULL << (FlingHdlGrammarParser::KwAlias - 78))
      | (1ULL << (FlingHdlGrammarParser::KwEnum - 78))
      | (1ULL << (FlingHdlGrammarParser::KwClass - 78))
      | (1ULL << (FlingHdlGrammarParser::KwMixin - 78))
      | (1ULL << (FlingHdlGrammarParser::KwBase - 78))
      | (1ULL << (FlingHdlGrammarParser::KwSelfT - 78))
      | (1ULL << (FlingHdlGrammarParser::KwString - 78))
      | (1ULL << (FlingHdlGrammarParser::MiscIdent - 78)))) != 0)) {
      setState(542);
      flingBehav_Item();
      setState(547);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(548);
    match(FlingHdlGrammarParser::PunctRBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingBehav_ItemContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingBehav_ItemContext::FlingBehav_ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingBehav_ScopeContext* FlingHdlGrammarParser::FlingBehav_ItemContext::flingBehav_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_ScopeContext>(0);
}

FlingHdlGrammarParser::FlingDeclAliasContext* FlingHdlGrammarParser::FlingBehav_ItemContext::flingDeclAlias() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclAliasContext>(0);
}

FlingHdlGrammarParser::FlingDeclVarContext* FlingHdlGrammarParser::FlingBehav_ItemContext::flingDeclVar() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclVarContext>(0);
}

FlingHdlGrammarParser::FlingDeclConstContext* FlingHdlGrammarParser::FlingBehav_ItemContext::flingDeclConst() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclConstContext>(0);
}

FlingHdlGrammarParser::FlingDeclTypeContext* FlingHdlGrammarParser::FlingBehav_ItemContext::flingDeclType() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTypeContext>(0);
}

FlingHdlGrammarParser::FlingBehav_Item_BlkAssignContext* FlingHdlGrammarParser::FlingBehav_ItemContext::flingBehav_Item_BlkAssign() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_Item_BlkAssignContext>(0);
}

FlingHdlGrammarParser::FlingBehav_Item_NonBlkAssignContext* FlingHdlGrammarParser::FlingBehav_ItemContext::flingBehav_Item_NonBlkAssign() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_Item_NonBlkAssignContext>(0);
}

FlingHdlGrammarParser::FlingBehav_Item_IfContext* FlingHdlGrammarParser::FlingBehav_ItemContext::flingBehav_Item_If() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_Item_IfContext>(0);
}

FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchzContext* FlingHdlGrammarParser::FlingBehav_ItemContext::flingBehav_Item_SwitchOrSwitchz() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchzContext>(0);
}

FlingHdlGrammarParser::FlingBehav_Item_ForContext* FlingHdlGrammarParser::FlingBehav_ItemContext::flingBehav_Item_For() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_Item_ForContext>(0);
}

FlingHdlGrammarParser::FlingBehav_Item_WhileContext* FlingHdlGrammarParser::FlingBehav_ItemContext::flingBehav_Item_While() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_Item_WhileContext>(0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingBehav_ItemContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehav_ItemContext::PunctSemicolon() {
  return getToken(FlingHdlGrammarParser::PunctSemicolon, 0);
}


size_t FlingHdlGrammarParser::FlingBehav_ItemContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingBehav_Item;
}


antlrcpp::Any FlingHdlGrammarParser::FlingBehav_ItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingBehav_Item(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingBehav_ItemContext* FlingHdlGrammarParser::flingBehav_Item() {
  FlingBehav_ItemContext *_localctx = _tracker.createInstance<FlingBehav_ItemContext>(_ctx, getState());
  enterRule(_localctx, 68, FlingHdlGrammarParser::RuleFlingBehav_Item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(564);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(550);
      flingBehav_Scope();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(551);
      flingDeclAlias();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(552);
      flingDeclVar();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(553);
      flingDeclConst();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(554);
      flingDeclType();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(555);
      flingBehav_Item_BlkAssign();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(556);
      flingBehav_Item_NonBlkAssign();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(557);
      flingBehav_Item_If();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(558);
      flingBehav_Item_SwitchOrSwitchz();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(559);
      flingBehav_Item_For();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(560);
      flingBehav_Item_While();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(561);
      flingExpr();
      setState(562);
      match(FlingHdlGrammarParser::PunctSemicolon);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingBehav_Item_IfContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingBehav_Item_IfContext::FlingBehav_Item_IfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehav_Item_IfContext::KwIf() {
  return getToken(FlingHdlGrammarParser::KwIf, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingBehav_Item_IfContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

FlingHdlGrammarParser::FlingBehav_ScopeContext* FlingHdlGrammarParser::FlingBehav_Item_IfContext::flingBehav_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_ScopeContext>(0);
}

std::vector<FlingHdlGrammarParser::FlingBehav_Item_If_ElifContext *> FlingHdlGrammarParser::FlingBehav_Item_IfContext::flingBehav_Item_If_Elif() {
  return getRuleContexts<FlingHdlGrammarParser::FlingBehav_Item_If_ElifContext>();
}

FlingHdlGrammarParser::FlingBehav_Item_If_ElifContext* FlingHdlGrammarParser::FlingBehav_Item_IfContext::flingBehav_Item_If_Elif(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_Item_If_ElifContext>(i);
}

FlingHdlGrammarParser::FlingBehav_Item_If_ElseContext* FlingHdlGrammarParser::FlingBehav_Item_IfContext::flingBehav_Item_If_Else() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_Item_If_ElseContext>(0);
}


size_t FlingHdlGrammarParser::FlingBehav_Item_IfContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingBehav_Item_If;
}


antlrcpp::Any FlingHdlGrammarParser::FlingBehav_Item_IfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingBehav_Item_If(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingBehav_Item_IfContext* FlingHdlGrammarParser::flingBehav_Item_If() {
  FlingBehav_Item_IfContext *_localctx = _tracker.createInstance<FlingBehav_Item_IfContext>(_ctx, getState());
  enterRule(_localctx, 70, FlingHdlGrammarParser::RuleFlingBehav_Item_If);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(566);
    match(FlingHdlGrammarParser::KwIf);
    setState(567);
    flingExpr();
    setState(568);
    flingBehav_Scope();
    setState(572);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FlingHdlGrammarParser::KwElif) {
      setState(569);
      flingBehav_Item_If_Elif();
      setState(574);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(576);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::KwElse) {
      setState(575);
      flingBehav_Item_If_Else();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingBehav_Item_If_ElifContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingBehav_Item_If_ElifContext::FlingBehav_Item_If_ElifContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehav_Item_If_ElifContext::KwElif() {
  return getToken(FlingHdlGrammarParser::KwElif, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingBehav_Item_If_ElifContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

FlingHdlGrammarParser::FlingBehav_ScopeContext* FlingHdlGrammarParser::FlingBehav_Item_If_ElifContext::flingBehav_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingBehav_Item_If_ElifContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingBehav_Item_If_Elif;
}


antlrcpp::Any FlingHdlGrammarParser::FlingBehav_Item_If_ElifContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingBehav_Item_If_Elif(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingBehav_Item_If_ElifContext* FlingHdlGrammarParser::flingBehav_Item_If_Elif() {
  FlingBehav_Item_If_ElifContext *_localctx = _tracker.createInstance<FlingBehav_Item_If_ElifContext>(_ctx, getState());
  enterRule(_localctx, 72, FlingHdlGrammarParser::RuleFlingBehav_Item_If_Elif);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(578);
    match(FlingHdlGrammarParser::KwElif);
    setState(579);
    flingExpr();
    setState(580);
    flingBehav_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingBehav_Item_If_ElseContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingBehav_Item_If_ElseContext::FlingBehav_Item_If_ElseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehav_Item_If_ElseContext::KwElse() {
  return getToken(FlingHdlGrammarParser::KwElse, 0);
}

FlingHdlGrammarParser::FlingBehav_ScopeContext* FlingHdlGrammarParser::FlingBehav_Item_If_ElseContext::flingBehav_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingBehav_Item_If_ElseContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingBehav_Item_If_Else;
}


antlrcpp::Any FlingHdlGrammarParser::FlingBehav_Item_If_ElseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingBehav_Item_If_Else(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingBehav_Item_If_ElseContext* FlingHdlGrammarParser::flingBehav_Item_If_Else() {
  FlingBehav_Item_If_ElseContext *_localctx = _tracker.createInstance<FlingBehav_Item_If_ElseContext>(_ctx, getState());
  enterRule(_localctx, 74, FlingHdlGrammarParser::RuleFlingBehav_Item_If_Else);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(582);
    match(FlingHdlGrammarParser::KwElse);
    setState(583);
    flingBehav_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingBehav_Item_SwitchOrSwitchzContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchzContext::FlingBehav_Item_SwitchOrSwitchzContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchzContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchzContext::PunctLBrace() {
  return getToken(FlingHdlGrammarParser::PunctLBrace, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchzContext::PunctRBrace() {
  return getToken(FlingHdlGrammarParser::PunctRBrace, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchzContext::KwSwitch() {
  return getToken(FlingHdlGrammarParser::KwSwitch, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchzContext::KwSwitchz() {
  return getToken(FlingHdlGrammarParser::KwSwitchz, 0);
}

FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_DefaultContext* FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchzContext::flingBehav_Item_SwitchOrSwitchz_Default() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_DefaultContext>(0);
}

std::vector<FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_CaseContext *> FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchzContext::flingBehav_Item_SwitchOrSwitchz_Case() {
  return getRuleContexts<FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_CaseContext>();
}

FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_CaseContext* FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchzContext::flingBehav_Item_SwitchOrSwitchz_Case(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_CaseContext>(i);
}


size_t FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchzContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingBehav_Item_SwitchOrSwitchz;
}


antlrcpp::Any FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchzContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingBehav_Item_SwitchOrSwitchz(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchzContext* FlingHdlGrammarParser::flingBehav_Item_SwitchOrSwitchz() {
  FlingBehav_Item_SwitchOrSwitchzContext *_localctx = _tracker.createInstance<FlingBehav_Item_SwitchOrSwitchzContext>(_ctx, getState());
  enterRule(_localctx, 76, FlingHdlGrammarParser::RuleFlingBehav_Item_SwitchOrSwitchz);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(585);
    _la = _input->LA(1);
    if (!(_la == FlingHdlGrammarParser::KwSwitch

    || _la == FlingHdlGrammarParser::KwSwitchz)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(586);
    flingExpr();
    setState(587);
    match(FlingHdlGrammarParser::PunctLBrace);
    setState(604);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      setState(589);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FlingHdlGrammarParser::KwDefault) {
        setState(588);
        flingBehav_Item_SwitchOrSwitchz_Default();
      }
      setState(594);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << FlingHdlGrammarParser::LitDecNum)
        | (1ULL << FlingHdlGrammarParser::LitHexNum)
        | (1ULL << FlingHdlGrammarParser::LitOctNum)
        | (1ULL << FlingHdlGrammarParser::LitBinNum)
        | (1ULL << FlingHdlGrammarParser::LitFloatNum)
        | (1ULL << FlingHdlGrammarParser::LitString)
        | (1ULL << FlingHdlGrammarParser::PunctPlus)
        | (1ULL << FlingHdlGrammarParser::PunctMinus)
        | (1ULL << FlingHdlGrammarParser::PunctBitOr)
        | (1ULL << FlingHdlGrammarParser::PunctBitNor)
        | (1ULL << FlingHdlGrammarParser::PunctBitAnd)
        | (1ULL << FlingHdlGrammarParser::PunctBitNand)
        | (1ULL << FlingHdlGrammarParser::PunctBitXor)
        | (1ULL << FlingHdlGrammarParser::PunctBitXnor)
        | (1ULL << FlingHdlGrammarParser::PunctBitNot)
        | (1ULL << FlingHdlGrammarParser::PunctLogNot)
        | (1ULL << FlingHdlGrammarParser::PunctLParen)
        | (1ULL << FlingHdlGrammarParser::KwMux))) != 0) || ((((_la - 78) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 78)) & ((1ULL << (FlingHdlGrammarParser::KwLogic - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwInteger - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSizeT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU8 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI8 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU16 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI16 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU32 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI32 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU64 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI64 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU128 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI128 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRetT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwAuto - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRange - 78))
        | (1ULL << (FlingHdlGrammarParser::KwHighZ - 78))
        | (1ULL << (FlingHdlGrammarParser::KwUnkX - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSized - 78))
        | (1ULL << (FlingHdlGrammarParser::KwCat - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRepl - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarSigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarUnsigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarPow - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarClog2 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwVoid - 78))
        | (1ULL << (FlingHdlGrammarParser::KwTypeof - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSelfT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwString - 78))
        | (1ULL << (FlingHdlGrammarParser::MiscIdent - 78)))) != 0)) {
        setState(591);
        flingBehav_Item_SwitchOrSwitchz_Case();
        setState(596);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      setState(598); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(597);
        flingBehav_Item_SwitchOrSwitchz_Case();
        setState(600); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << FlingHdlGrammarParser::LitDecNum)
        | (1ULL << FlingHdlGrammarParser::LitHexNum)
        | (1ULL << FlingHdlGrammarParser::LitOctNum)
        | (1ULL << FlingHdlGrammarParser::LitBinNum)
        | (1ULL << FlingHdlGrammarParser::LitFloatNum)
        | (1ULL << FlingHdlGrammarParser::LitString)
        | (1ULL << FlingHdlGrammarParser::PunctPlus)
        | (1ULL << FlingHdlGrammarParser::PunctMinus)
        | (1ULL << FlingHdlGrammarParser::PunctBitOr)
        | (1ULL << FlingHdlGrammarParser::PunctBitNor)
        | (1ULL << FlingHdlGrammarParser::PunctBitAnd)
        | (1ULL << FlingHdlGrammarParser::PunctBitNand)
        | (1ULL << FlingHdlGrammarParser::PunctBitXor)
        | (1ULL << FlingHdlGrammarParser::PunctBitXnor)
        | (1ULL << FlingHdlGrammarParser::PunctBitNot)
        | (1ULL << FlingHdlGrammarParser::PunctLogNot)
        | (1ULL << FlingHdlGrammarParser::PunctLParen)
        | (1ULL << FlingHdlGrammarParser::KwMux))) != 0) || ((((_la - 78) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 78)) & ((1ULL << (FlingHdlGrammarParser::KwLogic - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwInteger - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSizeT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU8 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI8 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU16 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI16 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU32 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI32 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU64 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI64 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU128 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI128 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRetT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwAuto - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRange - 78))
        | (1ULL << (FlingHdlGrammarParser::KwHighZ - 78))
        | (1ULL << (FlingHdlGrammarParser::KwUnkX - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSized - 78))
        | (1ULL << (FlingHdlGrammarParser::KwCat - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRepl - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarSigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarUnsigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarPow - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarClog2 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwVoid - 78))
        | (1ULL << (FlingHdlGrammarParser::KwTypeof - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSelfT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwString - 78))
        | (1ULL << (FlingHdlGrammarParser::MiscIdent - 78)))) != 0));
      setState(602);
      flingBehav_Item_SwitchOrSwitchz_Default();
      break;
    }

    }
    setState(606);
    match(FlingHdlGrammarParser::PunctRBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingBehav_Item_SwitchOrSwitchz_DefaultContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_DefaultContext::FlingBehav_Item_SwitchOrSwitchz_DefaultContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_DefaultContext::KwDefault() {
  return getToken(FlingHdlGrammarParser::KwDefault, 0);
}

FlingHdlGrammarParser::FlingBehav_ScopeContext* FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_DefaultContext::flingBehav_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_DefaultContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingBehav_Item_SwitchOrSwitchz_Default;
}


antlrcpp::Any FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_DefaultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingBehav_Item_SwitchOrSwitchz_Default(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_DefaultContext* FlingHdlGrammarParser::flingBehav_Item_SwitchOrSwitchz_Default() {
  FlingBehav_Item_SwitchOrSwitchz_DefaultContext *_localctx = _tracker.createInstance<FlingBehav_Item_SwitchOrSwitchz_DefaultContext>(_ctx, getState());
  enterRule(_localctx, 78, FlingHdlGrammarParser::RuleFlingBehav_Item_SwitchOrSwitchz_Default);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(608);
    match(FlingHdlGrammarParser::KwDefault);
    setState(609);
    flingBehav_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingBehav_Item_SwitchOrSwitchz_CaseContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_CaseContext::FlingBehav_Item_SwitchOrSwitchz_CaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExprListContext* FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_CaseContext::flingExprList() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprListContext>(0);
}

FlingHdlGrammarParser::FlingBehav_ScopeContext* FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_CaseContext::flingBehav_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_CaseContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingBehav_Item_SwitchOrSwitchz_Case;
}


antlrcpp::Any FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_CaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingBehav_Item_SwitchOrSwitchz_Case(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingBehav_Item_SwitchOrSwitchz_CaseContext* FlingHdlGrammarParser::flingBehav_Item_SwitchOrSwitchz_Case() {
  FlingBehav_Item_SwitchOrSwitchz_CaseContext *_localctx = _tracker.createInstance<FlingBehav_Item_SwitchOrSwitchz_CaseContext>(_ctx, getState());
  enterRule(_localctx, 80, FlingHdlGrammarParser::RuleFlingBehav_Item_SwitchOrSwitchz_Case);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(611);
    flingExprList();
    setState(612);
    flingBehav_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingBehav_Item_ForContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingBehav_Item_ForContext::FlingBehav_Item_ForContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehav_Item_ForContext::KwFor() {
  return getToken(FlingHdlGrammarParser::KwFor, 0);
}

FlingHdlGrammarParser::FlingIdentContext* FlingHdlGrammarParser::FlingBehav_Item_ForContext::flingIdent() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehav_Item_ForContext::PunctColon() {
  return getToken(FlingHdlGrammarParser::PunctColon, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingBehav_Item_ForContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

FlingHdlGrammarParser::FlingBehav_ScopeContext* FlingHdlGrammarParser::FlingBehav_Item_ForContext::flingBehav_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingBehav_Item_ForContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingBehav_Item_For;
}


antlrcpp::Any FlingHdlGrammarParser::FlingBehav_Item_ForContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingBehav_Item_For(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingBehav_Item_ForContext* FlingHdlGrammarParser::flingBehav_Item_For() {
  FlingBehav_Item_ForContext *_localctx = _tracker.createInstance<FlingBehav_Item_ForContext>(_ctx, getState());
  enterRule(_localctx, 82, FlingHdlGrammarParser::RuleFlingBehav_Item_For);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(614);
    match(FlingHdlGrammarParser::KwFor);
    setState(615);
    flingIdent();
    setState(616);
    match(FlingHdlGrammarParser::PunctColon);
    setState(617);
    flingExpr();
    setState(618);
    flingBehav_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingBehav_Item_WhileContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingBehav_Item_WhileContext::FlingBehav_Item_WhileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehav_Item_WhileContext::KwWhile() {
  return getToken(FlingHdlGrammarParser::KwWhile, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingBehav_Item_WhileContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

FlingHdlGrammarParser::FlingBehav_ScopeContext* FlingHdlGrammarParser::FlingBehav_Item_WhileContext::flingBehav_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingBehav_Item_WhileContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingBehav_Item_While;
}


antlrcpp::Any FlingHdlGrammarParser::FlingBehav_Item_WhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingBehav_Item_While(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingBehav_Item_WhileContext* FlingHdlGrammarParser::flingBehav_Item_While() {
  FlingBehav_Item_WhileContext *_localctx = _tracker.createInstance<FlingBehav_Item_WhileContext>(_ctx, getState());
  enterRule(_localctx, 84, FlingHdlGrammarParser::RuleFlingBehav_Item_While);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(620);
    match(FlingHdlGrammarParser::KwWhile);
    setState(621);
    flingExpr();
    setState(622);
    flingBehav_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingBehav_Item_NonBlkAssignContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingBehav_Item_NonBlkAssignContext::FlingBehav_Item_NonBlkAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FlingHdlGrammarParser::FlingExprContext *> FlingHdlGrammarParser::FlingBehav_Item_NonBlkAssignContext::flingExpr() {
  return getRuleContexts<FlingHdlGrammarParser::FlingExprContext>();
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingBehav_Item_NonBlkAssignContext::flingExpr(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(i);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehav_Item_NonBlkAssignContext::PunctNonBlkAssign() {
  return getToken(FlingHdlGrammarParser::PunctNonBlkAssign, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehav_Item_NonBlkAssignContext::PunctSemicolon() {
  return getToken(FlingHdlGrammarParser::PunctSemicolon, 0);
}


size_t FlingHdlGrammarParser::FlingBehav_Item_NonBlkAssignContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingBehav_Item_NonBlkAssign;
}


antlrcpp::Any FlingHdlGrammarParser::FlingBehav_Item_NonBlkAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingBehav_Item_NonBlkAssign(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingBehav_Item_NonBlkAssignContext* FlingHdlGrammarParser::flingBehav_Item_NonBlkAssign() {
  FlingBehav_Item_NonBlkAssignContext *_localctx = _tracker.createInstance<FlingBehav_Item_NonBlkAssignContext>(_ctx, getState());
  enterRule(_localctx, 86, FlingHdlGrammarParser::RuleFlingBehav_Item_NonBlkAssign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(624);
    flingExpr();
    setState(625);
    match(FlingHdlGrammarParser::PunctNonBlkAssign);
    setState(626);
    flingExpr();
    setState(627);
    match(FlingHdlGrammarParser::PunctSemicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingBehav_Item_BlkAssignContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingBehav_Item_BlkAssignContext::FlingBehav_Item_BlkAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FlingHdlGrammarParser::FlingExprContext *> FlingHdlGrammarParser::FlingBehav_Item_BlkAssignContext::flingExpr() {
  return getRuleContexts<FlingHdlGrammarParser::FlingExprContext>();
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingBehav_Item_BlkAssignContext::flingExpr(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(i);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehav_Item_BlkAssignContext::PunctBlkAssign() {
  return getToken(FlingHdlGrammarParser::PunctBlkAssign, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingBehav_Item_BlkAssignContext::PunctSemicolon() {
  return getToken(FlingHdlGrammarParser::PunctSemicolon, 0);
}


size_t FlingHdlGrammarParser::FlingBehav_Item_BlkAssignContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingBehav_Item_BlkAssign;
}


antlrcpp::Any FlingHdlGrammarParser::FlingBehav_Item_BlkAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingBehav_Item_BlkAssign(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingBehav_Item_BlkAssignContext* FlingHdlGrammarParser::flingBehav_Item_BlkAssign() {
  FlingBehav_Item_BlkAssignContext *_localctx = _tracker.createInstance<FlingBehav_Item_BlkAssignContext>(_ctx, getState());
  enterRule(_localctx, 88, FlingHdlGrammarParser::RuleFlingBehav_Item_BlkAssign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(629);
    flingExpr();
    setState(630);
    match(FlingHdlGrammarParser::PunctBlkAssign);
    setState(631);
    flingExpr();
    setState(632);
    match(FlingHdlGrammarParser::PunctSemicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclWireContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclWireContext::FlingDeclWireContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingIdentListContext* FlingHdlGrammarParser::FlingDeclWireContext::flingIdentList() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentListContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclWireContext::PunctColon() {
  return getToken(FlingHdlGrammarParser::PunctColon, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclWireContext::KwWire() {
  return getToken(FlingHdlGrammarParser::KwWire, 0);
}

FlingHdlGrammarParser::FlingTypenameOrModnameContext* FlingHdlGrammarParser::FlingDeclWireContext::flingTypenameOrModname() {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModnameContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclWireContext::PunctSemicolon() {
  return getToken(FlingHdlGrammarParser::PunctSemicolon, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclWireContext::PunctBlkAssign() {
  return getToken(FlingHdlGrammarParser::PunctBlkAssign, 0);
}

FlingHdlGrammarParser::FlingExprListContext* FlingHdlGrammarParser::FlingDeclWireContext::flingExprList() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprListContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclWireContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclWire;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclWireContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclWire(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclWireContext* FlingHdlGrammarParser::flingDeclWire() {
  FlingDeclWireContext *_localctx = _tracker.createInstance<FlingDeclWireContext>(_ctx, getState());
  enterRule(_localctx, 90, FlingHdlGrammarParser::RuleFlingDeclWire);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(634);
    flingIdentList();
    setState(635);
    match(FlingHdlGrammarParser::PunctColon);
    setState(636);
    match(FlingHdlGrammarParser::KwWire);
    setState(637);
    flingTypenameOrModname();
    setState(640);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::PunctBlkAssign) {
      setState(638);
      match(FlingHdlGrammarParser::PunctBlkAssign);
      setState(639);
      flingExprList();
    }
    setState(642);
    match(FlingHdlGrammarParser::PunctSemicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclVarContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclVarContext::FlingDeclVarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingIdentListContext* FlingHdlGrammarParser::FlingDeclVarContext::flingIdentList() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentListContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclVarContext::PunctColon() {
  return getToken(FlingHdlGrammarParser::PunctColon, 0);
}

FlingHdlGrammarParser::FlingTypenameOrModnameContext* FlingHdlGrammarParser::FlingDeclVarContext::flingTypenameOrModname() {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModnameContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclVarContext::PunctSemicolon() {
  return getToken(FlingHdlGrammarParser::PunctSemicolon, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclVarContext::PunctBlkAssign() {
  return getToken(FlingHdlGrammarParser::PunctBlkAssign, 0);
}

FlingHdlGrammarParser::FlingExprListContext* FlingHdlGrammarParser::FlingDeclVarContext::flingExprList() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprListContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclVarContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclVar;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclVar(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclVarContext* FlingHdlGrammarParser::flingDeclVar() {
  FlingDeclVarContext *_localctx = _tracker.createInstance<FlingDeclVarContext>(_ctx, getState());
  enterRule(_localctx, 92, FlingHdlGrammarParser::RuleFlingDeclVar);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(644);
    flingIdentList();
    setState(645);
    match(FlingHdlGrammarParser::PunctColon);
    setState(646);
    flingTypenameOrModname();
    setState(649);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::PunctBlkAssign) {
      setState(647);
      match(FlingHdlGrammarParser::PunctBlkAssign);
      setState(648);
      flingExprList();
    }
    setState(651);
    match(FlingHdlGrammarParser::PunctSemicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclConstContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclConstContext::FlingDeclConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingIdentListContext* FlingHdlGrammarParser::FlingDeclConstContext::flingIdentList() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentListContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclConstContext::PunctColon() {
  return getToken(FlingHdlGrammarParser::PunctColon, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclConstContext::KwConst() {
  return getToken(FlingHdlGrammarParser::KwConst, 0);
}

FlingHdlGrammarParser::FlingTypenameOrModnameContext* FlingHdlGrammarParser::FlingDeclConstContext::flingTypenameOrModname() {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModnameContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclConstContext::PunctBlkAssign() {
  return getToken(FlingHdlGrammarParser::PunctBlkAssign, 0);
}

FlingHdlGrammarParser::FlingExprListContext* FlingHdlGrammarParser::FlingDeclConstContext::flingExprList() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprListContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclConstContext::PunctSemicolon() {
  return getToken(FlingHdlGrammarParser::PunctSemicolon, 0);
}


size_t FlingHdlGrammarParser::FlingDeclConstContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclConst;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclConst(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclConstContext* FlingHdlGrammarParser::flingDeclConst() {
  FlingDeclConstContext *_localctx = _tracker.createInstance<FlingDeclConstContext>(_ctx, getState());
  enterRule(_localctx, 94, FlingHdlGrammarParser::RuleFlingDeclConst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(653);
    flingIdentList();
    setState(654);
    match(FlingHdlGrammarParser::PunctColon);
    setState(655);
    match(FlingHdlGrammarParser::KwConst);
    setState(656);
    flingTypenameOrModname();
    setState(657);
    match(FlingHdlGrammarParser::PunctBlkAssign);
    setState(658);
    flingExprList();
    setState(659);
    match(FlingHdlGrammarParser::PunctSemicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclTypeContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclTypeContext::FlingDeclTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingDeclEnumContext* FlingHdlGrammarParser::FlingDeclTypeContext::flingDeclEnum() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclEnumContext>(0);
}

FlingHdlGrammarParser::FlingDeclClassContext* FlingHdlGrammarParser::FlingDeclTypeContext::flingDeclClass() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclClassContext>(0);
}

FlingHdlGrammarParser::FlingDeclMixinContext* FlingHdlGrammarParser::FlingDeclTypeContext::flingDeclMixin() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclMixinContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclTypeContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclType;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclType(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclTypeContext* FlingHdlGrammarParser::flingDeclType() {
  FlingDeclTypeContext *_localctx = _tracker.createInstance<FlingDeclTypeContext>(_ctx, getState());
  enterRule(_localctx, 96, FlingHdlGrammarParser::RuleFlingDeclType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(664);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(661);
      flingDeclEnum();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(662);
      flingDeclClass();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(663);
      flingDeclMixin();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclEnumContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclEnumContext::FlingDeclEnumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclEnumContext::KwEnum() {
  return getToken(FlingHdlGrammarParser::KwEnum, 0);
}

FlingHdlGrammarParser::FlingIdentContext* FlingHdlGrammarParser::FlingDeclEnumContext::flingIdent() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclEnumContext::PunctLBrace() {
  return getToken(FlingHdlGrammarParser::PunctLBrace, 0);
}

FlingHdlGrammarParser::FlingIdentListContext* FlingHdlGrammarParser::FlingDeclEnumContext::flingIdentList() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentListContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclEnumContext::PunctRBrace() {
  return getToken(FlingHdlGrammarParser::PunctRBrace, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclEnumContext::PunctColon() {
  return getToken(FlingHdlGrammarParser::PunctColon, 0);
}

FlingHdlGrammarParser::FlingTypenameOrModnameContext* FlingHdlGrammarParser::FlingDeclEnumContext::flingTypenameOrModname() {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModnameContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclEnumContext::PunctComma() {
  return getToken(FlingHdlGrammarParser::PunctComma, 0);
}


size_t FlingHdlGrammarParser::FlingDeclEnumContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclEnum;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclEnumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclEnum(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclEnumContext* FlingHdlGrammarParser::flingDeclEnum() {
  FlingDeclEnumContext *_localctx = _tracker.createInstance<FlingDeclEnumContext>(_ctx, getState());
  enterRule(_localctx, 98, FlingHdlGrammarParser::RuleFlingDeclEnum);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(666);
    match(FlingHdlGrammarParser::KwEnum);
    setState(667);
    flingIdent();
    setState(670);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::PunctColon) {
      setState(668);
      match(FlingHdlGrammarParser::PunctColon);
      setState(669);
      flingTypenameOrModname();
    }
    setState(672);
    match(FlingHdlGrammarParser::PunctLBrace);
    setState(673);
    flingIdentList();
    setState(675);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::PunctComma) {
      setState(674);
      match(FlingHdlGrammarParser::PunctComma);
    }
    setState(677);
    match(FlingHdlGrammarParser::PunctRBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclClassContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclClassContext::FlingDeclClassContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclClassContext::KwClass() {
  return getToken(FlingHdlGrammarParser::KwClass, 0);
}

FlingHdlGrammarParser::FlingIdentContext* FlingHdlGrammarParser::FlingDeclClassContext::flingIdent() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentContext>(0);
}

FlingHdlGrammarParser::FlingDeclParamListContext* FlingHdlGrammarParser::FlingDeclClassContext::flingDeclParamList() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclParamListContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclClassContext::PunctLBrace() {
  return getToken(FlingHdlGrammarParser::PunctLBrace, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclClassContext::PunctRBrace() {
  return getToken(FlingHdlGrammarParser::PunctRBrace, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclClassContext::KwBase() {
  return getToken(FlingHdlGrammarParser::KwBase, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclClassContext::KwPacked() {
  return getToken(FlingHdlGrammarParser::KwPacked, 0);
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_ExtendsContext* FlingHdlGrammarParser::FlingDeclClassContext::flingDeclClsOrMxn_Extends() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclClsOrMxn_ExtendsContext>(0);
}

std::vector<FlingHdlGrammarParser::FlingDeclClass_ItemContext *> FlingHdlGrammarParser::FlingDeclClassContext::flingDeclClass_Item() {
  return getRuleContexts<FlingHdlGrammarParser::FlingDeclClass_ItemContext>();
}

FlingHdlGrammarParser::FlingDeclClass_ItemContext* FlingHdlGrammarParser::FlingDeclClassContext::flingDeclClass_Item(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclClass_ItemContext>(i);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclClassContext::KwSigned() {
  return getToken(FlingHdlGrammarParser::KwSigned, 0);
}


size_t FlingHdlGrammarParser::FlingDeclClassContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclClass;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclClassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclClass(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclClassContext* FlingHdlGrammarParser::flingDeclClass() {
  FlingDeclClassContext *_localctx = _tracker.createInstance<FlingDeclClassContext>(_ctx, getState());
  enterRule(_localctx, 100, FlingHdlGrammarParser::RuleFlingDeclClass);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(680);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::KwBase) {
      setState(679);
      match(FlingHdlGrammarParser::KwBase);
    }
    setState(682);
    match(FlingHdlGrammarParser::KwClass);
    setState(687);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::KwSigned

    || _la == FlingHdlGrammarParser::KwPacked) {
      setState(684);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FlingHdlGrammarParser::KwSigned) {
        setState(683);
        match(FlingHdlGrammarParser::KwSigned);
      }
      setState(686);
      match(FlingHdlGrammarParser::KwPacked);
    }
    setState(689);
    flingIdent();
    setState(690);
    flingDeclParamList();
    setState(692);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::KwExtends) {
      setState(691);
      flingDeclClsOrMxn_Extends();
    }
    setState(694);
    match(FlingHdlGrammarParser::PunctLBrace);
    setState(698);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 73) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 73)) & ((1ULL << (FlingHdlGrammarParser::KwFunc - 73))
      | (1ULL << (FlingHdlGrammarParser::KwTask - 73))
      | (1ULL << (FlingHdlGrammarParser::KwImport - 73))
      | (1ULL << (FlingHdlGrammarParser::KwConst - 73))
      | (1ULL << (FlingHdlGrammarParser::KwAlias - 73))
      | (1ULL << (FlingHdlGrammarParser::KwEnum - 73))
      | (1ULL << (FlingHdlGrammarParser::KwClass - 73))
      | (1ULL << (FlingHdlGrammarParser::KwMixin - 73))
      | (1ULL << (FlingHdlGrammarParser::KwVirtual - 73))
      | (1ULL << (FlingHdlGrammarParser::KwAbstract - 73))
      | (1ULL << (FlingHdlGrammarParser::KwBase - 73))
      | (1ULL << (FlingHdlGrammarParser::KwStatic - 73))
      | (1ULL << (FlingHdlGrammarParser::KwProc - 73))
      | (1ULL << (FlingHdlGrammarParser::KwPub - 73))
      | (1ULL << (FlingHdlGrammarParser::KwProt - 73))
      | (1ULL << (FlingHdlGrammarParser::KwPriv - 73)))) != 0) || _la == FlingHdlGrammarParser::MiscIdent) {
      setState(695);
      flingDeclClass_Item();
      setState(700);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(701);
    match(FlingHdlGrammarParser::PunctRBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclClsOrMxn_ExtendsContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclClsOrMxn_ExtendsContext::FlingDeclClsOrMxn_ExtendsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclClsOrMxn_ExtendsContext::KwExtends() {
  return getToken(FlingHdlGrammarParser::KwExtends, 0);
}

FlingHdlGrammarParser::FlingTypenameOrModnameListContext* FlingHdlGrammarParser::FlingDeclClsOrMxn_ExtendsContext::flingTypenameOrModnameList() {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModnameListContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclClsOrMxn_ExtendsContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclClsOrMxn_Extends;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclClsOrMxn_ExtendsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclClsOrMxn_Extends(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_ExtendsContext* FlingHdlGrammarParser::flingDeclClsOrMxn_Extends() {
  FlingDeclClsOrMxn_ExtendsContext *_localctx = _tracker.createInstance<FlingDeclClsOrMxn_ExtendsContext>(_ctx, getState());
  enterRule(_localctx, 102, FlingHdlGrammarParser::RuleFlingDeclClsOrMxn_Extends);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(703);
    match(FlingHdlGrammarParser::KwExtends);
    setState(704);
    flingTypenameOrModnameList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclClass_ItemContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclClass_ItemContext::FlingDeclClass_ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingDeclClass_Item_DeclVarContext* FlingHdlGrammarParser::FlingDeclClass_ItemContext::flingDeclClass_Item_DeclVar() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclClass_Item_DeclVarContext>(0);
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_ItemContext* FlingHdlGrammarParser::FlingDeclClass_ItemContext::flingDeclClsOrMxn_Item() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclClsOrMxn_ItemContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclClass_ItemContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclClass_Item;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclClass_ItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclClass_Item(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclClass_ItemContext* FlingHdlGrammarParser::flingDeclClass_Item() {
  FlingDeclClass_ItemContext *_localctx = _tracker.createInstance<FlingDeclClass_ItemContext>(_ctx, getState());
  enterRule(_localctx, 104, FlingHdlGrammarParser::RuleFlingDeclClass_Item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(708);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(706);
      flingDeclClass_Item_DeclVar();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(707);
      flingDeclClsOrMxn_Item();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclClass_Item_DeclVarContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclClass_Item_DeclVarContext::FlingDeclClass_Item_DeclVarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingDeclVarContext* FlingHdlGrammarParser::FlingDeclClass_Item_DeclVarContext::flingDeclVar() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclVarContext>(0);
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_AccessSpecifierContext* FlingHdlGrammarParser::FlingDeclClass_Item_DeclVarContext::flingDeclClsOrMxn_AccessSpecifier() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclClsOrMxn_AccessSpecifierContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclClass_Item_DeclVarContext::KwStatic() {
  return getToken(FlingHdlGrammarParser::KwStatic, 0);
}


size_t FlingHdlGrammarParser::FlingDeclClass_Item_DeclVarContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclClass_Item_DeclVar;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclClass_Item_DeclVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclClass_Item_DeclVar(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclClass_Item_DeclVarContext* FlingHdlGrammarParser::flingDeclClass_Item_DeclVar() {
  FlingDeclClass_Item_DeclVarContext *_localctx = _tracker.createInstance<FlingDeclClass_Item_DeclVarContext>(_ctx, getState());
  enterRule(_localctx, 106, FlingHdlGrammarParser::RuleFlingDeclClass_Item_DeclVar);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(711);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 133) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 133)) & ((1ULL << (FlingHdlGrammarParser::KwPub - 133))
      | (1ULL << (FlingHdlGrammarParser::KwProt - 133))
      | (1ULL << (FlingHdlGrammarParser::KwPriv - 133)))) != 0)) {
      setState(710);
      flingDeclClsOrMxn_AccessSpecifier();
    }
    setState(714);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::KwStatic) {
      setState(713);
      match(FlingHdlGrammarParser::KwStatic);
    }
    setState(716);
    flingDeclVar();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclClsOrMxn_ItemContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclClsOrMxn_ItemContext::FlingDeclClsOrMxn_ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclTypeContext* FlingHdlGrammarParser::FlingDeclClsOrMxn_ItemContext::flingDeclClsOrMxn_Item_DeclType() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclTypeContext>(0);
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclAliasOrConstContext* FlingHdlGrammarParser::FlingDeclClsOrMxn_ItemContext::flingDeclClsOrMxn_Item_DeclAliasOrConst() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclAliasOrConstContext>(0);
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprogContext* FlingHdlGrammarParser::FlingDeclClsOrMxn_ItemContext::flingDeclClsOrMxn_Item_DeclSubprog() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprogContext>(0);
}

FlingHdlGrammarParser::FlingImportListContext* FlingHdlGrammarParser::FlingDeclClsOrMxn_ItemContext::flingImportList() {
  return getRuleContext<FlingHdlGrammarParser::FlingImportListContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclClsOrMxn_ItemContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclClsOrMxn_Item;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclClsOrMxn_ItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclClsOrMxn_Item(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_ItemContext* FlingHdlGrammarParser::flingDeclClsOrMxn_Item() {
  FlingDeclClsOrMxn_ItemContext *_localctx = _tracker.createInstance<FlingDeclClsOrMxn_ItemContext>(_ctx, getState());
  enterRule(_localctx, 108, FlingHdlGrammarParser::RuleFlingDeclClsOrMxn_Item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(722);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(718);
      flingDeclClsOrMxn_Item_DeclType();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(719);
      flingDeclClsOrMxn_Item_DeclAliasOrConst();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(720);
      flingDeclClsOrMxn_Item_DeclSubprog();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(721);
      flingImportList();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclClsOrMxn_Item_DeclTypeContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclTypeContext::FlingDeclClsOrMxn_Item_DeclTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingDeclTypeContext* FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclTypeContext::flingDeclType() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTypeContext>(0);
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_AccessSpecifierContext* FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclTypeContext::flingDeclClsOrMxn_AccessSpecifier() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclClsOrMxn_AccessSpecifierContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclTypeContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclClsOrMxn_Item_DeclType;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclClsOrMxn_Item_DeclType(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclTypeContext* FlingHdlGrammarParser::flingDeclClsOrMxn_Item_DeclType() {
  FlingDeclClsOrMxn_Item_DeclTypeContext *_localctx = _tracker.createInstance<FlingDeclClsOrMxn_Item_DeclTypeContext>(_ctx, getState());
  enterRule(_localctx, 110, FlingHdlGrammarParser::RuleFlingDeclClsOrMxn_Item_DeclType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(725);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 133) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 133)) & ((1ULL << (FlingHdlGrammarParser::KwPub - 133))
      | (1ULL << (FlingHdlGrammarParser::KwProt - 133))
      | (1ULL << (FlingHdlGrammarParser::KwPriv - 133)))) != 0)) {
      setState(724);
      flingDeclClsOrMxn_AccessSpecifier();
    }
    setState(727);
    flingDeclType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclClsOrMxn_Item_DeclAliasOrConstContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclAliasOrConstContext::FlingDeclClsOrMxn_Item_DeclAliasOrConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingDeclAliasContext* FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclAliasOrConstContext::flingDeclAlias() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclAliasContext>(0);
}

FlingHdlGrammarParser::FlingDeclConstContext* FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclAliasOrConstContext::flingDeclConst() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclConstContext>(0);
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_AccessSpecifierContext* FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclAliasOrConstContext::flingDeclClsOrMxn_AccessSpecifier() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclClsOrMxn_AccessSpecifierContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclAliasOrConstContext::KwStatic() {
  return getToken(FlingHdlGrammarParser::KwStatic, 0);
}


size_t FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclAliasOrConstContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclClsOrMxn_Item_DeclAliasOrConst;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclAliasOrConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclClsOrMxn_Item_DeclAliasOrConst(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclAliasOrConstContext* FlingHdlGrammarParser::flingDeclClsOrMxn_Item_DeclAliasOrConst() {
  FlingDeclClsOrMxn_Item_DeclAliasOrConstContext *_localctx = _tracker.createInstance<FlingDeclClsOrMxn_Item_DeclAliasOrConstContext>(_ctx, getState());
  enterRule(_localctx, 112, FlingHdlGrammarParser::RuleFlingDeclClsOrMxn_Item_DeclAliasOrConst);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(730);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 133) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 133)) & ((1ULL << (FlingHdlGrammarParser::KwPub - 133))
      | (1ULL << (FlingHdlGrammarParser::KwProt - 133))
      | (1ULL << (FlingHdlGrammarParser::KwPriv - 133)))) != 0)) {
      setState(729);
      flingDeclClsOrMxn_AccessSpecifier();
    }
    setState(733);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::KwStatic) {
      setState(732);
      match(FlingHdlGrammarParser::KwStatic);
    }
    setState(737);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FlingHdlGrammarParser::KwAlias: {
        setState(735);
        flingDeclAlias();
        break;
      }

      case FlingHdlGrammarParser::MiscIdent: {
        setState(736);
        flingDeclConst();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclClsOrMxn_AccessSpecifierContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclClsOrMxn_AccessSpecifierContext::FlingDeclClsOrMxn_AccessSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclClsOrMxn_AccessSpecifierContext::KwPub() {
  return getToken(FlingHdlGrammarParser::KwPub, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclClsOrMxn_AccessSpecifierContext::KwProt() {
  return getToken(FlingHdlGrammarParser::KwProt, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclClsOrMxn_AccessSpecifierContext::KwPriv() {
  return getToken(FlingHdlGrammarParser::KwPriv, 0);
}


size_t FlingHdlGrammarParser::FlingDeclClsOrMxn_AccessSpecifierContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclClsOrMxn_AccessSpecifier;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclClsOrMxn_AccessSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclClsOrMxn_AccessSpecifier(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_AccessSpecifierContext* FlingHdlGrammarParser::flingDeclClsOrMxn_AccessSpecifier() {
  FlingDeclClsOrMxn_AccessSpecifierContext *_localctx = _tracker.createInstance<FlingDeclClsOrMxn_AccessSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 114, FlingHdlGrammarParser::RuleFlingDeclClsOrMxn_AccessSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(739);
    _la = _input->LA(1);
    if (!(((((_la - 133) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 133)) & ((1ULL << (FlingHdlGrammarParser::KwPub - 133))
      | (1ULL << (FlingHdlGrammarParser::KwProt - 133))
      | (1ULL << (FlingHdlGrammarParser::KwPriv - 133)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclClsOrMxn_Item_DeclSubprogContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprogContext::FlingDeclClsOrMxn_Item_DeclSubprogContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext* FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprogContext::flingDeclClsOrMxn_Item_DeclSubprog_FullDefn() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext>(0);
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext* FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprogContext::flingDeclClsOrMxn_Item_DeclSubprog_Abstract() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprogContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclClsOrMxn_Item_DeclSubprog;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprogContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclClsOrMxn_Item_DeclSubprog(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprogContext* FlingHdlGrammarParser::flingDeclClsOrMxn_Item_DeclSubprog() {
  FlingDeclClsOrMxn_Item_DeclSubprogContext *_localctx = _tracker.createInstance<FlingDeclClsOrMxn_Item_DeclSubprogContext>(_ctx, getState());
  enterRule(_localctx, 116, FlingHdlGrammarParser::RuleFlingDeclClsOrMxn_Item_DeclSubprog);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(743);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(741);
      flingDeclClsOrMxn_Item_DeclSubprog_FullDefn();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(742);
      flingDeclClsOrMxn_Item_DeclSubprog_Abstract();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext::FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingDeclSubprogContext* FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext::flingDeclSubprog() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclSubprogContext>(0);
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_AccessSpecifierContext* FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext::flingDeclClsOrMxn_AccessSpecifier() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclClsOrMxn_AccessSpecifierContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext::KwConst() {
  return getToken(FlingHdlGrammarParser::KwConst, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext::KwVirtual() {
  return getToken(FlingHdlGrammarParser::KwVirtual, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext::KwStatic() {
  return getToken(FlingHdlGrammarParser::KwStatic, 0);
}


size_t FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclClsOrMxn_Item_DeclSubprog_FullDefn;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclClsOrMxn_Item_DeclSubprog_FullDefn(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext* FlingHdlGrammarParser::flingDeclClsOrMxn_Item_DeclSubprog_FullDefn() {
  FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext *_localctx = _tracker.createInstance<FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext>(_ctx, getState());
  enterRule(_localctx, 118, FlingHdlGrammarParser::RuleFlingDeclClsOrMxn_Item_DeclSubprog_FullDefn);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(746);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 133) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 133)) & ((1ULL << (FlingHdlGrammarParser::KwPub - 133))
      | (1ULL << (FlingHdlGrammarParser::KwProt - 133))
      | (1ULL << (FlingHdlGrammarParser::KwPriv - 133)))) != 0)) {
      setState(745);
      flingDeclClsOrMxn_AccessSpecifier();
    }
    setState(749);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::KwVirtual

    || _la == FlingHdlGrammarParser::KwStatic) {
      setState(748);
      _la = _input->LA(1);
      if (!(_la == FlingHdlGrammarParser::KwVirtual

      || _la == FlingHdlGrammarParser::KwStatic)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(752);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::KwConst) {
      setState(751);
      match(FlingHdlGrammarParser::KwConst);
    }
    setState(754);
    flingDeclSubprog();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext::FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext::KwAbstract() {
  return getToken(FlingHdlGrammarParser::KwAbstract, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext::PunctSemicolon() {
  return getToken(FlingHdlGrammarParser::PunctSemicolon, 0);
}

FlingHdlGrammarParser::FlingDeclFunc_HeaderContext* FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext::flingDeclFunc_Header() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclFunc_HeaderContext>(0);
}

FlingHdlGrammarParser::FlingDeclTask_HeaderContext* FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext::flingDeclTask_Header() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTask_HeaderContext>(0);
}

FlingHdlGrammarParser::FlingDeclProc_HeaderContext* FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext::flingDeclProc_Header() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclProc_HeaderContext>(0);
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_AccessSpecifierContext* FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext::flingDeclClsOrMxn_AccessSpecifier() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclClsOrMxn_AccessSpecifierContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext::KwConst() {
  return getToken(FlingHdlGrammarParser::KwConst, 0);
}


size_t FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclClsOrMxn_Item_DeclSubprog_Abstract;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclClsOrMxn_Item_DeclSubprog_Abstract(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext* FlingHdlGrammarParser::flingDeclClsOrMxn_Item_DeclSubprog_Abstract() {
  FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext *_localctx = _tracker.createInstance<FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext>(_ctx, getState());
  enterRule(_localctx, 120, FlingHdlGrammarParser::RuleFlingDeclClsOrMxn_Item_DeclSubprog_Abstract);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(757);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 133) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 133)) & ((1ULL << (FlingHdlGrammarParser::KwPub - 133))
      | (1ULL << (FlingHdlGrammarParser::KwProt - 133))
      | (1ULL << (FlingHdlGrammarParser::KwPriv - 133)))) != 0)) {
      setState(756);
      flingDeclClsOrMxn_AccessSpecifier();
    }
    setState(759);
    match(FlingHdlGrammarParser::KwAbstract);
    setState(761);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::KwConst) {
      setState(760);
      match(FlingHdlGrammarParser::KwConst);
    }
    setState(766);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FlingHdlGrammarParser::KwFunc: {
        setState(763);
        flingDeclFunc_Header();
        break;
      }

      case FlingHdlGrammarParser::KwTask: {
        setState(764);
        flingDeclTask_Header();
        break;
      }

      case FlingHdlGrammarParser::KwProc: {
        setState(765);
        flingDeclProc_Header();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(768);
    match(FlingHdlGrammarParser::PunctSemicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclMixinContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclMixinContext::FlingDeclMixinContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclMixinContext::KwMixin() {
  return getToken(FlingHdlGrammarParser::KwMixin, 0);
}

FlingHdlGrammarParser::FlingIdentContext* FlingHdlGrammarParser::FlingDeclMixinContext::flingIdent() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentContext>(0);
}

FlingHdlGrammarParser::FlingDeclParamListContext* FlingHdlGrammarParser::FlingDeclMixinContext::flingDeclParamList() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclParamListContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclMixinContext::PunctLBrace() {
  return getToken(FlingHdlGrammarParser::PunctLBrace, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclMixinContext::PunctRBrace() {
  return getToken(FlingHdlGrammarParser::PunctRBrace, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclMixinContext::KwBase() {
  return getToken(FlingHdlGrammarParser::KwBase, 0);
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_ExtendsContext* FlingHdlGrammarParser::FlingDeclMixinContext::flingDeclClsOrMxn_Extends() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclClsOrMxn_ExtendsContext>(0);
}

std::vector<FlingHdlGrammarParser::FlingDeclClsOrMxn_ItemContext *> FlingHdlGrammarParser::FlingDeclMixinContext::flingDeclClsOrMxn_Item() {
  return getRuleContexts<FlingHdlGrammarParser::FlingDeclClsOrMxn_ItemContext>();
}

FlingHdlGrammarParser::FlingDeclClsOrMxn_ItemContext* FlingHdlGrammarParser::FlingDeclMixinContext::flingDeclClsOrMxn_Item(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclClsOrMxn_ItemContext>(i);
}


size_t FlingHdlGrammarParser::FlingDeclMixinContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclMixin;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclMixinContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclMixin(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclMixinContext* FlingHdlGrammarParser::flingDeclMixin() {
  FlingDeclMixinContext *_localctx = _tracker.createInstance<FlingDeclMixinContext>(_ctx, getState());
  enterRule(_localctx, 122, FlingHdlGrammarParser::RuleFlingDeclMixin);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(771);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::KwBase) {
      setState(770);
      match(FlingHdlGrammarParser::KwBase);
    }
    setState(773);
    match(FlingHdlGrammarParser::KwMixin);
    setState(774);
    flingIdent();
    setState(775);
    flingDeclParamList();
    setState(777);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::KwExtends) {
      setState(776);
      flingDeclClsOrMxn_Extends();
    }
    setState(779);
    match(FlingHdlGrammarParser::PunctLBrace);
    setState(783);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 73) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 73)) & ((1ULL << (FlingHdlGrammarParser::KwFunc - 73))
      | (1ULL << (FlingHdlGrammarParser::KwTask - 73))
      | (1ULL << (FlingHdlGrammarParser::KwImport - 73))
      | (1ULL << (FlingHdlGrammarParser::KwConst - 73))
      | (1ULL << (FlingHdlGrammarParser::KwAlias - 73))
      | (1ULL << (FlingHdlGrammarParser::KwEnum - 73))
      | (1ULL << (FlingHdlGrammarParser::KwClass - 73))
      | (1ULL << (FlingHdlGrammarParser::KwMixin - 73))
      | (1ULL << (FlingHdlGrammarParser::KwVirtual - 73))
      | (1ULL << (FlingHdlGrammarParser::KwAbstract - 73))
      | (1ULL << (FlingHdlGrammarParser::KwBase - 73))
      | (1ULL << (FlingHdlGrammarParser::KwStatic - 73))
      | (1ULL << (FlingHdlGrammarParser::KwProc - 73))
      | (1ULL << (FlingHdlGrammarParser::KwPub - 73))
      | (1ULL << (FlingHdlGrammarParser::KwProt - 73))
      | (1ULL << (FlingHdlGrammarParser::KwPriv - 73)))) != 0) || _la == FlingHdlGrammarParser::MiscIdent) {
      setState(780);
      flingDeclClsOrMxn_Item();
      setState(785);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(786);
    match(FlingHdlGrammarParser::PunctRBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclSubprogContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclSubprogContext::FlingDeclSubprogContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingDeclFuncContext* FlingHdlGrammarParser::FlingDeclSubprogContext::flingDeclFunc() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclFuncContext>(0);
}

FlingHdlGrammarParser::FlingDeclTaskContext* FlingHdlGrammarParser::FlingDeclSubprogContext::flingDeclTask() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTaskContext>(0);
}

FlingHdlGrammarParser::FlingDeclProcContext* FlingHdlGrammarParser::FlingDeclSubprogContext::flingDeclProc() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclProcContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclSubprogContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclSubprog;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclSubprogContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclSubprog(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclSubprogContext* FlingHdlGrammarParser::flingDeclSubprog() {
  FlingDeclSubprogContext *_localctx = _tracker.createInstance<FlingDeclSubprogContext>(_ctx, getState());
  enterRule(_localctx, 124, FlingHdlGrammarParser::RuleFlingDeclSubprog);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(791);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FlingHdlGrammarParser::KwFunc: {
        enterOuterAlt(_localctx, 1);
        setState(788);
        flingDeclFunc();
        break;
      }

      case FlingHdlGrammarParser::KwTask: {
        enterOuterAlt(_localctx, 2);
        setState(789);
        flingDeclTask();
        break;
      }

      case FlingHdlGrammarParser::KwProc: {
        enterOuterAlt(_localctx, 3);
        setState(790);
        flingDeclProc();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclFuncContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclFuncContext::FlingDeclFuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingDeclFunc_HeaderContext* FlingHdlGrammarParser::FlingDeclFuncContext::flingDeclFunc_Header() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclFunc_HeaderContext>(0);
}

FlingHdlGrammarParser::FlingDeclFunc_ScopeContext* FlingHdlGrammarParser::FlingDeclFuncContext::flingDeclFunc_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclFunc_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclFuncContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclFunc;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclFunc(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclFuncContext* FlingHdlGrammarParser::flingDeclFunc() {
  FlingDeclFuncContext *_localctx = _tracker.createInstance<FlingDeclFuncContext>(_ctx, getState());
  enterRule(_localctx, 126, FlingHdlGrammarParser::RuleFlingDeclFunc);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(793);
    flingDeclFunc_Header();
    setState(794);
    flingDeclFunc_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclFunc_HeaderContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclFunc_HeaderContext::FlingDeclFunc_HeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclFunc_HeaderContext::KwFunc() {
  return getToken(FlingHdlGrammarParser::KwFunc, 0);
}

FlingHdlGrammarParser::FlingIdentContext* FlingHdlGrammarParser::FlingDeclFunc_HeaderContext::flingIdent() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentContext>(0);
}

FlingHdlGrammarParser::FlingDeclArgListContext* FlingHdlGrammarParser::FlingDeclFunc_HeaderContext::flingDeclArgList() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclArgListContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclFunc_HeaderContext::PunctColon() {
  return getToken(FlingHdlGrammarParser::PunctColon, 0);
}

FlingHdlGrammarParser::FlingTypenameOrModnameContext* FlingHdlGrammarParser::FlingDeclFunc_HeaderContext::flingTypenameOrModname() {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModnameContext>(0);
}

FlingHdlGrammarParser::FlingDeclParamListContext* FlingHdlGrammarParser::FlingDeclFunc_HeaderContext::flingDeclParamList() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclParamListContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclFunc_HeaderContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclFunc_Header;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclFunc_HeaderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclFunc_Header(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclFunc_HeaderContext* FlingHdlGrammarParser::flingDeclFunc_Header() {
  FlingDeclFunc_HeaderContext *_localctx = _tracker.createInstance<FlingDeclFunc_HeaderContext>(_ctx, getState());
  enterRule(_localctx, 128, FlingHdlGrammarParser::RuleFlingDeclFunc_Header);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(796);
    match(FlingHdlGrammarParser::KwFunc);
    setState(797);
    flingIdent();
    setState(799);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::PunctCmpLt) {
      setState(798);
      flingDeclParamList();
    }
    setState(801);
    flingDeclArgList();
    setState(802);
    match(FlingHdlGrammarParser::PunctColon);
    setState(803);
    flingTypenameOrModname();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclFunc_ScopeContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclFunc_ScopeContext::FlingDeclFunc_ScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclFunc_ScopeContext::PunctLBrace() {
  return getToken(FlingHdlGrammarParser::PunctLBrace, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclFunc_ScopeContext::PunctRBrace() {
  return getToken(FlingHdlGrammarParser::PunctRBrace, 0);
}

std::vector<FlingHdlGrammarParser::FlingDeclFunc_ItemContext *> FlingHdlGrammarParser::FlingDeclFunc_ScopeContext::flingDeclFunc_Item() {
  return getRuleContexts<FlingHdlGrammarParser::FlingDeclFunc_ItemContext>();
}

FlingHdlGrammarParser::FlingDeclFunc_ItemContext* FlingHdlGrammarParser::FlingDeclFunc_ScopeContext::flingDeclFunc_Item(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclFunc_ItemContext>(i);
}


size_t FlingHdlGrammarParser::FlingDeclFunc_ScopeContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclFunc_Scope;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclFunc_ScopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclFunc_Scope(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclFunc_ScopeContext* FlingHdlGrammarParser::flingDeclFunc_Scope() {
  FlingDeclFunc_ScopeContext *_localctx = _tracker.createInstance<FlingDeclFunc_ScopeContext>(_ctx, getState());
  enterRule(_localctx, 130, FlingHdlGrammarParser::RuleFlingDeclFunc_Scope);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(805);
    match(FlingHdlGrammarParser::PunctLBrace);
    setState(809);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FlingHdlGrammarParser::LitDecNum)
      | (1ULL << FlingHdlGrammarParser::LitHexNum)
      | (1ULL << FlingHdlGrammarParser::LitOctNum)
      | (1ULL << FlingHdlGrammarParser::LitBinNum)
      | (1ULL << FlingHdlGrammarParser::LitFloatNum)
      | (1ULL << FlingHdlGrammarParser::LitString)
      | (1ULL << FlingHdlGrammarParser::PunctPlus)
      | (1ULL << FlingHdlGrammarParser::PunctMinus)
      | (1ULL << FlingHdlGrammarParser::PunctBitOr)
      | (1ULL << FlingHdlGrammarParser::PunctBitNor)
      | (1ULL << FlingHdlGrammarParser::PunctBitAnd)
      | (1ULL << FlingHdlGrammarParser::PunctBitNand)
      | (1ULL << FlingHdlGrammarParser::PunctBitXor)
      | (1ULL << FlingHdlGrammarParser::PunctBitXnor)
      | (1ULL << FlingHdlGrammarParser::PunctBitNot)
      | (1ULL << FlingHdlGrammarParser::PunctLogNot)
      | (1ULL << FlingHdlGrammarParser::PunctLParen)
      | (1ULL << FlingHdlGrammarParser::PunctLBrace)
      | (1ULL << FlingHdlGrammarParser::KwIf)
      | (1ULL << FlingHdlGrammarParser::KwMux)
      | (1ULL << FlingHdlGrammarParser::KwSwitch)
      | (1ULL << FlingHdlGrammarParser::KwSwitchz)
      | (1ULL << FlingHdlGrammarParser::KwFor)
      | (1ULL << FlingHdlGrammarParser::KwWhile))) != 0) || ((((_la - 78) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 78)) & ((1ULL << (FlingHdlGrammarParser::KwLogic - 78))
      | (1ULL << (FlingHdlGrammarParser::KwSigned - 78))
      | (1ULL << (FlingHdlGrammarParser::KwInteger - 78))
      | (1ULL << (FlingHdlGrammarParser::KwSizeT - 78))
      | (1ULL << (FlingHdlGrammarParser::KwU8 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwI8 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwU16 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwI16 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwU32 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwI32 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwU64 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwI64 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwU128 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwI128 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwReturn - 78))
      | (1ULL << (FlingHdlGrammarParser::KwRetT - 78))
      | (1ULL << (FlingHdlGrammarParser::KwAuto - 78))
      | (1ULL << (FlingHdlGrammarParser::KwRange - 78))
      | (1ULL << (FlingHdlGrammarParser::KwHighZ - 78))
      | (1ULL << (FlingHdlGrammarParser::KwUnkX - 78))
      | (1ULL << (FlingHdlGrammarParser::KwSized - 78))
      | (1ULL << (FlingHdlGrammarParser::KwCat - 78))
      | (1ULL << (FlingHdlGrammarParser::KwRepl - 78))
      | (1ULL << (FlingHdlGrammarParser::KwDollarSigned - 78))
      | (1ULL << (FlingHdlGrammarParser::KwDollarUnsigned - 78))
      | (1ULL << (FlingHdlGrammarParser::KwDollarPow - 78))
      | (1ULL << (FlingHdlGrammarParser::KwDollarClog2 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwVoid - 78))
      | (1ULL << (FlingHdlGrammarParser::KwTypeof - 78))
      | (1ULL << (FlingHdlGrammarParser::KwAlias - 78))
      | (1ULL << (FlingHdlGrammarParser::KwEnum - 78))
      | (1ULL << (FlingHdlGrammarParser::KwClass - 78))
      | (1ULL << (FlingHdlGrammarParser::KwMixin - 78))
      | (1ULL << (FlingHdlGrammarParser::KwBase - 78))
      | (1ULL << (FlingHdlGrammarParser::KwSelfT - 78))
      | (1ULL << (FlingHdlGrammarParser::KwString - 78))
      | (1ULL << (FlingHdlGrammarParser::MiscIdent - 78)))) != 0)) {
      setState(806);
      flingDeclFunc_Item();
      setState(811);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(812);
    match(FlingHdlGrammarParser::PunctRBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclFunc_ItemContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclFunc_ItemContext::FlingDeclFunc_ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingDeclFunc_ItemContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclFunc_ItemContext::PunctSemicolon() {
  return getToken(FlingHdlGrammarParser::PunctSemicolon, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclFunc_ItemContext::KwReturn() {
  return getToken(FlingHdlGrammarParser::KwReturn, 0);
}

FlingHdlGrammarParser::FlingDeclFunc_ScopeContext* FlingHdlGrammarParser::FlingDeclFunc_ItemContext::flingDeclFunc_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclFunc_ScopeContext>(0);
}

FlingHdlGrammarParser::FlingDeclAliasContext* FlingHdlGrammarParser::FlingDeclFunc_ItemContext::flingDeclAlias() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclAliasContext>(0);
}

FlingHdlGrammarParser::FlingDeclVarContext* FlingHdlGrammarParser::FlingDeclFunc_ItemContext::flingDeclVar() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclVarContext>(0);
}

FlingHdlGrammarParser::FlingDeclConstContext* FlingHdlGrammarParser::FlingDeclFunc_ItemContext::flingDeclConst() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclConstContext>(0);
}

FlingHdlGrammarParser::FlingDeclTypeContext* FlingHdlGrammarParser::FlingDeclFunc_ItemContext::flingDeclType() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTypeContext>(0);
}

FlingHdlGrammarParser::FlingBehav_Item_BlkAssignContext* FlingHdlGrammarParser::FlingDeclFunc_ItemContext::flingBehav_Item_BlkAssign() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_Item_BlkAssignContext>(0);
}

FlingHdlGrammarParser::FlingDeclFunc_Item_IfContext* FlingHdlGrammarParser::FlingDeclFunc_ItemContext::flingDeclFunc_Item_If() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclFunc_Item_IfContext>(0);
}

FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchzContext* FlingHdlGrammarParser::FlingDeclFunc_ItemContext::flingDeclFunc_Item_SwitchOrSwitchz() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchzContext>(0);
}

FlingHdlGrammarParser::FlingDeclFunc_Item_ForContext* FlingHdlGrammarParser::FlingDeclFunc_ItemContext::flingDeclFunc_Item_For() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclFunc_Item_ForContext>(0);
}

FlingHdlGrammarParser::FlingDeclFunc_Item_WhileContext* FlingHdlGrammarParser::FlingDeclFunc_ItemContext::flingDeclFunc_Item_While() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclFunc_Item_WhileContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclFunc_ItemContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclFunc_Item;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclFunc_ItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclFunc_Item(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclFunc_ItemContext* FlingHdlGrammarParser::flingDeclFunc_Item() {
  FlingDeclFunc_ItemContext *_localctx = _tracker.createInstance<FlingDeclFunc_ItemContext>(_ctx, getState());
  enterRule(_localctx, 132, FlingHdlGrammarParser::RuleFlingDeclFunc_Item);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(830);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(815);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FlingHdlGrammarParser::KwReturn) {
        setState(814);
        match(FlingHdlGrammarParser::KwReturn);
      }
      setState(817);
      flingExpr();
      setState(818);
      match(FlingHdlGrammarParser::PunctSemicolon);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(820);
      flingDeclFunc_Scope();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(821);
      flingDeclAlias();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(822);
      flingDeclVar();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(823);
      flingDeclConst();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(824);
      flingDeclType();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(825);
      flingBehav_Item_BlkAssign();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(826);
      flingDeclFunc_Item_If();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(827);
      flingDeclFunc_Item_SwitchOrSwitchz();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(828);
      flingDeclFunc_Item_For();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(829);
      flingDeclFunc_Item_While();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclFunc_Item_IfContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclFunc_Item_IfContext::FlingDeclFunc_Item_IfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclFunc_Item_IfContext::KwIf() {
  return getToken(FlingHdlGrammarParser::KwIf, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingDeclFunc_Item_IfContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

FlingHdlGrammarParser::FlingDeclFunc_ScopeContext* FlingHdlGrammarParser::FlingDeclFunc_Item_IfContext::flingDeclFunc_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclFunc_ScopeContext>(0);
}

std::vector<FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElifContext *> FlingHdlGrammarParser::FlingDeclFunc_Item_IfContext::flingDeclFunc_Item_If_Elif() {
  return getRuleContexts<FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElifContext>();
}

FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElifContext* FlingHdlGrammarParser::FlingDeclFunc_Item_IfContext::flingDeclFunc_Item_If_Elif(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElifContext>(i);
}

FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElseContext* FlingHdlGrammarParser::FlingDeclFunc_Item_IfContext::flingDeclFunc_Item_If_Else() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElseContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclFunc_Item_IfContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclFunc_Item_If;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclFunc_Item_IfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclFunc_Item_If(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclFunc_Item_IfContext* FlingHdlGrammarParser::flingDeclFunc_Item_If() {
  FlingDeclFunc_Item_IfContext *_localctx = _tracker.createInstance<FlingDeclFunc_Item_IfContext>(_ctx, getState());
  enterRule(_localctx, 134, FlingHdlGrammarParser::RuleFlingDeclFunc_Item_If);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(832);
    match(FlingHdlGrammarParser::KwIf);
    setState(833);
    flingExpr();
    setState(834);
    flingDeclFunc_Scope();
    setState(838);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FlingHdlGrammarParser::KwElif) {
      setState(835);
      flingDeclFunc_Item_If_Elif();
      setState(840);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(842);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::KwElse) {
      setState(841);
      flingDeclFunc_Item_If_Else();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclFunc_Item_If_ElifContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElifContext::FlingDeclFunc_Item_If_ElifContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElifContext::KwElif() {
  return getToken(FlingHdlGrammarParser::KwElif, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElifContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

FlingHdlGrammarParser::FlingDeclFunc_ScopeContext* FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElifContext::flingDeclFunc_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclFunc_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElifContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclFunc_Item_If_Elif;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElifContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclFunc_Item_If_Elif(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElifContext* FlingHdlGrammarParser::flingDeclFunc_Item_If_Elif() {
  FlingDeclFunc_Item_If_ElifContext *_localctx = _tracker.createInstance<FlingDeclFunc_Item_If_ElifContext>(_ctx, getState());
  enterRule(_localctx, 136, FlingHdlGrammarParser::RuleFlingDeclFunc_Item_If_Elif);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(844);
    match(FlingHdlGrammarParser::KwElif);
    setState(845);
    flingExpr();
    setState(846);
    flingDeclFunc_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclFunc_Item_If_ElseContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElseContext::FlingDeclFunc_Item_If_ElseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElseContext::KwElse() {
  return getToken(FlingHdlGrammarParser::KwElse, 0);
}

FlingHdlGrammarParser::FlingDeclFunc_ScopeContext* FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElseContext::flingDeclFunc_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclFunc_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElseContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclFunc_Item_If_Else;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclFunc_Item_If_Else(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclFunc_Item_If_ElseContext* FlingHdlGrammarParser::flingDeclFunc_Item_If_Else() {
  FlingDeclFunc_Item_If_ElseContext *_localctx = _tracker.createInstance<FlingDeclFunc_Item_If_ElseContext>(_ctx, getState());
  enterRule(_localctx, 138, FlingHdlGrammarParser::RuleFlingDeclFunc_Item_If_Else);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(848);
    match(FlingHdlGrammarParser::KwElse);
    setState(849);
    flingDeclFunc_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclFunc_Item_SwitchOrSwitchzContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchzContext::FlingDeclFunc_Item_SwitchOrSwitchzContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchzContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchzContext::PunctLBrace() {
  return getToken(FlingHdlGrammarParser::PunctLBrace, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchzContext::PunctRBrace() {
  return getToken(FlingHdlGrammarParser::PunctRBrace, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchzContext::KwSwitch() {
  return getToken(FlingHdlGrammarParser::KwSwitch, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchzContext::KwSwitchz() {
  return getToken(FlingHdlGrammarParser::KwSwitchz, 0);
}

FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext* FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchzContext::flingDeclFunc_Item_SwitchOrSwitchz_Default() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext>(0);
}

std::vector<FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext *> FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchzContext::flingDeclFunc_Item_SwitchOrSwitchz_Case() {
  return getRuleContexts<FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext>();
}

FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext* FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchzContext::flingDeclFunc_Item_SwitchOrSwitchz_Case(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext>(i);
}


size_t FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchzContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclFunc_Item_SwitchOrSwitchz;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchzContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclFunc_Item_SwitchOrSwitchz(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchzContext* FlingHdlGrammarParser::flingDeclFunc_Item_SwitchOrSwitchz() {
  FlingDeclFunc_Item_SwitchOrSwitchzContext *_localctx = _tracker.createInstance<FlingDeclFunc_Item_SwitchOrSwitchzContext>(_ctx, getState());
  enterRule(_localctx, 140, FlingHdlGrammarParser::RuleFlingDeclFunc_Item_SwitchOrSwitchz);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(851);
    _la = _input->LA(1);
    if (!(_la == FlingHdlGrammarParser::KwSwitch

    || _la == FlingHdlGrammarParser::KwSwitchz)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(852);
    flingExpr();
    setState(853);
    match(FlingHdlGrammarParser::PunctLBrace);
    setState(870);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx)) {
    case 1: {
      setState(855);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FlingHdlGrammarParser::KwDefault) {
        setState(854);
        flingDeclFunc_Item_SwitchOrSwitchz_Default();
      }
      setState(860);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << FlingHdlGrammarParser::LitDecNum)
        | (1ULL << FlingHdlGrammarParser::LitHexNum)
        | (1ULL << FlingHdlGrammarParser::LitOctNum)
        | (1ULL << FlingHdlGrammarParser::LitBinNum)
        | (1ULL << FlingHdlGrammarParser::LitFloatNum)
        | (1ULL << FlingHdlGrammarParser::LitString)
        | (1ULL << FlingHdlGrammarParser::PunctPlus)
        | (1ULL << FlingHdlGrammarParser::PunctMinus)
        | (1ULL << FlingHdlGrammarParser::PunctBitOr)
        | (1ULL << FlingHdlGrammarParser::PunctBitNor)
        | (1ULL << FlingHdlGrammarParser::PunctBitAnd)
        | (1ULL << FlingHdlGrammarParser::PunctBitNand)
        | (1ULL << FlingHdlGrammarParser::PunctBitXor)
        | (1ULL << FlingHdlGrammarParser::PunctBitXnor)
        | (1ULL << FlingHdlGrammarParser::PunctBitNot)
        | (1ULL << FlingHdlGrammarParser::PunctLogNot)
        | (1ULL << FlingHdlGrammarParser::PunctLParen)
        | (1ULL << FlingHdlGrammarParser::KwMux))) != 0) || ((((_la - 78) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 78)) & ((1ULL << (FlingHdlGrammarParser::KwLogic - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwInteger - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSizeT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU8 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI8 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU16 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI16 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU32 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI32 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU64 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI64 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU128 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI128 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRetT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwAuto - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRange - 78))
        | (1ULL << (FlingHdlGrammarParser::KwHighZ - 78))
        | (1ULL << (FlingHdlGrammarParser::KwUnkX - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSized - 78))
        | (1ULL << (FlingHdlGrammarParser::KwCat - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRepl - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarSigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarUnsigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarPow - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarClog2 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwVoid - 78))
        | (1ULL << (FlingHdlGrammarParser::KwTypeof - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSelfT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwString - 78))
        | (1ULL << (FlingHdlGrammarParser::MiscIdent - 78)))) != 0)) {
        setState(857);
        flingDeclFunc_Item_SwitchOrSwitchz_Case();
        setState(862);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      setState(864); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(863);
        flingDeclFunc_Item_SwitchOrSwitchz_Case();
        setState(866); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << FlingHdlGrammarParser::LitDecNum)
        | (1ULL << FlingHdlGrammarParser::LitHexNum)
        | (1ULL << FlingHdlGrammarParser::LitOctNum)
        | (1ULL << FlingHdlGrammarParser::LitBinNum)
        | (1ULL << FlingHdlGrammarParser::LitFloatNum)
        | (1ULL << FlingHdlGrammarParser::LitString)
        | (1ULL << FlingHdlGrammarParser::PunctPlus)
        | (1ULL << FlingHdlGrammarParser::PunctMinus)
        | (1ULL << FlingHdlGrammarParser::PunctBitOr)
        | (1ULL << FlingHdlGrammarParser::PunctBitNor)
        | (1ULL << FlingHdlGrammarParser::PunctBitAnd)
        | (1ULL << FlingHdlGrammarParser::PunctBitNand)
        | (1ULL << FlingHdlGrammarParser::PunctBitXor)
        | (1ULL << FlingHdlGrammarParser::PunctBitXnor)
        | (1ULL << FlingHdlGrammarParser::PunctBitNot)
        | (1ULL << FlingHdlGrammarParser::PunctLogNot)
        | (1ULL << FlingHdlGrammarParser::PunctLParen)
        | (1ULL << FlingHdlGrammarParser::KwMux))) != 0) || ((((_la - 78) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 78)) & ((1ULL << (FlingHdlGrammarParser::KwLogic - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwInteger - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSizeT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU8 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI8 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU16 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI16 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU32 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI32 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU64 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI64 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU128 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI128 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRetT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwAuto - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRange - 78))
        | (1ULL << (FlingHdlGrammarParser::KwHighZ - 78))
        | (1ULL << (FlingHdlGrammarParser::KwUnkX - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSized - 78))
        | (1ULL << (FlingHdlGrammarParser::KwCat - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRepl - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarSigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarUnsigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarPow - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarClog2 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwVoid - 78))
        | (1ULL << (FlingHdlGrammarParser::KwTypeof - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSelfT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwString - 78))
        | (1ULL << (FlingHdlGrammarParser::MiscIdent - 78)))) != 0));
      setState(868);
      flingDeclFunc_Item_SwitchOrSwitchz_Default();
      break;
    }

    }
    setState(872);
    match(FlingHdlGrammarParser::PunctRBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext::FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext::KwDefault() {
  return getToken(FlingHdlGrammarParser::KwDefault, 0);
}

FlingHdlGrammarParser::FlingDeclFunc_ScopeContext* FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext::flingDeclFunc_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclFunc_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclFunc_Item_SwitchOrSwitchz_Default;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclFunc_Item_SwitchOrSwitchz_Default(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext* FlingHdlGrammarParser::flingDeclFunc_Item_SwitchOrSwitchz_Default() {
  FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext *_localctx = _tracker.createInstance<FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext>(_ctx, getState());
  enterRule(_localctx, 142, FlingHdlGrammarParser::RuleFlingDeclFunc_Item_SwitchOrSwitchz_Default);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(874);
    match(FlingHdlGrammarParser::KwDefault);
    setState(875);
    flingDeclFunc_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext::FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExprListContext* FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext::flingExprList() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprListContext>(0);
}

FlingHdlGrammarParser::FlingDeclFunc_ScopeContext* FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext::flingDeclFunc_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclFunc_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclFunc_Item_SwitchOrSwitchz_Case;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclFunc_Item_SwitchOrSwitchz_Case(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext* FlingHdlGrammarParser::flingDeclFunc_Item_SwitchOrSwitchz_Case() {
  FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext *_localctx = _tracker.createInstance<FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext>(_ctx, getState());
  enterRule(_localctx, 144, FlingHdlGrammarParser::RuleFlingDeclFunc_Item_SwitchOrSwitchz_Case);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(877);
    flingExprList();
    setState(878);
    flingDeclFunc_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclFunc_Item_ForContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclFunc_Item_ForContext::FlingDeclFunc_Item_ForContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclFunc_Item_ForContext::KwFor() {
  return getToken(FlingHdlGrammarParser::KwFor, 0);
}

FlingHdlGrammarParser::FlingIdentContext* FlingHdlGrammarParser::FlingDeclFunc_Item_ForContext::flingIdent() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclFunc_Item_ForContext::PunctColon() {
  return getToken(FlingHdlGrammarParser::PunctColon, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingDeclFunc_Item_ForContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

FlingHdlGrammarParser::FlingDeclFunc_ScopeContext* FlingHdlGrammarParser::FlingDeclFunc_Item_ForContext::flingDeclFunc_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclFunc_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclFunc_Item_ForContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclFunc_Item_For;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclFunc_Item_ForContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclFunc_Item_For(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclFunc_Item_ForContext* FlingHdlGrammarParser::flingDeclFunc_Item_For() {
  FlingDeclFunc_Item_ForContext *_localctx = _tracker.createInstance<FlingDeclFunc_Item_ForContext>(_ctx, getState());
  enterRule(_localctx, 146, FlingHdlGrammarParser::RuleFlingDeclFunc_Item_For);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(880);
    match(FlingHdlGrammarParser::KwFor);
    setState(881);
    flingIdent();
    setState(882);
    match(FlingHdlGrammarParser::PunctColon);
    setState(883);
    flingExpr();
    setState(884);
    flingDeclFunc_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclFunc_Item_WhileContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclFunc_Item_WhileContext::FlingDeclFunc_Item_WhileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclFunc_Item_WhileContext::KwWhile() {
  return getToken(FlingHdlGrammarParser::KwWhile, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingDeclFunc_Item_WhileContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

FlingHdlGrammarParser::FlingDeclFunc_ScopeContext* FlingHdlGrammarParser::FlingDeclFunc_Item_WhileContext::flingDeclFunc_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclFunc_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclFunc_Item_WhileContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclFunc_Item_While;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclFunc_Item_WhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclFunc_Item_While(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclFunc_Item_WhileContext* FlingHdlGrammarParser::flingDeclFunc_Item_While() {
  FlingDeclFunc_Item_WhileContext *_localctx = _tracker.createInstance<FlingDeclFunc_Item_WhileContext>(_ctx, getState());
  enterRule(_localctx, 148, FlingHdlGrammarParser::RuleFlingDeclFunc_Item_While);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(886);
    match(FlingHdlGrammarParser::KwWhile);
    setState(887);
    flingExpr();
    setState(888);
    flingDeclFunc_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclTaskContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclTaskContext::FlingDeclTaskContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingDeclTask_HeaderContext* FlingHdlGrammarParser::FlingDeclTaskContext::flingDeclTask_Header() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTask_HeaderContext>(0);
}

FlingHdlGrammarParser::FlingDeclTask_ScopeContext* FlingHdlGrammarParser::FlingDeclTaskContext::flingDeclTask_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTask_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclTaskContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclTask;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclTaskContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclTask(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclTaskContext* FlingHdlGrammarParser::flingDeclTask() {
  FlingDeclTaskContext *_localctx = _tracker.createInstance<FlingDeclTaskContext>(_ctx, getState());
  enterRule(_localctx, 150, FlingHdlGrammarParser::RuleFlingDeclTask);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(890);
    flingDeclTask_Header();
    setState(891);
    flingDeclTask_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclTask_HeaderContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclTask_HeaderContext::FlingDeclTask_HeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclTask_HeaderContext::KwTask() {
  return getToken(FlingHdlGrammarParser::KwTask, 0);
}

FlingHdlGrammarParser::FlingIdentContext* FlingHdlGrammarParser::FlingDeclTask_HeaderContext::flingIdent() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentContext>(0);
}

FlingHdlGrammarParser::FlingDeclArgListContext* FlingHdlGrammarParser::FlingDeclTask_HeaderContext::flingDeclArgList() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclArgListContext>(0);
}

FlingHdlGrammarParser::FlingDeclParamListContext* FlingHdlGrammarParser::FlingDeclTask_HeaderContext::flingDeclParamList() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclParamListContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclTask_HeaderContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclTask_Header;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclTask_HeaderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclTask_Header(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclTask_HeaderContext* FlingHdlGrammarParser::flingDeclTask_Header() {
  FlingDeclTask_HeaderContext *_localctx = _tracker.createInstance<FlingDeclTask_HeaderContext>(_ctx, getState());
  enterRule(_localctx, 152, FlingHdlGrammarParser::RuleFlingDeclTask_Header);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(893);
    match(FlingHdlGrammarParser::KwTask);
    setState(894);
    flingIdent();
    setState(896);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::PunctCmpLt) {
      setState(895);
      flingDeclParamList();
    }
    setState(898);
    flingDeclArgList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclTask_ScopeContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclTask_ScopeContext::FlingDeclTask_ScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclTask_ScopeContext::PunctLBrace() {
  return getToken(FlingHdlGrammarParser::PunctLBrace, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclTask_ScopeContext::PunctRBrace() {
  return getToken(FlingHdlGrammarParser::PunctRBrace, 0);
}

std::vector<FlingHdlGrammarParser::FlingDeclTask_ItemContext *> FlingHdlGrammarParser::FlingDeclTask_ScopeContext::flingDeclTask_Item() {
  return getRuleContexts<FlingHdlGrammarParser::FlingDeclTask_ItemContext>();
}

FlingHdlGrammarParser::FlingDeclTask_ItemContext* FlingHdlGrammarParser::FlingDeclTask_ScopeContext::flingDeclTask_Item(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTask_ItemContext>(i);
}


size_t FlingHdlGrammarParser::FlingDeclTask_ScopeContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclTask_Scope;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclTask_ScopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclTask_Scope(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclTask_ScopeContext* FlingHdlGrammarParser::flingDeclTask_Scope() {
  FlingDeclTask_ScopeContext *_localctx = _tracker.createInstance<FlingDeclTask_ScopeContext>(_ctx, getState());
  enterRule(_localctx, 154, FlingHdlGrammarParser::RuleFlingDeclTask_Scope);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(900);
    match(FlingHdlGrammarParser::PunctLBrace);
    setState(904);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FlingHdlGrammarParser::LitDecNum)
      | (1ULL << FlingHdlGrammarParser::LitHexNum)
      | (1ULL << FlingHdlGrammarParser::LitOctNum)
      | (1ULL << FlingHdlGrammarParser::LitBinNum)
      | (1ULL << FlingHdlGrammarParser::LitFloatNum)
      | (1ULL << FlingHdlGrammarParser::LitString)
      | (1ULL << FlingHdlGrammarParser::PunctPlus)
      | (1ULL << FlingHdlGrammarParser::PunctMinus)
      | (1ULL << FlingHdlGrammarParser::PunctBitOr)
      | (1ULL << FlingHdlGrammarParser::PunctBitNor)
      | (1ULL << FlingHdlGrammarParser::PunctBitAnd)
      | (1ULL << FlingHdlGrammarParser::PunctBitNand)
      | (1ULL << FlingHdlGrammarParser::PunctBitXor)
      | (1ULL << FlingHdlGrammarParser::PunctBitXnor)
      | (1ULL << FlingHdlGrammarParser::PunctBitNot)
      | (1ULL << FlingHdlGrammarParser::PunctLogNot)
      | (1ULL << FlingHdlGrammarParser::PunctLParen)
      | (1ULL << FlingHdlGrammarParser::PunctLBrace)
      | (1ULL << FlingHdlGrammarParser::KwIf)
      | (1ULL << FlingHdlGrammarParser::KwMux)
      | (1ULL << FlingHdlGrammarParser::KwSwitch)
      | (1ULL << FlingHdlGrammarParser::KwSwitchz)
      | (1ULL << FlingHdlGrammarParser::KwFor)
      | (1ULL << FlingHdlGrammarParser::KwWhile))) != 0) || ((((_la - 78) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 78)) & ((1ULL << (FlingHdlGrammarParser::KwLogic - 78))
      | (1ULL << (FlingHdlGrammarParser::KwSigned - 78))
      | (1ULL << (FlingHdlGrammarParser::KwInteger - 78))
      | (1ULL << (FlingHdlGrammarParser::KwSizeT - 78))
      | (1ULL << (FlingHdlGrammarParser::KwU8 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwI8 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwU16 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwI16 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwU32 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwI32 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwU64 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwI64 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwU128 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwI128 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwRetT - 78))
      | (1ULL << (FlingHdlGrammarParser::KwAuto - 78))
      | (1ULL << (FlingHdlGrammarParser::KwRange - 78))
      | (1ULL << (FlingHdlGrammarParser::KwHighZ - 78))
      | (1ULL << (FlingHdlGrammarParser::KwUnkX - 78))
      | (1ULL << (FlingHdlGrammarParser::KwSized - 78))
      | (1ULL << (FlingHdlGrammarParser::KwCat - 78))
      | (1ULL << (FlingHdlGrammarParser::KwRepl - 78))
      | (1ULL << (FlingHdlGrammarParser::KwDollarSigned - 78))
      | (1ULL << (FlingHdlGrammarParser::KwDollarUnsigned - 78))
      | (1ULL << (FlingHdlGrammarParser::KwDollarPow - 78))
      | (1ULL << (FlingHdlGrammarParser::KwDollarClog2 - 78))
      | (1ULL << (FlingHdlGrammarParser::KwVoid - 78))
      | (1ULL << (FlingHdlGrammarParser::KwTypeof - 78))
      | (1ULL << (FlingHdlGrammarParser::KwAlias - 78))
      | (1ULL << (FlingHdlGrammarParser::KwEnum - 78))
      | (1ULL << (FlingHdlGrammarParser::KwClass - 78))
      | (1ULL << (FlingHdlGrammarParser::KwMixin - 78))
      | (1ULL << (FlingHdlGrammarParser::KwBase - 78))
      | (1ULL << (FlingHdlGrammarParser::KwSelfT - 78))
      | (1ULL << (FlingHdlGrammarParser::KwString - 78))
      | (1ULL << (FlingHdlGrammarParser::MiscIdent - 78)))) != 0)) {
      setState(901);
      flingDeclTask_Item();
      setState(906);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(907);
    match(FlingHdlGrammarParser::PunctRBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclTask_ItemContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclTask_ItemContext::FlingDeclTask_ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingDeclTask_ScopeContext* FlingHdlGrammarParser::FlingDeclTask_ItemContext::flingDeclTask_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTask_ScopeContext>(0);
}

FlingHdlGrammarParser::FlingDeclAliasContext* FlingHdlGrammarParser::FlingDeclTask_ItemContext::flingDeclAlias() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclAliasContext>(0);
}

FlingHdlGrammarParser::FlingDeclVarContext* FlingHdlGrammarParser::FlingDeclTask_ItemContext::flingDeclVar() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclVarContext>(0);
}

FlingHdlGrammarParser::FlingDeclConstContext* FlingHdlGrammarParser::FlingDeclTask_ItemContext::flingDeclConst() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclConstContext>(0);
}

FlingHdlGrammarParser::FlingDeclTypeContext* FlingHdlGrammarParser::FlingDeclTask_ItemContext::flingDeclType() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTypeContext>(0);
}

FlingHdlGrammarParser::FlingBehav_Item_BlkAssignContext* FlingHdlGrammarParser::FlingDeclTask_ItemContext::flingBehav_Item_BlkAssign() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_Item_BlkAssignContext>(0);
}

FlingHdlGrammarParser::FlingBehav_Item_NonBlkAssignContext* FlingHdlGrammarParser::FlingDeclTask_ItemContext::flingBehav_Item_NonBlkAssign() {
  return getRuleContext<FlingHdlGrammarParser::FlingBehav_Item_NonBlkAssignContext>(0);
}

FlingHdlGrammarParser::FlingDeclTask_Item_IfContext* FlingHdlGrammarParser::FlingDeclTask_ItemContext::flingDeclTask_Item_If() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTask_Item_IfContext>(0);
}

FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchzContext* FlingHdlGrammarParser::FlingDeclTask_ItemContext::flingDeclTask_Item_SwitchOrSwitchz() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchzContext>(0);
}

FlingHdlGrammarParser::FlingDeclTask_Item_ForContext* FlingHdlGrammarParser::FlingDeclTask_ItemContext::flingDeclTask_Item_For() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTask_Item_ForContext>(0);
}

FlingHdlGrammarParser::FlingDeclTask_Item_WhileContext* FlingHdlGrammarParser::FlingDeclTask_ItemContext::flingDeclTask_Item_While() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTask_Item_WhileContext>(0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingDeclTask_ItemContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclTask_ItemContext::PunctSemicolon() {
  return getToken(FlingHdlGrammarParser::PunctSemicolon, 0);
}


size_t FlingHdlGrammarParser::FlingDeclTask_ItemContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclTask_Item;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclTask_ItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclTask_Item(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclTask_ItemContext* FlingHdlGrammarParser::flingDeclTask_Item() {
  FlingDeclTask_ItemContext *_localctx = _tracker.createInstance<FlingDeclTask_ItemContext>(_ctx, getState());
  enterRule(_localctx, 156, FlingHdlGrammarParser::RuleFlingDeclTask_Item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(923);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(909);
      flingDeclTask_Scope();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(910);
      flingDeclAlias();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(911);
      flingDeclVar();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(912);
      flingDeclConst();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(913);
      flingDeclType();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(914);
      flingBehav_Item_BlkAssign();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(915);
      flingBehav_Item_NonBlkAssign();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(916);
      flingDeclTask_Item_If();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(917);
      flingDeclTask_Item_SwitchOrSwitchz();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(918);
      flingDeclTask_Item_For();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(919);
      flingDeclTask_Item_While();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(920);
      flingExpr();
      setState(921);
      match(FlingHdlGrammarParser::PunctSemicolon);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclTask_Item_IfContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclTask_Item_IfContext::FlingDeclTask_Item_IfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclTask_Item_IfContext::KwIf() {
  return getToken(FlingHdlGrammarParser::KwIf, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingDeclTask_Item_IfContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

FlingHdlGrammarParser::FlingDeclTask_ScopeContext* FlingHdlGrammarParser::FlingDeclTask_Item_IfContext::flingDeclTask_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTask_ScopeContext>(0);
}

std::vector<FlingHdlGrammarParser::FlingDeclTask_Item_If_ElifContext *> FlingHdlGrammarParser::FlingDeclTask_Item_IfContext::flingDeclTask_Item_If_Elif() {
  return getRuleContexts<FlingHdlGrammarParser::FlingDeclTask_Item_If_ElifContext>();
}

FlingHdlGrammarParser::FlingDeclTask_Item_If_ElifContext* FlingHdlGrammarParser::FlingDeclTask_Item_IfContext::flingDeclTask_Item_If_Elif(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTask_Item_If_ElifContext>(i);
}

FlingHdlGrammarParser::FlingDeclTask_Item_If_ElseContext* FlingHdlGrammarParser::FlingDeclTask_Item_IfContext::flingDeclTask_Item_If_Else() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTask_Item_If_ElseContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclTask_Item_IfContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclTask_Item_If;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclTask_Item_IfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclTask_Item_If(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclTask_Item_IfContext* FlingHdlGrammarParser::flingDeclTask_Item_If() {
  FlingDeclTask_Item_IfContext *_localctx = _tracker.createInstance<FlingDeclTask_Item_IfContext>(_ctx, getState());
  enterRule(_localctx, 158, FlingHdlGrammarParser::RuleFlingDeclTask_Item_If);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(925);
    match(FlingHdlGrammarParser::KwIf);
    setState(926);
    flingExpr();
    setState(927);
    flingDeclTask_Scope();
    setState(931);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FlingHdlGrammarParser::KwElif) {
      setState(928);
      flingDeclTask_Item_If_Elif();
      setState(933);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(935);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::KwElse) {
      setState(934);
      flingDeclTask_Item_If_Else();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclTask_Item_If_ElifContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclTask_Item_If_ElifContext::FlingDeclTask_Item_If_ElifContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclTask_Item_If_ElifContext::KwElif() {
  return getToken(FlingHdlGrammarParser::KwElif, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingDeclTask_Item_If_ElifContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

FlingHdlGrammarParser::FlingDeclTask_ScopeContext* FlingHdlGrammarParser::FlingDeclTask_Item_If_ElifContext::flingDeclTask_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTask_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclTask_Item_If_ElifContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclTask_Item_If_Elif;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclTask_Item_If_ElifContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclTask_Item_If_Elif(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclTask_Item_If_ElifContext* FlingHdlGrammarParser::flingDeclTask_Item_If_Elif() {
  FlingDeclTask_Item_If_ElifContext *_localctx = _tracker.createInstance<FlingDeclTask_Item_If_ElifContext>(_ctx, getState());
  enterRule(_localctx, 160, FlingHdlGrammarParser::RuleFlingDeclTask_Item_If_Elif);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(937);
    match(FlingHdlGrammarParser::KwElif);
    setState(938);
    flingExpr();
    setState(939);
    flingDeclTask_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclTask_Item_If_ElseContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclTask_Item_If_ElseContext::FlingDeclTask_Item_If_ElseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclTask_Item_If_ElseContext::KwElse() {
  return getToken(FlingHdlGrammarParser::KwElse, 0);
}

FlingHdlGrammarParser::FlingDeclTask_ScopeContext* FlingHdlGrammarParser::FlingDeclTask_Item_If_ElseContext::flingDeclTask_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTask_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclTask_Item_If_ElseContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclTask_Item_If_Else;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclTask_Item_If_ElseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclTask_Item_If_Else(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclTask_Item_If_ElseContext* FlingHdlGrammarParser::flingDeclTask_Item_If_Else() {
  FlingDeclTask_Item_If_ElseContext *_localctx = _tracker.createInstance<FlingDeclTask_Item_If_ElseContext>(_ctx, getState());
  enterRule(_localctx, 162, FlingHdlGrammarParser::RuleFlingDeclTask_Item_If_Else);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(941);
    match(FlingHdlGrammarParser::KwElse);
    setState(942);
    flingDeclTask_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclTask_Item_SwitchOrSwitchzContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchzContext::FlingDeclTask_Item_SwitchOrSwitchzContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchzContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchzContext::PunctLBrace() {
  return getToken(FlingHdlGrammarParser::PunctLBrace, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchzContext::PunctRBrace() {
  return getToken(FlingHdlGrammarParser::PunctRBrace, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchzContext::KwSwitch() {
  return getToken(FlingHdlGrammarParser::KwSwitch, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchzContext::KwSwitchz() {
  return getToken(FlingHdlGrammarParser::KwSwitchz, 0);
}

FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext* FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchzContext::flingDeclTask_Item_SwitchOrSwitchz_Default() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext>(0);
}

std::vector<FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_CaseContext *> FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchzContext::flingDeclTask_Item_SwitchOrSwitchz_Case() {
  return getRuleContexts<FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_CaseContext>();
}

FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_CaseContext* FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchzContext::flingDeclTask_Item_SwitchOrSwitchz_Case(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_CaseContext>(i);
}


size_t FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchzContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclTask_Item_SwitchOrSwitchz;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchzContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclTask_Item_SwitchOrSwitchz(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchzContext* FlingHdlGrammarParser::flingDeclTask_Item_SwitchOrSwitchz() {
  FlingDeclTask_Item_SwitchOrSwitchzContext *_localctx = _tracker.createInstance<FlingDeclTask_Item_SwitchOrSwitchzContext>(_ctx, getState());
  enterRule(_localctx, 164, FlingHdlGrammarParser::RuleFlingDeclTask_Item_SwitchOrSwitchz);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(944);
    _la = _input->LA(1);
    if (!(_la == FlingHdlGrammarParser::KwSwitch

    || _la == FlingHdlGrammarParser::KwSwitchz)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(945);
    flingExpr();
    setState(946);
    match(FlingHdlGrammarParser::PunctLBrace);
    setState(963);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx)) {
    case 1: {
      setState(948);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FlingHdlGrammarParser::KwDefault) {
        setState(947);
        flingDeclTask_Item_SwitchOrSwitchz_Default();
      }
      setState(953);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << FlingHdlGrammarParser::LitDecNum)
        | (1ULL << FlingHdlGrammarParser::LitHexNum)
        | (1ULL << FlingHdlGrammarParser::LitOctNum)
        | (1ULL << FlingHdlGrammarParser::LitBinNum)
        | (1ULL << FlingHdlGrammarParser::LitFloatNum)
        | (1ULL << FlingHdlGrammarParser::LitString)
        | (1ULL << FlingHdlGrammarParser::PunctPlus)
        | (1ULL << FlingHdlGrammarParser::PunctMinus)
        | (1ULL << FlingHdlGrammarParser::PunctBitOr)
        | (1ULL << FlingHdlGrammarParser::PunctBitNor)
        | (1ULL << FlingHdlGrammarParser::PunctBitAnd)
        | (1ULL << FlingHdlGrammarParser::PunctBitNand)
        | (1ULL << FlingHdlGrammarParser::PunctBitXor)
        | (1ULL << FlingHdlGrammarParser::PunctBitXnor)
        | (1ULL << FlingHdlGrammarParser::PunctBitNot)
        | (1ULL << FlingHdlGrammarParser::PunctLogNot)
        | (1ULL << FlingHdlGrammarParser::PunctLParen)
        | (1ULL << FlingHdlGrammarParser::KwMux))) != 0) || ((((_la - 78) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 78)) & ((1ULL << (FlingHdlGrammarParser::KwLogic - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwInteger - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSizeT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU8 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI8 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU16 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI16 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU32 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI32 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU64 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI64 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU128 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI128 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRetT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwAuto - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRange - 78))
        | (1ULL << (FlingHdlGrammarParser::KwHighZ - 78))
        | (1ULL << (FlingHdlGrammarParser::KwUnkX - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSized - 78))
        | (1ULL << (FlingHdlGrammarParser::KwCat - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRepl - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarSigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarUnsigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarPow - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarClog2 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwVoid - 78))
        | (1ULL << (FlingHdlGrammarParser::KwTypeof - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSelfT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwString - 78))
        | (1ULL << (FlingHdlGrammarParser::MiscIdent - 78)))) != 0)) {
        setState(950);
        flingDeclTask_Item_SwitchOrSwitchz_Case();
        setState(955);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      setState(957); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(956);
        flingDeclTask_Item_SwitchOrSwitchz_Case();
        setState(959); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << FlingHdlGrammarParser::LitDecNum)
        | (1ULL << FlingHdlGrammarParser::LitHexNum)
        | (1ULL << FlingHdlGrammarParser::LitOctNum)
        | (1ULL << FlingHdlGrammarParser::LitBinNum)
        | (1ULL << FlingHdlGrammarParser::LitFloatNum)
        | (1ULL << FlingHdlGrammarParser::LitString)
        | (1ULL << FlingHdlGrammarParser::PunctPlus)
        | (1ULL << FlingHdlGrammarParser::PunctMinus)
        | (1ULL << FlingHdlGrammarParser::PunctBitOr)
        | (1ULL << FlingHdlGrammarParser::PunctBitNor)
        | (1ULL << FlingHdlGrammarParser::PunctBitAnd)
        | (1ULL << FlingHdlGrammarParser::PunctBitNand)
        | (1ULL << FlingHdlGrammarParser::PunctBitXor)
        | (1ULL << FlingHdlGrammarParser::PunctBitXnor)
        | (1ULL << FlingHdlGrammarParser::PunctBitNot)
        | (1ULL << FlingHdlGrammarParser::PunctLogNot)
        | (1ULL << FlingHdlGrammarParser::PunctLParen)
        | (1ULL << FlingHdlGrammarParser::KwMux))) != 0) || ((((_la - 78) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 78)) & ((1ULL << (FlingHdlGrammarParser::KwLogic - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwInteger - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSizeT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU8 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI8 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU16 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI16 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU32 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI32 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU64 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI64 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwU128 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwI128 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRetT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwAuto - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRange - 78))
        | (1ULL << (FlingHdlGrammarParser::KwHighZ - 78))
        | (1ULL << (FlingHdlGrammarParser::KwUnkX - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSized - 78))
        | (1ULL << (FlingHdlGrammarParser::KwCat - 78))
        | (1ULL << (FlingHdlGrammarParser::KwRepl - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarSigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarUnsigned - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarPow - 78))
        | (1ULL << (FlingHdlGrammarParser::KwDollarClog2 - 78))
        | (1ULL << (FlingHdlGrammarParser::KwVoid - 78))
        | (1ULL << (FlingHdlGrammarParser::KwTypeof - 78))
        | (1ULL << (FlingHdlGrammarParser::KwSelfT - 78))
        | (1ULL << (FlingHdlGrammarParser::KwString - 78))
        | (1ULL << (FlingHdlGrammarParser::MiscIdent - 78)))) != 0));
      setState(961);
      flingDeclTask_Item_SwitchOrSwitchz_Default();
      break;
    }

    }
    setState(965);
    match(FlingHdlGrammarParser::PunctRBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext::FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext::KwDefault() {
  return getToken(FlingHdlGrammarParser::KwDefault, 0);
}

FlingHdlGrammarParser::FlingDeclTask_ScopeContext* FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext::flingDeclTask_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTask_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclTask_Item_SwitchOrSwitchz_Default;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclTask_Item_SwitchOrSwitchz_Default(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext* FlingHdlGrammarParser::flingDeclTask_Item_SwitchOrSwitchz_Default() {
  FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext *_localctx = _tracker.createInstance<FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext>(_ctx, getState());
  enterRule(_localctx, 166, FlingHdlGrammarParser::RuleFlingDeclTask_Item_SwitchOrSwitchz_Default);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(967);
    match(FlingHdlGrammarParser::KwDefault);
    setState(968);
    flingDeclTask_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclTask_Item_SwitchOrSwitchz_CaseContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_CaseContext::FlingDeclTask_Item_SwitchOrSwitchz_CaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExprListContext* FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_CaseContext::flingExprList() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprListContext>(0);
}

FlingHdlGrammarParser::FlingDeclTask_ScopeContext* FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_CaseContext::flingDeclTask_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTask_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_CaseContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclTask_Item_SwitchOrSwitchz_Case;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_CaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclTask_Item_SwitchOrSwitchz_Case(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclTask_Item_SwitchOrSwitchz_CaseContext* FlingHdlGrammarParser::flingDeclTask_Item_SwitchOrSwitchz_Case() {
  FlingDeclTask_Item_SwitchOrSwitchz_CaseContext *_localctx = _tracker.createInstance<FlingDeclTask_Item_SwitchOrSwitchz_CaseContext>(_ctx, getState());
  enterRule(_localctx, 168, FlingHdlGrammarParser::RuleFlingDeclTask_Item_SwitchOrSwitchz_Case);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(970);
    flingExprList();
    setState(971);
    flingDeclTask_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclTask_Item_ForContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclTask_Item_ForContext::FlingDeclTask_Item_ForContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclTask_Item_ForContext::KwFor() {
  return getToken(FlingHdlGrammarParser::KwFor, 0);
}

FlingHdlGrammarParser::FlingIdentContext* FlingHdlGrammarParser::FlingDeclTask_Item_ForContext::flingIdent() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclTask_Item_ForContext::PunctColon() {
  return getToken(FlingHdlGrammarParser::PunctColon, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingDeclTask_Item_ForContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

FlingHdlGrammarParser::FlingDeclTask_ScopeContext* FlingHdlGrammarParser::FlingDeclTask_Item_ForContext::flingDeclTask_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTask_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclTask_Item_ForContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclTask_Item_For;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclTask_Item_ForContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclTask_Item_For(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclTask_Item_ForContext* FlingHdlGrammarParser::flingDeclTask_Item_For() {
  FlingDeclTask_Item_ForContext *_localctx = _tracker.createInstance<FlingDeclTask_Item_ForContext>(_ctx, getState());
  enterRule(_localctx, 170, FlingHdlGrammarParser::RuleFlingDeclTask_Item_For);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(973);
    match(FlingHdlGrammarParser::KwFor);
    setState(974);
    flingIdent();
    setState(975);
    match(FlingHdlGrammarParser::PunctColon);
    setState(976);
    flingExpr();
    setState(977);
    flingDeclTask_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclTask_Item_WhileContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclTask_Item_WhileContext::FlingDeclTask_Item_WhileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclTask_Item_WhileContext::KwWhile() {
  return getToken(FlingHdlGrammarParser::KwWhile, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingDeclTask_Item_WhileContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

FlingHdlGrammarParser::FlingDeclTask_ScopeContext* FlingHdlGrammarParser::FlingDeclTask_Item_WhileContext::flingDeclTask_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclTask_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclTask_Item_WhileContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclTask_Item_While;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclTask_Item_WhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclTask_Item_While(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclTask_Item_WhileContext* FlingHdlGrammarParser::flingDeclTask_Item_While() {
  FlingDeclTask_Item_WhileContext *_localctx = _tracker.createInstance<FlingDeclTask_Item_WhileContext>(_ctx, getState());
  enterRule(_localctx, 172, FlingHdlGrammarParser::RuleFlingDeclTask_Item_While);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(979);
    match(FlingHdlGrammarParser::KwWhile);
    setState(980);
    flingExpr();
    setState(981);
    flingDeclTask_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclProcContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclProcContext::FlingDeclProcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingDeclProc_HeaderContext* FlingHdlGrammarParser::FlingDeclProcContext::flingDeclProc_Header() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclProc_HeaderContext>(0);
}

FlingHdlGrammarParser::FlingDeclModule_ScopeContext* FlingHdlGrammarParser::FlingDeclProcContext::flingDeclModule_Scope() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclModule_ScopeContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclProcContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclProc;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclProcContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclProc(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclProcContext* FlingHdlGrammarParser::flingDeclProc() {
  FlingDeclProcContext *_localctx = _tracker.createInstance<FlingDeclProcContext>(_ctx, getState());
  enterRule(_localctx, 174, FlingHdlGrammarParser::RuleFlingDeclProc);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(983);
    flingDeclProc_Header();
    setState(984);
    flingDeclModule_Scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclProc_HeaderContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclProc_HeaderContext::FlingDeclProc_HeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclProc_HeaderContext::KwProc() {
  return getToken(FlingHdlGrammarParser::KwProc, 0);
}

FlingHdlGrammarParser::FlingIdentContext* FlingHdlGrammarParser::FlingDeclProc_HeaderContext::flingIdent() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentContext>(0);
}

FlingHdlGrammarParser::FlingDeclProc_ArgListContext* FlingHdlGrammarParser::FlingDeclProc_HeaderContext::flingDeclProc_ArgList() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclProc_ArgListContext>(0);
}

FlingHdlGrammarParser::FlingDeclParamListContext* FlingHdlGrammarParser::FlingDeclProc_HeaderContext::flingDeclParamList() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclParamListContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclProc_HeaderContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclProc_Header;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclProc_HeaderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclProc_Header(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclProc_HeaderContext* FlingHdlGrammarParser::flingDeclProc_Header() {
  FlingDeclProc_HeaderContext *_localctx = _tracker.createInstance<FlingDeclProc_HeaderContext>(_ctx, getState());
  enterRule(_localctx, 176, FlingHdlGrammarParser::RuleFlingDeclProc_Header);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(986);
    match(FlingHdlGrammarParser::KwProc);
    setState(987);
    flingIdent();
    setState(989);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::PunctCmpLt) {
      setState(988);
      flingDeclParamList();
    }
    setState(991);
    flingDeclProc_ArgList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclProc_ArgListContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclProc_ArgListContext::FlingDeclProc_ArgListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclProc_ArgListContext::PunctLParen() {
  return getToken(FlingHdlGrammarParser::PunctLParen, 0);
}

std::vector<FlingHdlGrammarParser::FlingDeclProc_ArgList_ItemContext *> FlingHdlGrammarParser::FlingDeclProc_ArgListContext::flingDeclProc_ArgList_Item() {
  return getRuleContexts<FlingHdlGrammarParser::FlingDeclProc_ArgList_ItemContext>();
}

FlingHdlGrammarParser::FlingDeclProc_ArgList_ItemContext* FlingHdlGrammarParser::FlingDeclProc_ArgListContext::flingDeclProc_ArgList_Item(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclProc_ArgList_ItemContext>(i);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclProc_ArgListContext::PunctRParen() {
  return getToken(FlingHdlGrammarParser::PunctRParen, 0);
}

std::vector<tree::TerminalNode *> FlingHdlGrammarParser::FlingDeclProc_ArgListContext::PunctSemicolon() {
  return getTokens(FlingHdlGrammarParser::PunctSemicolon);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclProc_ArgListContext::PunctSemicolon(size_t i) {
  return getToken(FlingHdlGrammarParser::PunctSemicolon, i);
}


size_t FlingHdlGrammarParser::FlingDeclProc_ArgListContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclProc_ArgList;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclProc_ArgListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclProc_ArgList(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclProc_ArgListContext* FlingHdlGrammarParser::flingDeclProc_ArgList() {
  FlingDeclProc_ArgListContext *_localctx = _tracker.createInstance<FlingDeclProc_ArgListContext>(_ctx, getState());
  enterRule(_localctx, 178, FlingHdlGrammarParser::RuleFlingDeclProc_ArgList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(993);
    match(FlingHdlGrammarParser::PunctLParen);
    setState(994);
    flingDeclProc_ArgList_Item();
    setState(999);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(995);
        match(FlingHdlGrammarParser::PunctSemicolon);
        setState(996);
        flingDeclProc_ArgList_Item(); 
      }
      setState(1001);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx);
    }
    setState(1003);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::PunctSemicolon) {
      setState(1002);
      match(FlingHdlGrammarParser::PunctSemicolon);
    }
    setState(1005);
    match(FlingHdlGrammarParser::PunctRParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclProc_ArgList_ItemContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclProc_ArgList_ItemContext::FlingDeclProc_ArgList_ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingIdentListContext* FlingHdlGrammarParser::FlingDeclProc_ArgList_ItemContext::flingIdentList() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentListContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclProc_ArgList_ItemContext::PunctColon() {
  return getToken(FlingHdlGrammarParser::PunctColon, 0);
}

FlingHdlGrammarParser::FlingTypenameOrModnameContext* FlingHdlGrammarParser::FlingDeclProc_ArgList_ItemContext::flingTypenameOrModname() {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModnameContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclProc_ArgList_ItemContext::KwInput() {
  return getToken(FlingHdlGrammarParser::KwInput, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclProc_ArgList_ItemContext::KwInout() {
  return getToken(FlingHdlGrammarParser::KwInout, 0);
}


size_t FlingHdlGrammarParser::FlingDeclProc_ArgList_ItemContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclProc_ArgList_Item;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclProc_ArgList_ItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclProc_ArgList_Item(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclProc_ArgList_ItemContext* FlingHdlGrammarParser::flingDeclProc_ArgList_Item() {
  FlingDeclProc_ArgList_ItemContext *_localctx = _tracker.createInstance<FlingDeclProc_ArgList_ItemContext>(_ctx, getState());
  enterRule(_localctx, 180, FlingHdlGrammarParser::RuleFlingDeclProc_ArgList_Item);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1007);
    flingIdentList();
    setState(1008);
    match(FlingHdlGrammarParser::PunctColon);
    setState(1010);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::KwInput

    || _la == FlingHdlGrammarParser::KwInout) {
      setState(1009);
      _la = _input->LA(1);
      if (!(_la == FlingHdlGrammarParser::KwInput

      || _la == FlingHdlGrammarParser::KwInout)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(1012);
    flingTypenameOrModname();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclAliasContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclAliasContext::FlingDeclAliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingDeclAlias_ValueContext* FlingHdlGrammarParser::FlingDeclAliasContext::flingDeclAlias_Value() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclAlias_ValueContext>(0);
}

FlingHdlGrammarParser::FlingDeclAlias_TypeContext* FlingHdlGrammarParser::FlingDeclAliasContext::flingDeclAlias_Type() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclAlias_TypeContext>(0);
}

FlingHdlGrammarParser::FlingDeclAlias_ModuleContext* FlingHdlGrammarParser::FlingDeclAliasContext::flingDeclAlias_Module() {
  return getRuleContext<FlingHdlGrammarParser::FlingDeclAlias_ModuleContext>(0);
}


size_t FlingHdlGrammarParser::FlingDeclAliasContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclAlias;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclAliasContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclAlias(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclAliasContext* FlingHdlGrammarParser::flingDeclAlias() {
  FlingDeclAliasContext *_localctx = _tracker.createInstance<FlingDeclAliasContext>(_ctx, getState());
  enterRule(_localctx, 182, FlingHdlGrammarParser::RuleFlingDeclAlias);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1017);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1014);
      flingDeclAlias_Value();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1015);
      flingDeclAlias_Type();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1016);
      flingDeclAlias_Module();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclAlias_ValueContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclAlias_ValueContext::FlingDeclAlias_ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclAlias_ValueContext::KwAlias() {
  return getToken(FlingHdlGrammarParser::KwAlias, 0);
}

FlingHdlGrammarParser::FlingIdentListContext* FlingHdlGrammarParser::FlingDeclAlias_ValueContext::flingIdentList() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentListContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclAlias_ValueContext::PunctColon() {
  return getToken(FlingHdlGrammarParser::PunctColon, 0);
}

FlingHdlGrammarParser::FlingTypenameOrModnameContext* FlingHdlGrammarParser::FlingDeclAlias_ValueContext::flingTypenameOrModname() {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModnameContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclAlias_ValueContext::PunctBlkAssign() {
  return getToken(FlingHdlGrammarParser::PunctBlkAssign, 0);
}

FlingHdlGrammarParser::FlingExprListContext* FlingHdlGrammarParser::FlingDeclAlias_ValueContext::flingExprList() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprListContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclAlias_ValueContext::PunctSemicolon() {
  return getToken(FlingHdlGrammarParser::PunctSemicolon, 0);
}


size_t FlingHdlGrammarParser::FlingDeclAlias_ValueContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclAlias_Value;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclAlias_ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclAlias_Value(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclAlias_ValueContext* FlingHdlGrammarParser::flingDeclAlias_Value() {
  FlingDeclAlias_ValueContext *_localctx = _tracker.createInstance<FlingDeclAlias_ValueContext>(_ctx, getState());
  enterRule(_localctx, 184, FlingHdlGrammarParser::RuleFlingDeclAlias_Value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1019);
    match(FlingHdlGrammarParser::KwAlias);
    setState(1020);
    flingIdentList();
    setState(1021);
    match(FlingHdlGrammarParser::PunctColon);
    setState(1022);
    flingTypenameOrModname();
    setState(1023);
    match(FlingHdlGrammarParser::PunctBlkAssign);
    setState(1024);
    flingExprList();
    setState(1025);
    match(FlingHdlGrammarParser::PunctSemicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclAlias_TypeContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclAlias_TypeContext::FlingDeclAlias_TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclAlias_TypeContext::KwAlias() {
  return getToken(FlingHdlGrammarParser::KwAlias, 0);
}

FlingHdlGrammarParser::FlingIdentListContext* FlingHdlGrammarParser::FlingDeclAlias_TypeContext::flingIdentList() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentListContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclAlias_TypeContext::PunctColon() {
  return getToken(FlingHdlGrammarParser::PunctColon, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclAlias_TypeContext::KwType() {
  return getToken(FlingHdlGrammarParser::KwType, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclAlias_TypeContext::PunctBlkAssign() {
  return getToken(FlingHdlGrammarParser::PunctBlkAssign, 0);
}

FlingHdlGrammarParser::FlingTypenameOrModnameListContext* FlingHdlGrammarParser::FlingDeclAlias_TypeContext::flingTypenameOrModnameList() {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModnameListContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclAlias_TypeContext::PunctSemicolon() {
  return getToken(FlingHdlGrammarParser::PunctSemicolon, 0);
}


size_t FlingHdlGrammarParser::FlingDeclAlias_TypeContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclAlias_Type;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclAlias_TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclAlias_Type(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclAlias_TypeContext* FlingHdlGrammarParser::flingDeclAlias_Type() {
  FlingDeclAlias_TypeContext *_localctx = _tracker.createInstance<FlingDeclAlias_TypeContext>(_ctx, getState());
  enterRule(_localctx, 186, FlingHdlGrammarParser::RuleFlingDeclAlias_Type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1027);
    match(FlingHdlGrammarParser::KwAlias);
    setState(1028);
    flingIdentList();
    setState(1029);
    match(FlingHdlGrammarParser::PunctColon);
    setState(1030);
    match(FlingHdlGrammarParser::KwType);
    setState(1031);
    match(FlingHdlGrammarParser::PunctBlkAssign);
    setState(1032);
    flingTypenameOrModnameList();
    setState(1033);
    match(FlingHdlGrammarParser::PunctSemicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingDeclAlias_ModuleContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingDeclAlias_ModuleContext::FlingDeclAlias_ModuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclAlias_ModuleContext::KwAlias() {
  return getToken(FlingHdlGrammarParser::KwAlias, 0);
}

FlingHdlGrammarParser::FlingIdentListContext* FlingHdlGrammarParser::FlingDeclAlias_ModuleContext::flingIdentList() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentListContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclAlias_ModuleContext::PunctColon() {
  return getToken(FlingHdlGrammarParser::PunctColon, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclAlias_ModuleContext::KwModule() {
  return getToken(FlingHdlGrammarParser::KwModule, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclAlias_ModuleContext::PunctBlkAssign() {
  return getToken(FlingHdlGrammarParser::PunctBlkAssign, 0);
}

FlingHdlGrammarParser::FlingTypenameOrModnameListContext* FlingHdlGrammarParser::FlingDeclAlias_ModuleContext::flingTypenameOrModnameList() {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModnameListContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingDeclAlias_ModuleContext::PunctSemicolon() {
  return getToken(FlingHdlGrammarParser::PunctSemicolon, 0);
}


size_t FlingHdlGrammarParser::FlingDeclAlias_ModuleContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingDeclAlias_Module;
}


antlrcpp::Any FlingHdlGrammarParser::FlingDeclAlias_ModuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingDeclAlias_Module(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingDeclAlias_ModuleContext* FlingHdlGrammarParser::flingDeclAlias_Module() {
  FlingDeclAlias_ModuleContext *_localctx = _tracker.createInstance<FlingDeclAlias_ModuleContext>(_ctx, getState());
  enterRule(_localctx, 188, FlingHdlGrammarParser::RuleFlingDeclAlias_Module);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1035);
    match(FlingHdlGrammarParser::KwAlias);
    setState(1036);
    flingIdentList();
    setState(1037);
    match(FlingHdlGrammarParser::PunctColon);
    setState(1038);
    match(FlingHdlGrammarParser::KwModule);
    setState(1039);
    match(FlingHdlGrammarParser::PunctBlkAssign);
    setState(1040);
    flingTypenameOrModnameList();
    setState(1041);
    match(FlingHdlGrammarParser::PunctSemicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingIdentContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingIdentContext::FlingIdentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingIdentContext::MiscIdent() {
  return getToken(FlingHdlGrammarParser::MiscIdent, 0);
}


size_t FlingHdlGrammarParser::FlingIdentContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingIdent;
}


antlrcpp::Any FlingHdlGrammarParser::FlingIdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingIdent(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingIdentContext* FlingHdlGrammarParser::flingIdent() {
  FlingIdentContext *_localctx = _tracker.createInstance<FlingIdentContext>(_ctx, getState());
  enterRule(_localctx, 190, FlingHdlGrammarParser::RuleFlingIdent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1043);
    match(FlingHdlGrammarParser::MiscIdent);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingIdentListContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingIdentListContext::FlingIdentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FlingHdlGrammarParser::FlingIdentContext *> FlingHdlGrammarParser::FlingIdentListContext::flingIdent() {
  return getRuleContexts<FlingHdlGrammarParser::FlingIdentContext>();
}

FlingHdlGrammarParser::FlingIdentContext* FlingHdlGrammarParser::FlingIdentListContext::flingIdent(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentContext>(i);
}

std::vector<tree::TerminalNode *> FlingHdlGrammarParser::FlingIdentListContext::PunctComma() {
  return getTokens(FlingHdlGrammarParser::PunctComma);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingIdentListContext::PunctComma(size_t i) {
  return getToken(FlingHdlGrammarParser::PunctComma, i);
}


size_t FlingHdlGrammarParser::FlingIdentListContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingIdentList;
}


antlrcpp::Any FlingHdlGrammarParser::FlingIdentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingIdentList(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingIdentListContext* FlingHdlGrammarParser::flingIdentList() {
  FlingIdentListContext *_localctx = _tracker.createInstance<FlingIdentListContext>(_ctx, getState());
  enterRule(_localctx, 192, FlingHdlGrammarParser::RuleFlingIdentList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1045);
    flingIdent();
    setState(1050);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1046);
        match(FlingHdlGrammarParser::PunctComma);
        setState(1047);
        flingIdent(); 
      }
      setState(1052);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingScopedIdentContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingScopedIdentContext::FlingScopedIdentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FlingHdlGrammarParser::FlingIdentContext *> FlingHdlGrammarParser::FlingScopedIdentContext::flingIdent() {
  return getRuleContexts<FlingHdlGrammarParser::FlingIdentContext>();
}

FlingHdlGrammarParser::FlingIdentContext* FlingHdlGrammarParser::FlingScopedIdentContext::flingIdent(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentContext>(i);
}

std::vector<tree::TerminalNode *> FlingHdlGrammarParser::FlingScopedIdentContext::PunctScopeAccess() {
  return getTokens(FlingHdlGrammarParser::PunctScopeAccess);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingScopedIdentContext::PunctScopeAccess(size_t i) {
  return getToken(FlingHdlGrammarParser::PunctScopeAccess, i);
}


size_t FlingHdlGrammarParser::FlingScopedIdentContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingScopedIdent;
}


antlrcpp::Any FlingHdlGrammarParser::FlingScopedIdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingScopedIdent(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingScopedIdentContext* FlingHdlGrammarParser::flingScopedIdent() {
  FlingScopedIdentContext *_localctx = _tracker.createInstance<FlingScopedIdentContext>(_ctx, getState());
  enterRule(_localctx, 194, FlingHdlGrammarParser::RuleFlingScopedIdent);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1053);
    flingIdent();
    setState(1058);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FlingHdlGrammarParser::PunctScopeAccess) {
      setState(1054);
      match(FlingHdlGrammarParser::PunctScopeAccess);
      setState(1055);
      flingIdent();
      setState(1060);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExprListContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExprListContext::FlingExprListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FlingHdlGrammarParser::FlingExprContext *> FlingHdlGrammarParser::FlingExprListContext::flingExpr() {
  return getRuleContexts<FlingHdlGrammarParser::FlingExprContext>();
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExprListContext::flingExpr(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(i);
}

std::vector<tree::TerminalNode *> FlingHdlGrammarParser::FlingExprListContext::PunctComma() {
  return getTokens(FlingHdlGrammarParser::PunctComma);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExprListContext::PunctComma(size_t i) {
  return getToken(FlingHdlGrammarParser::PunctComma, i);
}


size_t FlingHdlGrammarParser::FlingExprListContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExprList;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExprListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExprList(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExprListContext* FlingHdlGrammarParser::flingExprList() {
  FlingExprListContext *_localctx = _tracker.createInstance<FlingExprListContext>(_ctx, getState());
  enterRule(_localctx, 196, FlingHdlGrammarParser::RuleFlingExprList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1061);
    flingExpr();
    setState(1066);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FlingHdlGrammarParser::PunctComma) {
      setState(1062);
      match(FlingHdlGrammarParser::PunctComma);
      setState(1063);
      flingExpr();
      setState(1068);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingTypenameOrModnameListContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingTypenameOrModnameListContext::FlingTypenameOrModnameListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FlingHdlGrammarParser::FlingTypenameOrModnameContext *> FlingHdlGrammarParser::FlingTypenameOrModnameListContext::flingTypenameOrModname() {
  return getRuleContexts<FlingHdlGrammarParser::FlingTypenameOrModnameContext>();
}

FlingHdlGrammarParser::FlingTypenameOrModnameContext* FlingHdlGrammarParser::FlingTypenameOrModnameListContext::flingTypenameOrModname(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModnameContext>(i);
}

std::vector<tree::TerminalNode *> FlingHdlGrammarParser::FlingTypenameOrModnameListContext::PunctComma() {
  return getTokens(FlingHdlGrammarParser::PunctComma);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModnameListContext::PunctComma(size_t i) {
  return getToken(FlingHdlGrammarParser::PunctComma, i);
}


size_t FlingHdlGrammarParser::FlingTypenameOrModnameListContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingTypenameOrModnameList;
}


antlrcpp::Any FlingHdlGrammarParser::FlingTypenameOrModnameListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingTypenameOrModnameList(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingTypenameOrModnameListContext* FlingHdlGrammarParser::flingTypenameOrModnameList() {
  FlingTypenameOrModnameListContext *_localctx = _tracker.createInstance<FlingTypenameOrModnameListContext>(_ctx, getState());
  enterRule(_localctx, 198, FlingHdlGrammarParser::RuleFlingTypenameOrModnameList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1069);
    flingTypenameOrModname();
    setState(1074);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FlingHdlGrammarParser::PunctComma) {
      setState(1070);
      match(FlingHdlGrammarParser::PunctComma);
      setState(1071);
      flingTypenameOrModname();
      setState(1076);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingImportListContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingImportListContext::FlingImportListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingImportListContext::KwImport() {
  return getToken(FlingHdlGrammarParser::KwImport, 0);
}

std::vector<FlingHdlGrammarParser::FlingScopedIdentContext *> FlingHdlGrammarParser::FlingImportListContext::flingScopedIdent() {
  return getRuleContexts<FlingHdlGrammarParser::FlingScopedIdentContext>();
}

FlingHdlGrammarParser::FlingScopedIdentContext* FlingHdlGrammarParser::FlingImportListContext::flingScopedIdent(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingScopedIdentContext>(i);
}

std::vector<tree::TerminalNode *> FlingHdlGrammarParser::FlingImportListContext::PunctComma() {
  return getTokens(FlingHdlGrammarParser::PunctComma);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingImportListContext::PunctComma(size_t i) {
  return getToken(FlingHdlGrammarParser::PunctComma, i);
}


size_t FlingHdlGrammarParser::FlingImportListContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingImportList;
}


antlrcpp::Any FlingHdlGrammarParser::FlingImportListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingImportList(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingImportListContext* FlingHdlGrammarParser::flingImportList() {
  FlingImportListContext *_localctx = _tracker.createInstance<FlingImportListContext>(_ctx, getState());
  enterRule(_localctx, 200, FlingHdlGrammarParser::RuleFlingImportList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1077);
    match(FlingHdlGrammarParser::KwImport);
    setState(1078);
    flingScopedIdent();
    setState(1083);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FlingHdlGrammarParser::PunctComma) {
      setState(1079);
      match(FlingHdlGrammarParser::PunctComma);
      setState(1080);
      flingScopedIdent();
      setState(1085);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingTypenameOrModnameContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingTypenameOrModnameContext::FlingTypenameOrModnameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingTypenameOrModname_CstmContext* FlingHdlGrammarParser::FlingTypenameOrModnameContext::flingTypenameOrModname_Cstm() {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModname_CstmContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModnameContext::KwSelfT() {
  return getToken(FlingHdlGrammarParser::KwSelfT, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModnameContext::KwRetT() {
  return getToken(FlingHdlGrammarParser::KwRetT, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModnameContext::KwTypeof() {
  return getToken(FlingHdlGrammarParser::KwTypeof, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModnameContext::PunctLParen() {
  return getToken(FlingHdlGrammarParser::PunctLParen, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingTypenameOrModnameContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModnameContext::PunctRParen() {
  return getToken(FlingHdlGrammarParser::PunctRParen, 0);
}

FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext* FlingHdlGrammarParser::FlingTypenameOrModnameContext::flingTypenameOrModname_Builtin() {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext>(0);
}


size_t FlingHdlGrammarParser::FlingTypenameOrModnameContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingTypenameOrModname;
}


antlrcpp::Any FlingHdlGrammarParser::FlingTypenameOrModnameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingTypenameOrModname(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingTypenameOrModnameContext* FlingHdlGrammarParser::flingTypenameOrModname() {
  FlingTypenameOrModnameContext *_localctx = _tracker.createInstance<FlingTypenameOrModnameContext>(_ctx, getState());
  enterRule(_localctx, 202, FlingHdlGrammarParser::RuleFlingTypenameOrModname);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1095);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FlingHdlGrammarParser::MiscIdent: {
        enterOuterAlt(_localctx, 1);
        setState(1086);
        flingTypenameOrModname_Cstm();
        break;
      }

      case FlingHdlGrammarParser::KwSelfT: {
        enterOuterAlt(_localctx, 2);
        setState(1087);
        match(FlingHdlGrammarParser::KwSelfT);
        break;
      }

      case FlingHdlGrammarParser::KwRetT: {
        enterOuterAlt(_localctx, 3);
        setState(1088);
        match(FlingHdlGrammarParser::KwRetT);
        break;
      }

      case FlingHdlGrammarParser::KwTypeof: {
        enterOuterAlt(_localctx, 4);
        setState(1089);
        match(FlingHdlGrammarParser::KwTypeof);
        setState(1090);
        match(FlingHdlGrammarParser::PunctLParen);
        setState(1091);
        flingExpr();
        setState(1092);
        match(FlingHdlGrammarParser::PunctRParen);
        break;
      }

      case FlingHdlGrammarParser::KwLogic:
      case FlingHdlGrammarParser::KwSigned:
      case FlingHdlGrammarParser::KwInteger:
      case FlingHdlGrammarParser::KwSizeT:
      case FlingHdlGrammarParser::KwU8:
      case FlingHdlGrammarParser::KwI8:
      case FlingHdlGrammarParser::KwU16:
      case FlingHdlGrammarParser::KwI16:
      case FlingHdlGrammarParser::KwU32:
      case FlingHdlGrammarParser::KwI32:
      case FlingHdlGrammarParser::KwU64:
      case FlingHdlGrammarParser::KwI64:
      case FlingHdlGrammarParser::KwU128:
      case FlingHdlGrammarParser::KwI128:
      case FlingHdlGrammarParser::KwAuto:
      case FlingHdlGrammarParser::KwRange:
      case FlingHdlGrammarParser::KwVoid:
      case FlingHdlGrammarParser::KwString: {
        enterOuterAlt(_localctx, 5);
        setState(1094);
        flingTypenameOrModname_Builtin();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingTypenameOrModname_CstmContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingTypenameOrModname_CstmContext::FlingTypenameOrModname_CstmContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FlingHdlGrammarParser::FlingTypenameOrModname_Cstm_ItemContext *> FlingHdlGrammarParser::FlingTypenameOrModname_CstmContext::flingTypenameOrModname_Cstm_Item() {
  return getRuleContexts<FlingHdlGrammarParser::FlingTypenameOrModname_Cstm_ItemContext>();
}

FlingHdlGrammarParser::FlingTypenameOrModname_Cstm_ItemContext* FlingHdlGrammarParser::FlingTypenameOrModname_CstmContext::flingTypenameOrModname_Cstm_Item(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModname_Cstm_ItemContext>(i);
}

std::vector<tree::TerminalNode *> FlingHdlGrammarParser::FlingTypenameOrModname_CstmContext::PunctScopeAccess() {
  return getTokens(FlingHdlGrammarParser::PunctScopeAccess);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModname_CstmContext::PunctScopeAccess(size_t i) {
  return getToken(FlingHdlGrammarParser::PunctScopeAccess, i);
}

std::vector<FlingHdlGrammarParser::FlingTypenameOrModname_ArrDimContext *> FlingHdlGrammarParser::FlingTypenameOrModname_CstmContext::flingTypenameOrModname_ArrDim() {
  return getRuleContexts<FlingHdlGrammarParser::FlingTypenameOrModname_ArrDimContext>();
}

FlingHdlGrammarParser::FlingTypenameOrModname_ArrDimContext* FlingHdlGrammarParser::FlingTypenameOrModname_CstmContext::flingTypenameOrModname_ArrDim(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModname_ArrDimContext>(i);
}


size_t FlingHdlGrammarParser::FlingTypenameOrModname_CstmContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingTypenameOrModname_Cstm;
}


antlrcpp::Any FlingHdlGrammarParser::FlingTypenameOrModname_CstmContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingTypenameOrModname_Cstm(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingTypenameOrModname_CstmContext* FlingHdlGrammarParser::flingTypenameOrModname_Cstm() {
  FlingTypenameOrModname_CstmContext *_localctx = _tracker.createInstance<FlingTypenameOrModname_CstmContext>(_ctx, getState());
  enterRule(_localctx, 204, FlingHdlGrammarParser::RuleFlingTypenameOrModname_Cstm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1097);
    flingTypenameOrModname_Cstm_Item();
    setState(1102);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1098);
        match(FlingHdlGrammarParser::PunctScopeAccess);
        setState(1099);
        flingTypenameOrModname_Cstm_Item(); 
      }
      setState(1104);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx);
    }
    setState(1108);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FlingHdlGrammarParser::PunctLBracket) {
      setState(1105);
      flingTypenameOrModname_ArrDim();
      setState(1110);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingTypenameOrModname_Cstm_ItemContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingTypenameOrModname_Cstm_ItemContext::FlingTypenameOrModname_Cstm_ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingIdentContext* FlingHdlGrammarParser::FlingTypenameOrModname_Cstm_ItemContext::flingIdent() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentContext>(0);
}

FlingHdlGrammarParser::FlingInstParamListContext* FlingHdlGrammarParser::FlingTypenameOrModname_Cstm_ItemContext::flingInstParamList() {
  return getRuleContext<FlingHdlGrammarParser::FlingInstParamListContext>(0);
}


size_t FlingHdlGrammarParser::FlingTypenameOrModname_Cstm_ItemContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingTypenameOrModname_Cstm_Item;
}


antlrcpp::Any FlingHdlGrammarParser::FlingTypenameOrModname_Cstm_ItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingTypenameOrModname_Cstm_Item(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingTypenameOrModname_Cstm_ItemContext* FlingHdlGrammarParser::flingTypenameOrModname_Cstm_Item() {
  FlingTypenameOrModname_Cstm_ItemContext *_localctx = _tracker.createInstance<FlingTypenameOrModname_Cstm_ItemContext>(_ctx, getState());
  enterRule(_localctx, 206, FlingHdlGrammarParser::RuleFlingTypenameOrModname_Cstm_Item);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1111);
    flingIdent();
    setState(1113);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::PunctCmpLt) {
      setState(1112);
      flingInstParamList();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingTypenameOrModname_ArrDimContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingTypenameOrModname_ArrDimContext::FlingTypenameOrModname_ArrDimContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModname_ArrDimContext::PunctLBracket() {
  return getToken(FlingHdlGrammarParser::PunctLBracket, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModname_ArrDimContext::PunctRBracket() {
  return getToken(FlingHdlGrammarParser::PunctRBracket, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingTypenameOrModname_ArrDimContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

FlingHdlGrammarParser::FlingTypenameOrModnameContext* FlingHdlGrammarParser::FlingTypenameOrModname_ArrDimContext::flingTypenameOrModname() {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModnameContext>(0);
}


size_t FlingHdlGrammarParser::FlingTypenameOrModname_ArrDimContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingTypenameOrModname_ArrDim;
}


antlrcpp::Any FlingHdlGrammarParser::FlingTypenameOrModname_ArrDimContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingTypenameOrModname_ArrDim(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingTypenameOrModname_ArrDimContext* FlingHdlGrammarParser::flingTypenameOrModname_ArrDim() {
  FlingTypenameOrModname_ArrDimContext *_localctx = _tracker.createInstance<FlingTypenameOrModname_ArrDimContext>(_ctx, getState());
  enterRule(_localctx, 208, FlingHdlGrammarParser::RuleFlingTypenameOrModname_ArrDim);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1115);
    match(FlingHdlGrammarParser::PunctLBracket);
    setState(1118);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx)) {
    case 1: {
      setState(1116);
      flingExpr();
      break;
    }

    case 2: {
      setState(1117);
      flingTypenameOrModname();
      break;
    }

    }
    setState(1120);
    match(FlingHdlGrammarParser::PunctRBracket);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingTypenameOrModname_BuiltinContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::FlingTypenameOrModname_BuiltinContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::KwLogic() {
  return getToken(FlingHdlGrammarParser::KwLogic, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::KwInteger() {
  return getToken(FlingHdlGrammarParser::KwInteger, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::KwSizeT() {
  return getToken(FlingHdlGrammarParser::KwSizeT, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::KwRange() {
  return getToken(FlingHdlGrammarParser::KwRange, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::KwString() {
  return getToken(FlingHdlGrammarParser::KwString, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::KwU8() {
  return getToken(FlingHdlGrammarParser::KwU8, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::KwI8() {
  return getToken(FlingHdlGrammarParser::KwI8, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::KwU16() {
  return getToken(FlingHdlGrammarParser::KwU16, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::KwI16() {
  return getToken(FlingHdlGrammarParser::KwI16, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::KwU32() {
  return getToken(FlingHdlGrammarParser::KwU32, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::KwI32() {
  return getToken(FlingHdlGrammarParser::KwI32, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::KwU64() {
  return getToken(FlingHdlGrammarParser::KwU64, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::KwI64() {
  return getToken(FlingHdlGrammarParser::KwI64, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::KwU128() {
  return getToken(FlingHdlGrammarParser::KwU128, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::KwI128() {
  return getToken(FlingHdlGrammarParser::KwI128, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::KwAuto() {
  return getToken(FlingHdlGrammarParser::KwAuto, 0);
}

std::vector<FlingHdlGrammarParser::FlingTypenameOrModname_ArrDimContext *> FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::flingTypenameOrModname_ArrDim() {
  return getRuleContexts<FlingHdlGrammarParser::FlingTypenameOrModname_ArrDimContext>();
}

FlingHdlGrammarParser::FlingTypenameOrModname_ArrDimContext* FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::flingTypenameOrModname_ArrDim(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModname_ArrDimContext>(i);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::KwSigned() {
  return getToken(FlingHdlGrammarParser::KwSigned, 0);
}

FlingHdlGrammarParser::FlingInstParamListContext* FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::flingInstParamList() {
  return getRuleContext<FlingHdlGrammarParser::FlingInstParamListContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::KwVoid() {
  return getToken(FlingHdlGrammarParser::KwVoid, 0);
}


size_t FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingTypenameOrModname_Builtin;
}


antlrcpp::Any FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingTypenameOrModname_Builtin(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingTypenameOrModname_BuiltinContext* FlingHdlGrammarParser::flingTypenameOrModname_Builtin() {
  FlingTypenameOrModname_BuiltinContext *_localctx = _tracker.createInstance<FlingTypenameOrModname_BuiltinContext>(_ctx, getState());
  enterRule(_localctx, 210, FlingHdlGrammarParser::RuleFlingTypenameOrModname_Builtin);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1153);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FlingHdlGrammarParser::KwLogic:
      case FlingHdlGrammarParser::KwSigned:
      case FlingHdlGrammarParser::KwInteger:
      case FlingHdlGrammarParser::KwSizeT:
      case FlingHdlGrammarParser::KwU8:
      case FlingHdlGrammarParser::KwI8:
      case FlingHdlGrammarParser::KwU16:
      case FlingHdlGrammarParser::KwI16:
      case FlingHdlGrammarParser::KwU32:
      case FlingHdlGrammarParser::KwI32:
      case FlingHdlGrammarParser::KwU64:
      case FlingHdlGrammarParser::KwI64:
      case FlingHdlGrammarParser::KwU128:
      case FlingHdlGrammarParser::KwI128:
      case FlingHdlGrammarParser::KwAuto:
      case FlingHdlGrammarParser::KwRange:
      case FlingHdlGrammarParser::KwString: {
        enterOuterAlt(_localctx, 1);
        setState(1144);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case FlingHdlGrammarParser::KwLogic:
          case FlingHdlGrammarParser::KwSigned: {
            setState(1123);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == FlingHdlGrammarParser::KwSigned) {
              setState(1122);
              match(FlingHdlGrammarParser::KwSigned);
            }
            setState(1125);
            match(FlingHdlGrammarParser::KwLogic);
            setState(1127);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == FlingHdlGrammarParser::PunctCmpLt) {
              setState(1126);
              flingInstParamList();
            }
            break;
          }

          case FlingHdlGrammarParser::KwInteger: {
            setState(1129);
            match(FlingHdlGrammarParser::KwInteger);
            break;
          }

          case FlingHdlGrammarParser::KwSizeT: {
            setState(1130);
            match(FlingHdlGrammarParser::KwSizeT);
            break;
          }

          case FlingHdlGrammarParser::KwRange: {
            setState(1131);
            match(FlingHdlGrammarParser::KwRange);
            break;
          }

          case FlingHdlGrammarParser::KwString: {
            setState(1132);
            match(FlingHdlGrammarParser::KwString);
            break;
          }

          case FlingHdlGrammarParser::KwU8: {
            setState(1133);
            match(FlingHdlGrammarParser::KwU8);
            break;
          }

          case FlingHdlGrammarParser::KwI8: {
            setState(1134);
            match(FlingHdlGrammarParser::KwI8);
            break;
          }

          case FlingHdlGrammarParser::KwU16: {
            setState(1135);
            match(FlingHdlGrammarParser::KwU16);
            break;
          }

          case FlingHdlGrammarParser::KwI16: {
            setState(1136);
            match(FlingHdlGrammarParser::KwI16);
            break;
          }

          case FlingHdlGrammarParser::KwU32: {
            setState(1137);
            match(FlingHdlGrammarParser::KwU32);
            break;
          }

          case FlingHdlGrammarParser::KwI32: {
            setState(1138);
            match(FlingHdlGrammarParser::KwI32);
            break;
          }

          case FlingHdlGrammarParser::KwU64: {
            setState(1139);
            match(FlingHdlGrammarParser::KwU64);
            break;
          }

          case FlingHdlGrammarParser::KwI64: {
            setState(1140);
            match(FlingHdlGrammarParser::KwI64);
            break;
          }

          case FlingHdlGrammarParser::KwU128: {
            setState(1141);
            match(FlingHdlGrammarParser::KwU128);
            break;
          }

          case FlingHdlGrammarParser::KwI128: {
            setState(1142);
            match(FlingHdlGrammarParser::KwI128);
            break;
          }

          case FlingHdlGrammarParser::KwAuto: {
            setState(1143);
            match(FlingHdlGrammarParser::KwAuto);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(1149);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == FlingHdlGrammarParser::PunctLBracket) {
          setState(1146);
          flingTypenameOrModname_ArrDim();
          setState(1151);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case FlingHdlGrammarParser::KwVoid: {
        enterOuterAlt(_localctx, 2);
        setState(1152);
        match(FlingHdlGrammarParser::KwVoid);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExprContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExprContext::FlingExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExprContext::KwMux() {
  return getToken(FlingHdlGrammarParser::KwMux, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExprContext::PunctLParen() {
  return getToken(FlingHdlGrammarParser::PunctLParen, 0);
}

std::vector<FlingHdlGrammarParser::FlingExprContext *> FlingHdlGrammarParser::FlingExprContext::flingExpr() {
  return getRuleContexts<FlingHdlGrammarParser::FlingExprContext>();
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExprContext::flingExpr(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(i);
}

std::vector<tree::TerminalNode *> FlingHdlGrammarParser::FlingExprContext::PunctComma() {
  return getTokens(FlingHdlGrammarParser::PunctComma);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExprContext::PunctComma(size_t i) {
  return getToken(FlingHdlGrammarParser::PunctComma, i);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExprContext::PunctRParen() {
  return getToken(FlingHdlGrammarParser::PunctRParen, 0);
}

FlingHdlGrammarParser::FlingExpr_MuxContext* FlingHdlGrammarParser::FlingExprContext::flingExpr_Mux() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_MuxContext>(0);
}


size_t FlingHdlGrammarParser::FlingExprContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::flingExpr() {
  FlingExprContext *_localctx = _tracker.createInstance<FlingExprContext>(_ctx, getState());
  enterRule(_localctx, 212, FlingHdlGrammarParser::RuleFlingExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1165);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FlingHdlGrammarParser::KwMux: {
        enterOuterAlt(_localctx, 1);
        setState(1155);
        match(FlingHdlGrammarParser::KwMux);
        setState(1156);
        match(FlingHdlGrammarParser::PunctLParen);
        setState(1157);
        flingExpr();
        setState(1158);
        match(FlingHdlGrammarParser::PunctComma);
        setState(1159);
        flingExpr();
        setState(1160);
        match(FlingHdlGrammarParser::PunctComma);
        setState(1161);
        flingExpr();
        setState(1162);
        match(FlingHdlGrammarParser::PunctRParen);
        break;
      }

      case FlingHdlGrammarParser::LitDecNum:
      case FlingHdlGrammarParser::LitHexNum:
      case FlingHdlGrammarParser::LitOctNum:
      case FlingHdlGrammarParser::LitBinNum:
      case FlingHdlGrammarParser::LitFloatNum:
      case FlingHdlGrammarParser::LitString:
      case FlingHdlGrammarParser::PunctPlus:
      case FlingHdlGrammarParser::PunctMinus:
      case FlingHdlGrammarParser::PunctBitOr:
      case FlingHdlGrammarParser::PunctBitNor:
      case FlingHdlGrammarParser::PunctBitAnd:
      case FlingHdlGrammarParser::PunctBitNand:
      case FlingHdlGrammarParser::PunctBitXor:
      case FlingHdlGrammarParser::PunctBitXnor:
      case FlingHdlGrammarParser::PunctBitNot:
      case FlingHdlGrammarParser::PunctLogNot:
      case FlingHdlGrammarParser::PunctLParen:
      case FlingHdlGrammarParser::KwLogic:
      case FlingHdlGrammarParser::KwSigned:
      case FlingHdlGrammarParser::KwInteger:
      case FlingHdlGrammarParser::KwSizeT:
      case FlingHdlGrammarParser::KwU8:
      case FlingHdlGrammarParser::KwI8:
      case FlingHdlGrammarParser::KwU16:
      case FlingHdlGrammarParser::KwI16:
      case FlingHdlGrammarParser::KwU32:
      case FlingHdlGrammarParser::KwI32:
      case FlingHdlGrammarParser::KwU64:
      case FlingHdlGrammarParser::KwI64:
      case FlingHdlGrammarParser::KwU128:
      case FlingHdlGrammarParser::KwI128:
      case FlingHdlGrammarParser::KwRetT:
      case FlingHdlGrammarParser::KwAuto:
      case FlingHdlGrammarParser::KwRange:
      case FlingHdlGrammarParser::KwHighZ:
      case FlingHdlGrammarParser::KwUnkX:
      case FlingHdlGrammarParser::KwSized:
      case FlingHdlGrammarParser::KwCat:
      case FlingHdlGrammarParser::KwRepl:
      case FlingHdlGrammarParser::KwDollarSigned:
      case FlingHdlGrammarParser::KwDollarUnsigned:
      case FlingHdlGrammarParser::KwDollarPow:
      case FlingHdlGrammarParser::KwDollarClog2:
      case FlingHdlGrammarParser::KwVoid:
      case FlingHdlGrammarParser::KwTypeof:
      case FlingHdlGrammarParser::KwSelfT:
      case FlingHdlGrammarParser::KwString:
      case FlingHdlGrammarParser::MiscIdent: {
        enterOuterAlt(_localctx, 2);
        setState(1164);
        flingExpr_Mux();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_MuxContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_MuxContext::FlingExpr_MuxContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExpr_LogOrContext* FlingHdlGrammarParser::FlingExpr_MuxContext::flingExpr_LogOr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_LogOrContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_MuxContext::PunctLogOr() {
  return getToken(FlingHdlGrammarParser::PunctLogOr, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExpr_MuxContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}


size_t FlingHdlGrammarParser::FlingExpr_MuxContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_Mux;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_MuxContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_Mux(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_MuxContext* FlingHdlGrammarParser::flingExpr_Mux() {
  FlingExpr_MuxContext *_localctx = _tracker.createInstance<FlingExpr_MuxContext>(_ctx, getState());
  enterRule(_localctx, 214, FlingHdlGrammarParser::RuleFlingExpr_Mux);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1167);
    flingExpr_LogOr();
    setState(1170);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx)) {
    case 1: {
      setState(1168);
      match(FlingHdlGrammarParser::PunctLogOr);
      setState(1169);
      flingExpr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_LogOrContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_LogOrContext::FlingExpr_LogOrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExpr_LogAndContext* FlingHdlGrammarParser::FlingExpr_LogOrContext::flingExpr_LogAnd() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_LogAndContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_LogOrContext::PunctLogAnd() {
  return getToken(FlingHdlGrammarParser::PunctLogAnd, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExpr_LogOrContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}


size_t FlingHdlGrammarParser::FlingExpr_LogOrContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_LogOr;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_LogOrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_LogOr(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_LogOrContext* FlingHdlGrammarParser::flingExpr_LogOr() {
  FlingExpr_LogOrContext *_localctx = _tracker.createInstance<FlingExpr_LogOrContext>(_ctx, getState());
  enterRule(_localctx, 216, FlingHdlGrammarParser::RuleFlingExpr_LogOr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1172);
    flingExpr_LogAnd();
    setState(1175);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 110, _ctx)) {
    case 1: {
      setState(1173);
      match(FlingHdlGrammarParser::PunctLogAnd);
      setState(1174);
      flingExpr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_LogAndContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_LogAndContext::FlingExpr_LogAndContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExpr_BitOr_Or_BitNorContext* FlingHdlGrammarParser::FlingExpr_LogAndContext::flingExpr_BitOr_Or_BitNor() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_BitOr_Or_BitNorContext>(0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExpr_LogAndContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_LogAndContext::PunctBitOr() {
  return getToken(FlingHdlGrammarParser::PunctBitOr, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_LogAndContext::PunctBitNor() {
  return getToken(FlingHdlGrammarParser::PunctBitNor, 0);
}


size_t FlingHdlGrammarParser::FlingExpr_LogAndContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_LogAnd;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_LogAndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_LogAnd(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_LogAndContext* FlingHdlGrammarParser::flingExpr_LogAnd() {
  FlingExpr_LogAndContext *_localctx = _tracker.createInstance<FlingExpr_LogAndContext>(_ctx, getState());
  enterRule(_localctx, 218, FlingHdlGrammarParser::RuleFlingExpr_LogAnd);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1177);
    flingExpr_BitOr_Or_BitNor();
    setState(1180);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 111, _ctx)) {
    case 1: {
      setState(1178);
      _la = _input->LA(1);
      if (!(_la == FlingHdlGrammarParser::PunctBitOr

      || _la == FlingHdlGrammarParser::PunctBitNor)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1179);
      flingExpr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_BitOr_Or_BitNorContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_BitOr_Or_BitNorContext::FlingExpr_BitOr_Or_BitNorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExpr_BitAnd_Or_BitNandContext* FlingHdlGrammarParser::FlingExpr_BitOr_Or_BitNorContext::flingExpr_BitAnd_Or_BitNand() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_BitAnd_Or_BitNandContext>(0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExpr_BitOr_Or_BitNorContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_BitOr_Or_BitNorContext::PunctBitAnd() {
  return getToken(FlingHdlGrammarParser::PunctBitAnd, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_BitOr_Or_BitNorContext::PunctBitNand() {
  return getToken(FlingHdlGrammarParser::PunctBitNand, 0);
}


size_t FlingHdlGrammarParser::FlingExpr_BitOr_Or_BitNorContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_BitOr_Or_BitNor;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_BitOr_Or_BitNorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_BitOr_Or_BitNor(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_BitOr_Or_BitNorContext* FlingHdlGrammarParser::flingExpr_BitOr_Or_BitNor() {
  FlingExpr_BitOr_Or_BitNorContext *_localctx = _tracker.createInstance<FlingExpr_BitOr_Or_BitNorContext>(_ctx, getState());
  enterRule(_localctx, 220, FlingHdlGrammarParser::RuleFlingExpr_BitOr_Or_BitNor);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1182);
    flingExpr_BitAnd_Or_BitNand();
    setState(1185);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 112, _ctx)) {
    case 1: {
      setState(1183);
      _la = _input->LA(1);
      if (!(_la == FlingHdlGrammarParser::PunctBitAnd

      || _la == FlingHdlGrammarParser::PunctBitNand)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1184);
      flingExpr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_BitAnd_Or_BitNandContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_BitAnd_Or_BitNandContext::FlingExpr_BitAnd_Or_BitNandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExpr_BitXor_Or_BitXnorContext* FlingHdlGrammarParser::FlingExpr_BitAnd_Or_BitNandContext::flingExpr_BitXor_Or_BitXnor() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_BitXor_Or_BitXnorContext>(0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExpr_BitAnd_Or_BitNandContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_BitAnd_Or_BitNandContext::PunctBitXor() {
  return getToken(FlingHdlGrammarParser::PunctBitXor, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_BitAnd_Or_BitNandContext::PunctBitXnor() {
  return getToken(FlingHdlGrammarParser::PunctBitXnor, 0);
}


size_t FlingHdlGrammarParser::FlingExpr_BitAnd_Or_BitNandContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_BitAnd_Or_BitNand;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_BitAnd_Or_BitNandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_BitAnd_Or_BitNand(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_BitAnd_Or_BitNandContext* FlingHdlGrammarParser::flingExpr_BitAnd_Or_BitNand() {
  FlingExpr_BitAnd_Or_BitNandContext *_localctx = _tracker.createInstance<FlingExpr_BitAnd_Or_BitNandContext>(_ctx, getState());
  enterRule(_localctx, 222, FlingHdlGrammarParser::RuleFlingExpr_BitAnd_Or_BitNand);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1187);
    flingExpr_BitXor_Or_BitXnor();
    setState(1190);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 113, _ctx)) {
    case 1: {
      setState(1188);
      _la = _input->LA(1);
      if (!(_la == FlingHdlGrammarParser::PunctBitXor

      || _la == FlingHdlGrammarParser::PunctBitXnor)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1189);
      flingExpr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_BitXor_Or_BitXnorContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_BitXor_Or_BitXnorContext::FlingExpr_BitXor_Or_BitXnorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExpr_CmpEqEtcContext* FlingHdlGrammarParser::FlingExpr_BitXor_Or_BitXnorContext::flingExpr_CmpEqEtc() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_CmpEqEtcContext>(0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExpr_BitXor_Or_BitXnorContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_BitXor_Or_BitXnorContext::PunctCmpEq() {
  return getToken(FlingHdlGrammarParser::PunctCmpEq, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_BitXor_Or_BitXnorContext::PunctCmpNe() {
  return getToken(FlingHdlGrammarParser::PunctCmpNe, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_BitXor_Or_BitXnorContext::PunctCaseCmpEq() {
  return getToken(FlingHdlGrammarParser::PunctCaseCmpEq, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_BitXor_Or_BitXnorContext::PunctCaseCmpNe() {
  return getToken(FlingHdlGrammarParser::PunctCaseCmpNe, 0);
}


size_t FlingHdlGrammarParser::FlingExpr_BitXor_Or_BitXnorContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_BitXor_Or_BitXnor;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_BitXor_Or_BitXnorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_BitXor_Or_BitXnor(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_BitXor_Or_BitXnorContext* FlingHdlGrammarParser::flingExpr_BitXor_Or_BitXnor() {
  FlingExpr_BitXor_Or_BitXnorContext *_localctx = _tracker.createInstance<FlingExpr_BitXor_Or_BitXnorContext>(_ctx, getState());
  enterRule(_localctx, 224, FlingHdlGrammarParser::RuleFlingExpr_BitXor_Or_BitXnor);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1192);
    flingExpr_CmpEqEtc();
    setState(1195);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 114, _ctx)) {
    case 1: {
      setState(1193);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << FlingHdlGrammarParser::PunctCmpEq)
        | (1ULL << FlingHdlGrammarParser::PunctCmpNe)
        | (1ULL << FlingHdlGrammarParser::PunctCaseCmpEq)
        | (1ULL << FlingHdlGrammarParser::PunctCaseCmpNe))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1194);
      flingExpr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_CmpEqEtcContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_CmpEqEtcContext::FlingExpr_CmpEqEtcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExpr_CmpLtEtcContext* FlingHdlGrammarParser::FlingExpr_CmpEqEtcContext::flingExpr_CmpLtEtc() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_CmpLtEtcContext>(0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExpr_CmpEqEtcContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_CmpEqEtcContext::PunctCmpLt() {
  return getToken(FlingHdlGrammarParser::PunctCmpLt, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_CmpEqEtcContext::PunctCmpLe() {
  return getToken(FlingHdlGrammarParser::PunctCmpLe, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_CmpEqEtcContext::PunctCmpGt() {
  return getToken(FlingHdlGrammarParser::PunctCmpGt, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_CmpEqEtcContext::PunctCmpGe() {
  return getToken(FlingHdlGrammarParser::PunctCmpGe, 0);
}


size_t FlingHdlGrammarParser::FlingExpr_CmpEqEtcContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_CmpEqEtc;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_CmpEqEtcContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_CmpEqEtc(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_CmpEqEtcContext* FlingHdlGrammarParser::flingExpr_CmpEqEtc() {
  FlingExpr_CmpEqEtcContext *_localctx = _tracker.createInstance<FlingExpr_CmpEqEtcContext>(_ctx, getState());
  enterRule(_localctx, 226, FlingHdlGrammarParser::RuleFlingExpr_CmpEqEtc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1197);
    flingExpr_CmpLtEtc();
    setState(1200);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 115, _ctx)) {
    case 1: {
      setState(1198);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << FlingHdlGrammarParser::PunctCmpLt)
        | (1ULL << FlingHdlGrammarParser::PunctCmpGt)
        | (1ULL << FlingHdlGrammarParser::PunctCmpLe)
        | (1ULL << FlingHdlGrammarParser::PunctCmpGe))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1199);
      flingExpr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_CmpLtEtcContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_CmpLtEtcContext::FlingExpr_CmpLtEtcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExpr_BitShiftContext* FlingHdlGrammarParser::FlingExpr_CmpLtEtcContext::flingExpr_BitShift() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_BitShiftContext>(0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExpr_CmpLtEtcContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_CmpLtEtcContext::KwLsl() {
  return getToken(FlingHdlGrammarParser::KwLsl, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_CmpLtEtcContext::KwLsr() {
  return getToken(FlingHdlGrammarParser::KwLsr, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_CmpLtEtcContext::KwAsr() {
  return getToken(FlingHdlGrammarParser::KwAsr, 0);
}


size_t FlingHdlGrammarParser::FlingExpr_CmpLtEtcContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_CmpLtEtc;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_CmpLtEtcContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_CmpLtEtc(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_CmpLtEtcContext* FlingHdlGrammarParser::flingExpr_CmpLtEtc() {
  FlingExpr_CmpLtEtcContext *_localctx = _tracker.createInstance<FlingExpr_CmpLtEtcContext>(_ctx, getState());
  enterRule(_localctx, 228, FlingHdlGrammarParser::RuleFlingExpr_CmpLtEtc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1202);
    flingExpr_BitShift();
    setState(1205);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 116, _ctx)) {
    case 1: {
      setState(1203);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << FlingHdlGrammarParser::KwLsl)
        | (1ULL << FlingHdlGrammarParser::KwLsr)
        | (1ULL << FlingHdlGrammarParser::KwAsr))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1204);
      flingExpr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_BitShiftContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_BitShiftContext::FlingExpr_BitShiftContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExpr_BinaryPlus_Or_BinaryMinusContext* FlingHdlGrammarParser::FlingExpr_BitShiftContext::flingExpr_BinaryPlus_Or_BinaryMinus() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_BinaryPlus_Or_BinaryMinusContext>(0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExpr_BitShiftContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_BitShiftContext::PunctPlus() {
  return getToken(FlingHdlGrammarParser::PunctPlus, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_BitShiftContext::PunctMinus() {
  return getToken(FlingHdlGrammarParser::PunctMinus, 0);
}


size_t FlingHdlGrammarParser::FlingExpr_BitShiftContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_BitShift;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_BitShiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_BitShift(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_BitShiftContext* FlingHdlGrammarParser::flingExpr_BitShift() {
  FlingExpr_BitShiftContext *_localctx = _tracker.createInstance<FlingExpr_BitShiftContext>(_ctx, getState());
  enterRule(_localctx, 230, FlingHdlGrammarParser::RuleFlingExpr_BitShift);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1207);
    flingExpr_BinaryPlus_Or_BinaryMinus();
    setState(1210);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 117, _ctx)) {
    case 1: {
      setState(1208);
      _la = _input->LA(1);
      if (!(_la == FlingHdlGrammarParser::PunctPlus

      || _la == FlingHdlGrammarParser::PunctMinus)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1209);
      flingExpr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_BinaryPlus_Or_BinaryMinusContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_BinaryPlus_Or_BinaryMinusContext::FlingExpr_BinaryPlus_Or_BinaryMinusContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExpr_Mul_Or_Div_Or_ModContext* FlingHdlGrammarParser::FlingExpr_BinaryPlus_Or_BinaryMinusContext::flingExpr_Mul_Or_Div_Or_Mod() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_Mul_Or_Div_Or_ModContext>(0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExpr_BinaryPlus_Or_BinaryMinusContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_BinaryPlus_Or_BinaryMinusContext::PunctMul() {
  return getToken(FlingHdlGrammarParser::PunctMul, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_BinaryPlus_Or_BinaryMinusContext::PunctDiv() {
  return getToken(FlingHdlGrammarParser::PunctDiv, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_BinaryPlus_Or_BinaryMinusContext::PunctMod() {
  return getToken(FlingHdlGrammarParser::PunctMod, 0);
}


size_t FlingHdlGrammarParser::FlingExpr_BinaryPlus_Or_BinaryMinusContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_BinaryPlus_Or_BinaryMinus;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_BinaryPlus_Or_BinaryMinusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_BinaryPlus_Or_BinaryMinus(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_BinaryPlus_Or_BinaryMinusContext* FlingHdlGrammarParser::flingExpr_BinaryPlus_Or_BinaryMinus() {
  FlingExpr_BinaryPlus_Or_BinaryMinusContext *_localctx = _tracker.createInstance<FlingExpr_BinaryPlus_Or_BinaryMinusContext>(_ctx, getState());
  enterRule(_localctx, 232, FlingHdlGrammarParser::RuleFlingExpr_BinaryPlus_Or_BinaryMinus);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1212);
    flingExpr_Mul_Or_Div_Or_Mod();
    setState(1215);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 118, _ctx)) {
    case 1: {
      setState(1213);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << FlingHdlGrammarParser::PunctMul)
        | (1ULL << FlingHdlGrammarParser::PunctDiv)
        | (1ULL << FlingHdlGrammarParser::PunctMod))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1214);
      flingExpr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_Mul_Or_Div_Or_ModContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_Mul_Or_Div_Or_ModContext::FlingExpr_Mul_Or_Div_Or_ModContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExpr_Mul_Or_Div_Or_ModContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

FlingHdlGrammarParser::FlingExpr_UnaryContext* FlingHdlGrammarParser::FlingExpr_Mul_Or_Div_Or_ModContext::flingExpr_Unary() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_UnaryContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_Mul_Or_Div_Or_ModContext::PunctPlus() {
  return getToken(FlingHdlGrammarParser::PunctPlus, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_Mul_Or_Div_Or_ModContext::PunctMinus() {
  return getToken(FlingHdlGrammarParser::PunctMinus, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_Mul_Or_Div_Or_ModContext::PunctLogNot() {
  return getToken(FlingHdlGrammarParser::PunctLogNot, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_Mul_Or_Div_Or_ModContext::PunctBitNot() {
  return getToken(FlingHdlGrammarParser::PunctBitNot, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_Mul_Or_Div_Or_ModContext::PunctBitOr() {
  return getToken(FlingHdlGrammarParser::PunctBitOr, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_Mul_Or_Div_Or_ModContext::PunctBitNor() {
  return getToken(FlingHdlGrammarParser::PunctBitNor, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_Mul_Or_Div_Or_ModContext::PunctBitAnd() {
  return getToken(FlingHdlGrammarParser::PunctBitAnd, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_Mul_Or_Div_Or_ModContext::PunctBitNand() {
  return getToken(FlingHdlGrammarParser::PunctBitNand, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_Mul_Or_Div_Or_ModContext::PunctBitXor() {
  return getToken(FlingHdlGrammarParser::PunctBitXor, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_Mul_Or_Div_Or_ModContext::PunctBitXnor() {
  return getToken(FlingHdlGrammarParser::PunctBitXnor, 0);
}


size_t FlingHdlGrammarParser::FlingExpr_Mul_Or_Div_Or_ModContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_Mul_Or_Div_Or_Mod;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_Mul_Or_Div_Or_ModContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_Mul_Or_Div_Or_Mod(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_Mul_Or_Div_Or_ModContext* FlingHdlGrammarParser::flingExpr_Mul_Or_Div_Or_Mod() {
  FlingExpr_Mul_Or_Div_Or_ModContext *_localctx = _tracker.createInstance<FlingExpr_Mul_Or_Div_Or_ModContext>(_ctx, getState());
  enterRule(_localctx, 234, FlingHdlGrammarParser::RuleFlingExpr_Mul_Or_Div_Or_Mod);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1220);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FlingHdlGrammarParser::PunctPlus:
      case FlingHdlGrammarParser::PunctMinus:
      case FlingHdlGrammarParser::PunctBitOr:
      case FlingHdlGrammarParser::PunctBitNor:
      case FlingHdlGrammarParser::PunctBitAnd:
      case FlingHdlGrammarParser::PunctBitNand:
      case FlingHdlGrammarParser::PunctBitXor:
      case FlingHdlGrammarParser::PunctBitXnor:
      case FlingHdlGrammarParser::PunctBitNot:
      case FlingHdlGrammarParser::PunctLogNot: {
        setState(1217);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << FlingHdlGrammarParser::PunctPlus)
          | (1ULL << FlingHdlGrammarParser::PunctMinus)
          | (1ULL << FlingHdlGrammarParser::PunctBitOr)
          | (1ULL << FlingHdlGrammarParser::PunctBitNor)
          | (1ULL << FlingHdlGrammarParser::PunctBitAnd)
          | (1ULL << FlingHdlGrammarParser::PunctBitNand)
          | (1ULL << FlingHdlGrammarParser::PunctBitXor)
          | (1ULL << FlingHdlGrammarParser::PunctBitXnor)
          | (1ULL << FlingHdlGrammarParser::PunctBitNot)
          | (1ULL << FlingHdlGrammarParser::PunctLogNot))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(1218);
        flingExpr();
        break;
      }

      case FlingHdlGrammarParser::LitDecNum:
      case FlingHdlGrammarParser::LitHexNum:
      case FlingHdlGrammarParser::LitOctNum:
      case FlingHdlGrammarParser::LitBinNum:
      case FlingHdlGrammarParser::LitFloatNum:
      case FlingHdlGrammarParser::LitString:
      case FlingHdlGrammarParser::PunctLParen:
      case FlingHdlGrammarParser::KwLogic:
      case FlingHdlGrammarParser::KwSigned:
      case FlingHdlGrammarParser::KwInteger:
      case FlingHdlGrammarParser::KwSizeT:
      case FlingHdlGrammarParser::KwU8:
      case FlingHdlGrammarParser::KwI8:
      case FlingHdlGrammarParser::KwU16:
      case FlingHdlGrammarParser::KwI16:
      case FlingHdlGrammarParser::KwU32:
      case FlingHdlGrammarParser::KwI32:
      case FlingHdlGrammarParser::KwU64:
      case FlingHdlGrammarParser::KwI64:
      case FlingHdlGrammarParser::KwU128:
      case FlingHdlGrammarParser::KwI128:
      case FlingHdlGrammarParser::KwRetT:
      case FlingHdlGrammarParser::KwAuto:
      case FlingHdlGrammarParser::KwRange:
      case FlingHdlGrammarParser::KwHighZ:
      case FlingHdlGrammarParser::KwUnkX:
      case FlingHdlGrammarParser::KwSized:
      case FlingHdlGrammarParser::KwCat:
      case FlingHdlGrammarParser::KwRepl:
      case FlingHdlGrammarParser::KwDollarSigned:
      case FlingHdlGrammarParser::KwDollarUnsigned:
      case FlingHdlGrammarParser::KwDollarPow:
      case FlingHdlGrammarParser::KwDollarClog2:
      case FlingHdlGrammarParser::KwVoid:
      case FlingHdlGrammarParser::KwTypeof:
      case FlingHdlGrammarParser::KwSelfT:
      case FlingHdlGrammarParser::KwString:
      case FlingHdlGrammarParser::MiscIdent: {
        setState(1219);
        flingExpr_Unary();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_UnaryContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_UnaryContext::FlingExpr_UnaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExpr_Unary_ItemFromMajorityContext* FlingHdlGrammarParser::FlingExpr_UnaryContext::flingExpr_Unary_ItemFromMajority() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_Unary_ItemFromMajorityContext>(0);
}

FlingHdlGrammarParser::FlingExpr_RangeContext* FlingHdlGrammarParser::FlingExpr_UnaryContext::flingExpr_Range() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_RangeContext>(0);
}


size_t FlingHdlGrammarParser::FlingExpr_UnaryContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_Unary;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_UnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_Unary(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_UnaryContext* FlingHdlGrammarParser::flingExpr_Unary() {
  FlingExpr_UnaryContext *_localctx = _tracker.createInstance<FlingExpr_UnaryContext>(_ctx, getState());
  enterRule(_localctx, 236, FlingHdlGrammarParser::RuleFlingExpr_Unary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1224);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 120, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1222);
      flingExpr_Unary_ItemFromMajority();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1223);
      flingExpr_Range();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_Unary_ItemFromMajorityContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_Unary_ItemFromMajorityContext::FlingExpr_Unary_ItemFromMajorityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExpr_LiteralContext* FlingHdlGrammarParser::FlingExpr_Unary_ItemFromMajorityContext::flingExpr_Literal() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_LiteralContext>(0);
}

FlingHdlGrammarParser::FlingExpr_SizedContext* FlingHdlGrammarParser::FlingExpr_Unary_ItemFromMajorityContext::flingExpr_Sized() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_SizedContext>(0);
}

FlingHdlGrammarParser::FlingExpr_CatContext* FlingHdlGrammarParser::FlingExpr_Unary_ItemFromMajorityContext::flingExpr_Cat() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_CatContext>(0);
}

FlingHdlGrammarParser::FlingExpr_ReplContext* FlingHdlGrammarParser::FlingExpr_Unary_ItemFromMajorityContext::flingExpr_Repl() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_ReplContext>(0);
}

FlingHdlGrammarParser::FlingExpr_KwDollarFuncOfContext* FlingHdlGrammarParser::FlingExpr_Unary_ItemFromMajorityContext::flingExpr_KwDollarFuncOf() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_KwDollarFuncOfContext>(0);
}

FlingHdlGrammarParser::FlingExpr_IdentEtcContext* FlingHdlGrammarParser::FlingExpr_Unary_ItemFromMajorityContext::flingExpr_IdentEtc() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_IdentEtcContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_Unary_ItemFromMajorityContext::PunctLParen() {
  return getToken(FlingHdlGrammarParser::PunctLParen, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExpr_Unary_ItemFromMajorityContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_Unary_ItemFromMajorityContext::PunctRParen() {
  return getToken(FlingHdlGrammarParser::PunctRParen, 0);
}


size_t FlingHdlGrammarParser::FlingExpr_Unary_ItemFromMajorityContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_Unary_ItemFromMajority;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_Unary_ItemFromMajorityContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_Unary_ItemFromMajority(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_Unary_ItemFromMajorityContext* FlingHdlGrammarParser::flingExpr_Unary_ItemFromMajority() {
  FlingExpr_Unary_ItemFromMajorityContext *_localctx = _tracker.createInstance<FlingExpr_Unary_ItemFromMajorityContext>(_ctx, getState());
  enterRule(_localctx, 238, FlingHdlGrammarParser::RuleFlingExpr_Unary_ItemFromMajority);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1236);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FlingHdlGrammarParser::LitDecNum:
      case FlingHdlGrammarParser::LitHexNum:
      case FlingHdlGrammarParser::LitOctNum:
      case FlingHdlGrammarParser::LitBinNum:
      case FlingHdlGrammarParser::LitFloatNum:
      case FlingHdlGrammarParser::LitString:
      case FlingHdlGrammarParser::KwHighZ:
      case FlingHdlGrammarParser::KwUnkX: {
        enterOuterAlt(_localctx, 1);
        setState(1226);
        flingExpr_Literal();
        break;
      }

      case FlingHdlGrammarParser::KwSized: {
        enterOuterAlt(_localctx, 2);
        setState(1227);
        flingExpr_Sized();
        break;
      }

      case FlingHdlGrammarParser::KwCat: {
        enterOuterAlt(_localctx, 3);
        setState(1228);
        flingExpr_Cat();
        break;
      }

      case FlingHdlGrammarParser::KwRepl: {
        enterOuterAlt(_localctx, 4);
        setState(1229);
        flingExpr_Repl();
        break;
      }

      case FlingHdlGrammarParser::KwDollarSigned:
      case FlingHdlGrammarParser::KwDollarUnsigned:
      case FlingHdlGrammarParser::KwDollarPow:
      case FlingHdlGrammarParser::KwDollarClog2: {
        enterOuterAlt(_localctx, 5);
        setState(1230);
        flingExpr_KwDollarFuncOf();
        break;
      }

      case FlingHdlGrammarParser::KwLogic:
      case FlingHdlGrammarParser::KwSigned:
      case FlingHdlGrammarParser::KwInteger:
      case FlingHdlGrammarParser::KwSizeT:
      case FlingHdlGrammarParser::KwU8:
      case FlingHdlGrammarParser::KwI8:
      case FlingHdlGrammarParser::KwU16:
      case FlingHdlGrammarParser::KwI16:
      case FlingHdlGrammarParser::KwU32:
      case FlingHdlGrammarParser::KwI32:
      case FlingHdlGrammarParser::KwU64:
      case FlingHdlGrammarParser::KwI64:
      case FlingHdlGrammarParser::KwU128:
      case FlingHdlGrammarParser::KwI128:
      case FlingHdlGrammarParser::KwRetT:
      case FlingHdlGrammarParser::KwAuto:
      case FlingHdlGrammarParser::KwRange:
      case FlingHdlGrammarParser::KwVoid:
      case FlingHdlGrammarParser::KwTypeof:
      case FlingHdlGrammarParser::KwSelfT:
      case FlingHdlGrammarParser::KwString:
      case FlingHdlGrammarParser::MiscIdent: {
        enterOuterAlt(_localctx, 6);
        setState(1231);
        flingExpr_IdentEtc();
        break;
      }

      case FlingHdlGrammarParser::PunctLParen: {
        enterOuterAlt(_localctx, 7);
        setState(1232);
        match(FlingHdlGrammarParser::PunctLParen);
        setState(1233);
        flingExpr();
        setState(1234);
        match(FlingHdlGrammarParser::PunctRParen);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_LiteralContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_LiteralContext::FlingExpr_LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_LiteralContext::LitDecNum() {
  return getToken(FlingHdlGrammarParser::LitDecNum, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_LiteralContext::LitHexNum() {
  return getToken(FlingHdlGrammarParser::LitHexNum, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_LiteralContext::LitOctNum() {
  return getToken(FlingHdlGrammarParser::LitOctNum, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_LiteralContext::LitBinNum() {
  return getToken(FlingHdlGrammarParser::LitBinNum, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_LiteralContext::LitFloatNum() {
  return getToken(FlingHdlGrammarParser::LitFloatNum, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_LiteralContext::LitString() {
  return getToken(FlingHdlGrammarParser::LitString, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_LiteralContext::KwHighZ() {
  return getToken(FlingHdlGrammarParser::KwHighZ, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_LiteralContext::PunctLParen() {
  return getToken(FlingHdlGrammarParser::PunctLParen, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExpr_LiteralContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_LiteralContext::PunctRParen() {
  return getToken(FlingHdlGrammarParser::PunctRParen, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_LiteralContext::KwUnkX() {
  return getToken(FlingHdlGrammarParser::KwUnkX, 0);
}


size_t FlingHdlGrammarParser::FlingExpr_LiteralContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_Literal;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_Literal(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_LiteralContext* FlingHdlGrammarParser::flingExpr_Literal() {
  FlingExpr_LiteralContext *_localctx = _tracker.createInstance<FlingExpr_LiteralContext>(_ctx, getState());
  enterRule(_localctx, 240, FlingHdlGrammarParser::RuleFlingExpr_Literal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1258);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FlingHdlGrammarParser::LitDecNum: {
        enterOuterAlt(_localctx, 1);
        setState(1238);
        match(FlingHdlGrammarParser::LitDecNum);
        break;
      }

      case FlingHdlGrammarParser::LitHexNum: {
        enterOuterAlt(_localctx, 2);
        setState(1239);
        match(FlingHdlGrammarParser::LitHexNum);
        break;
      }

      case FlingHdlGrammarParser::LitOctNum: {
        enterOuterAlt(_localctx, 3);
        setState(1240);
        match(FlingHdlGrammarParser::LitOctNum);
        break;
      }

      case FlingHdlGrammarParser::LitBinNum: {
        enterOuterAlt(_localctx, 4);
        setState(1241);
        match(FlingHdlGrammarParser::LitBinNum);
        break;
      }

      case FlingHdlGrammarParser::LitFloatNum: {
        enterOuterAlt(_localctx, 5);
        setState(1242);
        match(FlingHdlGrammarParser::LitFloatNum);
        break;
      }

      case FlingHdlGrammarParser::LitString: {
        enterOuterAlt(_localctx, 6);
        setState(1243);
        match(FlingHdlGrammarParser::LitString);
        break;
      }

      case FlingHdlGrammarParser::KwHighZ: {
        enterOuterAlt(_localctx, 7);
        setState(1244);
        match(FlingHdlGrammarParser::KwHighZ);
        setState(1249);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FlingHdlGrammarParser::PunctLParen) {
          setState(1245);
          match(FlingHdlGrammarParser::PunctLParen);
          setState(1246);
          flingExpr();
          setState(1247);
          match(FlingHdlGrammarParser::PunctRParen);
        }
        break;
      }

      case FlingHdlGrammarParser::KwUnkX: {
        enterOuterAlt(_localctx, 8);
        setState(1251);
        match(FlingHdlGrammarParser::KwUnkX);
        setState(1256);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FlingHdlGrammarParser::PunctLParen) {
          setState(1252);
          match(FlingHdlGrammarParser::PunctLParen);
          setState(1253);
          flingExpr();
          setState(1254);
          match(FlingHdlGrammarParser::PunctRParen);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_SizedContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_SizedContext::FlingExpr_SizedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_SizedContext::KwSized() {
  return getToken(FlingHdlGrammarParser::KwSized, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_SizedContext::PunctLParen() {
  return getToken(FlingHdlGrammarParser::PunctLParen, 0);
}

std::vector<FlingHdlGrammarParser::FlingExprContext *> FlingHdlGrammarParser::FlingExpr_SizedContext::flingExpr() {
  return getRuleContexts<FlingHdlGrammarParser::FlingExprContext>();
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExpr_SizedContext::flingExpr(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(i);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_SizedContext::PunctComma() {
  return getToken(FlingHdlGrammarParser::PunctComma, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_SizedContext::PunctRParen() {
  return getToken(FlingHdlGrammarParser::PunctRParen, 0);
}


size_t FlingHdlGrammarParser::FlingExpr_SizedContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_Sized;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_SizedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_Sized(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_SizedContext* FlingHdlGrammarParser::flingExpr_Sized() {
  FlingExpr_SizedContext *_localctx = _tracker.createInstance<FlingExpr_SizedContext>(_ctx, getState());
  enterRule(_localctx, 242, FlingHdlGrammarParser::RuleFlingExpr_Sized);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1260);
    match(FlingHdlGrammarParser::KwSized);
    setState(1261);
    match(FlingHdlGrammarParser::PunctLParen);
    setState(1262);
    flingExpr();
    setState(1263);
    match(FlingHdlGrammarParser::PunctComma);
    setState(1264);
    flingExpr();
    setState(1265);
    match(FlingHdlGrammarParser::PunctRParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_RangeContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_RangeContext::FlingExpr_RangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExpr_Range_DotDotContext* FlingHdlGrammarParser::FlingExpr_RangeContext::flingExpr_Range_DotDot() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_Range_DotDotContext>(0);
}

FlingHdlGrammarParser::FlingExpr_Range_CallFuncContext* FlingHdlGrammarParser::FlingExpr_RangeContext::flingExpr_Range_CallFunc() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_Range_CallFuncContext>(0);
}


size_t FlingHdlGrammarParser::FlingExpr_RangeContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_Range;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_RangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_Range(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_RangeContext* FlingHdlGrammarParser::flingExpr_Range() {
  FlingExpr_RangeContext *_localctx = _tracker.createInstance<FlingExpr_RangeContext>(_ctx, getState());
  enterRule(_localctx, 244, FlingHdlGrammarParser::RuleFlingExpr_Range);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1269);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 125, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1267);
      flingExpr_Range_DotDot();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1268);
      flingExpr_Range_CallFunc();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_Range_DotDotContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_Range_DotDotContext::FlingExpr_Range_DotDotContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_Range_DotDotContext::PunctRangeSeparator() {
  return getToken(FlingHdlGrammarParser::PunctRangeSeparator, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExpr_Range_DotDotContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

FlingHdlGrammarParser::FlingExpr_Unary_ItemFromMajorityContext* FlingHdlGrammarParser::FlingExpr_Range_DotDotContext::flingExpr_Unary_ItemFromMajority() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_Unary_ItemFromMajorityContext>(0);
}

FlingHdlGrammarParser::FlingExpr_Range_CallFuncContext* FlingHdlGrammarParser::FlingExpr_Range_DotDotContext::flingExpr_Range_CallFunc() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_Range_CallFuncContext>(0);
}


size_t FlingHdlGrammarParser::FlingExpr_Range_DotDotContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_Range_DotDot;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_Range_DotDotContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_Range_DotDot(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_Range_DotDotContext* FlingHdlGrammarParser::flingExpr_Range_DotDot() {
  FlingExpr_Range_DotDotContext *_localctx = _tracker.createInstance<FlingExpr_Range_DotDotContext>(_ctx, getState());
  enterRule(_localctx, 246, FlingHdlGrammarParser::RuleFlingExpr_Range_DotDot);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1273);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 126, _ctx)) {
    case 1: {
      setState(1271);
      flingExpr_Unary_ItemFromMajority();
      break;
    }

    case 2: {
      setState(1272);
      flingExpr_Range_CallFunc();
      break;
    }

    }
    setState(1275);
    match(FlingHdlGrammarParser::PunctRangeSeparator);
    setState(1276);
    flingExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_Range_CallFuncContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_Range_CallFuncContext::FlingExpr_Range_CallFuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_Range_CallFuncContext::KwRange() {
  return getToken(FlingHdlGrammarParser::KwRange, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_Range_CallFuncContext::PunctLParen() {
  return getToken(FlingHdlGrammarParser::PunctLParen, 0);
}

std::vector<FlingHdlGrammarParser::FlingExprContext *> FlingHdlGrammarParser::FlingExpr_Range_CallFuncContext::flingExpr() {
  return getRuleContexts<FlingHdlGrammarParser::FlingExprContext>();
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExpr_Range_CallFuncContext::flingExpr(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(i);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_Range_CallFuncContext::PunctComma() {
  return getToken(FlingHdlGrammarParser::PunctComma, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_Range_CallFuncContext::PunctRParen() {
  return getToken(FlingHdlGrammarParser::PunctRParen, 0);
}


size_t FlingHdlGrammarParser::FlingExpr_Range_CallFuncContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_Range_CallFunc;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_Range_CallFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_Range_CallFunc(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_Range_CallFuncContext* FlingHdlGrammarParser::flingExpr_Range_CallFunc() {
  FlingExpr_Range_CallFuncContext *_localctx = _tracker.createInstance<FlingExpr_Range_CallFuncContext>(_ctx, getState());
  enterRule(_localctx, 248, FlingHdlGrammarParser::RuleFlingExpr_Range_CallFunc);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1278);
    match(FlingHdlGrammarParser::KwRange);
    setState(1279);
    match(FlingHdlGrammarParser::PunctLParen);
    setState(1280);
    flingExpr();
    setState(1281);
    match(FlingHdlGrammarParser::PunctComma);
    setState(1282);
    flingExpr();
    setState(1283);
    match(FlingHdlGrammarParser::PunctRParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_CatContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_CatContext::FlingExpr_CatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_CatContext::KwCat() {
  return getToken(FlingHdlGrammarParser::KwCat, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_CatContext::PunctLParen() {
  return getToken(FlingHdlGrammarParser::PunctLParen, 0);
}

FlingHdlGrammarParser::FlingExprListContext* FlingHdlGrammarParser::FlingExpr_CatContext::flingExprList() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprListContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_CatContext::PunctRParen() {
  return getToken(FlingHdlGrammarParser::PunctRParen, 0);
}


size_t FlingHdlGrammarParser::FlingExpr_CatContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_Cat;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_CatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_Cat(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_CatContext* FlingHdlGrammarParser::flingExpr_Cat() {
  FlingExpr_CatContext *_localctx = _tracker.createInstance<FlingExpr_CatContext>(_ctx, getState());
  enterRule(_localctx, 250, FlingHdlGrammarParser::RuleFlingExpr_Cat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1285);
    match(FlingHdlGrammarParser::KwCat);
    setState(1286);
    match(FlingHdlGrammarParser::PunctLParen);
    setState(1287);
    flingExprList();
    setState(1288);
    match(FlingHdlGrammarParser::PunctRParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_ReplContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_ReplContext::FlingExpr_ReplContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_ReplContext::KwRepl() {
  return getToken(FlingHdlGrammarParser::KwRepl, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_ReplContext::PunctLParen() {
  return getToken(FlingHdlGrammarParser::PunctLParen, 0);
}

std::vector<FlingHdlGrammarParser::FlingExprContext *> FlingHdlGrammarParser::FlingExpr_ReplContext::flingExpr() {
  return getRuleContexts<FlingHdlGrammarParser::FlingExprContext>();
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExpr_ReplContext::flingExpr(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(i);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_ReplContext::PunctComma() {
  return getToken(FlingHdlGrammarParser::PunctComma, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_ReplContext::PunctRParen() {
  return getToken(FlingHdlGrammarParser::PunctRParen, 0);
}


size_t FlingHdlGrammarParser::FlingExpr_ReplContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_Repl;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_ReplContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_Repl(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_ReplContext* FlingHdlGrammarParser::flingExpr_Repl() {
  FlingExpr_ReplContext *_localctx = _tracker.createInstance<FlingExpr_ReplContext>(_ctx, getState());
  enterRule(_localctx, 252, FlingHdlGrammarParser::RuleFlingExpr_Repl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1290);
    match(FlingHdlGrammarParser::KwRepl);
    setState(1291);
    match(FlingHdlGrammarParser::PunctLParen);
    setState(1292);
    flingExpr();
    setState(1293);
    match(FlingHdlGrammarParser::PunctComma);
    setState(1294);
    flingExpr();
    setState(1295);
    match(FlingHdlGrammarParser::PunctRParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_KwDollarFuncOfContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_KwDollarFuncOfContext::FlingExpr_KwDollarFuncOfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_NonPowContext* FlingHdlGrammarParser::FlingExpr_KwDollarFuncOfContext::flingExpr_KwDollarFuncOf_NonPow() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_NonPowContext>(0);
}

FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_PowContext* FlingHdlGrammarParser::FlingExpr_KwDollarFuncOfContext::flingExpr_KwDollarFuncOf_Pow() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_PowContext>(0);
}


size_t FlingHdlGrammarParser::FlingExpr_KwDollarFuncOfContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_KwDollarFuncOf;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_KwDollarFuncOfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_KwDollarFuncOf(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_KwDollarFuncOfContext* FlingHdlGrammarParser::flingExpr_KwDollarFuncOf() {
  FlingExpr_KwDollarFuncOfContext *_localctx = _tracker.createInstance<FlingExpr_KwDollarFuncOfContext>(_ctx, getState());
  enterRule(_localctx, 254, FlingHdlGrammarParser::RuleFlingExpr_KwDollarFuncOf);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1299);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FlingHdlGrammarParser::KwDollarSigned:
      case FlingHdlGrammarParser::KwDollarUnsigned:
      case FlingHdlGrammarParser::KwDollarClog2: {
        enterOuterAlt(_localctx, 1);
        setState(1297);
        flingExpr_KwDollarFuncOf_NonPow();
        break;
      }

      case FlingHdlGrammarParser::KwDollarPow: {
        enterOuterAlt(_localctx, 2);
        setState(1298);
        flingExpr_KwDollarFuncOf_Pow();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_KwDollarFuncOf_NonPowContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_NonPowContext::FlingExpr_KwDollarFuncOf_NonPowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_NonPowContext::PunctLParen() {
  return getToken(FlingHdlGrammarParser::PunctLParen, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_NonPowContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_NonPowContext::PunctRParen() {
  return getToken(FlingHdlGrammarParser::PunctRParen, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_NonPowContext::KwDollarSigned() {
  return getToken(FlingHdlGrammarParser::KwDollarSigned, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_NonPowContext::KwDollarUnsigned() {
  return getToken(FlingHdlGrammarParser::KwDollarUnsigned, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_NonPowContext::KwDollarClog2() {
  return getToken(FlingHdlGrammarParser::KwDollarClog2, 0);
}


size_t FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_NonPowContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_KwDollarFuncOf_NonPow;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_NonPowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_KwDollarFuncOf_NonPow(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_NonPowContext* FlingHdlGrammarParser::flingExpr_KwDollarFuncOf_NonPow() {
  FlingExpr_KwDollarFuncOf_NonPowContext *_localctx = _tracker.createInstance<FlingExpr_KwDollarFuncOf_NonPowContext>(_ctx, getState());
  enterRule(_localctx, 256, FlingHdlGrammarParser::RuleFlingExpr_KwDollarFuncOf_NonPow);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1301);
    _la = _input->LA(1);
    if (!(((((_la - 109) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 109)) & ((1ULL << (FlingHdlGrammarParser::KwDollarSigned - 109))
      | (1ULL << (FlingHdlGrammarParser::KwDollarUnsigned - 109))
      | (1ULL << (FlingHdlGrammarParser::KwDollarClog2 - 109)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(1302);
    match(FlingHdlGrammarParser::PunctLParen);
    setState(1303);
    flingExpr();
    setState(1304);
    match(FlingHdlGrammarParser::PunctRParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_KwDollarFuncOf_PowContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_PowContext::FlingExpr_KwDollarFuncOf_PowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_PowContext::KwDollarPow() {
  return getToken(FlingHdlGrammarParser::KwDollarPow, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_PowContext::PunctLParen() {
  return getToken(FlingHdlGrammarParser::PunctLParen, 0);
}

std::vector<FlingHdlGrammarParser::FlingExprContext *> FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_PowContext::flingExpr() {
  return getRuleContexts<FlingHdlGrammarParser::FlingExprContext>();
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_PowContext::flingExpr(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(i);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_PowContext::PunctComma() {
  return getToken(FlingHdlGrammarParser::PunctComma, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_PowContext::PunctRParen() {
  return getToken(FlingHdlGrammarParser::PunctRParen, 0);
}


size_t FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_PowContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_KwDollarFuncOf_Pow;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_PowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_KwDollarFuncOf_Pow(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_KwDollarFuncOf_PowContext* FlingHdlGrammarParser::flingExpr_KwDollarFuncOf_Pow() {
  FlingExpr_KwDollarFuncOf_PowContext *_localctx = _tracker.createInstance<FlingExpr_KwDollarFuncOf_PowContext>(_ctx, getState());
  enterRule(_localctx, 258, FlingHdlGrammarParser::RuleFlingExpr_KwDollarFuncOf_Pow);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1306);
    match(FlingHdlGrammarParser::KwDollarPow);
    setState(1307);
    match(FlingHdlGrammarParser::PunctLParen);
    setState(1308);
    flingExpr();
    setState(1309);
    match(FlingHdlGrammarParser::PunctComma);
    setState(1310);
    flingExpr();
    setState(1311);
    match(FlingHdlGrammarParser::PunctRParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_IdentEtcContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_IdentEtcContext::FlingExpr_IdentEtcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FlingHdlGrammarParser::FlingExpr_IdentEtc_ItemContext *> FlingHdlGrammarParser::FlingExpr_IdentEtcContext::flingExpr_IdentEtc_Item() {
  return getRuleContexts<FlingHdlGrammarParser::FlingExpr_IdentEtc_ItemContext>();
}

FlingHdlGrammarParser::FlingExpr_IdentEtc_ItemContext* FlingHdlGrammarParser::FlingExpr_IdentEtcContext::flingExpr_IdentEtc_Item(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_IdentEtc_ItemContext>(i);
}

FlingHdlGrammarParser::FlingTypenameOrModnameContext* FlingHdlGrammarParser::FlingExpr_IdentEtcContext::flingTypenameOrModname() {
  return getRuleContext<FlingHdlGrammarParser::FlingTypenameOrModnameContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_IdentEtcContext::PunctScopeAccess() {
  return getToken(FlingHdlGrammarParser::PunctScopeAccess, 0);
}

std::vector<tree::TerminalNode *> FlingHdlGrammarParser::FlingExpr_IdentEtcContext::PunctMemberAccess() {
  return getTokens(FlingHdlGrammarParser::PunctMemberAccess);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_IdentEtcContext::PunctMemberAccess(size_t i) {
  return getToken(FlingHdlGrammarParser::PunctMemberAccess, i);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_IdentEtcContext::KwDollarSize() {
  return getToken(FlingHdlGrammarParser::KwDollarSize, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_IdentEtcContext::KwDollarRange() {
  return getToken(FlingHdlGrammarParser::KwDollarRange, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_IdentEtcContext::KwDollarHigh() {
  return getToken(FlingHdlGrammarParser::KwDollarHigh, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_IdentEtcContext::KwDollarLow() {
  return getToken(FlingHdlGrammarParser::KwDollarLow, 0);
}


size_t FlingHdlGrammarParser::FlingExpr_IdentEtcContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_IdentEtc;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_IdentEtcContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_IdentEtc(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_IdentEtcContext* FlingHdlGrammarParser::flingExpr_IdentEtc() {
  FlingExpr_IdentEtcContext *_localctx = _tracker.createInstance<FlingExpr_IdentEtcContext>(_ctx, getState());
  enterRule(_localctx, 260, FlingHdlGrammarParser::RuleFlingExpr_IdentEtc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1316);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 128, _ctx)) {
    case 1: {
      setState(1313);
      flingTypenameOrModname();
      setState(1314);
      match(FlingHdlGrammarParser::PunctScopeAccess);
      break;
    }

    }
    setState(1318);
    flingExpr_IdentEtc_Item();
    setState(1323);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FlingHdlGrammarParser::PunctMemberAccess) {
      setState(1319);
      match(FlingHdlGrammarParser::PunctMemberAccess);
      setState(1320);
      flingExpr_IdentEtc_Item();
      setState(1325);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1327);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 103) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 103)) & ((1ULL << (FlingHdlGrammarParser::KwDollarSize - 103))
      | (1ULL << (FlingHdlGrammarParser::KwDollarRange - 103))
      | (1ULL << (FlingHdlGrammarParser::KwDollarHigh - 103))
      | (1ULL << (FlingHdlGrammarParser::KwDollarLow - 103)))) != 0)) {
      setState(1326);
      _la = _input->LA(1);
      if (!(((((_la - 103) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 103)) & ((1ULL << (FlingHdlGrammarParser::KwDollarSize - 103))
        | (1ULL << (FlingHdlGrammarParser::KwDollarRange - 103))
        | (1ULL << (FlingHdlGrammarParser::KwDollarHigh - 103))
        | (1ULL << (FlingHdlGrammarParser::KwDollarLow - 103)))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_IdentEtc_ItemContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_IdentEtc_ItemContext::FlingExpr_IdentEtc_ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingIdentContext* FlingHdlGrammarParser::FlingExpr_IdentEtc_ItemContext::flingIdent() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentContext>(0);
}

FlingHdlGrammarParser::FlingInstArgListContext* FlingHdlGrammarParser::FlingExpr_IdentEtc_ItemContext::flingInstArgList() {
  return getRuleContext<FlingHdlGrammarParser::FlingInstArgListContext>(0);
}

std::vector<FlingHdlGrammarParser::FlingExpr_IdentEtc_Item_EndContext *> FlingHdlGrammarParser::FlingExpr_IdentEtc_ItemContext::flingExpr_IdentEtc_Item_End() {
  return getRuleContexts<FlingHdlGrammarParser::FlingExpr_IdentEtc_Item_EndContext>();
}

FlingHdlGrammarParser::FlingExpr_IdentEtc_Item_EndContext* FlingHdlGrammarParser::FlingExpr_IdentEtc_ItemContext::flingExpr_IdentEtc_Item_End(size_t i) {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_IdentEtc_Item_EndContext>(i);
}

FlingHdlGrammarParser::FlingInstParamListContext* FlingHdlGrammarParser::FlingExpr_IdentEtc_ItemContext::flingInstParamList() {
  return getRuleContext<FlingHdlGrammarParser::FlingInstParamListContext>(0);
}


size_t FlingHdlGrammarParser::FlingExpr_IdentEtc_ItemContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_IdentEtc_Item;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_IdentEtc_ItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_IdentEtc_Item(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_IdentEtc_ItemContext* FlingHdlGrammarParser::flingExpr_IdentEtc_Item() {
  FlingExpr_IdentEtc_ItemContext *_localctx = _tracker.createInstance<FlingExpr_IdentEtc_ItemContext>(_ctx, getState());
  enterRule(_localctx, 262, FlingHdlGrammarParser::RuleFlingExpr_IdentEtc_Item);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1329);
    flingIdent();
    setState(1334);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 132, _ctx)) {
    case 1: {
      setState(1331);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FlingHdlGrammarParser::PunctCmpLt) {
        setState(1330);
        flingInstParamList();
      }
      setState(1333);
      flingInstArgList();
      break;
    }

    }
    setState(1339);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FlingHdlGrammarParser::PunctLBracket || _la == FlingHdlGrammarParser::KwDollarFirstel

    || _la == FlingHdlGrammarParser::KwDollarLastel) {
      setState(1336);
      flingExpr_IdentEtc_Item_End();
      setState(1341);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_IdentEtc_Item_EndContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_IdentEtc_Item_EndContext::FlingExpr_IdentEtc_Item_EndContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_IdentEtc_Item_EndContext::PunctLBracket() {
  return getToken(FlingHdlGrammarParser::PunctLBracket, 0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExpr_IdentEtc_Item_EndContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_IdentEtc_Item_EndContext::PunctRBracket() {
  return getToken(FlingHdlGrammarParser::PunctRBracket, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_IdentEtc_Item_EndContext::KwDollarFirstel() {
  return getToken(FlingHdlGrammarParser::KwDollarFirstel, 0);
}

tree::TerminalNode* FlingHdlGrammarParser::FlingExpr_IdentEtc_Item_EndContext::KwDollarLastel() {
  return getToken(FlingHdlGrammarParser::KwDollarLastel, 0);
}


size_t FlingHdlGrammarParser::FlingExpr_IdentEtc_Item_EndContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_IdentEtc_Item_End;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_IdentEtc_Item_EndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_IdentEtc_Item_End(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_IdentEtc_Item_EndContext* FlingHdlGrammarParser::flingExpr_IdentEtc_Item_End() {
  FlingExpr_IdentEtc_Item_EndContext *_localctx = _tracker.createInstance<FlingExpr_IdentEtc_Item_EndContext>(_ctx, getState());
  enterRule(_localctx, 264, FlingHdlGrammarParser::RuleFlingExpr_IdentEtc_Item_End);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1348);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FlingHdlGrammarParser::PunctLBracket: {
        enterOuterAlt(_localctx, 1);
        setState(1342);
        match(FlingHdlGrammarParser::PunctLBracket);
        setState(1343);
        flingExpr();
        setState(1344);
        match(FlingHdlGrammarParser::PunctRBracket);
        break;
      }

      case FlingHdlGrammarParser::KwDollarFirstel: {
        enterOuterAlt(_localctx, 2);
        setState(1346);
        match(FlingHdlGrammarParser::KwDollarFirstel);
        break;
      }

      case FlingHdlGrammarParser::KwDollarLastel: {
        enterOuterAlt(_localctx, 3);
        setState(1347);
        match(FlingHdlGrammarParser::KwDollarLastel);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlingExpr_CallSubprog_PseudoOperContext ------------------------------------------------------------------

FlingHdlGrammarParser::FlingExpr_CallSubprog_PseudoOperContext::FlingExpr_CallSubprog_PseudoOperContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FlingHdlGrammarParser::FlingIdentContext* FlingHdlGrammarParser::FlingExpr_CallSubprog_PseudoOperContext::flingIdent() {
  return getRuleContext<FlingHdlGrammarParser::FlingIdentContext>(0);
}

FlingHdlGrammarParser::FlingExprContext* FlingHdlGrammarParser::FlingExpr_CallSubprog_PseudoOperContext::flingExpr() {
  return getRuleContext<FlingHdlGrammarParser::FlingExprContext>(0);
}

FlingHdlGrammarParser::FlingExpr_Unary_ItemFromMajorityContext* FlingHdlGrammarParser::FlingExpr_CallSubprog_PseudoOperContext::flingExpr_Unary_ItemFromMajority() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_Unary_ItemFromMajorityContext>(0);
}

FlingHdlGrammarParser::FlingExpr_Range_CallFuncContext* FlingHdlGrammarParser::FlingExpr_CallSubprog_PseudoOperContext::flingExpr_Range_CallFunc() {
  return getRuleContext<FlingHdlGrammarParser::FlingExpr_Range_CallFuncContext>(0);
}

FlingHdlGrammarParser::FlingInstParamListContext* FlingHdlGrammarParser::FlingExpr_CallSubprog_PseudoOperContext::flingInstParamList() {
  return getRuleContext<FlingHdlGrammarParser::FlingInstParamListContext>(0);
}


size_t FlingHdlGrammarParser::FlingExpr_CallSubprog_PseudoOperContext::getRuleIndex() const {
  return FlingHdlGrammarParser::RuleFlingExpr_CallSubprog_PseudoOper;
}


antlrcpp::Any FlingHdlGrammarParser::FlingExpr_CallSubprog_PseudoOperContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FlingHdlGrammarVisitor*>(visitor))
    return parserVisitor->visitFlingExpr_CallSubprog_PseudoOper(this);
  else
    return visitor->visitChildren(this);
}

FlingHdlGrammarParser::FlingExpr_CallSubprog_PseudoOperContext* FlingHdlGrammarParser::flingExpr_CallSubprog_PseudoOper() {
  FlingExpr_CallSubprog_PseudoOperContext *_localctx = _tracker.createInstance<FlingExpr_CallSubprog_PseudoOperContext>(_ctx, getState());
  enterRule(_localctx, 266, FlingHdlGrammarParser::RuleFlingExpr_CallSubprog_PseudoOper);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1352);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 135, _ctx)) {
    case 1: {
      setState(1350);
      flingExpr_Unary_ItemFromMajority();
      break;
    }

    case 2: {
      setState(1351);
      flingExpr_Range_CallFunc();
      break;
    }

    }
    setState(1354);
    flingIdent();
    setState(1356);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FlingHdlGrammarParser::PunctCmpLt) {
      setState(1355);
      flingInstParamList();
    }
    setState(1358);
    flingExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> FlingHdlGrammarParser::_decisionToDFA;
atn::PredictionContextCache FlingHdlGrammarParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN FlingHdlGrammarParser::_atn;
std::vector<uint16_t> FlingHdlGrammarParser::_serializedATN;

std::vector<std::string> FlingHdlGrammarParser::_ruleNames = {
  "flingProgram", "flingProgram_Item", "flingDeclPackage", "flingDeclPackage_Item", 
  "flingDeclParamList", "flingDeclParamList_Item", "flingDeclArgList", "flingDeclArgList_Item", 
  "flingInstParamList", "flingInstParamList_Pos", "flingInstParamList_Pos_Item", 
  "flingInstParamList_Named", "flingInstParamList_Named_Item", "flingInstArgList", 
  "flingInstArgList_Pos", "flingInstArgList_Named", "flingInstArgList_Named_Item", 
  "flingDeclModule", "flingDeclModule_Scope", "flingDeclModule_Item", "flingInstModule", 
  "flingGen", "flingGen_If", "flingGen_If_Elif", "flingGen_If_Else", "flingGen_Switch", 
  "flingGen_Switch_Default", "flingGen_Switch_Case", "flingGen_For", "flingContAssign", 
  "flingBehav", "flingBehav_Seq_EdgeList", "flingBehav_Seq_EdgeList_Item", 
  "flingBehav_Scope", "flingBehav_Item", "flingBehav_Item_If", "flingBehav_Item_If_Elif", 
  "flingBehav_Item_If_Else", "flingBehav_Item_SwitchOrSwitchz", "flingBehav_Item_SwitchOrSwitchz_Default", 
  "flingBehav_Item_SwitchOrSwitchz_Case", "flingBehav_Item_For", "flingBehav_Item_While", 
  "flingBehav_Item_NonBlkAssign", "flingBehav_Item_BlkAssign", "flingDeclWire", 
  "flingDeclVar", "flingDeclConst", "flingDeclType", "flingDeclEnum", "flingDeclClass", 
  "flingDeclClsOrMxn_Extends", "flingDeclClass_Item", "flingDeclClass_Item_DeclVar", 
  "flingDeclClsOrMxn_Item", "flingDeclClsOrMxn_Item_DeclType", "flingDeclClsOrMxn_Item_DeclAliasOrConst", 
  "flingDeclClsOrMxn_AccessSpecifier", "flingDeclClsOrMxn_Item_DeclSubprog", 
  "flingDeclClsOrMxn_Item_DeclSubprog_FullDefn", "flingDeclClsOrMxn_Item_DeclSubprog_Abstract", 
  "flingDeclMixin", "flingDeclSubprog", "flingDeclFunc", "flingDeclFunc_Header", 
  "flingDeclFunc_Scope", "flingDeclFunc_Item", "flingDeclFunc_Item_If", 
  "flingDeclFunc_Item_If_Elif", "flingDeclFunc_Item_If_Else", "flingDeclFunc_Item_SwitchOrSwitchz", 
  "flingDeclFunc_Item_SwitchOrSwitchz_Default", "flingDeclFunc_Item_SwitchOrSwitchz_Case", 
  "flingDeclFunc_Item_For", "flingDeclFunc_Item_While", "flingDeclTask", 
  "flingDeclTask_Header", "flingDeclTask_Scope", "flingDeclTask_Item", "flingDeclTask_Item_If", 
  "flingDeclTask_Item_If_Elif", "flingDeclTask_Item_If_Else", "flingDeclTask_Item_SwitchOrSwitchz", 
  "flingDeclTask_Item_SwitchOrSwitchz_Default", "flingDeclTask_Item_SwitchOrSwitchz_Case", 
  "flingDeclTask_Item_For", "flingDeclTask_Item_While", "flingDeclProc", 
  "flingDeclProc_Header", "flingDeclProc_ArgList", "flingDeclProc_ArgList_Item", 
  "flingDeclAlias", "flingDeclAlias_Value", "flingDeclAlias_Type", "flingDeclAlias_Module", 
  "flingIdent", "flingIdentList", "flingScopedIdent", "flingExprList", "flingTypenameOrModnameList", 
  "flingImportList", "flingTypenameOrModname", "flingTypenameOrModname_Cstm", 
  "flingTypenameOrModname_Cstm_Item", "flingTypenameOrModname_ArrDim", "flingTypenameOrModname_Builtin", 
  "flingExpr", "flingExpr_Mux", "flingExpr_LogOr", "flingExpr_LogAnd", "flingExpr_BitOr_Or_BitNor", 
  "flingExpr_BitAnd_Or_BitNand", "flingExpr_BitXor_Or_BitXnor", "flingExpr_CmpEqEtc", 
  "flingExpr_CmpLtEtc", "flingExpr_BitShift", "flingExpr_BinaryPlus_Or_BinaryMinus", 
  "flingExpr_Mul_Or_Div_Or_Mod", "flingExpr_Unary", "flingExpr_Unary_ItemFromMajority", 
  "flingExpr_Literal", "flingExpr_Sized", "flingExpr_Range", "flingExpr_Range_DotDot", 
  "flingExpr_Range_CallFunc", "flingExpr_Cat", "flingExpr_Repl", "flingExpr_KwDollarFuncOf", 
  "flingExpr_KwDollarFuncOf_NonPow", "flingExpr_KwDollarFuncOf_Pow", "flingExpr_IdentEtc", 
  "flingExpr_IdentEtc_Item", "flingExpr_IdentEtc_Item_End", "flingExpr_CallSubprog_PseudoOper"
};

std::vector<std::string> FlingHdlGrammarParser::_literalNames = {
  "", "", "", "", "", "", "", "", "", "'..'", "':='", "'='", "'||'", "'&&'", 
  "'=='", "'!='", "'==='", "'!=='", "'<'", "'>'", "'<='", "'>='", "'+'", 
  "'-'", "'*'", "'/'", "'%'", "'|'", "'~|'", "'&'", "'~&'", "'^'", "", "'lsl'", 
  "'lsr'", "'asr'", "'~'", "'!'", "'=>'", "'.'", "'::'", "'('", "')'", "'['", 
  "']'", "'{'", "'}'", "';'", "':'", "','", "'if'", "'elif'", "'else'", 
  "'mux'", "'switch'", "'switchz'", "'default'", "'for'", "'while'", "'break'", 
  "'continue'", "'module'", "'package'", "'input'", "'output'", "'inout'", 
  "'interface'", "'gen'", "'initial'", "'comb'", "'seq'", "'posedge'", "'negedge'", 
  "'func'", "'task'", "'import'", "'all'", "'wire'", "'logic'", "'const'", 
  "'signed'", "'integer'", "'size_t'", "'u8'", "'i8'", "'u16'", "'i16'", 
  "'u32'", "'i32'", "'u64'", "'i64'", "'u128'", "'i128'", "'return'", "'ret_t'", 
  "'auto'", "'range'", "'high_z'", "'unk_x'", "'sized'", "'cat'", "'repl'", 
  "'as'", "'$size'", "'$range'", "'$high'", "'$low'", "'$firstel'", "'$lastel'", 
  "'$signed'", "'$unsigned'", "'$pow'", "'$clog2'", "'assert'", "'assume'", 
  "'cover'", "'void'", "'type'", "'typeof'", "'alias'", "'enum'", "'class'", 
  "'packed'", "'mixin'", "'extends'", "'virtual'", "'abstract'", "'isvtype'", 
  "'base'", "'static'", "'proc'", "'self'", "'self_t'", "'pub'", "'prot'", 
  "'priv'", "'string'", "'float'"
};

std::vector<std::string> FlingHdlGrammarParser::_symbolicNames = {
  "", "LexWhitespace", "LexLineComment", "LitDecNum", "LitHexNum", "LitOctNum", 
  "LitBinNum", "LitFloatNum", "LitString", "PunctRangeSeparator", "PunctNonBlkAssign", 
  "PunctBlkAssign", "PunctLogOr", "PunctLogAnd", "PunctCmpEq", "PunctCmpNe", 
  "PunctCaseCmpEq", "PunctCaseCmpNe", "PunctCmpLt", "PunctCmpGt", "PunctCmpLe", 
  "PunctCmpGe", "PunctPlus", "PunctMinus", "PunctMul", "PunctDiv", "PunctMod", 
  "PunctBitOr", "PunctBitNor", "PunctBitAnd", "PunctBitNand", "PunctBitXor", 
  "PunctBitXnor", "KwLsl", "KwLsr", "KwAsr", "PunctBitNot", "PunctLogNot", 
  "PunctMapTo", "PunctMemberAccess", "PunctScopeAccess", "PunctLParen", 
  "PunctRParen", "PunctLBracket", "PunctRBracket", "PunctLBrace", "PunctRBrace", 
  "PunctSemicolon", "PunctColon", "PunctComma", "KwIf", "KwElif", "KwElse", 
  "KwMux", "KwSwitch", "KwSwitchz", "KwDefault", "KwFor", "KwWhile", "KwBreak", 
  "KwContinue", "KwModule", "KwPackage", "KwInput", "KwOutput", "KwInout", 
  "KwInterface", "KwGen", "KwInitial", "KwComb", "KwSeq", "KwPosedge", "KwNegedge", 
  "KwFunc", "KwTask", "KwImport", "KwAll", "KwWire", "KwLogic", "KwConst", 
  "KwSigned", "KwInteger", "KwSizeT", "KwU8", "KwI8", "KwU16", "KwI16", 
  "KwU32", "KwI32", "KwU64", "KwI64", "KwU128", "KwI128", "KwReturn", "KwRetT", 
  "KwAuto", "KwRange", "KwHighZ", "KwUnkX", "KwSized", "KwCat", "KwRepl", 
  "KwAs", "KwDollarSize", "KwDollarRange", "KwDollarHigh", "KwDollarLow", 
  "KwDollarFirstel", "KwDollarLastel", "KwDollarSigned", "KwDollarUnsigned", 
  "KwDollarPow", "KwDollarClog2", "KwAssert", "KwAssume", "KwCover", "KwVoid", 
  "KwType", "KwTypeof", "KwAlias", "KwEnum", "KwClass", "KwPacked", "KwMixin", 
  "KwExtends", "KwVirtual", "KwAbstract", "KwIsvtype", "KwBase", "KwStatic", 
  "KwProc", "KwSelf", "KwSelfT", "KwPub", "KwProt", "KwPriv", "KwString", 
  "KwFloat", "MiscReservedIdent", "MiscIdent", "MiscOther"
};

dfa::Vocabulary FlingHdlGrammarParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> FlingHdlGrammarParser::_tokenNames;

FlingHdlGrammarParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x8e, 0x553, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 
    0x4, 0x50, 0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
    0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 0x9, 
    0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 0x9, 0x5c, 
    0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 0x9, 0x5f, 0x4, 
    0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 0x9, 0x62, 0x4, 0x63, 
    0x9, 0x63, 0x4, 0x64, 0x9, 0x64, 0x4, 0x65, 0x9, 0x65, 0x4, 0x66, 0x9, 
    0x66, 0x4, 0x67, 0x9, 0x67, 0x4, 0x68, 0x9, 0x68, 0x4, 0x69, 0x9, 0x69, 
    0x4, 0x6a, 0x9, 0x6a, 0x4, 0x6b, 0x9, 0x6b, 0x4, 0x6c, 0x9, 0x6c, 0x4, 
    0x6d, 0x9, 0x6d, 0x4, 0x6e, 0x9, 0x6e, 0x4, 0x6f, 0x9, 0x6f, 0x4, 0x70, 
    0x9, 0x70, 0x4, 0x71, 0x9, 0x71, 0x4, 0x72, 0x9, 0x72, 0x4, 0x73, 0x9, 
    0x73, 0x4, 0x74, 0x9, 0x74, 0x4, 0x75, 0x9, 0x75, 0x4, 0x76, 0x9, 0x76, 
    0x4, 0x77, 0x9, 0x77, 0x4, 0x78, 0x9, 0x78, 0x4, 0x79, 0x9, 0x79, 0x4, 
    0x7a, 0x9, 0x7a, 0x4, 0x7b, 0x9, 0x7b, 0x4, 0x7c, 0x9, 0x7c, 0x4, 0x7d, 
    0x9, 0x7d, 0x4, 0x7e, 0x9, 0x7e, 0x4, 0x7f, 0x9, 0x7f, 0x4, 0x80, 0x9, 
    0x80, 0x4, 0x81, 0x9, 0x81, 0x4, 0x82, 0x9, 0x82, 0x4, 0x83, 0x9, 0x83, 
    0x4, 0x84, 0x9, 0x84, 0x4, 0x85, 0x9, 0x85, 0x4, 0x86, 0x9, 0x86, 0x4, 
    0x87, 0x9, 0x87, 0x3, 0x2, 0x7, 0x2, 0x110, 0xa, 0x2, 0xc, 0x2, 0xe, 
    0x2, 0x113, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x11d, 0xa, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x123, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 
    0x126, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x130, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x136, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x139, 
    0xb, 0x6, 0x3, 0x6, 0x5, 0x6, 0x13c, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x145, 0xa, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x14a, 0xa, 0x7, 0x5, 0x7, 0x14c, 
    0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x152, 0xa, 
    0x8, 0xc, 0x8, 0xe, 0x8, 0x155, 0xb, 0x8, 0x3, 0x8, 0x5, 0x8, 0x158, 
    0xa, 0x8, 0x5, 0x8, 0x15a, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x164, 0xa, 0x9, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x169, 0xa, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x170, 0xa, 0xb, 0xc, 0xb, 
    0xe, 0xb, 0x173, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x177, 0xa, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x17c, 0xa, 0xd, 0xc, 0xd, 
    0xe, 0xd, 0x17f, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x188, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0x191, 
    0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x194, 0xb, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x19d, 
    0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x1a1, 0xa, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x1a7, 0xa, 0x14, 0xc, 0x14, 
    0xe, 0x14, 0x1aa, 0xb, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 
    0x1bc, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x1c8, 
    0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 
    0x18, 0x1cf, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x1d2, 0xb, 0x18, 0x3, 
    0x18, 0x5, 0x18, 0x1d5, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
    0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x1e5, 
    0xa, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x1e8, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 
    0x1eb, 0xb, 0x1b, 0x3, 0x1b, 0x6, 0x1b, 0x1ee, 0xa, 0x1b, 0xd, 0x1b, 
    0xe, 0x1b, 0x1ef, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x1f4, 0xa, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 
    0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x5, 0x20, 0x211, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x218, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 
    0x21b, 0xb, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 
    0x7, 0x23, 0x222, 0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 0x225, 0xb, 0x23, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x237, 0xa, 0x24, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x23d, 0xa, 0x25, 0xc, 0x25, 
    0xe, 0x25, 0x240, 0xb, 0x25, 0x3, 0x25, 0x5, 0x25, 0x243, 0xa, 0x25, 
    0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x250, 
    0xa, 0x28, 0x3, 0x28, 0x7, 0x28, 0x253, 0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 
    0x256, 0xb, 0x28, 0x3, 0x28, 0x6, 0x28, 0x259, 0xa, 0x28, 0xd, 0x28, 
    0xe, 0x28, 0x25a, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x25f, 0xa, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 
    0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 
    0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 
    0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x283, 0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x28c, 
    0xa, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 
    0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x5, 0x32, 0x29b, 0xa, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x5, 0x33, 0x2a1, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x5, 0x33, 0x2a6, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x5, 0x34, 
    0x2ab, 0xa, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x2af, 0xa, 0x34, 
    0x3, 0x34, 0x5, 0x34, 0x2b2, 0xa, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 
    0x5, 0x34, 0x2b7, 0xa, 0x34, 0x3, 0x34, 0x3, 0x34, 0x7, 0x34, 0x2bb, 
    0xa, 0x34, 0xc, 0x34, 0xe, 0x34, 0x2be, 0xb, 0x34, 0x3, 0x34, 0x3, 0x34, 
    0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x2c7, 
    0xa, 0x36, 0x3, 0x37, 0x5, 0x37, 0x2ca, 0xa, 0x37, 0x3, 0x37, 0x5, 0x37, 
    0x2cd, 0xa, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 
    0x3, 0x38, 0x5, 0x38, 0x2d5, 0xa, 0x38, 0x3, 0x39, 0x5, 0x39, 0x2d8, 
    0xa, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x5, 0x3a, 0x2dd, 0xa, 0x3a, 
    0x3, 0x3a, 0x5, 0x3a, 0x2e0, 0xa, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 
    0x2e4, 0xa, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 
    0x2ea, 0xa, 0x3c, 0x3, 0x3d, 0x5, 0x3d, 0x2ed, 0xa, 0x3d, 0x3, 0x3d, 
    0x5, 0x3d, 0x2f0, 0xa, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x2f3, 0xa, 0x3d, 
    0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3e, 0x5, 0x3e, 0x2f8, 0xa, 0x3e, 0x3, 0x3e, 
    0x3, 0x3e, 0x5, 0x3e, 0x2fc, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 
    0x5, 0x3e, 0x301, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3f, 0x5, 0x3f, 
    0x306, 0xa, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 
    0x30c, 0xa, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x7, 0x3f, 0x310, 0xa, 0x3f, 
    0xc, 0x3f, 0xe, 0x3f, 0x313, 0xb, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x31a, 0xa, 0x40, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 0x322, 0xa, 0x42, 
    0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x43, 0x3, 0x43, 0x7, 
    0x43, 0x32a, 0xa, 0x43, 0xc, 0x43, 0xe, 0x43, 0x32d, 0xb, 0x43, 0x3, 
    0x43, 0x3, 0x43, 0x3, 0x44, 0x5, 0x44, 0x332, 0xa, 0x44, 0x3, 0x44, 
    0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 
    0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x5, 0x44, 
    0x341, 0xa, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x7, 0x45, 
    0x347, 0xa, 0x45, 0xc, 0x45, 0xe, 0x45, 0x34a, 0xb, 0x45, 0x3, 0x45, 
    0x5, 0x45, 0x34d, 0xa, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 
    0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 
    0x48, 0x5, 0x48, 0x35a, 0xa, 0x48, 0x3, 0x48, 0x7, 0x48, 0x35d, 0xa, 
    0x48, 0xc, 0x48, 0xe, 0x48, 0x360, 0xb, 0x48, 0x3, 0x48, 0x6, 0x48, 
    0x363, 0xa, 0x48, 0xd, 0x48, 0xe, 0x48, 0x364, 0x3, 0x48, 0x3, 0x48, 
    0x5, 0x48, 0x369, 0xa, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x49, 0x3, 0x49, 
    0x3, 0x49, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x3, 
    0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 
    0x3, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 0x3, 
    0x4e, 0x5, 0x4e, 0x383, 0xa, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4f, 
    0x3, 0x4f, 0x7, 0x4f, 0x389, 0xa, 0x4f, 0xc, 0x4f, 0xe, 0x4f, 0x38c, 
    0xb, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 
    0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 
    0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x5, 0x50, 0x39e, 0xa, 0x50, 
    0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x7, 0x51, 0x3a4, 0xa, 0x51, 
    0xc, 0x51, 0xe, 0x51, 0x3a7, 0xb, 0x51, 0x3, 0x51, 0x5, 0x51, 0x3aa, 
    0xa, 0x51, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x53, 0x3, 
    0x53, 0x3, 0x53, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x5, 0x54, 
    0x3b7, 0xa, 0x54, 0x3, 0x54, 0x7, 0x54, 0x3ba, 0xa, 0x54, 0xc, 0x54, 
    0xe, 0x54, 0x3bd, 0xb, 0x54, 0x3, 0x54, 0x6, 0x54, 0x3c0, 0xa, 0x54, 
    0xd, 0x54, 0xe, 0x54, 0x3c1, 0x3, 0x54, 0x3, 0x54, 0x5, 0x54, 0x3c6, 
    0xa, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 
    0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 
    0x3, 0x57, 0x3, 0x57, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 
    0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x5, 0x5a, 
    0x3e0, 0xa, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 
    0x3, 0x5b, 0x7, 0x5b, 0x3e8, 0xa, 0x5b, 0xc, 0x5b, 0xe, 0x5b, 0x3eb, 
    0xb, 0x5b, 0x3, 0x5b, 0x5, 0x5b, 0x3ee, 0xa, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 
    0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x5, 0x5c, 0x3f5, 0xa, 0x5c, 0x3, 0x5c, 
    0x3, 0x5c, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x5, 0x5d, 0x3fc, 0xa, 0x5d, 
    0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 
    0x5e, 0x3, 0x5e, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 
    0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 
    0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x61, 0x3, 0x61, 
    0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 0x7, 0x62, 0x41b, 0xa, 0x62, 0xc, 0x62, 
    0xe, 0x62, 0x41e, 0xb, 0x62, 0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 0x7, 0x63, 
    0x423, 0xa, 0x63, 0xc, 0x63, 0xe, 0x63, 0x426, 0xb, 0x63, 0x3, 0x64, 
    0x3, 0x64, 0x3, 0x64, 0x7, 0x64, 0x42b, 0xa, 0x64, 0xc, 0x64, 0xe, 0x64, 
    0x42e, 0xb, 0x64, 0x3, 0x65, 0x3, 0x65, 0x3, 0x65, 0x7, 0x65, 0x433, 
    0xa, 0x65, 0xc, 0x65, 0xe, 0x65, 0x436, 0xb, 0x65, 0x3, 0x66, 0x3, 0x66, 
    0x3, 0x66, 0x3, 0x66, 0x7, 0x66, 0x43c, 0xa, 0x66, 0xc, 0x66, 0xe, 0x66, 
    0x43f, 0xb, 0x66, 0x3, 0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 0x67, 
    0x3, 0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 0x67, 0x5, 0x67, 0x44a, 0xa, 0x67, 
    0x3, 0x68, 0x3, 0x68, 0x3, 0x68, 0x7, 0x68, 0x44f, 0xa, 0x68, 0xc, 0x68, 
    0xe, 0x68, 0x452, 0xb, 0x68, 0x3, 0x68, 0x7, 0x68, 0x455, 0xa, 0x68, 
    0xc, 0x68, 0xe, 0x68, 0x458, 0xb, 0x68, 0x3, 0x69, 0x3, 0x69, 0x5, 0x69, 
    0x45c, 0xa, 0x69, 0x3, 0x6a, 0x3, 0x6a, 0x3, 0x6a, 0x5, 0x6a, 0x461, 
    0xa, 0x6a, 0x3, 0x6a, 0x3, 0x6a, 0x3, 0x6b, 0x5, 0x6b, 0x466, 0xa, 0x6b, 
    0x3, 0x6b, 0x3, 0x6b, 0x5, 0x6b, 0x46a, 0xa, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 
    0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 
    0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 
    0x5, 0x6b, 0x47b, 0xa, 0x6b, 0x3, 0x6b, 0x7, 0x6b, 0x47e, 0xa, 0x6b, 
    0xc, 0x6b, 0xe, 0x6b, 0x481, 0xb, 0x6b, 0x3, 0x6b, 0x5, 0x6b, 0x484, 
    0xa, 0x6b, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x3, 
    0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x5, 0x6c, 0x490, 
    0xa, 0x6c, 0x3, 0x6d, 0x3, 0x6d, 0x3, 0x6d, 0x5, 0x6d, 0x495, 0xa, 0x6d, 
    0x3, 0x6e, 0x3, 0x6e, 0x3, 0x6e, 0x5, 0x6e, 0x49a, 0xa, 0x6e, 0x3, 0x6f, 
    0x3, 0x6f, 0x3, 0x6f, 0x5, 0x6f, 0x49f, 0xa, 0x6f, 0x3, 0x70, 0x3, 0x70, 
    0x3, 0x70, 0x5, 0x70, 0x4a4, 0xa, 0x70, 0x3, 0x71, 0x3, 0x71, 0x3, 0x71, 
    0x5, 0x71, 0x4a9, 0xa, 0x71, 0x3, 0x72, 0x3, 0x72, 0x3, 0x72, 0x5, 0x72, 
    0x4ae, 0xa, 0x72, 0x3, 0x73, 0x3, 0x73, 0x3, 0x73, 0x5, 0x73, 0x4b3, 
    0xa, 0x73, 0x3, 0x74, 0x3, 0x74, 0x3, 0x74, 0x5, 0x74, 0x4b8, 0xa, 0x74, 
    0x3, 0x75, 0x3, 0x75, 0x3, 0x75, 0x5, 0x75, 0x4bd, 0xa, 0x75, 0x3, 0x76, 
    0x3, 0x76, 0x3, 0x76, 0x5, 0x76, 0x4c2, 0xa, 0x76, 0x3, 0x77, 0x3, 0x77, 
    0x3, 0x77, 0x5, 0x77, 0x4c7, 0xa, 0x77, 0x3, 0x78, 0x3, 0x78, 0x5, 0x78, 
    0x4cb, 0xa, 0x78, 0x3, 0x79, 0x3, 0x79, 0x3, 0x79, 0x3, 0x79, 0x3, 0x79, 
    0x3, 0x79, 0x3, 0x79, 0x3, 0x79, 0x3, 0x79, 0x3, 0x79, 0x5, 0x79, 0x4d7, 
    0xa, 0x79, 0x3, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 0x3, 
    0x7a, 0x3, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 0x5, 0x7a, 
    0x4e4, 0xa, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 
    0x5, 0x7a, 0x4eb, 0xa, 0x7a, 0x5, 0x7a, 0x4ed, 0xa, 0x7a, 0x3, 0x7b, 
    0x3, 0x7b, 0x3, 0x7b, 0x3, 0x7b, 0x3, 0x7b, 0x3, 0x7b, 0x3, 0x7b, 0x3, 
    0x7c, 0x3, 0x7c, 0x5, 0x7c, 0x4f8, 0xa, 0x7c, 0x3, 0x7d, 0x3, 0x7d, 
    0x5, 0x7d, 0x4fc, 0xa, 0x7d, 0x3, 0x7d, 0x3, 0x7d, 0x3, 0x7d, 0x3, 0x7e, 
    0x3, 0x7e, 0x3, 0x7e, 0x3, 0x7e, 0x3, 0x7e, 0x3, 0x7e, 0x3, 0x7e, 0x3, 
    0x7f, 0x3, 0x7f, 0x3, 0x7f, 0x3, 0x7f, 0x3, 0x7f, 0x3, 0x80, 0x3, 0x80, 
    0x3, 0x80, 0x3, 0x80, 0x3, 0x80, 0x3, 0x80, 0x3, 0x80, 0x3, 0x81, 0x3, 
    0x81, 0x5, 0x81, 0x516, 0xa, 0x81, 0x3, 0x82, 0x3, 0x82, 0x3, 0x82, 
    0x3, 0x82, 0x3, 0x82, 0x3, 0x83, 0x3, 0x83, 0x3, 0x83, 0x3, 0x83, 0x3, 
    0x83, 0x3, 0x83, 0x3, 0x83, 0x3, 0x84, 0x3, 0x84, 0x3, 0x84, 0x5, 0x84, 
    0x527, 0xa, 0x84, 0x3, 0x84, 0x3, 0x84, 0x3, 0x84, 0x7, 0x84, 0x52c, 
    0xa, 0x84, 0xc, 0x84, 0xe, 0x84, 0x52f, 0xb, 0x84, 0x3, 0x84, 0x5, 0x84, 
    0x532, 0xa, 0x84, 0x3, 0x85, 0x3, 0x85, 0x5, 0x85, 0x536, 0xa, 0x85, 
    0x3, 0x85, 0x5, 0x85, 0x539, 0xa, 0x85, 0x3, 0x85, 0x7, 0x85, 0x53c, 
    0xa, 0x85, 0xc, 0x85, 0xe, 0x85, 0x53f, 0xb, 0x85, 0x3, 0x86, 0x3, 0x86, 
    0x3, 0x86, 0x3, 0x86, 0x3, 0x86, 0x3, 0x86, 0x5, 0x86, 0x547, 0xa, 0x86, 
    0x3, 0x87, 0x3, 0x87, 0x5, 0x87, 0x54b, 0xa, 0x87, 0x3, 0x87, 0x3, 0x87, 
    0x5, 0x87, 0x54f, 0xa, 0x87, 0x3, 0x87, 0x3, 0x87, 0x3, 0x87, 0x2, 0x2, 
    0x88, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 
    0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 
    0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 
    0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 
    0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 
    0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 
    0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe, 0xc0, 
    0xc2, 0xc4, 0xc6, 0xc8, 0xca, 0xcc, 0xce, 0xd0, 0xd2, 0xd4, 0xd6, 0xd8, 
    0xda, 0xdc, 0xde, 0xe0, 0xe2, 0xe4, 0xe6, 0xe8, 0xea, 0xec, 0xee, 0xf0, 
    0xf2, 0xf4, 0xf6, 0xf8, 0xfa, 0xfc, 0xfe, 0x100, 0x102, 0x104, 0x106, 
    0x108, 0x10a, 0x10c, 0x2, 0x14, 0x4, 0x2, 0x3f, 0x3f, 0x77, 0x77, 0x3, 
    0x2, 0x41, 0x44, 0x3, 0x2, 0x49, 0x4a, 0x3, 0x2, 0x38, 0x39, 0x3, 0x2, 
    0x87, 0x89, 0x4, 0x2, 0x7f, 0x7f, 0x83, 0x83, 0x4, 0x2, 0x41, 0x41, 
    0x43, 0x43, 0x3, 0x2, 0x1d, 0x1e, 0x3, 0x2, 0x1f, 0x20, 0x3, 0x2, 0x21, 
    0x22, 0x3, 0x2, 0x10, 0x13, 0x3, 0x2, 0x14, 0x17, 0x3, 0x2, 0x23, 0x25, 
    0x3, 0x2, 0x18, 0x19, 0x3, 0x2, 0x1a, 0x1c, 0x5, 0x2, 0x18, 0x19, 0x1d, 
    0x22, 0x26, 0x27, 0x4, 0x2, 0x6f, 0x70, 0x72, 0x72, 0x3, 0x2, 0x69, 
    0x6c, 0x2, 0x5ac, 0x2, 0x111, 0x3, 0x2, 0x2, 0x2, 0x4, 0x11c, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x8, 0x12f, 0x3, 0x2, 0x2, 
    0x2, 0xa, 0x131, 0x3, 0x2, 0x2, 0x2, 0xc, 0x13f, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x10, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0x165, 0x3, 0x2, 0x2, 0x2, 0x14, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16, 0x176, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0x178, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x180, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0x184, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x18b, 0x3, 0x2, 
    0x2, 0x2, 0x20, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x22, 0x195, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0x199, 0x3, 0x2, 0x2, 0x2, 0x26, 0x1a4, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x2c, 
    0x1c7, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x30, 0x1d6, 
    0x3, 0x2, 0x2, 0x2, 0x32, 0x1db, 0x3, 0x2, 0x2, 0x2, 0x34, 0x1df, 0x3, 
    0x2, 0x2, 0x2, 0x36, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x38, 0x1fa, 0x3, 0x2, 
    0x2, 0x2, 0x3a, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x207, 0x3, 0x2, 0x2, 
    0x2, 0x3e, 0x210, 0x3, 0x2, 0x2, 0x2, 0x40, 0x214, 0x3, 0x2, 0x2, 0x2, 
    0x42, 0x21c, 0x3, 0x2, 0x2, 0x2, 0x44, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x46, 
    0x236, 0x3, 0x2, 0x2, 0x2, 0x48, 0x238, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x244, 
    0x3, 0x2, 0x2, 0x2, 0x4c, 0x248, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x24b, 0x3, 
    0x2, 0x2, 0x2, 0x50, 0x262, 0x3, 0x2, 0x2, 0x2, 0x52, 0x265, 0x3, 0x2, 
    0x2, 0x2, 0x54, 0x268, 0x3, 0x2, 0x2, 0x2, 0x56, 0x26e, 0x3, 0x2, 0x2, 
    0x2, 0x58, 0x272, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x277, 0x3, 0x2, 0x2, 0x2, 
    0x5c, 0x27c, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x286, 0x3, 0x2, 0x2, 0x2, 0x60, 
    0x28f, 0x3, 0x2, 0x2, 0x2, 0x62, 0x29a, 0x3, 0x2, 0x2, 0x2, 0x64, 0x29c, 
    0x3, 0x2, 0x2, 0x2, 0x66, 0x2aa, 0x3, 0x2, 0x2, 0x2, 0x68, 0x2c1, 0x3, 
    0x2, 0x2, 0x2, 0x6a, 0x2c6, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x2c9, 0x3, 0x2, 
    0x2, 0x2, 0x6e, 0x2d4, 0x3, 0x2, 0x2, 0x2, 0x70, 0x2d7, 0x3, 0x2, 0x2, 
    0x2, 0x72, 0x2dc, 0x3, 0x2, 0x2, 0x2, 0x74, 0x2e5, 0x3, 0x2, 0x2, 0x2, 
    0x76, 0x2e9, 0x3, 0x2, 0x2, 0x2, 0x78, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x7a, 
    0x2f7, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x305, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x319, 
    0x3, 0x2, 0x2, 0x2, 0x80, 0x31b, 0x3, 0x2, 0x2, 0x2, 0x82, 0x31e, 0x3, 
    0x2, 0x2, 0x2, 0x84, 0x327, 0x3, 0x2, 0x2, 0x2, 0x86, 0x340, 0x3, 0x2, 
    0x2, 0x2, 0x88, 0x342, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x34e, 0x3, 0x2, 0x2, 
    0x2, 0x8c, 0x352, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x355, 0x3, 0x2, 0x2, 0x2, 
    0x90, 0x36c, 0x3, 0x2, 0x2, 0x2, 0x92, 0x36f, 0x3, 0x2, 0x2, 0x2, 0x94, 
    0x372, 0x3, 0x2, 0x2, 0x2, 0x96, 0x378, 0x3, 0x2, 0x2, 0x2, 0x98, 0x37c, 
    0x3, 0x2, 0x2, 0x2, 0x9a, 0x37f, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x386, 0x3, 
    0x2, 0x2, 0x2, 0x9e, 0x39d, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x39f, 0x3, 0x2, 
    0x2, 0x2, 0xa2, 0x3ab, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x3af, 0x3, 0x2, 0x2, 
    0x2, 0xa6, 0x3b2, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x3c9, 0x3, 0x2, 0x2, 0x2, 
    0xaa, 0x3cc, 0x3, 0x2, 0x2, 0x2, 0xac, 0x3cf, 0x3, 0x2, 0x2, 0x2, 0xae, 
    0x3d5, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x3d9, 0x3, 0x2, 0x2, 0x2, 0xb2, 0x3dc, 
    0x3, 0x2, 0x2, 0x2, 0xb4, 0x3e3, 0x3, 0x2, 0x2, 0x2, 0xb6, 0x3f1, 0x3, 
    0x2, 0x2, 0x2, 0xb8, 0x3fb, 0x3, 0x2, 0x2, 0x2, 0xba, 0x3fd, 0x3, 0x2, 
    0x2, 0x2, 0xbc, 0x405, 0x3, 0x2, 0x2, 0x2, 0xbe, 0x40d, 0x3, 0x2, 0x2, 
    0x2, 0xc0, 0x415, 0x3, 0x2, 0x2, 0x2, 0xc2, 0x417, 0x3, 0x2, 0x2, 0x2, 
    0xc4, 0x41f, 0x3, 0x2, 0x2, 0x2, 0xc6, 0x427, 0x3, 0x2, 0x2, 0x2, 0xc8, 
    0x42f, 0x3, 0x2, 0x2, 0x2, 0xca, 0x437, 0x3, 0x2, 0x2, 0x2, 0xcc, 0x449, 
    0x3, 0x2, 0x2, 0x2, 0xce, 0x44b, 0x3, 0x2, 0x2, 0x2, 0xd0, 0x459, 0x3, 
    0x2, 0x2, 0x2, 0xd2, 0x45d, 0x3, 0x2, 0x2, 0x2, 0xd4, 0x483, 0x3, 0x2, 
    0x2, 0x2, 0xd6, 0x48f, 0x3, 0x2, 0x2, 0x2, 0xd8, 0x491, 0x3, 0x2, 0x2, 
    0x2, 0xda, 0x496, 0x3, 0x2, 0x2, 0x2, 0xdc, 0x49b, 0x3, 0x2, 0x2, 0x2, 
    0xde, 0x4a0, 0x3, 0x2, 0x2, 0x2, 0xe0, 0x4a5, 0x3, 0x2, 0x2, 0x2, 0xe2, 
    0x4aa, 0x3, 0x2, 0x2, 0x2, 0xe4, 0x4af, 0x3, 0x2, 0x2, 0x2, 0xe6, 0x4b4, 
    0x3, 0x2, 0x2, 0x2, 0xe8, 0x4b9, 0x3, 0x2, 0x2, 0x2, 0xea, 0x4be, 0x3, 
    0x2, 0x2, 0x2, 0xec, 0x4c6, 0x3, 0x2, 0x2, 0x2, 0xee, 0x4ca, 0x3, 0x2, 
    0x2, 0x2, 0xf0, 0x4d6, 0x3, 0x2, 0x2, 0x2, 0xf2, 0x4ec, 0x3, 0x2, 0x2, 
    0x2, 0xf4, 0x4ee, 0x3, 0x2, 0x2, 0x2, 0xf6, 0x4f7, 0x3, 0x2, 0x2, 0x2, 
    0xf8, 0x4fb, 0x3, 0x2, 0x2, 0x2, 0xfa, 0x500, 0x3, 0x2, 0x2, 0x2, 0xfc, 
    0x507, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x50c, 0x3, 0x2, 0x2, 0x2, 0x100, 0x515, 
    0x3, 0x2, 0x2, 0x2, 0x102, 0x517, 0x3, 0x2, 0x2, 0x2, 0x104, 0x51c, 
    0x3, 0x2, 0x2, 0x2, 0x106, 0x526, 0x3, 0x2, 0x2, 0x2, 0x108, 0x533, 
    0x3, 0x2, 0x2, 0x2, 0x10a, 0x546, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x54a, 
    0x3, 0x2, 0x2, 0x2, 0x10e, 0x110, 0x5, 0x4, 0x3, 0x2, 0x10f, 0x10e, 
    0x3, 0x2, 0x2, 0x2, 0x110, 0x113, 0x3, 0x2, 0x2, 0x2, 0x111, 0x10f, 
    0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x3, 0x2, 0x2, 0x2, 0x112, 0x114, 
    0x3, 0x2, 0x2, 0x2, 0x113, 0x111, 0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 
    0x7, 0x2, 0x2, 0x3, 0x115, 0x3, 0x3, 0x2, 0x2, 0x2, 0x116, 0x11d, 0x5, 
    0x6, 0x4, 0x2, 0x117, 0x11d, 0x5, 0x24, 0x13, 0x2, 0x118, 0x11d, 0x5, 
    0x62, 0x32, 0x2, 0x119, 0x11d, 0x5, 0x7e, 0x40, 0x2, 0x11a, 0x11d, 0x5, 
    0xb8, 0x5d, 0x2, 0x11b, 0x11d, 0x5, 0x60, 0x31, 0x2, 0x11c, 0x116, 0x3, 
    0x2, 0x2, 0x2, 0x11c, 0x117, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x118, 0x3, 
    0x2, 0x2, 0x2, 0x11c, 0x119, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11a, 0x3, 
    0x2, 0x2, 0x2, 0x11c, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x11e, 0x11f, 0x7, 0x40, 0x2, 0x2, 0x11f, 0x120, 0x5, 0xc0, 
    0x61, 0x2, 0x120, 0x124, 0x7, 0x2f, 0x2, 0x2, 0x121, 0x123, 0x5, 0x8, 
    0x5, 0x2, 0x122, 0x121, 0x3, 0x2, 0x2, 0x2, 0x123, 0x126, 0x3, 0x2, 
    0x2, 0x2, 0x124, 0x122, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x3, 0x2, 
    0x2, 0x2, 0x125, 0x127, 0x3, 0x2, 0x2, 0x2, 0x126, 0x124, 0x3, 0x2, 
    0x2, 0x2, 0x127, 0x128, 0x7, 0x30, 0x2, 0x2, 0x128, 0x7, 0x3, 0x2, 0x2, 
    0x2, 0x129, 0x130, 0x5, 0x6, 0x4, 0x2, 0x12a, 0x130, 0x5, 0x24, 0x13, 
    0x2, 0x12b, 0x130, 0x5, 0x62, 0x32, 0x2, 0x12c, 0x130, 0x5, 0x7e, 0x40, 
    0x2, 0x12d, 0x130, 0x5, 0xb8, 0x5d, 0x2, 0x12e, 0x130, 0x5, 0x60, 0x31, 
    0x2, 0x12f, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12a, 0x3, 0x2, 0x2, 
    0x2, 0x12f, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12c, 0x3, 0x2, 0x2, 
    0x2, 0x12f, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12e, 0x3, 0x2, 0x2, 
    0x2, 0x130, 0x9, 0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x7, 0x14, 0x2, 0x2, 
    0x132, 0x137, 0x5, 0xc, 0x7, 0x2, 0x133, 0x134, 0x7, 0x31, 0x2, 0x2, 
    0x134, 0x136, 0x5, 0xc, 0x7, 0x2, 0x135, 0x133, 0x3, 0x2, 0x2, 0x2, 
    0x136, 0x139, 0x3, 0x2, 0x2, 0x2, 0x137, 0x135, 0x3, 0x2, 0x2, 0x2, 
    0x137, 0x138, 0x3, 0x2, 0x2, 0x2, 0x138, 0x13b, 0x3, 0x2, 0x2, 0x2, 
    0x139, 0x137, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13c, 0x7, 0x31, 0x2, 0x2, 
    0x13b, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 0x3, 0x2, 0x2, 0x2, 
    0x13c, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 0x7, 0x15, 0x2, 0x2, 
    0x13e, 0xb, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 0x5, 0xc2, 0x62, 0x2, 
    0x140, 0x14b, 0x7, 0x32, 0x2, 0x2, 0x141, 0x144, 0x5, 0xcc, 0x67, 0x2, 
    0x142, 0x143, 0x7, 0xd, 0x2, 0x2, 0x143, 0x145, 0x5, 0xc6, 0x64, 0x2, 
    0x144, 0x142, 0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 0x3, 0x2, 0x2, 0x2, 
    0x145, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x146, 0x149, 0x9, 0x2, 0x2, 0x2, 
    0x147, 0x148, 0x7, 0xd, 0x2, 0x2, 0x148, 0x14a, 0x5, 0xc8, 0x65, 0x2, 
    0x149, 0x147, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x3, 0x2, 0x2, 0x2, 
    0x14a, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x141, 0x3, 0x2, 0x2, 0x2, 
    0x14b, 0x146, 0x3, 0x2, 0x2, 0x2, 0x14c, 0xd, 0x3, 0x2, 0x2, 0x2, 0x14d, 
    0x159, 0x7, 0x2b, 0x2, 0x2, 0x14e, 0x153, 0x5, 0x10, 0x9, 0x2, 0x14f, 
    0x150, 0x7, 0x31, 0x2, 0x2, 0x150, 0x152, 0x5, 0x10, 0x9, 0x2, 0x151, 
    0x14f, 0x3, 0x2, 0x2, 0x2, 0x152, 0x155, 0x3, 0x2, 0x2, 0x2, 0x153, 
    0x151, 0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 0x3, 0x2, 0x2, 0x2, 0x154, 
    0x157, 0x3, 0x2, 0x2, 0x2, 0x155, 0x153, 0x3, 0x2, 0x2, 0x2, 0x156, 
    0x158, 0x7, 0x31, 0x2, 0x2, 0x157, 0x156, 0x3, 0x2, 0x2, 0x2, 0x157, 
    0x158, 0x3, 0x2, 0x2, 0x2, 0x158, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x159, 
    0x14e, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15a, 
    0x15b, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15c, 0x7, 0x2c, 0x2, 0x2, 0x15c, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15e, 0x5, 0xc2, 0x62, 0x2, 0x15e, 
    0x15f, 0x7, 0x32, 0x2, 0x2, 0x15f, 0x160, 0x9, 0x3, 0x2, 0x2, 0x160, 
    0x163, 0x5, 0xcc, 0x67, 0x2, 0x161, 0x162, 0x7, 0xd, 0x2, 0x2, 0x162, 
    0x164, 0x5, 0xc6, 0x64, 0x2, 0x163, 0x161, 0x3, 0x2, 0x2, 0x2, 0x163, 
    0x164, 0x3, 0x2, 0x2, 0x2, 0x164, 0x11, 0x3, 0x2, 0x2, 0x2, 0x165, 0x168, 
    0x7, 0x14, 0x2, 0x2, 0x166, 0x169, 0x5, 0x14, 0xb, 0x2, 0x167, 0x169, 
    0x5, 0x18, 0xd, 0x2, 0x168, 0x166, 0x3, 0x2, 0x2, 0x2, 0x168, 0x167, 
    0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x3, 0x2, 0x2, 0x2, 0x169, 0x16a, 
    0x3, 0x2, 0x2, 0x2, 0x16a, 0x16b, 0x7, 0x15, 0x2, 0x2, 0x16b, 0x13, 
    0x3, 0x2, 0x2, 0x2, 0x16c, 0x171, 0x5, 0x16, 0xc, 0x2, 0x16d, 0x16e, 
    0x7, 0x33, 0x2, 0x2, 0x16e, 0x170, 0x5, 0x16, 0xc, 0x2, 0x16f, 0x16d, 
    0x3, 0x2, 0x2, 0x2, 0x170, 0x173, 0x3, 0x2, 0x2, 0x2, 0x171, 0x16f, 
    0x3, 0x2, 0x2, 0x2, 0x171, 0x172, 0x3, 0x2, 0x2, 0x2, 0x172, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0x173, 0x171, 0x3, 0x2, 0x2, 0x2, 0x174, 0x177, 0x5, 
    0xd6, 0x6c, 0x2, 0x175, 0x177, 0x5, 0xcc, 0x67, 0x2, 0x176, 0x174, 0x3, 
    0x2, 0x2, 0x2, 0x176, 0x175, 0x3, 0x2, 0x2, 0x2, 0x177, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0x178, 0x17d, 0x5, 0x1a, 0xe, 0x2, 0x179, 0x17a, 0x7, 0x33, 
    0x2, 0x2, 0x17a, 0x17c, 0x5, 0x1a, 0xe, 0x2, 0x17b, 0x179, 0x3, 0x2, 
    0x2, 0x2, 0x17c, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17b, 0x3, 0x2, 
    0x2, 0x2, 0x17d, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0x17f, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x180, 0x181, 0x5, 0xc0, 0x61, 
    0x2, 0x181, 0x182, 0x7, 0x28, 0x2, 0x2, 0x182, 0x183, 0x5, 0x16, 0xc, 
    0x2, 0x183, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x184, 0x187, 0x7, 0x2b, 0x2, 
    0x2, 0x185, 0x188, 0x5, 0x1e, 0x10, 0x2, 0x186, 0x188, 0x5, 0x20, 0x11, 
    0x2, 0x187, 0x185, 0x3, 0x2, 0x2, 0x2, 0x187, 0x186, 0x3, 0x2, 0x2, 
    0x2, 0x187, 0x188, 0x3, 0x2, 0x2, 0x2, 0x188, 0x189, 0x3, 0x2, 0x2, 
    0x2, 0x189, 0x18a, 0x7, 0x2c, 0x2, 0x2, 0x18a, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0x18b, 0x18c, 0x5, 0xc6, 0x64, 0x2, 0x18c, 0x1f, 0x3, 0x2, 0x2, 
    0x2, 0x18d, 0x192, 0x5, 0x22, 0x12, 0x2, 0x18e, 0x18f, 0x7, 0x33, 0x2, 
    0x2, 0x18f, 0x191, 0x5, 0x22, 0x12, 0x2, 0x190, 0x18e, 0x3, 0x2, 0x2, 
    0x2, 0x191, 0x194, 0x3, 0x2, 0x2, 0x2, 0x192, 0x190, 0x3, 0x2, 0x2, 
    0x2, 0x192, 0x193, 0x3, 0x2, 0x2, 0x2, 0x193, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0x194, 0x192, 0x3, 0x2, 0x2, 0x2, 0x195, 0x196, 0x5, 0xc0, 0x61, 0x2, 
    0x196, 0x197, 0x7, 0x28, 0x2, 0x2, 0x197, 0x198, 0x5, 0xd6, 0x6c, 0x2, 
    0x198, 0x23, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19a, 0x7, 0x3f, 0x2, 0x2, 
    0x19a, 0x19c, 0x5, 0xc0, 0x61, 0x2, 0x19b, 0x19d, 0x5, 0xa, 0x6, 0x2, 
    0x19c, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19d, 0x3, 0x2, 0x2, 0x2, 
    0x19d, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x1a0, 0x5, 0xe, 0x8, 0x2, 
    0x19f, 0x1a1, 0x5, 0xca, 0x66, 0x2, 0x1a0, 0x19f, 0x3, 0x2, 0x2, 0x2, 
    0x1a0, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a2, 0x3, 0x2, 0x2, 0x2, 
    0x1a2, 0x1a3, 0x5, 0x26, 0x14, 0x2, 0x1a3, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0x1a4, 0x1a8, 0x7, 0x2f, 0x2, 0x2, 0x1a5, 0x1a7, 0x5, 0x28, 0x15, 0x2, 
    0x1a6, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1aa, 0x3, 0x2, 0x2, 0x2, 
    0x1a8, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a9, 0x3, 0x2, 0x2, 0x2, 
    0x1a9, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1a8, 0x3, 0x2, 0x2, 0x2, 
    0x1ab, 0x1ac, 0x7, 0x30, 0x2, 0x2, 0x1ac, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0x1ad, 0x1bc, 0x5, 0x2a, 0x16, 0x2, 0x1ae, 0x1af, 0x5, 0xd6, 0x6c, 0x2, 
    0x1af, 0x1b0, 0x7, 0x31, 0x2, 0x2, 0x1b0, 0x1bc, 0x3, 0x2, 0x2, 0x2, 
    0x1b1, 0x1bc, 0x5, 0x2c, 0x17, 0x2, 0x1b2, 0x1bc, 0x5, 0x3c, 0x1f, 0x2, 
    0x1b3, 0x1bc, 0x5, 0xca, 0x66, 0x2, 0x1b4, 0x1bc, 0x5, 0x3e, 0x20, 0x2, 
    0x1b5, 0x1bc, 0x5, 0x5c, 0x2f, 0x2, 0x1b6, 0x1bc, 0x5, 0x5e, 0x30, 0x2, 
    0x1b7, 0x1bc, 0x5, 0x60, 0x31, 0x2, 0x1b8, 0x1bc, 0x5, 0x62, 0x32, 0x2, 
    0x1b9, 0x1bc, 0x5, 0x7e, 0x40, 0x2, 0x1ba, 0x1bc, 0x5, 0xb8, 0x5d, 0x2, 
    0x1bb, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1ae, 0x3, 0x2, 0x2, 0x2, 
    0x1bb, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1b2, 0x3, 0x2, 0x2, 0x2, 
    0x1bb, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1b4, 0x3, 0x2, 0x2, 0x2, 
    0x1bb, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1b6, 0x3, 0x2, 0x2, 0x2, 
    0x1bb, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1b8, 0x3, 0x2, 0x2, 0x2, 
    0x1bb, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1ba, 0x3, 0x2, 0x2, 0x2, 
    0x1bc, 0x29, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1be, 0x5, 0xc0, 0x61, 0x2, 
    0x1be, 0x1bf, 0x7, 0x32, 0x2, 0x2, 0x1bf, 0x1c0, 0x7, 0x3f, 0x2, 0x2, 
    0x1c0, 0x1c1, 0x5, 0xcc, 0x67, 0x2, 0x1c1, 0x1c2, 0x5, 0x1c, 0xf, 0x2, 
    0x1c2, 0x1c3, 0x7, 0x31, 0x2, 0x2, 0x1c3, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0x1c4, 0x1c8, 0x5, 0x2e, 0x18, 0x2, 0x1c5, 0x1c8, 0x5, 0x34, 0x1b, 0x2, 
    0x1c6, 0x1c8, 0x5, 0x3a, 0x1e, 0x2, 0x1c7, 0x1c4, 0x3, 0x2, 0x2, 0x2, 
    0x1c7, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c6, 0x3, 0x2, 0x2, 0x2, 
    0x1c8, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1ca, 0x7, 0x45, 0x2, 0x2, 
    0x1ca, 0x1cb, 0x7, 0x34, 0x2, 0x2, 0x1cb, 0x1cc, 0x5, 0xd6, 0x6c, 0x2, 
    0x1cc, 0x1d0, 0x5, 0x26, 0x14, 0x2, 0x1cd, 0x1cf, 0x5, 0x30, 0x19, 0x2, 
    0x1ce, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d2, 0x3, 0x2, 0x2, 0x2, 
    0x1d0, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d1, 0x3, 0x2, 0x2, 0x2, 
    0x1d1, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d0, 0x3, 0x2, 0x2, 0x2, 
    0x1d3, 0x1d5, 0x5, 0x32, 0x1a, 0x2, 0x1d4, 0x1d3, 0x3, 0x2, 0x2, 0x2, 
    0x1d4, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x1d6, 
    0x1d7, 0x7, 0x45, 0x2, 0x2, 0x1d7, 0x1d8, 0x7, 0x35, 0x2, 0x2, 0x1d8, 
    0x1d9, 0x5, 0xd6, 0x6c, 0x2, 0x1d9, 0x1da, 0x5, 0x26, 0x14, 0x2, 0x1da, 
    0x31, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1dc, 0x7, 0x45, 0x2, 0x2, 0x1dc, 
    0x1dd, 0x7, 0x36, 0x2, 0x2, 0x1dd, 0x1de, 0x5, 0x26, 0x14, 0x2, 0x1de, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e0, 0x7, 0x45, 0x2, 0x2, 0x1e0, 
    0x1e1, 0x7, 0x38, 0x2, 0x2, 0x1e1, 0x1e2, 0x5, 0xd6, 0x6c, 0x2, 0x1e2, 
    0x1f3, 0x7, 0x2f, 0x2, 0x2, 0x1e3, 0x1e5, 0x5, 0x36, 0x1c, 0x2, 0x1e4, 
    0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e5, 
    0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1e8, 0x5, 0x38, 0x1d, 0x2, 0x1e7, 
    0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1e9, 
    0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1ea, 
    0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1ec, 
    0x1ee, 0x5, 0x38, 0x1d, 0x2, 0x1ed, 0x1ec, 0x3, 0x2, 0x2, 0x2, 0x1ee, 
    0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ef, 
    0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f1, 
    0x1f2, 0x5, 0x36, 0x1c, 0x2, 0x1f2, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f3, 
    0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1f4, 
    0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f6, 0x7, 0x30, 0x2, 0x2, 0x1f6, 
    0x35, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f8, 0x7, 0x3a, 0x2, 0x2, 0x1f8, 
    0x1f9, 0x5, 0x26, 0x14, 0x2, 0x1f9, 0x37, 0x3, 0x2, 0x2, 0x2, 0x1fa, 
    0x1fb, 0x5, 0xc6, 0x64, 0x2, 0x1fb, 0x1fc, 0x5, 0x26, 0x14, 0x2, 0x1fc, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fe, 0x7, 0x45, 0x2, 0x2, 0x1fe, 
    0x1ff, 0x7, 0x2d, 0x2, 0x2, 0x1ff, 0x200, 0x5, 0xc0, 0x61, 0x2, 0x200, 
    0x201, 0x7, 0x2e, 0x2, 0x2, 0x201, 0x202, 0x7, 0x3b, 0x2, 0x2, 0x202, 
    0x203, 0x5, 0xc0, 0x61, 0x2, 0x203, 0x204, 0x7, 0x32, 0x2, 0x2, 0x204, 
    0x205, 0x5, 0xd6, 0x6c, 0x2, 0x205, 0x206, 0x5, 0x26, 0x14, 0x2, 0x206, 
    0x3b, 0x3, 0x2, 0x2, 0x2, 0x207, 0x208, 0x5, 0xd6, 0x6c, 0x2, 0x208, 
    0x209, 0x7, 0xc, 0x2, 0x2, 0x209, 0x20a, 0x5, 0xd6, 0x6c, 0x2, 0x20a, 
    0x20b, 0x7, 0x31, 0x2, 0x2, 0x20b, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x20c, 
    0x211, 0x7, 0x46, 0x2, 0x2, 0x20d, 0x211, 0x7, 0x47, 0x2, 0x2, 0x20e, 
    0x20f, 0x7, 0x48, 0x2, 0x2, 0x20f, 0x211, 0x5, 0x40, 0x21, 0x2, 0x210, 
    0x20c, 0x3, 0x2, 0x2, 0x2, 0x210, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x210, 
    0x20e, 0x3, 0x2, 0x2, 0x2, 0x211, 0x212, 0x3, 0x2, 0x2, 0x2, 0x212, 
    0x213, 0x5, 0x44, 0x23, 0x2, 0x213, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x214, 
    0x219, 0x5, 0x42, 0x22, 0x2, 0x215, 0x216, 0x7, 0x33, 0x2, 0x2, 0x216, 
    0x218, 0x5, 0x42, 0x22, 0x2, 0x217, 0x215, 0x3, 0x2, 0x2, 0x2, 0x218, 
    0x21b, 0x3, 0x2, 0x2, 0x2, 0x219, 0x217, 0x3, 0x2, 0x2, 0x2, 0x219, 
    0x21a, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x41, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x219, 
    0x3, 0x2, 0x2, 0x2, 0x21c, 0x21d, 0x9, 0x4, 0x2, 0x2, 0x21d, 0x21e, 
    0x5, 0xd6, 0x6c, 0x2, 0x21e, 0x43, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x223, 
    0x7, 0x2f, 0x2, 0x2, 0x220, 0x222, 0x5, 0x46, 0x24, 0x2, 0x221, 0x220, 
    0x3, 0x2, 0x2, 0x2, 0x222, 0x225, 0x3, 0x2, 0x2, 0x2, 0x223, 0x221, 
    0x3, 0x2, 0x2, 0x2, 0x223, 0x224, 0x3, 0x2, 0x2, 0x2, 0x224, 0x226, 
    0x3, 0x2, 0x2, 0x2, 0x225, 0x223, 0x3, 0x2, 0x2, 0x2, 0x226, 0x227, 
    0x7, 0x30, 0x2, 0x2, 0x227, 0x45, 0x3, 0x2, 0x2, 0x2, 0x228, 0x237, 
    0x5, 0x44, 0x23, 0x2, 0x229, 0x237, 0x5, 0xb8, 0x5d, 0x2, 0x22a, 0x237, 
    0x5, 0x5e, 0x30, 0x2, 0x22b, 0x237, 0x5, 0x60, 0x31, 0x2, 0x22c, 0x237, 
    0x5, 0x62, 0x32, 0x2, 0x22d, 0x237, 0x5, 0x5a, 0x2e, 0x2, 0x22e, 0x237, 
    0x5, 0x58, 0x2d, 0x2, 0x22f, 0x237, 0x5, 0x48, 0x25, 0x2, 0x230, 0x237, 
    0x5, 0x4e, 0x28, 0x2, 0x231, 0x237, 0x5, 0x54, 0x2b, 0x2, 0x232, 0x237, 
    0x5, 0x56, 0x2c, 0x2, 0x233, 0x234, 0x5, 0xd6, 0x6c, 0x2, 0x234, 0x235, 
    0x7, 0x31, 0x2, 0x2, 0x235, 0x237, 0x3, 0x2, 0x2, 0x2, 0x236, 0x228, 
    0x3, 0x2, 0x2, 0x2, 0x236, 0x229, 0x3, 0x2, 0x2, 0x2, 0x236, 0x22a, 
    0x3, 0x2, 0x2, 0x2, 0x236, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x236, 0x22c, 
    0x3, 0x2, 0x2, 0x2, 0x236, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x236, 0x22e, 
    0x3, 0x2, 0x2, 0x2, 0x236, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x236, 0x230, 
    0x3, 0x2, 0x2, 0x2, 0x236, 0x231, 0x3, 0x2, 0x2, 0x2, 0x236, 0x232, 
    0x3, 0x2, 0x2, 0x2, 0x236, 0x233, 0x3, 0x2, 0x2, 0x2, 0x237, 0x47, 0x3, 
    0x2, 0x2, 0x2, 0x238, 0x239, 0x7, 0x34, 0x2, 0x2, 0x239, 0x23a, 0x5, 
    0xd6, 0x6c, 0x2, 0x23a, 0x23e, 0x5, 0x44, 0x23, 0x2, 0x23b, 0x23d, 0x5, 
    0x4a, 0x26, 0x2, 0x23c, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x23d, 0x240, 0x3, 
    0x2, 0x2, 0x2, 0x23e, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x23f, 0x3, 
    0x2, 0x2, 0x2, 0x23f, 0x242, 0x3, 0x2, 0x2, 0x2, 0x240, 0x23e, 0x3, 
    0x2, 0x2, 0x2, 0x241, 0x243, 0x5, 0x4c, 0x27, 0x2, 0x242, 0x241, 0x3, 
    0x2, 0x2, 0x2, 0x242, 0x243, 0x3, 0x2, 0x2, 0x2, 0x243, 0x49, 0x3, 0x2, 
    0x2, 0x2, 0x244, 0x245, 0x7, 0x35, 0x2, 0x2, 0x245, 0x246, 0x5, 0xd6, 
    0x6c, 0x2, 0x246, 0x247, 0x5, 0x44, 0x23, 0x2, 0x247, 0x4b, 0x3, 0x2, 
    0x2, 0x2, 0x248, 0x249, 0x7, 0x36, 0x2, 0x2, 0x249, 0x24a, 0x5, 0x44, 
    0x23, 0x2, 0x24a, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x24c, 0x9, 0x5, 
    0x2, 0x2, 0x24c, 0x24d, 0x5, 0xd6, 0x6c, 0x2, 0x24d, 0x25e, 0x7, 0x2f, 
    0x2, 0x2, 0x24e, 0x250, 0x5, 0x50, 0x29, 0x2, 0x24f, 0x24e, 0x3, 0x2, 
    0x2, 0x2, 0x24f, 0x250, 0x3, 0x2, 0x2, 0x2, 0x250, 0x254, 0x3, 0x2, 
    0x2, 0x2, 0x251, 0x253, 0x5, 0x52, 0x2a, 0x2, 0x252, 0x251, 0x3, 0x2, 
    0x2, 0x2, 0x253, 0x256, 0x3, 0x2, 0x2, 0x2, 0x254, 0x252, 0x3, 0x2, 
    0x2, 0x2, 0x254, 0x255, 0x3, 0x2, 0x2, 0x2, 0x255, 0x25f, 0x3, 0x2, 
    0x2, 0x2, 0x256, 0x254, 0x3, 0x2, 0x2, 0x2, 0x257, 0x259, 0x5, 0x52, 
    0x2a, 0x2, 0x258, 0x257, 0x3, 0x2, 0x2, 0x2, 0x259, 0x25a, 0x3, 0x2, 
    0x2, 0x2, 0x25a, 0x258, 0x3, 0x2, 0x2, 0x2, 0x25a, 0x25b, 0x3, 0x2, 
    0x2, 0x2, 0x25b, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x25c, 0x25d, 0x5, 0x50, 
    0x29, 0x2, 0x25d, 0x25f, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x24f, 0x3, 0x2, 
    0x2, 0x2, 0x25e, 0x258, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x260, 0x3, 0x2, 
    0x2, 0x2, 0x260, 0x261, 0x7, 0x30, 0x2, 0x2, 0x261, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0x262, 0x263, 0x7, 0x3a, 0x2, 0x2, 0x263, 0x264, 0x5, 0x44, 
    0x23, 0x2, 0x264, 0x51, 0x3, 0x2, 0x2, 0x2, 0x265, 0x266, 0x5, 0xc6, 
    0x64, 0x2, 0x266, 0x267, 0x5, 0x44, 0x23, 0x2, 0x267, 0x53, 0x3, 0x2, 
    0x2, 0x2, 0x268, 0x269, 0x7, 0x3b, 0x2, 0x2, 0x269, 0x26a, 0x5, 0xc0, 
    0x61, 0x2, 0x26a, 0x26b, 0x7, 0x32, 0x2, 0x2, 0x26b, 0x26c, 0x5, 0xd6, 
    0x6c, 0x2, 0x26c, 0x26d, 0x5, 0x44, 0x23, 0x2, 0x26d, 0x55, 0x3, 0x2, 
    0x2, 0x2, 0x26e, 0x26f, 0x7, 0x3c, 0x2, 0x2, 0x26f, 0x270, 0x5, 0xd6, 
    0x6c, 0x2, 0x270, 0x271, 0x5, 0x44, 0x23, 0x2, 0x271, 0x57, 0x3, 0x2, 
    0x2, 0x2, 0x272, 0x273, 0x5, 0xd6, 0x6c, 0x2, 0x273, 0x274, 0x7, 0xc, 
    0x2, 0x2, 0x274, 0x275, 0x5, 0xd6, 0x6c, 0x2, 0x275, 0x276, 0x7, 0x31, 
    0x2, 0x2, 0x276, 0x59, 0x3, 0x2, 0x2, 0x2, 0x277, 0x278, 0x5, 0xd6, 
    0x6c, 0x2, 0x278, 0x279, 0x7, 0xd, 0x2, 0x2, 0x279, 0x27a, 0x5, 0xd6, 
    0x6c, 0x2, 0x27a, 0x27b, 0x7, 0x31, 0x2, 0x2, 0x27b, 0x5b, 0x3, 0x2, 
    0x2, 0x2, 0x27c, 0x27d, 0x5, 0xc2, 0x62, 0x2, 0x27d, 0x27e, 0x7, 0x32, 
    0x2, 0x2, 0x27e, 0x27f, 0x7, 0x4f, 0x2, 0x2, 0x27f, 0x282, 0x5, 0xcc, 
    0x67, 0x2, 0x280, 0x281, 0x7, 0xd, 0x2, 0x2, 0x281, 0x283, 0x5, 0xc6, 
    0x64, 0x2, 0x282, 0x280, 0x3, 0x2, 0x2, 0x2, 0x282, 0x283, 0x3, 0x2, 
    0x2, 0x2, 0x283, 0x284, 0x3, 0x2, 0x2, 0x2, 0x284, 0x285, 0x7, 0x31, 
    0x2, 0x2, 0x285, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x286, 0x287, 0x5, 0xc2, 
    0x62, 0x2, 0x287, 0x288, 0x7, 0x32, 0x2, 0x2, 0x288, 0x28b, 0x5, 0xcc, 
    0x67, 0x2, 0x289, 0x28a, 0x7, 0xd, 0x2, 0x2, 0x28a, 0x28c, 0x5, 0xc6, 
    0x64, 0x2, 0x28b, 0x289, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x28c, 0x3, 0x2, 
    0x2, 0x2, 0x28c, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x28e, 0x7, 0x31, 
    0x2, 0x2, 0x28e, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x28f, 0x290, 0x5, 0xc2, 
    0x62, 0x2, 0x290, 0x291, 0x7, 0x32, 0x2, 0x2, 0x291, 0x292, 0x7, 0x51, 
    0x2, 0x2, 0x292, 0x293, 0x5, 0xcc, 0x67, 0x2, 0x293, 0x294, 0x7, 0xd, 
    0x2, 0x2, 0x294, 0x295, 0x5, 0xc6, 0x64, 0x2, 0x295, 0x296, 0x7, 0x31, 
    0x2, 0x2, 0x296, 0x61, 0x3, 0x2, 0x2, 0x2, 0x297, 0x29b, 0x5, 0x64, 
    0x33, 0x2, 0x298, 0x29b, 0x5, 0x66, 0x34, 0x2, 0x299, 0x29b, 0x5, 0x7c, 
    0x3f, 0x2, 0x29a, 0x297, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x298, 0x3, 0x2, 
    0x2, 0x2, 0x29a, 0x299, 0x3, 0x2, 0x2, 0x2, 0x29b, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x29c, 0x29d, 0x7, 0x7a, 0x2, 0x2, 0x29d, 0x2a0, 0x5, 0xc0, 0x61, 
    0x2, 0x29e, 0x29f, 0x7, 0x32, 0x2, 0x2, 0x29f, 0x2a1, 0x5, 0xcc, 0x67, 
    0x2, 0x2a0, 0x29e, 0x3, 0x2, 0x2, 0x2, 0x2a0, 0x2a1, 0x3, 0x2, 0x2, 
    0x2, 0x2a1, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x2a3, 0x7, 0x2f, 0x2, 
    0x2, 0x2a3, 0x2a5, 0x5, 0xc2, 0x62, 0x2, 0x2a4, 0x2a6, 0x7, 0x33, 0x2, 
    0x2, 0x2a5, 0x2a4, 0x3, 0x2, 0x2, 0x2, 0x2a5, 0x2a6, 0x3, 0x2, 0x2, 
    0x2, 0x2a6, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2a7, 0x2a8, 0x7, 0x30, 0x2, 
    0x2, 0x2a8, 0x65, 0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2ab, 0x7, 0x82, 0x2, 
    0x2, 0x2aa, 0x2a9, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2ab, 0x3, 0x2, 0x2, 
    0x2, 0x2ab, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2ac, 0x2b1, 0x7, 0x7b, 0x2, 
    0x2, 0x2ad, 0x2af, 0x7, 0x52, 0x2, 0x2, 0x2ae, 0x2ad, 0x3, 0x2, 0x2, 
    0x2, 0x2ae, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x2b0, 0x3, 0x2, 0x2, 
    0x2, 0x2b0, 0x2b2, 0x7, 0x7c, 0x2, 0x2, 0x2b1, 0x2ae, 0x3, 0x2, 0x2, 
    0x2, 0x2b1, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2b3, 0x3, 0x2, 0x2, 
    0x2, 0x2b3, 0x2b4, 0x5, 0xc0, 0x61, 0x2, 0x2b4, 0x2b6, 0x5, 0xa, 0x6, 
    0x2, 0x2b5, 0x2b7, 0x5, 0x68, 0x35, 0x2, 0x2b6, 0x2b5, 0x3, 0x2, 0x2, 
    0x2, 0x2b6, 0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2b8, 0x3, 0x2, 0x2, 
    0x2, 0x2b8, 0x2bc, 0x7, 0x2f, 0x2, 0x2, 0x2b9, 0x2bb, 0x5, 0x6a, 0x36, 
    0x2, 0x2ba, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2bb, 0x2be, 0x3, 0x2, 0x2, 
    0x2, 0x2bc, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2bd, 0x3, 0x2, 0x2, 
    0x2, 0x2bd, 0x2bf, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2bc, 0x3, 0x2, 0x2, 
    0x2, 0x2bf, 0x2c0, 0x7, 0x30, 0x2, 0x2, 0x2c0, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x2c1, 0x2c2, 0x7, 0x7e, 0x2, 0x2, 0x2c2, 0x2c3, 0x5, 0xc8, 0x65, 
    0x2, 0x2c3, 0x69, 0x3, 0x2, 0x2, 0x2, 0x2c4, 0x2c7, 0x5, 0x6c, 0x37, 
    0x2, 0x2c5, 0x2c7, 0x5, 0x6e, 0x38, 0x2, 0x2c6, 0x2c4, 0x3, 0x2, 0x2, 
    0x2, 0x2c6, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0x2c7, 0x6b, 0x3, 0x2, 0x2, 0x2, 
    0x2c8, 0x2ca, 0x5, 0x74, 0x3b, 0x2, 0x2c9, 0x2c8, 0x3, 0x2, 0x2, 0x2, 
    0x2c9, 0x2ca, 0x3, 0x2, 0x2, 0x2, 0x2ca, 0x2cc, 0x3, 0x2, 0x2, 0x2, 
    0x2cb, 0x2cd, 0x7, 0x83, 0x2, 0x2, 0x2cc, 0x2cb, 0x3, 0x2, 0x2, 0x2, 
    0x2cc, 0x2cd, 0x3, 0x2, 0x2, 0x2, 0x2cd, 0x2ce, 0x3, 0x2, 0x2, 0x2, 
    0x2ce, 0x2cf, 0x5, 0x5e, 0x30, 0x2, 0x2cf, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x2d0, 0x2d5, 0x5, 0x70, 0x39, 0x2, 0x2d1, 0x2d5, 0x5, 0x72, 0x3a, 0x2, 
    0x2d2, 0x2d5, 0x5, 0x76, 0x3c, 0x2, 0x2d3, 0x2d5, 0x5, 0xca, 0x66, 0x2, 
    0x2d4, 0x2d0, 0x3, 0x2, 0x2, 0x2, 0x2d4, 0x2d1, 0x3, 0x2, 0x2, 0x2, 
    0x2d4, 0x2d2, 0x3, 0x2, 0x2, 0x2, 0x2d4, 0x2d3, 0x3, 0x2, 0x2, 0x2, 
    0x2d5, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d8, 0x5, 0x74, 0x3b, 0x2, 
    0x2d7, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2d8, 0x3, 0x2, 0x2, 0x2, 
    0x2d8, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2da, 0x5, 0x62, 0x32, 0x2, 
    0x2da, 0x71, 0x3, 0x2, 0x2, 0x2, 0x2db, 0x2dd, 0x5, 0x74, 0x3b, 0x2, 
    0x2dc, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x2dc, 0x2dd, 0x3, 0x2, 0x2, 0x2, 
    0x2dd, 0x2df, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2e0, 0x7, 0x83, 0x2, 0x2, 
    0x2df, 0x2de, 0x3, 0x2, 0x2, 0x2, 0x2df, 0x2e0, 0x3, 0x2, 0x2, 0x2, 
    0x2e0, 0x2e3, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2e4, 0x5, 0xb8, 0x5d, 0x2, 
    0x2e2, 0x2e4, 0x5, 0x60, 0x31, 0x2, 0x2e3, 0x2e1, 0x3, 0x2, 0x2, 0x2, 
    0x2e3, 0x2e2, 0x3, 0x2, 0x2, 0x2, 0x2e4, 0x73, 0x3, 0x2, 0x2, 0x2, 0x2e5, 
    0x2e6, 0x9, 0x6, 0x2, 0x2, 0x2e6, 0x75, 0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2ea, 
    0x5, 0x78, 0x3d, 0x2, 0x2e8, 0x2ea, 0x5, 0x7a, 0x3e, 0x2, 0x2e9, 0x2e7, 
    0x3, 0x2, 0x2, 0x2, 0x2e9, 0x2e8, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x77, 0x3, 
    0x2, 0x2, 0x2, 0x2eb, 0x2ed, 0x5, 0x74, 0x3b, 0x2, 0x2ec, 0x2eb, 0x3, 
    0x2, 0x2, 0x2, 0x2ec, 0x2ed, 0x3, 0x2, 0x2, 0x2, 0x2ed, 0x2ef, 0x3, 
    0x2, 0x2, 0x2, 0x2ee, 0x2f0, 0x9, 0x7, 0x2, 0x2, 0x2ef, 0x2ee, 0x3, 
    0x2, 0x2, 0x2, 0x2ef, 0x2f0, 0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2f2, 0x3, 
    0x2, 0x2, 0x2, 0x2f1, 0x2f3, 0x7, 0x51, 0x2, 0x2, 0x2f2, 0x2f1, 0x3, 
    0x2, 0x2, 0x2, 0x2f2, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f4, 0x3, 
    0x2, 0x2, 0x2, 0x2f4, 0x2f5, 0x5, 0x7e, 0x40, 0x2, 0x2f5, 0x79, 0x3, 
    0x2, 0x2, 0x2, 0x2f6, 0x2f8, 0x5, 0x74, 0x3b, 0x2, 0x2f7, 0x2f6, 0x3, 
    0x2, 0x2, 0x2, 0x2f7, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2f9, 0x3, 
    0x2, 0x2, 0x2, 0x2f9, 0x2fb, 0x7, 0x80, 0x2, 0x2, 0x2fa, 0x2fc, 0x7, 
    0x51, 0x2, 0x2, 0x2fb, 0x2fa, 0x3, 0x2, 0x2, 0x2, 0x2fb, 0x2fc, 0x3, 
    0x2, 0x2, 0x2, 0x2fc, 0x300, 0x3, 0x2, 0x2, 0x2, 0x2fd, 0x301, 0x5, 
    0x82, 0x42, 0x2, 0x2fe, 0x301, 0x5, 0x9a, 0x4e, 0x2, 0x2ff, 0x301, 0x5, 
    0xb2, 0x5a, 0x2, 0x300, 0x2fd, 0x3, 0x2, 0x2, 0x2, 0x300, 0x2fe, 0x3, 
    0x2, 0x2, 0x2, 0x300, 0x2ff, 0x3, 0x2, 0x2, 0x2, 0x301, 0x302, 0x3, 
    0x2, 0x2, 0x2, 0x302, 0x303, 0x7, 0x31, 0x2, 0x2, 0x303, 0x7b, 0x3, 
    0x2, 0x2, 0x2, 0x304, 0x306, 0x7, 0x82, 0x2, 0x2, 0x305, 0x304, 0x3, 
    0x2, 0x2, 0x2, 0x305, 0x306, 0x3, 0x2, 0x2, 0x2, 0x306, 0x307, 0x3, 
    0x2, 0x2, 0x2, 0x307, 0x308, 0x7, 0x7d, 0x2, 0x2, 0x308, 0x309, 0x5, 
    0xc0, 0x61, 0x2, 0x309, 0x30b, 0x5, 0xa, 0x6, 0x2, 0x30a, 0x30c, 0x5, 
    0x68, 0x35, 0x2, 0x30b, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x30c, 0x3, 
    0x2, 0x2, 0x2, 0x30c, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x30d, 0x311, 0x7, 
    0x2f, 0x2, 0x2, 0x30e, 0x310, 0x5, 0x6e, 0x38, 0x2, 0x30f, 0x30e, 0x3, 
    0x2, 0x2, 0x2, 0x310, 0x313, 0x3, 0x2, 0x2, 0x2, 0x311, 0x30f, 0x3, 
    0x2, 0x2, 0x2, 0x311, 0x312, 0x3, 0x2, 0x2, 0x2, 0x312, 0x314, 0x3, 
    0x2, 0x2, 0x2, 0x313, 0x311, 0x3, 0x2, 0x2, 0x2, 0x314, 0x315, 0x7, 
    0x30, 0x2, 0x2, 0x315, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x316, 0x31a, 0x5, 
    0x80, 0x41, 0x2, 0x317, 0x31a, 0x5, 0x98, 0x4d, 0x2, 0x318, 0x31a, 0x5, 
    0xb0, 0x59, 0x2, 0x319, 0x316, 0x3, 0x2, 0x2, 0x2, 0x319, 0x317, 0x3, 
    0x2, 0x2, 0x2, 0x319, 0x318, 0x3, 0x2, 0x2, 0x2, 0x31a, 0x7f, 0x3, 0x2, 
    0x2, 0x2, 0x31b, 0x31c, 0x5, 0x82, 0x42, 0x2, 0x31c, 0x31d, 0x5, 0x84, 
    0x43, 0x2, 0x31d, 0x81, 0x3, 0x2, 0x2, 0x2, 0x31e, 0x31f, 0x7, 0x4b, 
    0x2, 0x2, 0x31f, 0x321, 0x5, 0xc0, 0x61, 0x2, 0x320, 0x322, 0x5, 0xa, 
    0x6, 0x2, 0x321, 0x320, 0x3, 0x2, 0x2, 0x2, 0x321, 0x322, 0x3, 0x2, 
    0x2, 0x2, 0x322, 0x323, 0x3, 0x2, 0x2, 0x2, 0x323, 0x324, 0x5, 0xe, 
    0x8, 0x2, 0x324, 0x325, 0x7, 0x32, 0x2, 0x2, 0x325, 0x326, 0x5, 0xcc, 
    0x67, 0x2, 0x326, 0x83, 0x3, 0x2, 0x2, 0x2, 0x327, 0x32b, 0x7, 0x2f, 
    0x2, 0x2, 0x328, 0x32a, 0x5, 0x86, 0x44, 0x2, 0x329, 0x328, 0x3, 0x2, 
    0x2, 0x2, 0x32a, 0x32d, 0x3, 0x2, 0x2, 0x2, 0x32b, 0x329, 0x3, 0x2, 
    0x2, 0x2, 0x32b, 0x32c, 0x3, 0x2, 0x2, 0x2, 0x32c, 0x32e, 0x3, 0x2, 
    0x2, 0x2, 0x32d, 0x32b, 0x3, 0x2, 0x2, 0x2, 0x32e, 0x32f, 0x7, 0x30, 
    0x2, 0x2, 0x32f, 0x85, 0x3, 0x2, 0x2, 0x2, 0x330, 0x332, 0x7, 0x5f, 
    0x2, 0x2, 0x331, 0x330, 0x3, 0x2, 0x2, 0x2, 0x331, 0x332, 0x3, 0x2, 
    0x2, 0x2, 0x332, 0x333, 0x3, 0x2, 0x2, 0x2, 0x333, 0x334, 0x5, 0xd6, 
    0x6c, 0x2, 0x334, 0x335, 0x7, 0x31, 0x2, 0x2, 0x335, 0x341, 0x3, 0x2, 
    0x2, 0x2, 0x336, 0x341, 0x5, 0x84, 0x43, 0x2, 0x337, 0x341, 0x5, 0xb8, 
    0x5d, 0x2, 0x338, 0x341, 0x5, 0x5e, 0x30, 0x2, 0x339, 0x341, 0x5, 0x60, 
    0x31, 0x2, 0x33a, 0x341, 0x5, 0x62, 0x32, 0x2, 0x33b, 0x341, 0x5, 0x5a, 
    0x2e, 0x2, 0x33c, 0x341, 0x5, 0x88, 0x45, 0x2, 0x33d, 0x341, 0x5, 0x8e, 
    0x48, 0x2, 0x33e, 0x341, 0x5, 0x94, 0x4b, 0x2, 0x33f, 0x341, 0x5, 0x96, 
    0x4c, 0x2, 0x340, 0x331, 0x3, 0x2, 0x2, 0x2, 0x340, 0x336, 0x3, 0x2, 
    0x2, 0x2, 0x340, 0x337, 0x3, 0x2, 0x2, 0x2, 0x340, 0x338, 0x3, 0x2, 
    0x2, 0x2, 0x340, 0x339, 0x3, 0x2, 0x2, 0x2, 0x340, 0x33a, 0x3, 0x2, 
    0x2, 0x2, 0x340, 0x33b, 0x3, 0x2, 0x2, 0x2, 0x340, 0x33c, 0x3, 0x2, 
    0x2, 0x2, 0x340, 0x33d, 0x3, 0x2, 0x2, 0x2, 0x340, 0x33e, 0x3, 0x2, 
    0x2, 0x2, 0x340, 0x33f, 0x3, 0x2, 0x2, 0x2, 0x341, 0x87, 0x3, 0x2, 0x2, 
    0x2, 0x342, 0x343, 0x7, 0x34, 0x2, 0x2, 0x343, 0x344, 0x5, 0xd6, 0x6c, 
    0x2, 0x344, 0x348, 0x5, 0x84, 0x43, 0x2, 0x345, 0x347, 0x5, 0x8a, 0x46, 
    0x2, 0x346, 0x345, 0x3, 0x2, 0x2, 0x2, 0x347, 0x34a, 0x3, 0x2, 0x2, 
    0x2, 0x348, 0x346, 0x3, 0x2, 0x2, 0x2, 0x348, 0x349, 0x3, 0x2, 0x2, 
    0x2, 0x349, 0x34c, 0x3, 0x2, 0x2, 0x2, 0x34a, 0x348, 0x3, 0x2, 0x2, 
    0x2, 0x34b, 0x34d, 0x5, 0x8c, 0x47, 0x2, 0x34c, 0x34b, 0x3, 0x2, 0x2, 
    0x2, 0x34c, 0x34d, 0x3, 0x2, 0x2, 0x2, 0x34d, 0x89, 0x3, 0x2, 0x2, 0x2, 
    0x34e, 0x34f, 0x7, 0x35, 0x2, 0x2, 0x34f, 0x350, 0x5, 0xd6, 0x6c, 0x2, 
    0x350, 0x351, 0x5, 0x84, 0x43, 0x2, 0x351, 0x8b, 0x3, 0x2, 0x2, 0x2, 
    0x352, 0x353, 0x7, 0x36, 0x2, 0x2, 0x353, 0x354, 0x5, 0x84, 0x43, 0x2, 
    0x354, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x355, 0x356, 0x9, 0x5, 0x2, 0x2, 0x356, 
    0x357, 0x5, 0xd6, 0x6c, 0x2, 0x357, 0x368, 0x7, 0x2f, 0x2, 0x2, 0x358, 
    0x35a, 0x5, 0x90, 0x49, 0x2, 0x359, 0x358, 0x3, 0x2, 0x2, 0x2, 0x359, 
    0x35a, 0x3, 0x2, 0x2, 0x2, 0x35a, 0x35e, 0x3, 0x2, 0x2, 0x2, 0x35b, 
    0x35d, 0x5, 0x92, 0x4a, 0x2, 0x35c, 0x35b, 0x3, 0x2, 0x2, 0x2, 0x35d, 
    0x360, 0x3, 0x2, 0x2, 0x2, 0x35e, 0x35c, 0x3, 0x2, 0x2, 0x2, 0x35e, 
    0x35f, 0x3, 0x2, 0x2, 0x2, 0x35f, 0x369, 0x3, 0x2, 0x2, 0x2, 0x360, 
    0x35e, 0x3, 0x2, 0x2, 0x2, 0x361, 0x363, 0x5, 0x92, 0x4a, 0x2, 0x362, 
    0x361, 0x3, 0x2, 0x2, 0x2, 0x363, 0x364, 0x3, 0x2, 0x2, 0x2, 0x364, 
    0x362, 0x3, 0x2, 0x2, 0x2, 0x364, 0x365, 0x3, 0x2, 0x2, 0x2, 0x365, 
    0x366, 0x3, 0x2, 0x2, 0x2, 0x366, 0x367, 0x5, 0x90, 0x49, 0x2, 0x367, 
    0x369, 0x3, 0x2, 0x2, 0x2, 0x368, 0x359, 0x3, 0x2, 0x2, 0x2, 0x368, 
    0x362, 0x3, 0x2, 0x2, 0x2, 0x369, 0x36a, 0x3, 0x2, 0x2, 0x2, 0x36a, 
    0x36b, 0x7, 0x30, 0x2, 0x2, 0x36b, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x36c, 
    0x36d, 0x7, 0x3a, 0x2, 0x2, 0x36d, 0x36e, 0x5, 0x84, 0x43, 0x2, 0x36e, 
    0x91, 0x3, 0x2, 0x2, 0x2, 0x36f, 0x370, 0x5, 0xc6, 0x64, 0x2, 0x370, 
    0x371, 0x5, 0x84, 0x43, 0x2, 0x371, 0x93, 0x3, 0x2, 0x2, 0x2, 0x372, 
    0x373, 0x7, 0x3b, 0x2, 0x2, 0x373, 0x374, 0x5, 0xc0, 0x61, 0x2, 0x374, 
    0x375, 0x7, 0x32, 0x2, 0x2, 0x375, 0x376, 0x5, 0xd6, 0x6c, 0x2, 0x376, 
    0x377, 0x5, 0x84, 0x43, 0x2, 0x377, 0x95, 0x3, 0x2, 0x2, 0x2, 0x378, 
    0x379, 0x7, 0x3c, 0x2, 0x2, 0x379, 0x37a, 0x5, 0xd6, 0x6c, 0x2, 0x37a, 
    0x37b, 0x5, 0x84, 0x43, 0x2, 0x37b, 0x97, 0x3, 0x2, 0x2, 0x2, 0x37c, 
    0x37d, 0x5, 0x9a, 0x4e, 0x2, 0x37d, 0x37e, 0x5, 0x9c, 0x4f, 0x2, 0x37e, 
    0x99, 0x3, 0x2, 0x2, 0x2, 0x37f, 0x380, 0x7, 0x4c, 0x2, 0x2, 0x380, 
    0x382, 0x5, 0xc0, 0x61, 0x2, 0x381, 0x383, 0x5, 0xa, 0x6, 0x2, 0x382, 
    0x381, 0x3, 0x2, 0x2, 0x2, 0x382, 0x383, 0x3, 0x2, 0x2, 0x2, 0x383, 
    0x384, 0x3, 0x2, 0x2, 0x2, 0x384, 0x385, 0x5, 0xe, 0x8, 0x2, 0x385, 
    0x9b, 0x3, 0x2, 0x2, 0x2, 0x386, 0x38a, 0x7, 0x2f, 0x2, 0x2, 0x387, 
    0x389, 0x5, 0x9e, 0x50, 0x2, 0x388, 0x387, 0x3, 0x2, 0x2, 0x2, 0x389, 
    0x38c, 0x3, 0x2, 0x2, 0x2, 0x38a, 0x388, 0x3, 0x2, 0x2, 0x2, 0x38a, 
    0x38b, 0x3, 0x2, 0x2, 0x2, 0x38b, 0x38d, 0x3, 0x2, 0x2, 0x2, 0x38c, 
    0x38a, 0x3, 0x2, 0x2, 0x2, 0x38d, 0x38e, 0x7, 0x30, 0x2, 0x2, 0x38e, 
    0x9d, 0x3, 0x2, 0x2, 0x2, 0x38f, 0x39e, 0x5, 0x9c, 0x4f, 0x2, 0x390, 
    0x39e, 0x5, 0xb8, 0x5d, 0x2, 0x391, 0x39e, 0x5, 0x5e, 0x30, 0x2, 0x392, 
    0x39e, 0x5, 0x60, 0x31, 0x2, 0x393, 0x39e, 0x5, 0x62, 0x32, 0x2, 0x394, 
    0x39e, 0x5, 0x5a, 0x2e, 0x2, 0x395, 0x39e, 0x5, 0x58, 0x2d, 0x2, 0x396, 
    0x39e, 0x5, 0xa0, 0x51, 0x2, 0x397, 0x39e, 0x5, 0xa6, 0x54, 0x2, 0x398, 
    0x39e, 0x5, 0xac, 0x57, 0x2, 0x399, 0x39e, 0x5, 0xae, 0x58, 0x2, 0x39a, 
    0x39b, 0x5, 0xd6, 0x6c, 0x2, 0x39b, 0x39c, 0x7, 0x31, 0x2, 0x2, 0x39c, 
    0x39e, 0x3, 0x2, 0x2, 0x2, 0x39d, 0x38f, 0x3, 0x2, 0x2, 0x2, 0x39d, 
    0x390, 0x3, 0x2, 0x2, 0x2, 0x39d, 0x391, 0x3, 0x2, 0x2, 0x2, 0x39d, 
    0x392, 0x3, 0x2, 0x2, 0x2, 0x39d, 0x393, 0x3, 0x2, 0x2, 0x2, 0x39d, 
    0x394, 0x3, 0x2, 0x2, 0x2, 0x39d, 0x395, 0x3, 0x2, 0x2, 0x2, 0x39d, 
    0x396, 0x3, 0x2, 0x2, 0x2, 0x39d, 0x397, 0x3, 0x2, 0x2, 0x2, 0x39d, 
    0x398, 0x3, 0x2, 0x2, 0x2, 0x39d, 0x399, 0x3, 0x2, 0x2, 0x2, 0x39d, 
    0x39a, 0x3, 0x2, 0x2, 0x2, 0x39e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x39f, 0x3a0, 
    0x7, 0x34, 0x2, 0x2, 0x3a0, 0x3a1, 0x5, 0xd6, 0x6c, 0x2, 0x3a1, 0x3a5, 
    0x5, 0x9c, 0x4f, 0x2, 0x3a2, 0x3a4, 0x5, 0xa2, 0x52, 0x2, 0x3a3, 0x3a2, 
    0x3, 0x2, 0x2, 0x2, 0x3a4, 0x3a7, 0x3, 0x2, 0x2, 0x2, 0x3a5, 0x3a3, 
    0x3, 0x2, 0x2, 0x2, 0x3a5, 0x3a6, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x3a9, 
    0x3, 0x2, 0x2, 0x2, 0x3a7, 0x3a5, 0x3, 0x2, 0x2, 0x2, 0x3a8, 0x3aa, 
    0x5, 0xa4, 0x53, 0x2, 0x3a9, 0x3a8, 0x3, 0x2, 0x2, 0x2, 0x3a9, 0x3aa, 
    0x3, 0x2, 0x2, 0x2, 0x3aa, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x3ab, 0x3ac, 0x7, 
    0x35, 0x2, 0x2, 0x3ac, 0x3ad, 0x5, 0xd6, 0x6c, 0x2, 0x3ad, 0x3ae, 0x5, 
    0x9c, 0x4f, 0x2, 0x3ae, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x3af, 0x3b0, 0x7, 
    0x36, 0x2, 0x2, 0x3b0, 0x3b1, 0x5, 0x9c, 0x4f, 0x2, 0x3b1, 0xa5, 0x3, 
    0x2, 0x2, 0x2, 0x3b2, 0x3b3, 0x9, 0x5, 0x2, 0x2, 0x3b3, 0x3b4, 0x5, 
    0xd6, 0x6c, 0x2, 0x3b4, 0x3c5, 0x7, 0x2f, 0x2, 0x2, 0x3b5, 0x3b7, 0x5, 
    0xa8, 0x55, 0x2, 0x3b6, 0x3b5, 0x3, 0x2, 0x2, 0x2, 0x3b6, 0x3b7, 0x3, 
    0x2, 0x2, 0x2, 0x3b7, 0x3bb, 0x3, 0x2, 0x2, 0x2, 0x3b8, 0x3ba, 0x5, 
    0xaa, 0x56, 0x2, 0x3b9, 0x3b8, 0x3, 0x2, 0x2, 0x2, 0x3ba, 0x3bd, 0x3, 
    0x2, 0x2, 0x2, 0x3bb, 0x3b9, 0x3, 0x2, 0x2, 0x2, 0x3bb, 0x3bc, 0x3, 
    0x2, 0x2, 0x2, 0x3bc, 0x3c6, 0x3, 0x2, 0x2, 0x2, 0x3bd, 0x3bb, 0x3, 
    0x2, 0x2, 0x2, 0x3be, 0x3c0, 0x5, 0xaa, 0x56, 0x2, 0x3bf, 0x3be, 0x3, 
    0x2, 0x2, 0x2, 0x3c0, 0x3c1, 0x3, 0x2, 0x2, 0x2, 0x3c1, 0x3bf, 0x3, 
    0x2, 0x2, 0x2, 0x3c1, 0x3c2, 0x3, 0x2, 0x2, 0x2, 0x3c2, 0x3c3, 0x3, 
    0x2, 0x2, 0x2, 0x3c3, 0x3c4, 0x5, 0xa8, 0x55, 0x2, 0x3c4, 0x3c6, 0x3, 
    0x2, 0x2, 0x2, 0x3c5, 0x3b6, 0x3, 0x2, 0x2, 0x2, 0x3c5, 0x3bf, 0x3, 
    0x2, 0x2, 0x2, 0x3c6, 0x3c7, 0x3, 0x2, 0x2, 0x2, 0x3c7, 0x3c8, 0x7, 
    0x30, 0x2, 0x2, 0x3c8, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x3c9, 0x3ca, 0x7, 
    0x3a, 0x2, 0x2, 0x3ca, 0x3cb, 0x5, 0x9c, 0x4f, 0x2, 0x3cb, 0xa9, 0x3, 
    0x2, 0x2, 0x2, 0x3cc, 0x3cd, 0x5, 0xc6, 0x64, 0x2, 0x3cd, 0x3ce, 0x5, 
    0x9c, 0x4f, 0x2, 0x3ce, 0xab, 0x3, 0x2, 0x2, 0x2, 0x3cf, 0x3d0, 0x7, 
    0x3b, 0x2, 0x2, 0x3d0, 0x3d1, 0x5, 0xc0, 0x61, 0x2, 0x3d1, 0x3d2, 0x7, 
    0x32, 0x2, 0x2, 0x3d2, 0x3d3, 0x5, 0xd6, 0x6c, 0x2, 0x3d3, 0x3d4, 0x5, 
    0x9c, 0x4f, 0x2, 0x3d4, 0xad, 0x3, 0x2, 0x2, 0x2, 0x3d5, 0x3d6, 0x7, 
    0x3c, 0x2, 0x2, 0x3d6, 0x3d7, 0x5, 0xd6, 0x6c, 0x2, 0x3d7, 0x3d8, 0x5, 
    0x9c, 0x4f, 0x2, 0x3d8, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x3d9, 0x3da, 0x5, 
    0xb2, 0x5a, 0x2, 0x3da, 0x3db, 0x5, 0x26, 0x14, 0x2, 0x3db, 0xb1, 0x3, 
    0x2, 0x2, 0x2, 0x3dc, 0x3dd, 0x7, 0x84, 0x2, 0x2, 0x3dd, 0x3df, 0x5, 
    0xc0, 0x61, 0x2, 0x3de, 0x3e0, 0x5, 0xa, 0x6, 0x2, 0x3df, 0x3de, 0x3, 
    0x2, 0x2, 0x2, 0x3df, 0x3e0, 0x3, 0x2, 0x2, 0x2, 0x3e0, 0x3e1, 0x3, 
    0x2, 0x2, 0x2, 0x3e1, 0x3e2, 0x5, 0xb4, 0x5b, 0x2, 0x3e2, 0xb3, 0x3, 
    0x2, 0x2, 0x2, 0x3e3, 0x3e4, 0x7, 0x2b, 0x2, 0x2, 0x3e4, 0x3e9, 0x5, 
    0xb6, 0x5c, 0x2, 0x3e5, 0x3e6, 0x7, 0x31, 0x2, 0x2, 0x3e6, 0x3e8, 0x5, 
    0xb6, 0x5c, 0x2, 0x3e7, 0x3e5, 0x3, 0x2, 0x2, 0x2, 0x3e8, 0x3eb, 0x3, 
    0x2, 0x2, 0x2, 0x3e9, 0x3e7, 0x3, 0x2, 0x2, 0x2, 0x3e9, 0x3ea, 0x3, 
    0x2, 0x2, 0x2, 0x3ea, 0x3ed, 0x3, 0x2, 0x2, 0x2, 0x3eb, 0x3e9, 0x3, 
    0x2, 0x2, 0x2, 0x3ec, 0x3ee, 0x7, 0x31, 0x2, 0x2, 0x3ed, 0x3ec, 0x3, 
    0x2, 0x2, 0x2, 0x3ed, 0x3ee, 0x3, 0x2, 0x2, 0x2, 0x3ee, 0x3ef, 0x3, 
    0x2, 0x2, 0x2, 0x3ef, 0x3f0, 0x7, 0x2c, 0x2, 0x2, 0x3f0, 0xb5, 0x3, 
    0x2, 0x2, 0x2, 0x3f1, 0x3f2, 0x5, 0xc2, 0x62, 0x2, 0x3f2, 0x3f4, 0x7, 
    0x32, 0x2, 0x2, 0x3f3, 0x3f5, 0x9, 0x8, 0x2, 0x2, 0x3f4, 0x3f3, 0x3, 
    0x2, 0x2, 0x2, 0x3f4, 0x3f5, 0x3, 0x2, 0x2, 0x2, 0x3f5, 0x3f6, 0x3, 
    0x2, 0x2, 0x2, 0x3f6, 0x3f7, 0x5, 0xcc, 0x67, 0x2, 0x3f7, 0xb7, 0x3, 
    0x2, 0x2, 0x2, 0x3f8, 0x3fc, 0x5, 0xba, 0x5e, 0x2, 0x3f9, 0x3fc, 0x5, 
    0xbc, 0x5f, 0x2, 0x3fa, 0x3fc, 0x5, 0xbe, 0x60, 0x2, 0x3fb, 0x3f8, 0x3, 
    0x2, 0x2, 0x2, 0x3fb, 0x3f9, 0x3, 0x2, 0x2, 0x2, 0x3fb, 0x3fa, 0x3, 
    0x2, 0x2, 0x2, 0x3fc, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x3fd, 0x3fe, 0x7, 0x79, 
    0x2, 0x2, 0x3fe, 0x3ff, 0x5, 0xc2, 0x62, 0x2, 0x3ff, 0x400, 0x7, 0x32, 
    0x2, 0x2, 0x400, 0x401, 0x5, 0xcc, 0x67, 0x2, 0x401, 0x402, 0x7, 0xd, 
    0x2, 0x2, 0x402, 0x403, 0x5, 0xc6, 0x64, 0x2, 0x403, 0x404, 0x7, 0x31, 
    0x2, 0x2, 0x404, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x405, 0x406, 0x7, 0x79, 
    0x2, 0x2, 0x406, 0x407, 0x5, 0xc2, 0x62, 0x2, 0x407, 0x408, 0x7, 0x32, 
    0x2, 0x2, 0x408, 0x409, 0x7, 0x77, 0x2, 0x2, 0x409, 0x40a, 0x7, 0xd, 
    0x2, 0x2, 0x40a, 0x40b, 0x5, 0xc8, 0x65, 0x2, 0x40b, 0x40c, 0x7, 0x31, 
    0x2, 0x2, 0x40c, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x40d, 0x40e, 0x7, 0x79, 
    0x2, 0x2, 0x40e, 0x40f, 0x5, 0xc2, 0x62, 0x2, 0x40f, 0x410, 0x7, 0x32, 
    0x2, 0x2, 0x410, 0x411, 0x7, 0x3f, 0x2, 0x2, 0x411, 0x412, 0x7, 0xd, 
    0x2, 0x2, 0x412, 0x413, 0x5, 0xc8, 0x65, 0x2, 0x413, 0x414, 0x7, 0x31, 
    0x2, 0x2, 0x414, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x415, 0x416, 0x7, 0x8d, 
    0x2, 0x2, 0x416, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x417, 0x41c, 0x5, 0xc0, 
    0x61, 0x2, 0x418, 0x419, 0x7, 0x33, 0x2, 0x2, 0x419, 0x41b, 0x5, 0xc0, 
    0x61, 0x2, 0x41a, 0x418, 0x3, 0x2, 0x2, 0x2, 0x41b, 0x41e, 0x3, 0x2, 
    0x2, 0x2, 0x41c, 0x41a, 0x3, 0x2, 0x2, 0x2, 0x41c, 0x41d, 0x3, 0x2, 
    0x2, 0x2, 0x41d, 0xc3, 0x3, 0x2, 0x2, 0x2, 0x41e, 0x41c, 0x3, 0x2, 0x2, 
    0x2, 0x41f, 0x424, 0x5, 0xc0, 0x61, 0x2, 0x420, 0x421, 0x7, 0x2a, 0x2, 
    0x2, 0x421, 0x423, 0x5, 0xc0, 0x61, 0x2, 0x422, 0x420, 0x3, 0x2, 0x2, 
    0x2, 0x423, 0x426, 0x3, 0x2, 0x2, 0x2, 0x424, 0x422, 0x3, 0x2, 0x2, 
    0x2, 0x424, 0x425, 0x3, 0x2, 0x2, 0x2, 0x425, 0xc5, 0x3, 0x2, 0x2, 0x2, 
    0x426, 0x424, 0x3, 0x2, 0x2, 0x2, 0x427, 0x42c, 0x5, 0xd6, 0x6c, 0x2, 
    0x428, 0x429, 0x7, 0x33, 0x2, 0x2, 0x429, 0x42b, 0x5, 0xd6, 0x6c, 0x2, 
    0x42a, 0x428, 0x3, 0x2, 0x2, 0x2, 0x42b, 0x42e, 0x3, 0x2, 0x2, 0x2, 
    0x42c, 0x42a, 0x3, 0x2, 0x2, 0x2, 0x42c, 0x42d, 0x3, 0x2, 0x2, 0x2, 
    0x42d, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x42e, 0x42c, 0x3, 0x2, 0x2, 0x2, 0x42f, 
    0x434, 0x5, 0xcc, 0x67, 0x2, 0x430, 0x431, 0x7, 0x33, 0x2, 0x2, 0x431, 
    0x433, 0x5, 0xcc, 0x67, 0x2, 0x432, 0x430, 0x3, 0x2, 0x2, 0x2, 0x433, 
    0x436, 0x3, 0x2, 0x2, 0x2, 0x434, 0x432, 0x3, 0x2, 0x2, 0x2, 0x434, 
    0x435, 0x3, 0x2, 0x2, 0x2, 0x435, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x436, 0x434, 
    0x3, 0x2, 0x2, 0x2, 0x437, 0x438, 0x7, 0x4d, 0x2, 0x2, 0x438, 0x43d, 
    0x5, 0xc4, 0x63, 0x2, 0x439, 0x43a, 0x7, 0x33, 0x2, 0x2, 0x43a, 0x43c, 
    0x5, 0xc4, 0x63, 0x2, 0x43b, 0x439, 0x3, 0x2, 0x2, 0x2, 0x43c, 0x43f, 
    0x3, 0x2, 0x2, 0x2, 0x43d, 0x43b, 0x3, 0x2, 0x2, 0x2, 0x43d, 0x43e, 
    0x3, 0x2, 0x2, 0x2, 0x43e, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x43f, 0x43d, 0x3, 
    0x2, 0x2, 0x2, 0x440, 0x44a, 0x5, 0xce, 0x68, 0x2, 0x441, 0x44a, 0x7, 
    0x86, 0x2, 0x2, 0x442, 0x44a, 0x7, 0x60, 0x2, 0x2, 0x443, 0x444, 0x7, 
    0x78, 0x2, 0x2, 0x444, 0x445, 0x7, 0x2b, 0x2, 0x2, 0x445, 0x446, 0x5, 
    0xd6, 0x6c, 0x2, 0x446, 0x447, 0x7, 0x2c, 0x2, 0x2, 0x447, 0x44a, 0x3, 
    0x2, 0x2, 0x2, 0x448, 0x44a, 0x5, 0xd4, 0x6b, 0x2, 0x449, 0x440, 0x3, 
    0x2, 0x2, 0x2, 0x449, 0x441, 0x3, 0x2, 0x2, 0x2, 0x449, 0x442, 0x3, 
    0x2, 0x2, 0x2, 0x449, 0x443, 0x3, 0x2, 0x2, 0x2, 0x449, 0x448, 0x3, 
    0x2, 0x2, 0x2, 0x44a, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x44b, 0x450, 0x5, 0xd0, 
    0x69, 0x2, 0x44c, 0x44d, 0x7, 0x2a, 0x2, 0x2, 0x44d, 0x44f, 0x5, 0xd0, 
    0x69, 0x2, 0x44e, 0x44c, 0x3, 0x2, 0x2, 0x2, 0x44f, 0x452, 0x3, 0x2, 
    0x2, 0x2, 0x450, 0x44e, 0x3, 0x2, 0x2, 0x2, 0x450, 0x451, 0x3, 0x2, 
    0x2, 0x2, 0x451, 0x456, 0x3, 0x2, 0x2, 0x2, 0x452, 0x450, 0x3, 0x2, 
    0x2, 0x2, 0x453, 0x455, 0x5, 0xd2, 0x6a, 0x2, 0x454, 0x453, 0x3, 0x2, 
    0x2, 0x2, 0x455, 0x458, 0x3, 0x2, 0x2, 0x2, 0x456, 0x454, 0x3, 0x2, 
    0x2, 0x2, 0x456, 0x457, 0x3, 0x2, 0x2, 0x2, 0x457, 0xcf, 0x3, 0x2, 0x2, 
    0x2, 0x458, 0x456, 0x3, 0x2, 0x2, 0x2, 0x459, 0x45b, 0x5, 0xc0, 0x61, 
    0x2, 0x45a, 0x45c, 0x5, 0x12, 0xa, 0x2, 0x45b, 0x45a, 0x3, 0x2, 0x2, 
    0x2, 0x45b, 0x45c, 0x3, 0x2, 0x2, 0x2, 0x45c, 0xd1, 0x3, 0x2, 0x2, 0x2, 
    0x45d, 0x460, 0x7, 0x2d, 0x2, 0x2, 0x45e, 0x461, 0x5, 0xd6, 0x6c, 0x2, 
    0x45f, 0x461, 0x5, 0xcc, 0x67, 0x2, 0x460, 0x45e, 0x3, 0x2, 0x2, 0x2, 
    0x460, 0x45f, 0x3, 0x2, 0x2, 0x2, 0x460, 0x461, 0x3, 0x2, 0x2, 0x2, 
    0x461, 0x462, 0x3, 0x2, 0x2, 0x2, 0x462, 0x463, 0x7, 0x2e, 0x2, 0x2, 
    0x463, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x464, 0x466, 0x7, 0x52, 0x2, 0x2, 
    0x465, 0x464, 0x3, 0x2, 0x2, 0x2, 0x465, 0x466, 0x3, 0x2, 0x2, 0x2, 
    0x466, 0x467, 0x3, 0x2, 0x2, 0x2, 0x467, 0x469, 0x7, 0x50, 0x2, 0x2, 
    0x468, 0x46a, 0x5, 0x12, 0xa, 0x2, 0x469, 0x468, 0x3, 0x2, 0x2, 0x2, 
    0x469, 0x46a, 0x3, 0x2, 0x2, 0x2, 0x46a, 0x47b, 0x3, 0x2, 0x2, 0x2, 
    0x46b, 0x47b, 0x7, 0x53, 0x2, 0x2, 0x46c, 0x47b, 0x7, 0x54, 0x2, 0x2, 
    0x46d, 0x47b, 0x7, 0x62, 0x2, 0x2, 0x46e, 0x47b, 0x7, 0x8a, 0x2, 0x2, 
    0x46f, 0x47b, 0x7, 0x55, 0x2, 0x2, 0x470, 0x47b, 0x7, 0x56, 0x2, 0x2, 
    0x471, 0x47b, 0x7, 0x57, 0x2, 0x2, 0x472, 0x47b, 0x7, 0x58, 0x2, 0x2, 
    0x473, 0x47b, 0x7, 0x59, 0x2, 0x2, 0x474, 0x47b, 0x7, 0x5a, 0x2, 0x2, 
    0x475, 0x47b, 0x7, 0x5b, 0x2, 0x2, 0x476, 0x47b, 0x7, 0x5c, 0x2, 0x2, 
    0x477, 0x47b, 0x7, 0x5d, 0x2, 0x2, 0x478, 0x47b, 0x7, 0x5e, 0x2, 0x2, 
    0x479, 0x47b, 0x7, 0x61, 0x2, 0x2, 0x47a, 0x465, 0x3, 0x2, 0x2, 0x2, 
    0x47a, 0x46b, 0x3, 0x2, 0x2, 0x2, 0x47a, 0x46c, 0x3, 0x2, 0x2, 0x2, 
    0x47a, 0x46d, 0x3, 0x2, 0x2, 0x2, 0x47a, 0x46e, 0x3, 0x2, 0x2, 0x2, 
    0x47a, 0x46f, 0x3, 0x2, 0x2, 0x2, 0x47a, 0x470, 0x3, 0x2, 0x2, 0x2, 
    0x47a, 0x471, 0x3, 0x2, 0x2, 0x2, 0x47a, 0x472, 0x3, 0x2, 0x2, 0x2, 
    0x47a, 0x473, 0x3, 0x2, 0x2, 0x2, 0x47a, 0x474, 0x3, 0x2, 0x2, 0x2, 
    0x47a, 0x475, 0x3, 0x2, 0x2, 0x2, 0x47a, 0x476, 0x3, 0x2, 0x2, 0x2, 
    0x47a, 0x477, 0x3, 0x2, 0x2, 0x2, 0x47a, 0x478, 0x3, 0x2, 0x2, 0x2, 
    0x47a, 0x479, 0x3, 0x2, 0x2, 0x2, 0x47b, 0x47f, 0x3, 0x2, 0x2, 0x2, 
    0x47c, 0x47e, 0x5, 0xd2, 0x6a, 0x2, 0x47d, 0x47c, 0x3, 0x2, 0x2, 0x2, 
    0x47e, 0x481, 0x3, 0x2, 0x2, 0x2, 0x47f, 0x47d, 0x3, 0x2, 0x2, 0x2, 
    0x47f, 0x480, 0x3, 0x2, 0x2, 0x2, 0x480, 0x484, 0x3, 0x2, 0x2, 0x2, 
    0x481, 0x47f, 0x3, 0x2, 0x2, 0x2, 0x482, 0x484, 0x7, 0x76, 0x2, 0x2, 
    0x483, 0x47a, 0x3, 0x2, 0x2, 0x2, 0x483, 0x482, 0x3, 0x2, 0x2, 0x2, 
    0x484, 0xd5, 0x3, 0x2, 0x2, 0x2, 0x485, 0x486, 0x7, 0x37, 0x2, 0x2, 
    0x486, 0x487, 0x7, 0x2b, 0x2, 0x2, 0x487, 0x488, 0x5, 0xd6, 0x6c, 0x2, 
    0x488, 0x489, 0x7, 0x33, 0x2, 0x2, 0x489, 0x48a, 0x5, 0xd6, 0x6c, 0x2, 
    0x48a, 0x48b, 0x7, 0x33, 0x2, 0x2, 0x48b, 0x48c, 0x5, 0xd6, 0x6c, 0x2, 
    0x48c, 0x48d, 0x7, 0x2c, 0x2, 0x2, 0x48d, 0x490, 0x3, 0x2, 0x2, 0x2, 
    0x48e, 0x490, 0x5, 0xd8, 0x6d, 0x2, 0x48f, 0x485, 0x3, 0x2, 0x2, 0x2, 
    0x48f, 0x48e, 0x3, 0x2, 0x2, 0x2, 0x490, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x491, 
    0x494, 0x5, 0xda, 0x6e, 0x2, 0x492, 0x493, 0x7, 0xe, 0x2, 0x2, 0x493, 
    0x495, 0x5, 0xd6, 0x6c, 0x2, 0x494, 0x492, 0x3, 0x2, 0x2, 0x2, 0x494, 
    0x495, 0x3, 0x2, 0x2, 0x2, 0x495, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x496, 0x499, 
    0x5, 0xdc, 0x6f, 0x2, 0x497, 0x498, 0x7, 0xf, 0x2, 0x2, 0x498, 0x49a, 
    0x5, 0xd6, 0x6c, 0x2, 0x499, 0x497, 0x3, 0x2, 0x2, 0x2, 0x499, 0x49a, 
    0x3, 0x2, 0x2, 0x2, 0x49a, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x49b, 0x49e, 0x5, 
    0xde, 0x70, 0x2, 0x49c, 0x49d, 0x9, 0x9, 0x2, 0x2, 0x49d, 0x49f, 0x5, 
    0xd6, 0x6c, 0x2, 0x49e, 0x49c, 0x3, 0x2, 0x2, 0x2, 0x49e, 0x49f, 0x3, 
    0x2, 0x2, 0x2, 0x49f, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x4a0, 0x4a3, 0x5, 0xe0, 
    0x71, 0x2, 0x4a1, 0x4a2, 0x9, 0xa, 0x2, 0x2, 0x4a2, 0x4a4, 0x5, 0xd6, 
    0x6c, 0x2, 0x4a3, 0x4a1, 0x3, 0x2, 0x2, 0x2, 0x4a3, 0x4a4, 0x3, 0x2, 
    0x2, 0x2, 0x4a4, 0xdf, 0x3, 0x2, 0x2, 0x2, 0x4a5, 0x4a8, 0x5, 0xe2, 
    0x72, 0x2, 0x4a6, 0x4a7, 0x9, 0xb, 0x2, 0x2, 0x4a7, 0x4a9, 0x5, 0xd6, 
    0x6c, 0x2, 0x4a8, 0x4a6, 0x3, 0x2, 0x2, 0x2, 0x4a8, 0x4a9, 0x3, 0x2, 
    0x2, 0x2, 0x4a9, 0xe1, 0x3, 0x2, 0x2, 0x2, 0x4aa, 0x4ad, 0x5, 0xe4, 
    0x73, 0x2, 0x4ab, 0x4ac, 0x9, 0xc, 0x2, 0x2, 0x4ac, 0x4ae, 0x5, 0xd6, 
    0x6c, 0x2, 0x4ad, 0x4ab, 0x3, 0x2, 0x2, 0x2, 0x4ad, 0x4ae, 0x3, 0x2, 
    0x2, 0x2, 0x4ae, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x4af, 0x4b2, 0x5, 0xe6, 
    0x74, 0x2, 0x4b0, 0x4b1, 0x9, 0xd, 0x2, 0x2, 0x4b1, 0x4b3, 0x5, 0xd6, 
    0x6c, 0x2, 0x4b2, 0x4b0, 0x3, 0x2, 0x2, 0x2, 0x4b2, 0x4b3, 0x3, 0x2, 
    0x2, 0x2, 0x4b3, 0xe5, 0x3, 0x2, 0x2, 0x2, 0x4b4, 0x4b7, 0x5, 0xe8, 
    0x75, 0x2, 0x4b5, 0x4b6, 0x9, 0xe, 0x2, 0x2, 0x4b6, 0x4b8, 0x5, 0xd6, 
    0x6c, 0x2, 0x4b7, 0x4b5, 0x3, 0x2, 0x2, 0x2, 0x4b7, 0x4b8, 0x3, 0x2, 
    0x2, 0x2, 0x4b8, 0xe7, 0x3, 0x2, 0x2, 0x2, 0x4b9, 0x4bc, 0x5, 0xea, 
    0x76, 0x2, 0x4ba, 0x4bb, 0x9, 0xf, 0x2, 0x2, 0x4bb, 0x4bd, 0x5, 0xd6, 
    0x6c, 0x2, 0x4bc, 0x4ba, 0x3, 0x2, 0x2, 0x2, 0x4bc, 0x4bd, 0x3, 0x2, 
    0x2, 0x2, 0x4bd, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x4be, 0x4c1, 0x5, 0xec, 
    0x77, 0x2, 0x4bf, 0x4c0, 0x9, 0x10, 0x2, 0x2, 0x4c0, 0x4c2, 0x5, 0xd6, 
    0x6c, 0x2, 0x4c1, 0x4bf, 0x3, 0x2, 0x2, 0x2, 0x4c1, 0x4c2, 0x3, 0x2, 
    0x2, 0x2, 0x4c2, 0xeb, 0x3, 0x2, 0x2, 0x2, 0x4c3, 0x4c4, 0x9, 0x11, 
    0x2, 0x2, 0x4c4, 0x4c7, 0x5, 0xd6, 0x6c, 0x2, 0x4c5, 0x4c7, 0x5, 0xee, 
    0x78, 0x2, 0x4c6, 0x4c3, 0x3, 0x2, 0x2, 0x2, 0x4c6, 0x4c5, 0x3, 0x2, 
    0x2, 0x2, 0x4c7, 0xed, 0x3, 0x2, 0x2, 0x2, 0x4c8, 0x4cb, 0x5, 0xf0, 
    0x79, 0x2, 0x4c9, 0x4cb, 0x5, 0xf6, 0x7c, 0x2, 0x4ca, 0x4c8, 0x3, 0x2, 
    0x2, 0x2, 0x4ca, 0x4c9, 0x3, 0x2, 0x2, 0x2, 0x4cb, 0xef, 0x3, 0x2, 0x2, 
    0x2, 0x4cc, 0x4d7, 0x5, 0xf2, 0x7a, 0x2, 0x4cd, 0x4d7, 0x5, 0xf4, 0x7b, 
    0x2, 0x4ce, 0x4d7, 0x5, 0xfc, 0x7f, 0x2, 0x4cf, 0x4d7, 0x5, 0xfe, 0x80, 
    0x2, 0x4d0, 0x4d7, 0x5, 0x100, 0x81, 0x2, 0x4d1, 0x4d7, 0x5, 0x106, 
    0x84, 0x2, 0x4d2, 0x4d3, 0x7, 0x2b, 0x2, 0x2, 0x4d3, 0x4d4, 0x5, 0xd6, 
    0x6c, 0x2, 0x4d4, 0x4d5, 0x7, 0x2c, 0x2, 0x2, 0x4d5, 0x4d7, 0x3, 0x2, 
    0x2, 0x2, 0x4d6, 0x4cc, 0x3, 0x2, 0x2, 0x2, 0x4d6, 0x4cd, 0x3, 0x2, 
    0x2, 0x2, 0x4d6, 0x4ce, 0x3, 0x2, 0x2, 0x2, 0x4d6, 0x4cf, 0x3, 0x2, 
    0x2, 0x2, 0x4d6, 0x4d0, 0x3, 0x2, 0x2, 0x2, 0x4d6, 0x4d1, 0x3, 0x2, 
    0x2, 0x2, 0x4d6, 0x4d2, 0x3, 0x2, 0x2, 0x2, 0x4d7, 0xf1, 0x3, 0x2, 0x2, 
    0x2, 0x4d8, 0x4ed, 0x7, 0x5, 0x2, 0x2, 0x4d9, 0x4ed, 0x7, 0x6, 0x2, 
    0x2, 0x4da, 0x4ed, 0x7, 0x7, 0x2, 0x2, 0x4db, 0x4ed, 0x7, 0x8, 0x2, 
    0x2, 0x4dc, 0x4ed, 0x7, 0x9, 0x2, 0x2, 0x4dd, 0x4ed, 0x7, 0xa, 0x2, 
    0x2, 0x4de, 0x4e3, 0x7, 0x63, 0x2, 0x2, 0x4df, 0x4e0, 0x7, 0x2b, 0x2, 
    0x2, 0x4e0, 0x4e1, 0x5, 0xd6, 0x6c, 0x2, 0x4e1, 0x4e2, 0x7, 0x2c, 0x2, 
    0x2, 0x4e2, 0x4e4, 0x3, 0x2, 0x2, 0x2, 0x4e3, 0x4df, 0x3, 0x2, 0x2, 
    0x2, 0x4e3, 0x4e4, 0x3, 0x2, 0x2, 0x2, 0x4e4, 0x4ed, 0x3, 0x2, 0x2, 
    0x2, 0x4e5, 0x4ea, 0x7, 0x64, 0x2, 0x2, 0x4e6, 0x4e7, 0x7, 0x2b, 0x2, 
    0x2, 0x4e7, 0x4e8, 0x5, 0xd6, 0x6c, 0x2, 0x4e8, 0x4e9, 0x7, 0x2c, 0x2, 
    0x2, 0x4e9, 0x4eb, 0x3, 0x2, 0x2, 0x2, 0x4ea, 0x4e6, 0x3, 0x2, 0x2, 
    0x2, 0x4ea, 0x4eb, 0x3, 0x2, 0x2, 0x2, 0x4eb, 0x4ed, 0x3, 0x2, 0x2, 
    0x2, 0x4ec, 0x4d8, 0x3, 0x2, 0x2, 0x2, 0x4ec, 0x4d9, 0x3, 0x2, 0x2, 
    0x2, 0x4ec, 0x4da, 0x3, 0x2, 0x2, 0x2, 0x4ec, 0x4db, 0x3, 0x2, 0x2, 
    0x2, 0x4ec, 0x4dc, 0x3, 0x2, 0x2, 0x2, 0x4ec, 0x4dd, 0x3, 0x2, 0x2, 
    0x2, 0x4ec, 0x4de, 0x3, 0x2, 0x2, 0x2, 0x4ec, 0x4e5, 0x3, 0x2, 0x2, 
    0x2, 0x4ed, 0xf3, 0x3, 0x2, 0x2, 0x2, 0x4ee, 0x4ef, 0x7, 0x65, 0x2, 
    0x2, 0x4ef, 0x4f0, 0x7, 0x2b, 0x2, 0x2, 0x4f0, 0x4f1, 0x5, 0xd6, 0x6c, 
    0x2, 0x4f1, 0x4f2, 0x7, 0x33, 0x2, 0x2, 0x4f2, 0x4f3, 0x5, 0xd6, 0x6c, 
    0x2, 0x4f3, 0x4f4, 0x7, 0x2c, 0x2, 0x2, 0x4f4, 0xf5, 0x3, 0x2, 0x2, 
    0x2, 0x4f5, 0x4f8, 0x5, 0xf8, 0x7d, 0x2, 0x4f6, 0x4f8, 0x5, 0xfa, 0x7e, 
    0x2, 0x4f7, 0x4f5, 0x3, 0x2, 0x2, 0x2, 0x4f7, 0x4f6, 0x3, 0x2, 0x2, 
    0x2, 0x4f8, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x4f9, 0x4fc, 0x5, 0xf0, 0x79, 
    0x2, 0x4fa, 0x4fc, 0x5, 0xfa, 0x7e, 0x2, 0x4fb, 0x4f9, 0x3, 0x2, 0x2, 
    0x2, 0x4fb, 0x4fa, 0x3, 0x2, 0x2, 0x2, 0x4fc, 0x4fd, 0x3, 0x2, 0x2, 
    0x2, 0x4fd, 0x4fe, 0x7, 0xb, 0x2, 0x2, 0x4fe, 0x4ff, 0x5, 0xd6, 0x6c, 
    0x2, 0x4ff, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x500, 0x501, 0x7, 0x62, 0x2, 
    0x2, 0x501, 0x502, 0x7, 0x2b, 0x2, 0x2, 0x502, 0x503, 0x5, 0xd6, 0x6c, 
    0x2, 0x503, 0x504, 0x7, 0x33, 0x2, 0x2, 0x504, 0x505, 0x5, 0xd6, 0x6c, 
    0x2, 0x505, 0x506, 0x7, 0x2c, 0x2, 0x2, 0x506, 0xfb, 0x3, 0x2, 0x2, 
    0x2, 0x507, 0x508, 0x7, 0x66, 0x2, 0x2, 0x508, 0x509, 0x7, 0x2b, 0x2, 
    0x2, 0x509, 0x50a, 0x5, 0xc6, 0x64, 0x2, 0x50a, 0x50b, 0x7, 0x2c, 0x2, 
    0x2, 0x50b, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x50c, 0x50d, 0x7, 0x67, 0x2, 
    0x2, 0x50d, 0x50e, 0x7, 0x2b, 0x2, 0x2, 0x50e, 0x50f, 0x5, 0xd6, 0x6c, 
    0x2, 0x50f, 0x510, 0x7, 0x33, 0x2, 0x2, 0x510, 0x511, 0x5, 0xd6, 0x6c, 
    0x2, 0x511, 0x512, 0x7, 0x2c, 0x2, 0x2, 0x512, 0xff, 0x3, 0x2, 0x2, 
    0x2, 0x513, 0x516, 0x5, 0x102, 0x82, 0x2, 0x514, 0x516, 0x5, 0x104, 
    0x83, 0x2, 0x515, 0x513, 0x3, 0x2, 0x2, 0x2, 0x515, 0x514, 0x3, 0x2, 
    0x2, 0x2, 0x516, 0x101, 0x3, 0x2, 0x2, 0x2, 0x517, 0x518, 0x9, 0x12, 
    0x2, 0x2, 0x518, 0x519, 0x7, 0x2b, 0x2, 0x2, 0x519, 0x51a, 0x5, 0xd6, 
    0x6c, 0x2, 0x51a, 0x51b, 0x7, 0x2c, 0x2, 0x2, 0x51b, 0x103, 0x3, 0x2, 
    0x2, 0x2, 0x51c, 0x51d, 0x7, 0x71, 0x2, 0x2, 0x51d, 0x51e, 0x7, 0x2b, 
    0x2, 0x2, 0x51e, 0x51f, 0x5, 0xd6, 0x6c, 0x2, 0x51f, 0x520, 0x7, 0x33, 
    0x2, 0x2, 0x520, 0x521, 0x5, 0xd6, 0x6c, 0x2, 0x521, 0x522, 0x7, 0x2c, 
    0x2, 0x2, 0x522, 0x105, 0x3, 0x2, 0x2, 0x2, 0x523, 0x524, 0x5, 0xcc, 
    0x67, 0x2, 0x524, 0x525, 0x7, 0x2a, 0x2, 0x2, 0x525, 0x527, 0x3, 0x2, 
    0x2, 0x2, 0x526, 0x523, 0x3, 0x2, 0x2, 0x2, 0x526, 0x527, 0x3, 0x2, 
    0x2, 0x2, 0x527, 0x528, 0x3, 0x2, 0x2, 0x2, 0x528, 0x52d, 0x5, 0x108, 
    0x85, 0x2, 0x529, 0x52a, 0x7, 0x29, 0x2, 0x2, 0x52a, 0x52c, 0x5, 0x108, 
    0x85, 0x2, 0x52b, 0x529, 0x3, 0x2, 0x2, 0x2, 0x52c, 0x52f, 0x3, 0x2, 
    0x2, 0x2, 0x52d, 0x52b, 0x3, 0x2, 0x2, 0x2, 0x52d, 0x52e, 0x3, 0x2, 
    0x2, 0x2, 0x52e, 0x531, 0x3, 0x2, 0x2, 0x2, 0x52f, 0x52d, 0x3, 0x2, 
    0x2, 0x2, 0x530, 0x532, 0x9, 0x13, 0x2, 0x2, 0x531, 0x530, 0x3, 0x2, 
    0x2, 0x2, 0x531, 0x532, 0x3, 0x2, 0x2, 0x2, 0x532, 0x107, 0x3, 0x2, 
    0x2, 0x2, 0x533, 0x538, 0x5, 0xc0, 0x61, 0x2, 0x534, 0x536, 0x5, 0x12, 
    0xa, 0x2, 0x535, 0x534, 0x3, 0x2, 0x2, 0x2, 0x535, 0x536, 0x3, 0x2, 
    0x2, 0x2, 0x536, 0x537, 0x3, 0x2, 0x2, 0x2, 0x537, 0x539, 0x5, 0x1c, 
    0xf, 0x2, 0x538, 0x535, 0x3, 0x2, 0x2, 0x2, 0x538, 0x539, 0x3, 0x2, 
    0x2, 0x2, 0x539, 0x53d, 0x3, 0x2, 0x2, 0x2, 0x53a, 0x53c, 0x5, 0x10a, 
    0x86, 0x2, 0x53b, 0x53a, 0x3, 0x2, 0x2, 0x2, 0x53c, 0x53f, 0x3, 0x2, 
    0x2, 0x2, 0x53d, 0x53b, 0x3, 0x2, 0x2, 0x2, 0x53d, 0x53e, 0x3, 0x2, 
    0x2, 0x2, 0x53e, 0x109, 0x3, 0x2, 0x2, 0x2, 0x53f, 0x53d, 0x3, 0x2, 
    0x2, 0x2, 0x540, 0x541, 0x7, 0x2d, 0x2, 0x2, 0x541, 0x542, 0x5, 0xd6, 
    0x6c, 0x2, 0x542, 0x543, 0x7, 0x2e, 0x2, 0x2, 0x543, 0x547, 0x3, 0x2, 
    0x2, 0x2, 0x544, 0x547, 0x7, 0x6d, 0x2, 0x2, 0x545, 0x547, 0x7, 0x6e, 
    0x2, 0x2, 0x546, 0x540, 0x3, 0x2, 0x2, 0x2, 0x546, 0x544, 0x3, 0x2, 
    0x2, 0x2, 0x546, 0x545, 0x3, 0x2, 0x2, 0x2, 0x547, 0x10b, 0x3, 0x2, 
    0x2, 0x2, 0x548, 0x54b, 0x5, 0xf0, 0x79, 0x2, 0x549, 0x54b, 0x5, 0xfa, 
    0x7e, 0x2, 0x54a, 0x548, 0x3, 0x2, 0x2, 0x2, 0x54a, 0x549, 0x3, 0x2, 
    0x2, 0x2, 0x54b, 0x54c, 0x3, 0x2, 0x2, 0x2, 0x54c, 0x54e, 0x5, 0xc0, 
    0x61, 0x2, 0x54d, 0x54f, 0x5, 0x12, 0xa, 0x2, 0x54e, 0x54d, 0x3, 0x2, 
    0x2, 0x2, 0x54e, 0x54f, 0x3, 0x2, 0x2, 0x2, 0x54f, 0x550, 0x3, 0x2, 
    0x2, 0x2, 0x550, 0x551, 0x5, 0xd6, 0x6c, 0x2, 0x551, 0x10d, 0x3, 0x2, 
    0x2, 0x2, 0x8b, 0x111, 0x11c, 0x124, 0x12f, 0x137, 0x13b, 0x144, 0x149, 
    0x14b, 0x153, 0x157, 0x159, 0x163, 0x168, 0x171, 0x176, 0x17d, 0x187, 
    0x192, 0x19c, 0x1a0, 0x1a8, 0x1bb, 0x1c7, 0x1d0, 0x1d4, 0x1e4, 0x1e9, 
    0x1ef, 0x1f3, 0x210, 0x219, 0x223, 0x236, 0x23e, 0x242, 0x24f, 0x254, 
    0x25a, 0x25e, 0x282, 0x28b, 0x29a, 0x2a0, 0x2a5, 0x2aa, 0x2ae, 0x2b1, 
    0x2b6, 0x2bc, 0x2c6, 0x2c9, 0x2cc, 0x2d4, 0x2d7, 0x2dc, 0x2df, 0x2e3, 
    0x2e9, 0x2ec, 0x2ef, 0x2f2, 0x2f7, 0x2fb, 0x300, 0x305, 0x30b, 0x311, 
    0x319, 0x321, 0x32b, 0x331, 0x340, 0x348, 0x34c, 0x359, 0x35e, 0x364, 
    0x368, 0x382, 0x38a, 0x39d, 0x3a5, 0x3a9, 0x3b6, 0x3bb, 0x3c1, 0x3c5, 
    0x3df, 0x3e9, 0x3ed, 0x3f4, 0x3fb, 0x41c, 0x424, 0x42c, 0x434, 0x43d, 
    0x449, 0x450, 0x456, 0x45b, 0x460, 0x465, 0x469, 0x47a, 0x47f, 0x483, 
    0x48f, 0x494, 0x499, 0x49e, 0x4a3, 0x4a8, 0x4ad, 0x4b2, 0x4b7, 0x4bc, 
    0x4c1, 0x4c6, 0x4ca, 0x4d6, 0x4e3, 0x4ea, 0x4ec, 0x4f7, 0x4fb, 0x515, 
    0x526, 0x52d, 0x531, 0x535, 0x538, 0x53d, 0x546, 0x54a, 0x54e, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

FlingHdlGrammarParser::Initializer FlingHdlGrammarParser::_init;
