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
auto Parser::_parse_flingDeclSubprog() -> ParseRet
{
	#define LIST(X) \
		X \
		( \
			_parse_flingDeclFuncHeader, \
			_parse_flingDeclTaskHeader \
		)

	if (just_get_valid_tokens())
	{
		return LIST(GET_VALID_TOK_SET)
			;
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclSubprog);
		DEFER_PUSH_NODE_AND_SET_TEMP(node, DeclSubprog);

		START_PARSE_IFELSE(LIST);

		JUST_PARSE_AND_POP_AST_NODE
			(node->scope, _parse_flingDeclSubprogScope);

		return std::nullopt;
	}
	#undef LIST
}
//--------

//--------
auto Parser::_parse_flingDeclFuncHeader() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclFuncHeader);

		if (_temp_ast->id() == "DeclSubprog")
		{
			auto node = static_cast<DeclSubprog*>(_temp_ast);

			node->kind = DeclSubprog::Kind::Func;

			EXPECT(KwFunc);

			EXPECT_IDENT_AND_GRAB_S(node->ident);

			PARSE_AND_POP_AST_NODE_IF
				(node->opt_param_list, _parse_flingDeclParamList);

			JUST_PARSE_AND_POP_AST_NODE
				(node->arg_list, _parse_flingDeclArgList);

			EXPECT(PunctColon);

			JUST_PARSE_AND_POP_AST_NODE
				(node->opt_ret_typenm, _parse_flingTypenm);
		}
		else
		{
			_pfs_internal_err();
		}

		return std::nullopt;
	}
}
auto Parser::_parse_flingDeclTaskHeader() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclFuncHeader);

		if (_temp_ast->id() == "DeclSubprog")
		{
			auto node = static_cast<DeclSubprog*>(_temp_ast);

			node->kind = DeclSubprog::Kind::Task;

			EXPECT(KwTask);

			EXPECT_IDENT_AND_GRAB_S(node->ident);

			PARSE_AND_POP_AST_NODE_IF
				(node->opt_param_list, _parse_flingDeclParamList);

			JUST_PARSE_AND_POP_AST_NODE
				(node->arg_list, _parse_flingDeclArgList);
		}
		else
		{
			_pfs_internal_err();
		}

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parse_flingDeclSubprogScope() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclSubprogScope);
		DEFER_PUSH_NODE(node, Scope);

		EXPECT(PunctLbrace);

		while (ATTEMPT_PARSE(_parse_flingDeclSubprogScopeItem))
		{
			node->item_list.push_back(_pop_ast_node());
		}

		EXPECT(PunctRbrace);

		return std::nullopt;
	}
}
auto Parser::_parse_flingDeclSubprogScopeItem() -> ParseRet
{
	#define LIST(X) \
		X \
		( \
			_parse_flingDeclSubprogScope, \
			\
			_parse_flingDeclSubprogScopeItemIf, \
			_parse_flingDeclSubprogScopeItemSwitchEtc, \
			_parse_flingDeclSubprogScopeItemFor, \
			_parse_flingDeclSubprogScopeItemWhile, \
			\
			_parse_flingDeclSubprogScopeItemGen, \
			\
			/* We need semantic analysis to determine whether or not */ \
			/* this item is a non-blocking assignment, which is banned */ \
			/* inside of a function. */ \
			_parse_flingAnyBehavScopeItem \
		)

	if (just_get_valid_tokens())
	{
		return LIST(GET_VALID_TOK_SET);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclSubprogScopeItem);

		START_PARSE_IFELSE(LIST);

		return std::nullopt;
	}

	#undef LIST
}
auto Parser::_parse_flingDeclSubprogScopeItemIf() -> ParseRet
{
	return _inner_parse_flingIf("_parse_flingDeclSubprogScopeItemIf",
		MEMB_FUNC(_parse_flingDeclSubprogScope));
}
auto Parser::_parse_flingDeclSubprogScopeItemSwitchEtc() -> ParseRet
{
	return _inner_parse_flingSwitchEtc
		("_parse_flingDeclSubprogScopeItemSwitchEtc",
		MEMB_FUNC(_parse_flingDeclSubprogScopeItemCase),
		MEMB_FUNC(_parse_flingDeclSubprogScopeItemDefault));
}
auto Parser::_parse_flingDeclSubprogScopeItemCase() -> ParseRet
{
	return _inner_parse_flingCase
		("_parse_flingDeclSubprogScopeItemCase",
		MEMB_FUNC(_parse_flingDeclSubprogScope));
}
auto Parser::_parse_flingDeclSubprogScopeItemDefault() -> ParseRet
{
	return _inner_parse_flingDefault
		("_parse_flingDeclSubprogScopeItemDefault",
		MEMB_FUNC(_parse_flingDeclSubprogScope));
}
auto Parser::_parse_flingDeclSubprogScopeItemFor() -> ParseRet
{
	return _inner_parse_flingFor
		("_parse_flingDeclSubprogScopeItemFor",
		MEMB_FUNC(_parse_flingDeclSubprogScope));
}
auto Parser::_parse_flingDeclSubprogScopeItemWhile() -> ParseRet
{
	return _inner_parse_flingWhile
		("_parse_flingDeclSubprogScopeItemWhile",
		MEMB_FUNC(_parse_flingDeclSubprogScope));
}
//--------

//--------
auto Parser::_parse_flingDeclSubprogScopeItemGen() -> ParseRet
{
	return _inner_parse_flingGen("_parse_flingDeclSubprogScopeItemGen",
		MEMB_FUNC(_parse_flingDeclSubprogScopeItemGenIf),
		MEMB_FUNC(_parse_flingDeclSubprogScopeItemGenSwitchEtc),
		MEMB_FUNC(_parse_flingDeclSubprogScopeItemGenFor));
}
auto Parser::_parse_flingDeclSubprogScopeItemGenIf() -> ParseRet
{
	return _inner_parse_flingGenIf
		("_parse_flingDeclSubprogScopeItemGenIf",
		MEMB_FUNC(_parse_flingDeclSubprogScope));
}
auto Parser::_parse_flingDeclSubprogScopeItemGenSwitchEtc() -> ParseRet
{
	return _inner_parse_flingGenSwitchEtc
		("_parse_flingDeclSubprogScopeItemGenSwitchEtc",
		MEMB_FUNC(_parse_flingDeclSubprogScopeItemGenCase),
		MEMB_FUNC(_parse_flingDeclSubprogScopeItemGenDefault));
}
auto Parser::_parse_flingDeclSubprogScopeItemGenCase() -> ParseRet
{
	return _inner_parse_flingGenCase
		("_parse_flingDeclSubprogScopeItemGenCase",
		MEMB_FUNC(_parse_flingDeclSubprogScope));
}
auto Parser::_parse_flingDeclSubprogScopeItemGenDefault() -> ParseRet
{
	return _inner_parse_flingGenDefault
		("_parse_flingDeclSubprogScopeItemGenDefault",
		MEMB_FUNC(_parse_flingDeclSubprogScope));
}
auto Parser::_parse_flingDeclSubprogScopeItemGenFor() -> ParseRet
{
	return _inner_parse_flingGenFor
		("_parse_flingDeclSubprogScopeItemGenFor",
		MEMB_FUNC(_parse_flingDeclSubprogScope));
}
//--------

} // namespace fling_hdl
