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

#ifndef src_parser_class_hpp
#define src_parser_class_hpp

// src/parser_class.hpp

#include "misc_includes.hpp"
#include "lexer_class.hpp"
#include "ast/ast_node_classes.hpp"

namespace fling_hdl
{

class TempAstNodeDeferredRestorer;
class AstNodeDeferredBase;
class AstNodeDeferredPusher;
class AstNodeListDeferredPusher;
class IdentListDeferredPusher;

class Parser final: public RdParserBase<Lexer, Parser>
{
	friend class TempAstNodeDeferredRestorer;
	friend class AstNodeDeferredBase;
	friend class AstNodeDeferredPusher;
	friend class AstNodeListDeferredPusher;
	friend class IdentListDeferredPusher;

public:		// types
	using ParserBase = RdParserBase<Lexer, Parser>;
	using IdentList = IndCircLinkList<pair<string, FilePos>>;
	using ParseFunc = ParserBase::ParseFunc;

private:		// variables
	size_t _max_ast_level;

	ast::BaseUptr _ast;
	ast::Program* _ast_program = nullptr;
	ast::Base* _curr_ast_parent = nullptr;

	ast::BaseUptr* _temp_ast = nullptr;
	//ast::IdentExprSuffix _ident_expr_suffix;

	stack<IdentList> _ident_list_stack;
	stack<ast::BaseUptr> _ast_node_stack;
	stack<ast::BaseUptrList> _ast_list_stack;
	string _parse_func_str;

public:		// misc. functions
	template<typename Type>
	static inline Type* as(ast::BaseUptr& base_sptr)
	{
		return static_cast<Type*>(base_sptr.get());
	}

private:		// misc. functions
	inline void _push_ident_list(IdentList&& to_push)
	{
		_ident_list_stack.push(move(to_push));
	}
	inline void _pop_ident_list(IdentList& to_set)
	{
		to_set = move(_ident_list_stack.top());
		_ident_list_stack.pop();
	}
	inline IdentList _pop_ident_list()
	{
		IdentList ret;
		_pop_ident_list(ret);
		return ret;
	}

	inline void _push_ast_node(ast::Base* to_push)
	{
		_ast_node_stack.push(ast::BaseUptr(to_push));
	}
	inline void _pop_ast_node(ast::BaseUptr& to_set)
	{
		to_set = move(_ast_node_stack.top());
		_ast_node_stack.top().reset(nullptr);
		_ast_node_stack.pop();
	}
	inline ast::BaseUptr _pop_ast_node()
	{
		ast::BaseUptr ret;
		_pop_ast_node(ret);
		return ret;
	}

	inline void _push_ast_list(ast::BaseUptrList&& to_push)
	{
		_ast_list_stack.push(move(to_push));
	}
	inline void _pop_ast_list(ast::BaseUptrList& to_set)
	{
		to_set = move(_ast_list_stack.top());
		_ast_list_stack.pop();
	}
	inline ast::BaseUptrList _pop_ast_list()
	{
		ast::BaseUptrList ret;
		_pop_ast_list(ret);
		return ret;
	}

	virtual inline void _internal_err(const string& func,
		const string& msg="") const
	{
		ParserBase::_internal_err(sconcat("Parser::", func), msg);
	}

public:		// functions
	Parser(const string& s_filename);
	GEN_NO_CM_CONSTRUCTORS_AND_ASSIGN(Parser);
	virtual inline ~Parser() = default;

	int run();

	GEN_GETTER_BY_VAL(max_ast_level);

public:		// parsing functions
	//--------
	ParseRet _parseFlingProgram();
	//--------

	//--------
	ParseRet _parseFlingDeclPackage();
	ParseRet _parseFlingDeclPackageItem();
	ParseRet _parseFlingImport();
	//--------

	//--------
	ParseRet _parseFlingDeclParamList();
	ParseRet _parseFlingDeclParamSublist();
	ParseRet _parseFlingDeclArgList();
	ParseRet _parseFlingDeclArgSublist();
	ParseRet _parseFlingInstParamList();
	ParseRet _parseFlingInstParamListItem();
	ParseRet _parseFlingInstParamListItemPos();
	ParseRet _parseFlingInstParamListItemNamed();
	ParseRet _parseFlingInstArgList();
	ParseRet _parseFlingInstArgListItem();
	ParseRet _parseFlingInstArgListItemPos();
	ParseRet _parseFlingInstArgListItemNamed();
	//--------

	//--------
	ParseRet _parseFlingDeclModule();
	ParseRet _parseFlingDeclModuleScope();
	ParseRet _parseFlingDeclModuleItem();
	//--------

	//--------
	ParseRet _parseFlingModinst();
	//--------

	//--------
	ParseRet _parseFlingDeclModuleGen();
	ParseRet _parseFlingDeclModuleGenIf();
	ParseRet _parseFlingDeclModuleGenSwitchEtc();
	ParseRet _parseFlingDeclModuleGenCase();
	ParseRet _parseFlingDeclModuleGenDefault();
	ParseRet _parseFlingDeclModuleGenFor();
	//--------

	//--------
	ParseRet _parseFlingDeclModuleBehav();
	ParseRet _parseFlingDeclModuleBehavComb();
	ParseRet _parseFlingDeclModuleBehavSeq();
	ParseRet _parseFlingDeclModuleBehavSeqEdgeItem();
	ParseRet _parseFlingDeclModuleBehavScope();
	ParseRet _parseFlingDeclModuleBehavScopeItem();
	ParseRet _parseFlingDeclModuleBehavScopeItemIf();
	ParseRet _parseFlingDeclModuleBehavScopeItemSwitchEtc();
	ParseRet _parseFlingDeclModuleBehavScopeItemCase();
	ParseRet _parseFlingDeclModuleBehavScopeItemDefault();
	ParseRet _parseFlingDeclModuleBehavScopeItemFor();
	ParseRet _parseFlingDeclModuleBehavScopeItemWhile();
	//--------

	//--------
	ParseRet _parseFlingDeclModuleBehavScopeItemGen();
	ParseRet _parseFlingDeclModuleBehavScopeItemGenIf();
	ParseRet _parseFlingDeclModuleBehavScopeItemGenSwitchEtc();
	ParseRet _parseFlingDeclModuleBehavScopeItemGenCase();
	ParseRet _parseFlingDeclModuleBehavScopeItemGenDefault();
	ParseRet _parseFlingDeclModuleBehavScopeItemGenFor();
	//--------

	//--------
	ParseRet _parseFlingAnyBehavScopeItem();
	ParseRet _parseFlingAnyBehavScopeItemStWithIdent();
	ParseRet _parseFlingAnyBehavScopeItemStWithCat();
	ParseRet _parseFlingAnyBehavScopeItemAssignSuffix();
	//--------

	//--------
	ParseRet _parseFlingDeclCompositeType();
	//--------

	//--------
	ParseRet _parseFlingDeclStruct();
	ParseRet _parseFlingDeclStructScope();
	ParseRet _parseFlingDeclStructScopeItem();
	//--------

	//--------
	ParseRet _parseFlingDeclStructScopeItemGen();
	ParseRet _parseFlingDeclStructScopeItemGenIf();
	ParseRet _parseFlingDeclStructScopeItemGenSwitchEtc();
	ParseRet _parseFlingDeclStructScopeItemGenCase();
	ParseRet _parseFlingDeclStructScopeItemGenDefault();
	ParseRet _parseFlingDeclStructScopeItemGenFor();
	//--------

	//--------
	ParseRet _parseFlingDeclEnum();
	ParseRet _parseFlingDeclEnumItem();
	//--------

	//--------
	ParseRet _parseFlingDeclSubprog();
	//--------

	//--------
	ParseRet _parseFlingDeclFuncHeader();
	ParseRet _parseFlingDeclTaskHeader();
	//--------

	//--------
	ParseRet _parseFlingDeclSubprogScope();
	ParseRet _parseFlingDeclSubprogScopeItem();
	ParseRet _parseFlingDeclSubprogScopeItemIf();
	ParseRet _parseFlingDeclSubprogScopeItemSwitchEtc();
	ParseRet _parseFlingDeclSubprogScopeItemCase();
	ParseRet _parseFlingDeclSubprogScopeItemDefault();
	ParseRet _parseFlingDeclSubprogScopeItemFor();
	ParseRet _parseFlingDeclSubprogScopeItemWhile();
	//--------

	//--------
	ParseRet _parseFlingDeclSubprogScopeItemGen();
	ParseRet _parseFlingDeclSubprogScopeItemGenIf();
	ParseRet _parseFlingDeclSubprogScopeItemGenSwitchEtc();
	ParseRet _parseFlingDeclSubprogScopeItemGenCase();
	ParseRet _parseFlingDeclSubprogScopeItemGenDefault();
	ParseRet _parseFlingDeclSubprogScopeItemGenFor();
	//--------

	//--------
	ParseRet _parseFlingDeclConst();
	ParseRet _parseFlingDeclVarNoDefVal();
	ParseRet _parseFlingDeclVar();
	ParseRet _parseFlingDeclWire();
	ParseRet _parseFlingWireAssign();
	ParseRet _parseFlingDeclAlias();
	//--------

	//--------
	ParseRet _parseFlingScopedIdent();
	ParseRet _parseFlingIdentList();
	ParseRet _parseFlingSubprogIdentList();
	ParseRet _parseFlingExprList();
	ParseRet _parseFlingRangeList();
	ParseRet _parseFlingTypenmList();
	ParseRet _parseFlingModnmList();
	ParseRet _parseFlingImportItem();
	ParseRet _parseFlingImportItemList();
	//--------

	//--------
	ParseRet _parseFlingExpr();
	ParseRet _parseFlingMuxExpr();
	ParseRet _parseFlingLogorExpr();
	ParseRet _parseFlingLogandExpr();
	ParseRet _parseFlingCmpEqEtcExpr();
	ParseRet _parseFlingCmpLtEtcExpr();
	ParseRet _parseFlingPlusMinusExpr();
	ParseRet _parseFlingMulDivModExpr();
	ParseRet _parseFlingBitorBitnorExpr();
	ParseRet _parseFlingBitandBitnandExpr();
	ParseRet _parseFlingBitxorBitxnorExpr();
	ParseRet _parseFlingBitshiftExpr();
	ParseRet _parseFlingUnaryExpr();
	ParseRet _parseFlingLowExpr();
	ParseRet _parseFlingCallDollarFuncExpr();
	ParseRet _parseFlingSubprogIdent();
	ParseRet _parseFlingAssignLhsIdentExpr();
	ParseRet _parseFlingAssignLhsCatExpr();
	ParseRet _parseFlingIdentExprSuffix();
	ParseRet _parseFlingIdentExprStart();
	ParseRet _parseFlingIdentExpr();
	ParseRet _parseFlingCatExpr();
	ParseRet _parseFlingReplExpr();
	ParseRet _parseFlingSizedExpr();
	//--------

	//--------
	ParseRet _parseFlingRange();
	ParseRet _parseFlingNonSimpleRange();
	ParseRet _parseFlingSimpleRangeSuffix();
	ParseRet _parseFlingExprOrRange();
	//--------

	//--------
	ParseRet _parseFlingTypenmCstmChainItem();
	ParseRet _parseFlingTypenm();
	ParseRet _parseFlingModnm();
	//--------

	//--------
	ParseRet _inner_parseFlingIf(string&& func_name,
		const ParseFunc& scope_func);
	ParseRet _inner_parseFlingSwitchEtc(string&& func_name,
		const ParseFunc& case_func, const ParseFunc& default_func);
	ParseRet _inner_parseFlingCase(string&& func_name,
		const ParseFunc& scope_func);
	ParseRet _inner_parseFlingDefault(string&& func_name,
		const ParseFunc& scope_func);
	ParseRet _inner_parseFlingFor(string&& func_name,
		const ParseFunc& scope_func);
	ParseRet _inner_parseFlingWhile(string&& func_name,
		const ParseFunc& scope_func);
	//--------

	//--------
	ParseRet _inner_parseFlingGen(string&& func_name,
		const ParseFunc& gen_if_func, const ParseFunc& gen_switch_etc_func,
		const ParseFunc& gen_for_func);
	ParseRet _inner_parseFlingGenIf(string&& func_name,
		const ParseFunc& scope_func);
	ParseRet _inner_parseFlingGenSwitchEtc(string&& func_name,
		const ParseFunc& gen_case_func, const ParseFunc& gen_default_func);
	ParseRet _inner_parseFlingGenCase(string&& func_name,
		const ParseFunc& scope_func);
	ParseRet _inner_parseFlingGenDefault(string&& func_name,
		const ParseFunc& scope_func);
	ParseRet _inner_parseFlingGenFor(string&& func_name,
		const ParseFunc& scope_func);
	//--------

	#define X(name, dummy_0) \
		ParseRet _parseTok##name();
	LIST_OF_TOKENS(X)
	#undef X
};

class TempAstNodeDeferredRestorer final
{
private:		// variables
	Parser* _parser = nullptr;
	ast::BaseUptr* _prev_temp_ast = nullptr;
public:		// functions
	inline TempAstNodeDeferredRestorer(Parser* s_parser,
		ast::BaseUptr& s_temp_ast)
		: _parser(s_parser)
	{
		_prev_temp_ast = _parser->_temp_ast;
		_parser->_temp_ast = &s_temp_ast;
	}
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(TempAstNodeDeferredRestorer);
	inline ~TempAstNodeDeferredRestorer()
	{
		_parser->_temp_ast = _prev_temp_ast;
	}
};

class AstNodeDeferredBase
{
protected:		// variables
	Parser* _parser = nullptr;
	ast::Base * _node = nullptr,
		* _prev_ast_parent = nullptr;

public:		// functions
	inline AstNodeDeferredBase(Parser* s_parser, ast::Base* s_node)
		: _parser(s_parser), _node(s_node)
	{
		_prev_ast_parent = _parser->_curr_ast_parent;
		_parser->_curr_ast_parent = _node;

		if (_parser->max_ast_level() < _node->level())
		{
			_parser->_max_ast_level = _node->level();
		}
	}
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(AstNodeDeferredBase);
	virtual inline ~AstNodeDeferredBase()
	{
		_parser->_curr_ast_parent = _prev_ast_parent;
	}
};
class AstNodeDeferredPusher final: public AstNodeDeferredBase
{
public:		// functions
	inline AstNodeDeferredPusher(Parser* s_parser, ast::Base* s_node)
		: AstNodeDeferredBase(s_parser, s_node)
	{
	}
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(AstNodeDeferredPusher);
	virtual inline ~AstNodeDeferredPusher()
	{
		_parser->_push_ast_node(_node);
	}
};

class AstNodeListDeferredPusher final
{
private:		// variables
	Parser* _parser = nullptr;
	ast::BaseUptrList* _node_list = nullptr;
public:		// functions
	inline AstNodeListDeferredPusher(Parser* s_parser,
		ast::BaseUptrList* s_node_list)
		: _parser(s_parser), _node_list(s_node_list)
	{
	}
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(AstNodeListDeferredPusher);
	inline ~AstNodeListDeferredPusher()
	{
		_parser->_push_ast_list(move(*_node_list));
	}
};

class IdentListDeferredPusher final
{
private:		// variables
	Parser* _parser = nullptr;
	Parser::IdentList* _list = nullptr;
public:		// functions
	inline IdentListDeferredPusher(Parser* s_parser,
		Parser::IdentList* s_list)
		: _parser(s_parser), _list(s_list)
	{
	}
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(IdentListDeferredPusher);
	inline ~IdentListDeferredPusher()
	{
		_parser->_push_ident_list(move(*_list));
	}
};

} // namespace fling_hdl


#endif		// src_parser_class_hpp
