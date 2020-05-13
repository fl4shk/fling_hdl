#ifndef src_parser_class_hpp
#define src_parser_class_hpp

// src/parser_class.hpp

#include "misc_includes.hpp"
#include "lexer_class.hpp"

namespace fling_hdl
{

class Parser: public RdParserBase<Lexer, Parser>
{
public:		// types
	using Base = RdParserBase<Lexer, Parser>;

public:		// functions
	inline Parser(const string& s_filename)
		: Base(s_filename)
	{
	}
	GEN_NO_CM_CONSTRUCTORS_AND_ASSIGN(Parser);
	virtual inline ~Parser() = default;

	void parseFlingProgram();

private:		// functions
	void _parseFlingDeclPackage();
	void _parseFlingDeclPackageItem();
	void _parseFlingImport();
	void _parseFlingDeclParamList();
	void _parseFlingDeclParamListItem();
	void _parseFlingDeclArgList();
	void _parseFlingDeclArgListItem();
	void _parseFlingInstParamList();
	void _parseFlingInstParamListPos();
	void _parseFlingInstParamListPosItem();
	void _parseFlingInstParamListNamed();
	void _parseFlingInstParamListNamedItem();
	void _parseFlingInstArgList();
	void _parseFlingInstArgListPos();
	void _parseFlingInstArgListPosItem();
	void _parseFlingInstArgListNamed();
	void _parseFlingInstArgListNamedItem();
	void _parseFlingDeclModule();
	void _parseFlingDeclModuleScope();
	void _parseFlingDeclModuleItem();
	void _parseFlingModinst();
	void _parseFlingDeclModuleGen();
	void _parseFlingDeclModuleGenIf();
	void _parseFlingDeclModuleGenSwitchEtc();
	void _parseFlingDeclModuleGenSwitchEtcCase();
	void _parseFlingDeclModuleGenSwitchEtcDefault();
	void _parseFlingDeclModuleGenFor();
	void _parseFlingDeclModuleBehav();
	void _parseFlingDeclModuleBehavComb();
	void _parseFlingDeclModuleBehavSeq();
	void _parseFlingDeclModuleBehavSeqEdgeItem();
	void _parseFlingDeclModuleBehavScope();
	void _parseFlingDeclModuleBehavScopeItem();
	void _parseFlingDeclModuleBehavScopeItemIf();
	void _parseFlingDeclModuleBehavScopeItemSwitchEtc();
	void _parseFlingDeclModuleBehavScopeItemSwitchEtcCase();
	void _parseFlingDeclModuleBehavScopeItemSwitchEtcDefault();
	void _parseFlingDeclModuleBehavScopeItemFor();
	void _parseFlingDeclModuleBehavScopeItemWhile();
	void _parseFlingDeclModuleBehavScopeItemGen();
	void _parseFlingDeclModuleBehavScopeItemGenIf();
	void _parseFlingDeclModuleBehavScopeItemGenSwitchEtc();
	void _parseFlingDeclModuleBehavScopeItemGenSwitchEtcCase();
	void _parseFlingDeclModuleBehavScopeItemGenSwitchEtcDefault();
	void _parseFlingDeclModuleBehavScopeItemGenFor();
	void _parseFlingAnyBehavScopeItem();
	void _parseFlingAnyBehavScopeItemAssign();
	void _parseFlingDeclCompositeType();
	void _parseFlingDeclCompositeTypeStruct();
	void _parseFlingDeclCompositeTypeStructItem();
	void _parseFlingCompositeTypeStructItemGen();
	void _parseFlingCompositeTypeStructItemGenIf();
	void _parseFlingCompositeTypeStructItemGenSwitchEtc();
	void _parseFlingCompositeTypeStructItemGenSwitchEtcCase();
	void _parseFlingCompositeTypeStructItemGenSwitchEtcDefault();
	void _parseFlingCompositeTypeStructItemGenFor();
	void _parseFlingDeclEnum();
	void _parseFlingDeclEnumItem();
	void _parseFlingDeclSubprog();
	void _parseFlingDeclSubprogFuncHeader();
	void _parseFlingDeclSubprogTaskHeader();
	void _parseFlingDeclSubprogScope();
	void _parseFlingDeclSubprogScopeItem();
	void _parseFlingDeclSubprogScopeItemIf();
	void _parseFlingDeclSubprogScopeItemSwitchEtc();
	void _parseFlingDeclSubprogScopeItemSwitchEtcCase();
	void _parseFlingDeclSubprogScopeItemSwitchEtcDefault();
	void _parseFlingDeclSubprogScopeItemFor();
	void _parseFlingDeclSubprogScopeItemWhile();
	void _parseFlingDeclSubprogScopeItemGen();
	void _parseFlingDeclSubprogScopeItemGenIf();
	void _parseFlingDeclSubprogScopeItemGenSwitchEtc();
	void _parseFlingDeclSubprogScopeItemGenSwitchEtcCase();
	void _parseFlingDeclSubprogScopeItemGenSwitchEtcDefault();
	void _parseFlingDeclSubprogScopeItemGenFor();
	void _parseFlingDeclConst();
	void _parseFlingDeclVarNoInitVal();
	void _parseFlingDeclVar();
	void _parseFlingDeclWire();
	void _parseFlingWireAssign();
	void _parseFlingDeclAlias();
	void _parseFlingScopedIdent();
	void _parseFlingIdentList();
	void _parseFlingSubprogIdentList();
	void _parseFlingExprList();
	void _parseFlingRangeList();
	void _parseFlingExprOrRangeList();
	void _parseFlingTypenmOrModnmList();
	void _parseFlingImportItem();
	void _parseFlingImportItemList();
	void _parseFlingExpr();
	void _parseFlingMuxExpr();
	void _parseFlingLogorExpr();
	void _parseFlingLogandExpr();
	void _parseFlingCmpEqEtcExpr();
	void _parseFlingCmpLtEtcExpr();
	void _parseFlingPlusMinusExpr();
	void _parseFlingMulDivModExpr();
	void _parseFlingBitorBitnorExpr();
	void _parseFlingBitandBitnandExpr();
	void _parseFlingBitxorBitxnorExpr();
	void _parseFlingBitshiftExpr();
	void _parseFlingUnaryExpr();
	void _parseFlingLowExpr();
	void _parseFlingCallDollarFuncExpr();
	void _parseFlingCallSubprogExpr();
	void _parseFlingSubprogIdent();
	void _parseFlingIdentExpr();
	void _parseFlingCatExpr();
	void _parseFlingReplExpr();
	void _parseFlingRange();
	void _parseFlingNonSimpleRange();
	void _parseFlingSimpleRangeSuffix();
	void _parseFlingExprOrRange();
	void _parseFlingTypenmOrModnm();
};

} // namespace fling_hdl


#endif		// src_parser_class_hpp
