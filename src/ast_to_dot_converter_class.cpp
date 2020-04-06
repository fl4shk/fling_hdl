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


void AstToDotConverter::_build_node_vec
	(Program* n)
{
}
void AstToDotConverter::_print
	(Program* n)
{
}

void AstToDotConverter::_build_node_vec
	(DeclPackage* n)
{
}
void AstToDotConverter::_print
	(DeclPackage* n)
{
}

void AstToDotConverter::_build_node_vec
	(ParamOrArgList* n)
{
}
void AstToDotConverter::_print
	(ParamOrArgList* n)
{
}
void AstToDotConverter::_build_node_vec
	(DeclParamList_Item* n)
{
}
void AstToDotConverter::_print
	(DeclParamList_Item* n)
{
}
// This covers both regular argument lists and those for `proc`s
void AstToDotConverter::_build_node_vec
	(DeclArgList_Item* n)
{
}
void AstToDotConverter::_print
	(DeclArgList_Item* n)
{
}
void AstToDotConverter::_build_node_vec
	(InstParamList_Named_Item* n)
{
}
void AstToDotConverter::_print
	(InstParamList_Named_Item* n)
{
}
void AstToDotConverter::_build_node_vec
	(InstArgList_Named_Item* n)
{
}
void AstToDotConverter::_print
	(InstArgList_Named_Item* n)
{
}

void AstToDotConverter::_build_node_vec
	(DeclModule* n)
{
}
void AstToDotConverter::_print
	(DeclModule* n)
{
}

void AstToDotConverter::_build_node_vec
	(InstModule* n)
{
}
void AstToDotConverter::_print
	(InstModule* n)
{
}

void AstToDotConverter::_build_node_vec
	(GenIf* n)
{
}
void AstToDotConverter::_print
	(GenIf* n)
{
}
void AstToDotConverter::_build_node_vec
	(GenIf_Elif* n)
{
}
void AstToDotConverter::_print
	(GenIf_Elif* n)
{
}
void AstToDotConverter::_build_node_vec
	(GenIf_Else* n)
{
}
void AstToDotConverter::_print
	(GenIf_Else* n)
{
}

void AstToDotConverter::_build_node_vec
	(GenSwitch* n)
{
}
void AstToDotConverter::_print
	(GenSwitch* n)
{
}
void AstToDotConverter::_build_node_vec
	(GenSwitch_Case* n)
{
}
void AstToDotConverter::_print
	(GenSwitch_Case* n)
{
}
void AstToDotConverter::_build_node_vec
	(GenSwitch_Default* n)
{
}
void AstToDotConverter::_print
	(GenSwitch_Default* n)
{
}

void AstToDotConverter::_build_node_vec
	(GenFor* n)
{
}
void AstToDotConverter::_print
	(GenFor* n)
{
}

void AstToDotConverter::_build_node_vec
	(ContAssign* n)
{
}
void AstToDotConverter::_print
	(ContAssign* n)
{
}

void AstToDotConverter::_build_node_vec
	(Behav* n)
{
}
void AstToDotConverter::_print
	(Behav* n)
{
}
void AstToDotConverter::_build_node_vec
	(Behav_SeqEdgeListItem* n)
{
}
void AstToDotConverter::_print
	(Behav_SeqEdgeListItem* n)
{
}
// This is used for behavioral blocks, functions, and tasks
void AstToDotConverter::_build_node_vec
	(Behav_Scope* n)
{
}
void AstToDotConverter::_print
	(Behav_Scope* n)
{
}

void AstToDotConverter::_build_node_vec
	(If* n)
{
}
void AstToDotConverter::_print
	(If* n)
{
}
void AstToDotConverter::_build_node_vec
	(If_Elif* n)
{
}
void AstToDotConverter::_print
	(If_Elif* n)
{
}
void AstToDotConverter::_build_node_vec
	(If_Else* n)
{
}
void AstToDotConverter::_print
	(If_Else* n)
{
}

void AstToDotConverter::_build_node_vec
	(Switch* n)
{
}
void AstToDotConverter::_print
	(Switch* n)
{
}
void AstToDotConverter::_build_node_vec
	(Switchz* n)
{
}
void AstToDotConverter::_print
	(Switchz* n)
{
}
void AstToDotConverter::_build_node_vec
	(SwitchOrSwitchz_Case* n)
{
}
void AstToDotConverter::_print
	(SwitchOrSwitchz_Case* n)
{
}
void AstToDotConverter::_build_node_vec
	(SwitchOrSwitchz_Default* n)
{
}
void AstToDotConverter::_print
	(SwitchOrSwitchz_Default* n)
{
}

void AstToDotConverter::_build_node_vec
	(For* n)
{
}
void AstToDotConverter::_print
	(For* n)
{
}
void AstToDotConverter::_build_node_vec
	(While* n)
{
}
void AstToDotConverter::_print
	(While* n)
{
}

void AstToDotConverter::_build_node_vec
	(NonBlkAssign* n)
{
}
void AstToDotConverter::_print
	(NonBlkAssign* n)
{
}
void AstToDotConverter::_build_node_vec
	(BlkAssign* n)
{
}
void AstToDotConverter::_print
	(BlkAssign* n)
{
}

void AstToDotConverter::_build_node_vec
	(DeclWire* n)
{
}
void AstToDotConverter::_print
	(DeclWire* n)
{
}
void AstToDotConverter::_build_node_vec
	(DeclVar* n)
{
}
void AstToDotConverter::_print
	(DeclVar* n)
{
}
void AstToDotConverter::_build_node_vec
	(DeclConst* n)
{
}
void AstToDotConverter::_print
	(DeclConst* n)
{
}

void AstToDotConverter::_build_node_vec
	(DeclEnum* n)
{
}
void AstToDotConverter::_print
	(DeclEnum* n)
{
}

void AstToDotConverter::_build_node_vec
	(DeclMixin* n)
{
}
void AstToDotConverter::_print
	(DeclMixin* n)
{
}
void AstToDotConverter::_build_node_vec
	(DeclClass* n)
{
}
void AstToDotConverter::_print
	(DeclClass* n)
{
}

void AstToDotConverter::_build_node_vec
	(DeclClass_DeclVar* n)
{
}
void AstToDotConverter::_print
	(DeclClass_DeclVar* n)
{
}
void AstToDotConverter::_build_node_vec
	(DeclClsOrMxn_DeclType* n)
{
}
void AstToDotConverter::_print
	(DeclClsOrMxn_DeclType* n)
{
}
void AstToDotConverter::_build_node_vec
	(DeclClsOrMxn_DeclAliasOrConst* n)
{
}
void AstToDotConverter::_print
	(DeclClsOrMxn_DeclAliasOrConst* n)
{
}

void AstToDotConverter::_build_node_vec
	(DeclClsOrMxn_DeclSubprogFullDefn* n)
{
}
void AstToDotConverter::_print
	(DeclClsOrMxn_DeclSubprogFullDefn* n)
{
}
void AstToDotConverter::_build_node_vec
	(DeclClsOrMxn_DeclSubprogAbstract* n)
{
}
void AstToDotConverter::_print
	(DeclClsOrMxn_DeclSubprogAbstract* n)
{
}

void AstToDotConverter::_build_node_vec
	(DeclFunc* n)
{
}
void AstToDotConverter::_print
	(DeclFunc* n)
{
}
void AstToDotConverter::_build_node_vec
	(DeclFunc_Header* n)
{
}
void AstToDotConverter::_print
	(DeclFunc_Header* n)
{
}
void AstToDotConverter::_build_node_vec
	(DeclFunc_Return* n)
{
}
void AstToDotConverter::_print
	(DeclFunc_Return* n)
{
}

void AstToDotConverter::_build_node_vec
	(DeclTask* n)
{
}
void AstToDotConverter::_print
	(DeclTask* n)
{
}
void AstToDotConverter::_build_node_vec
	(DeclTask_Header* n)
{
}
void AstToDotConverter::_print
	(DeclTask_Header* n)
{
}

void AstToDotConverter::_build_node_vec
	(DeclProc* n)
{
}
void AstToDotConverter::_print
	(DeclProc* n)
{
}
void AstToDotConverter::_build_node_vec
	(DeclProc_Header* n)
{
}
void AstToDotConverter::_print
	(DeclProc_Header* n)
{
}

void AstToDotConverter::_build_node_vec
	(DeclAlias_Value* n)
{
}
void AstToDotConverter::_print
	(DeclAlias_Value* n)
{
}
void AstToDotConverter::_build_node_vec
	(DeclAlias_Type* n)
{
}
void AstToDotConverter::_print
	(DeclAlias_Type* n)
{
}
void AstToDotConverter::_build_node_vec
	(DeclAlias_Module* n)
{
}
void AstToDotConverter::_print
	(DeclAlias_Module* n)
{
}

void AstToDotConverter::_build_node_vec
	(IdentList* n)
{
}
void AstToDotConverter::_print
	(IdentList* n)
{
}
void AstToDotConverter::_build_node_vec
	(ScopedIdent* n)
{
}
void AstToDotConverter::_print
	(ScopedIdent* n)
{
}
void AstToDotConverter::_build_node_vec
	(ImportList* n)
{
}
void AstToDotConverter::_print
	(ImportList* n)
{
}

void AstToDotConverter::_build_node_vec
	(TypenameOrModname_Special* n)
{
}
void AstToDotConverter::_print
	(TypenameOrModname_Special* n)
{
}
void AstToDotConverter::_build_node_vec
	(TypenameOrModname_Cstm* n)
{
}
void AstToDotConverter::_print
	(TypenameOrModname_Cstm* n)
{
}
void AstToDotConverter::_build_node_vec
	(TypenameOrModname_Typeof* n)
{
}
void AstToDotConverter::_print
	(TypenameOrModname_Typeof* n)
{
}
void AstToDotConverter::_build_node_vec
	(TypenameOrModname_Cstm_Item* n)
{
}
void AstToDotConverter::_print
	(TypenameOrModname_Cstm_Item* n)
{
}
void AstToDotConverter::_build_node_vec
	(TypenameOrModname_Builtin* n)
{
}
void AstToDotConverter::_print
	(TypenameOrModname_Builtin* n)
{
}

void AstToDotConverter::_build_node_vec
	(ExprMux* n)
{
}
void AstToDotConverter::_print
	(ExprMux* n)
{
}

void AstToDotConverter::_build_node_vec
	(ExprLogOr* n)
{
}
void AstToDotConverter::_print
	(ExprLogOr* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprLogAnd* n)
{
}
void AstToDotConverter::_print
	(ExprLogAnd* n)
{
}

void AstToDotConverter::_build_node_vec
	(ExprBinopBitOr* n)
{
}
void AstToDotConverter::_print
	(ExprBinopBitOr* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprBinopBitNor* n)
{
}
void AstToDotConverter::_print
	(ExprBinopBitNor* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprBinopBitAnd* n)
{
}
void AstToDotConverter::_print
	(ExprBinopBitAnd* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprBinopBitNand* n)
{
}
void AstToDotConverter::_print
	(ExprBinopBitNand* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprBinopBitXor* n)
{
}
void AstToDotConverter::_print
	(ExprBinopBitXor* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprBinopBitXnor* n)
{
}
void AstToDotConverter::_print
	(ExprBinopBitXnor* n)
{
}

void AstToDotConverter::_build_node_vec
	(ExprCmpEq* n)
{
}
void AstToDotConverter::_print
	(ExprCmpEq* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprCmpNe* n)
{
}
void AstToDotConverter::_print
	(ExprCmpNe* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprCaseCmpEq* n)
{
}
void AstToDotConverter::_print
	(ExprCaseCmpEq* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprCaseCmpNe* n)
{
}
void AstToDotConverter::_print
	(ExprCaseCmpNe* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprCmpLt* n)
{
}
void AstToDotConverter::_print
	(ExprCmpLt* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprCmpLe* n)
{
}
void AstToDotConverter::_print
	(ExprCmpLe* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprCmpGt* n)
{
}
void AstToDotConverter::_print
	(ExprCmpGt* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprCmpGe* n)
{
}
void AstToDotConverter::_print
	(ExprCmpGe* n)
{
}

void AstToDotConverter::_build_node_vec
	(ExprBitLsl* n)
{
}
void AstToDotConverter::_print
	(ExprBitLsl* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprBitLsr* n)
{
}
void AstToDotConverter::_print
	(ExprBitLsr* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprBitAsr* n)
{
}
void AstToDotConverter::_print
	(ExprBitAsr* n)
{
}

void AstToDotConverter::_build_node_vec
	(ExprBinopPlus* n)
{
}
void AstToDotConverter::_print
	(ExprBinopPlus* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprBinopMinus* n)
{
}
void AstToDotConverter::_print
	(ExprBinopMinus* n)
{
}

void AstToDotConverter::_build_node_vec
	(ExprMul* n)
{
}
void AstToDotConverter::_print
	(ExprMul* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprDiv* n)
{
}
void AstToDotConverter::_print
	(ExprDiv* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprMod* n)
{
}
void AstToDotConverter::_print
	(ExprMod* n)
{
}

void AstToDotConverter::_build_node_vec
	(ExprUnopPlus* n)
{
}
void AstToDotConverter::_print
	(ExprUnopPlus* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprUnopMinus* n)
{
}
void AstToDotConverter::_print
	(ExprUnopMinus* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprLogNot* n)
{
}
void AstToDotConverter::_print
	(ExprLogNot* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprBitNot* n)
{
}
void AstToDotConverter::_print
	(ExprBitNot* n)
{
}

void AstToDotConverter::_build_node_vec
	(ExprUnopBitOr* n)
{
}
void AstToDotConverter::_print
	(ExprUnopBitOr* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprUnopBitNor* n)
{
}
void AstToDotConverter::_print
	(ExprUnopBitNor* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprUnopBitAnd* n)
{
}
void AstToDotConverter::_print
	(ExprUnopBitAnd* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprUnopBitNand* n)
{
}
void AstToDotConverter::_print
	(ExprUnopBitNand* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprUnopBitXor* n)
{
}
void AstToDotConverter::_print
	(ExprUnopBitXor* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprUnopBitXnor* n)
{
}
void AstToDotConverter::_print
	(ExprUnopBitXnor* n)
{
}

void AstToDotConverter::_build_node_vec
	(ExprLiteral* n)
{
}
void AstToDotConverter::_print
	(ExprLiteral* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprSized* n)
{
}
void AstToDotConverter::_print
	(ExprSized* n)
{
}

void AstToDotConverter::_build_node_vec
	(ExprRange* n)
{
}
void AstToDotConverter::_print
	(ExprRange* n)
{
}

void AstToDotConverter::_build_node_vec
	(ExprCat* n)
{
}
void AstToDotConverter::_print
	(ExprCat* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprRepl* n)
{
}
void AstToDotConverter::_print
	(ExprRepl* n)
{
}

void AstToDotConverter::_build_node_vec
	(ExprDollarSigned* n)
{
}
void AstToDotConverter::_print
	(ExprDollarSigned* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprDollarUnsigned* n)
{
}
void AstToDotConverter::_print
	(ExprDollarUnsigned* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprDollarClog2* n)
{
}
void AstToDotConverter::_print
	(ExprDollarClog2* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprDollarIsvtype* n)
{
}
void AstToDotConverter::_print
	(ExprDollarIsvtype* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprDollarPow* n)
{
}
void AstToDotConverter::_print
	(ExprDollarPow* n)
{
}

void AstToDotConverter::_build_node_vec
	(ExprIdentEtc* n)
{
}
void AstToDotConverter::_print
	(ExprIdentEtc* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprIdentEtc_FirstItem* n)
{
}
void AstToDotConverter::_print
	(ExprIdentEtc_FirstItem* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprIdentEtc_NonSelfItem* n)
{
}
void AstToDotConverter::_print
	(ExprIdentEtc_NonSelfItem* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprIdentEtc_ItemEnd* n)
{
}
void AstToDotConverter::_print
	(ExprIdentEtc_ItemEnd* n)
{
}
void AstToDotConverter::_build_node_vec
	(ExprIdentEtc_ItemEndIndex* n)
{
}
void AstToDotConverter::_print
	(ExprIdentEtc_ItemEndIndex* n)
{
}

// Call a member function via `a plus b` instead of `a.plus(b)`
void AstToDotConverter::_build_node_vec
	(ExprCallSubprog_PseudoOper* n)
{
}
void AstToDotConverter::_print
	(ExprCallSubprog_PseudoOper* n)
{
}

} // namespace fling_hdl
