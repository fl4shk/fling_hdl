//#ifndef src_ast_ast_build_data_macro_calls_hpp
//#define src_ast_ast_build_data_macro_calls_hpp

// src/ast/ast_build_data_macro_calls.hpp

//--------
BUILD_DATA(Program)
//--------

//--------
BUILD_DATA(DeclPackage, ident)

BUILD_DATA(Import)
BUILD_DATA(ImportItem, ends_with_all)
//--------

//--------
BUILD_DATA(ParamOrArgList)

BUILD_DATA(DeclParamSublistItem, ident, kind)
BUILD_DATA(DeclArgSublistItem, ident, kind)
BUILD_DATA(StrAndNode, str)
//--------

//--------
BUILD_DATA(DeclModule, ident)
BUILD_DATA(Scope)
//--------

//--------
BUILD_DATA(Modinst, ident)
//--------

//--------
BUILD_DATA(GenIf)
BUILD_DATA(GenElif)
BUILD_DATA(GenSwitchEtc, kind)
BUILD_DATA(GenCase)
BUILD_DATA(GenDefault)
BUILD_DATA(GenFor, label, iter_ident)
//--------

//--------
BUILD_DATA(DeclModuleBehavComb)
BUILD_DATA(DeclModuleBehavSeq)
BUILD_DATA(DeclModuleBehavSeqEdgeItem, kind)
//--------

//--------
BUILD_DATA(BehavIf)
BUILD_DATA(BehavElif)
BUILD_DATA(BehavSwitchEtc, kind)
BUILD_DATA(BehavCase)
BUILD_DATA(BehavDefault)
BUILD_DATA(BehavFor, iter_ident)
BUILD_DATA(BehavWhile)
//--------

//--------
BUILD_DATA(BehavAssign, kind)
//--------

//--------
BUILD_DATA(DeclStruct, ident)
//--------

//--------
BUILD_DATA(DeclEnum, ident)
//--------

//--------
BUILD_DATA(DeclSubprog, kind, ident)
//--------

//--------
BUILD_DATA(DeclVarEtc, kind, ident)
BUILD_DATA(WireAssign)
//--------

//--------
BUILD_DATA(DeclAlias, ident, kind)
//--------

//--------
BUILD_DATA(NamedScope)
//--------

//--------
BUILD_DATA(MuxExpr, is_self_determined,)
BUILD_DATA(BinopExpr, is_self_determined, kind)
BUILD_DATA(UnopExpr, is_self_determined, kind)

BUILD_DATA(LitValExpr, is_self_determined, kind, opt_num_str, opt_num)

BUILD_DATA(CallDollarFuncExpr, is_self_determined, kind)

BUILD_DATA(String, data)
BUILD_DATA(IdentExprSuffix, part_sel_is_minus_colon)
BUILD_DATA(IdentExpr, is_self_determined)

BUILD_DATA(CatExpr, is_self_determined)
BUILD_DATA(ReplExpr, is_self_determined)

BUILD_DATA(SizedExpr, is_self_determined)
//--------

//--------
BUILD_DATA(NonDollarFuncRange)
//--------

//--------
BUILD_DATA(Typenm, kind)
BUILD_DATA(Modnm)
//--------


//#endif		// src_ast_ast_build_data_macro_calls_hpp
