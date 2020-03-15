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

	//#define LIST \
	//	Base, \
	//	Program, \
	//	DeclPackage, \
	//	DeclParamList, \
	//	DeclParamList_Item, \
	//	DeclArgList, \
	//	DeclArgList_Item, \
	//	InstParamList, \
	//	InstParamList_Pos, \
	//	InstParamList_Named, \
	//	InstParamList_Named_Item, \
	//	InstArgList, \
	//	InstArgList_Named, \
	//	InstArgList_Named_Item, \
	//	DeclModule, \
	//	DeclModule_Scope, \
	//	InstModule, \
	//	Gen, \
	//	Gen_If, \
	//	Gen_Switch, \
	//	Gen_For, \
	//	ContAssign, \
	//	Behav, \
	//	Behav_Seq_EdgeList, \
	//	Behav_Seq_EdgeList_Item, \
	//	Behav_Scope, \
	//	Behav_Item_If, \
	//	Behav_Item_Switch, \
	//	Behav_Item_Switchz, \
	//	Behav_Item_For, \
	//	Behav_Item_While, \
	//	Behav_Item_NonBlkAssign, \
	//	Behav_Item_BlkAssign, \
	//	DeclWire, \
	//	DeclVar, \
	//	DeclConst, \
	//	DeclType, \
	//	DeclEnum, \
	//	DeclClass, \
	//	DeclClass_Item_DeclVar, \
	//	DeclClsOrMxn_Item_DeclType, \
	//	DeclClsOrMxn_Item_DeclAliasOrConst, \
	//	DeclClsOrMxn_Item_DeclSubprog_FullDefn, \
	//	DeclClsOrMxn_Item_DeclSubprog_Abstract, \
	//	DeclMixin, \
	//	DeclSubprog, \
	//	DeclFunc, \
	//	DeclFunc_Header, \
	//	DeclFunc_Scope, \
	//	DeclFunc_Item_If, \
	//	DeclFunc_Item_Switch, \
	//	DeclFunc_Item_Switchz, \
	//	DeclFunc_Item_For, \
	//	DeclFunc_Item_While, \
	//	DeclTask, \
	//	DeclTask_Header, \
	//	DeclTask_Scope, \
	//	DeclTask_Item_If, \
	//	DeclTask_Item_Switch, \
	//	DeclTask_Item_Switchz, \
	//	DeclTask_Item_For, \
	//	DeclTask_Item_While, \
	//	DeclProc, \
	//	DeclProc_Header, \
	//	DeclProc_ArgList, \
	//	DeclProc_ArgList_Item, \
	//	DeclAlias, \
	//	DeclAlias_Value, \
	//	DeclAlias_Type, \
	//	DeclAlias_Module, \
	//	IdentList, \
	//	ScopedIdent, \
	//	ExprList, \
	//	TypenameOrModnameList, \
	//	ImportList, \
	//	TypenameOrModname_SelfT, \
	//	TypenameOrModname_RetT, \
	//	TypenameOrModname, \
	//	TypenameOrModname_Cstm, \
	//	TypenameOrModname_Cstm_Item, \
	//	TypenameOrModname_Builtin, \
	//	Expr, \
	//	Expr_Mux, \
	//	ExprBinopBase, \
	//	ExprUnopBase, \
	//	Expr_LogOr, \
	//	Expr_LogAnd, \
	//	Expr_BinopBitOr, \
	//	Expr_BinopBitNor, \
	//	Expr_BinopBitAnd, \
	//	Expr_BinopBitNand, \
	//	Expr_BinopBitXor, \
	//	Expr_BinopBitXnor, \
	//	Expr_CmpEq, \
	//	Expr_CmpNe, \
	//	Expr_CaseCmpEq, \
	//	Expr_CaseCmpNe, \
	//	Expr_CmpLt, \
	//	Expr_CmpLe, \
	//	Expr_CmpGt, \
	//	Expr_CmpGe, \
	//	Expr_BitLsl, \
	//	Expr_BitLsr, \
	//	Expr_BitAsr, \
	//	Expr_BinopPlus, \
	//	Expr_BinopMinus, \
	//	Expr_Mul, \
	//	Expr_Div, \
	//	Expr_Mod, \
	//	Expr_UnopPlus, \
	//	Expr_UnopMinus, \
	//	Expr_LogNot, \
	//	Expr_BitNot, \
	//	Expr_UnopBitOr, \
	//	Expr_UnopBitNor, \
	//	Expr_UnopBitAnd, \
	//	Expr_UnopBitNand, \
	//	Expr_UnopBitXor, \
	//	Expr_UnopBitXnor, \
	//	Expr_Literal, \
	//	Expr_Sized, \
	//	Expr_Range, \
	//	Expr_Cat, \
	//	Expr_Repl, \
	//	Expr_KwDollarFuncOf_NonPow, \
	//	Expr_KwDollarFuncOf_Pow, \
	//	Expr_IdentEtcAndOptKwDollarFuncOf, \
	//	Expr_IdentEtc, \
	//	Expr_IdentEtc_Item, \
	//	Expr_IdentEtc_Item_End_Index, \
	//	Expr_IdentEtc_Item_End_SubprogCallSuffix, \
	//	Expr_IdentEtc_Item_End_KwDollarOper, \
	//	Expr_CallSubprog_Regular, \
	//	Expr_CallSubprog_PseudoOper

	//#define BUILD_VISIT(name) \
	//	virtual void visit##name(shared_ptr<ast::name>& self) = 0;
	//EVAL(MAP(BUILD_VISIT, COMMA, LIST))
	//#undef BUILD_VISIT

	#undef LIST
};

} // namespace fling_hdl

#endif		// src_ast_visitor_class_hpp
