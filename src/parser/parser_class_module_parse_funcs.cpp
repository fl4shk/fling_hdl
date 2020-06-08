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
					DEFER_PUSH_NODE(start, IdentExprStart);
					defer(_, start->item_list.push_back(_pop_ast_node()););
					{
						DEFER_PUSH_NODE(to_push, StrAndNode);
						to_push->str = move(ident);
					}
				}
				ident_expr->start = _pop_ast_node();

				PARSE_AND_POP_AST_NODE_IF
					(ident_expr->opt_suffix, _parse_flingIdentExprSuffix);
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
				DEFER_PUSH_NODE(start, IdentExprStart);
				{
					DEFER_PUSH_NODE(to_push, StrAndNode);
					to_push->str = move(ident);

					PARSE_AND_POP_AST_NODE_IF
						(to_push->node, _parse_flingInstParamList);
				}
				start->item_list.push_back(_pop_ast_node());

				while (ATTEMPT_PARSE(_parse_flingTypenmCstmChainItem))
				{
					start->item_list.push_back(_pop_ast_node());
				}
			}
			node->start = _pop_ast_node();

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


} // namespace fling_hdl
