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
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingProgram);

	while (!CMP_LEX_TOK(MiscEof))
	{
	}
	JUST_EXPECT(MiscEof);

	return std::nullopt;
}
auto Parser::parseFlingDeclPackage() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclPackage);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclPackageItem() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclPackageItem);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingImport() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingImport);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclParamList() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclParamList);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclParamListItem() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclParamListItem);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclArgList() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclArgList);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclArgListItem() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclArgListItem);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingInstParamList() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingInstParamList);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingInstParamListPos() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingInstParamListPos);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingInstParamListPosItem() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingInstParamListPosItem);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingInstParamListNamed() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingInstParamListNamed);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingInstParamListNamedItem() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingInstParamListNamedItem);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingInstArgList() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingInstArgList);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingInstArgListPos() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingInstArgListPos);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingInstArgListPosItem() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingInstArgListPosItem);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingInstArgListNamed() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingInstArgListNamed);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingInstArgListNamedItem() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingInstArgListNamedItem);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModule() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModule);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleScope() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleScope);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleItem() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleItem);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingModinst() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingModinst);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleGen() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleGen);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleGenIf() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleGenIf);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleGenSwitchEtc() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleGenSwitchEtc);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleGenSwitchEtcCase() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleGenSwitchEtcCase);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleGenSwitchEtcDefault() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleGenSwitchEtcDefault);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleGenFor() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleGenFor);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehav() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleBehav);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavComb() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleBehavComb);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavSeq() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleBehavSeq);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavSeqEdgeItem() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleBehavSeqEdgeItem);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScope() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleBehavScope);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItem() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleBehavScopeItem);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemIf() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleBehavScopeItemIf);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemSwitchEtc() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleBehavScopeItemSwitchEtc);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemSwitchEtcCase() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleBehavScopeItemSwitchEtcCase);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemSwitchEtcDefault() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleBehavScopeItemSwitchEtcDefault);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemFor() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleBehavScopeItemFor);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemWhile() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleBehavScopeItemWhile);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemGen() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleBehavScopeItemGen);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemGenIf() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleBehavScopeItemGenIf);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemGenSwitchEtc() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleBehavScopeItemGenSwitchEtc);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemGenSwitchEtcCase() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleBehavScopeItemGenSwitchEtcCase);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemGenSwitchEtcDefault() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleBehavScopeItemGenSwitchEtcDefault);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclModuleBehavScopeItemGenFor() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclModuleBehavScopeItemGenFor);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingAnyBehavScopeItem() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingAnyBehavScopeItem);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingAnyBehavScopeItemAssign() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingAnyBehavScopeItemAssign);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclCompositeType() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclCompositeType);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclCompositeTypeStruct() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclCompositeTypeStruct);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclCompositeTypeStructItem() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclCompositeTypeStructItem);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCompositeTypeStructItemGen() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingCompositeTypeStructItemGen);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCompositeTypeStructItemGenIf() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingCompositeTypeStructItemGenIf);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCompositeTypeStructItemGenSwitchEtc() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingCompositeTypeStructItemGenSwitchEtc);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCompositeTypeStructItemGenSwitchEtcCase() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingCompositeTypeStructItemGenSwitchEtcCase);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCompositeTypeStructItemGenSwitchEtcDefault() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingCompositeTypeStructItemGenSwitchEtcDefault);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCompositeTypeStructItemGenFor() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingCompositeTypeStructItemGenFor);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclEnum() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclEnum);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclEnumItem() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclEnumItem);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprog() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclSubprog);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogFuncHeader() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclSubprogFuncHeader);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogTaskHeader() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclSubprogTaskHeader);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScope() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclSubprogScope);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItem() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclSubprogScopeItem);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemIf() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclSubprogScopeItemIf);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemSwitchEtc() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclSubprogScopeItemSwitchEtc);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemSwitchEtcCase() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclSubprogScopeItemSwitchEtcCase);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemSwitchEtcDefault() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclSubprogScopeItemSwitchEtcDefault);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemFor() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclSubprogScopeItemFor);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemWhile() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclSubprogScopeItemWhile);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemGen() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclSubprogScopeItemGen);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemGenIf() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclSubprogScopeItemGenIf);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemGenSwitchEtc() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclSubprogScopeItemGenSwitchEtc);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemGenSwitchEtcCase() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclSubprogScopeItemGenSwitchEtcCase);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemGenSwitchEtcDefault() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclSubprogScopeItemGenSwitchEtcDefault);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclSubprogScopeItemGenFor() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclSubprogScopeItemGenFor);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclConst() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclConst);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclVarNoInitVal() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclVarNoInitVal);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclVar() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclVar);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclWire() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclWire);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingWireAssign() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingWireAssign);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingDeclAlias() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingDeclAlias);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingScopedIdent() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingScopedIdent);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingIdentList() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingIdentList);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingSubprogIdentList() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingSubprogIdentList);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingExprList() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingExprList);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingRangeList() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingRangeList);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingExprOrRangeList() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingExprOrRangeList);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingTypenmOrModnmList() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingTypenmOrModnmList);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingImportItem() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingImportItem);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingImportItemList() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingImportItemList);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingExpr() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingExpr);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingMuxExpr() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingMuxExpr);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingLogorExpr() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingLogorExpr);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingLogandExpr() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingLogandExpr);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCmpEqEtcExpr() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingCmpEqEtcExpr);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCmpLtEtcExpr() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingCmpLtEtcExpr);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingPlusMinusExpr() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingPlusMinusExpr);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingMulDivModExpr() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingMulDivModExpr);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingBitorBitnorExpr() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingBitorBitnorExpr);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingBitandBitnandExpr() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingBitandBitnandExpr);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingBitxorBitxnorExpr() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingBitxorBitxnorExpr);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingBitshiftExpr() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingBitshiftExpr);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingUnaryExpr() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingUnaryExpr);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingLowExpr() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingLowExpr);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCallDollarFuncExpr() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingCallDollarFuncExpr);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCallSubprogExpr() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingCallSubprogExpr);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingSubprogIdent() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingSubprogIdent);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingIdentExpr() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingIdentExpr);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingCatExpr() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingCatExpr);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingReplExpr() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingReplExpr);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingSizedExpr() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingSizedExpr);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingRange() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingRange);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingNonSimpleRange() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingNonSimpleRange);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingSimpleRangeSuffix() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingSimpleRangeSuffix);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingExprOrRange() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingExprOrRange);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingTypenmOrModnmCstmStart() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingTypenmOrModnmCstmStart);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingTypenmOrModnmCstmChainItem() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingTypenmOrModnmCstmChainItem);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

		return ret;
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::parseFlingTypenmOrModnm() -> ParseRet
{
	DEFER_RESTORE_PARSE_FUNC_STR(parseFlingTypenmOrModnm);

	if (just_get_valid_tokens())
	{
		JtParseRet ret;

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
		DEFER_RESTORE_PARSE_FUNC_STR(parseTok##name); \
		\
		if (just_get_valid_tokens()) \
		{ \
			JtParseRet ret; \
			ret.first = TOK_SET(
			return ret; \
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
