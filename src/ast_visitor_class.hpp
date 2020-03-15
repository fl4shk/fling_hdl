#ifndef src_ast_visitor_class_hpp
#define src_ast_visitor_class_hpp

// src/ast_visitor_class.hpp

#include "misc_includes.hpp"
#include "ast_node_classes.hpp"

namespace fling_hdl
{

class AstVisitor
{
public:		// functions
	inline AstVisitor() = default;
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(AstVisitor);
	virtual inline ~AstVisitor() = default;

	#define LIST(X) \
		X(Base) \
		X(Program) \
		X(DeclPackage) \
		X(DeclParamList) \
		X(DeclParamList_Item) \
		X(DeclArgList) \
		X(DeclArgList_Item) \
		X(InstParamList) \
		X(InstParamList_Pos) \
		X(InstParamList_Named) \
		X(InstParamList_Named_Item) \
		X(InstArgList) \
		X(InstArgList_Named) \
		X(InstArgList_Named_Item) \
		X(DeclModule) \
		X(DeclModule_Scope) \
		X(InstModule) \
		X(Gen) \
		X(Gen_If) \
		X(Gen_Switch) \
		X(Gen_For) \
		X(ContAssign) \
		X(Behav) \
		X(Behav_Seq_EdgeList) \
		X(Behav_Seq_EdgeList_Item) \
		X(Behav_Scope) \
		X(Behav_Item_If) \
		X(Behav_Item_Switch) \
		X(Behav_Item_Switchz) \
		X(Behav_Item_For) \
		X(Behav_Item_While) \
		X(Behav_Item_NonBlkAssign) \
		X(Behav_Item_BlkAssign) \
		X(DeclWire) \
		X(DeclVar) \
		X(DeclConst) \
		X(DeclType) \
		X(DeclEnum) \
		X(DeclClass) \
		X(DeclClass_Item_DeclVar) \
		X(DeclClsOrMxn_Item_DeclType) \
		X(DeclClsOrMxn_Item_DeclAliasOrConst) \
		X(DeclClsOrMxn_Item_DeclSubprog_FullDefn) \
		X(DeclClsOrMxn_Item_DeclSubprog_Abstract) \
		X(DeclMixin) \
		X(DeclSubprog) \
		X(DeclFunc) \
		X(DeclFunc_Header) \
		X(DeclFunc_Scope) \
		X(DeclFunc_Item_If) \
		X(DeclFunc_Item_Switch) \
		X(DeclFunc_Item_Switchz) \
		X(DeclFunc_Item_For) \
		X(DeclFunc_Item_While) \
		X(DeclTask) \
		X(DeclTask_Header) \
		X(DeclTask_Scope) \
		X(DeclTask_Item_If) \
		X(DeclTask_Item_Switch) \
		X(DeclTask_Item_Switchz) \
		X(DeclTask_Item_For) \
		X(DeclTask_Item_While) \
		X(DeclProc) \
		X(DeclProc_Header) \
		X(DeclProc_ArgList) \
		X(DeclProc_ArgList_Item) \
		X(DeclAlias) \
		X(DeclAlias_Value) \
		X(DeclAlias_Type) \
		X(DeclAlias_Module) \
		X(IdentList) \
		X(ScopedIdent) \
		X(ExprList) \
		X(TypenameOrModnameList) \
		X(ImportList) \
		X(TypenameOrModname_SelfT) \
		X(TypenameOrModname_RetT) \
		X(TypenameOrModname) \
		X(TypenameOrModname_Cstm) \
		X(TypenameOrModname_Cstm_Item) \
		X(TypenameOrModname_Builtin) \
		X(Expr) \
		X(Expr_Mux) \
		X(ExprBinopBase) \
		X(ExprUnopBase) \
		X(Expr_LogOr) \
		X(Expr_LogAnd) \
		X(Expr_BinopBitOr) \
		X(Expr_BinopBitNor) \
		X(Expr_BinopBitAnd) \
		X(Expr_BinopBitNand) \
		X(Expr_BinopBitXor) \
		X(Expr_BinopBitXnor) \
		X(Expr_CmpEq) \
		X(Expr_CmpNe) \
		X(Expr_CaseCmpEq) \
		X(Expr_CaseCmpNe) \
		X(Expr_CmpLt) \
		X(Expr_CmpLe) \
		X(Expr_CmpGt) \
		X(Expr_CmpGe) \
		X(Expr_BitLsl) \
		X(Expr_BitLsr) \
		X(Expr_BitAsr) \
		X(Expr_BinopPlus) \
		X(Expr_BinopMinus) \
		X(Expr_Mul) \
		X(Expr_Div) \
		X(Expr_Mod) \
		X(Expr_UnopPlus) \
		X(Expr_UnopMinus) \
		X(Expr_LogNot) \
		X(Expr_BitNot) \
		X(Expr_UnopBitOr) \
		X(Expr_UnopBitNor) \
		X(Expr_UnopBitAnd) \
		X(Expr_UnopBitNand) \
		X(Expr_UnopBitXor) \
		X(Expr_UnopBitXnor) \
		X(Expr_Literal) \
		X(Expr_Sized) \
		X(Expr_Range) \
		X(Expr_Cat) \
		X(Expr_Repl) \
		X(Expr_KwDollarFuncOf_NonPow) \
		X(Expr_KwDollarFuncOf_Pow) \
		X(Expr_IdentEtcAndOptKwDollarFuncOf) \
		X(Expr_IdentEtc) \
		X(Expr_IdentEtc_Item) \
		X(Expr_IdentEtc_Item_End_Index) \
		X(Expr_IdentEtc_Item_End_SubprogCallSuffix) \
		X(Expr_IdentEtc_Item_End_KwDollarOper) \
		X(Expr_CallSubprog_Regular) \
		X(Expr_CallSubprog_PseudoOper

	#undef LIST
};

} // namespace fling_hdl

#endif		// src_ast_visitor_class_hpp
