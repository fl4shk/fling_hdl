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
	_parseFlingProgram();
	return 0;
}

auto Parser::_parseFlingProgram() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingProgram);
	INSERT_WANTED_TOK(MiscEof);

	while (CHECK_PARSE(_parseFlingDeclPackageItem))
	{
		_found_tok = true;
		_parseFlingDeclPackageItem();
	}

	_fail_if_not_found_wanted_tok();

	JUST_EXPECT(MiscEof);

	return std::nullopt;
}
auto Parser::_parseFlingDeclPackage() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclPackage);

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
auto Parser::_parseFlingDeclPackageItem() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclPackageItem);

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
auto Parser::_parseFlingImport() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingImport);

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
auto Parser::_parseFlingDeclParamList() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclParamList);

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
auto Parser::_parseFlingDeclParamListItem() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclParamListItem);

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
auto Parser::_parseFlingDeclArgList() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclArgList);

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
auto Parser::_parseFlingDeclArgListItem() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclArgListItem);

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
auto Parser::_parseFlingInstParamList() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingInstParamList);

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
auto Parser::_parseFlingInstParamListPos() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingInstParamListPos);

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
auto Parser::_parseFlingInstParamListPosItem() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingInstParamListPosItem);

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
auto Parser::_parseFlingInstParamListNamed() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingInstParamListNamed);

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
auto Parser::_parseFlingInstParamListNamedItem() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingInstParamListNamedItem);

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
auto Parser::_parseFlingInstArgList() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingInstArgList);

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
auto Parser::_parseFlingInstArgListPos() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingInstArgListPos);

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
auto Parser::_parseFlingInstArgListPosItem() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingInstArgListPosItem);

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
auto Parser::_parseFlingInstArgListNamed() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingInstArgListNamed);

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
auto Parser::_parseFlingInstArgListNamedItem() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingInstArgListNamedItem);

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
auto Parser::_parseFlingDeclModule() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModule);

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
auto Parser::_parseFlingDeclModuleScope() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleScope);

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
auto Parser::_parseFlingDeclModuleItem() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleItem);

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
auto Parser::_parseFlingModinst() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingModinst);

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
auto Parser::_parseFlingDeclModuleGen() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleGen);

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
auto Parser::_parseFlingDeclModuleGenIf() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleGenIf);

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
auto Parser::_parseFlingDeclModuleGenSwitchEtc() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleGenSwitchEtc);

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
auto Parser::_parseFlingDeclModuleGenCase() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleGenCase);

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
auto Parser::_parseFlingDeclModuleGenDefault() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleGenDefault);

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
auto Parser::_parseFlingDeclModuleGenFor() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleGenFor);

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
auto Parser::_parseFlingDeclModuleBehav() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehav);

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
auto Parser::_parseFlingDeclModuleBehavComb() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavComb);

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
auto Parser::_parseFlingDeclModuleBehavSeq() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavSeq);

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
auto Parser::_parseFlingDeclModuleBehavSeqEdgeItem() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavSeqEdgeItem);

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
auto Parser::_parseFlingDeclModuleBehavScope() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScope);

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
auto Parser::_parseFlingDeclModuleBehavScopeItem() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItem);

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
auto Parser::_parseFlingDeclModuleBehavScopeItemIf() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemIf);

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
auto Parser::_parseFlingDeclModuleBehavScopeItemSwitchEtc() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemSwitchEtc);

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
auto Parser::_parseFlingDeclModuleBehavScopeItemCase() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemCase);

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
auto Parser::_parseFlingDeclModuleBehavScopeItemDefault() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemDefault);

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
auto Parser::_parseFlingDeclModuleBehavScopeItemFor() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemFor);

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
auto Parser::_parseFlingDeclModuleBehavScopeItemWhile() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemWhile);

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
auto Parser::_parseFlingDeclModuleBehavScopeItemGen() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemGen);

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
auto Parser::_parseFlingDeclModuleBehavScopeItemGenIf() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemGenIf);

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
auto Parser::_parseFlingDeclModuleBehavScopeItemGenSwitchEtc() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemGenSwitchEtc);

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
auto Parser::_parseFlingDeclModuleBehavScopeItemGenCase() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemGenCase);

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
auto Parser::_parseFlingDeclModuleBehavScopeItemGenDefault() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemGenDefault);

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
auto Parser::_parseFlingDeclModuleBehavScopeItemGenFor() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemGenFor);

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
auto Parser::_parseFlingAnyBehavScopeItem() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingAnyBehavScopeItem);

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
auto Parser::_parseFlingAnyBehavScopeItemAssign() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingAnyBehavScopeItemAssign);

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
auto Parser::_parseFlingDeclCompositeType() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclCompositeType);

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
auto Parser::_parseFlingDeclStruct() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclStruct);

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
auto Parser::_parseFlingDeclStructScope() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclStructScope);

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
auto Parser::_parseFlingDeclStructScopeItem() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclStructScopeItem);

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
auto Parser::_parseFlingDeclStructScopeItemGen() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclStructScopeItemGen);

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
auto Parser::_parseFlingDeclStructScopeItemGenIf() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclStructScopeItemGenIf);

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
auto Parser::_parseFlingDeclStructScopeItemGenSwitchEtc() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclStructScopeItemGenSwitchEtc);

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
auto Parser::_parseFlingDeclStructScopeItemGenCase() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclStructScopeItemGenCase);

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
auto Parser::_parseFlingDeclStructScopeItemGenDefault() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclStructScopeItemGenDefault);

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
auto Parser::_parseFlingDeclStructScopeItemGenFor() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclStructScopeItemGenFor);

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
auto Parser::_parseFlingDeclEnum() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclEnum);

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
auto Parser::_parseFlingDeclEnumItem() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclEnumItem);

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
auto Parser::_parseFlingDeclSubprog() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprog);

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
auto Parser::_parseFlingDeclFuncHeader() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclFuncHeader);

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
auto Parser::_parseFlingDeclTaskHeader() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclTaskHeader);

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
auto Parser::_parseFlingDeclSubprogScope() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScope);

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
auto Parser::_parseFlingDeclSubprogScopeItem() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItem);

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
auto Parser::_parseFlingDeclSubprogScopeItemIf() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemIf);

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
auto Parser::_parseFlingDeclSubprogScopeItemSwitchEtc() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemSwitchEtc);

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
auto Parser::_parseFlingDeclSubprogScopeItemCase() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemCase);

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
auto Parser::_parseFlingDeclSubprogScopeItemDefault() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemDefault);

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
auto Parser::_parseFlingDeclSubprogScopeItemFor() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemFor);

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
auto Parser::_parseFlingDeclSubprogScopeItemWhile() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemWhile);

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
auto Parser::_parseFlingDeclSubprogScopeItemGen() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemGen);

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
auto Parser::_parseFlingDeclSubprogScopeItemGenIf() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemGenIf);

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
auto Parser::_parseFlingDeclSubprogScopeItemGenSwitchEtc() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemGenSwitchEtc);

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
auto Parser::_parseFlingDeclSubprogScopeItemGenCase() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemGenCase);

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
auto Parser::_parseFlingDeclSubprogScopeItemGenDefault() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemGenDefault);

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
auto Parser::_parseFlingDeclSubprogScopeItemGenFor() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemGenFor);

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
auto Parser::_parseFlingDeclConst() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclConst);

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
auto Parser::_parseFlingDeclVarNoDefVal() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclVarNoDefVal);

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
auto Parser::_parseFlingDeclVar() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclVar);

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
auto Parser::_parseFlingDeclWire() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclWire);

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
auto Parser::_parseFlingWireAssign() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingWireAssign);

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
auto Parser::_parseFlingDeclAlias() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclAlias);

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
auto Parser::_parseFlingScopedIdent() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingScopedIdent);

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
auto Parser::_parseFlingIdentList() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingIdentList);

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
auto Parser::_parseFlingSubprogIdentList() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingSubprogIdentList);

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
auto Parser::_parseFlingExprList() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingExprList);

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
auto Parser::_parseFlingRangeList() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingRangeList);

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
//auto Parser::_parseFlingExprOrRangeList() -> ParseRet
//{
//	PROLOGUE_AND_EPILOGUE(_parseFlingExprOrRangeList);
//
//	if (just_get_valid_tokens())
//	{
//		TokSet ret;
//
//		return ret;
//	}
//	else // if (!just_get_valid_tokens())
//	{
//		return std::nullopt;
//	}
//}
auto Parser::_parseFlingTypenmOrModnmList() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingTypenmOrModnmList);

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
auto Parser::_parseFlingImportItem() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingImportItem);

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
auto Parser::_parseFlingImportItemList() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingImportItemList);

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
auto Parser::_parseFlingExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingExpr);

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
auto Parser::_parseFlingMuxExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingMuxExpr);

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
auto Parser::_parseFlingLogorExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingLogorExpr);

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
auto Parser::_parseFlingLogandExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingLogandExpr);

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
auto Parser::_parseFlingCmpEqEtcExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingCmpEqEtcExpr);

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
auto Parser::_parseFlingCmpLtEtcExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingCmpLtEtcExpr);

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
auto Parser::_parseFlingPlusMinusExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingPlusMinusExpr);

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
auto Parser::_parseFlingMulDivModExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingMulDivModExpr);

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
auto Parser::_parseFlingBitorBitnorExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingBitorBitnorExpr);

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
auto Parser::_parseFlingBitandBitnandExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingBitandBitnandExpr);

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
auto Parser::_parseFlingBitxorBitxnorExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingBitxorBitxnorExpr);

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
auto Parser::_parseFlingBitshiftExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingBitshiftExpr);

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
auto Parser::_parseFlingUnaryExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingUnaryExpr);

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
auto Parser::_parseFlingLowExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingLowExpr);

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
auto Parser::_parseFlingCallDollarFuncExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingCallDollarFuncExpr);

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
auto Parser::_parseFlingCallSubprogExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingCallSubprogExpr);

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
auto Parser::_parseFlingSubprogIdent() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingSubprogIdent);

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
auto Parser::_parseFlingIdentExprStart() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingIdentExprStart);

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
auto Parser::_parseFlingIdentExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingIdentExpr);

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
auto Parser::_parseFlingCatExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingCatExpr);

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
auto Parser::_parseFlingReplExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingReplExpr);

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
auto Parser::_parseFlingSizedExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingSizedExpr);

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
auto Parser::_parseFlingRange() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingRange);

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
auto Parser::_parseFlingNonSimpleRange() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingNonSimpleRange);

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
auto Parser::_parseFlingSimpleRangeSuffix() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingSimpleRangeSuffix);

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
auto Parser::_parseFlingExprOrRange() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingExprOrRange);

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
auto Parser::_parseFlingTypenmOrModnmCstmChainItem() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingTypenmOrModnmCstmChainItem);

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
auto Parser::_parseFlingTypenmOrModnm() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingTypenmOrModnm);

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
		PROLOGUE_AND_EPILOGUE(parseTok##name); \
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
