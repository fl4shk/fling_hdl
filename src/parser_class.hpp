#ifndef src_parser_class_hpp
#define src_parser_class_hpp

// src/parser_class.hpp

#include "misc_includes.hpp"
#include "lexer_class.hpp"
#include "ast/ast_node_classes.hpp"

namespace fling_hdl
{

class AstNodeDeferredPusher;
class AstNodeListDeferredPusher;

class Parser final: public RdParserBase<Lexer, Parser>
{
	friend class AstNodeDeferredPusher;
	friend class AstNodeListDeferredPusher;
	friend class StrVecDeferredPusher;

public:		// types
	using ParserBase = RdParserBase<Lexer, Parser>;
	using StrVec = vector<string>;

private:		// variables
	size_t _max_ast_level;

	ast::BaseSptr _ast;
	ast::Program* _ast_program = nullptr;
	ast::Base* _curr_ast_parent = nullptr;

	stack<unique_ptr<StrVec>> _str_vec_stack;
	stack<unique_ptr<ast::BaseSptr>> _ast_stack;
	stack<unique_ptr<ast::BaseSptrList>> _ast_list_stack;
	string _parse_func_str;

public:		// misc. functions
	template<typename Type>
	static inline Type* as(ast::BaseSptr& base_sptr)
	{
		return static_cast<Type*>(base_sptr.get());
	}

private:		// misc. functions
	inline void _push_str_vec(StrVec&& to_push)
	{
		_str_vec_stack.push(unique_ptr<StrVec>(new StrVec(move(to_push))));
	}
	inline void _pop_str_vec(StrVec& to_set)
	{
		to_set = move(*_str_vec_stack.top());
		_str_vec_stack.top().reset(nullptr);
		_str_vec_stack.pop();
	}

	inline void _push_ast(ast::Base* to_push)
	{
		_ast_stack.push(unique_ptr<ast::BaseSptr>
			(new ast::BaseSptr(to_push)));
	}
	inline void _pop_ast(ast::BaseSptr& to_set)
	{
		to_set = move(*_ast_stack.top());
		_ast_stack.top().reset(nullptr);
		_ast_stack.pop();
	}

	inline void _push_ast_list(ast::BaseSptrList&& to_push)
	{
		_ast_list_stack.push(unique_ptr<ast::BaseSptrList>
			(new ast::BaseSptrList(move(to_push))));
	}
	inline void _pop_ast_list(ast::BaseSptrList& to_set)
	{
		to_set = move(*_ast_list_stack.top());
		_ast_list_stack.top().reset(nullptr);
		_ast_list_stack.pop();
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
	ParseRet _parseFlingDeclParamListItem();
	ParseRet _parseFlingDeclArgList();
	ParseRet _parseFlingDeclArgListItem();
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
	ParseRet _parseFlingAnyBehavScopeItemAssign();
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
	//ParseRet _parseFlingExprOrRangeList();
	ParseRet _parseFlingTypenmOrModnmList();
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
	ParseRet _parseFlingCallSubprogExpr();
	ParseRet _parseFlingSubprogIdent();
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
	ParseRet _parseFlingTypenmOrModnmCstmChainItem();
	ParseRet _parseFlingTypenmOrModnm();
	//--------

	#define X(name, dummy_0) \
		ParseRet parseTok##name();
	LIST_OF_TOKENS(X)
	#undef X
};

class AstNodeDeferredPusher final
{
private:		// variables
	Parser* _parser = nullptr;
	ast::Base * _node = nullptr,
		* _prev_ast_parent = nullptr;
public:		// functions
	inline AstNodeDeferredPusher(Parser* s_parser, ast::Base* s_node)
		: _parser(s_parser), _node(s_node)
	{
		_prev_ast_parent = _parser->_curr_ast_parent;
		_parser->_curr_ast_parent = _node;

		if (_parser->max_ast_level() < _node->level())
		{
			_parser->_max_ast_level = _node->level();
		}
	}
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(AstNodeDeferredPusher);
	inline ~AstNodeDeferredPusher()
	{
		_parser->_push_ast(_node);
		_parser->_curr_ast_parent = _prev_ast_parent;
	}
};

class AstNodeListDeferredPusher final
{
private:		// variables
	Parser* _parser = nullptr;
	ast::BaseSptrList* _node_list = nullptr;
public:		// functions
	inline AstNodeListDeferredPusher(Parser* s_parser,
		ast::BaseSptrList* s_node_list)
		: _parser(s_parser), _node_list(s_node_list)
	{
	}
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(AstNodeListDeferredPusher);
	inline ~AstNodeListDeferredPusher()
	{
		_parser->_push_ast_list(move(*_node_list));
	}
};

class StrVecDeferredPusher final
{
private:		// variables
	Parser* _parser = nullptr;
	Parser::StrVec* _vec = nullptr;
public:		// functions
	inline StrVecDeferredPusher(Parser* s_parser,
		Parser::StrVec* s_vec)
		: _parser(s_parser), _vec(s_vec)
	{
	}
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(StrVecDeferredPusher);
	inline ~StrVecDeferredPusher()
	{
		_parser->_push_str_vec(move(*_vec));
	}
};

} // namespace fling_hdl


#endif		// src_parser_class_hpp
