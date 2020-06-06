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
	_parse_flingProgram();
	return 0;
}
//--------

//--------
auto Parser::_build_pv_etc_vec(IdentList& ident_list,
	BaseUptrList& rhs_list, bool force_build_expr,
	const FilePos& err_file_pos, const string& err_msg) 
	const -> vector<ParamVarEtcTriple>
{
	vector<ParamVarEtcTriple> ret;

	for (auto& p: ident_list)
	{
		ParamVarEtcTriple to_push;
		defer(_, ret.push_back(move(to_push)););

		// It's okay to do a `move` here because we don't need
		// to keep `ident_list` itself around.
		to_push.ident = move(p.data.first);
		to_push.ident_fp = move(p.data.second);
	}

	if (force_build_expr || (rhs_list.size() > 0))
	{
		if (ident_list.size() != rhs_list.size())
		{
			_err(err_file_pos, err_msg);
		}

		size_t i = 0;
		for (auto& p: rhs_list)
		{
			ret.at(i).rhs = move(p.data);
			++i;
		}
	}

	return ret;
}
//--------

//--------
auto Parser::_parse_flingProgram() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parse_flingProgram);

	while (ATTEMPT_PARSE(_parse_flingDeclPackageItem))
	{
		_ast_program->item_list.push_back(_pop_ast_node());
	}

	EXPECT(MiscEof);

	return std::nullopt;
}
//--------

//--------
auto Parser::_parse_flingDeclPackage() -> ParseRet
{
	#define LIST(X) \
		X \
		( \
			TOK_PARSE_FUNC(KwPackage) \
		)

	if (just_get_valid_tokens())
	{
		return LIST(GET_VALID_TOK_SET);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclPackage);
		DEFER_PUSH_NODE(node, DeclPackage);

		START_PARSE_IFELSE(LIST);

		EXPECT_IDENT_AND_GRAB_S(node->ident);
		EXPECT(PunctLbrace);


		while (ATTEMPT_PARSE(_parse_flingDeclPackageItem))
		{
			node->item_list.push_back(_pop_ast_node());
		}

		EXPECT(PunctRbrace);

		return std::nullopt;
	}

	#undef LIST
}
auto Parser::_parse_flingDeclPackageItem() -> ParseRet
{
	#define LIST(X) \
		X \
		( \
			_parse_flingImport, \
			_parse_flingDeclConst, \
			\
			_parse_flingDeclAlias, \
			\
			_parse_flingDeclCompositeType, \
			_parse_flingDeclEnum, \
			\
			_parse_flingDeclSubprog, \
			\
			_parse_flingDeclPackage, \
			\
			_parse_flingDeclModule \
		)

	if (just_get_valid_tokens())
	{
		return LIST(GET_VALID_TOK_SET);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclPackageItem);

		START_PARSE_IFELSE(LIST);

		return std::nullopt;
	}

	#undef LIST
}
auto Parser::_parse_flingImport() -> ParseRet
{
	#define LIST(X) \
		X \
		( \
			TOK_PARSE_FUNC(KwImport) \
		)
	if (just_get_valid_tokens())
	{
		return LIST(GET_VALID_TOK_SET);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingImport);
		DEFER_PUSH_NODE(node, Import);

		START_PARSE_IFELSE(LIST);

		JUST_PARSE_AND_POP_AST_LIST
			(node->item_list, _parse_flingImportItemList);
		EXPECT(PunctSemicolon);

		return std::nullopt;
	}

	#undef LIST
}
//--------

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

//--------
auto Parser::_parse_flingDeclModule() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclModule);
		DEFER_PUSH_NODE(node, DeclModule);

		EXPECT(KwModule);
		EXPECT_IDENT_AND_GRAB_S(node->ident);

		PARSE_AND_POP_AST_NODE_IF
			(node->opt_param_list, _parse_flingDeclParamList);

		JUST_PARSE_AND_POP_AST_NODE
			(node->arg_list, _parse_flingDeclArgList);

		JUST_PARSE_AND_POP_AST_NODE
			(node->scope, _parse_flingDeclModuleScope);

		return std::nullopt;
	}
}
auto Parser::_parse_flingDeclModuleScope() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclModuleScope);
		DEFER_PUSH_NODE(node, Scope);

		EXPECT(PunctLbrace);

		while (ATTEMPT_PARSE(_parse_flingDeclModuleItem))
		{
			node->item_list.push_back(_pop_ast_node());
		}

		EXPECT(PunctRbrace);

		return std::nullopt;
	}
}
auto Parser::_parse_flingDeclModuleItem() -> ParseRet
{
	#define LIST(X) \
		X \
		( \
			_parse_flingModinst, \
			\
			_parse_flingImport, \
			\
			_parse_flingDeclConst, \
			_parse_flingDeclVar, \
			_parse_flingDeclWire, \
			\
			_parse_flingWireAssign, \
			\
			_parse_flingDeclAlias, \
			\
			_parse_flingDeclCompositeType, \
			_parse_flingDeclEnum, \
			\
			_parse_flingDeclSubprog, \
			\
			_parse_flingDeclModuleGen, \
			_parse_flingDeclModuleBehav \
		)
	if (just_get_valid_tokens())
	{
		return LIST(GET_VALID_TOK_SET);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclModuleItem);

		START_PARSE_IFELSE(LIST);

		return std::nullopt;
	}

	#undef LIST
}
//--------

//--------
auto Parser::_parse_flingModinst() -> ParseRet
{
	#define LIST(X) \
		X \
		( \
			TOK_PARSE_FUNC(KwModinst) \
		)
	if (just_get_valid_tokens())
	{
		return LIST(GET_VALID_TOK_SET);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingModinst);
		DEFER_PUSH_NODE(node, Modinst);

		START_PARSE_IFELSE(LIST);

		EXPECT_IDENT_AND_GRAB_S(node->ident);

		EXPECT(PunctColon);

		JUST_PARSE_AND_POP_AST_NODE
		(
			node->modnm, _parse_flingModnm,
			node->arg_list, _parse_flingInstArgList
		);

		return std::nullopt;
	}

	#undef LIST
}
//--------

//--------
auto Parser::_parse_flingDeclModuleGen() -> ParseRet
{
	return _inner_parse_flingGen("_parse_flingDeclModuleGen",
		MEMB_FUNC(_parse_flingDeclModuleGenIf),
		MEMB_FUNC(_parse_flingDeclModuleGenSwitchEtc),
		MEMB_FUNC(_parse_flingDeclModuleGenFor));
}
auto Parser::_parse_flingDeclModuleGenIf() -> ParseRet
{
	return _inner_parse_flingGenIf
		("_parse_flingDeclModuleGenIf",
		MEMB_FUNC(_parse_flingDeclModuleScope));
}
auto Parser::_parse_flingDeclModuleGenSwitchEtc() -> ParseRet
{
	return _inner_parse_flingGenSwitchEtc
		("_parse_flingDeclModuleGenSwitchEtc",
		MEMB_FUNC(_parse_flingDeclModuleGenCase),
		MEMB_FUNC(_parse_flingDeclModuleGenDefault));
}
auto Parser::_parse_flingDeclModuleGenCase() -> ParseRet
{
	return _inner_parse_flingGenCase
		("_parse_flingDeclModuleGenCase",
		MEMB_FUNC(_parse_flingDeclModuleScope));
}
auto Parser::_parse_flingDeclModuleGenDefault() -> ParseRet
{
	return _inner_parse_flingGenDefault
		("_parse_flingDeclModuleGenDefault",
		MEMB_FUNC(_parse_flingDeclModuleScope));
}
auto Parser::_parse_flingDeclModuleGenFor() -> ParseRet
{
	return _inner_parse_flingGenFor
		("_parse_flingDeclModuleGenFor",
		MEMB_FUNC(_parse_flingDeclModuleScope));
}
//--------

//--------
auto Parser::_parse_flingDeclModuleBehav() -> ParseRet
{
	#define LIST(X) \
		X \
		( \
			_parse_flingDeclModuleBehavComb, \
			_parse_flingDeclModuleBehavSeq \
		)
	if (just_get_valid_tokens())
	{
		return LIST(GET_VALID_TOK_SET);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclModuleBehav);

		START_PARSE_IFELSE(LIST);

		return std::nullopt;
	}

	#undef LIST
}
auto Parser::_parse_flingDeclModuleBehavComb() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclModuleBehavComb);
		DEFER_PUSH_NODE(node, DeclModuleBehavComb);

		EXPECT(KwComb);

		JUST_PARSE_AND_POP_AST_NODE
			(node->scope, _parse_flingDeclModuleScope);

		return std::nullopt;
	}
}
auto Parser::_parse_flingDeclModuleBehavSeq() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclModuleBehavSeq);
		DEFER_PUSH_NODE(node, DeclModuleBehavSeq);

		EXPECT(KwSeq);

		do
		{
			_parse_flingDeclModuleBehavSeqEdgeItem();
			node->edge_item_list.push_back(_pop_ast_node());
		} while (ATTEMPT_TOK_PARSE(PunctComma));

		JUST_PARSE_AND_POP_AST_NODE
			(node->scope, _parse_flingDeclModuleBehavScope);

		return std::nullopt;
	}
}
auto Parser::_parse_flingDeclModuleBehavSeqEdgeItem() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclModuleBehavSeqEdgeItem);
		DEFER_PUSH_NODE(node, DeclModuleBehavSeqEdgeItem);

		using Kind = DeclModuleBehavSeqEdgeItem::Kind;

		if (ATTEMPT_TOK_PARSE(KwPosedge))
		{
			node->kind = Kind::Posedge;
		}
		else if (ATTEMPT_TOK_PARSE(KwNegedge))
		{
			node->kind = Kind::Negedge;
		}
		else
		{
			_expect_wanted_tok();
		}

		JUST_PARSE_AND_POP_AST_NODE
			(node->expr, _parse_flingExpr);

		return std::nullopt;
	}
}
auto Parser::_parse_flingDeclModuleBehavScope() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclModuleBehavScope);
		DEFER_PUSH_NODE(node, Scope);

		EXPECT(PunctLbrace);

		while (ATTEMPT_PARSE(_parse_flingDeclModuleBehavScopeItem))
		{
			node->item_list.push_back(_pop_ast_node());
		}

		EXPECT(PunctRbrace);

		return std::nullopt;
	}
}
auto Parser::_parse_flingDeclModuleBehavScopeItem() -> ParseRet
{
	#define LIST(X) \
		X \
		( \
			_parse_flingDeclModuleBehavScope, \
			\
			_parse_flingDeclModuleBehavScopeItemIf, \
			_parse_flingDeclModuleBehavScopeItemSwitchEtc, \
			_parse_flingDeclModuleBehavScopeItemFor, \
			_parse_flingDeclModuleBehavScopeItemWhile, \
			\
			_parse_flingDeclModuleBehavScopeItemGen, \
			\
			_parse_flingAnyBehavScopeItem \
		)
	if (just_get_valid_tokens())
	{
		return LIST(GET_VALID_TOK_SET);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingDeclModuleBehavScopeItem);

		START_PARSE_IFELSE(LIST);

		return std::nullopt;
	}
	#undef LIST
}
auto Parser::_parse_flingDeclModuleBehavScopeItemIf() -> ParseRet
{
	return _inner_parse_flingIf("_parse_flingDeclModuleBehavScopeItemIf",
		MEMB_FUNC(_parse_flingDeclModuleBehavScope));
}
auto Parser::_parse_flingDeclModuleBehavScopeItemSwitchEtc() -> ParseRet
{
	return _inner_parse_flingSwitchEtc
		("_parse_flingDeclModuleBehavScopeItemSwitchEtc",
		MEMB_FUNC(_parse_flingDeclModuleBehavScopeItemCase),
		MEMB_FUNC(_parse_flingDeclModuleBehavScopeItemDefault));
}
auto Parser::_parse_flingDeclModuleBehavScopeItemCase() -> ParseRet
{
	return _inner_parse_flingCase
		("_parse_flingDeclModuleBehavScopeItemCase",
		MEMB_FUNC(_parse_flingDeclModuleBehavScope));
}
auto Parser::_parse_flingDeclModuleBehavScopeItemDefault() -> ParseRet
{
	return _inner_parse_flingDefault
		("_parse_flingDeclModuleBehavScopeItemDefault",
		MEMB_FUNC(_parse_flingDeclModuleBehavScope));
}
auto Parser::_parse_flingDeclModuleBehavScopeItemFor() -> ParseRet
{
	return _inner_parse_flingFor
		("_parse_flingDeclModuleBehavScopeItemFor",
		MEMB_FUNC(_parse_flingDeclModuleBehavScope));
}
auto Parser::_parse_flingDeclModuleBehavScopeItemWhile() -> ParseRet
{
	return _inner_parse_flingWhile
		("_parse_flingDeclModuleBehavScopeItemWhile",
		MEMB_FUNC(_parse_flingDeclModuleBehavScope));
}
//--------

//--------
auto Parser::_parse_flingDeclModuleBehavScopeItemGen() -> ParseRet
{
	return _inner_parse_flingGen("_parse_flingDeclModuleBehavScopeItemGen",
		MEMB_FUNC(_parse_flingDeclModuleBehavScopeItemGenIf),
		MEMB_FUNC(_parse_flingDeclModuleBehavScopeItemGenSwitchEtc),
		MEMB_FUNC(_parse_flingDeclModuleBehavScopeItemGenFor));
}
auto Parser::_parse_flingDeclModuleBehavScopeItemGenIf() -> ParseRet
{
	return _inner_parse_flingGenIf
		("_parse_flingDeclModuleBehavScopeItemGenIf",
		MEMB_FUNC(_parse_flingDeclModuleBehavScope));
}
auto Parser::_parse_flingDeclModuleBehavScopeItemGenSwitchEtc() -> ParseRet
{
	return _inner_parse_flingGenSwitchEtc
		("_parse_flingDeclModuleBehavScopeItemGenSwitchEtc",
		MEMB_FUNC(_parse_flingDeclModuleBehavScopeItemGenCase),
		MEMB_FUNC(_parse_flingDeclModuleBehavScopeItemGenDefault));
}
auto Parser::_parse_flingDeclModuleBehavScopeItemGenCase() -> ParseRet
{
	return _inner_parse_flingGenCase
		("_parse_flingDeclModuleBehavScopeItemGenCase",
		MEMB_FUNC(_parse_flingDeclModuleBehavScope));
}
auto Parser::_parse_flingDeclModuleBehavScopeItemGenDefault() -> ParseRet
{
	return _inner_parse_flingGenDefault
		("_parse_flingDeclModuleBehavScopeItemGenDefault",
		MEMB_FUNC(_parse_flingDeclModuleBehavScope));
}
auto Parser::_parse_flingDeclModuleBehavScopeItemGenFor() -> ParseRet
{
	return _inner_parse_flingGenFor
		("_parse_flingDeclModuleBehavScopeItemGenFor",
		MEMB_FUNC(_parse_flingDeclModuleBehavScope));
}
//--------

//--------
auto Parser::_parse_flingAnyBehavScopeItem() -> ParseRet
{
	#define LIST(X) \
		X \
		( \
			_parse_flingDeclConst, \
			_parse_flingDeclVar, \
			\
			_parse_flingDeclCompositeType, \
			_parse_flingDeclEnum, \
			\
			_parse_flingDeclSubprog, \
			\
			_parse_flingAnyBehavScopeItemStWithIdent, \
			_parse_flingAnyBehavScopeItemStWithCat \
		)
		
	if (just_get_valid_tokens())
	{
		return LIST(GET_VALID_TOK_SET);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingAnyBehavScopeItem);

		START_PARSE_IFELSE(LIST);

		return std::nullopt;
	}

	#undef LIST
}
auto Parser::_parse_flingAnyBehavScopeItemStWithIdent() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingAnyBehavScopeItemStWithIdent);

		string ident;
		EXPECT_IDENT_AND_GRAB_S(ident);

		if (CHECK_PARSE(_parse_flingIdentExprSuffix,
			_parse_flingAnyBehavScopeItemAssignSuffix))
		{
			DEFER_PUSH_NODE_AND_SET_TEMP(node, BehavAssign);

			{
				DEFER_PUSH_NODE(ident_expr, IdentExpr);

				{
					DEFER_PUSH_NODE(to_push, StrAndNode);
					to_push->str = move(ident);
				}

				ident_expr->prologue_list.push_back(_pop_ast_node());

				PARSE_AND_POP_AST_NODE_IF
					(ident_expr->suffix, _parse_flingIdentExprSuffix);
			}

			node->lhs = _pop_ast_node();

			// Just a regular call here.  This function exclusively
			// operates on `_temp_ast`.
			_parse_flingAnyBehavScopeItemAssignSuffix();
		}
		else if (CHECK_PARSE(_parse_flingInstParamList,
			_parse_flingTypenmCstmChainItem,
			_parse_flingInstArgList))
		{
			DEFER_PUSH_NODE(node, IdentExpr);

			{
				DEFER_PUSH_NODE(to_push, StrAndNode);
				to_push->str = move(ident);

				PARSE_AND_POP_AST_NODE_IF
					(to_push->node, _parse_flingInstParamList);
			}

			node->prologue_list.push_back(_pop_ast_node());

			while (ATTEMPT_PARSE(_parse_flingTypenmCstmChainItem))
			{
				node->prologue_list.push_back(_pop_ast_node());
			}

			JUST_PARSE_AND_POP_AST_NODE
				(node->opt_arg_list, _parse_flingInstArgList);
		}

		EXPECT(PunctSemicolon);

		return std::nullopt;
	}
}
auto Parser::_parse_flingAnyBehavScopeItemStWithCat() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingAssignLhsCatExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingAnyBehavScopeItemStWithCat);
		DEFER_PUSH_NODE_AND_SET_TEMP(node, BehavAssign);

		JUST_PARSE_AND_POP_AST_NODE
			(node->lhs, _parse_flingAssignLhsCatExpr);

		_parse_flingAnyBehavScopeItemAssignSuffix();

		EXPECT(PunctSemicolon);

		return std::nullopt;
	}
}
auto Parser::_parse_flingAnyBehavScopeItemAssignSuffix() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingAnyBehavScopeItemAssignSuffix);

		if (_temp_ast->id() == "BehavAssign")
		{
			auto node = static_cast<BehavAssign*>(_temp_ast);
			using Kind = BehavAssign::Kind;

			if (ATTEMPT_TOK_PARSE(PunctBlkAssign))
			{
				node->kind = Kind::Blk;
			}
			else if (ATTEMPT_TOK_PARSE(PunctNonBlkAssign))
			{
				node->kind = Kind::NonBlk;
			}
			else
			{
				_expect_wanted_tok();
			}

			JUST_PARSE_AND_POP_AST_NODE
				(node->rhs, _parse_flingExpr);

			EXPECT(PunctSemicolon);
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

//--------
auto Parser::_parse_flingExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingMuxExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingExpr);

		_parse_flingMuxExpr();

		return std::nullopt;
	}
}
auto Parser::_parse_flingMuxExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwMux),
				_parse_flingLogorExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingMuxExpr);

		if (ATTEMPT_TOK_PARSE(KwMux))
		{
			DEFER_PUSH_NODE(node, MuxExpr);

			EXPECT(PunctLparen);

			JUST_PARSE_AND_POP_AST_NODE
				(node->cond, _parse_flingExpr);
			EXPECT(PunctComma);
			JUST_PARSE_AND_POP_AST_NODE
				(node->when_true, _parse_flingExpr);
			EXPECT(PunctComma);
			JUST_PARSE_AND_POP_AST_NODE
				(node->when_false, _parse_flingExpr);

			EXPECT(PunctRparen);
		}
		else if (ATTEMPT_PARSE(_parse_flingLogorExpr))
		{
		}
		else
		{
			_expect_wanted_tok();
		}

		return std::nullopt;
	}
}
auto Parser::_parse_flingLogorExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingLogandExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingLogorExpr);

		//_inner_parse_binop_expr(MEMB_FUNC(_parse_flingLogandExpr),
		//	pair(TOK_PARSE_MEMB_FUNC(PunctLogor), BinopExpr::Kind::Logor));
		INNER_PARSE_BINOP_EXPR(_parse_flingLogandExpr,
			PunctLogor, Logor);

		return std::nullopt;
	}
}
auto Parser::_parse_flingLogandExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingCmpEqEtcExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingLogandExpr);

		INNER_PARSE_BINOP_EXPR(_parse_flingCmpEqEtcExpr,
			PunctLogand, Logand);

		return std::nullopt;
	}
}
auto Parser::_parse_flingCmpEqEtcExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingCmpLtEtcExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingCmpEqEtcExpr);

		INNER_PARSE_BINOP_EXPR(_parse_flingCmpLtEtcExpr,
			PunctCmpEq, CmpEq,
			PunctCmpNe, CmpNe,
			PunctCaseCmpEq, CaseCmpEq,
			PunctCaseCmpNe, CaseCmpNe);

		return std::nullopt;
	}
}
auto Parser::_parse_flingCmpLtEtcExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingPlusMinusExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingCmpLtEtcExpr);

		INNER_PARSE_BINOP_EXPR(_parse_flingPlusMinusExpr,
			PunctCmpLt, CmpLt,
			PunctCmpGt, CmpGt,
			PunctCmpLe, CmpLe,
			PunctCmpGe, CmpGe);

		return std::nullopt;
	}
}
auto Parser::_parse_flingPlusMinusExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingMulDivModExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingPlusMinusExpr);

		INNER_PARSE_BINOP_EXPR(_parse_flingMulDivModExpr,
			PunctPlus, Plus,
			PunctMinus, Minus);

		return std::nullopt;
	}
}
auto Parser::_parse_flingMulDivModExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingBitorBitnorExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingMulDivModExpr);

		INNER_PARSE_BINOP_EXPR(_parse_flingBitorBitnorExpr,
			PunctMul, Mul,
			PunctDiv, Div,
			PunctMod, Mod);

		return std::nullopt;
	}
}
auto Parser::_parse_flingBitorBitnorExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingBitandBitnandExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingBitorBitnorExpr);

		INNER_PARSE_BINOP_EXPR(_parse_flingBitandBitnandExpr,
			PunctBitor, Bitor,
			PunctBitnor, Bitnor);

		return std::nullopt;
	}
}
auto Parser::_parse_flingBitandBitnandExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingBitxorBitxnorExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingBitandBitnandExpr);

		INNER_PARSE_BINOP_EXPR(_parse_flingBitxorBitxnorExpr,
			PunctBitand, Bitand,
			PunctBitnand, Bitnand);

		return std::nullopt;
	}
}
auto Parser::_parse_flingBitxorBitxnorExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingBitshiftExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingBitxorBitxnorExpr);

		INNER_PARSE_BINOP_EXPR(_parse_flingBitshiftExpr,
			PunctBitxor, Bitxor,
			PunctBitxnor, Bitxnor);

		return std::nullopt;
	}
}
auto Parser::_parse_flingBitshiftExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingUnaryExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingBitshiftExpr);

		INNER_PARSE_BINOP_EXPR(_parse_flingUnaryExpr,
			KwLsl, Lsl,
			KwLsr, Lsr,
			KwAsr, Asr);

		return std::nullopt;
	}
}
auto Parser::_parse_flingUnaryExpr() -> ParseRet
{
	#define LIST(X) \
		X \
		( \
			PunctPlus, Kind::Plus, \
			PunctMinus, Kind::Minus, \
			\
			PunctBitnot, Kind::Bitnot, \
			PunctLognot, Kind::Lognot, \
			\
			PunctBitor, Kind::Bitor, \
			PunctBitnor, Kind::Bitnor, \
			\
			PunctBitand, Kind::Bitand, \
			PunctBitnand, Kind::Bitnand, \
			\
			PunctBitxor, Kind::Bitxor, \
			PunctBitxnor, Kind::Bitxnor \
		)
	if (just_get_valid_tokens())
	{
		#define _INNER_X(tok, kind) \
			TOK_PARSE_FUNC(tok)
		#define X(...) \
			GET_VALID_TOK_SET \
			( \
				EVAL(MAP_PAIRS(_INNER_X, COMMA, __VA_ARGS__)), \
				_parse_flingLowExpr \
			)
		return LIST(X);
		#undef _INNER_X
		#undef X
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingUnaryExpr);

		using Kind = UnopExpr::Kind;

		//if (_attempt_parse(p.first))
		//{
		//	DEFER_PUSH_NODE(node, UnopExpr);

		//	node->kind = p.second;

		//	JUST_PARSE_AND_POP_AST_NODE
		//		(node->arg, _parse_flingExpr);
		//}
		#define _INNER_X(tok, some_kind) \
			if (ATTEMPT_TOK_PARSE(tok)) \
			{ \
				DEFER_PUSH_NODE(node, UnopExpr); \
				node->kind = some_kind; \
				_parse_flingExpr(); \
				node->arg = _pop_ast_node(); \
			}
		#define X(...) \
			EVAL(MAP_PAIRS(_INNER_X, ELSE, __VA_ARGS__))
		LIST(X)
		#undef _INNER_X
		#undef X
		else if (ATTEMPT_PARSE(_parse_flingLowExpr))
		{
		}
		else
		{
			_expect_wanted_tok();
		}

		return std::nullopt;
	}
	#undef LIST
}
auto Parser::_parse_flingLowExpr() -> ParseRet
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

				_parse_flingCallDollarFuncExpr,

				_parse_flingIdentExpr,

				_parse_flingCatExpr,
				_parse_flingReplExpr,
				_parse_flingSizedExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingLowExpr);

		return std::nullopt;
	}
}
auto Parser::_parse_flingCallDollarFuncExpr() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingCallDollarFuncExpr);

		return std::nullopt;
	}
}
auto Parser::_parse_flingAssignLhsIdentExpr() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingAssignLhsIdentExpr);

		return std::nullopt;
	}
}
auto Parser::_parse_flingAssignLhsCatExpr() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingAssignLhsCatExpr);

		return std::nullopt;
	}
}
auto Parser::_parse_flingIdentExprSuffix() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingIdentExprSuffix);

		return std::nullopt;
	}
}
auto Parser::_parse_flingIdentExprStart() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingIdentExprStart);

		return std::nullopt;
	}
}
auto Parser::_parse_flingIdentExpr() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingIdentExpr);

		return std::nullopt;
	}
}
auto Parser::_parse_flingCatExpr() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingCatExpr);

		return std::nullopt;
	}
}
auto Parser::_parse_flingReplExpr() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingReplExpr);

		return std::nullopt;
	}
}
auto Parser::_parse_flingSizedExpr() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingSizedExpr);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parse_flingRange() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingNonSimpleRange,
				_parse_flingExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingRange);

		return std::nullopt;
	}
}
auto Parser::_parse_flingNonSimpleRange() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingNonSimpleRange);

		return std::nullopt;
	}
}
auto Parser::_parse_flingSimpleRangeSuffix() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingSimpleRangeSuffix);

		return std::nullopt;
	}
}
auto Parser::_parse_flingExprOrRange() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingExpr,
				_parse_flingNonSimpleRange
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingExprOrRange);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parse_flingTypenmCstmChainItem() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingTypenmCstmChainItem);

		return std::nullopt;
	}
}
auto Parser::_parse_flingTypenm() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingIdentExprStart,
				TOK_PARSE_FUNC(KwLogic),
				TOK_PARSE_FUNC(KwInteger)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingTypenm);

		return std::nullopt;
	}
}
auto Parser::_parse_flingModnm() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingModnm);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_inner_parse_flingIf(string&& func_name,
	const ParseFunc& scope_func) -> ParseRet
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
		ParserBase::PrologueAndEpilogue p_and_e(this, move(func_name));
		DEFER_PUSH_NODE(node, BehavIf);

		EXPECT(KwIf);
		JUST_PARSE_AND_POP_AST_NODE
		(
			node->if_expr, _parse_flingExpr,
		);

		_call_parse_func(scope_func);
		node->if_scope = _pop_ast_node();

		while (ATTEMPT_TOK_PARSE(KwElif))
		{
			{
				DEFER_PUSH_NODE(elif_node, BehavElif);
				JUST_PARSE_AND_POP_AST_NODE
				(
					elif_node->expr, _parse_flingExpr,
				);

				_call_parse_func(scope_func);
				elif_node->scope = _pop_ast_node();
			}

			node->opt_elif_list.push_back(_pop_ast_node());
		}

		if (ATTEMPT_TOK_PARSE(KwElse))
		{
			_call_parse_func(scope_func);
			node->opt_else_scope = _pop_ast_node();
		}

		return std::nullopt;
	}
}
auto Parser::_inner_parse_flingSwitchEtc(string&& func_name,
	const ParseFunc& case_func, const ParseFunc& default_func)
	-> ParseRet
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
		PrologueAndEpilogue p_and_e(this, move(func_name));
		DEFER_PUSH_NODE(node, BehavSwitchEtc);

		using Kind = BehavSwitchEtc::Kind;

		if (ATTEMPT_TOK_PARSE(KwSwitch))
		{
			node->kind = Kind::Switch;
		}
		else if (ATTEMPT_TOK_PARSE(KwSwitchz))
		{
			node->kind = Kind::Switchz;
		}
		else
		{
			_expect_wanted_tok();
		}

		JUST_PARSE_AND_POP_AST_NODE
			(node->expr, _parse_flingExpr);

		EXPECT(PunctLbrace);

		if (_attempt_parse(default_func))
		{
			node->opt_default = _pop_ast_node();

			while (_attempt_parse(case_func))
			{
				node->opt_case_list.push_back(_pop_ast_node());
			}
		}
		else
		{
			while (_attempt_parse(case_func))
			{
				node->opt_case_list.push_back(_pop_ast_node());
			}

			if (_attempt_parse(default_func))
			{
				node->opt_default = _pop_ast_node();
			}
		}

		EXPECT(PunctRbrace);

		return std::nullopt;
	}
}
auto Parser::_inner_parse_flingCase(string&& func_name,
	const ParseFunc& scope_func) -> ParseRet
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
		PrologueAndEpilogue p_and_e(this, move(func_name));
		DEFER_PUSH_NODE(node, BehavCase);

		EXPECT(KwCase);
		JUST_PARSE_AND_POP_AST_LIST
			(node->expr_list, _parse_flingExprList);

		_call_parse_func(scope_func);
		node->scope = _pop_ast_node();

		return std::nullopt;
	}
}
auto Parser::_inner_parse_flingDefault(string&& func_name,
	const ParseFunc& scope_func) -> ParseRet
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
		PrologueAndEpilogue p_and_e(this, move(func_name));
		DEFER_PUSH_NODE(node, BehavDefault);

		EXPECT(KwDefault);

		_call_parse_func(scope_func);
		node->scope = _pop_ast_node();

		return std::nullopt;
	}
}
auto Parser::_inner_parse_flingFor(string&& func_name,
	const ParseFunc& scope_func) -> ParseRet
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
		PrologueAndEpilogue p_and_e(this, move(func_name));
		DEFER_PUSH_NODE(node, BehavFor);

		EXPECT(KwFor);

		EXPECT_IDENT_AND_GRAB_S(node->iter_ident);
		EXPECT(PunctColon);

		JUST_PARSE_AND_POP_AST_NODE
			(node->range, _parse_flingRange);

		_call_parse_func(scope_func);
		node->scope = _pop_ast_node();

		return std::nullopt;
	}
}
auto Parser::_inner_parse_flingWhile(string&& func_name,
	const ParseFunc& scope_func) -> ParseRet
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
		PrologueAndEpilogue p_and_e(this, move(func_name));
		DEFER_PUSH_NODE(node, BehavWhile);

		EXPECT(KwWhile);

		JUST_PARSE_AND_POP_AST_NODE
			(node->expr, _parse_flingExpr);

		_call_parse_func(scope_func);
		node->scope = _pop_ast_node();

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_inner_parse_flingGen(string&& func_name,
	const ParseFunc& gen_if_func, const ParseFunc& gen_switch_etc_func,
	const ParseFunc& gen_for_func) -> ParseRet
{
	#define LIST(X) \
		X \
		( \
			gen_if_func, \
			gen_switch_etc_func, \
			gen_for_func \
		)
	if (just_get_valid_tokens())
	{
		#define X(...) \
			_get_valid_tok_set(__VA_ARGS__)
		return LIST(X);
		#undef X
	}
	else // if (!just_get_valid_tokens())
	{
		ParserBase::PrologueAndEpilogue p_and_e(this, move(func_name));

		LIST(NON_MEMB_PARSE_IFELSE)
		else
		{
			_expect_wanted_tok();
		}

		return std::nullopt;
	}
	#undef LIST
}
auto Parser::_inner_parse_flingGenIf(string&& func_name,
	const ParseFunc& scope_func) -> ParseRet
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
		ParserBase::PrologueAndEpilogue p_and_e(this, move(func_name));
		DEFER_PUSH_NODE(node, GenIf);

		EXPECT(KwGenIf);
		JUST_PARSE_AND_POP_AST_NODE
		(
			node->if_expr, _parse_flingExpr,
		);

		_call_parse_func(scope_func);
		node->if_scope = _pop_ast_node();

		while (ATTEMPT_TOK_PARSE(KwGenElif))
		{
			{
				DEFER_PUSH_NODE(gen_elif_node, GenElif);
				JUST_PARSE_AND_POP_AST_NODE
				(
					gen_elif_node->expr, _parse_flingExpr,
				);

				_call_parse_func(scope_func);
				gen_elif_node->scope = _pop_ast_node();
			}

			node->opt_elif_list.push_back(_pop_ast_node());
		}

		if (ATTEMPT_TOK_PARSE(KwGenElse))
		{
			_call_parse_func(scope_func);
			node->opt_else_scope = _pop_ast_node();
		}

		return std::nullopt;
	}
}
auto Parser::_inner_parse_flingGenSwitchEtc(string&& func_name,
	const ParseFunc& gen_case_func, const ParseFunc& gen_default_func)
	-> ParseRet
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
		PrologueAndEpilogue p_and_e(this, move(func_name));
		DEFER_PUSH_NODE(node, GenSwitchEtc);

		using Kind = GenSwitchEtc::Kind;

		if (ATTEMPT_TOK_PARSE(KwGenSwitch))
		{
			node->kind = Kind::Switch;
		}
		else if (ATTEMPT_TOK_PARSE(KwGenSwitchz))
		{
			node->kind = Kind::Switchz;
		}
		else
		{
			_expect_wanted_tok();
		}

		JUST_PARSE_AND_POP_AST_NODE
			(node->expr, _parse_flingExpr);

		EXPECT(PunctLbrace);

		if (_attempt_parse(gen_default_func))
		{
			node->opt_default = _pop_ast_node();

			while (_attempt_parse(gen_case_func))
			{
				node->opt_case_list.push_back(_pop_ast_node());
			}
		}
		else
		{
			while (_attempt_parse(gen_case_func))
			{
				node->opt_case_list.push_back(_pop_ast_node());
			}

			if (_attempt_parse(gen_default_func))
			{
				node->opt_default = _pop_ast_node();
			}
		}

		EXPECT(PunctRbrace);

		return std::nullopt;
	}
}
auto Parser::_inner_parse_flingGenCase(string&& func_name,
	const ParseFunc& scope_func) -> ParseRet
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
		PrologueAndEpilogue p_and_e(this, move(func_name));
		DEFER_PUSH_NODE(node, GenCase);

		EXPECT(KwGenCase);
		JUST_PARSE_AND_POP_AST_LIST
			(node->expr_list, _parse_flingExprList);

		_call_parse_func(scope_func);
		node->scope = _pop_ast_node();

		return std::nullopt;
	}
}
auto Parser::_inner_parse_flingGenDefault(string&& func_name,
	const ParseFunc& scope_func) -> ParseRet
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
		PrologueAndEpilogue p_and_e(this, move(func_name));
		DEFER_PUSH_NODE(node, GenDefault);

		EXPECT(KwGenDefault);

		_call_parse_func(scope_func);
		node->scope = _pop_ast_node();

		return std::nullopt;
	}
}
auto Parser::_inner_parse_flingGenFor(string&& func_name,
	const ParseFunc& scope_func) -> ParseRet
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
		PrologueAndEpilogue p_and_e(this, move(func_name));
		DEFER_PUSH_NODE(node, GenFor);

		EXPECT(KwGenFor);

		if (ATTEMPT_TOK_PARSE(PunctLbracket))
		{
			EXPECT_IDENT_AND_GRAB_S(node->label);
			EXPECT(PunctRbracket);
		}

		EXPECT_IDENT_AND_GRAB_S(node->iter_ident);
		EXPECT(PunctColon);

		JUST_PARSE_AND_POP_AST_NODE
			(node->range, _parse_flingRange);

		_call_parse_func(scope_func);
		node->scope = _pop_ast_node();

		return std::nullopt;
	}
}
//--------

//--------
template<typename... RemArgTypes>
void Parser::_inner_parse_binop_expr(const BinopParsePair& first_pair,
	RemArgTypes&&... rem_args)
{
	if (_attempt_parse(first_pair.first))
	{
		DEFER_PUSH_NODE(node, BinopExpr);

		node->kind = first_pair.second;

		node->left = _pop_ast_node();

		JUST_PARSE_AND_POP_AST_NODE
			(node->right, _parse_flingExpr);
	}
	else if constexpr (sizeof...(rem_args) > 0)
	{
		_inner_parse_binop_expr(rem_args...);
	}
	else
	{
		_expect_wanted_tok();
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
