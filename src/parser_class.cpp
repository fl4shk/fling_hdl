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
	if (lex_tok() != Tok::MiscEof)
	{
		const auto& parse_ret = _rg_rules_parse
			(&Parser::parseFlingDeclPackageItem, TOK_SET(MiscEof));
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
	else
	{
		EXPECT_IDENT_AND_GRAB_S(ident);

		JUST_EXPECT(PunctLbrace);

		if (lex_tok() != Tok::PunctRbrace)
		{
		}

		JUST_EXPECT(PunctRbrace);
	}
}
void Parser::parseFlingDeclPackageItem()
{
}
void Parser::parseFlingImport()
{
}
void Parser::parseFlingDeclParamList()
{
}
void Parser::parseFlingDeclParamListItem()
{
}
void Parser::parseFlingDeclArgList()
{
}
void Parser::parseFlingDeclArgListItem()
{
}
void Parser::parseFlingInstParamList()
{
}
void Parser::parseFlingInstParamListPos()
{
}
void Parser::parseFlingInstParamListPosItem()
{
}
void Parser::parseFlingInstParamListNamed()
{
}
void Parser::parseFlingInstParamListNamedItem()
{
}
void Parser::parseFlingInstArgList()
{
}
void Parser::parseFlingInstArgListPos()
{
}
void Parser::parseFlingInstArgListPosItem()
{
}
void Parser::parseFlingInstArgListNamed()
{
}
void Parser::parseFlingInstArgListNamedItem()
{
}
void Parser::parseFlingDeclModule()
{
}
void Parser::parseFlingDeclModuleScope()
{
}
void Parser::parseFlingDeclModuleItem()
{
}
void Parser::parseFlingModinst()
{
}
void Parser::parseFlingDeclModuleGen()
{
}
void Parser::parseFlingDeclModuleGenIf()
{
}
void Parser::parseFlingDeclModuleGenSwitchEtc()
{
}
void Parser::parseFlingDeclModuleGenSwitchEtcCase()
{
}
void Parser::parseFlingDeclModuleGenSwitchEtcDefault()
{
}
void Parser::parseFlingDeclModuleGenFor()
{
}
void Parser::parseFlingDeclModuleBehav()
{
}
void Parser::parseFlingDeclModuleBehavComb()
{
}
void Parser::parseFlingDeclModuleBehavSeq()
{
}
void Parser::parseFlingDeclModuleBehavSeqEdgeItem()
{
}
void Parser::parseFlingDeclModuleBehavScope()
{
}
void Parser::parseFlingDeclModuleBehavScopeItem()
{
}
void Parser::parseFlingDeclModuleBehavScopeItemIf()
{
}
void Parser::parseFlingDeclModuleBehavScopeItemSwitchEtc()
{
}
void Parser::parseFlingDeclModuleBehavScopeItemSwitchEtcCase()
{
}
void Parser::parseFlingDeclModuleBehavScopeItemSwitchEtcDefault()
{
}
void Parser::parseFlingDeclModuleBehavScopeItemFor()
{
}
void Parser::parseFlingDeclModuleBehavScopeItemWhile()
{
}
void Parser::parseFlingDeclModuleBehavScopeItemGen()
{
}
void Parser::parseFlingDeclModuleBehavScopeItemGenIf()
{
}
void Parser::parseFlingDeclModuleBehavScopeItemGenSwitchEtc()
{
}
void Parser::parseFlingDeclModuleBehavScopeItemGenSwitchEtcCase()
{
}
void Parser::parseFlingDeclModuleBehavScopeItemGenSwitchEtcDefault()
{
}
void Parser::parseFlingDeclModuleBehavScopeItemGenFor()
{
}
void Parser::parseFlingAnyBehavScopeItem()
{
}
void Parser::parseFlingAnyBehavScopeItemAssign()
{
}
void Parser::parseFlingDeclCompositeType()
{
}
void Parser::parseFlingDeclCompositeTypeStruct()
{
}
void Parser::parseFlingDeclCompositeTypeStructItem()
{
}
void Parser::parseFlingCompositeTypeStructItemGen()
{
}
void Parser::parseFlingCompositeTypeStructItemGenIf()
{
}
void Parser::parseFlingCompositeTypeStructItemGenSwitchEtc()
{
}
void Parser::parseFlingCompositeTypeStructItemGenSwitchEtcCase()
{
}
void Parser::parseFlingCompositeTypeStructItemGenSwitchEtcDefault()
{
}
void Parser::parseFlingCompositeTypeStructItemGenFor()
{
}
void Parser::parseFlingDeclEnum()
{
}
void Parser::parseFlingDeclEnumItem()
{
}
void Parser::parseFlingDeclSubprog()
{
}
void Parser::parseFlingDeclSubprogFuncHeader()
{
}
void Parser::parseFlingDeclSubprogTaskHeader()
{
}
void Parser::parseFlingDeclSubprogScope()
{
}
void Parser::parseFlingDeclSubprogScopeItem()
{
}
void Parser::parseFlingDeclSubprogScopeItemIf()
{
}
void Parser::parseFlingDeclSubprogScopeItemSwitchEtc()
{
}
void Parser::parseFlingDeclSubprogScopeItemSwitchEtcCase()
{
}
void Parser::parseFlingDeclSubprogScopeItemSwitchEtcDefault()
{
}
void Parser::parseFlingDeclSubprogScopeItemFor()
{
}
void Parser::parseFlingDeclSubprogScopeItemWhile()
{
}
void Parser::parseFlingDeclSubprogScopeItemGen()
{
}
void Parser::parseFlingDeclSubprogScopeItemGenIf()
{
}
void Parser::parseFlingDeclSubprogScopeItemGenSwitchEtc()
{
}
void Parser::parseFlingDeclSubprogScopeItemGenSwitchEtcCase()
{
}
void Parser::parseFlingDeclSubprogScopeItemGenSwitchEtcDefault()
{
}
void Parser::parseFlingDeclSubprogScopeItemGenFor()
{
}
void Parser::parseFlingDeclConst()
{
}
void Parser::parseFlingDeclVarNoInitVal()
{
}
void Parser::parseFlingDeclVar()
{
}
void Parser::parseFlingDeclWire()
{
}
void Parser::parseFlingWireAssign()
{
}
void Parser::parseFlingDeclAlias()
{
}
void Parser::parseFlingScopedIdent()
{
}
void Parser::parseFlingIdentList()
{
}
void Parser::parseFlingSubprogIdentList()
{
}
void Parser::parseFlingExprList()
{
}
void Parser::parseFlingRangeList()
{
}
void Parser::parseFlingExprOrRangeList()
{
}
void Parser::parseFlingTypenmOrModnmList()
{
}
void Parser::parseFlingImportItem()
{
}
void Parser::parseFlingImportItemList()
{
}
void Parser::parseFlingExpr()
{
}
void Parser::parseFlingMuxExpr()
{
}
void Parser::parseFlingLogorExpr()
{
}
void Parser::parseFlingLogandExpr()
{
}
void Parser::parseFlingCmpEqEtcExpr()
{
}
void Parser::parseFlingCmpLtEtcExpr()
{
}
void Parser::parseFlingPlusMinusExpr()
{
}
void Parser::parseFlingMulDivModExpr()
{
}
void Parser::parseFlingBitorBitnorExpr()
{
}
void Parser::parseFlingBitandBitnandExpr()
{
}
void Parser::parseFlingBitxorBitxnorExpr()
{
}
void Parser::parseFlingBitshiftExpr()
{
}
void Parser::parseFlingUnaryExpr()
{
}
void Parser::parseFlingLowExpr()
{
}
void Parser::parseFlingCallDollarFuncExpr()
{
}
void Parser::parseFlingCallSubprogExpr()
{
}
void Parser::parseFlingSubprogIdent()
{
}
void Parser::parseFlingIdentExpr()
{
}
void Parser::parseFlingCatExpr()
{
}
void Parser::parseFlingReplExpr()
{
}
void Parser::parseFlingSizedExpr()
{
}
void Parser::parseFlingRange()
{
}
void Parser::parseFlingNonSimpleRange()
{
}
void Parser::parseFlingSimpleRangeSuffix()
{
}
void Parser::parseFlingExprOrRange()
{
}
void Parser::parseFlingTypenmOrModnmCstmStart()
{
}
void Parser::parseFlingTypenmOrModnmCstmChainItem()
{
}
void Parser::parseFlingTypenmOrModnm()
{
}

} // namespace fling_hdl
