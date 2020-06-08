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
auto Parser::_parse_flingDeclConst() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclConst);
		DEFER_PUSH_NODE(node, DeclVarEtcList);

		EXPECT(KwConst);

		IdentList ident_list;
		JUST_PARSE_AND_POP_IDENT_LIST
			(ident_list, _parse_flingIdentList);

		EXPECT(PunctColon);

		BaseUptr typenm;
		JUST_PARSE_AND_POP_AST_NODE
			(typenm, _parse_flingTypenm);

		EXPECT(PunctBlkAssign);
		const auto err_file_pos = lex_file_pos();

		BaseUptrList expr_list;
		JUST_PARSE_AND_POP_AST_LIST
			(expr_list, _parse_flingExprList);

		const auto err_msg = sconcat("Number of values unequal to ",
			"number of names provided.");
		auto triple_vec = _build_pv_etc_vec(ident_list, expr_list, true,
			err_file_pos, err_msg);

		EXPECT(PunctSemicolon);

		for (auto& triple: triple_vec)
		{
			using AstNodeType = DeclVarEtc;
			BaseUptr to_push(new DeclVarEtc(_curr_ast_parent,
				move(triple.ident_fp)));
			defer(_, node->item_list.push_back(move(to_push)););

			auto to_push_ptr = static_cast<AstNodeType*>(to_push.get());

			to_push_ptr->kind = AstNodeType::Kind::Const;

			to_push_ptr->ident = move(triple.ident);
			to_push_ptr->typenm = typenm->dup(typenm->parent());
			to_push_ptr->val = move(triple.rhs);
		}

		return std::nullopt;
	}
}
auto Parser::_parse_flingDeclVarNoDefVal() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclVarNoDefVal);
		DEFER_PUSH_NODE(node, DeclVarEtcList);

		EXPECT(KwVar);

		IdentList ident_list;
		JUST_PARSE_AND_POP_IDENT_LIST
			(ident_list, _parse_flingIdentList);

		EXPECT(PunctColon);

		BaseUptr typenm;
		JUST_PARSE_AND_POP_AST_NODE
			(typenm, _parse_flingTypenm);

		EXPECT(PunctSemicolon);

		for (auto& p: ident_list)
		{
			using AstNodeType = DeclVarEtc;
			BaseUptr to_push(new AstNodeType(_curr_ast_parent,
				move(p.data.second)));
			defer(_, node->item_list.push_back(move(to_push)););

			auto to_push_ptr = static_cast<AstNodeType*>(to_push.get());

			to_push_ptr->kind = AstNodeType::Kind::Var;
			to_push_ptr->ident = move(p.data.first);
			to_push_ptr->typenm = typenm->dup(typenm->parent());
		}

		return std::nullopt;
	}
}
auto Parser::_parse_flingDeclVar() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclVar);
		DEFER_PUSH_NODE(node, DeclVarEtcList);

		EXPECT(KwVar);

		IdentList ident_list;
		JUST_PARSE_AND_POP_IDENT_LIST
			(ident_list, _parse_flingIdentList);

		EXPECT(PunctColon);

		BaseUptr typenm;

		FilePos err_file_pos;
		BaseUptrList expr_list;
		if (ATTEMPT_TOK_PARSE(PunctBlkAssign))
		{
			err_file_pos = lex_file_pos();
			JUST_PARSE_AND_POP_AST_LIST
				(expr_list, _parse_flingExprList);
		}

		const auto err_msg = sconcat("Number of values unequal to ",
			"number of names provided.");
		auto triple_vec = _build_pv_etc_vec(ident_list, expr_list, false,
			err_file_pos, err_msg);

		EXPECT(PunctSemicolon);

		for (auto& triple: triple_vec)
		{
			using AstNodeType = DeclVarEtc;
			BaseUptr to_push(new DeclVarEtc(_curr_ast_parent,
				move(triple.ident_fp)));
			defer(_, node->item_list.push_back(move(to_push)););

			auto to_push_ptr = static_cast<AstNodeType*>(to_push.get());

			to_push_ptr->kind = AstNodeType::Kind::Var;
			to_push_ptr->ident = move(triple.ident);
			to_push_ptr->typenm = typenm->dup(typenm->parent());
			to_push_ptr->val = move(triple.rhs);
		}

		return std::nullopt;
	}
}
auto Parser::_parse_flingDeclWire() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclVar);
		DEFER_PUSH_NODE(node, DeclVarEtcList);

		EXPECT(KwWire);

		IdentList ident_list;
		JUST_PARSE_AND_POP_IDENT_LIST
			(ident_list, _parse_flingIdentList);

		EXPECT(PunctColon);

		BaseUptr typenm;

		FilePos err_file_pos;
		BaseUptrList expr_list;
		if (ATTEMPT_TOK_PARSE(PunctBlkAssign))
		{
			err_file_pos = lex_file_pos();
			JUST_PARSE_AND_POP_AST_LIST
				(expr_list, _parse_flingExprList);
		}

		const auto err_msg = sconcat("Number of values unequal to ",
			"number of names provided.");
		auto triple_vec = _build_pv_etc_vec(ident_list, expr_list, false,
			err_file_pos, err_msg);

		EXPECT(PunctSemicolon);

		for (auto& triple: triple_vec)
		{
			using AstNodeType = DeclVarEtc;
			BaseUptr to_push(new DeclVarEtc(_curr_ast_parent,
				move(triple.ident_fp)));
			defer(_, node->item_list.push_back(move(to_push)););

			auto to_push_ptr = static_cast<AstNodeType*>(to_push.get());

			to_push_ptr->kind = AstNodeType::Kind::Wire;
			to_push_ptr->ident = move(triple.ident);
			to_push_ptr->typenm = typenm->dup(typenm->parent());
			to_push_ptr->val = move(triple.rhs);
		}

		return std::nullopt;
	}
}
auto Parser::_parse_flingWireAssign() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingWireAssign);
		DEFER_PUSH_NODE(node, WireAssign);

		EXPECT(KwAssign);

		PARSE_IFELSE
		(
			_parse_flingAssignLhsIdentExpr,
			_parse_flingAssignLhsCatExpr
		)
		else
		{
			_expect_wanted_tok();
		}
		node->lhs = _pop_ast_node();

		EXPECT(PunctBlkAssign);

		JUST_PARSE_AND_POP_AST_NODE
			(node->rhs, _parse_flingExpr);

		EXPECT(PunctSemicolon);

		return std::nullopt;
	}
}
auto Parser::_parse_flingDeclAlias() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclAlias);
		DEFER_PUSH_NODE(node, DeclAliasList);

		using AstNodeType = DeclAlias;

		EXPECT(KwAlias);

		IdentList ident_list;
		JUST_PARSE_AND_POP_IDENT_LIST
			(ident_list, _parse_flingIdentList);

		EXPECT(PunctColon);

		using Kind = AstNodeType::Kind;
		Kind kind = Kind::Var;
		BaseUptr opt_typenm;
		BaseUptrList rhs_list;
		FilePos err_file_pos;

		if (ATTEMPT_PARSE(_parse_flingTypenm))
		{
			_pop_ast_node(opt_typenm);
			kind = Kind::Var;

			err_file_pos = lex_file_pos();
			JUST_PARSE_AND_POP_AST_LIST
				(rhs_list, _parse_flingExprList);
		}
		else if (ATTEMPT_TOK_PARSE(KwRange))
		{
			kind = Kind::Range;

			err_file_pos = lex_file_pos();
			JUST_PARSE_AND_POP_AST_LIST
				(rhs_list, _parse_flingRangeList);
		}
		else if (ATTEMPT_TOK_PARSE(KwType))
		{
			kind = Kind::Type;

			err_file_pos = lex_file_pos();

			JUST_PARSE_AND_POP_AST_LIST
				(rhs_list, _parse_flingTypenmList);
		}
		else if (ATTEMPT_TOK_PARSE(KwModule))
		{
			kind = Kind::Module;

			err_file_pos = lex_file_pos();

			JUST_PARSE_AND_POP_AST_LIST
				(rhs_list, _parse_flingModnmList);
		}
		else if (ATTEMPT_TOK_PARSE(KwFunc))
		{
			kind = Kind::Func;

			err_file_pos = lex_file_pos();

			JUST_PARSE_AND_POP_AST_LIST
				(rhs_list, _parse_flingSubprogIdentList);
		}
		else if (ATTEMPT_TOK_PARSE(KwTask))
		{
			kind = Kind::Task;

			err_file_pos = lex_file_pos();

			JUST_PARSE_AND_POP_AST_LIST
				(rhs_list, _parse_flingSubprogIdentList);
		}
		else
		{
			_expect_wanted_tok();
		}

		const auto err_msg = sconcat("Number of identifiers unequal to ",
			"number of values.");
		auto triple_vec = _build_pv_etc_vec(ident_list, rhs_list, true,
			err_file_pos, err_msg);

		for (auto& triple: triple_vec)
		{
			BaseUptr to_push(new AstNodeType(_curr_ast_parent,
				move(triple.ident_fp)));
			defer(_, node->item_list.push_back(move(to_push)););

			auto to_push_ptr = static_cast<AstNodeType*>(to_push.get());

			to_push_ptr->ident = move(triple.ident);
			to_push_ptr->kind = kind;

			if (opt_typenm)
			{
				to_push_ptr->opt_typenm = opt_typenm->dup
					(opt_typenm->parent());
			}

			to_push_ptr->rhs = move(triple.rhs);
		}

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parse_flingIdentList() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingIdentList);
		DEFER_PUSH_IDENT_LIST(ident_list);

		do
		{
			pair<string, FilePos> to_push;
			defer(_, ident_list.push_back(move(to_push)););

			to_push.second = lex_file_pos();

			EXPECT_IDENT_AND_GRAB_S(to_push.first);
		} while (ATTEMPT_TOK_PARSE(PunctComma));

		return std::nullopt;
	}
}
auto Parser::_parse_flingSubprogIdentList() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingIdentExprStart
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingSubprogIdentList);
		DEFER_PUSH_LIST(list);

		do
		{
			_parse_flingIdentExprStart();
			list.push_back(_pop_ast_node());
		} while (ATTEMPT_TOK_PARSE(PunctComma));

		return std::nullopt;
	}
}
auto Parser::_parse_flingExprList() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingExprList);
		DEFER_PUSH_LIST(list);

		do
		{
			_parse_flingExpr();
			list.push_back(_pop_ast_node());
		} while (ATTEMPT_TOK_PARSE(PunctComma));

		return std::nullopt;
	}
}
auto Parser::_parse_flingRangeList() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingRange
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingRangeList);
		DEFER_PUSH_LIST(list);

		do
		{
			_parse_flingRange();
			list.push_back(_pop_ast_node());
		} while (ATTEMPT_TOK_PARSE(PunctComma));

		return std::nullopt;
	}
}
auto Parser::_parse_flingTypenmList() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingTypenm
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingTypenmList);
		DEFER_PUSH_LIST(list);

		do
		{
			_parse_flingTypenm();
			list.push_back(_pop_ast_node());
		} while (ATTEMPT_TOK_PARSE(PunctComma));

		return std::nullopt;
	}
}
auto Parser::_parse_flingModnmList() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingModnm
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingModnmList);
		DEFER_PUSH_LIST(list);

		do
		{
			_parse_flingModnm();
			list.push_back(_pop_ast_node());
		} while (ATTEMPT_TOK_PARSE(PunctComma));

		return std::nullopt;
	}
}
auto Parser::_parse_flingImportItem() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingImportItem);
		DEFER_PUSH_NODE(node, ImportItem);

		node->ends_with_all = false;

		{
			string ident;
			defer(_, node->ident_list.push_back(move(ident)););
			EXPECT_IDENT_AND_GRAB_S(ident);
		}

		while (ATTEMPT_TOK_PARSE(PunctScopeAccess))
		{
			if (ATTEMPT_TOK_PARSE(MiscIdent))
			{
				node->ident_list.push_back(prev_lex_s());
			}
			else if (ATTEMPT_TOK_PARSE(KwAll))
			{
				node->ends_with_all = true;
				break;
			}
			else
			{
				_expect_wanted_tok();
			}
		}

		return std::nullopt;
	}
}
auto Parser::_parse_flingImportItemList() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingImportItem
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingImportItemList);
		DEFER_PUSH_LIST(list);

		do
		{
			_parse_flingImportItem();
			list.push_back(_pop_ast_node());
		} while (ATTEMPT_TOK_PARSE(PunctComma));

		return std::nullopt;
	}
}
//--------

} // namespace fling_hdl
