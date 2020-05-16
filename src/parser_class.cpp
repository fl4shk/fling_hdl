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

auto Parser::parseFlingProgram() -> ParseRet
{
	PROLOGUE(parseFlingProgram);

	while (!CMP_LEX_TOK(MiscEof))
	{
	}
	JUST_EXPECT(MiscEof);

	return std::nullopt;
}
auto Parser::parseFlingDeclPackage() -> ParseRet
{
	PROLOGUE(parseFlingDeclPackage);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclPackageItem() -> ParseRet
{
	PROLOGUE(parseFlingDeclPackageItem);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingImport() -> ParseRet
{
	PROLOGUE(parseFlingImport);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclParamList() -> ParseRet
{
	PROLOGUE(parseFlingDeclParamList);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclParamListItem() -> ParseRet
{
	PROLOGUE(parseFlingDeclParamListItem);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclArgList() -> ParseRet
{
	PROLOGUE(parseFlingDeclArgList);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclArgListItem() -> ParseRet
{
	PROLOGUE(parseFlingDeclArgListItem);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingInstParamList() -> ParseRet
{
	PROLOGUE(parseFlingInstParamList);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingInstParamListPos() -> ParseRet
{
	PROLOGUE(parseFlingInstParamListPos);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingInstParamListPosItem() -> ParseRet
{
	PROLOGUE(parseFlingInstParamListPosItem);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingInstParamListNamed() -> ParseRet
{
	PROLOGUE(parseFlingInstParamListNamed);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingInstParamListNamedItem() -> ParseRet
{
	PROLOGUE(parseFlingInstParamListNamedItem);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingInstArgList() -> ParseRet
{
	PROLOGUE(parseFlingInstArgList);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingInstArgListPos() -> ParseRet
{
	PROLOGUE(parseFlingInstArgListPos);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingInstArgListPosItem() -> ParseRet
{
	PROLOGUE(parseFlingInstArgListPosItem);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingInstArgListNamed() -> ParseRet
{
	PROLOGUE(parseFlingInstArgListNamed);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingInstArgListNamedItem() -> ParseRet
{
	PROLOGUE(parseFlingInstArgListNamedItem);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModule() -> ParseRet
{
	PROLOGUE(parseFlingDeclModule);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleScope() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleScope);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleItem() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleItem);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingModinst() -> ParseRet
{
	PROLOGUE(parseFlingModinst);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleGen() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleGen);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleGenIf() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleGenIf);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleGenSwitchEtc() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleGenSwitchEtc);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleGenSwitchEtcCase() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleGenSwitchEtcCase);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleGenSwitchEtcDefault() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleGenSwitchEtcDefault);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleGenFor() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleGenFor);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehav() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleBehav);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavComb() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleBehavComb);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavSeq() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleBehavSeq);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavSeqEdgeItem() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleBehavSeqEdgeItem);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScope() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleBehavScope);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItem() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleBehavScopeItem);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemIf() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleBehavScopeItemIf);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemSwitchEtc() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleBehavScopeItemSwitchEtc);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemSwitchEtcCase() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleBehavScopeItemSwitchEtcCase);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemSwitchEtcDefault() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleBehavScopeItemSwitchEtcDefault);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemFor() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleBehavScopeItemFor);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemWhile() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleBehavScopeItemWhile);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemGen() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleBehavScopeItemGen);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemGenIf() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleBehavScopeItemGenIf);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemGenSwitchEtc() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleBehavScopeItemGenSwitchEtc);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemGenSwitchEtcCase() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleBehavScopeItemGenSwitchEtcCase);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemGenSwitchEtcDefault() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleBehavScopeItemGenSwitchEtcDefault);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemGenFor() -> ParseRet
{
	PROLOGUE(parseFlingDeclModuleBehavScopeItemGenFor);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingAnyBehavScopeItem() -> ParseRet
{
	PROLOGUE(parseFlingAnyBehavScopeItem);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingAnyBehavScopeItemAssign() -> ParseRet
{
	PROLOGUE(parseFlingAnyBehavScopeItemAssign);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclCompositeType() -> ParseRet
{
	PROLOGUE(parseFlingDeclCompositeType);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclCompositeTypeStruct() -> ParseRet
{
	PROLOGUE(parseFlingDeclCompositeTypeStruct);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclCompositeTypeStructItem() -> ParseRet
{
	PROLOGUE(parseFlingDeclCompositeTypeStructItem);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCompositeTypeStructItemGen() -> ParseRet
{
	PROLOGUE(parseFlingCompositeTypeStructItemGen);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCompositeTypeStructItemGenIf() -> ParseRet
{
	PROLOGUE(parseFlingCompositeTypeStructItemGenIf);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCompositeTypeStructItemGenSwitchEtc() -> ParseRet
{
	PROLOGUE(parseFlingCompositeTypeStructItemGenSwitchEtc);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCompositeTypeStructItemGenSwitchEtcCase() -> ParseRet
{
	PROLOGUE(parseFlingCompositeTypeStructItemGenSwitchEtcCase);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCompositeTypeStructItemGenSwitchEtcDefault() -> ParseRet
{
	PROLOGUE(parseFlingCompositeTypeStructItemGenSwitchEtcDefault);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCompositeTypeStructItemGenFor() -> ParseRet
{
	PROLOGUE(parseFlingCompositeTypeStructItemGenFor);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclEnum() -> ParseRet
{
	PROLOGUE(parseFlingDeclEnum);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclEnumItem() -> ParseRet
{
	PROLOGUE(parseFlingDeclEnumItem);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprog() -> ParseRet
{
	PROLOGUE(parseFlingDeclSubprog);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogFuncHeader() -> ParseRet
{
	PROLOGUE(parseFlingDeclSubprogFuncHeader);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogTaskHeader() -> ParseRet
{
	PROLOGUE(parseFlingDeclSubprogTaskHeader);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScope() -> ParseRet
{
	PROLOGUE(parseFlingDeclSubprogScope);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItem() -> ParseRet
{
	PROLOGUE(parseFlingDeclSubprogScopeItem);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemIf() -> ParseRet
{
	PROLOGUE(parseFlingDeclSubprogScopeItemIf);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemSwitchEtc() -> ParseRet
{
	PROLOGUE(parseFlingDeclSubprogScopeItemSwitchEtc);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemSwitchEtcCase() -> ParseRet
{
	PROLOGUE(parseFlingDeclSubprogScopeItemSwitchEtcCase);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemSwitchEtcDefault() -> ParseRet
{
	PROLOGUE(parseFlingDeclSubprogScopeItemSwitchEtcDefault);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemFor() -> ParseRet
{
	PROLOGUE(parseFlingDeclSubprogScopeItemFor);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemWhile() -> ParseRet
{
	PROLOGUE(parseFlingDeclSubprogScopeItemWhile);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemGen() -> ParseRet
{
	PROLOGUE(parseFlingDeclSubprogScopeItemGen);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemGenIf() -> ParseRet
{
	PROLOGUE(parseFlingDeclSubprogScopeItemGenIf);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemGenSwitchEtc() -> ParseRet
{
	PROLOGUE(parseFlingDeclSubprogScopeItemGenSwitchEtc);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemGenSwitchEtcCase() -> ParseRet
{
	PROLOGUE(parseFlingDeclSubprogScopeItemGenSwitchEtcCase);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemGenSwitchEtcDefault() -> ParseRet
{
	PROLOGUE(parseFlingDeclSubprogScopeItemGenSwitchEtcDefault);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemGenFor() -> ParseRet
{
	PROLOGUE(parseFlingDeclSubprogScopeItemGenFor);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclConst() -> ParseRet
{
	PROLOGUE(parseFlingDeclConst);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclVarNoInitVal() -> ParseRet
{
	PROLOGUE(parseFlingDeclVarNoInitVal);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclVar() -> ParseRet
{
	PROLOGUE(parseFlingDeclVar);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclWire() -> ParseRet
{
	PROLOGUE(parseFlingDeclWire);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingWireAssign() -> ParseRet
{
	PROLOGUE(parseFlingWireAssign);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclAlias() -> ParseRet
{
	PROLOGUE(parseFlingDeclAlias);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingScopedIdent() -> ParseRet
{
	PROLOGUE(parseFlingScopedIdent);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingIdentList() -> ParseRet
{
	PROLOGUE(parseFlingIdentList);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingSubprogIdentList() -> ParseRet
{
	PROLOGUE(parseFlingSubprogIdentList);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingExprList() -> ParseRet
{
	PROLOGUE(parseFlingExprList);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingRangeList() -> ParseRet
{
	PROLOGUE(parseFlingRangeList);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingExprOrRangeList() -> ParseRet
{
	PROLOGUE(parseFlingExprOrRangeList);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingTypenmOrModnmList() -> ParseRet
{
	PROLOGUE(parseFlingTypenmOrModnmList);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingImportItem() -> ParseRet
{
	PROLOGUE(parseFlingImportItem);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingImportItemList() -> ParseRet
{
	PROLOGUE(parseFlingImportItemList);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingExpr() -> ParseRet
{
	PROLOGUE(parseFlingExpr);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingMuxExpr() -> ParseRet
{
	PROLOGUE(parseFlingMuxExpr);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingLogorExpr() -> ParseRet
{
	PROLOGUE(parseFlingLogorExpr);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingLogandExpr() -> ParseRet
{
	PROLOGUE(parseFlingLogandExpr);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCmpEqEtcExpr() -> ParseRet
{
	PROLOGUE(parseFlingCmpEqEtcExpr);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCmpLtEtcExpr() -> ParseRet
{
	PROLOGUE(parseFlingCmpLtEtcExpr);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingPlusMinusExpr() -> ParseRet
{
	PROLOGUE(parseFlingPlusMinusExpr);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingMulDivModExpr() -> ParseRet
{
	PROLOGUE(parseFlingMulDivModExpr);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingBitorBitnorExpr() -> ParseRet
{
	PROLOGUE(parseFlingBitorBitnorExpr);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingBitandBitnandExpr() -> ParseRet
{
	PROLOGUE(parseFlingBitandBitnandExpr);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingBitxorBitxnorExpr() -> ParseRet
{
	PROLOGUE(parseFlingBitxorBitxnorExpr);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingBitshiftExpr() -> ParseRet
{
	PROLOGUE(parseFlingBitshiftExpr);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingUnaryExpr() -> ParseRet
{
	PROLOGUE(parseFlingUnaryExpr);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingLowExpr() -> ParseRet
{
	PROLOGUE(parseFlingLowExpr);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCallDollarFuncExpr() -> ParseRet
{
	PROLOGUE(parseFlingCallDollarFuncExpr);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCallSubprogExpr() -> ParseRet
{
	PROLOGUE(parseFlingCallSubprogExpr);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingSubprogIdent() -> ParseRet
{
	PROLOGUE(parseFlingSubprogIdent);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingIdentExpr() -> ParseRet
{
	PROLOGUE(parseFlingIdentExpr);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCatExpr() -> ParseRet
{
	PROLOGUE(parseFlingCatExpr);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingReplExpr() -> ParseRet
{
	PROLOGUE(parseFlingReplExpr);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingSizedExpr() -> ParseRet
{
	PROLOGUE(parseFlingSizedExpr);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingRange() -> ParseRet
{
	PROLOGUE(parseFlingRange);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingNonSimpleRange() -> ParseRet
{
	PROLOGUE(parseFlingNonSimpleRange);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingSimpleRangeSuffix() -> ParseRet
{
	PROLOGUE(parseFlingSimpleRangeSuffix);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingExprOrRange() -> ParseRet
{
	PROLOGUE(parseFlingExprOrRange);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingTypenmOrModnmCstmStart() -> ParseRet
{
	PROLOGUE(parseFlingTypenmOrModnmCstmStart);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingTypenmOrModnmCstmChainItem() -> ParseRet
{
	PROLOGUE(parseFlingTypenmOrModnmCstmChainItem);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingTypenmOrModnm() -> ParseRet
{
	PROLOGUE(parseFlingTypenmOrModnm);

	if (just_get_valid_tokens())
	{
		TokSet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}

#define X(name, dummy_0) \
	auto Parser::parseTok##name() -> ParseRet \
	{ \
		PROLOGUE(parseTok##name); \
		\
		if (just_get_valid_tokens()) \
		{ \
			return TOK_SET(name); \
		} \
		else /* if (!just_get_valid_tokens()) */ \
		{ \
			JUST_EXPECT(name); \
			return std::nullopt; \
		} \
	}
LIST_OF_TOKENS(X)
#undef X

} // namespace fling_hdl
