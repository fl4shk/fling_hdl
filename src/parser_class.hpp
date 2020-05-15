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
	ast::Base* _curr_ast_parent = nullptr;

	stack<unique_ptr<ast::BaseSptr>> _ast_stack;
	stack<unique_ptr<ast::BaseSptrList>> _ast_list_stack;

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

	inline void _internal_err(const string& func) const
	{
		lex_file_pos().err(sconcat("Parser::", func, "():  Internal ",
			"error."));
	}

public:		// functions
	inline Parser(const string& s_filename)
		: ParserBase(s_filename)
	{
	}
	GEN_NO_CM_CONSTRUCTORS_AND_ASSIGN(Parser);
	virtual inline ~Parser() = default;

	void parseFlingProgram();

	GEN_GETTER_BY_VAL(max_ast_level);

private:		// parsing functions
	void _parseFlingDeclPackage();
	void _parseFlingDeclPackageItem();
	void _parseFlingImport();
	void _parseFlingDeclParamList();
	void _parseFlingDeclParamListItem();
	void _parseFlingDeclArgList();
	void _parseFlingDeclArgListItem();
	void _parseFlingInstParamList();
	void _parseFlingInstParamListPos();
	void _parseFlingInstParamListPosItem();
	void _parseFlingInstParamListNamed();
	void _parseFlingInstParamListNamedItem();
	void _parseFlingInstArgList();
	void _parseFlingInstArgListPos();
	void _parseFlingInstArgListPosItem();
	void _parseFlingInstArgListNamed();
	void _parseFlingInstArgListNamedItem();
	void _parseFlingDeclModule();
	void _parseFlingDeclModuleScope();
	void _parseFlingDeclModuleItem();
	void _parseFlingModinst();
	void _parseFlingDeclModuleGen();
	void _parseFlingDeclModuleGenIf();
	void _parseFlingDeclModuleGenSwitchEtc();
	void _parseFlingDeclModuleGenSwitchEtcCase();
	void _parseFlingDeclModuleGenSwitchEtcDefault();
	void _parseFlingDeclModuleGenFor();
	void _parseFlingDeclModuleBehav();
	void _parseFlingDeclModuleBehavComb();
	void _parseFlingDeclModuleBehavSeq();
	void _parseFlingDeclModuleBehavSeqEdgeItem();
	void _parseFlingDeclModuleBehavScope();
	void _parseFlingDeclModuleBehavScopeItem();
	void _parseFlingDeclModuleBehavScopeItemIf();
	void _parseFlingDeclModuleBehavScopeItemSwitchEtc();
	void _parseFlingDeclModuleBehavScopeItemSwitchEtcCase();
	void _parseFlingDeclModuleBehavScopeItemSwitchEtcDefault();
	void _parseFlingDeclModuleBehavScopeItemFor();
	void _parseFlingDeclModuleBehavScopeItemWhile();
	void _parseFlingDeclModuleBehavScopeItemGen();
	void _parseFlingDeclModuleBehavScopeItemGenIf();
	void _parseFlingDeclModuleBehavScopeItemGenSwitchEtc();
	void _parseFlingDeclModuleBehavScopeItemGenSwitchEtcCase();
	void _parseFlingDeclModuleBehavScopeItemGenSwitchEtcDefault();
	void _parseFlingDeclModuleBehavScopeItemGenFor();
	void _parseFlingAnyBehavScopeItem();
	void _parseFlingAnyBehavScopeItemAssign();
	void _parseFlingDeclCompositeType();
	void _parseFlingDeclCompositeTypeStruct();
	void _parseFlingDeclCompositeTypeStructItem();
	void _parseFlingCompositeTypeStructItemGen();
	void _parseFlingCompositeTypeStructItemGenIf();
	void _parseFlingCompositeTypeStructItemGenSwitchEtc();
	void _parseFlingCompositeTypeStructItemGenSwitchEtcCase();
	void _parseFlingCompositeTypeStructItemGenSwitchEtcDefault();
	void _parseFlingCompositeTypeStructItemGenFor();
	void _parseFlingDeclEnum();
	void _parseFlingDeclEnumItem();
	void _parseFlingDeclSubprog();
	void _parseFlingDeclSubprogFuncHeader();
	void _parseFlingDeclSubprogTaskHeader();
	void _parseFlingDeclSubprogScope();
	void _parseFlingDeclSubprogScopeItem();
	void _parseFlingDeclSubprogScopeItemIf();
	void _parseFlingDeclSubprogScopeItemSwitchEtc();
	void _parseFlingDeclSubprogScopeItemSwitchEtcCase();
	void _parseFlingDeclSubprogScopeItemSwitchEtcDefault();
	void _parseFlingDeclSubprogScopeItemFor();
	void _parseFlingDeclSubprogScopeItemWhile();
	void _parseFlingDeclSubprogScopeItemGen();
	void _parseFlingDeclSubprogScopeItemGenIf();
	void _parseFlingDeclSubprogScopeItemGenSwitchEtc();
	void _parseFlingDeclSubprogScopeItemGenSwitchEtcCase();
	void _parseFlingDeclSubprogScopeItemGenSwitchEtcDefault();
	void _parseFlingDeclSubprogScopeItemGenFor();
	void _parseFlingDeclConst();
	void _parseFlingDeclVarNoInitVal();
	void _parseFlingDeclVar();
	void _parseFlingDeclWire();
	void _parseFlingWireAssign();
	void _parseFlingDeclAlias();
	void _parseFlingScopedIdent();
	void _parseFlingIdentList();
	void _parseFlingSubprogIdentList();
	void _parseFlingExprList();
	void _parseFlingRangeList();
	void _parseFlingExprOrRangeList();
	void _parseFlingTypenmOrModnmList();
	void _parseFlingImportItem();
	void _parseFlingImportItemList();
	void _parseFlingExpr();
	void _parseFlingMuxExpr();
	void _parseFlingLogorExpr();
	void _parseFlingLogandExpr();
	void _parseFlingCmpEqEtcExpr();
	void _parseFlingCmpLtEtcExpr();
	void _parseFlingPlusMinusExpr();
	void _parseFlingMulDivModExpr();
	void _parseFlingBitorBitnorExpr();
	void _parseFlingBitandBitnandExpr();
	void _parseFlingBitxorBitxnorExpr();
	void _parseFlingBitshiftExpr();
	void _parseFlingUnaryExpr();
	void _parseFlingLowExpr();
	void _parseFlingCallDollarFuncExpr();
	void _parseFlingCallSubprogExpr();
	void _parseFlingSubprogIdent();
	void _parseFlingIdentExpr();
	void _parseFlingCatExpr();
	void _parseFlingReplExpr();
	void _parseFlingSizedExpr();
	void _parseFlingRange();
	void _parseFlingNonSimpleRange();
	void _parseFlingSimpleRangeSuffix();
	void _parseFlingExprOrRange();
	void _parseFlingTypenmOrModnmCstmStart();
	void _parseFlingTypenmOrModnmCstmChainItem();
	void _parseFlingTypenmOrModnm();
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

} // namespace fling_hdl


#endif		// src_parser_class_hpp
