#include "parser_class.hpp"
#include "liborangepower_src/cpp_magic.hpp"

namespace fling_hdl
{

using namespace ast;

#include "parser_class_defines.hpp"

Parser::Parser(const string& s_filename)
	: ParserBase(s_filename)
{
}
int Parser::run()
{
	parseFlingProgram();
}

void Parser::parseFlingProgram()
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingProgram);

	while (!CMP_LEX_TOK(MiscEof))
	{
	}
	JUST_EXPECT(MiscEof);
}
void Parser::parseFlingDeclPackage()
{
	DEFER_RESTORE_PARSE_FUNC_STR(
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclPackageItem()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingImport()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclParamList()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclParamListItem()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclArgList()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclArgListItem()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingInstParamList()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingInstParamListPos()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingInstParamListPosItem()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingInstParamListNamed()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingInstParamListNamedItem()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingInstArgList()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingInstArgListPos()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingInstArgListPosItem()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingInstArgListNamed()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingInstArgListNamedItem()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModule()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleScope()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleItem()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingModinst()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleGen()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleGenIf()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleGenSwitchEtc()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleGenSwitchEtcCase()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleGenSwitchEtcDefault()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleGenFor()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleBehav()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleBehavComb()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleBehavSeq()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleBehavSeqEdgeItem()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScope()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItem()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemIf()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemSwitchEtc()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemSwitchEtcCase()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemSwitchEtcDefault()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemFor()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemWhile()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemGen()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemGenIf()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemGenSwitchEtc()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemGenSwitchEtcCase()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemGenSwitchEtcDefault()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemGenFor()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingAnyBehavScopeItem()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingAnyBehavScopeItemAssign()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclCompositeType()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclCompositeTypeStruct()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclCompositeTypeStructItem()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingCompositeTypeStructItemGen()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingCompositeTypeStructItemGenIf()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingCompositeTypeStructItemGenSwitchEtc()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingCompositeTypeStructItemGenSwitchEtcCase()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingCompositeTypeStructItemGenSwitchEtcDefault()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingCompositeTypeStructItemGenFor()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclEnum()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclEnumItem()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclSubprog()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclSubprogFuncHeader()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclSubprogTaskHeader()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclSubprogScope()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItem()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemIf()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemSwitchEtc()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemSwitchEtcCase()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemSwitchEtcDefault()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemFor()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemWhile()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemGen()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemGenIf()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemGenSwitchEtc()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemGenSwitchEtcCase()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemGenSwitchEtcDefault()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemGenFor()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclConst()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclVarNoInitVal()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclVar()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclWire()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingWireAssign()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingDeclAlias()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingScopedIdent()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingIdentList()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingSubprogIdentList()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingExprList()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingRangeList()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingExprOrRangeList()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingTypenmOrModnmList()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingImportItem()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingImportItemList()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingExpr()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingMuxExpr()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingLogorExpr()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingLogandExpr()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingCmpEqEtcExpr()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingCmpLtEtcExpr()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingPlusMinusExpr()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingMulDivModExpr()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingBitorBitnorExpr()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingBitandBitnandExpr()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingBitxorBitxnorExpr()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingBitshiftExpr()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingUnaryExpr()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingLowExpr()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingCallDollarFuncExpr()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingCallSubprogExpr()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingSubprogIdent()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingIdentExpr()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingCatExpr()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingReplExpr()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingSizedExpr()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingRange()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingNonSimpleRange()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingSimpleRangeSuffix()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingExprOrRange()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingTypenmOrModnmCstmStart()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingTypenmOrModnmCstmChainItem()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}
void Parser::parseFlingTypenmOrModnm()
{
	if (just_test())
	{
	}
	else // if (!just_test())
	{
	}
}

#define X(name, dummy_0) \
	void Parser::parseTok##name() \
	{ \
		if (just_test()) \
		{ \
			JustTestParseRet ret; \
			return ret; \
		} \
		else /* if (!just_test()) */ \
		{ \
			JUST_EXPECT(name); \
			return std::nullopt; \
		} \
	}
LIST_OF_TOKENS(X)
#undef X

} // namespace fling_hdl
