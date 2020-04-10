//#ifndef src_list_of_ast_node_classes_define_hpp
//#define src_list_of_ast_node_classes_define_hpp

// src/list_of_ast_node_classes_define.hpp

//#include "misc_includes.hpp"

// List of AST node classes that are intended to actually be instantiated
#define LIST_OF_AST_NODE_CLASSES(X) \
	X(Program) \
	\
	X(DeclPackage) \
	\
	X(ParamOrArgList) \
	X(DeclParamList_Item) \
	/* This covers both regular argument lists and those for `proc`s */ \
	X(DeclArgList_Item) \
	X(InstParamList_Named_Item) \
	X(InstArgList_Named_Item) \
	\
	X(DeclModule) \
	\
	X(InstModule) \
	\
	X(GenIf) \
	X(GenIf_Elif) \
	X(GenIf_Else) \
	\
	X(GenSwitch) \
	X(GenSwitch_Case) \
	X(GenSwitch_Default) \
	\
	X(GenFor) \
	\
	X(ContAssign) \
	\
	X(Behav) \
	X(Behav_SeqEdgeListItem) \
	/* This is used for behavioral blocks, functions, and tasks */ \
	X(Behav_Scope) \
	\
	X(If) \
	X(If_Elif) \
	X(If_Else) \
	\
	X(Switch) \
	X(Switchz) \
	X(SwitchOrSwitchz_Case) \
	X(SwitchOrSwitchz_Default) \
	\
	X(For) \
	X(While) \
	\
	X(NonBlkAssign) \
	X(BlkAssign) \
	\
	X(DeclWire) \
	X(DeclVar) \
	X(DeclConst) \
	\
	X(DeclEnum) \
	\
	X(DeclMixin) \
	X(DeclClass) \
	\
	X(DeclClass_DeclVar) \
	X(DeclClsOrMxn_DeclType) \
	X(DeclClsOrMxn_DeclAliasOrConst) \
	\
	X(DeclClsOrMxn_DeclSubprogFullDefn) \
	X(DeclClsOrMxn_DeclSubprogAbstract) \
	\
	X(DeclFunc) \
	X(DeclFunc_Header) \
	X(DeclFunc_Return) \
	X(DeclFunc_Defer) \
	\
	X(DeclTask) \
	X(DeclTask_Header) \
	\
	X(DeclProc) \
	X(DeclProc_Header) \
	\
	X(DeclAlias_Value) \
	X(DeclAlias_Type) \
	X(DeclAlias_Module) \
	\
	X(IdentList) \
	X(ScopedIdent) \
	X(ImportList) \
	X(ImportList_Item) \
	\
	X(TypenameOrModname_Special) \
	X(TypenameOrModname_Cstm) \
	X(TypenameOrModname_Typeof) \
	X(TypenameOrModname_Cstm_Item) \
	X(TypenameOrModname_Builtin) \
	\
	X(ExprMux) \
	\
	X(ExprLogOr) \
	X(ExprLogAnd) \
	\
	X(ExprBinopBitOr) \
	X(ExprBinopBitNor) \
	X(ExprBinopBitAnd) \
	X(ExprBinopBitNand) \
	X(ExprBinopBitXor) \
	X(ExprBinopBitXnor) \
	\
	X(ExprCmpEq) \
	X(ExprCmpNe) \
	X(ExprCaseCmpEq) \
	X(ExprCaseCmpNe) \
	X(ExprCmpLt) \
	X(ExprCmpLe) \
	X(ExprCmpGt) \
	X(ExprCmpGe) \
	\
	X(ExprBitLsl) \
	X(ExprBitLsr) \
	X(ExprBitAsr) \
	\
	X(ExprBinopPlus) \
	X(ExprBinopMinus) \
	\
	X(ExprMul) \
	X(ExprDiv) \
	X(ExprMod) \
	\
	X(ExprUnopPlus) \
	X(ExprUnopMinus) \
	X(ExprLogNot) \
	X(ExprBitNot) \
	\
	X(ExprUnopBitOr) \
	X(ExprUnopBitNor) \
	X(ExprUnopBitAnd) \
	X(ExprUnopBitNand) \
	X(ExprUnopBitXor) \
	X(ExprUnopBitXnor) \
	\
	X(ExprLiteral) \
	X(ExprSized) \
	\
	X(ExprRange) \
	\
	X(ExprCat) \
	X(ExprRepl) \
	\
	X(ExprDollarSigned) \
	X(ExprDollarUnsigned) \
	X(ExprDollarClog2) \
	X(ExprDollarIsvtype) \
	X(ExprDollarPow) \
	\
	X(ExprIdentEtc) \
	X(ExprIdentEtc_FirstItem) \
	X(ExprIdentEtc_NonSelfItem) \
	X(ExprIdentEtc_ItemEnd) \
	X(ExprIdentEtc_ItemEndIndex) \
	\
	X(ExprCast) \
	\
	/* Call a member function via `a plus b` instead of `a.plus(b)` */ \
	X(ExprCallSubprog_PseudoOper) \





//#endif		// src_list_of_ast_node_classes_define_hpp
