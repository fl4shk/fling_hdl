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
	#define LIST(X) \
		X \
		( \
			_parse_flingLitNumExpr, \
			_parse_flingLitHighImpedExpr, \
			_parse_flingLitUnknExpr, \
			_parse_flingParenExpr, \
			\
			_parse_flingCallDollarFuncExpr, \
			\
			_parse_flingIdentExpr, \
			\
			_parse_flingCatExpr, \
			_parse_flingReplExpr, \
			_parse_flingSizedExpr \
		)
	if (just_get_valid_tokens())
	{
		return LIST(GET_VALID_TOK_SET);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingLowExpr);

		START_PARSE_IFELSE(LIST);

		return std::nullopt;
	}
	#undef LIST
}
auto Parser::_parse_flingLitNumExpr() -> ParseRet
{
	#define LIST(X) \
		X \
		( \
			TOK_PARSE_FUNC(LitDecNum), \
			TOK_PARSE_FUNC(LitHexNum), \
			TOK_PARSE_FUNC(LitOctNum), \
			TOK_PARSE_FUNC(LitBinNum) \
		)

	if (just_get_valid_tokens())
	{
		return LIST(GET_VALID_TOK_SET);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingLitNumExpr);

		DEFER_PUSH_NODE(node, LitValExpr);

		START_PARSE_IFELSE(LIST);

		node->kind = LitValExpr::Kind::Number;
		node->opt_num_str = prev_lex_s();
		node->opt_num = prev_lex_n();

		return std::nullopt;
	}

	#undef LIST
}
auto Parser::_parse_flingLitHighImpedExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwHighImped)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingLitHighImpedExpr);

		DEFER_PUSH_NODE(node, LitValExpr);

		EXPECT(KwHighImped);

		node->kind = LitValExpr::Kind::HighImped;

		if (ATTEMPT_TOK_PARSE(PunctLparen))
		{
			JUST_PARSE_AND_POP_AST_NODE
				(node->opt_expr, _parse_flingExpr);

			EXPECT(PunctRparen);
		}

		return std::nullopt;
	}
}
auto Parser::_parse_flingLitUnknExpr() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwUnkn)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingLitUnknExpr);

		DEFER_PUSH_NODE(node, LitValExpr);

		EXPECT(KwUnkn);

		node->kind = LitValExpr::Kind::Unknown;

		if (ATTEMPT_TOK_PARSE(PunctLparen))
		{
			JUST_PARSE_AND_POP_AST_NODE
				(node->opt_expr, _parse_flingExpr);

			EXPECT(PunctRparen);
		}

		return std::nullopt;
	}
}
auto Parser::_parse_flingParenExpr() -> ParseRet
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
		PROLOGUE_AND_EPILOGUE(_parse_flingParenExpr);

		EXPECT(PunctLparen);
		_parse_flingExpr();
		EXPECT(PunctRparen);

		return std::nullopt;
	}
}

auto Parser::_parse_flingCallDollarFuncExpr() -> ParseRet
{
	#define LIST(X) \
		X \
		( \
			TOK_PARSE_FUNC(KwDollarSize), \
			TOK_PARSE_FUNC(KwDollarHigh), \
			TOK_PARSE_FUNC(KwDollarLow), \
			\
			TOK_PARSE_FUNC(KwDollarUnsigned), \
			TOK_PARSE_FUNC(KwDollarSigned), \
			\
			TOK_PARSE_FUNC(KwDollarIsUnsigned), \
			TOK_PARSE_FUNC(KwDollarIsSigned), \
			\
			TOK_PARSE_FUNC(KwDollarPow) \
		)

	if (just_get_valid_tokens())
	{
		return LIST(GET_VALID_TOK_SET);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingCallDollarFuncExpr);
		DEFER_PUSH_NODE(node, CallDollarFuncExpr);

		START_PARSE_IFELSE(LIST);

		if (prev_lex_tok() != Tok::KwDollarPow)
		{
			if (ATTEMPT_PARSE(_parse_flingExpr)
				|| ATTEMPT_PARSE(_parse_flingTypenm))
			{
				node->arg = _pop_ast_node();
			}
			else
			{
				_expect_wanted_tok();
			}
		}
		else // if (prev_lex_tok() == Tok::KwDollarPow)
		{
			EXPECT(PunctLparen);
			JUST_PARSE_AND_POP_AST_NODE
				(node->arg, _parse_flingExpr);
			EXPECT(PunctComma);
			JUST_PARSE_AND_POP_AST_NODE
				(node->opt_second_arg, _parse_flingExpr);
			EXPECT(PunctRparen);
		}

		return std::nullopt;
	}

	#undef LIST
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

		DEFER_PUSH_NODE(node, IdentExpr);

		{
			DEFER_PUSH_NODE(start, IdentExprStart);
			defer(_, start->item_list.push_back(_pop_ast_node()););
			{
				DEFER_PUSH_NODE(str_and_node, StrAndNode);
				EXPECT_IDENT_AND_GRAB_S(str_and_node->str);
			}
		}
		node->start = _pop_ast_node();

		if (ATTEMPT_PARSE(_parse_flingIdentExprSuffix))
		{
			node->opt_suffix = _pop_ast_node();
		}

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
		DEFER_PUSH_NODE(node, CatExpr);

		EXPECT(KwCat);
		EXPECT(PunctLparen);

		do
		{
			_parse_flingAssignLhsIdentExpr();
			node->item_list.push_back(_pop_ast_node());
		} while (ATTEMPT_TOK_PARSE(PunctComma));

		EXPECT(PunctRparen);

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
		DEFER_PUSH_NODE(node, IdentExprSuffix);

		while (ATTEMPT_TOK_PARSE(PunctMemberAccess)
			|| ATTEMPT_TOK_PARSE(PunctLbracket))
		{
			if (prev_lex_tok() == Tok::PunctMemberAccess)
			{
				DEFER_PUSH_NODE(child, StrAndNode);
				EXPECT_IDENT_AND_GRAB_S(child->str);
			}
			else // if (prev_lex_tok() == Tok::PunctLbracket)
			{
				_parse_flingExpr();
				EXPECT(PunctRbracket);
			}
			node->acc_memb_or_arr_list.push_back(_pop_ast_node());
		}

		if (ATTEMPT_TOK_PARSE(PunctVecDimStart))
		{
			if (ATTEMPT_PARSE(_parse_flingExpr))
			{
				if (ATTEMPT_TOK_PARSE(PunctPlusColon)
					|| ATTEMPT_TOK_PARSE(PunctMinusColon))
				{
					DEFER_PUSH_NODE(ind_part_sel, IndexedPartSel);
					ind_part_sel->left = _pop_ast_node();

					using Kind = IndexedPartSel::Kind;

					if (prev_lex_tok() == Tok::PunctPlusColon)
					{
						ind_part_sel->kind = Kind::PlusColon;
					}
					else // if (prev_lex_tok() == Tok::PunctMinusColon)
					{
						ind_part_sel->kind = Kind::MinusColon;
					}

					JUST_PARSE_AND_POP_AST_NODE
						(ind_part_sel->right, _parse_flingExpr);
				}
				else 
				{
					DEFER_PUSH_NODE(range, NonDollarFuncRange);

					range->arg = _pop_ast_node();

					PARSE_AND_POP_AST_NODE_IF
						(range->opt_second_arg,
						_parse_flingSimpleRangeSuffix);
				}
			}
			else if (ATTEMPT_PARSE(_parse_flingNonSimpleRange))
			{
			}
			else
			{
				_expect_wanted_tok();
			}

			node->opt_range_etc = _pop_ast_node();

			EXPECT(PunctRbracket);
		}

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
		DEFER_PUSH_NODE(node, IdentExprStart);

		do
		{
			{
				DEFER_PUSH_NODE(str_and_node, StrAndNode);
				EXPECT_IDENT_AND_GRAB_S(str_and_node->str);
				PARSE_AND_POP_AST_NODE_IF
					(str_and_node->node, _parse_flingInstParamList);
			}
			node->item_list.push_back(_pop_ast_node());
		} while (ATTEMPT_TOK_PARSE(PunctScopeAccess));

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
		DEFER_PUSH_NODE(node, IdentExpr);

		JUST_PARSE_AND_POP_AST_NODE
			(node->start, _parse_flingIdentExprStart);
		PARSE_AND_POP_AST_NODE_IF
			(node->opt_arg_list, _parse_flingInstArgList);
		PARSE_AND_POP_AST_NODE_IF
			(node->opt_suffix, _parse_flingIdentExprSuffix);

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
		DEFER_PUSH_NODE(node, CatExpr);

		EXPECT(KwCat);
		EXPECT(PunctLparen);
		JUST_PARSE_AND_POP_AST_LIST
			(node->item_list, _parse_flingExprList);
		EXPECT(PunctRparen);

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
		DEFER_PUSH_NODE(node, ReplExpr);

		EXPECT(KwRepl);
		EXPECT(PunctLparen);
		JUST_PARSE_AND_POP_AST_NODE
			(node->amount, _parse_flingExpr);
		EXPECT(PunctComma);
		JUST_PARSE_AND_POP_AST_NODE
			(node->to_repl, _parse_flingExpr);
		EXPECT(PunctRparen);

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
		DEFER_PUSH_NODE(node, SizedExpr);

		EXPECT(KwSized);
		EXPECT(PunctLparen);
		JUST_PARSE_AND_POP_AST_NODE
			(node->lit_num, _parse_flingLitNumExpr);
		EXPECT(PunctComma);
		JUST_PARSE_AND_POP_AST_NODE
			(node->width, _parse_flingExpr);
		EXPECT(PunctRparen);

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

} // namespace fling_hdl
