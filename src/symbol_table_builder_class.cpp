#include "symbol_table_builder_class.hpp"

namespace fling_hdl
{

using namespace ast;

//--------
SymbolTableBuilder::SymbolTableBuilder(AstEtcMapPair* s_ast_etc_map_pair)
	: MultiPassAstVisitor(s_ast_etc_map_pair)
{
}
SymbolTableBuilder::~SymbolTableBuilder()
{
}

bool SymbolTableBuilder::should_perf_ast_etc_map_move() const
{
	return false;
}
//--------

//--------
#define blank(type) \
	void SymbolTableBuilder::_build_sym_table \
		(type* n) \
	{ \
	}

blank(Program)

void SymbolTableBuilder::_build_sym_table
	(DeclPackage* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(ParamOrArgList* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(DeclParamList_Item* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(DeclArgList_Item* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(InstParamOrArgList_PosItemParpk* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(InstParamOrArgList_PosItemUnparpk* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(InstParamList_NamedItem* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(InstArgList_NamedItem* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(DeclModnm* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(InstModule* n)
{
}
blank(GenIf)
blank(GenIf_Elif)
blank(GenIf_Else)
blank(GenSwitch)
blank(GenSwitch_Case)
blank(GenSwitch_Default)
void SymbolTableBuilder::_build_sym_table
	(GenFor* n)
{
}
blank(ContAssign)
blank(Behav)
blank(Behav_SeqEdgeListItem)
blank(Behav_Scope)
blank(If)
blank(If_Elif)
blank(If_Else)
blank(Switch)
blank(Switchz)
blank(SwitchOrSwitchz_Case)
blank(SwitchOrSwitchz_Default)
blank(For)
blank(While)
blank(NonBlkAssign)
blank(BlkAssign)
void SymbolTableBuilder::_build_sym_table
	(DeclWire* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(DeclVar* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(DeclConst* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(DeclEnum* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(DeclMixin* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(DeclClass* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(DeclClass_DeclVar* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(DeclClsOrMxn_DeclType* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(DeclClsOrMxn_DeclAliasOrConst* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(DeclClsOrMxn_DeclSubprogFullDefn* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(DeclClsOrMxn_DeclSubprogAbstract* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(DeclFunc* n)
{
}
blank(DeclFunc_Header)
blank(DeclFunc_Return)
blank(DeclFunc_Defer)
void SymbolTableBuilder::_build_sym_table
	(DeclTask* n)
{
}
blank(DeclTask_Header)
void SymbolTableBuilder::_build_sym_table
	(DeclProc* n)
{
}
blank(DeclProc_Header)
void SymbolTableBuilder::_build_sym_table
	(DeclAlias_Value* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(DeclAlias_Type* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(DeclAlias_Modnm* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(IdentList* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(ScopedIdent* n)
{
}
void SymbolTableBuilder::_build_sym_table
	(ImportList* n)
{
}
blank(ImportList_Item)
blank(TypenameOrModname_Special)
blank(TypenameOrModname_Cstm)
blank(TypenameOrModname_Typeof)
blank(TypenameOrModname_Cstm_Item)
blank(TypenameOrModname_Builtin)
blank(ExprMux)
blank(ExprLogOr)
blank(ExprLogAnd)
blank(ExprBinopBitOr)
blank(ExprBinopBitNor)
blank(ExprBinopBitAnd)
blank(ExprBinopBitNand)
blank(ExprBinopBitXor)
blank(ExprBinopBitXnor)
blank(ExprCmpEq)
blank(ExprCmpNe)
blank(ExprCaseCmpEq)
blank(ExprCaseCmpNe)
blank(ExprCmpLt)
blank(ExprCmpLe)
blank(ExprCmpGt)
blank(ExprCmpGe)
blank(ExprBitLsl)
blank(ExprBitLsr)
blank(ExprBitAsr)
blank(ExprBinopPlus)
blank(ExprBinopMinus)
blank(ExprMul)
blank(ExprDiv)
blank(ExprMod)
blank(ExprUnopPlus)
blank(ExprUnopMinus)
blank(ExprLogNot)
blank(ExprBitNot)
blank(ExprUnopBitOr)
blank(ExprUnopBitNor)
blank(ExprUnopBitAnd)
blank(ExprUnopBitNand)
blank(ExprUnopBitXor)
blank(ExprUnopBitXnor)
blank(ExprLiteral)
blank(ExprSized)
blank(ExprRange)
blank(ExprCat)
blank(ExprRepl)
blank(ExprDollarSigned)
blank(ExprDollarUnsigned)
blank(ExprDollarClog2)
blank(ExprDollarIsvtype)
blank(ExprDollarPow)
blank(ExprIdentEtc)
blank(ExprIdentEtc_FirstItem)
blank(ExprIdentEtc_NonSelfItem)
blank(ExprIdentEtc_ItemEnd)
blank(ExprIdentEtc_ItemEndIndex)
blank(ExprCast)
blank(ExprCallSubprog_PseudoOper)
//--------
} // namespace fling_hdl
