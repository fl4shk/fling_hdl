#ifndef src_parser_class_hpp
#define src_parser_class_hpp

// src/parser_class.hpp

#include "misc_includes.hpp"
#include "lexer_class.hpp"

namespace fling_hdl
{

class AstNodeDeferredPusher;
class AstNodeListDeferredPusher;

class Parser final: public RdParserBase<Lexer, Parser>
{
	friend class AstNodeDeferredPusher;
	friend class AstNodeListDeferredPusher;
public:		// types
	using ParserBase = RdParserBase<Lexer, Parser>;

private:		// variables
	size_t _max_ast_level;

	ast::BaseSptr _ast;
	ast::Program* _ast_program = nullptr;
	ast::Base* _curr_ast_parent = nullptr;

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

private:		// functions
	virtual inline bool _check_parse(const ParseFunc& parse_func,
		TokSet& wanted_tok_set)
	{
		return ParserBase::_check_parse(this, parse_func, wanted_tok_set,
			_parse_func_str);
	}

public:		// parsing functions
	ParseRet parseFlingProgram();
	ParseRet parseFlingDeclPackage();
	ParseRet parseFlingDeclPackageItem();
	ParseRet parseFlingImport();
	ParseRet parseFlingDeclParamList();
	ParseRet parseFlingDeclParamListItem();
	ParseRet parseFlingDeclArgList();
	ParseRet parseFlingDeclArgListItem();
	ParseRet parseFlingInstParamList();
	ParseRet parseFlingInstParamListPos();
	ParseRet parseFlingInstParamListPosItem();
	ParseRet parseFlingInstParamListNamed();
	ParseRet parseFlingInstParamListNamedItem();
	ParseRet parseFlingInstArgList();
	ParseRet parseFlingInstArgListPos();
	ParseRet parseFlingInstArgListPosItem();
	ParseRet parseFlingInstArgListNamed();
	ParseRet parseFlingInstArgListNamedItem();
	ParseRet parseFlingDeclModule();
	ParseRet parseFlingDeclModuleScope();
	ParseRet parseFlingDeclModuleItem();
	ParseRet parseFlingModinst();
	ParseRet parseFlingDeclModuleGen();
	ParseRet parseFlingDeclModuleGenIf();
	ParseRet parseFlingDeclModuleGenSwitchEtc();
	ParseRet parseFlingDeclModuleGenSwitchEtcCase();
	ParseRet parseFlingDeclModuleGenSwitchEtcDefault();
	ParseRet parseFlingDeclModuleGenFor();
	ParseRet parseFlingDeclModuleBehav();
	ParseRet parseFlingDeclModuleBehavComb();
	ParseRet parseFlingDeclModuleBehavSeq();
	ParseRet parseFlingDeclModuleBehavSeqEdgeItem();
	ParseRet parseFlingDeclModuleBehavScope();
	ParseRet parseFlingDeclModuleBehavScopeItem();
	ParseRet parseFlingDeclModuleBehavScopeItemIf();
	ParseRet parseFlingDeclModuleBehavScopeItemSwitchEtc();
	ParseRet parseFlingDeclModuleBehavScopeItemSwitchEtcCase();
	ParseRet parseFlingDeclModuleBehavScopeItemSwitchEtcDefault();
	ParseRet parseFlingDeclModuleBehavScopeItemFor();
	ParseRet parseFlingDeclModuleBehavScopeItemWhile();
	ParseRet parseFlingDeclModuleBehavScopeItemGen();
	ParseRet parseFlingDeclModuleBehavScopeItemGenIf();
	ParseRet parseFlingDeclModuleBehavScopeItemGenSwitchEtc();
	ParseRet parseFlingDeclModuleBehavScopeItemGenSwitchEtcCase();
	ParseRet parseFlingDeclModuleBehavScopeItemGenSwitchEtcDefault();
	ParseRet parseFlingDeclModuleBehavScopeItemGenFor();
	ParseRet parseFlingAnyBehavScopeItem();
	ParseRet parseFlingAnyBehavScopeItemAssign();
	ParseRet parseFlingDeclCompositeType();
	ParseRet parseFlingDeclCompositeTypeStruct();
	ParseRet parseFlingDeclCompositeTypeStructItem();
	ParseRet parseFlingCompositeTypeStructItemGen();
	ParseRet parseFlingCompositeTypeStructItemGenIf();
	ParseRet parseFlingCompositeTypeStructItemGenSwitchEtc();
	ParseRet parseFlingCompositeTypeStructItemGenSwitchEtcCase();
	ParseRet parseFlingCompositeTypeStructItemGenSwitchEtcDefault();
	ParseRet parseFlingCompositeTypeStructItemGenFor();
	ParseRet parseFlingDeclEnum();
	ParseRet parseFlingDeclEnumItem();
	ParseRet parseFlingDeclSubprog();
	ParseRet parseFlingDeclSubprogFuncHeader();
	ParseRet parseFlingDeclSubprogTaskHeader();
	ParseRet parseFlingDeclSubprogScope();
	ParseRet parseFlingDeclSubprogScopeItem();
	ParseRet parseFlingDeclSubprogScopeItemIf();
	ParseRet parseFlingDeclSubprogScopeItemSwitchEtc();
	ParseRet parseFlingDeclSubprogScopeItemSwitchEtcCase();
	ParseRet parseFlingDeclSubprogScopeItemSwitchEtcDefault();
	ParseRet parseFlingDeclSubprogScopeItemFor();
	ParseRet parseFlingDeclSubprogScopeItemWhile();
	ParseRet parseFlingDeclSubprogScopeItemGen();
	ParseRet parseFlingDeclSubprogScopeItemGenIf();
	ParseRet parseFlingDeclSubprogScopeItemGenSwitchEtc();
	ParseRet parseFlingDeclSubprogScopeItemGenSwitchEtcCase();
	ParseRet parseFlingDeclSubprogScopeItemGenSwitchEtcDefault();
	ParseRet parseFlingDeclSubprogScopeItemGenFor();
	ParseRet parseFlingDeclConst();
	ParseRet parseFlingDeclVarNoInitVal();
	ParseRet parseFlingDeclVar();
	ParseRet parseFlingDeclWire();
	ParseRet parseFlingWireAssign();
	ParseRet parseFlingDeclAlias();
	ParseRet parseFlingScopedIdent();
	ParseRet parseFlingIdentList();
	ParseRet parseFlingSubprogIdentList();
	ParseRet parseFlingExprList();
	ParseRet parseFlingRangeList();
	ParseRet parseFlingExprOrRangeList();
	ParseRet parseFlingTypenmOrModnmList();
	ParseRet parseFlingImportItem();
	ParseRet parseFlingImportItemList();
	ParseRet parseFlingExpr();
	ParseRet parseFlingMuxExpr();
	ParseRet parseFlingLogorExpr();
	ParseRet parseFlingLogandExpr();
	ParseRet parseFlingCmpEqEtcExpr();
	ParseRet parseFlingCmpLtEtcExpr();
	ParseRet parseFlingPlusMinusExpr();
	ParseRet parseFlingMulDivModExpr();
	ParseRet parseFlingBitorBitnorExpr();
	ParseRet parseFlingBitandBitnandExpr();
	ParseRet parseFlingBitxorBitxnorExpr();
	ParseRet parseFlingBitshiftExpr();
	ParseRet parseFlingUnaryExpr();
	ParseRet parseFlingLowExpr();
	ParseRet parseFlingCallDollarFuncExpr();
	ParseRet parseFlingCallSubprogExpr();
	ParseRet parseFlingSubprogIdent();
	ParseRet parseFlingIdentExpr();
	ParseRet parseFlingCatExpr();
	ParseRet parseFlingReplExpr();
	ParseRet parseFlingSizedExpr();
	ParseRet parseFlingRange();
	ParseRet parseFlingNonSimpleRange();
	ParseRet parseFlingSimpleRangeSuffix();
	ParseRet parseFlingExprOrRange();
	ParseRet parseFlingTypenmOrModnmCstmStart();
	ParseRet parseFlingTypenmOrModnmCstmChainItem();
	ParseRet parseFlingTypenmOrModnm();

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
		_prev_ast_parent = _pt_visitor->_curr_ast_parent;
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

class ParseFuncStrDeferredRestorer final
{
private:		// variables
	Parser* _parser = nullptr;
	string _old_parse_func_str;
public:		// functions
	inline ParseFuncStrDeferredRestorer(Parser* s_parser,
		string&& s_parse_func_str)
		: _parser(s_parser)
	{
		_old_parse_func_str = move(_parser->_parse_func_str);
		_parser->_parse_func_str = move(s_parse_func_str);
	}
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(ParseFuncStrDeferredRestorer)
	inline ~ParseFuncStrDeferredRestorer()
	{
		_parser->_parse_func_str = move(_old_parse_func_str);
	}
};

} // namespace fling_hdl


#endif		// src_parser_class_hpp
