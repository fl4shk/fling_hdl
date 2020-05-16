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
	while (!CMP_LEX_TOK(MiscEof))
	{
		MAKE_FANCY_RG_RULES_PARSE(parse_ret, parseFlingDeclPackageItem,
			MiscEof);
		_post_rg_rules_parse(parse_ret);
	}
	JUST_EXPECT(MiscEof);
}
void Parser::parseFlingDeclPackage()
{
	if (just_rg_rules())
	{
		RGR_INSERT(KwPackage, &Parser::parseFlingDeclPackage);
	}
	else // if (!just_rg_rules())
	{
		EXPECT_IDENT_AND_GRAB_S(ident);

		JUST_EXPECT(PunctLbrace);

		if (!CMP_LEX_TOK(PunctRbrace))
		{
		}

		JUST_EXPECT(PunctRbrace);
	}
}
void Parser::parseFlingDeclPackageItem()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingImport()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclParamList()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclParamListItem()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclArgList()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclArgListItem()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingInstParamList()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingInstParamListPos()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingInstParamListPosItem()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingInstParamListNamed()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingInstParamListNamedItem()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingInstArgList()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingInstArgListPos()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingInstArgListPosItem()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingInstArgListNamed()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingInstArgListNamedItem()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModule()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleScope()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleItem()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingModinst()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleGen()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleGenIf()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleGenSwitchEtc()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleGenSwitchEtcCase()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleGenSwitchEtcDefault()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleGenFor()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleBehav()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleBehavComb()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleBehavSeq()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleBehavSeqEdgeItem()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScope()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItem()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemIf()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemSwitchEtc()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemSwitchEtcCase()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemSwitchEtcDefault()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemFor()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemWhile()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemGen()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemGenIf()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemGenSwitchEtc()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemGenSwitchEtcCase()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemGenSwitchEtcDefault()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclModuleBehavScopeItemGenFor()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingAnyBehavScopeItem()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingAnyBehavScopeItemAssign()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclCompositeType()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclCompositeTypeStruct()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclCompositeTypeStructItem()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingCompositeTypeStructItemGen()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingCompositeTypeStructItemGenIf()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingCompositeTypeStructItemGenSwitchEtc()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingCompositeTypeStructItemGenSwitchEtcCase()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingCompositeTypeStructItemGenSwitchEtcDefault()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingCompositeTypeStructItemGenFor()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclEnum()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclEnumItem()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclSubprog()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclSubprogFuncHeader()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclSubprogTaskHeader()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclSubprogScope()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItem()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemIf()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemSwitchEtc()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemSwitchEtcCase()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemSwitchEtcDefault()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemFor()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemWhile()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemGen()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemGenIf()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemGenSwitchEtc()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemGenSwitchEtcCase()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemGenSwitchEtcDefault()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclSubprogScopeItemGenFor()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclConst()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclVarNoInitVal()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclVar()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclWire()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingWireAssign()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingDeclAlias()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingScopedIdent()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingIdentList()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingSubprogIdentList()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingExprList()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingRangeList()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingExprOrRangeList()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingTypenmOrModnmList()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingImportItem()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingImportItemList()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingExpr()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingMuxExpr()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingLogorExpr()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingLogandExpr()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingCmpEqEtcExpr()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingCmpLtEtcExpr()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingPlusMinusExpr()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingMulDivModExpr()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingBitorBitnorExpr()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingBitandBitnandExpr()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingBitxorBitxnorExpr()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingBitshiftExpr()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingUnaryExpr()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingLowExpr()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingCallDollarFuncExpr()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingCallSubprogExpr()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingSubprogIdent()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingIdentExpr()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingCatExpr()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingReplExpr()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingSizedExpr()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingRange()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingNonSimpleRange()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingSimpleRangeSuffix()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingExprOrRange()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingTypenmOrModnmCstmStart()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingTypenmOrModnmCstmChainItem()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}
void Parser::parseFlingTypenmOrModnm()
{
	if (just_rg_rules())
	{
	}
	else // if (!just_rg_rules())
	{
	}
}

#define X(name, dummy_0) \
	void Parser::parseTok##name() \
	{ \
		if (just_rg_rules()) \
		{ \
			RGR_INSERT(name, parseTok##name); \
		} \
		else /* if (!just_rg_rules()) */ \
		{ \
			JUST_EXPECT(name); \
		} \
	}
LIST_OF_TOKENS(X)
#undef X

} // namespace fling_hdl
