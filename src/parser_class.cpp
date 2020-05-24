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
		MAKE_AST_NODE_AND_POP(to_push);
		_ast_program->item_list.push_back(move(to_push));
	}

	_expect_wanted_tok();

	return std::nullopt;
}
//--------

//--------
auto Parser::_parseFlingDeclPackage() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwPackage)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclPackage);
		DEFER_PUSH(node, DeclPackage);

		EXPECT(KwPackage);
		EXPECT_IDENT_AND_GRAB_S(node->ident);
		EXPECT(PunctLbrace);


		SUB_P_AND_E
		{
			INSERT_WANTED_TOK(PunctRbrace);

			while (ATTEMPT_PARSE_IFELSE(_parseFlingDeclPackageItem))
			{
				MAKE_AST_NODE_AND_POP(to_push);
				node->item_list.push_back(move(to_push));
			}

			_expect_wanted_tok();
		}

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclPackageItem() -> ParseRet
{

	#define LIST(X) \
		X \
		( \
			_parseFlingImport, \
			_parseFlingDeclConst, \
			\
			_parseFlingDeclAlias, \
			\
			_parseFlingDeclCompositeType, \
			_parseFlingDeclEnum, \
			\
			_parseFlingDeclSubprog, \
			\
			_parseFlingDeclPackage, \
			\
			_parseFlingDeclModule \
		)

	if (just_get_valid_tokens())
	{
		return LIST(GET_VALID_TOK_SET);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclPackageItem);

		LIST(PARSE_IFELSE)

		return std::nullopt;
	}

	#undef LIST
}
auto Parser::_parseFlingImport() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwImport)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingImport);
		DEFER_PUSH(node, Import);

		EXPECT(KwImport);
		JUST_PARSE_AND_POP_AST_LIST
			(node->item_list, _parseFlingImportItemList);
		EXPECT(PunctSemicolon);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclParamList() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctCmpLt)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclParamList);
		DEFER_PUSH(node, ParamOrArgList);

		EXPECT(PunctCmpLt);

		INSERT_WANTED_TOK(PunctCmpGt);

		bool found = false;
		while (ATTEMPT_PARSE_IFELSE(_parseFlingDeclParamSublist))
		{
			MAKE_AST_LIST_AND_POP(sublist);
			for (auto& item: sublist)
			{
				node->item_list.push_back(move(item.data));
			}

			// This also inserts PunctComma into `_wanted_tok_set`.
			if (!ATTEMPT_PARSE_IFELSE(PunctComma))
			{
				break;
			}
		}

		_expect_wanted_tok();

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclParamSublist() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingIdentList
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclParamSublist);
		DEFER_PUSH_LIST(sublist);

		StrList ident_list;
		JUST_PARSE_AND_POP_STR_LIST(ident_list, _parseFlingIdentList);

		EXPECT(PunctColon);

		SUB_P_AND_E
		{
			if (ATTEMPT_PARSE_IFELSE(_parseFlingTypenm))
			{
				MAKE_AST_NODE_AND_POP(typenm);
			}
			else if (ATTEMPT_PARSE_IFELSE(TOK_PARSE_FUNC(KwRange)))
			{
				SUB_P_AND_E
				{
					INSERT_WANTED_TOK(
				}
			}
			else if (ATTEMPT_PARSE_IFELSE(TOK_PARSE_FUNC(KwType)))
			{
			}
			else if (ATTEMPT_PARSE_IFELSE(TOK_PARSE_FUNC(KwModule)))
			{
			}
			else if (ATTEMPT_PARSE_IFELSE(TOK_PARSE_FUNC(KwFunc)))
			{
			}
			else if (ATTEMPT_PARSE_IFELSE(TOK_PARSE_FUNC(KwTask)))
			{
			}

			_expect_wanted_tok();
		}

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclArgList() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctLparen)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclArgList);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclArgSublist() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingIdentList
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclArgSublist);

		return std::nullopt;
	}
}
auto Parser::_parseFlingInstParamList() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctLparen)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingInstParamList);

		return std::nullopt;
	}
}
auto Parser::_parseFlingInstParamListItem() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingInstParamListItem);

		return std::nullopt;
	}
}
auto Parser::_parseFlingInstParamListItemPos() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingExprOrRange
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingInstParamListItemPos);

		return std::nullopt;
	}
}
auto Parser::_parseFlingInstParamListItemNamed() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctMemberAccess)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingInstParamListItemNamed);

		return std::nullopt;
	}
}
auto Parser::_parseFlingInstArgList() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctLparen)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingInstArgList);

		return std::nullopt;
	}
}
auto Parser::_parseFlingInstArgListItem() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingInstArgListItem);

		return std::nullopt;
	}
}
auto Parser::_parseFlingInstArgListItemPos() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingInstArgListItemPos);

		return std::nullopt;
	}
}
auto Parser::_parseFlingInstArgListItemNamed() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctMemberAccess)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingInstArgListItemNamed);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclModule() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwModule)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModule);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleScope() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctLbrace)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleScope);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleItem() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleItem);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingModinst() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwModinst)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingModinst);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclModuleGen() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleGen);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleGenIf() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenIf)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleGenIf);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleGenSwitchEtc() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleGenSwitchEtc);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleGenCase() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenCase)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleGenCase);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleGenDefault() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenDefault)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleGenDefault);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleGenFor() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenFor)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleGenFor);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclModuleBehav() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehav);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleBehavComb() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwComb)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavComb);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleBehavSeq() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwSeq)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavSeq);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleBehavSeqEdgeItem() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavSeqEdgeItem);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleBehavScope() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctLbrace)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScope);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleBehavScopeItem() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItem);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleBehavScopeItemIf() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET(TOK_PARSE_FUNC(KwIf));
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemIf);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleBehavScopeItemSwitchEtc() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemSwitchEtc);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleBehavScopeItemCase() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwCase)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemCase);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleBehavScopeItemDefault() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwDefault)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemDefault);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleBehavScopeItemFor() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET(TOK_PARSE_FUNC(KwFor));
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemFor);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleBehavScopeItemWhile() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET(TOK_PARSE_FUNC(KwWhile));
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemWhile);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclModuleBehavScopeItemGen() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemGen);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleBehavScopeItemGenIf() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenIf)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemGenIf);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleBehavScopeItemGenSwitchEtc() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemGenSwitchEtc);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleBehavScopeItemGenCase() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenCase)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemGenCase);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleBehavScopeItemGenDefault() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenDefault)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemGenDefault);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleBehavScopeItemGenFor() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenFor)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItemGenFor);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingAnyBehavScopeItem() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingAnyBehavScopeItem);

		return std::nullopt;
	}
}
auto Parser::_parseFlingAnyBehavScopeItemAssignSuffix() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingAnyBehavScopeItemAssignSuffix);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclCompositeType() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingDeclStruct
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclCompositeType);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclStruct() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwStruct)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclStruct);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclStructScope() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctLbrace)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclStructScope);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclStructScopeItem() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclStructScopeItem);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclStructScopeItemGen() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclStructScopeItemGen);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclStructScopeItemGenIf() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenIf)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclStructScopeItemGenIf);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclStructScopeItemGenSwitchEtc() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclStructScopeItemGenSwitchEtc);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclStructScopeItemGenCase() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenCase)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclStructScopeItemGenCase);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclStructScopeItemGenDefault() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenDefault)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclStructScopeItemGenDefault);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclStructScopeItemGenFor() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenFor)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclStructScopeItemGenFor);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclEnum() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwEnum)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclEnum);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclEnumItem() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(MiscIdent)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclEnumItem);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclSubprog() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprog);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclFuncHeader() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwFunc)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclFuncHeader);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclTaskHeader() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwTask)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclTaskHeader);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclSubprogScope() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctLbrace)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScope);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclSubprogScopeItem() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItem);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclSubprogScopeItemIf() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwIf)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemIf);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclSubprogScopeItemSwitchEtc() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemSwitchEtc);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclSubprogScopeItemCase() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwCase)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemCase);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclSubprogScopeItemDefault() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwDefault)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemDefault);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclSubprogScopeItemFor() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwFor)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemFor);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclSubprogScopeItemWhile() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwWhile)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemWhile);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclSubprogScopeItemGen() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemGen);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclSubprogScopeItemGenIf() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenIf)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemGenIf);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclSubprogScopeItemGenSwitchEtc() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemGenSwitchEtc);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclSubprogScopeItemGenCase() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenCase)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemGenCase);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclSubprogScopeItemGenDefault() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenDefault)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemGenDefault);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclSubprogScopeItemGenFor() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwGenFor)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclSubprogScopeItemGenFor);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingDeclConst() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwConst)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclConst);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclVarNoDefVal() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwVar)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclVarNoDefVal);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclVar() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwVar)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclVar);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclWire() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwWire)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclWire);

		return std::nullopt;
	}
}
auto Parser::_parseFlingWireAssign() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwAssign)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingWireAssign);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclAlias() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwAlias)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclAlias);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingScopedIdent() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(MiscIdent)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingScopedIdent);

		return std::nullopt;
	}
}
auto Parser::_parseFlingIdentList() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(MiscIdent)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingIdentList);

		return std::nullopt;
	}
}
auto Parser::_parseFlingSubprogIdentList() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingSubprogIdent
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingSubprogIdentList);

		return std::nullopt;
	}
}
auto Parser::_parseFlingExprList() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingExprList);

		return std::nullopt;
	}
}
auto Parser::_parseFlingRangeList() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingRange
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingRangeList);

		return std::nullopt;
	}
}
auto Parser::_parseFlingTypenmList() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingTypenm
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingTypenmList);

		return std::nullopt;
	}
}
auto Parser::_parseFlingModnmList() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingModnm
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingModnmList);

		return std::nullopt;
	}
}
auto Parser::_parseFlingImportItem() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(MiscIdent)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingImportItem);

		return std::nullopt;
	}
}
auto Parser::_parseFlingImportItemList() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingImportItem
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingImportItemList);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingMuxExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingExpr);

		return std::nullopt;
	}
}
auto Parser::_parseFlingMuxExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwMux),
				_parseFlingLogorExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingMuxExpr);

		return std::nullopt;
	}
}
auto Parser::_parseFlingLogorExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingLogandExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingLogorExpr);

		return std::nullopt;
	}
}
auto Parser::_parseFlingLogandExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingCmpEqEtcExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingLogandExpr);

		return std::nullopt;
	}
}
auto Parser::_parseFlingCmpEqEtcExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingCmpLtEtcExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingCmpEqEtcExpr);

		return std::nullopt;
	}
}
auto Parser::_parseFlingCmpLtEtcExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingPlusMinusExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingCmpLtEtcExpr);

		return std::nullopt;
	}
}
auto Parser::_parseFlingPlusMinusExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingMulDivModExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingPlusMinusExpr);

		return std::nullopt;
	}
}
auto Parser::_parseFlingMulDivModExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingBitorBitnorExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingMulDivModExpr);

		return std::nullopt;
	}
}
auto Parser::_parseFlingBitorBitnorExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingBitandBitnandExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingBitorBitnorExpr);

		return std::nullopt;
	}
}
auto Parser::_parseFlingBitandBitnandExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingBitxorBitxnorExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingBitandBitnandExpr);

		return std::nullopt;
	}
}
auto Parser::_parseFlingBitxorBitxnorExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingBitshiftExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingBitxorBitxnorExpr);

		return std::nullopt;
	}
}
auto Parser::_parseFlingBitshiftExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingUnaryExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingBitshiftExpr);

		return std::nullopt;
	}
}
auto Parser::_parseFlingUnaryExpr() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingUnaryExpr);

		return std::nullopt;
	}
}
auto Parser::_parseFlingLowExpr() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingLowExpr);

		return std::nullopt;
	}
}
auto Parser::_parseFlingCallDollarFuncExpr() -> ParseRet
{
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
		PROLOGUE_AND_EPILOGUE(_parseFlingCallDollarFuncExpr);

		return std::nullopt;
	}
}
auto Parser::_parseFlingSubprogIdent() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingIdentExprStart
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingSubprogIdent);

		return std::nullopt;
	}
}
auto Parser::_parseFlingAssignLhsIdentExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(MiscIdent)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingAssignLhsIdentExpr);

		return std::nullopt;
	}
}
auto Parser::_parseFlingAssignLhsCatExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwCat)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingAssignLhsCatExpr);

		return std::nullopt;
	}
}
auto Parser::_parseFlingIdentExprSuffix() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctMemberAccess),
				TOK_PARSE_FUNC(PunctLbracket),

				TOK_PARSE_FUNC(PunctVecDimStart)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingIdentExprSuffix);

		return std::nullopt;
	}
}
auto Parser::_parseFlingIdentExprStart() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(MiscIdent)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingIdentExprStart);

		return std::nullopt;
	}
}
auto Parser::_parseFlingIdentExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(MiscIdent)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingIdentExpr);

		return std::nullopt;
	}
}
auto Parser::_parseFlingCatExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwCat)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingCatExpr);

		return std::nullopt;
	}
}
auto Parser::_parseFlingReplExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwRepl)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingReplExpr);

		return std::nullopt;
	}
}
auto Parser::_parseFlingSizedExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwSized)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingSizedExpr);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingRange() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingNonSimpleRange,
				_parseFlingExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingRange);

		return std::nullopt;
	}
}
auto Parser::_parseFlingNonSimpleRange() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwDollarRange),
				TOK_PARSE_FUNC(KwRange)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingNonSimpleRange);

		return std::nullopt;
	}
}
auto Parser::_parseFlingSimpleRangeSuffix() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctRangeSeparator)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingSimpleRangeSuffix);

		return std::nullopt;
	}
}
auto Parser::_parseFlingExprOrRange() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingExpr,
				_parseFlingNonSimpleRange
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingExprOrRange);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parseFlingTypenmCstmChainItem() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctScopeAccess)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingTypenmCstmChainItem);

		return std::nullopt;
	}
}
auto Parser::_parseFlingTypenm() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingIdentExprStart,
				TOK_PARSE_FUNC(KwLogic),
				TOK_PARSE_FUNC(KwInteger)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingTypenm);

		return std::nullopt;
	}
}
auto Parser::_parseFlingModnm() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingScopedIdent
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingModnm);

		return std::nullopt;
	}
}
//--------

#define X(name, dummy_0) \
	auto Parser::_parseTok##name() -> ParseRet \
	{ \
		if (just_get_valid_tokens()) \
		{ \
			return TOK_SET(name); \
		} \
		else /* if (!just_get_valid_tokens()) */ \
		{ \
			PROLOGUE_AND_EPILOGUE(parseTok##name); \
			EXPECT(name); \
			return std::nullopt; \
		} \
	}
LIST_OF_TOKENS(X)
#undef X

} // namespace fling_hdl
