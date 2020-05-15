#include "parser_class.hpp"
#include "liborangepower_src/cpp_magic.hpp"

namespace fling_hdl
{

using namespace ast;

#include "parser_class_defines.hpp"


void Parser::parseFlingProgram()
{
	WHILE_NOT_TOK(MiscEof)
	{
		JUST_RG_RULES_PARSE(_parseFlingDeclPackageItem);
	}
	JUST_EXPECT(MiscEof);
}
void Parser::_parseFlingDeclPackage()
{
	if (just_rg_rules())
	{
		RGR_INSERT(KwPackage, _parseFlingDeclPackage);
	}
	else
	{
		EXPECT_IDENT_AND_GRAB_S(ident);

		JUST_EXPECT(PunctLbrace);

		WHILE_NOT_TOK(PunctRbrace)
		{
		}

		JUST_EXPECT(PunctRbrace);
	}
}
void Parser::_parseFlingDeclPackageItem()
{
}
void Parser::_parseFlingImport()
{
}
void Parser::_parseFlingDeclParamList()
{
}
void Parser::_parseFlingDeclParamListItem()
{
}
void Parser::_parseFlingDeclArgList()
{
}
void Parser::_parseFlingDeclArgListItem()
{
}
void Parser::_parseFlingInstParamList()
{
}
void Parser::_parseFlingInstParamListPos()
{
}
void Parser::_parseFlingInstParamListPosItem()
{
}
void Parser::_parseFlingInstParamListNamed()
{
}
void Parser::_parseFlingInstParamListNamedItem()
{
}
void Parser::_parseFlingInstArgList()
{
}
void Parser::_parseFlingInstArgListPos()
{
}
void Parser::_parseFlingInstArgListPosItem()
{
}
void Parser::_parseFlingInstArgListNamed()
{
}
void Parser::_parseFlingInstArgListNamedItem()
{
}
void Parser::_parseFlingDeclModule()
{
}
void Parser::_parseFlingDeclModuleScope()
{
}
void Parser::_parseFlingDeclModuleItem()
{
}
void Parser::_parseFlingModinst()
{
}
void Parser::_parseFlingDeclModuleGen()
{
}
void Parser::_parseFlingDeclModuleGenIf()
{
}
void Parser::_parseFlingDeclModuleGenSwitchEtc()
{
}
void Parser::_parseFlingDeclModuleGenSwitchEtcCase()
{
}
void Parser::_parseFlingDeclModuleGenSwitchEtcDefault()
{
}
void Parser::_parseFlingDeclModuleGenFor()
{
}
void Parser::_parseFlingDeclModuleBehav()
{
}
void Parser::_parseFlingDeclModuleBehavComb()
{
}
void Parser::_parseFlingDeclModuleBehavSeq()
{
}
void Parser::_parseFlingDeclModuleBehavSeqEdgeItem()
{
}
void Parser::_parseFlingDeclModuleBehavScope()
{
}
void Parser::_parseFlingDeclModuleBehavScopeItem()
{
}
void Parser::_parseFlingDeclModuleBehavScopeItemIf()
{
}
void Parser::_parseFlingDeclModuleBehavScopeItemSwitchEtc()
{
}
void Parser::_parseFlingDeclModuleBehavScopeItemSwitchEtcCase()
{
}
void Parser::_parseFlingDeclModuleBehavScopeItemSwitchEtcDefault()
{
}
void Parser::_parseFlingDeclModuleBehavScopeItemFor()
{
}
void Parser::_parseFlingDeclModuleBehavScopeItemWhile()
{
}
void Parser::_parseFlingDeclModuleBehavScopeItemGen()
{
}
void Parser::_parseFlingDeclModuleBehavScopeItemGenIf()
{
}
void Parser::_parseFlingDeclModuleBehavScopeItemGenSwitchEtc()
{
}
void Parser::_parseFlingDeclModuleBehavScopeItemGenSwitchEtcCase()
{
}
void Parser::_parseFlingDeclModuleBehavScopeItemGenSwitchEtcDefault()
{
}
void Parser::_parseFlingDeclModuleBehavScopeItemGenFor()
{
}
void Parser::_parseFlingAnyBehavScopeItem()
{
}
void Parser::_parseFlingAnyBehavScopeItemAssign()
{
}
void Parser::_parseFlingDeclCompositeType()
{
}
void Parser::_parseFlingDeclCompositeTypeStruct()
{
}
void Parser::_parseFlingDeclCompositeTypeStructItem()
{
}
void Parser::_parseFlingCompositeTypeStructItemGen()
{
}
void Parser::_parseFlingCompositeTypeStructItemGenIf()
{
}
void Parser::_parseFlingCompositeTypeStructItemGenSwitchEtc()
{
}
void Parser::_parseFlingCompositeTypeStructItemGenSwitchEtcCase()
{
}
void Parser::_parseFlingCompositeTypeStructItemGenSwitchEtcDefault()
{
}
void Parser::_parseFlingCompositeTypeStructItemGenFor()
{
}
void Parser::_parseFlingDeclEnum()
{
}
void Parser::_parseFlingDeclEnumItem()
{
}
void Parser::_parseFlingDeclSubprog()
{
}
void Parser::_parseFlingDeclSubprogFuncHeader()
{
}
void Parser::_parseFlingDeclSubprogTaskHeader()
{
}
void Parser::_parseFlingDeclSubprogScope()
{
}
void Parser::_parseFlingDeclSubprogScopeItem()
{
}
void Parser::_parseFlingDeclSubprogScopeItemIf()
{
}
void Parser::_parseFlingDeclSubprogScopeItemSwitchEtc()
{
}
void Parser::_parseFlingDeclSubprogScopeItemSwitchEtcCase()
{
}
void Parser::_parseFlingDeclSubprogScopeItemSwitchEtcDefault()
{
}
void Parser::_parseFlingDeclSubprogScopeItemFor()
{
}
void Parser::_parseFlingDeclSubprogScopeItemWhile()
{
}
void Parser::_parseFlingDeclSubprogScopeItemGen()
{
}
void Parser::_parseFlingDeclSubprogScopeItemGenIf()
{
}
void Parser::_parseFlingDeclSubprogScopeItemGenSwitchEtc()
{
}
void Parser::_parseFlingDeclSubprogScopeItemGenSwitchEtcCase()
{
}
void Parser::_parseFlingDeclSubprogScopeItemGenSwitchEtcDefault()
{
}
void Parser::_parseFlingDeclSubprogScopeItemGenFor()
{
}
void Parser::_parseFlingDeclConst()
{
}
void Parser::_parseFlingDeclVarNoInitVal()
{
}
void Parser::_parseFlingDeclVar()
{
}
void Parser::_parseFlingDeclWire()
{
}
void Parser::_parseFlingWireAssign()
{
}
void Parser::_parseFlingDeclAlias()
{
}
void Parser::_parseFlingScopedIdent()
{
}
void Parser::_parseFlingIdentList()
{
}
void Parser::_parseFlingSubprogIdentList()
{
}
void Parser::_parseFlingExprList()
{
}
void Parser::_parseFlingRangeList()
{
}
void Parser::_parseFlingExprOrRangeList()
{
}
void Parser::_parseFlingTypenmOrModnmList()
{
}
void Parser::_parseFlingImportItem()
{
}
void Parser::_parseFlingImportItemList()
{
}
void Parser::_parseFlingExpr()
{
}
void Parser::_parseFlingMuxExpr()
{
}
void Parser::_parseFlingLogorExpr()
{
}
void Parser::_parseFlingLogandExpr()
{
}
void Parser::_parseFlingCmpEqEtcExpr()
{
}
void Parser::_parseFlingCmpLtEtcExpr()
{
}
void Parser::_parseFlingPlusMinusExpr()
{
}
void Parser::_parseFlingMulDivModExpr()
{
}
void Parser::_parseFlingBitorBitnorExpr()
{
}
void Parser::_parseFlingBitandBitnandExpr()
{
}
void Parser::_parseFlingBitxorBitxnorExpr()
{
}
void Parser::_parseFlingBitshiftExpr()
{
}
void Parser::_parseFlingUnaryExpr()
{
}
void Parser::_parseFlingLowExpr()
{
}
void Parser::_parseFlingCallDollarFuncExpr()
{
}
void Parser::_parseFlingCallSubprogExpr()
{
}
void Parser::_parseFlingSubprogIdent()
{
}
void Parser::_parseFlingIdentExpr()
{
}
void Parser::_parseFlingCatExpr()
{
}
void Parser::_parseFlingReplExpr()
{
}
void Parser::_parseFlingSizedExpr()
{
}
void Parser::_parseFlingRange()
{
}
void Parser::_parseFlingNonSimpleRange()
{
}
void Parser::_parseFlingSimpleRangeSuffix()
{
}
void Parser::_parseFlingExprOrRange()
{
}
void Parser::_parseFlingTypenmOrModnmCstmStart()
{
}
void Parser::_parseFlingTypenmOrModnmCstmChainItem()
{
}
void Parser::_parseFlingTypenmOrModnm()
{
}

} // namespace fling_hdl
