#include "ast_to_dot_converter_class.hpp"

namespace fling_hdl
{

using namespace ast;

void AstToDotConverter::convert(const string& dst_filename,
	const string& src_filename, Base* root)
{
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

	osprintout(_file,
		"}\n");
}
void AstToDotConverter::visitProgram(Program* node)
{
}

void AstToDotConverter::visitDeclPackage(DeclPackage* node)
{
}

void AstToDotConverter::visitParamOrArgList(ParamOrArgList* node)
{
}
void AstToDotConverter::visitDeclParamList_Item(DeclParamList_Item* node)
{
}
// This covers both regular argument lists and those for `proc`s
void AstToDotConverter::visitDeclArgList_Item(DeclArgList_Item* node)
{
}
void AstToDotConverter::visitInstParamList_Named_Item(InstParamList_Named_Item* node)
{
}
void AstToDotConverter::visitInstArgList_Named_Item(InstArgList_Named_Item* node)
{
}

void AstToDotConverter::visitDeclModule(DeclModule* node)
{
}

void AstToDotConverter::visitInstModule(InstModule* node)
{
}

void AstToDotConverter::visitGenIf(GenIf* node)
{
}
void AstToDotConverter::visitGenIf_Elif(GenIf_Elif* node)
{
}
void AstToDotConverter::visitGenIf_Else(GenIf_Else* node)
{
}

void AstToDotConverter::visitGenSwitch(GenSwitch* node)
{
}
void AstToDotConverter::visitGenSwitch_Case(GenSwitch_Case* node)
{
}
void AstToDotConverter::visitGenSwitch_Default(GenSwitch_Default* node)
{
}

void AstToDotConverter::visitGenFor(GenFor* node)
{
}

void AstToDotConverter::visitContAssign(ContAssign* node)
{
}

void AstToDotConverter::visitBehav(Behav* node)
{
}
void AstToDotConverter::visitBehav_SeqEdgeListItem(Behav_SeqEdgeListItem* node)
{
}
// This is used for behavioral blocks, functions, and tasks
void AstToDotConverter::visitBehav_Scope(Behav_Scope* node)
{
}

void AstToDotConverter::visitIf(If* node)
{
}
void AstToDotConverter::visitIf_Elif(If_Elif* node)
{
}
void AstToDotConverter::visitIf_Else(If_Else* node)
{
}

void AstToDotConverter::visitSwitch(Switch* node)
{
}
void AstToDotConverter::visitSwitchz(Switchz* node)
{
}
void AstToDotConverter::visitSwitchOrSwitchz_Case(SwitchOrSwitchz_Case* node)
{
}
void AstToDotConverter::visitSwitchOrSwitchz_Default(SwitchOrSwitchz_Default* node)
{
}

void AstToDotConverter::visitFor(For* node)
{
}
void AstToDotConverter::visitWhile(While* node)
{
}

void AstToDotConverter::visitNonBlkAssign(NonBlkAssign* node)
{
}
void AstToDotConverter::visitBlkAssign(BlkAssign* node)
{
}

void AstToDotConverter::visitDeclWire(DeclWire* node)
{
}
void AstToDotConverter::visitDeclVar(DeclVar* node)
{
}
void AstToDotConverter::visitDeclConst(DeclConst* node)
{
}

void AstToDotConverter::visitDeclEnum(DeclEnum* node)
{
}

void AstToDotConverter::visitDeclMixin(DeclMixin* node)
{
}
void AstToDotConverter::visitDeclClass(DeclClass* node)
{
}

void AstToDotConverter::visitDeclClass_DeclVar(DeclClass_DeclVar* node)
{
}
void AstToDotConverter::visitDeclClsOrMxn_DeclType(DeclClsOrMxn_DeclType* node)
{
}
void AstToDotConverter::visitDeclClsOrMxn_DeclAliasOrConst(DeclClsOrMxn_DeclAliasOrConst* node)
{
}

void AstToDotConverter::visitDeclClsOrMxn_DeclSubprogFullDefn(DeclClsOrMxn_DeclSubprogFullDefn* node)
{
}
void AstToDotConverter::visitDeclClsOrMxn_DeclSubprogAbstract(DeclClsOrMxn_DeclSubprogAbstract* node)
{
}

void AstToDotConverter::visitDeclFunc(DeclFunc* node)
{
}
void AstToDotConverter::visitDeclFunc_Header(DeclFunc_Header* node)
{
}
void AstToDotConverter::visitDeclFunc_Return(DeclFunc_Return* node)
{
}

void AstToDotConverter::visitDeclTask(DeclTask* node)
{
}
void AstToDotConverter::visitDeclTask_Header(DeclTask_Header* node)
{
}

void AstToDotConverter::visitDeclProc(DeclProc* node)
{
}
void AstToDotConverter::visitDeclProc_Header(DeclProc_Header* node)
{
}

void AstToDotConverter::visitDeclAlias_Value(DeclAlias_Value* node)
{
}
void AstToDotConverter::visitDeclAlias_Type(DeclAlias_Type* node)
{
}
void AstToDotConverter::visitDeclAlias_Module(DeclAlias_Module* node)
{
}

void AstToDotConverter::visitIdentList(IdentList* node)
{
}
void AstToDotConverter::visitScopedIdent(ScopedIdent* node)
{
}
void AstToDotConverter::visitImportList(ImportList* node)
{
}

void AstToDotConverter::visitTypenameOrModname_Special(TypenameOrModname_Special* node)
{
}
void AstToDotConverter::visitTypenameOrModname_Cstm(TypenameOrModname_Cstm* node)
{
}
void AstToDotConverter::visitTypenameOrModname_Typeof(TypenameOrModname_Typeof* node)
{
}
void AstToDotConverter::visitTypenameOrModname_Cstm_Item(TypenameOrModname_Cstm_Item* node)
{
}
void AstToDotConverter::visitTypenameOrModname_Builtin(TypenameOrModname_Builtin* node)
{
}

void AstToDotConverter::visitExprMux(ExprMux* node)
{
}

void AstToDotConverter::visitExprLogOr(ExprLogOr* node)
{
}
void AstToDotConverter::visitExprLogAnd(ExprLogAnd* node)
{
}

void AstToDotConverter::visitExprBinopBitOr(ExprBinopBitOr* node)
{
}
void AstToDotConverter::visitExprBinopBitNor(ExprBinopBitNor* node)
{
}
void AstToDotConverter::visitExprBinopBitAnd(ExprBinopBitAnd* node)
{
}
void AstToDotConverter::visitExprBinopBitNand(ExprBinopBitNand* node)
{
}
void AstToDotConverter::visitExprBinopBitXor(ExprBinopBitXor* node)
{
}
void AstToDotConverter::visitExprBinopBitXnor(ExprBinopBitXnor* node)
{
}

void AstToDotConverter::visitExprCmpEq(ExprCmpEq* node)
{
}
void AstToDotConverter::visitExprCmpNe(ExprCmpNe* node)
{
}
void AstToDotConverter::visitExprCaseCmpEq(ExprCaseCmpEq* node)
{
}
void AstToDotConverter::visitExprCaseCmpNe(ExprCaseCmpNe* node)
{
}
void AstToDotConverter::visitExprCmpLt(ExprCmpLt* node)
{
}
void AstToDotConverter::visitExprCmpLe(ExprCmpLe* node)
{
}
void AstToDotConverter::visitExprCmpGt(ExprCmpGt* node)
{
}
void AstToDotConverter::visitExprCmpGe(ExprCmpGe* node)
{
}

void AstToDotConverter::visitExprBitLsl(ExprBitLsl* node)
{
}
void AstToDotConverter::visitExprBitLsr(ExprBitLsr* node)
{
}
void AstToDotConverter::visitExprBitAsr(ExprBitAsr* node)
{
}

void AstToDotConverter::visitExprBinopPlus(ExprBinopPlus* node)
{
}
void AstToDotConverter::visitExprBinopMinus(ExprBinopMinus* node)
{
}

void AstToDotConverter::visitExprMul(ExprMul* node)
{
}
void AstToDotConverter::visitExprDiv(ExprDiv* node)
{
}
void AstToDotConverter::visitExprMod(ExprMod* node)
{
}

void AstToDotConverter::visitExprUnopPlus(ExprUnopPlus* node)
{
}
void AstToDotConverter::visitExprUnopMinus(ExprUnopMinus* node)
{
}
void AstToDotConverter::visitExprLogNot(ExprLogNot* node)
{
}
void AstToDotConverter::visitExprBitNot(ExprBitNot* node)
{
}

void AstToDotConverter::visitExprUnopBitOr(ExprUnopBitOr* node)
{
}
void AstToDotConverter::visitExprUnopBitNor(ExprUnopBitNor* node)
{
}
void AstToDotConverter::visitExprUnopBitAnd(ExprUnopBitAnd* node)
{
}
void AstToDotConverter::visitExprUnopBitNand(ExprUnopBitNand* node)
{
}
void AstToDotConverter::visitExprUnopBitXor(ExprUnopBitXor* node)
{
}
void AstToDotConverter::visitExprUnopBitXnor(ExprUnopBitXnor* node)
{
}

void AstToDotConverter::visitExprLiteral(ExprLiteral* node)
{
}
void AstToDotConverter::visitExprSized(ExprSized* node)
{
}

void AstToDotConverter::visitExprRange(ExprRange* node)
{
}

void AstToDotConverter::visitExprCat(ExprCat* node)
{
}
void AstToDotConverter::visitExprRepl(ExprRepl* node)
{
}

void AstToDotConverter::visitExprDollarSigned(ExprDollarSigned* node)
{
}
void AstToDotConverter::visitExprDollarUnsigned(ExprDollarUnsigned* node)
{
}
void AstToDotConverter::visitExprDollarClog2(ExprDollarClog2* node)
{
}
void AstToDotConverter::visitExprDollarIsvtype(ExprDollarIsvtype* node)
{
}
void AstToDotConverter::visitExprDollarPow(ExprDollarPow* node)
{
}

void AstToDotConverter::visitExprIdentEtc(ExprIdentEtc* node)
{
}
void AstToDotConverter::visitExprIdentEtc_FirstItem(ExprIdentEtc_FirstItem* node)
{
}
void AstToDotConverter::visitExprIdentEtc_NonSelfItem(ExprIdentEtc_NonSelfItem* node)
{
}
void AstToDotConverter::visitExprIdentEtc_ItemEnd(ExprIdentEtc_ItemEnd* node)
{
}
void AstToDotConverter::visitExprIdentEtc_ItemEndIndex(ExprIdentEtc_ItemEndIndex* node)
{
}

// Call a member function via `a plus b` instead of `a.plus(b)`
void AstToDotConverter::visitExprCallSubprog_PseudoOper(ExprCallSubprog_PseudoOper* node)
{
}

} // namespace fling_hdl
