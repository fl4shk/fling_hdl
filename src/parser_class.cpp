#include "parser_class.hpp"
#include "liborangepower_src/cpp_magic.hpp"

namespace fling_hdl
{

using namespace ast;

#include "parser_class_defines.hpp"

//--------
Parser::Parser(const string& s_filename)
	: ParserBase(s_filename)
{
}
int Parser::run()
{
	_max_ast_level = 0;
	_ast_program = make_ast(Program);
	_ast.reset(_ast_program);
	_parseFlingProgram();
	return 0;
}
//--------

//--------
auto Parser::_parseFlingProgram() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingProgram);

	INSERT_WANTED_TOK(MiscEof);

	while (ATTEMPT_PARSE(_parseFlingDeclPackageItem))
	{
		BaseSptr to_push;
		_pop_ast(to_push);
		_ast_program->item_list.push_back(move(to_push));
	}

	_expect_wanted_tok();

	return std::nullopt;
}
//--------

//--------
auto Parser::_parseFlingDeclPackage() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclPackage);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwPackage)
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingImport,
				_parseFlingDeclConst,

				_parseFlingDeclAlias,

				_parseFlingDeclCompositeType,
				_parseFlingDeclEnum,

				_parseFlingDeclSubprog,

				_parseFlingDeclPackage,

				_parseFlingDeclModule
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwImport)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclParamList() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclParamList);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctCmpLt)
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingIdentList
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctLparen)
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingIdentList
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctLparen)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::_parseFlingInstParamListItem() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingInstParamListItem);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingInstParamListItemPos,
				_parseFlingInstParamListItemNamed
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::_parseFlingInstParamListItemPos() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingInstParamListItemPos);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingExprOrRange
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::_parseFlingInstParamListItemNamed() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingInstParamListItemNamed);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctMemberAccess)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctLparen)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::_parseFlingInstArgListItem() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingInstArgListItem);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingInstArgListItemPos,
				_parseFlingInstArgListItemNamed
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::_parseFlingInstArgListItemPos() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingInstArgListItemPos);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::_parseFlingInstArgListItemNamed() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingInstArgListItemNamed);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctMemberAccess)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclModule() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModule);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwModule)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctLbrace)
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingModinst,

				_parseFlingImport,

				_parseFlingDeclConst,
				_parseFlingDeclVar,
				_parseFlingDeclWire,

				_parseFlingWireAssign,

				_parseFlingDeclAlias,

				_parseFlingDeclCompositeType,
				_parseFlingDeclEnum,

				_parseFlingDeclSubprog,

				_parseFlingDeclModuleGen,
				_parseFlingDeclModuleBehav
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingModinst() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingModinst);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwModinst)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclModuleGen() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleGen);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingDeclModuleGenIf,
				_parseFlingDeclModuleGenSwitchEtc,
				_parseFlingDeclModuleGenFor
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenIf)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenSwitch),
				TOK_PARSE_FUNC(KwGenSwitchz)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenCase)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenDefault)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenFor)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclModuleBehav() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehav);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingDeclModuleBehavComb,
				_parseFlingDeclModuleBehavSeq
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwComb)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwSeq)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwPosedge),
				TOK_PARSE_FUNC(KwNegedge)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctLbrace)
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingDeclModuleBehavScope,

				_parseFlingDeclModuleBehavScopeItemIf,
				_parseFlingDeclModuleBehavScopeItemSwitchEtc,
				_parseFlingDeclModuleBehavScopeItemFor,
				_parseFlingDeclModuleBehavScopeItemWhile,

				_parseFlingDeclModuleBehavScopeItemGen,

				_parseFlingAnyBehavScopeItem
			);
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
		return GET_VALID_TOK_SET(TOK_PARSE_FUNC(KwIf));
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwSwitch),
				TOK_PARSE_FUNC(KwSwitchz)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwCase)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwDefault)
			);
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
		return GET_VALID_TOK_SET(TOK_PARSE_FUNC(KwFor));
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
		return GET_VALID_TOK_SET(TOK_PARSE_FUNC(KwWhile));
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclModuleBehavScopeItemGen() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemGen);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingDeclModuleBehavScopeItemGenIf,
				_parseFlingDeclModuleBehavScopeItemGenSwitchEtc,
				_parseFlingDeclModuleBehavScopeItemGenFor,
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenIf)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenSwitch),
				TOK_PARSE_FUNC(KwGenSwitchz)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenCase)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenDefault)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenFor)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingAnyBehavScopeItem() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingAnyBehavScopeItem);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingDeclConst,
				_parseFlingDeclVar,

				_parseFlingDeclCompositeType,
				_parseFlingDeclEnum,

				_parseFlingDeclSubprog,

				TOK_PARSE_FUNC(MiscIdent),
				_parseFlingAssignLhsCatExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::_parseFlingAnyBehavScopeItemAssignSuffix() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingAnyBehavScopeItemAssignSuffix);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctBlkAssign),
				TOK_PARSE_FUNC(PunctNonBlkAssign)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclCompositeType() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclCompositeType);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingDeclStruct
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclStruct() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclStruct);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwStruct)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctLbrace)
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingImport,

				_parseFlingDeclConst,
				_parseFlingDeclVarNoDefVal,

				_parseFlingDeclAlias,

				_parseFlingDeclCompositeType,
				_parseFlingDeclEnum,

				_parseFlingDeclStructScopeItemGen
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclStructScopeItemGen() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclStructScopeItemGen);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingDeclModuleBehavScopeItemGenIf,
				_parseFlingDeclModuleBehavScopeItemGenSwitchEtc,
				_parseFlingDeclModuleBehavScopeItemGenFor,
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenIf)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenSwitch),
				TOK_PARSE_FUNC(KwGenSwitchz)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenCase)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenDefault)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenFor)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclEnum() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclEnum);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwEnum)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(MiscIdent)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclSubprog() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprog);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingDeclFuncHeader,
				_parseFlingDeclTaskHeader
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclFuncHeader() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclFuncHeader);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwFunc)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwTask)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclSubprogScope() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScope);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctLbrace)
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingDeclSubprogScope,

				_parseFlingDeclSubprogScopeItemIf,
				_parseFlingDeclSubprogScopeItemSwitchEtc,
				_parseFlingDeclSubprogScopeItemFor,
				_parseFlingDeclSubprogScopeItemWhile,

				_parseFlingDeclSubprogScopeItemGen,

				// We need semantic analysis to determine whether or not
				// this item is a non-blocking assignment, which is banned
				// inside of a function.
				_parseFlingAnyBehavScopeItem
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwIf)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwSwitch),
				TOK_PARSE_FUNC(KwSwitchz)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwCase)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwDefault)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwFor)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwWhile)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclSubprogScopeItemGen() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemGen);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingDeclSubprogScopeItemGenIf,
				_parseFlingDeclSubprogScopeItemGenSwitchEtc,
				_parseFlingDeclSubprogScopeItemGenFor
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenIf)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenSwitch),
				TOK_PARSE_FUNC(KwGenSwitchz)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenCase)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenDefault)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenFor)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclConst() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingDeclConst);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwConst)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwVar)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwVar)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwWire)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwAssign)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwAlias)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingScopedIdent() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingScopedIdent);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(MiscIdent)
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(MiscIdent)
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingSubprogIdent
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingExpr
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingRange
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::_parseFlingTypenmList() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingTypenmList);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingTypenm
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::_parseFlingModnmList() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingModnmList);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingModnm
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(MiscIdent)
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingImportItem
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingExpr);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				flingMuxExpr
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwMux)
				| _parseFlingLogorExpr
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingLogandExpr
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingCmpEqEtcExpr
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingCmpLtEtcExpr
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingPlusMinusExpr
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingMulDivModExpr
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingBitorBitnorExpr
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingBitandBitnandExpr
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingBitxorBitxnorExpr
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingBitshiftExpr
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingUnaryExpr
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctPlus),
				TOK_PARSE_FUNC(PunctMinus),

				TOK_PARSE_FUNC(PunctBitnot),
				TOK_PARSE_FUNC(PunctLognot),

				TOK_PARSE_FUNC(PunctBitor),
				TOK_PARSE_FUNC(PunctBitnor),

				TOK_PARSE_FUNC(PunctBitand),
				TOK_PARSE_FUNC(PunctBitnand),

				TOK_PARSE_FUNC(PunctBitxor),
				TOK_PARSE_FUNC(PunctBitxnor),

				_parseFlingLowExpr
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(LitDecNum),
				TOK_PARSE_FUNC(LitHexNum),
				TOK_PARSE_FUNC(LitOctNum),
				TOK_PARSE_FUNC(LitBinNum),

				TOK_PARSE_FUNC(KwHighImped),
				TOK_PARSE_FUNC(KwUnkn),

				TOK_PARSE_FUNC(PunctLparen),

				_parseFlingCallDollarFuncExpr,

				_parseFlingIdentExpr,

				_parseFlingCatExpr,
				_parseFlingReplExpr,
				_parseFlingSizedExpr
			);
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
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwDollarSize),
				TOK_PARSE_FUNC(KwDollarHigh),
				TOK_PARSE_FUNC(KwDollarLow),

				TOK_PARSE_FUNC(KwDollarUnsigned),
				TOK_PARSE_FUNC(KwDollarSigned),

				TOK_PARSE_FUNC(KwDollarIsUnsigned),
				TOK_PARSE_FUNC(KwDollarIsSigned),

				TOK_PARSE_FUNC(KwDollarPow)
			);
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
		return GET_VALID_TOK_SET
			(
				_parseFlingIdentExprStart
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::_parseFlingAssignLhsIdentExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingAssignLhsIdentExpr);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(MiscIdent)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::_parseFlingAssignLhsCatExpr() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingAssignLhsCatExpr);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwCat)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::_parseFlingIdentExprSuffix() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingIdentExprSuffix);

	if (just_get_valid_tokens())
	{
		//return GET_VALID_TOK_SET
		//	(
		//	);
		_internal_err
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
		return GET_VALID_TOK_SET
			(
			);
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
		return GET_VALID_TOK_SET
			(
			);
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
		return GET_VALID_TOK_SET
			(
			);
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
		return GET_VALID_TOK_SET
			(
			);
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
		return GET_VALID_TOK_SET
			(
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingRange() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingRange);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
			);
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
		return GET_VALID_TOK_SET
			(
			);
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
		return GET_VALID_TOK_SET
			(
			);
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
		return GET_VALID_TOK_SET
			(
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingTypenmCstmChainItem() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingTypenmCstmChainItem);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::_parseFlingTypenm() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingTypenm);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
auto Parser::_parseFlingModnm() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingModnm);

	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
			);
	}
	else // if (!just_get_valid_tokens())
	{
		return std::nullopt;
	}
}
//--------

#define X(name, dummy_0) \
	auto Parser::_parseTok##name() -> ParseRet \
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
