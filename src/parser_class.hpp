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

	struct ParamVarEtcTriple
	{
		string ident;
		FilePos ident_fp;
		ast::BaseUptr expr;
	};

private:		// variables
	size_t _max_ast_level;

	ast::BaseUptr _ast;
	ast::Program* _ast_program = nullptr;
	ast::Base* _curr_ast_parent = nullptr;

	ast::Base* _temp_ast = nullptr;
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

private:		// functions
	vector<ParamVarEtcTriple> _build_pv_etc_vec
		(IdentList& ident_list, ast::BaseUptrList& expr_list,
		bool force_build_expr, const FilePos& err_file_pos,
		const string& err_msg) const;

public:		// parsing functions
	//--------
	ParseRet _parse_flingProgram();
	//--------

	//--------
	ParseRet _parse_flingDeclPackage();
	ParseRet _parse_flingDeclPackageItem();
	ParseRet _parse_flingImport();
	//--------

	//--------
	ParseRet _parse_flingDeclParamList();
	ParseRet _parse_flingDeclParamSublist();
	ParseRet _parse_flingDeclArgList();
	ParseRet _parse_flingDeclArgSublist();
	ParseRet _parse_flingInstParamList();
	ParseRet _parse_flingInstParamListItem();
	ParseRet _parse_flingInstParamListItemPos();
	ParseRet _parse_flingInstParamListItemNamed();
	ParseRet _parse_flingInstArgList();
	ParseRet _parse_flingInstArgListItem();
	ParseRet _parse_flingInstArgListItemPos();
	ParseRet _parse_flingInstArgListItemNamed();
	//--------

	//--------
	ParseRet _parse_flingDeclModule();
	ParseRet _parse_flingDeclModuleScope();
	ParseRet _parse_flingDeclModuleItem();
	//--------

	//--------
	ParseRet _parse_flingModinst();
	//--------

	//--------
	ParseRet _parse_flingDeclModuleGen();
	ParseRet _parse_flingDeclModuleGenIf();
	ParseRet _parse_flingDeclModuleGenSwitchEtc();
	ParseRet _parse_flingDeclModuleGenCase();
	ParseRet _parse_flingDeclModuleGenDefault();
	ParseRet _parse_flingDeclModuleGenFor();
	//--------

	//--------
	ParseRet _parse_flingDeclModuleBehav();
	ParseRet _parse_flingDeclModuleBehavComb();
	ParseRet _parse_flingDeclModuleBehavSeq();
	ParseRet _parse_flingDeclModuleBehavSeqEdgeItem();
	ParseRet _parse_flingDeclModuleBehavScope();
	ParseRet _parse_flingDeclModuleBehavScopeItem();
	ParseRet _parse_flingDeclModuleBehavScopeItemIf();
	ParseRet _parse_flingDeclModuleBehavScopeItemSwitchEtc();
	ParseRet _parse_flingDeclModuleBehavScopeItemCase();
	ParseRet _parse_flingDeclModuleBehavScopeItemDefault();
	ParseRet _parse_flingDeclModuleBehavScopeItemFor();
	ParseRet _parse_flingDeclModuleBehavScopeItemWhile();
	//--------

	//--------
	ParseRet _parse_flingDeclModuleBehavScopeItemGen();
	ParseRet _parse_flingDeclModuleBehavScopeItemGenIf();
	ParseRet _parse_flingDeclModuleBehavScopeItemGenSwitchEtc();
	ParseRet _parse_flingDeclModuleBehavScopeItemGenCase();
	ParseRet _parse_flingDeclModuleBehavScopeItemGenDefault();
	ParseRet _parse_flingDeclModuleBehavScopeItemGenFor();
	//--------

	//--------
	ParseRet _parse_flingAnyBehavScopeItem();
	ParseRet _parse_flingAnyBehavScopeItemStWithIdent();
	ParseRet _parse_flingAnyBehavScopeItemStWithCat();
	ParseRet _parse_flingAnyBehavScopeItemAssignSuffix();
	//--------

	//--------
	ParseRet _parse_flingDeclCompositeType();
	//--------

	//--------
	ParseRet _parse_flingDeclStruct();
	ParseRet _parse_flingDeclStructScope();
	ParseRet _parse_flingDeclStructScopeItem();
	//--------

	//--------
	ParseRet _parse_flingDeclStructScopeItemGen();
	ParseRet _parse_flingDeclStructScopeItemGenIf();
	ParseRet _parse_flingDeclStructScopeItemGenSwitchEtc();
	ParseRet _parse_flingDeclStructScopeItemGenCase();
	ParseRet _parse_flingDeclStructScopeItemGenDefault();
	ParseRet _parse_flingDeclStructScopeItemGenFor();
	//--------

	//--------
	ParseRet _parse_flingDeclEnum();
	ParseRet _parse_flingDeclEnumItem();
	//--------

	//--------
	ParseRet _parse_flingDeclSubprog();
	//--------

	//--------
	ParseRet _parse_flingDeclFuncHeader();
	ParseRet _parse_flingDeclTaskHeader();
	//--------

	//--------
	ParseRet _parse_flingDeclSubprogScope();
	ParseRet _parse_flingDeclSubprogScopeItem();
	ParseRet _parse_flingDeclSubprogScopeItemIf();
	ParseRet _parse_flingDeclSubprogScopeItemSwitchEtc();
	ParseRet _parse_flingDeclSubprogScopeItemCase();
	ParseRet _parse_flingDeclSubprogScopeItemDefault();
	ParseRet _parse_flingDeclSubprogScopeItemFor();
	ParseRet _parse_flingDeclSubprogScopeItemWhile();
	//--------

	//--------
	ParseRet _parse_flingDeclSubprogScopeItemGen();
	ParseRet _parse_flingDeclSubprogScopeItemGenIf();
	ParseRet _parse_flingDeclSubprogScopeItemGenSwitchEtc();
	ParseRet _parse_flingDeclSubprogScopeItemGenCase();
	ParseRet _parse_flingDeclSubprogScopeItemGenDefault();
	ParseRet _parse_flingDeclSubprogScopeItemGenFor();
	//--------

	//--------
	ParseRet _parse_flingDeclConst();
	ParseRet _parse_flingDeclVarNoDefVal();
	ParseRet _parse_flingDeclVar();
	ParseRet _parse_flingDeclWire();
	ParseRet _parse_flingWireAssign();
	ParseRet _parse_flingDeclAlias();
	//--------

	//--------
	ParseRet _parse_flingScopedIdent();
	ParseRet _parse_flingIdentList();
	ParseRet _parse_flingSubprogIdentList();
	ParseRet _parse_flingExprList();
	ParseRet _parse_flingRangeList();
	ParseRet _parse_flingTypenmList();
	ParseRet _parse_flingModnmList();
	ParseRet _parse_flingImportItem();
	ParseRet _parse_flingImportItemList();
	//--------

	//--------
	ParseRet _parse_flingExpr();
	ParseRet _parse_flingMuxExpr();
	ParseRet _parse_flingLogorExpr();
	ParseRet _parse_flingLogandExpr();
	ParseRet _parse_flingCmpEqEtcExpr();
	ParseRet _parse_flingCmpLtEtcExpr();
	ParseRet _parse_flingPlusMinusExpr();
	ParseRet _parse_flingMulDivModExpr();
	ParseRet _parse_flingBitorBitnorExpr();
	ParseRet _parse_flingBitandBitnandExpr();
	ParseRet _parse_flingBitxorBitxnorExpr();
	ParseRet _parse_flingBitshiftExpr();
	ParseRet _parse_flingUnaryExpr();
	ParseRet _parse_flingLowExpr();
	ParseRet _parse_flingCallDollarFuncExpr();
	ParseRet _parse_flingSubprogIdent();
	ParseRet _parse_flingAssignLhsIdentExpr();
	ParseRet _parse_flingAssignLhsCatExpr();
	ParseRet _parse_flingIdentExprSuffix();
	ParseRet _parse_flingIdentExprStart();
	ParseRet _parse_flingIdentExpr();
	ParseRet _parse_flingCatExpr();
	ParseRet _parse_flingReplExpr();
	ParseRet _parse_flingSizedExpr();
	//--------

	//--------
	ParseRet _parse_flingRange();
	ParseRet _parse_flingNonSimpleRange();
	ParseRet _parse_flingSimpleRangeSuffix();
	ParseRet _parse_flingExprOrRange();
	//--------

	//--------
	ParseRet _parse_flingTypenmCstmChainItem();
	ParseRet _parse_flingTypenm();
	ParseRet _parse_flingModnm();
	//--------

	//--------
	ParseRet _inner_parse_flingIf(string&& func_name,
		const ParseFunc& scope_func);
	ParseRet _inner_parse_flingSwitchEtc(string&& func_name,
		const ParseFunc& case_func, const ParseFunc& default_func);
	ParseRet _inner_parse_flingCase(string&& func_name,
		const ParseFunc& scope_func);
	ParseRet _inner_parse_flingDefault(string&& func_name,
		const ParseFunc& scope_func);
	ParseRet _inner_parse_flingFor(string&& func_name,
		const ParseFunc& scope_func);
	ParseRet _inner_parse_flingWhile(string&& func_name,
		const ParseFunc& scope_func);
	//--------

	//--------
	ParseRet _inner_parse_flingGen(string&& func_name,
		const ParseFunc& gen_if_func, const ParseFunc& gen_switch_etc_func,
		const ParseFunc& gen_for_func);
	ParseRet _inner_parse_flingGenIf(string&& func_name,
		const ParseFunc& scope_func);
	ParseRet _inner_parse_flingGenSwitchEtc(string&& func_name,
		const ParseFunc& gen_case_func, const ParseFunc& gen_default_func);
	ParseRet _inner_parse_flingGenCase(string&& func_name,
		const ParseFunc& scope_func);
	ParseRet _inner_parse_flingGenDefault(string&& func_name,
		const ParseFunc& scope_func);
	ParseRet _inner_parse_flingGenFor(string&& func_name,
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
	ast::Base* _prev_temp_ast = nullptr;
public:		// functions
	inline TempAstNodeDeferredRestorer(Parser* s_parser,
		ast::Base* s_temp_ast)
		: _parser(s_parser)
	{
		_prev_temp_ast = _parser->_temp_ast;
		_parser->_temp_ast = s_temp_ast;
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
