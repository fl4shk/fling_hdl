//#ifndef src_ast_ast_build_children_macro_calls_hpp
//#define src_ast_ast_build_children_macro_calls_hpp

// src/ast/ast_build_children_macro_calls.hpp

//--------
BUILD_CHILDREN(Program, item_list)
//--------

//--------
BUILD_CHILDREN(DeclPackage, item_list)
BUILD_CHILDREN(Import, item_list)
BUILD_CHILDREN(ImportItem, item_list)
//--------

//--------
BUILD_CHILDREN(ParamOrArgList, item_list)
BUILD_CHILDREN(DeclParamSublistItem, opt_typenm, opt_def_val)
BUILD_CHILDREN(DeclArgSublistItem, typenm, opt_def_val)
//--------

//--------
BUILD_CHILDREN(StrAndNode, node)
//--------

//--------
BUILD_CHILDREN(DeclModule, opt_param_list, arg_list, scope)
BUILD_CHILDREN(Scope, item_list)
//--------

//--------
BUILD_CHILDREN(Modinst, modnm, arg_list)
//--------

//--------
BUILD_CHILDREN(GenIf, if_expr, if_scope, opt_elif_list, opt_else_scope)
BUILD_CHILDREN(GenElif, expr, scope)
BUILD_CHILDREN(GenSwitchEtc, expr, opt_default, opt_case_list)
BUILD_CHILDREN(GenCase, expr_list, scope)
BUILD_CHILDREN(GenDefault, scope)
BUILD_CHILDREN(GenFor, range, scope)
//--------

//--------
BUILD_CHILDREN(DeclModuleBehavComb, scope)
BUILD_CHILDREN(DeclModuleBehavSeq, edge_item_list, scope)
BUILD_CHILDREN(DeclModuleBehavSeqEdgeItem, expr)
//--------

//--------
BUILD_CHILDREN(BehavIf, if_expr, if_scope, opt_elif_list, opt_else_scope)
BUILD_CHILDREN(BehavElif, expr, scope)
BUILD_CHILDREN(BehavSwitchEtc, expr, opt_default, opt_case_list)
BUILD_CHILDREN(BehavCase, expr_list, scope)
BUILD_CHILDREN(BehavDefault, scope)
BUILD_CHILDREN(BehavFor, range, scope)
BUILD_CHILDREN(BehavWhile, expr, scope)
//--------

//--------
BUILD_CHILDREN(BehavAssign, lhs, rhs)
//--------

//--------
BUILD_CHILDREN(DeclStruct, opt_param_list, scope)
//--------

//--------
BUILD_CHILDREN(DeclEnum, opt_typenm, item_list)
//--------

//--------
BUILD_CHILDREN(DeclSubprog, opt_param_list, arg_list, opt_ret_typenm,
	scope)
//--------

//--------
BUILD_CHILDREN(DeclVarEtc, typenm, val)
BUILD_CHILDREN(WireAssign, lhs, rhs)
//--------

//--------
BUILD_CHILDREN(DeclAlias, rhs)
//--------

//--------
BUILD_CHILDREN(NamedScope, item_list)
//--------

//--------
BUILD_CHILDREN(MuxExpr, cond, when_true, when_false)
BUILD_CHILDREN(BinopExpr, left, right)
BUILD_CHILDREN(UnopExpr, arg)
BUILD_CHILDREN(LitValExpr, opt_expr)
BUILD_CHILDREN(CallDollarFuncExpr, arg, opt_second_arg)
BUILD_CHILDREN(String)
BUILD_CHILDREN(IdentExprSuffix, acc_memb_or_arr_list, opt_range_etc,
	opt_part_sel_right)
BUILD_CHILDREN(IdentExpr, prologue_list, opt_arg_list, suffix)
BUILD_CHILDREN(CatExpr, item_list)
BUILD_CHILDREN(ReplExpr, amount, to_repl)
BUILD_CHILDREN(SizedExpr, lit_num, width)
//--------

//--------
BUILD_CHILDREN(NonDollarFuncRange, arg, opt_second_arg)
//--------

//--------
BUILD_CHILDREN(Typenm, opt_ident_expr, opt_vec_dim, opt_arr_dim_list)
BUILD_CHILDREN(Modnm, prologue_list, opt_arg_list, suffix)
//--------


//#endif		// src_ast_ast_build_children_macro_calls_hpp
