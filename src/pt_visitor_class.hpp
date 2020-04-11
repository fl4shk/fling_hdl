#ifndef src_pt_visitor_class_hpp
#define src_pt_visitor_class_hpp

// src/pt_visitor_class.hpp

#include "misc_includes.hpp"

#include "ast_node_classes.hpp"
#include "liborangepower_src/cpp_magic.hpp"

namespace fling_hdl
{


class AstEtc final
{
public:		// types
	using Parser = FlingHdlGrammarParser;
	using ProgramContext = Parser::FlingProgramContext;
private:		// variables
	string _filename;
	ProgramContext* _program_ctx = nullptr;
	ast::BaseSptr _ast;
	size_t _max_ast_level;
public:		// functions
	inline AstEtc() = default;
	inline AstEtc(const string& s_filename, ProgramContext* s_program_ctx)
		: _filename(s_filename), _program_ctx(s_program_ctx)
	{
	}
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(AstEtc);
	inline ~AstEtc() = default;

	GEN_GETTER_BY_CON_REF(filename);
	GEN_GETTER_BY_VAL(program_ctx);
	GEN_GETTERS_BY_CON_REF_AND_REF(ast);
	GEN_GETTER_AND_SETTER_BY_VAL(max_ast_level);
};

class AstNodeDeferredPusher;
class AstNodeListDeferredPusher;

class PtVisitor final: public FlingHdlGrammarVisitor
{
	friend class AstNodeDeferredPusher;
	friend class AstNodeListDeferredPusher;
public:		// typedefs
	using ParserRuleContext = antlr4::ParserRuleContext;

	using Parser = FlingHdlGrammarParser;
private:		// variables
	set<string>* _filename_set = nullptr;

	// This maps a filename to an `AstEtc`.
	map<string, AstEtc> _ast_etc_map;

	// The current filename
	string _filename;
	ast::Program* _ast = nullptr;
	ast::Base* _curr_ast_parent = nullptr;

	stack<string> _str_stack;
	stack<BigNum> _num_stack;
	
	stack<ast::BaseSptr> _ast_stack;
	stack<ast::BaseSptrList> _ast_list_stack;
public:		// misc functions
	template<typename Type>
	static inline Type* as(ast::BaseSptr& base_sptr)
	{
		return static_cast<Type*>(base_sptr.get());
	}
private:		// misc functions
	inline void _push_str(const string& to_push)
	{
		_str_stack.push(to_push);
	}
	inline auto _get_top_str()
	{
		return _str_stack.top();
	}
	inline auto _pop_str()
	{
		auto ret = _str_stack.top();
		_str_stack.pop();
		return ret;
	}

	inline void _push_num(const BigNum& to_push)
	{
		_num_stack.push(to_push);
	}
	inline auto _get_top_num()
	{
		return _num_stack.top();
	}
	inline auto _pop_num()
	{
		auto ret = _num_stack.top();
		_num_stack.pop();
		return ret;
	}

	inline void _push_ast(ast::Base* to_push)
	{
		_ast_stack.push(ast::BaseSptr(to_push));
	}
	inline auto _get_top_ast()
	{
		return _ast_stack.top();
	}
	inline auto _pop_ast()
	{
		auto ret = _ast_stack.top();
		_ast_stack.pop();
		return ret;
	}

	inline void _push_ast_list(ast::BaseSptrList&& to_push)
	{
		_ast_list_stack.push(move(to_push));
	}
	inline auto&& _pop_ast_list()
	{
		auto&& ret = move(_ast_list_stack.top());
		_ast_list_stack.pop();
		return ret;
	}

	inline void _internal_err(antlr4::ParserRuleContext* ctx,
		const string& func) const
	{
		FilePos(_filename, ctx).err(sconcat("PtVisitor::", func, "():  ",
			"Internal error."));
	}

	template<typename PtNodeVecType, typename OutputType,
		typename...  RemOutputTypes>
	void _inner_vec_just_accept_and_pop_ast(size_t i,
		PtNodeVecType&& pt_node_vec, OutputType& first_output,
		RemOutputTypes&&... rem_outputs)
	{
		pt_node_vec.at(i)->accept(this);
		first_output = _pop_ast();

		if constexpr (sizeof...(rem_outputs) > 0)
		{
			_inner_vec_just_accept_and_pop_ast(i + 1, move(pt_node_vec),
				rem_outputs...);
		}
	}
	template<typename PtNodeVecType, typename OutputType,
		typename...  RemOutputTypes>
	void _vec_just_accept_and_pop_ast(PtNodeVecType&& pt_node_vec,
		OutputType& first_output, RemOutputTypes&&... rem_outputs)
	{
		_inner_vec_just_accept_and_pop_ast(0, move(pt_node_vec),
			first_output, rem_outputs...);
	}

public:		// functions
	PtVisitor(set<string>* s_filename_set);
	virtual ~PtVisitor();
	int run();

	GEN_GETTER_BY_REF(ast_etc_map);

private:		// error/warning functions
	inline void _err(ParserRuleContext* ctx, const std::string& msg)
	{
		if (ctx == nullptr)
		{
			printerr("Error:  ", msg, "\n");
		}
		else
		{
			FilePos(_filename, ctx).err(msg);
		}
		exit(1);
	}
	inline void _err(const std::string& msg)
	{
		//printerr("Error in file \"", *__file_name, "\":  ", msg, "\n");
		printerr("Error:  ", msg, "\n");
		exit(1);
	}


	inline void _warn(ParserRuleContext* ctx, const std::string& msg)
	{
		if (ctx == nullptr)
		{
			printerr("Error:  ", msg, "\n");
		}
		else
		{
			FilePos(_filename, ctx).warn(msg);
		}
	}
	inline void _warn(const std::string& msg)
	{
		printerr("Warning:  ", msg, "\n");
	}

private:		// visitor functions
	antlrcpp::Any visitFlingProgram
		(Parser::FlingProgramContext *ctx);
	antlrcpp::Any visitFlingProgram_Item
		(Parser::FlingProgram_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclPackage
		(Parser::FlingDeclPackageContext *ctx);
	antlrcpp::Any visitFlingDeclPackage_Item
		(Parser::FlingDeclPackage_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclParamList
		(Parser::FlingDeclParamListContext *ctx);
	antlrcpp::Any visitFlingDeclParamList_Item
		(Parser::FlingDeclParamList_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclArgList
		(Parser::FlingDeclArgListContext *ctx);
	antlrcpp::Any visitFlingDeclArgList_Item
		(Parser::FlingDeclArgList_ItemContext *ctx);
	antlrcpp::Any visitFlingInstParamList
		(Parser::FlingInstParamListContext *ctx);
	antlrcpp::Any visitFlingInstParamList_Pos
		(Parser::FlingInstParamList_PosContext *ctx);
	antlrcpp::Any visitFlingInstParamList_Pos_Item
		(Parser::FlingInstParamList_Pos_ItemContext *ctx);
	antlrcpp::Any visitFlingInstParamList_Pos_Item_Parpk
		(Parser::FlingInstParamList_Pos_Item_ParpkContext *ctx);
	antlrcpp::Any visitFlingInstParamList_Pos_Item_Unparpk
		(Parser::FlingInstParamList_Pos_Item_UnparpkContext *ctx);
	antlrcpp::Any visitFlingInstParamList_Named
		(Parser::FlingInstParamList_NamedContext *ctx);
	antlrcpp::Any visitFlingInstParamList_Named_Item
		(Parser::FlingInstParamList_Named_ItemContext *ctx);
	antlrcpp::Any visitFlingInstArgList
		(Parser::FlingInstArgListContext *ctx);
	antlrcpp::Any visitFlingInstArgList_Pos
		(Parser::FlingInstArgList_PosContext *ctx);
	antlrcpp::Any visitFlingInstArgList_Pos_Item
		(Parser::FlingInstArgList_Pos_ItemContext *ctx);
	antlrcpp::Any visitFlingInstArgList_Pos_Item_Parpk
		(Parser::FlingInstArgList_Pos_Item_ParpkContext *ctx);
	antlrcpp::Any visitFlingInstArgList_Pos_Item_Unparpk
		(Parser::FlingInstArgList_Pos_Item_UnparpkContext *ctx);
	antlrcpp::Any visitFlingInstArgList_Named
		(Parser::FlingInstArgList_NamedContext *ctx);
	antlrcpp::Any visitFlingInstArgList_Named_Item
		(Parser::FlingInstArgList_Named_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclModule
		(Parser::FlingDeclModuleContext *ctx);
	antlrcpp::Any visitFlingDeclModule_Scope
		(Parser::FlingDeclModule_ScopeContext *ctx);
	antlrcpp::Any visitFlingDeclModule_Item
		(Parser::FlingDeclModule_ItemContext *ctx);
	antlrcpp::Any visitFlingInstModule
		(Parser::FlingInstModuleContext *ctx);
	antlrcpp::Any visitFlingGen
		(Parser::FlingGenContext *ctx);
	antlrcpp::Any visitFlingGen_If
		(Parser::FlingGen_IfContext *ctx);
	antlrcpp::Any visitFlingGen_If_Elif
		(Parser::FlingGen_If_ElifContext *ctx);
	antlrcpp::Any visitFlingGen_If_Else
		(Parser::FlingGen_If_ElseContext *ctx);
	antlrcpp::Any visitFlingGen_Switch
		(Parser::FlingGen_SwitchContext *ctx);
	antlrcpp::Any visitFlingGen_Switch_Default
		(Parser::FlingGen_Switch_DefaultContext *ctx);
	antlrcpp::Any visitFlingGen_Switch_Case
		(Parser::FlingGen_Switch_CaseContext *ctx);
	antlrcpp::Any visitFlingGen_For
		(Parser::FlingGen_ForContext *ctx);
	antlrcpp::Any visitFlingContAssign
		(Parser::FlingContAssignContext *ctx);
	antlrcpp::Any visitFlingBehav
		(Parser::FlingBehavContext *ctx);
	antlrcpp::Any visitFlingBehav_Seq_EdgeList
		(Parser::FlingBehav_Seq_EdgeListContext *ctx);
	antlrcpp::Any visitFlingBehav_Seq_EdgeList_Item
		(Parser::FlingBehav_Seq_EdgeList_ItemContext *ctx);
	antlrcpp::Any visitFlingBehav_Scope
		(Parser::FlingBehav_ScopeContext *ctx);
	antlrcpp::Any visitFlingBehav_Item
		(Parser::FlingBehav_ItemContext *ctx);
	antlrcpp::Any visitFlingBehav_Item_If
		(Parser::FlingBehav_Item_IfContext *ctx);
	antlrcpp::Any visitFlingBehav_Item_If_Elif
		(Parser::FlingBehav_Item_If_ElifContext *ctx);
	antlrcpp::Any visitFlingBehav_Item_If_Else
		(Parser::FlingBehav_Item_If_ElseContext *ctx);
	antlrcpp::Any visitFlingBehav_Item_SwitchOrSwitchz
		(Parser::FlingBehav_Item_SwitchOrSwitchzContext *ctx);
	antlrcpp::Any visitFlingBehav_Item_SwitchOrSwitchz_Default
		(Parser::FlingBehav_Item_SwitchOrSwitchz_DefaultContext *ctx);
	antlrcpp::Any visitFlingBehav_Item_SwitchOrSwitchz_Case
		(Parser::FlingBehav_Item_SwitchOrSwitchz_CaseContext *ctx);
	antlrcpp::Any visitFlingBehav_Item_For
		(Parser::FlingBehav_Item_ForContext *ctx);
	antlrcpp::Any visitFlingBehav_Item_While
		(Parser::FlingBehav_Item_WhileContext *ctx);
	antlrcpp::Any visitFlingBehav_Item_NonBlkAssign
		(Parser::FlingBehav_Item_NonBlkAssignContext *ctx);
	antlrcpp::Any visitFlingBehav_Item_BlkAssign
		(Parser::FlingBehav_Item_BlkAssignContext *ctx);
	antlrcpp::Any visitFlingDeclWire
		(Parser::FlingDeclWireContext *ctx);
	antlrcpp::Any visitFlingDeclVar
		(Parser::FlingDeclVarContext *ctx);
	antlrcpp::Any visitFlingDeclConst
		(Parser::FlingDeclConstContext *ctx);
	antlrcpp::Any visitFlingDeclType
		(Parser::FlingDeclTypeContext *ctx);
	antlrcpp::Any visitFlingDeclEnum
		(Parser::FlingDeclEnumContext *ctx);
	antlrcpp::Any visitFlingDeclClass
		(Parser::FlingDeclClassContext *ctx);
	antlrcpp::Any visitFlingDeclClsOrMxn_Extends
		(Parser::FlingDeclClsOrMxn_ExtendsContext *ctx);
	antlrcpp::Any visitFlingDeclClass_Item
		(Parser::FlingDeclClass_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclClass_Item_DeclVar
		(Parser::FlingDeclClass_Item_DeclVarContext *ctx);
	antlrcpp::Any visitFlingDeclClsOrMxn_Item
		(Parser::FlingDeclClsOrMxn_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclClsOrMxn_Item_DeclType
		(Parser::FlingDeclClsOrMxn_Item_DeclTypeContext *ctx);
	antlrcpp::Any visitFlingDeclClsOrMxn_Item_DeclAliasOrConst
		(Parser::FlingDeclClsOrMxn_Item_DeclAliasOrConstContext *ctx);
	antlrcpp::Any visitFlingDeclClsOrMxn_AccessSpecifier
		(Parser::FlingDeclClsOrMxn_AccessSpecifierContext *ctx);
	antlrcpp::Any visitFlingDeclClsOrMxn_Item_DeclSubprog
		(Parser::FlingDeclClsOrMxn_Item_DeclSubprogContext *ctx);
	antlrcpp::Any visitFlingDeclClsOrMxn_Item_DeclSubprog_FullDefn
		(Parser::FlingDeclClsOrMxn_Item_DeclSubprog_FullDefnContext *ctx);
	antlrcpp::Any visitFlingDeclClsOrMxn_Item_DeclSubprog_Abstract
		(Parser::FlingDeclClsOrMxn_Item_DeclSubprog_AbstractContext *ctx);
	antlrcpp::Any visitFlingDeclMixin
		(Parser::FlingDeclMixinContext *ctx);
	antlrcpp::Any visitFlingDeclSubprog
		(Parser::FlingDeclSubprogContext *ctx);
	antlrcpp::Any visitFlingDeclFunc
		(Parser::FlingDeclFuncContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Header
		(Parser::FlingDeclFunc_HeaderContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Scope
		(Parser::FlingDeclFunc_ScopeContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Item
		(Parser::FlingDeclFunc_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Item_If
		(Parser::FlingDeclFunc_Item_IfContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Item_If_Elif
		(Parser::FlingDeclFunc_Item_If_ElifContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Item_If_Else
		(Parser::FlingDeclFunc_Item_If_ElseContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Item_SwitchOrSwitchz
		(Parser::FlingDeclFunc_Item_SwitchOrSwitchzContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Item_SwitchOrSwitchz_Default
		(Parser::FlingDeclFunc_Item_SwitchOrSwitchz_DefaultContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Item_SwitchOrSwitchz_Case
		(Parser::FlingDeclFunc_Item_SwitchOrSwitchz_CaseContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Item_For
		(Parser::FlingDeclFunc_Item_ForContext *ctx);
	antlrcpp::Any visitFlingDeclFunc_Item_While
		(Parser::FlingDeclFunc_Item_WhileContext *ctx);
	antlrcpp::Any visitFlingDeclTask
		(Parser::FlingDeclTaskContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Header
		(Parser::FlingDeclTask_HeaderContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Scope
		(Parser::FlingDeclTask_ScopeContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Item
		(Parser::FlingDeclTask_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Item_If
		(Parser::FlingDeclTask_Item_IfContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Item_If_Elif
		(Parser::FlingDeclTask_Item_If_ElifContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Item_If_Else
		(Parser::FlingDeclTask_Item_If_ElseContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Item_SwitchOrSwitchz
		(Parser::FlingDeclTask_Item_SwitchOrSwitchzContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Item_SwitchOrSwitchz_Default
		(Parser::FlingDeclTask_Item_SwitchOrSwitchz_DefaultContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Item_SwitchOrSwitchz_Case
		(Parser::FlingDeclTask_Item_SwitchOrSwitchz_CaseContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Item_For
		(Parser::FlingDeclTask_Item_ForContext *ctx);
	antlrcpp::Any visitFlingDeclTask_Item_While
		(Parser::FlingDeclTask_Item_WhileContext *ctx);
	antlrcpp::Any visitFlingDeclProc
		(Parser::FlingDeclProcContext *ctx);
	antlrcpp::Any visitFlingDeclProc_Header
		(Parser::FlingDeclProc_HeaderContext *ctx);
	antlrcpp::Any visitFlingDeclProc_ArgList
		(Parser::FlingDeclProc_ArgListContext *ctx);
	antlrcpp::Any visitFlingDeclProc_ArgList_Item
		(Parser::FlingDeclProc_ArgList_ItemContext *ctx);
	antlrcpp::Any visitFlingDeclAlias
		(Parser::FlingDeclAliasContext *ctx);
	antlrcpp::Any visitFlingDeclAlias_Value
		(Parser::FlingDeclAlias_ValueContext *ctx);
	antlrcpp::Any visitFlingDeclAlias_Type
		(Parser::FlingDeclAlias_TypeContext *ctx);
	antlrcpp::Any visitFlingDeclAlias_Module
		(Parser::FlingDeclAlias_ModuleContext *ctx);
	antlrcpp::Any visitFlingIdent
		(Parser::FlingIdentContext *ctx);
	antlrcpp::Any visitFlingIdentList
		(Parser::FlingIdentListContext *ctx);
	antlrcpp::Any visitFlingScopedIdent
		(Parser::FlingScopedIdentContext *ctx);
	antlrcpp::Any visitFlingExprList
		(Parser::FlingExprListContext *ctx);
	antlrcpp::Any visitFlingTypenameOrModnameList
		(Parser::FlingTypenameOrModnameListContext *ctx);
	antlrcpp::Any visitFlingImportList
		(Parser::FlingImportListContext *ctx);
	antlrcpp::Any visitFlingImportList_Item
		(Parser::FlingImportList_ItemContext *ctx);
	antlrcpp::Any visitFlingTypenameOrModname
		(Parser::FlingTypenameOrModnameContext *ctx);
	antlrcpp::Any visitFlingTypenameOrModname_Cstm
		(Parser::FlingTypenameOrModname_CstmContext *ctx);
	antlrcpp::Any visitFlingTypenameOrModname_Typeof
		(Parser::FlingTypenameOrModname_TypeofContext *ctx);
	antlrcpp::Any visitFlingTypenameOrModname_Cstm_Item
		(Parser::FlingTypenameOrModname_Cstm_ItemContext *ctx);
	antlrcpp::Any visitFlingTypenameOrModname_ArrDim
		(Parser::FlingTypenameOrModname_ArrDimContext *ctx);
	antlrcpp::Any visitFlingTypenameOrModname_Builtin
		(Parser::FlingTypenameOrModname_BuiltinContext *ctx);
	antlrcpp::Any visitFlingExpr
		(Parser::FlingExprContext *ctx);
	antlrcpp::Any visitFlingExpr_Mux
		(Parser::FlingExpr_MuxContext *ctx);
	antlrcpp::Any visitFlingExpr_LogOr
		(Parser::FlingExpr_LogOrContext *ctx);
	antlrcpp::Any visitFlingExpr_LogAnd
		(Parser::FlingExpr_LogAndContext *ctx);
	antlrcpp::Any visitFlingExpr_BitOr_Or_BitNor
		(Parser::FlingExpr_BitOr_Or_BitNorContext *ctx);
	antlrcpp::Any visitFlingExpr_BitAnd_Or_BitNand
		(Parser::FlingExpr_BitAnd_Or_BitNandContext *ctx);
	antlrcpp::Any visitFlingExpr_BitXor_Or_BitXnor
		(Parser::FlingExpr_BitXor_Or_BitXnorContext *ctx);
	antlrcpp::Any visitFlingExpr_CmpEqEtc
		(Parser::FlingExpr_CmpEqEtcContext *ctx);
	antlrcpp::Any visitFlingExpr_CmpLtEtc
		(Parser::FlingExpr_CmpLtEtcContext *ctx);
	antlrcpp::Any visitFlingExpr_BitShift
		(Parser::FlingExpr_BitShiftContext *ctx);
	antlrcpp::Any visitFlingExpr_BinaryPlus_Or_BinaryMinus
		(Parser::FlingExpr_BinaryPlus_Or_BinaryMinusContext *ctx);
	antlrcpp::Any visitFlingExpr_Mul_Or_Div_Or_Mod
		(Parser::FlingExpr_Mul_Or_Div_Or_ModContext *ctx);
	antlrcpp::Any visitFlingExpr_Unary
		(Parser::FlingExpr_UnaryContext *ctx);
	antlrcpp::Any visitFlingExpr_Unary_ItemFromMajority
		(Parser::FlingExpr_Unary_ItemFromMajorityContext *ctx);
	antlrcpp::Any visitFlingExpr_Literal
		(Parser::FlingExpr_LiteralContext *ctx);
	antlrcpp::Any visitFlingExpr_Sized
		(Parser::FlingExpr_SizedContext *ctx);
	antlrcpp::Any visitFlingExpr_Range
		(Parser::FlingExpr_RangeContext *ctx);
	antlrcpp::Any visitFlingExpr_Range_DotDot
		(Parser::FlingExpr_Range_DotDotContext *ctx);
	antlrcpp::Any visitFlingExpr_Range_CallFunc
		(Parser::FlingExpr_Range_CallFuncContext *ctx);
	antlrcpp::Any visitFlingExpr_Cat
		(Parser::FlingExpr_CatContext *ctx);
	antlrcpp::Any visitFlingExpr_Repl
		(Parser::FlingExpr_ReplContext *ctx);
	antlrcpp::Any visitFlingExpr_KwDollarFuncOf
		(Parser::FlingExpr_KwDollarFuncOfContext *ctx);
	antlrcpp::Any visitFlingExpr_KwDollarFuncOf_NonPow
		(Parser::FlingExpr_KwDollarFuncOf_NonPowContext *ctx);
	antlrcpp::Any visitFlingExpr_KwDollarFuncOf_Pow
		(Parser::FlingExpr_KwDollarFuncOf_PowContext *ctx);
	antlrcpp::Any visitFlingExpr_IdentEtc
		(Parser::FlingExpr_IdentEtcContext *ctx);
	antlrcpp::Any visitFlingExpr_IdentEtc_FirstItem
		(Parser::FlingExpr_IdentEtc_FirstItemContext *ctx);
	antlrcpp::Any visitFlingExpr_IdentEtc_NonSelfItem
		(Parser::FlingExpr_IdentEtc_NonSelfItemContext *ctx);
	antlrcpp::Any visitFlingExpr_IdentEtc_Item_End
		(Parser::FlingExpr_IdentEtc_Item_EndContext *ctx);
	antlrcpp::Any visitFlingExpr_IdentEtc_Item_End_Index
		(Parser::FlingExpr_IdentEtc_Item_End_IndexContext *ctx);
	antlrcpp::Any visitFlingExpr_Cast
		(Parser::FlingExpr_CastContext *ctx);
	antlrcpp::Any visitFlingExpr_CallSubprog_PseudoOper
		(Parser::FlingExpr_CallSubprog_PseudoOperContext *ctx);
};

class AstNodeDeferredPusher final
{
private:		// variables
	PtVisitor* _pt_visitor = nullptr;
	ast::Base * _node = nullptr,
		* _prev_ast_parent = nullptr;
public:		// functions
	inline AstNodeDeferredPusher(PtVisitor* s_pt_visitor, ast::Base* s_node)
		: _pt_visitor(s_pt_visitor), _node(s_node)
	{
		_prev_ast_parent = _pt_visitor->_curr_ast_parent;
		_pt_visitor->_curr_ast_parent = _node;

		auto& ast_etc = _pt_visitor->_ast_etc_map.at
			(_pt_visitor->_filename);

		if (_prev_ast_parent->level() > ast_etc.max_ast_level())
		{
			ast_etc.set_max_ast_level(_prev_ast_parent->level());
		}
	}
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(AstNodeDeferredPusher);
	inline ~AstNodeDeferredPusher()
	{
		_pt_visitor->_push_ast(_node);
		_pt_visitor->_curr_ast_parent = _prev_ast_parent;
	}
};

class AstNodeListDeferredPusher final
{
private:		// variables
	PtVisitor* _pt_visitor = nullptr;
	ast::BaseSptrList* _node_list = nullptr;
public:		// functions
	inline AstNodeListDeferredPusher(PtVisitor* s_pt_visitor,
		ast::BaseSptrList* s_node_list)
		: _pt_visitor(s_pt_visitor), _node_list(s_node_list)
	{
	}
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(AstNodeListDeferredPusher);
	inline ~AstNodeListDeferredPusher()
	{
		_pt_visitor->_push_ast_list(move(*_node_list));
	}
};

} // namespace fling_hdl


#endif		// src_pt_visitor_class_hpp
