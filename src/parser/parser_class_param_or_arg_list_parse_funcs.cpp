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
auto Parser::_parse_flingDeclParamList() -> ParseRet
{
	#define LIST(X) \
		X \
		( \
			TOK_PARSE_FUNC(PunctCmpLt) \
		)
	if (just_get_valid_tokens())
	{
		return LIST(GET_VALID_TOK_SET);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclParamList);
		DEFER_PUSH_NODE(node, ParamOrArgList);

		START_PARSE_IFELSE(LIST);

		while (ATTEMPT_PARSE(_parse_flingDeclParamSublist))
		{
			auto sublist = _pop_ast_list();
			for (auto& item: sublist)
			{
				node->item_list.push_back(move(item.data));
			}

			// This also inserts PunctComma into `_wanted_tok_set`.
			if (!ATTEMPT_TOK_PARSE(PunctComma))
			{
				break;
			}
		}

		EXPECT(PunctCmpGt);

		return std::nullopt;
	}
	#undef LIST
}
auto Parser::_parse_flingDeclParamSublist() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingIdentList
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclParamSublist);
		DEFER_PUSH_LIST(sublist);

		IdentList ident_list;
		JUST_PARSE_AND_POP_IDENT_LIST(ident_list, _parse_flingIdentList);

		EXPECT(PunctColon);

		using Kind = DeclParamSublistItem::Kind;
		Kind kind = Kind::Var;
		BaseUptr opt_typenm;
		BaseUptrList opt_def_val_list;
		FilePos err_file_pos;

		if (ATTEMPT_PARSE(_parse_flingTypenm))
		{
			_pop_ast_node(opt_typenm);
			kind = Kind::Var;

			if (ATTEMPT_TOK_PARSE(PunctBlkAssign))
			{
				err_file_pos = lex_file_pos();
				JUST_PARSE_AND_POP_AST_LIST
					(opt_def_val_list, _parse_flingExprList);
			}
		}
		else if (ATTEMPT_TOK_PARSE(KwRange))
		{
			kind = Kind::Range;

			if (ATTEMPT_TOK_PARSE(PunctBlkAssign))
			{
				err_file_pos = lex_file_pos();
				JUST_PARSE_AND_POP_AST_LIST
					(opt_def_val_list, _parse_flingRangeList);
			}
		}
		else if (ATTEMPT_TOK_PARSE(KwType))
		{
			kind = Kind::Type;

			if (ATTEMPT_TOK_PARSE(PunctBlkAssign))
			{
				err_file_pos = lex_file_pos();

				JUST_PARSE_AND_POP_AST_LIST
					(opt_def_val_list, _parse_flingTypenmList);
			}
		}
		else if (ATTEMPT_TOK_PARSE(KwModule))
		{
			kind = Kind::Module;

			if (ATTEMPT_TOK_PARSE(PunctBlkAssign))
			{
				err_file_pos = lex_file_pos();

				JUST_PARSE_AND_POP_AST_LIST
					(opt_def_val_list, _parse_flingModnmList);
			}
		}
		else if (ATTEMPT_TOK_PARSE(KwFunc))
		{
			kind = Kind::Func;

			if (ATTEMPT_TOK_PARSE(PunctBlkAssign))
			{
				err_file_pos = lex_file_pos();

				JUST_PARSE_AND_POP_AST_LIST
					(opt_def_val_list, _parse_flingSubprogIdentList);
			}
		}
		else if (ATTEMPT_TOK_PARSE(KwTask))
		{
			kind = Kind::Task;

			if (ATTEMPT_TOK_PARSE(PunctBlkAssign))
			{
				err_file_pos = lex_file_pos();

				JUST_PARSE_AND_POP_AST_LIST
					(opt_def_val_list, _parse_flingSubprogIdentList);
			}
		}
		else
		{
			_expect_wanted_tok();
		}

		const auto err_msg = sconcat("Number of default values unequal ",
			"to number of parameters in sublist.");
		auto triple_vec = _build_pv_etc_vec(ident_list, opt_def_val_list,
			false, err_file_pos, err_msg);

		for (auto& triple: triple_vec)
		{
			using AstNodeType = DeclParamSublistItem;
			BaseUptr to_push(new AstNodeType(_curr_ast_parent,
				move(triple.ident_fp)));
			defer(_, sublist.push_back(move(to_push)););

			auto to_push_ptr = static_cast<AstNodeType*>(to_push.get());

			to_push_ptr->ident = move(triple.ident);
			to_push_ptr->kind = kind;

			if (opt_typenm)
			{
				to_push_ptr->opt_typenm = opt_typenm->dup
					(opt_typenm->parent());
			}

			to_push_ptr->opt_def_val = move(triple.rhs);
		}

		return std::nullopt;
	}
}
auto Parser::_parse_flingDeclArgList() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclArgList);
		DEFER_PUSH_NODE(node, ParamOrArgList);

		EXPECT(PunctLparen);

		while (ATTEMPT_PARSE(_parse_flingDeclArgSublist))
		{
			auto sublist = _pop_ast_list();

			for (auto& item: sublist)
			{
				node->item_list.push_back(move(item.data));
			}

			// This also inserts PunctComma into `_wanted_tok_set`.
			if (!ATTEMPT_TOK_PARSE(PunctComma))
			{
				break;
			}
		}

		EXPECT(PunctRparen);

		return std::nullopt;
	}
}
auto Parser::_parse_flingDeclArgSublist() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingIdentList
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclArgSublist);
		DEFER_PUSH_LIST(sublist);

		using AstNodeType = DeclArgSublistItem;
		using Kind = AstNodeType::Kind;

		IdentList ident_list;
		JUST_PARSE_AND_POP_IDENT_LIST(ident_list, _parse_flingIdentList);

		EXPECT(PunctColon);

		Kind kind = Kind::Input;

		if (ATTEMPT_TOK_PARSE(KwInput))
		{
			kind = Kind::Input;
		}
		else if (ATTEMPT_TOK_PARSE(KwOutput))
		{
			kind = Kind::Output;
		}
		else if (ATTEMPT_TOK_PARSE(KwInout))
		{
			kind = Kind::Inout;
		}
		else
		{
			_expect_wanted_tok();
		}

		BaseUptr typenm;
		JUST_PARSE_AND_POP_AST_NODE(typenm, _parse_flingTypenm);

		FilePos err_file_pos;
		BaseUptrList opt_def_val_list;

		if (ATTEMPT_TOK_PARSE(PunctBlkAssign))
		{
			err_file_pos = lex_file_pos();
			JUST_PARSE_AND_POP_AST_LIST
				(opt_def_val_list, _parse_flingExprList);
		}


		const auto err_msg = sconcat("Number of default values unequal ",
			"to number of parameters in sublist.");
		auto triple_vec = _build_pv_etc_vec(ident_list, opt_def_val_list,
			false, err_file_pos, err_msg);

		for (auto& triple: triple_vec)
		{
			BaseUptr to_push(new AstNodeType(_curr_ast_parent,
				triple.ident_fp));
			defer(_, sublist.push_back(move(to_push)););

			auto to_push_ptr = static_cast<AstNodeType*>(to_push.get());

			to_push_ptr->ident = move(triple.ident);
			to_push_ptr->kind = kind;

			to_push_ptr->typenm = typenm->dup(typenm->parent());

			to_push_ptr->opt_def_val = move(triple.rhs);
		}

		return std::nullopt;
	}
}
auto Parser::_parse_flingInstParamList() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingInstParamList);
		DEFER_PUSH_NODE(node, ParamOrArgList);

		EXPECT(PunctCmpLt);

		while (ATTEMPT_PARSE(_parse_flingInstParamListItem))
		{
			node->item_list.push_back(_pop_ast_node());

			if (!ATTEMPT_TOK_PARSE(PunctComma))
			{
				break;
			}
		}

		EXPECT(PunctCmpGt);

		return std::nullopt;
	}
}
auto Parser::_parse_flingInstParamListItem() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingInstParamListItemPos,
				_parse_flingInstParamListItemNamed
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingInstParamListItem);

		PARSE_IFELSE
		(
			_parse_flingInstParamListItemPos,
			_parse_flingInstParamListItemNamed
		)
		else
		{
			_expect_wanted_tok();
		}

		return std::nullopt;
	}
}
auto Parser::_parse_flingInstParamListItemPos() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingExprOrRange
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingInstParamListItemPos);

		PARSE_IFELSE
		(
			_parse_flingExprOrRange
		)
		else
		{
			_expect_wanted_tok();
		}

		return std::nullopt;
	}
}
auto Parser::_parse_flingInstParamListItemNamed() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingInstParamListItemNamed);

		DEFER_PUSH_NODE(node, StrAndNode);

		EXPECT(PunctMemberAccess);
		EXPECT_IDENT_AND_GRAB_S(node->str);

		if (ATTEMPT_TOK_PARSE(PunctMapTo))
		{
			JUST_PARSE_AND_POP_AST_NODE
				(node->node, _parse_flingInstParamListItemPos);
		}

		return std::nullopt;
	}
}
auto Parser::_parse_flingInstArgList() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingInstArgList);
		DEFER_PUSH_NODE(node, ParamOrArgList);

		EXPECT(PunctLparen);

		while (ATTEMPT_PARSE(_parse_flingInstArgListItem))
		{
			node->item_list.push_back(_pop_ast_node());

			if (!ATTEMPT_TOK_PARSE(PunctComma))
			{
				break;
			}
		}

		EXPECT(PunctRparen);

		return std::nullopt;
	}
}
auto Parser::_parse_flingInstArgListItem() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingInstArgListItemPos,
				_parse_flingInstArgListItemNamed
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingInstArgListItem);

		PARSE_IFELSE
		(
			_parse_flingInstArgListItemPos,
			_parse_flingInstArgListItemNamed
		)
		else
		{
			_expect_wanted_tok();
		}

		return std::nullopt;
	}
}
auto Parser::_parse_flingInstArgListItemPos() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingInstArgListItemPos);

		PARSE_IFELSE
		(
			_parse_flingExpr
		)
		else
		{
			_expect_wanted_tok();
		}

		return std::nullopt;
	}
}
auto Parser::_parse_flingInstArgListItemNamed() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingInstArgListItemNamed);

		DEFER_PUSH_NODE(node, StrAndNode);

		EXPECT(PunctMemberAccess);
		EXPECT_IDENT_AND_GRAB_S(node->str);

		if (ATTEMPT_TOK_PARSE(PunctMapTo))
		{
			JUST_PARSE_AND_POP_AST_NODE
				(node->node, _parse_flingInstArgListItemPos);
		}

		return std::nullopt;
	}
}
//--------
}
