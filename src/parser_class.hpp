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
	Parser(const string& s_filename);
	GEN_NO_CM_CONSTRUCTORS_AND_ASSIGN(Parser);
	virtual inline ~Parser() = default;

	int run();

	GEN_GETTER_BY_VAL(max_ast_level);

public:		// parsing functions
	void parseFlingProgram();
	void parseFlingDeclPackage();
	void parseFlingDeclPackageItem();
	void parseFlingImport();
	void parseFlingDeclParamList();
	void parseFlingDeclParamListItem();
	void parseFlingDeclArgList();
	void parseFlingDeclArgListItem();
	void parseFlingInstParamList();
	void parseFlingInstParamListPos();
	void parseFlingInstParamListPosItem();
	void parseFlingInstParamListNamed();
	void parseFlingInstParamListNamedItem();
	void parseFlingInstArgList();
	void parseFlingInstArgListPos();
	void parseFlingInstArgListPosItem();
	void parseFlingInstArgListNamed();
	void parseFlingInstArgListNamedItem();
	void parseFlingDeclModule();
	void parseFlingDeclModuleScope();
	void parseFlingDeclModuleItem();
	void parseFlingModinst();
	void parseFlingDeclModuleGen();
	void parseFlingDeclModuleGenIf();
	void parseFlingDeclModuleGenSwitchEtc();
	void parseFlingDeclModuleGenSwitchEtcCase();
	void parseFlingDeclModuleGenSwitchEtcDefault();
	void parseFlingDeclModuleGenFor();
	void parseFlingDeclModuleBehav();
	void parseFlingDeclModuleBehavComb();
	void parseFlingDeclModuleBehavSeq();
	void parseFlingDeclModuleBehavSeqEdgeItem();
	void parseFlingDeclModuleBehavScope();
	void parseFlingDeclModuleBehavScopeItem();
	void parseFlingDeclModuleBehavScopeItemIf();
	void parseFlingDeclModuleBehavScopeItemSwitchEtc();
	void parseFlingDeclModuleBehavScopeItemSwitchEtcCase();
	void parseFlingDeclModuleBehavScopeItemSwitchEtcDefault();
	void parseFlingDeclModuleBehavScopeItemFor();
	void parseFlingDeclModuleBehavScopeItemWhile();
	void parseFlingDeclModuleBehavScopeItemGen();
	void parseFlingDeclModuleBehavScopeItemGenIf();
	void parseFlingDeclModuleBehavScopeItemGenSwitchEtc();
	void parseFlingDeclModuleBehavScopeItemGenSwitchEtcCase();
	void parseFlingDeclModuleBehavScopeItemGenSwitchEtcDefault();
	void parseFlingDeclModuleBehavScopeItemGenFor();
	void parseFlingAnyBehavScopeItem();
	void parseFlingAnyBehavScopeItemAssign();
	void parseFlingDeclCompositeType();
	void parseFlingDeclCompositeTypeStruct();
	void parseFlingDeclCompositeTypeStructItem();
	void parseFlingCompositeTypeStructItemGen();
	void parseFlingCompositeTypeStructItemGenIf();
	void parseFlingCompositeTypeStructItemGenSwitchEtc();
	void parseFlingCompositeTypeStructItemGenSwitchEtcCase();
	void parseFlingCompositeTypeStructItemGenSwitchEtcDefault();
	void parseFlingCompositeTypeStructItemGenFor();
	void parseFlingDeclEnum();
	void parseFlingDeclEnumItem();
	void parseFlingDeclSubprog();
	void parseFlingDeclSubprogFuncHeader();
	void parseFlingDeclSubprogTaskHeader();
	void parseFlingDeclSubprogScope();
	void parseFlingDeclSubprogScopeItem();
	void parseFlingDeclSubprogScopeItemIf();
	void parseFlingDeclSubprogScopeItemSwitchEtc();
	void parseFlingDeclSubprogScopeItemSwitchEtcCase();
	void parseFlingDeclSubprogScopeItemSwitchEtcDefault();
	void parseFlingDeclSubprogScopeItemFor();
	void parseFlingDeclSubprogScopeItemWhile();
	void parseFlingDeclSubprogScopeItemGen();
	void parseFlingDeclSubprogScopeItemGenIf();
	void parseFlingDeclSubprogScopeItemGenSwitchEtc();
	void parseFlingDeclSubprogScopeItemGenSwitchEtcCase();
	void parseFlingDeclSubprogScopeItemGenSwitchEtcDefault();
	void parseFlingDeclSubprogScopeItemGenFor();
	void parseFlingDeclConst();
	void parseFlingDeclVarNoInitVal();
	void parseFlingDeclVar();
	void parseFlingDeclWire();
	void parseFlingWireAssign();
	void parseFlingDeclAlias();
	void parseFlingScopedIdent();
	void parseFlingIdentList();
	void parseFlingSubprogIdentList();
	void parseFlingExprList();
	void parseFlingRangeList();
	void parseFlingExprOrRangeList();
	void parseFlingTypenmOrModnmList();
	void parseFlingImportItem();
	void parseFlingImportItemList();
	void parseFlingExpr();
	void parseFlingMuxExpr();
	void parseFlingLogorExpr();
	void parseFlingLogandExpr();
	void parseFlingCmpEqEtcExpr();
	void parseFlingCmpLtEtcExpr();
	void parseFlingPlusMinusExpr();
	void parseFlingMulDivModExpr();
	void parseFlingBitorBitnorExpr();
	void parseFlingBitandBitnandExpr();
	void parseFlingBitxorBitxnorExpr();
	void parseFlingBitshiftExpr();
	void parseFlingUnaryExpr();
	void parseFlingLowExpr();
	void parseFlingCallDollarFuncExpr();
	void parseFlingCallSubprogExpr();
	void parseFlingSubprogIdent();
	void parseFlingIdentExpr();
	void parseFlingCatExpr();
	void parseFlingReplExpr();
	void parseFlingSizedExpr();
	void parseFlingRange();
	void parseFlingNonSimpleRange();
	void parseFlingSimpleRangeSuffix();
	void parseFlingExprOrRange();
	void parseFlingTypenmOrModnmCstmStart();
	void parseFlingTypenmOrModnmCstmChainItem();
	void parseFlingTypenmOrModnm();
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
