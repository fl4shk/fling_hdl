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
	_parseFlingProgram();
	return 0;
}
//--------

//--------
auto Parser::_parseFlingProgram() -> ParseRet
{
	PROLOGUE_AND_EPILOGUE(_parseFlingProgram);

	while (ATTEMPT_PARSE(_parseFlingDeclPackageItem))
	{
		_ast_program->item_list.push_back(_pop_ast_node());
	}

	EXPECT(MiscEof);

	return std::nullopt;
}
//--------

//--------
auto Parser::_parseFlingDeclPackage() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclPackage);
		DEFER_PUSH_NODE(node, DeclPackage);

		START_PARSE_IFELSE(LIST);

		EXPECT_IDENT_AND_GRAB_S(node->ident);
		EXPECT(PunctLbrace);


		while (ATTEMPT_PARSE(_parseFlingDeclPackageItem))
		{
			node->item_list.push_back(_pop_ast_node());
		}

		EXPECT(PunctRbrace);

		return std::nullopt;
	}

	#undef LIST
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

		START_PARSE_IFELSE(LIST);

		return std::nullopt;
	}

	#undef LIST
}
auto Parser::_parseFlingImport() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parseFlingImport);
		DEFER_PUSH_NODE(node, Import);

		START_PARSE_IFELSE(LIST);

		JUST_PARSE_AND_POP_AST_LIST
			(node->item_list, _parseFlingImportItemList);
		EXPECT(PunctSemicolon);

		return std::nullopt;
	}

	#undef LIST
}
//--------

//--------
auto Parser::_parseFlingDeclParamList() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclParamList);
		DEFER_PUSH_NODE(node, ParamOrArgList);

		START_PARSE_IFELSE(LIST);

		while (ATTEMPT_PARSE(_parseFlingDeclParamSublist))
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

		using Kind = DeclParamSublistItem::Kind;

		IdentList ident_list;
		JUST_PARSE_AND_POP_IDENT_LIST(ident_list, _parseFlingIdentList);

		EXPECT(PunctColon);

		Kind kind = Kind::Var;
		BaseUptr opt_typenm;
		BaseUptrList opt_def_val_list;
		FilePos err_file_pos;

		if (ATTEMPT_PARSE(_parseFlingTypenm))
		{
			_pop_ast_node(opt_typenm);
			kind = Kind::Var;

			if (ATTEMPT_TOK_PARSE(PunctBlkAssign))
			{
				err_file_pos = lex_file_pos();
				JUST_PARSE_AND_POP_AST_LIST
					(opt_def_val_list, _parseFlingExprList);
			}
		}
		else if (ATTEMPT_TOK_PARSE(KwRange))
		{
			kind = Kind::Range;

			if (ATTEMPT_TOK_PARSE(PunctBlkAssign))
			{
				err_file_pos = lex_file_pos();
				JUST_PARSE_AND_POP_AST_LIST
					(opt_def_val_list, _parseFlingRangeList);
			}
		}
		else if (ATTEMPT_TOK_PARSE(KwType))
		{
			kind = Kind::Type;

			if (ATTEMPT_TOK_PARSE(PunctBlkAssign))
			{
				err_file_pos = lex_file_pos();

				JUST_PARSE_AND_POP_AST_LIST
					(opt_def_val_list, _parseFlingTypenmList);
			}
		}
		else if (ATTEMPT_TOK_PARSE(KwModule))
		{
			kind = Kind::Module;

			if (ATTEMPT_TOK_PARSE(PunctBlkAssign))
			{
				err_file_pos = lex_file_pos();

				JUST_PARSE_AND_POP_AST_LIST
					(opt_def_val_list, _parseFlingModnmList);
			}
		}
		else if (ATTEMPT_TOK_PARSE(KwFunc))
		{
			kind = Kind::Func;

			if (ATTEMPT_TOK_PARSE(PunctBlkAssign))
			{
				err_file_pos = lex_file_pos();

				JUST_PARSE_AND_POP_AST_LIST
					(opt_def_val_list, _parseFlingSubprogIdentList);
			}
		}
		else if (ATTEMPT_TOK_PARSE(KwTask))
		{
			kind = Kind::Task;

			if (ATTEMPT_TOK_PARSE(PunctBlkAssign))
			{
				err_file_pos = lex_file_pos();

				JUST_PARSE_AND_POP_AST_LIST
					(opt_def_val_list, _parseFlingSubprogIdentList);
			}
		}
		else
		{
			_expect_wanted_tok();
		}

		struct Triple
		{
			string ident;
			FilePos ident_fp;
			BaseUptr opt_def_val;
		};

		vector<Triple> triple_vec;

		for (auto& node: ident_list)
		{
			Triple to_push;

			// It's okay to do a `move` here because we don't need
			// to keep `ident_list` itself around.
			to_push.ident = move(node.data.first);
			to_push.ident_fp = move(node.data.second);
			triple_vec.push_back(move(to_push));
		}

		if (opt_def_val_list.size() > 0)
		{
			if (ident_list.size() != opt_def_val_list.size())
			{
				_err(err_file_pos, "Number of default values unequal to ",
					"number of parameters in sublist.");
			}

			size_t i = 0;
			for (auto& node: opt_def_val_list)
			{
				triple_vec.at(i).opt_def_val = move(node.data);
				++i;
			}
		}
		for (auto& triple: triple_vec)
		{
			using AstNodeType = DeclParamSublistItem;
			BaseUptr to_push(new AstNodeType(_curr_ast_parent,
				triple.ident_fp));
			auto to_push_ptr = static_cast<AstNodeType*>(to_push.get());

			to_push_ptr->ident = move(triple.ident);
			to_push_ptr->kind = kind;

			if (opt_typenm)
			{
				to_push_ptr->opt_typenm = opt_typenm->dup
					(opt_typenm->parent());
			}

			to_push_ptr->opt_def_val = move(triple.opt_def_val);

			sublist.push_back(move(to_push));
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
		DEFER_PUSH_NODE(node, ParamOrArgList);

		EXPECT(PunctLparen);

		while (ATTEMPT_PARSE(_parseFlingDeclArgSublist))
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
		DEFER_PUSH_LIST(sublist);

		using Kind = DeclArgSublistItem::Kind;

		IdentList ident_list;
		JUST_PARSE_AND_POP_IDENT_LIST(ident_list, _parseFlingIdentList);

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
		JUST_PARSE_AND_POP_AST_NODE(typenm, _parseFlingTypenm);

		FilePos err_file_pos;
		BaseUptrList opt_def_val_list;

		if (ATTEMPT_TOK_PARSE(PunctBlkAssign))
		{
			err_file_pos = lex_file_pos();
			JUST_PARSE_AND_POP_AST_LIST
				(opt_def_val_list, _parseFlingExprList);
		}

		struct Triple
		{
			string ident;
			FilePos ident_fp;
			BaseUptr opt_def_val;
		};

		vector<Triple> triple_vec;

		for (auto& node: ident_list)
		{
			Triple to_push;

			to_push.ident = move(node.data.first);
			to_push.ident_fp = move(node.data.second);
			triple_vec.push_back(move(to_push));
		}

		if (opt_def_val_list.size() > 0)
		{
			if (ident_list.size() != opt_def_val_list.size())
			{
				_err(err_file_pos, "Number of default values unequal to ",
					"number of parameters in sublist.");
			}

			size_t i = 0;
			for (auto& node: opt_def_val_list)
			{
				triple_vec.at(i).opt_def_val = move(node.data);
				++i;
			}
		}

		for (auto& triple: triple_vec)
		{
			using AstNodeType = DeclArgSublistItem;
			BaseUptr to_push(new AstNodeType(_curr_ast_parent,
				triple.ident_fp));
			auto to_push_ptr = static_cast<AstNodeType*>(to_push.get());

			to_push_ptr->ident = move(triple.ident);
			to_push_ptr->kind = kind;

			to_push_ptr->typenm = typenm->dup(typenm->parent());

			to_push_ptr->opt_def_val = move(triple.opt_def_val);

			sublist.push_back(move(to_push));
		}

		return std::nullopt;
	}
}
auto Parser::_parseFlingInstParamList() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parseFlingInstParamList);
		DEFER_PUSH_NODE(node, ParamOrArgList);

		EXPECT(PunctCmpLt);

		while (ATTEMPT_PARSE(_parseFlingInstParamListItem))
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

		PARSE_IFELSE
		(
			_parseFlingInstParamListItemPos,
			_parseFlingInstParamListItemNamed
		)
		else
		{
			_expect_wanted_tok();
		}

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

		PARSE_IFELSE
		(
			_parseFlingExprOrRange
		)
		else
		{
			_expect_wanted_tok();
		}

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

		DEFER_PUSH_NODE(node, StrAndNode);

		EXPECT(PunctMemberAccess);
		EXPECT_IDENT_AND_GRAB_S(node->str);

		if (ATTEMPT_TOK_PARSE(PunctMapTo))
		{
			JUST_PARSE_AND_POP_AST_NODE
				(node->node, _parseFlingInstParamListItemPos);
		}

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
		DEFER_PUSH_NODE(node, ParamOrArgList);

		EXPECT(PunctLparen);

		while (ATTEMPT_PARSE(_parseFlingInstArgListItem))
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

		PARSE_IFELSE
		(
			_parseFlingInstArgListItemPos,
			_parseFlingInstArgListItemNamed
		)
		else
		{
			_expect_wanted_tok();
		}

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

		PARSE_IFELSE
		(
			_parseFlingExpr
		)
		else
		{
			_expect_wanted_tok();
		}

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

		DEFER_PUSH_NODE(node, StrAndNode);

		EXPECT(PunctMemberAccess);
		EXPECT_IDENT_AND_GRAB_S(node->str);

		if (ATTEMPT_TOK_PARSE(PunctMapTo))
		{
			JUST_PARSE_AND_POP_AST_NODE
				(node->node, _parseFlingInstArgListItemPos);
		}

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
		DEFER_PUSH_NODE(node, DeclModule);

		EXPECT(KwModule);
		EXPECT_IDENT_AND_GRAB_S(node->ident);

		PARSE_AND_POP_AST_NODE_IF
			(node->opt_param_list, _parseFlingDeclParamList);

		JUST_PARSE_AND_POP_AST_NODE
			(node->arg_list, _parseFlingDeclArgList);

		JUST_PARSE_AND_POP_AST_NODE
			(node->scope, _parseFlingDeclModuleScope);

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
		DEFER_PUSH_NODE(node, Scope);

		EXPECT(PunctLbrace);

		while (ATTEMPT_PARSE(_parseFlingDeclModuleItem))
		{
			node->item_list.push_back(_pop_ast_node());
		}

		EXPECT(PunctRbrace);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleItem() -> ParseRet
{
	#define LIST(X) \
		X \
		( \
			_parseFlingModinst, \
			\
			_parseFlingImport, \
			\
			_parseFlingDeclConst, \
			_parseFlingDeclVar, \
			_parseFlingDeclWire, \
			\
			_parseFlingWireAssign, \
			\
			_parseFlingDeclAlias, \
			\
			_parseFlingDeclCompositeType, \
			_parseFlingDeclEnum, \
			\
			_parseFlingDeclSubprog, \
			\
			_parseFlingDeclModuleGen, \
			_parseFlingDeclModuleBehav \
		)
	if (just_get_valid_tokens())
	{
		return LIST(GET_VALID_TOK_SET);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleItem);

		START_PARSE_IFELSE(LIST);

		return std::nullopt;
	}

	#undef LIST
}
//--------

//--------
auto Parser::_parseFlingModinst() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parseFlingModinst);
		DEFER_PUSH_NODE(node, Modinst);

		START_PARSE_IFELSE(LIST);

		EXPECT_IDENT_AND_GRAB_S(node->ident);

		EXPECT(PunctColon);

		JUST_PARSE_AND_POP_AST_NODE
		(
			node->modnm, _parseFlingModnm,
			node->arg_list, _parseFlingInstArgList
		);

		return std::nullopt;
	}

	#undef LIST
}
//--------

//--------
auto Parser::_parseFlingDeclModuleGen() -> ParseRet
{
	return _inner_parseFlingGen("_parseFlingDeclModuleGen",
		MEMB_FUNC(_parseFlingDeclModuleGenIf),
		MEMB_FUNC(_parseFlingDeclModuleGenSwitchEtc),
		MEMB_FUNC(_parseFlingDeclModuleGenFor));
}
auto Parser::_parseFlingDeclModuleGenIf() -> ParseRet
{
	return _inner_parseFlingGenIf
		("_parseFlingDeclModuleGenIf",
		MEMB_FUNC(_parseFlingDeclModuleScope));
}
auto Parser::_parseFlingDeclModuleGenSwitchEtc() -> ParseRet
{
	return _inner_parseFlingGenSwitchEtc
		("_parseFlingDeclModuleGenSwitchEtc",
		MEMB_FUNC(_parseFlingDeclModuleGenCase),
		MEMB_FUNC(_parseFlingDeclModuleGenDefault));
}
auto Parser::_parseFlingDeclModuleGenCase() -> ParseRet
{
	return _inner_parseFlingGenCase
		("_parseFlingDeclModuleGenCase",
		MEMB_FUNC(_parseFlingDeclModuleScope));
}
auto Parser::_parseFlingDeclModuleGenDefault() -> ParseRet
{
	return _inner_parseFlingGenDefault
		("_parseFlingDeclModuleGenDefault",
		MEMB_FUNC(_parseFlingDeclModuleScope));
}
auto Parser::_parseFlingDeclModuleGenFor() -> ParseRet
{
	return _inner_parseFlingGenFor
		("_parseFlingDeclModuleGenFor",
		MEMB_FUNC(_parseFlingDeclModuleScope));
}
//--------

//--------
auto Parser::_parseFlingDeclModuleBehav() -> ParseRet
{
	#define LIST(X) \
		X \
		( \
			_parseFlingDeclModuleBehavComb, \
			_parseFlingDeclModuleBehavSeq \
		)
	if (just_get_valid_tokens())
	{
		return LIST(GET_VALID_TOK_SET);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehav);

		START_PARSE_IFELSE(LIST);

		return std::nullopt;
	}

	#undef LIST
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
		DEFER_PUSH_NODE(node, DeclModuleBehavComb);

		EXPECT(KwComb);

		JUST_PARSE_AND_POP_AST_NODE
			(node->scope, _parseFlingDeclModuleScope);

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
		DEFER_PUSH_NODE(node, DeclModuleBehavSeq);

		EXPECT(KwSeq);

		do
		{
			_parseFlingDeclModuleBehavSeqEdgeItem();
			node->edge_item_list.push_back(_pop_ast_node());
		} while (ATTEMPT_TOK_PARSE(PunctComma));

		JUST_PARSE_AND_POP_AST_NODE
			(node->scope, _parseFlingDeclModuleBehavScope);

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
			(node->expr, _parseFlingExpr);

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
		DEFER_PUSH_NODE(node, Scope);

		EXPECT(PunctLbrace);

		while (ATTEMPT_PARSE(_parseFlingDeclModuleBehavScopeItem))
		{
			node->item_list.push_back(_pop_ast_node());
		}

		EXPECT(PunctRbrace);

		return std::nullopt;
	}
}
auto Parser::_parseFlingDeclModuleBehavScopeItem() -> ParseRet
{
	#define LIST(X) \
		X \
		( \
			_parseFlingDeclModuleBehavScope, \
			\
			_parseFlingDeclModuleBehavScopeItemIf, \
			_parseFlingDeclModuleBehavScopeItemSwitchEtc, \
			_parseFlingDeclModuleBehavScopeItemFor, \
			_parseFlingDeclModuleBehavScopeItemWhile, \
			\
			_parseFlingDeclModuleBehavScopeItemGen, \
			\
			_parseFlingAnyBehavScopeItem \
		)
	if (just_get_valid_tokens())
	{
		return LIST(GET_VALID_TOK_SET);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingDeclModuleBehavScopeItem);

		START_PARSE_IFELSE(LIST);

		return std::nullopt;
	}
	#undef LIST
}
auto Parser::_parseFlingDeclModuleBehavScopeItemIf() -> ParseRet
{
	return _inner_parseFlingIf("_parseFlingDeclModuleBehavScopeItemIf",
		MEMB_FUNC(_parseFlingDeclModuleBehavScope));
}
auto Parser::_parseFlingDeclModuleBehavScopeItemSwitchEtc() -> ParseRet
{
	return _inner_parseFlingSwitchEtc
		("_parseFlingDeclModuleBehavScopeItemSwitchEtc",
		MEMB_FUNC(_parseFlingDeclModuleBehavScopeItemCase),
		MEMB_FUNC(_parseFlingDeclModuleBehavScopeItemDefault));
}
auto Parser::_parseFlingDeclModuleBehavScopeItemCase() -> ParseRet
{
	return _inner_parseFlingCase
		("_parseFlingDeclModuleBehavScopeItemCase",
		MEMB_FUNC(_parseFlingDeclModuleBehavScope));
}
auto Parser::_parseFlingDeclModuleBehavScopeItemDefault() -> ParseRet
{
	return _inner_parseFlingDefault
		("_parseFlingDeclModuleBehavScopeItemDefault",
		MEMB_FUNC(_parseFlingDeclModuleBehavScope));
}
auto Parser::_parseFlingDeclModuleBehavScopeItemFor() -> ParseRet
{
	return _inner_parseFlingFor
		("_parseFlingDeclModuleBehavScopeItemFor",
		MEMB_FUNC(_parseFlingDeclModuleBehavScope));
}
auto Parser::_parseFlingDeclModuleBehavScopeItemWhile() -> ParseRet
{
	return _inner_parseFlingWhile
		("_parseFlingDeclModuleBehavScopeItemWhile",
		MEMB_FUNC(_parseFlingDeclModuleBehavScope));
}
//--------

//--------
auto Parser::_parseFlingDeclModuleBehavScopeItemGen() -> ParseRet
{
	return _inner_parseFlingGen("_parseFlingDeclModuleBehavScopeItemGen",
		MEMB_FUNC(_parseFlingDeclModuleBehavScopeItemGenIf),
		MEMB_FUNC(_parseFlingDeclModuleBehavScopeItemGenSwitchEtc),
		MEMB_FUNC(_parseFlingDeclModuleBehavScopeItemGenFor));
}
auto Parser::_parseFlingDeclModuleBehavScopeItemGenIf() -> ParseRet
{
	return _inner_parseFlingGenIf
		("_parseFlingDeclModuleBehavScopeItemGenIf",
		MEMB_FUNC(_parseFlingDeclModuleBehavScope));
}
auto Parser::_parseFlingDeclModuleBehavScopeItemGenSwitchEtc() -> ParseRet
{
	return _inner_parseFlingGenSwitchEtc
		("_parseFlingDeclModuleBehavScopeItemGenSwitchEtc",
		MEMB_FUNC(_parseFlingDeclModuleBehavScopeItemGenCase),
		MEMB_FUNC(_parseFlingDeclModuleBehavScopeItemGenDefault));
}
auto Parser::_parseFlingDeclModuleBehavScopeItemGenCase() -> ParseRet
{
	return _inner_parseFlingGenCase
		("_parseFlingDeclModuleBehavScopeItemGenCase",
		MEMB_FUNC(_parseFlingDeclModuleBehavScope));
}
auto Parser::_parseFlingDeclModuleBehavScopeItemGenDefault() -> ParseRet
{
	return _inner_parseFlingGenDefault
		("_parseFlingDeclModuleBehavScopeItemGenDefault",
		MEMB_FUNC(_parseFlingDeclModuleBehavScope));
}
auto Parser::_parseFlingDeclModuleBehavScopeItemGenFor() -> ParseRet
{
	return _inner_parseFlingGenFor
		("_parseFlingDeclModuleBehavScopeItemGenFor",
		MEMB_FUNC(_parseFlingDeclModuleBehavScope));
}
//--------

//--------
auto Parser::_parseFlingAnyBehavScopeItem() -> ParseRet
{
	#define LIST(X) \
		X \
		( \
			_parseFlingDeclConst, \
			_parseFlingDeclVar, \
			\
			_parseFlingDeclCompositeType, \
			_parseFlingDeclEnum, \
			\
			_parseFlingDeclSubprog, \
			\
			_parseFlingAnyBehavScopeItemStWithIdent, \
			_parseFlingAnyBehavScopeItemStWithCat \
		)
		
	if (just_get_valid_tokens())
	{
		return LIST(GET_VALID_TOK_SET);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingAnyBehavScopeItem);

		START_PARSE_IFELSE(LIST);

		return std::nullopt;
	}

	#undef LIST
}
auto Parser::_parseFlingAnyBehavScopeItemStWithIdent() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parseFlingAnyBehavScopeItemStWithIdent);

		string ident;
		EXPECT_IDENT_AND_GRAB_S(ident);

		BaseUptr ie_suffix;

		if (ATTEMPT_PARSE(_parseFlingIdentExprSuffix))
		{
			ie_suffix = _pop_ast_node();
		}
		else if (ATTEMPT_PARSE(_parseFlingAnyBehavScopeItemAssignSuffix))
		{
		}

		return std::nullopt;
	}
}
auto Parser::_parseFlingAnyBehavScopeItemStWithCat() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parseFlingAssignLhsCatExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parseFlingAnyBehavScopeItemStWithCat);

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
	return _inner_parseFlingGen("_parseFlingDeclStructScopeItemGen",
		MEMB_FUNC(_parseFlingDeclStructScopeItemGenIf),
		MEMB_FUNC(_parseFlingDeclStructScopeItemGenSwitchEtc),
		MEMB_FUNC(_parseFlingDeclStructScopeItemGenFor));
}
auto Parser::_parseFlingDeclStructScopeItemGenIf() -> ParseRet
{
	return _inner_parseFlingGenIf
		("_parseFlingDeclStructScopeItemGenIf",
		MEMB_FUNC(_parseFlingDeclStructScope));
}
auto Parser::_parseFlingDeclStructScopeItemGenSwitchEtc() -> ParseRet
{
	return _inner_parseFlingGenSwitchEtc
		("_parseFlingDeclStructScopeItemGenSwitchEtc",
		MEMB_FUNC(_parseFlingDeclStructScopeItemGenCase),
		MEMB_FUNC(_parseFlingDeclStructScopeItemGenDefault));
}
auto Parser::_parseFlingDeclStructScopeItemGenCase() -> ParseRet
{
	return _inner_parseFlingGenCase
		("_parseFlingDeclStructScopeItemGenCase",
		MEMB_FUNC(_parseFlingDeclStructScope));
}
auto Parser::_parseFlingDeclStructScopeItemGenDefault() -> ParseRet
{
	return _inner_parseFlingGenDefault
		("_parseFlingDeclStructScopeItemGenDefault",
		MEMB_FUNC(_parseFlingDeclStructScope));
}
auto Parser::_parseFlingDeclStructScopeItemGenFor() -> ParseRet
{
	return _inner_parseFlingGenFor
		("_parseFlingDeclStructScopeItemGenFor",
		MEMB_FUNC(_parseFlingDeclStructScope));
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
	return _inner_parseFlingIf("_parseFlingDeclSubprogScopeItemIf",
		MEMB_FUNC(_parseFlingDeclSubprogScope));
}
auto Parser::_parseFlingDeclSubprogScopeItemSwitchEtc() -> ParseRet
{
	return _inner_parseFlingSwitchEtc
		("_parseFlingDeclSubprogScopeItemSwitchEtc",
		MEMB_FUNC(_parseFlingDeclSubprogScopeItemCase),
		MEMB_FUNC(_parseFlingDeclSubprogScopeItemDefault));
}
auto Parser::_parseFlingDeclSubprogScopeItemCase() -> ParseRet
{
	return _inner_parseFlingCase
		("_parseFlingDeclSubprogScopeItemCase",
		MEMB_FUNC(_parseFlingDeclSubprogScope));
}
auto Parser::_parseFlingDeclSubprogScopeItemDefault() -> ParseRet
{
	return _inner_parseFlingDefault
		("_parseFlingDeclSubprogScopeItemDefault",
		MEMB_FUNC(_parseFlingDeclSubprogScope));
}
auto Parser::_parseFlingDeclSubprogScopeItemFor() -> ParseRet
{
	return _inner_parseFlingFor
		("_parseFlingDeclSubprogScopeItemFor",
		MEMB_FUNC(_parseFlingDeclSubprogScope));
}
auto Parser::_parseFlingDeclSubprogScopeItemWhile() -> ParseRet
{
	return _inner_parseFlingWhile
		("_parseFlingDeclSubprogScopeItemWhile",
		MEMB_FUNC(_parseFlingDeclSubprogScope));
}
//--------

//--------
auto Parser::_parseFlingDeclSubprogScopeItemGen() -> ParseRet
{
	return _inner_parseFlingGen("_parseFlingDeclSubprogScopeItemGen",
		MEMB_FUNC(_parseFlingDeclSubprogScopeItemGenIf),
		MEMB_FUNC(_parseFlingDeclSubprogScopeItemGenSwitchEtc),
		MEMB_FUNC(_parseFlingDeclSubprogScopeItemGenFor));
}
auto Parser::_parseFlingDeclSubprogScopeItemGenIf() -> ParseRet
{
	return _inner_parseFlingGenIf
		("_parseFlingDeclSubprogScopeItemGenIf",
		MEMB_FUNC(_parseFlingDeclSubprogScope));
}
auto Parser::_parseFlingDeclSubprogScopeItemGenSwitchEtc() -> ParseRet
{
	return _inner_parseFlingGenSwitchEtc
		("_parseFlingDeclSubprogScopeItemGenSwitchEtc",
		MEMB_FUNC(_parseFlingDeclSubprogScopeItemGenCase),
		MEMB_FUNC(_parseFlingDeclSubprogScopeItemGenDefault));
}
auto Parser::_parseFlingDeclSubprogScopeItemGenCase() -> ParseRet
{
	return _inner_parseFlingGenCase
		("_parseFlingDeclSubprogScopeItemGenCase",
		MEMB_FUNC(_parseFlingDeclSubprogScope));
}
auto Parser::_parseFlingDeclSubprogScopeItemGenDefault() -> ParseRet
{
	return _inner_parseFlingGenDefault
		("_parseFlingDeclSubprogScopeItemGenDefault",
		MEMB_FUNC(_parseFlingDeclSubprogScope));
}
auto Parser::_parseFlingDeclSubprogScopeItemGenFor() -> ParseRet
{
	return _inner_parseFlingGenFor
		("_parseFlingDeclSubprogScopeItemGenFor",
		MEMB_FUNC(_parseFlingDeclSubprogScope));
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
				_parseFlingIdentExprStart
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

//--------
auto Parser::_inner_parseFlingIf(string&& func_name,
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
			node->if_expr, _parseFlingExpr,
		);

		_call_parse_func(scope_func);
		node->if_scope = _pop_ast_node();

		while (ATTEMPT_TOK_PARSE(KwElif))
		{
			{
				DEFER_PUSH_NODE(elif_node, BehavElif);
				JUST_PARSE_AND_POP_AST_NODE
				(
					elif_node->expr, _parseFlingExpr,
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
auto Parser::_inner_parseFlingSwitchEtc(string&& func_name,
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
			(node->expr, _parseFlingExpr);

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
auto Parser::_inner_parseFlingCase(string&& func_name,
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
			(node->expr_list, _parseFlingExprList);

		_call_parse_func(scope_func);
		node->scope = _pop_ast_node();

		return std::nullopt;
	}
}
auto Parser::_inner_parseFlingDefault(string&& func_name,
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
auto Parser::_inner_parseFlingFor(string&& func_name,
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
			(node->range, _parseFlingRange);

		_call_parse_func(scope_func);
		node->scope = _pop_ast_node();

		return std::nullopt;
	}
}
auto Parser::_inner_parseFlingWhile(string&& func_name,
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
			(node->expr, _parseFlingExpr);

		_call_parse_func(scope_func);
		node->scope = _pop_ast_node();

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_inner_parseFlingGen(string&& func_name,
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
auto Parser::_inner_parseFlingGenIf(string&& func_name,
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
			node->if_expr, _parseFlingExpr,
		);

		_call_parse_func(scope_func);
		node->if_scope = _pop_ast_node();

		while (ATTEMPT_TOK_PARSE(KwGenElif))
		{
			{
				DEFER_PUSH_NODE(gen_elif_node, GenElif);
				JUST_PARSE_AND_POP_AST_NODE
				(
					gen_elif_node->expr, _parseFlingExpr,
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
auto Parser::_inner_parseFlingGenSwitchEtc(string&& func_name,
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
			(node->expr, _parseFlingExpr);

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
auto Parser::_inner_parseFlingGenCase(string&& func_name,
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
			(node->expr_list, _parseFlingExprList);

		_call_parse_func(scope_func);
		node->scope = _pop_ast_node();

		return std::nullopt;
	}
}
auto Parser::_inner_parseFlingGenDefault(string&& func_name,
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
auto Parser::_inner_parseFlingGenFor(string&& func_name,
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
			(node->range, _parseFlingRange);

		_call_parse_func(scope_func);
		node->scope = _pop_ast_node();

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
