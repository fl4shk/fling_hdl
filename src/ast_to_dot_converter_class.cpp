#include "ast_to_dot_converter_class.hpp"

namespace fling_hdl
{

using namespace ast;

void AstToDotConverter::convert(size_t max_ast_level,
	const string& dst_filename, const string& src_filename, Base* root)
{
	_max_ast_level = max_ast_level;
	_file.open(dst_filename, std::ios_base::out | std::ios_base::trunc);

	osprintout(_file,
		"digraph ", src_filename, "\n",
		"{\n",
		"\tordering=out;\n",
		"\tclusterrank=global;\n",
		"\tsize=\"6,4\";\n",
		"\tratio=fill;\n",
		"\tremincross=true;\n",
		"\trankdir=LR;\n",
		"\tstyle=\"invis\";\n",
		"\tnode [fontname=Helvetica];\n");

	_state = State::BuildNodeVec;
	root->accept(this);

	_state = State::Print;
	root->accept(this);

	osprintout(_file,
		"}\n");

	_file.close();
}
void AstToDotConverter::_print_node(Base* to_print, const string& lab)
{
}
void AstToDotConverter::_print_conn(Base* parent, Base* child)
{
}
void AstToDotConverter::_print_conn(Base* parent, const string& child)
{
}

void AstToDotConverter
	::visitProgram_build_node_vec
	(Program* node)
{
}
void AstToDotConverter
	::visitProgram_print
	(Program* node)
{
}

void AstToDotConverter
	::visitDeclPackage_build_node_vec
	(DeclPackage* node)
{
}
void AstToDotConverter
	::visitDeclPackage_print
	(DeclPackage* node)
{
}

void AstToDotConverter
	::visitParamOrArgList_build_node_vec
	(ParamOrArgList* node)
{
}
void AstToDotConverter
	::visitParamOrArgList_print
	(ParamOrArgList* node)
{
}
void AstToDotConverter
	::visitDeclParamList_Item_build_node_vec
	(DeclParamList_Item* node)
{
}
void AstToDotConverter
	::visitDeclParamList_Item_print
	(DeclParamList_Item* node)
{
}
// This covers both regular argument lists and those for `proc`s
void AstToDotConverter
	::visitDeclArgList_Item_build_node_vec
	(DeclArgList_Item* node)
{
}
void AstToDotConverter
	::visitDeclArgList_Item_print
	(DeclArgList_Item* node)
{
}
void AstToDotConverter
	::visitInstParamList_Named_Item_build_node_vec
	(InstParamList_Named_Item* node)
{
}
void AstToDotConverter
	::visitInstParamList_Named_Item_print
	(InstParamList_Named_Item* node)
{
}
void AstToDotConverter
	::visitInstArgList_Named_Item_build_node_vec
	(InstArgList_Named_Item* node)
{
}
void AstToDotConverter
	::visitInstArgList_Named_Item_print
	(InstArgList_Named_Item* node)
{
}

void AstToDotConverter
	::visitDeclModule_build_node_vec
	(DeclModule* node)
{
}
void AstToDotConverter
	::visitDeclModule_print
	(DeclModule* node)
{
}

void AstToDotConverter
	::visitInstModule_build_node_vec
	(InstModule* node)
{
}
void AstToDotConverter
	::visitInstModule_print
	(InstModule* node)
{
}

void AstToDotConverter
	::visitGenIf_build_node_vec
	(GenIf* node)
{
}
void AstToDotConverter
	::visitGenIf_print
	(GenIf* node)
{
}
void AstToDotConverter
	::visitGenIf_Elif_build_node_vec
	(GenIf_Elif* node)
{
}
void AstToDotConverter
	::visitGenIf_Elif_print
	(GenIf_Elif* node)
{
}
void AstToDotConverter
	::visitGenIf_Else_build_node_vec
	(GenIf_Else* node)
{
}
void AstToDotConverter
	::visitGenIf_Else_print
	(GenIf_Else* node)
{
}

void AstToDotConverter
	::visitGenSwitch_build_node_vec
	(GenSwitch* node)
{
}
void AstToDotConverter
	::visitGenSwitch_print
	(GenSwitch* node)
{
}
void AstToDotConverter
	::visitGenSwitch_Case_build_node_vec
	(GenSwitch_Case* node)
{
}
void AstToDotConverter
	::visitGenSwitch_Case_print
	(GenSwitch_Case* node)
{
}
void AstToDotConverter
	::visitGenSwitch_Default_build_node_vec
	(GenSwitch_Default* node)
{
}
void AstToDotConverter
	::visitGenSwitch_Default_print
	(GenSwitch_Default* node)
{
}

void AstToDotConverter
	::visitGenFor_build_node_vec
	(GenFor* node)
{
}
void AstToDotConverter
	::visitGenFor_print
	(GenFor* node)
{
}

void AstToDotConverter
	::visitContAssign_build_node_vec
	(ContAssign* node)
{
}
void AstToDotConverter
	::visitContAssign_print
	(ContAssign* node)
{
}

void AstToDotConverter
	::visitBehav_build_node_vec
	(Behav* node)
{
}
void AstToDotConverter
	::visitBehav_print
	(Behav* node)
{
}
void AstToDotConverter
	::visitBehav_SeqEdgeListItem_build_node_vec
	(Behav_SeqEdgeListItem* node)
{
}
void AstToDotConverter
	::visitBehav_SeqEdgeListItem_print
	(Behav_SeqEdgeListItem* node)
{
}
// This is used for behavioral blocks, functions, and tasks
void AstToDotConverter
	::visitBehav_Scope_build_node_vec
	(Behav_Scope* node)
{
}
void AstToDotConverter
	::visitBehav_Scope_print
	(Behav_Scope* node)
{
}

void AstToDotConverter
	::visitIf_build_node_vec
	(If* node)
{
}
void AstToDotConverter
	::visitIf_print
	(If* node)
{
}
void AstToDotConverter
	::visitIf_Elif_build_node_vec
	(If_Elif* node)
{
}
void AstToDotConverter
	::visitIf_Elif_print
	(If_Elif* node)
{
}
void AstToDotConverter
	::visitIf_Else_build_node_vec
	(If_Else* node)
{
}
void AstToDotConverter
	::visitIf_Else_print
	(If_Else* node)
{
}

void AstToDotConverter
	::visitSwitch_build_node_vec
	(Switch* node)
{
}
void AstToDotConverter
	::visitSwitch_print
	(Switch* node)
{
}
void AstToDotConverter
	::visitSwitchz_build_node_vec
	(Switchz* node)
{
}
void AstToDotConverter
	::visitSwitchz_print
	(Switchz* node)
{
}
void AstToDotConverter
	::visitSwitchOrSwitchz_Case_build_node_vec
	(SwitchOrSwitchz_Case* node)
{
}
void AstToDotConverter
	::visitSwitchOrSwitchz_Case_print
	(SwitchOrSwitchz_Case* node)
{
}
void AstToDotConverter
	::visitSwitchOrSwitchz_Default_build_node_vec
	(SwitchOrSwitchz_Default* node)
{
}
void AstToDotConverter
	::visitSwitchOrSwitchz_Default_print
	(SwitchOrSwitchz_Default* node)
{
}

void AstToDotConverter
	::visitFor_build_node_vec
	(For* node)
{
}
void AstToDotConverter
	::visitFor_print
	(For* node)
{
}
void AstToDotConverter
	::visitWhile_build_node_vec
	(While* node)
{
}
void AstToDotConverter
	::visitWhile_print
	(While* node)
{
}

void AstToDotConverter
	::visitNonBlkAssign_build_node_vec
	(NonBlkAssign* node)
{
}
void AstToDotConverter
	::visitNonBlkAssign_print
	(NonBlkAssign* node)
{
}
void AstToDotConverter
	::visitBlkAssign_build_node_vec
	(BlkAssign* node)
{
}
void AstToDotConverter
	::visitBlkAssign_print
	(BlkAssign* node)
{
}

void AstToDotConverter
	::visitDeclWire_build_node_vec
	(DeclWire* node)
{
}
void AstToDotConverter
	::visitDeclWire_print
	(DeclWire* node)
{
}
void AstToDotConverter
	::visitDeclVar_build_node_vec
	(DeclVar* node)
{
}
void AstToDotConverter
	::visitDeclVar_print
	(DeclVar* node)
{
}
void AstToDotConverter
	::visitDeclConst_build_node_vec
	(DeclConst* node)
{
}
void AstToDotConverter
	::visitDeclConst_print
	(DeclConst* node)
{
}

void AstToDotConverter
	::visitDeclEnum_build_node_vec
	(DeclEnum* node)
{
}
void AstToDotConverter
	::visitDeclEnum_print
	(DeclEnum* node)
{
}

void AstToDotConverter
	::visitDeclMixin_build_node_vec
	(DeclMixin* node)
{
}
void AstToDotConverter
	::visitDeclMixin_print
	(DeclMixin* node)
{
}
void AstToDotConverter
	::visitDeclClass_build_node_vec
	(DeclClass* node)
{
}
void AstToDotConverter
	::visitDeclClass_print
	(DeclClass* node)
{
}

void AstToDotConverter
	::visitDeclClass_DeclVar_build_node_vec
	(DeclClass_DeclVar* node)
{
}
void AstToDotConverter
	::visitDeclClass_DeclVar_print
	(DeclClass_DeclVar* node)
{
}
void AstToDotConverter
	::visitDeclClsOrMxn_DeclType_build_node_vec
	(DeclClsOrMxn_DeclType* node)
{
}
void AstToDotConverter
	::visitDeclClsOrMxn_DeclType_print
	(DeclClsOrMxn_DeclType* node)
{
}
void AstToDotConverter
	::visitDeclClsOrMxn_DeclAliasOrConst_build_node_vec
	(DeclClsOrMxn_DeclAliasOrConst* node)
{
}
void AstToDotConverter
	::visitDeclClsOrMxn_DeclAliasOrConst_print
	(DeclClsOrMxn_DeclAliasOrConst* node)
{
}

void AstToDotConverter
	::visitDeclClsOrMxn_DeclSubprogFullDefn_build_node_vec
	(DeclClsOrMxn_DeclSubprogFullDefn* node)
{
}
void AstToDotConverter
	::visitDeclClsOrMxn_DeclSubprogFullDefn_print
	(DeclClsOrMxn_DeclSubprogFullDefn* node)
{
}
void AstToDotConverter
	::visitDeclClsOrMxn_DeclSubprogAbstract_build_node_vec
	(DeclClsOrMxn_DeclSubprogAbstract* node)
{
}
void AstToDotConverter
	::visitDeclClsOrMxn_DeclSubprogAbstract_print
	(DeclClsOrMxn_DeclSubprogAbstract* node)
{
}

void AstToDotConverter
	::visitDeclFunc_build_node_vec
	(DeclFunc* node)
{
}
void AstToDotConverter
	::visitDeclFunc_print
	(DeclFunc* node)
{
}
void AstToDotConverter
	::visitDeclFunc_Header_build_node_vec
	(DeclFunc_Header* node)
{
}
void AstToDotConverter
	::visitDeclFunc_Header_print
	(DeclFunc_Header* node)
{
}
void AstToDotConverter
	::visitDeclFunc_Return_build_node_vec
	(DeclFunc_Return* node)
{
}
void AstToDotConverter
	::visitDeclFunc_Return_print
	(DeclFunc_Return* node)
{
}

void AstToDotConverter
	::visitDeclTask_build_node_vec
	(DeclTask* node)
{
}
void AstToDotConverter
	::visitDeclTask_print
	(DeclTask* node)
{
}
void AstToDotConverter
	::visitDeclTask_Header_build_node_vec
	(DeclTask_Header* node)
{
}
void AstToDotConverter
	::visitDeclTask_Header_print
	(DeclTask_Header* node)
{
}

void AstToDotConverter
	::visitDeclProc_build_node_vec
	(DeclProc* node)
{
}
void AstToDotConverter
	::visitDeclProc_print
	(DeclProc* node)
{
}
void AstToDotConverter
	::visitDeclProc_Header_build_node_vec
	(DeclProc_Header* node)
{
}
void AstToDotConverter
	::visitDeclProc_Header_print
	(DeclProc_Header* node)
{
}

void AstToDotConverter
	::visitDeclAlias_Value_build_node_vec
	(DeclAlias_Value* node)
{
}
void AstToDotConverter
	::visitDeclAlias_Value_print
	(DeclAlias_Value* node)
{
}
void AstToDotConverter
	::visitDeclAlias_Type_build_node_vec
	(DeclAlias_Type* node)
{
}
void AstToDotConverter
	::visitDeclAlias_Type_print
	(DeclAlias_Type* node)
{
}
void AstToDotConverter
	::visitDeclAlias_Module_build_node_vec
	(DeclAlias_Module* node)
{
}
void AstToDotConverter
	::visitDeclAlias_Module_print
	(DeclAlias_Module* node)
{
}

void AstToDotConverter
	::visitIdentList_build_node_vec
	(IdentList* node)
{
}
void AstToDotConverter
	::visitIdentList_print
	(IdentList* node)
{
}
void AstToDotConverter
	::visitScopedIdent_build_node_vec
	(ScopedIdent* node)
{
}
void AstToDotConverter
	::visitScopedIdent_print
	(ScopedIdent* node)
{
}
void AstToDotConverter
	::visitImportList_build_node_vec
	(ImportList* node)
{
}
void AstToDotConverter
	::visitImportList_print
	(ImportList* node)
{
}

void AstToDotConverter
	::visitTypenameOrModname_Special_build_node_vec
	(TypenameOrModname_Special* node)
{
}
void AstToDotConverter
	::visitTypenameOrModname_Special_print
	(TypenameOrModname_Special* node)
{
}
void AstToDotConverter
	::visitTypenameOrModname_Cstm_build_node_vec
	(TypenameOrModname_Cstm* node)
{
}
void AstToDotConverter
	::visitTypenameOrModname_Cstm_print
	(TypenameOrModname_Cstm* node)
{
}
void AstToDotConverter
	::visitTypenameOrModname_Typeof_build_node_vec
	(TypenameOrModname_Typeof* node)
{
}
void AstToDotConverter
	::visitTypenameOrModname_Typeof_print
	(TypenameOrModname_Typeof* node)
{
}
void AstToDotConverter
	::visitTypenameOrModname_Cstm_Item_build_node_vec
	(TypenameOrModname_Cstm_Item* node)
{
}
void AstToDotConverter
	::visitTypenameOrModname_Cstm_Item_print
	(TypenameOrModname_Cstm_Item* node)
{
}
void AstToDotConverter
	::visitTypenameOrModname_Builtin_build_node_vec
	(TypenameOrModname_Builtin* node)
{
}
void AstToDotConverter
	::visitTypenameOrModname_Builtin_print
	(TypenameOrModname_Builtin* node)
{
}

void AstToDotConverter
	::visitExprMux_build_node_vec
	(ExprMux* node)
{
}
void AstToDotConverter
	::visitExprMux_print
	(ExprMux* node)
{
}

void AstToDotConverter
	::visitExprLogOr_build_node_vec
	(ExprLogOr* node)
{
}
void AstToDotConverter
	::visitExprLogOr_print
	(ExprLogOr* node)
{
}
void AstToDotConverter
	::visitExprLogAnd_build_node_vec
	(ExprLogAnd* node)
{
}
void AstToDotConverter
	::visitExprLogAnd_print
	(ExprLogAnd* node)
{
}

void AstToDotConverter
	::visitExprBinopBitOr_build_node_vec
	(ExprBinopBitOr* node)
{
}
void AstToDotConverter
	::visitExprBinopBitOr_print
	(ExprBinopBitOr* node)
{
}
void AstToDotConverter
	::visitExprBinopBitNor_build_node_vec
	(ExprBinopBitNor* node)
{
}
void AstToDotConverter
	::visitExprBinopBitNor_print
	(ExprBinopBitNor* node)
{
}
void AstToDotConverter
	::visitExprBinopBitAnd_build_node_vec
	(ExprBinopBitAnd* node)
{
}
void AstToDotConverter
	::visitExprBinopBitAnd_print
	(ExprBinopBitAnd* node)
{
}
void AstToDotConverter
	::visitExprBinopBitNand_build_node_vec
	(ExprBinopBitNand* node)
{
}
void AstToDotConverter
	::visitExprBinopBitNand_print
	(ExprBinopBitNand* node)
{
}
void AstToDotConverter
	::visitExprBinopBitXor_build_node_vec
	(ExprBinopBitXor* node)
{
}
void AstToDotConverter
	::visitExprBinopBitXor_print
	(ExprBinopBitXor* node)
{
}
void AstToDotConverter
	::visitExprBinopBitXnor_build_node_vec
	(ExprBinopBitXnor* node)
{
}
void AstToDotConverter
	::visitExprBinopBitXnor_print
	(ExprBinopBitXnor* node)
{
}

void AstToDotConverter
	::visitExprCmpEq_build_node_vec
	(ExprCmpEq* node)
{
}
void AstToDotConverter
	::visitExprCmpEq_print
	(ExprCmpEq* node)
{
}
void AstToDotConverter
	::visitExprCmpNe_build_node_vec
	(ExprCmpNe* node)
{
}
void AstToDotConverter
	::visitExprCmpNe_print
	(ExprCmpNe* node)
{
}
void AstToDotConverter
	::visitExprCaseCmpEq_build_node_vec
	(ExprCaseCmpEq* node)
{
}
void AstToDotConverter
	::visitExprCaseCmpEq_print
	(ExprCaseCmpEq* node)
{
}
void AstToDotConverter
	::visitExprCaseCmpNe_build_node_vec
	(ExprCaseCmpNe* node)
{
}
void AstToDotConverter
	::visitExprCaseCmpNe_print
	(ExprCaseCmpNe* node)
{
}
void AstToDotConverter
	::visitExprCmpLt_build_node_vec
	(ExprCmpLt* node)
{
}
void AstToDotConverter
	::visitExprCmpLt_print
	(ExprCmpLt* node)
{
}
void AstToDotConverter
	::visitExprCmpLe_build_node_vec
	(ExprCmpLe* node)
{
}
void AstToDotConverter
	::visitExprCmpLe_print
	(ExprCmpLe* node)
{
}
void AstToDotConverter
	::visitExprCmpGt_build_node_vec
	(ExprCmpGt* node)
{
}
void AstToDotConverter
	::visitExprCmpGt_print
	(ExprCmpGt* node)
{
}
void AstToDotConverter
	::visitExprCmpGe_build_node_vec
	(ExprCmpGe* node)
{
}
void AstToDotConverter
	::visitExprCmpGe_print
	(ExprCmpGe* node)
{
}

void AstToDotConverter
	::visitExprBitLsl_build_node_vec
	(ExprBitLsl* node)
{
}
void AstToDotConverter
	::visitExprBitLsl_print
	(ExprBitLsl* node)
{
}
void AstToDotConverter
	::visitExprBitLsr_build_node_vec
	(ExprBitLsr* node)
{
}
void AstToDotConverter
	::visitExprBitLsr_print
	(ExprBitLsr* node)
{
}
void AstToDotConverter
	::visitExprBitAsr_build_node_vec
	(ExprBitAsr* node)
{
}
void AstToDotConverter
	::visitExprBitAsr_print
	(ExprBitAsr* node)
{
}

void AstToDotConverter
	::visitExprBinopPlus_build_node_vec
	(ExprBinopPlus* node)
{
}
void AstToDotConverter
	::visitExprBinopPlus_print
	(ExprBinopPlus* node)
{
}
void AstToDotConverter
	::visitExprBinopMinus_build_node_vec
	(ExprBinopMinus* node)
{
}
void AstToDotConverter
	::visitExprBinopMinus_print
	(ExprBinopMinus* node)
{
}

void AstToDotConverter
	::visitExprMul_build_node_vec
	(ExprMul* node)
{
}
void AstToDotConverter
	::visitExprMul_print
	(ExprMul* node)
{
}
void AstToDotConverter
	::visitExprDiv_build_node_vec
	(ExprDiv* node)
{
}
void AstToDotConverter
	::visitExprDiv_print
	(ExprDiv* node)
{
}
void AstToDotConverter
	::visitExprMod_build_node_vec
	(ExprMod* node)
{
}
void AstToDotConverter
	::visitExprMod_print
	(ExprMod* node)
{
}

void AstToDotConverter
	::visitExprUnopPlus_build_node_vec
	(ExprUnopPlus* node)
{
}
void AstToDotConverter
	::visitExprUnopPlus_print
	(ExprUnopPlus* node)
{
}
void AstToDotConverter
	::visitExprUnopMinus_build_node_vec
	(ExprUnopMinus* node)
{
}
void AstToDotConverter
	::visitExprUnopMinus_print
	(ExprUnopMinus* node)
{
}
void AstToDotConverter
	::visitExprLogNot_build_node_vec
	(ExprLogNot* node)
{
}
void AstToDotConverter
	::visitExprLogNot_print
	(ExprLogNot* node)
{
}
void AstToDotConverter
	::visitExprBitNot_build_node_vec
	(ExprBitNot* node)
{
}
void AstToDotConverter
	::visitExprBitNot_print
	(ExprBitNot* node)
{
}

void AstToDotConverter
	::visitExprUnopBitOr_build_node_vec
	(ExprUnopBitOr* node)
{
}
void AstToDotConverter
	::visitExprUnopBitOr_print
	(ExprUnopBitOr* node)
{
}
void AstToDotConverter
	::visitExprUnopBitNor_build_node_vec
	(ExprUnopBitNor* node)
{
}
void AstToDotConverter
	::visitExprUnopBitNor_print
	(ExprUnopBitNor* node)
{
}
void AstToDotConverter
	::visitExprUnopBitAnd_build_node_vec
	(ExprUnopBitAnd* node)
{
}
void AstToDotConverter
	::visitExprUnopBitAnd_print
	(ExprUnopBitAnd* node)
{
}
void AstToDotConverter
	::visitExprUnopBitNand_build_node_vec
	(ExprUnopBitNand* node)
{
}
void AstToDotConverter
	::visitExprUnopBitNand_print
	(ExprUnopBitNand* node)
{
}
void AstToDotConverter
	::visitExprUnopBitXor_build_node_vec
	(ExprUnopBitXor* node)
{
}
void AstToDotConverter
	::visitExprUnopBitXor_print
	(ExprUnopBitXor* node)
{
}
void AstToDotConverter
	::visitExprUnopBitXnor_build_node_vec
	(ExprUnopBitXnor* node)
{
}
void AstToDotConverter
	::visitExprUnopBitXnor_print
	(ExprUnopBitXnor* node)
{
}

void AstToDotConverter
	::visitExprLiteral_build_node_vec
	(ExprLiteral* node)
{
}
void AstToDotConverter
	::visitExprLiteral_print
	(ExprLiteral* node)
{
}
void AstToDotConverter
	::visitExprSized_build_node_vec
	(ExprSized* node)
{
}
void AstToDotConverter
	::visitExprSized_print
	(ExprSized* node)
{
}

void AstToDotConverter
	::visitExprRange_build_node_vec
	(ExprRange* node)
{
}
void AstToDotConverter
	::visitExprRange_print
	(ExprRange* node)
{
}

void AstToDotConverter
	::visitExprCat_build_node_vec
	(ExprCat* node)
{
}
void AstToDotConverter
	::visitExprCat_print
	(ExprCat* node)
{
}
void AstToDotConverter
	::visitExprRepl_build_node_vec
	(ExprRepl* node)
{
}
void AstToDotConverter
	::visitExprRepl_print
	(ExprRepl* node)
{
}

void AstToDotConverter
	::visitExprDollarSigned_build_node_vec
	(ExprDollarSigned* node)
{
}
void AstToDotConverter
	::visitExprDollarSigned_print
	(ExprDollarSigned* node)
{
}
void AstToDotConverter
	::visitExprDollarUnsigned_build_node_vec
	(ExprDollarUnsigned* node)
{
}
void AstToDotConverter
	::visitExprDollarUnsigned_print
	(ExprDollarUnsigned* node)
{
}
void AstToDotConverter
	::visitExprDollarClog2_build_node_vec
	(ExprDollarClog2* node)
{
}
void AstToDotConverter
	::visitExprDollarClog2_print
	(ExprDollarClog2* node)
{
}
void AstToDotConverter
	::visitExprDollarIsvtype_build_node_vec
	(ExprDollarIsvtype* node)
{
}
void AstToDotConverter
	::visitExprDollarIsvtype_print
	(ExprDollarIsvtype* node)
{
}
void AstToDotConverter
	::visitExprDollarPow_build_node_vec
	(ExprDollarPow* node)
{
}
void AstToDotConverter
	::visitExprDollarPow_print
	(ExprDollarPow* node)
{
}

void AstToDotConverter
	::visitExprIdentEtc_build_node_vec
	(ExprIdentEtc* node)
{
}
void AstToDotConverter
	::visitExprIdentEtc_print
	(ExprIdentEtc* node)
{
}
void AstToDotConverter
	::visitExprIdentEtc_FirstItem_build_node_vec
	(ExprIdentEtc_FirstItem* node)
{
}
void AstToDotConverter
	::visitExprIdentEtc_FirstItem_print
	(ExprIdentEtc_FirstItem* node)
{
}
void AstToDotConverter
	::visitExprIdentEtc_NonSelfItem_build_node_vec
	(ExprIdentEtc_NonSelfItem* node)
{
}
void AstToDotConverter
	::visitExprIdentEtc_NonSelfItem_print
	(ExprIdentEtc_NonSelfItem* node)
{
}
void AstToDotConverter
	::visitExprIdentEtc_ItemEnd_build_node_vec
	(ExprIdentEtc_ItemEnd* node)
{
}
void AstToDotConverter
	::visitExprIdentEtc_ItemEnd_print
	(ExprIdentEtc_ItemEnd* node)
{
}
void AstToDotConverter
	::visitExprIdentEtc_ItemEndIndex_build_node_vec
	(ExprIdentEtc_ItemEndIndex* node)
{
}
void AstToDotConverter
	::visitExprIdentEtc_ItemEndIndex_print
	(ExprIdentEtc_ItemEndIndex* node)
{
}

// Call a member function via `a plus b` instead of `a.plus(b)`
void AstToDotConverter
	::visitExprCallSubprog_PseudoOper_build_node_vec
	(ExprCallSubprog_PseudoOper* node)
{
}
void AstToDotConverter
	::visitExprCallSubprog_PseudoOper_print
	(ExprCallSubprog_PseudoOper* node)
{
}

} // namespace fling_hdl
