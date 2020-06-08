// This file is part of Fling HDL.
//
// Copyright 2020 Andrew Clark (FL4SHK)
//
// Fling HDL is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Fling HDL is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Fling HDL.  If not, see <https://www.gnu.org/licenses/>.

#include "parser_class.hpp"
#include "../liborangepower_src/metaprog_defines.hpp"
#include "parser_class_defines.hpp"

namespace fling_hdl
{

using namespace ast;

//--------
auto Parser::_parse_flingDeclCompositeType() -> ParseRet
{
	#define LIST(X) \
		X \
		( \
			_parse_flingDeclStruct \
		)

	if (just_get_valid_tokens())
	{
		return LIST(GET_VALID_TOK_SET);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclCompositeType);

		START_PARSE_IFELSE(LIST);

		return std::nullopt;
	}

	#undef LIST
}
//--------

//--------
auto Parser::_parse_flingDeclStruct() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclStruct);
		DEFER_PUSH_NODE(node, DeclStruct);

		EXPECT(KwStruct);

		node->is_packed = ATTEMPT_TOK_PARSE(KwPacked);
		node->is_signed = false;
		if (node->is_packed)
		{
			node->is_signed = ATTEMPT_TOK_PARSE(KwSigned);
		}
		EXPECT_IDENT_AND_GRAB_S(node->ident);

		PARSE_AND_POP_AST_NODE_IF
			(node->opt_param_list, _parse_flingDeclParamList);

		JUST_PARSE_AND_POP_AST_NODE
			(node->scope, _parse_flingDeclStructScope);

		return std::nullopt;
	}
}
auto Parser::_parse_flingDeclStructScope() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclStructScope);
		DEFER_PUSH_NODE(node, Scope);

		EXPECT(PunctLbrace);

		while (ATTEMPT_PARSE(_parse_flingDeclStructScopeItem))
		{
			node->item_list.push_back(_pop_ast_node());
		}

		EXPECT(PunctRbrace);

		return std::nullopt;
	}
}
auto Parser::_parse_flingDeclStructScopeItem() -> ParseRet
{
	#define LIST(X) \
		X \
		( \
			_parse_flingImport, \
			\
			_parse_flingDeclConst, \
			_parse_flingDeclVarNoDefVal, \
			\
			_parse_flingDeclAlias, \
			\
			_parse_flingDeclCompositeType, \
			_parse_flingDeclEnum, \
			\
			_parse_flingDeclStructScopeItemGen \
		)

	if (just_get_valid_tokens())
	{
		return LIST(GET_VALID_TOK_SET);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclStructScopeItem);

		START_PARSE_IFELSE(LIST);

		return std::nullopt;
	}

	#undef LIST
}
//--------

//--------
auto Parser::_parse_flingDeclStructScopeItemGen() -> ParseRet
{
	return _inner_parse_flingGen("_parse_flingDeclStructScopeItemGen",
		MEMB_FUNC(_parse_flingDeclStructScopeItemGenIf),
		MEMB_FUNC(_parse_flingDeclStructScopeItemGenSwitchEtc),
		MEMB_FUNC(_parse_flingDeclStructScopeItemGenFor));
}
auto Parser::_parse_flingDeclStructScopeItemGenIf() -> ParseRet
{
	return _inner_parse_flingGenIf
		("_parse_flingDeclStructScopeItemGenIf",
		MEMB_FUNC(_parse_flingDeclStructScope));
}
auto Parser::_parse_flingDeclStructScopeItemGenSwitchEtc() -> ParseRet
{
	return _inner_parse_flingGenSwitchEtc
		("_parse_flingDeclStructScopeItemGenSwitchEtc",
		MEMB_FUNC(_parse_flingDeclStructScopeItemGenCase),
		MEMB_FUNC(_parse_flingDeclStructScopeItemGenDefault));
}
auto Parser::_parse_flingDeclStructScopeItemGenCase() -> ParseRet
{
	return _inner_parse_flingGenCase
		("_parse_flingDeclStructScopeItemGenCase",
		MEMB_FUNC(_parse_flingDeclStructScope));
}
auto Parser::_parse_flingDeclStructScopeItemGenDefault() -> ParseRet
{
	return _inner_parse_flingGenDefault
		("_parse_flingDeclStructScopeItemGenDefault",
		MEMB_FUNC(_parse_flingDeclStructScope));
}
auto Parser::_parse_flingDeclStructScopeItemGenFor() -> ParseRet
{
	return _inner_parse_flingGenFor
		("_parse_flingDeclStructScopeItemGenFor",
		MEMB_FUNC(_parse_flingDeclStructScope));
}
//--------

//--------
auto Parser::_parse_flingDeclEnum() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclEnum);
		DEFER_PUSH_NODE(node, DeclEnum);

		EXPECT(KwEnum);

		EXPECT_IDENT_AND_GRAB_S(node->ident);

		if (ATTEMPT_TOK_PARSE(PunctColon))
		{
			JUST_PARSE_AND_POP_AST_NODE
				(node->opt_typenm, _parse_flingTypenm);
		}

		EXPECT(PunctLbrace);

		while (ATTEMPT_PARSE(_parse_flingDeclEnumItem))
		{
			node->item_list.push_back(_pop_ast_node());

			if (!ATTEMPT_TOK_PARSE(PunctComma))
			{
				break;
			}
		}

		EXPECT(PunctRbrace);

		return std::nullopt;
	}
}
auto Parser::_parse_flingDeclEnumItem() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclEnumItem);
		DEFER_PUSH_NODE(node, StrAndNode);

		EXPECT_IDENT_AND_GRAB_S(node->str);

		if (ATTEMPT_TOK_PARSE(PunctBlkAssign))
		{
			JUST_PARSE_AND_POP_AST_NODE
				(node->node, _parse_flingExpr);
		}

		return std::nullopt;
	}
}
//--------

} // namespace fling_hdl
