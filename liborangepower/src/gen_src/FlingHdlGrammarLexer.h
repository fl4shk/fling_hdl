
// Generated from FlingHdlGrammar.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  FlingHdlGrammarLexer : public antlr4::Lexer {
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

  FlingHdlGrammarLexer(antlr4::CharStream *input);
  ~FlingHdlGrammarLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

