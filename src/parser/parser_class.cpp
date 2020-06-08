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
