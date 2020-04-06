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

#define AL(p, list) \
	for (const auto& p: list) \
	{ \
		p->accept(this); \
	}

void AstToDotConverter
	::_build_node_vec_Program
	(Program* n)
{
}
void AstToDotConverter
	::_print_Program
	(Program* n)
{
}
void AstToDotConverter
	::_accept_children_Program
	(Program* n)
{
}

void AstToDotConverter
	::_build_node_vec_DeclPackage
	(DeclPackage* n)
{
}
void AstToDotConverter
	::_print_DeclPackage
	(DeclPackage* n)
{
}
void AstToDotConverter
	::_accept_children_DeclPackage
	(DeclPackage* n)
{
}

void AstToDotConverter
	::_build_node_vec_ParamOrArgList
	(ParamOrArgList* n)
{
}
void AstToDotConverter
	::_print_ParamOrArgList
	(ParamOrArgList* n)
{
}
void AstToDotConverter
	::_accept_children_ParamOrArgList
	(ParamOrArgList* n)
{
}
void AstToDotConverter
	::_build_node_vec_DeclParamList_Item
	(DeclParamList_Item* n)
{
}
void AstToDotConverter
	::_print_DeclParamList_Item
	(DeclParamList_Item* n)
{
}
void AstToDotConverter
	::_accept_children_DeclParamList_Item
	(DeclParamList_Item* n)
{
}
// This covers both regular argument lists and those for `proc`s
void AstToDotConverter
	::_build_node_vec_DeclArgList_Item
	(DeclArgList_Item* n)
{
}
void AstToDotConverter
	::_print_DeclArgList_Item
	(DeclArgList_Item* n)
{
}
void AstToDotConverter
	::_accept_children_DeclArgList_Item
	(DeclArgList_Item* n)
{
}
void AstToDotConverter
	::_build_node_vec_InstParamList_Named_Item
	(InstParamList_Named_Item* n)
{
}
void AstToDotConverter
	::_print_InstParamList_Named_Item
	(InstParamList_Named_Item* n)
{
}
void AstToDotConverter
	::_accept_children_InstParamList_Named_Item
	(InstParamList_Named_Item* n)
{
}
void AstToDotConverter
	::_build_node_vec_InstArgList_Named_Item
	(InstArgList_Named_Item* n)
{
}
void AstToDotConverter
	::_print_InstArgList_Named_Item
	(InstArgList_Named_Item* n)
{
}
void AstToDotConverter
	::_accept_children_InstArgList_Named_Item
	(InstArgList_Named_Item* n)
{
}

void AstToDotConverter
	::_build_node_vec_DeclModule
	(DeclModule* n)
{
}
void AstToDotConverter
	::_print_DeclModule
	(DeclModule* n)
{
}
void AstToDotConverter
	::_accept_children_DeclModule
	(DeclModule* n)
{
}

void AstToDotConverter
	::_build_node_vec_InstModule
	(InstModule* n)
{
}
void AstToDotConverter
	::_print_InstModule
	(InstModule* n)
{
}
void AstToDotConverter
	::_accept_children_InstModule
	(InstModule* n)
{
}

void AstToDotConverter
	::_build_node_vec_GenIf
	(GenIf* n)
{
}
void AstToDotConverter
	::_print_GenIf
	(GenIf* n)
{
}
void AstToDotConverter
	::_accept_children_GenIf
	(GenIf* n)
{
}
void AstToDotConverter
	::_build_node_vec_GenIf_Elif
	(GenIf_Elif* n)
{
}
void AstToDotConverter
	::_print_GenIf_Elif
	(GenIf_Elif* n)
{
}
void AstToDotConverter
	::_accept_children_GenIf_Elif
	(GenIf_Elif* n)
{
}
void AstToDotConverter
	::_build_node_vec_GenIf_Else
	(GenIf_Else* n)
{
}
void AstToDotConverter
	::_print_GenIf_Else
	(GenIf_Else* n)
{
}
void AstToDotConverter
	::_accept_children_GenIf_Else
	(GenIf_Else* n)
{
}

void AstToDotConverter
	::_build_node_vec_GenSwitch
	(GenSwitch* n)
{
}
void AstToDotConverter
	::_print_GenSwitch
	(GenSwitch* n)
{
}
void AstToDotConverter
	::_accept_children_GenSwitch
	(GenSwitch* n)
{
}
void AstToDotConverter
	::_build_node_vec_GenSwitch_Case
	(GenSwitch_Case* n)
{
}
void AstToDotConverter
	::_print_GenSwitch_Case
	(GenSwitch_Case* n)
{
}
void AstToDotConverter
	::_accept_children_GenSwitch_Case
	(GenSwitch_Case* n)
{
}
void AstToDotConverter
	::_build_node_vec_GenSwitch_Default
	(GenSwitch_Default* n)
{
}
void AstToDotConverter
	::_print_GenSwitch_Default
	(GenSwitch_Default* n)
{
}
void AstToDotConverter
	::_accept_children_GenSwitch_Default
	(GenSwitch_Default* n)
{
}

void AstToDotConverter
	::_build_node_vec_GenFor
	(GenFor* n)
{
}
void AstToDotConverter
	::_print_GenFor
	(GenFor* n)
{
}
void AstToDotConverter
	::_accept_children_GenFor
	(GenFor* n)
{
}

void AstToDotConverter
	::_build_node_vec_ContAssign
	(ContAssign* n)
{
}
void AstToDotConverter
	::_print_ContAssign
	(ContAssign* n)
{
}
void AstToDotConverter
	::_accept_children_ContAssign
	(ContAssign* n)
{
}

void AstToDotConverter
	::_build_node_vec_Behav
	(Behav* n)
{
}
void AstToDotConverter
	::_print_Behav
	(Behav* n)
{
}
void AstToDotConverter
	::_accept_children_Behav
	(Behav* n)
{
}
void AstToDotConverter
	::_build_node_vec_Behav_SeqEdgeListItem
	(Behav_SeqEdgeListItem* n)
{
}
void AstToDotConverter
	::_print_Behav_SeqEdgeListItem
	(Behav_SeqEdgeListItem* n)
{
}
void AstToDotConverter
	::_accept_children_Behav_SeqEdgeListItem
	(Behav_SeqEdgeListItem* n)
{
}
// This is used for behavioral blocks, functions, and tasks
void AstToDotConverter
	::_build_node_vec_Behav_Scope
	(Behav_Scope* n)
{
}
void AstToDotConverter
	::_print_Behav_Scope
	(Behav_Scope* n)
{
}
void AstToDotConverter
	::_accept_children_Behav_Scope
	(Behav_Scope* n)
{
}

void AstToDotConverter
	::_build_node_vec_If
	(If* n)
{
}
void AstToDotConverter
	::_print_If
	(If* n)
{
}
void AstToDotConverter
	::_accept_children_If
	(If* n)
{
}
void AstToDotConverter
	::_build_node_vec_If_Elif
	(If_Elif* n)
{
}
void AstToDotConverter
	::_print_If_Elif
	(If_Elif* n)
{
}
void AstToDotConverter
	::_accept_children_If_Elif
	(If_Elif* n)
{
}
void AstToDotConverter
	::_build_node_vec_If_Else
	(If_Else* n)
{
}
void AstToDotConverter
	::_print_If_Else
	(If_Else* n)
{
}
void AstToDotConverter
	::_accept_children_If_Else
	(If_Else* n)
{
}

void AstToDotConverter
	::_build_node_vec_Switch
	(Switch* n)
{
}
void AstToDotConverter
	::_print_Switch
	(Switch* n)
{
}
void AstToDotConverter
	::_accept_children_Switch
	(Switch* n)
{
}
void AstToDotConverter
	::_build_node_vec_Switchz
	(Switchz* n)
{
}
void AstToDotConverter
	::_print_Switchz
	(Switchz* n)
{
}
void AstToDotConverter
	::_accept_children_Switchz
	(Switchz* n)
{
}
void AstToDotConverter
	::_build_node_vec_SwitchOrSwitchz_Case
	(SwitchOrSwitchz_Case* n)
{
}
void AstToDotConverter
	::_print_SwitchOrSwitchz_Case
	(SwitchOrSwitchz_Case* n)
{
}
void AstToDotConverter
	::_accept_children_SwitchOrSwitchz_Case
	(SwitchOrSwitchz_Case* n)
{
}
void AstToDotConverter
	::_build_node_vec_SwitchOrSwitchz_Default
	(SwitchOrSwitchz_Default* n)
{
}
void AstToDotConverter
	::_print_SwitchOrSwitchz_Default
	(SwitchOrSwitchz_Default* n)
{
}
void AstToDotConverter
	::_accept_children_SwitchOrSwitchz_Default
	(SwitchOrSwitchz_Default* n)
{
}

void AstToDotConverter
	::_build_node_vec_For
	(For* n)
{
}
void AstToDotConverter
	::_print_For
	(For* n)
{
}
void AstToDotConverter
	::_accept_children_For
	(For* n)
{
}
void AstToDotConverter
	::_build_node_vec_While
	(While* n)
{
}
void AstToDotConverter
	::_print_While
	(While* n)
{
}
void AstToDotConverter
	::_accept_children_While
	(While* n)
{
}

void AstToDotConverter
	::_build_node_vec_NonBlkAssign
	(NonBlkAssign* n)
{
}
void AstToDotConverter
	::_print_NonBlkAssign
	(NonBlkAssign* n)
{
}
void AstToDotConverter
	::_accept_children_NonBlkAssign
	(NonBlkAssign* n)
{
}
void AstToDotConverter
	::_build_node_vec_BlkAssign
	(BlkAssign* n)
{
}
void AstToDotConverter
	::_print_BlkAssign
	(BlkAssign* n)
{
}
void AstToDotConverter
	::_accept_children_BlkAssign
	(BlkAssign* n)
{
}

void AstToDotConverter
	::_build_node_vec_DeclWire
	(DeclWire* n)
{
}
void AstToDotConverter
	::_print_DeclWire
	(DeclWire* n)
{
}
void AstToDotConverter
	::_accept_children_DeclWire
	(DeclWire* n)
{
}
void AstToDotConverter
	::_build_node_vec_DeclVar
	(DeclVar* n)
{
}
void AstToDotConverter
	::_print_DeclVar
	(DeclVar* n)
{
}
void AstToDotConverter
	::_accept_children_DeclVar
	(DeclVar* n)
{
}
void AstToDotConverter
	::_build_node_vec_DeclConst
	(DeclConst* n)
{
}
void AstToDotConverter
	::_print_DeclConst
	(DeclConst* n)
{
}
void AstToDotConverter
	::_accept_children_DeclConst
	(DeclConst* n)
{
}

void AstToDotConverter
	::_build_node_vec_DeclEnum
	(DeclEnum* n)
{
}
void AstToDotConverter
	::_print_DeclEnum
	(DeclEnum* n)
{
}
void AstToDotConverter
	::_accept_children_DeclEnum
	(DeclEnum* n)
{
}

void AstToDotConverter
	::_build_node_vec_DeclMixin
	(DeclMixin* n)
{
}
void AstToDotConverter
	::_print_DeclMixin
	(DeclMixin* n)
{
}
void AstToDotConverter
	::_accept_children_DeclMixin
	(DeclMixin* n)
{
}
void AstToDotConverter
	::_build_node_vec_DeclClass
	(DeclClass* n)
{
}
void AstToDotConverter
	::_print_DeclClass
	(DeclClass* n)
{
}
void AstToDotConverter
	::_accept_children_DeclClass
	(DeclClass* n)
{
}

void AstToDotConverter
	::_build_node_vec_DeclClass_DeclVar
	(DeclClass_DeclVar* n)
{
}
void AstToDotConverter
	::_print_DeclClass_DeclVar
	(DeclClass_DeclVar* n)
{
}
void AstToDotConverter
	::_accept_children_DeclClass_DeclVar
	(DeclClass_DeclVar* n)
{
}
void AstToDotConverter
	::_build_node_vec_DeclClsOrMxn_DeclType
	(DeclClsOrMxn_DeclType* n)
{
}
void AstToDotConverter
	::_print_DeclClsOrMxn_DeclType
	(DeclClsOrMxn_DeclType* n)
{
}
void AstToDotConverter
	::_accept_children_DeclClsOrMxn_DeclType
	(DeclClsOrMxn_DeclType* n)
{
}
void AstToDotConverter
	::_build_node_vec_DeclClsOrMxn_DeclAliasOrConst
	(DeclClsOrMxn_DeclAliasOrConst* n)
{
}
void AstToDotConverter
	::_print_DeclClsOrMxn_DeclAliasOrConst
	(DeclClsOrMxn_DeclAliasOrConst* n)
{
}
void AstToDotConverter
	::_accept_children_DeclClsOrMxn_DeclAliasOrConst
	(DeclClsOrMxn_DeclAliasOrConst* n)
{
}

void AstToDotConverter
	::_build_node_vec_DeclClsOrMxn_DeclSubprogFullDefn
	(DeclClsOrMxn_DeclSubprogFullDefn* n)
{
}
void AstToDotConverter
	::_print_DeclClsOrMxn_DeclSubprogFullDefn
	(DeclClsOrMxn_DeclSubprogFullDefn* n)
{
}
void AstToDotConverter
	::_accept_children_DeclClsOrMxn_DeclSubprogFullDefn
	(DeclClsOrMxn_DeclSubprogFullDefn* n)
{
}
void AstToDotConverter
	::_build_node_vec_DeclClsOrMxn_DeclSubprogAbstract
	(DeclClsOrMxn_DeclSubprogAbstract* n)
{
}
void AstToDotConverter
	::_print_DeclClsOrMxn_DeclSubprogAbstract
	(DeclClsOrMxn_DeclSubprogAbstract* n)
{
}
void AstToDotConverter
	::_accept_children_DeclClsOrMxn_DeclSubprogAbstract
	(DeclClsOrMxn_DeclSubprogAbstract* n)
{
}

void AstToDotConverter
	::_build_node_vec_DeclFunc
	(DeclFunc* n)
{
}
void AstToDotConverter
	::_print_DeclFunc
	(DeclFunc* n)
{
}
void AstToDotConverter
	::_accept_children_DeclFunc
	(DeclFunc* n)
{
}
void AstToDotConverter
	::_build_node_vec_DeclFunc_Header
	(DeclFunc_Header* n)
{
}
void AstToDotConverter
	::_print_DeclFunc_Header
	(DeclFunc_Header* n)
{
}
void AstToDotConverter
	::_accept_children_DeclFunc_Header
	(DeclFunc_Header* n)
{
}
void AstToDotConverter
	::_build_node_vec_DeclFunc_Return
	(DeclFunc_Return* n)
{
}
void AstToDotConverter
	::_print_DeclFunc_Return
	(DeclFunc_Return* n)
{
}
void AstToDotConverter
	::_accept_children_DeclFunc_Return
	(DeclFunc_Return* n)
{
}

void AstToDotConverter
	::_build_node_vec_DeclTask
	(DeclTask* n)
{
}
void AstToDotConverter
	::_print_DeclTask
	(DeclTask* n)
{
}
void AstToDotConverter
	::_accept_children_DeclTask
	(DeclTask* n)
{
}
void AstToDotConverter
	::_build_node_vec_DeclTask_Header
	(DeclTask_Header* n)
{
}
void AstToDotConverter
	::_print_DeclTask_Header
	(DeclTask_Header* n)
{
}
void AstToDotConverter
	::_accept_children_DeclTask_Header
	(DeclTask_Header* n)
{
}

void AstToDotConverter
	::_build_node_vec_DeclProc
	(DeclProc* n)
{
}
void AstToDotConverter
	::_print_DeclProc
	(DeclProc* n)
{
}
void AstToDotConverter
	::_accept_children_DeclProc
	(DeclProc* n)
{
}
void AstToDotConverter
	::_build_node_vec_DeclProc_Header
	(DeclProc_Header* n)
{
}
void AstToDotConverter
	::_print_DeclProc_Header
	(DeclProc_Header* n)
{
}
void AstToDotConverter
	::_accept_children_DeclProc_Header
	(DeclProc_Header* n)
{
}

void AstToDotConverter
	::_build_node_vec_DeclAlias_Value
	(DeclAlias_Value* n)
{
}
void AstToDotConverter
	::_print_DeclAlias_Value
	(DeclAlias_Value* n)
{
}
void AstToDotConverter
	::_accept_children_DeclAlias_Value
	(DeclAlias_Value* n)
{
}
void AstToDotConverter
	::_build_node_vec_DeclAlias_Type
	(DeclAlias_Type* n)
{
}
void AstToDotConverter
	::_print_DeclAlias_Type
	(DeclAlias_Type* n)
{
}
void AstToDotConverter
	::_accept_children_DeclAlias_Type
	(DeclAlias_Type* n)
{
}
void AstToDotConverter
	::_build_node_vec_DeclAlias_Module
	(DeclAlias_Module* n)
{
}
void AstToDotConverter
	::_print_DeclAlias_Module
	(DeclAlias_Module* n)
{
}
void AstToDotConverter
	::_accept_children_DeclAlias_Module
	(DeclAlias_Module* n)
{
}

void AstToDotConverter
	::_build_node_vec_IdentList
	(IdentList* n)
{
}
void AstToDotConverter
	::_print_IdentList
	(IdentList* n)
{
}
void AstToDotConverter
	::_accept_children_IdentList
	(IdentList* n)
{
}
void AstToDotConverter
	::_build_node_vec_ScopedIdent
	(ScopedIdent* n)
{
}
void AstToDotConverter
	::_print_ScopedIdent
	(ScopedIdent* n)
{
}
void AstToDotConverter
	::_accept_children_ScopedIdent
	(ScopedIdent* n)
{
}
void AstToDotConverter
	::_build_node_vec_ImportList
	(ImportList* n)
{
}
void AstToDotConverter
	::_print_ImportList
	(ImportList* n)
{
}
void AstToDotConverter
	::_accept_children_ImportList
	(ImportList* n)
{
}

void AstToDotConverter
	::_build_node_vec_TypenameOrModname_Special
	(TypenameOrModname_Special* n)
{
}
void AstToDotConverter
	::_print_TypenameOrModname_Special
	(TypenameOrModname_Special* n)
{
}
void AstToDotConverter
	::_accept_children_TypenameOrModname_Special
	(TypenameOrModname_Special* n)
{
}
void AstToDotConverter
	::_build_node_vec_TypenameOrModname_Cstm
	(TypenameOrModname_Cstm* n)
{
}
void AstToDotConverter
	::_print_TypenameOrModname_Cstm
	(TypenameOrModname_Cstm* n)
{
}
void AstToDotConverter
	::_accept_children_TypenameOrModname_Cstm
	(TypenameOrModname_Cstm* n)
{
}
void AstToDotConverter
	::_build_node_vec_TypenameOrModname_Typeof
	(TypenameOrModname_Typeof* n)
{
}
void AstToDotConverter
	::_print_TypenameOrModname_Typeof
	(TypenameOrModname_Typeof* n)
{
}
void AstToDotConverter
	::_accept_children_TypenameOrModname_Typeof
	(TypenameOrModname_Typeof* n)
{
}
void AstToDotConverter
	::_build_node_vec_TypenameOrModname_Cstm_Item
	(TypenameOrModname_Cstm_Item* n)
{
}
void AstToDotConverter
	::_print_TypenameOrModname_Cstm_Item
	(TypenameOrModname_Cstm_Item* n)
{
}
void AstToDotConverter
	::_accept_children_TypenameOrModname_Cstm_Item
	(TypenameOrModname_Cstm_Item* n)
{
}
void AstToDotConverter
	::_build_node_vec_TypenameOrModname_Builtin
	(TypenameOrModname_Builtin* n)
{
}
void AstToDotConverter
	::_print_TypenameOrModname_Builtin
	(TypenameOrModname_Builtin* n)
{
}
void AstToDotConverter
	::_accept_children_TypenameOrModname_Builtin
	(TypenameOrModname_Builtin* n)
{
}

void AstToDotConverter
	::_build_node_vec_ExprMux
	(ExprMux* n)
{
}
void AstToDotConverter
	::_print_ExprMux
	(ExprMux* n)
{
}
void AstToDotConverter
	::_accept_children_ExprMux
	(ExprMux* n)
{
}

void AstToDotConverter
	::_build_node_vec_ExprLogOr
	(ExprLogOr* n)
{
}
void AstToDotConverter
	::_print_ExprLogOr
	(ExprLogOr* n)
{
}
void AstToDotConverter
	::_accept_children_ExprLogOr
	(ExprLogOr* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprLogAnd
	(ExprLogAnd* n)
{
}
void AstToDotConverter
	::_print_ExprLogAnd
	(ExprLogAnd* n)
{
}
void AstToDotConverter
	::_accept_children_ExprLogAnd
	(ExprLogAnd* n)
{
}

void AstToDotConverter
	::_build_node_vec_ExprBinopBitOr
	(ExprBinopBitOr* n)
{
}
void AstToDotConverter
	::_print_ExprBinopBitOr
	(ExprBinopBitOr* n)
{
}
void AstToDotConverter
	::_accept_children_ExprBinopBitOr
	(ExprBinopBitOr* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprBinopBitNor
	(ExprBinopBitNor* n)
{
}
void AstToDotConverter
	::_print_ExprBinopBitNor
	(ExprBinopBitNor* n)
{
}
void AstToDotConverter
	::_accept_children_ExprBinopBitNor
	(ExprBinopBitNor* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprBinopBitAnd
	(ExprBinopBitAnd* n)
{
}
void AstToDotConverter
	::_print_ExprBinopBitAnd
	(ExprBinopBitAnd* n)
{
}
void AstToDotConverter
	::_accept_children_ExprBinopBitAnd
	(ExprBinopBitAnd* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprBinopBitNand
	(ExprBinopBitNand* n)
{
}
void AstToDotConverter
	::_print_ExprBinopBitNand
	(ExprBinopBitNand* n)
{
}
void AstToDotConverter
	::_accept_children_ExprBinopBitNand
	(ExprBinopBitNand* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprBinopBitXor
	(ExprBinopBitXor* n)
{
}
void AstToDotConverter
	::_print_ExprBinopBitXor
	(ExprBinopBitXor* n)
{
}
void AstToDotConverter
	::_accept_children_ExprBinopBitXor
	(ExprBinopBitXor* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprBinopBitXnor
	(ExprBinopBitXnor* n)
{
}
void AstToDotConverter
	::_print_ExprBinopBitXnor
	(ExprBinopBitXnor* n)
{
}
void AstToDotConverter
	::_accept_children_ExprBinopBitXnor
	(ExprBinopBitXnor* n)
{
}

void AstToDotConverter
	::_build_node_vec_ExprCmpEq
	(ExprCmpEq* n)
{
}
void AstToDotConverter
	::_print_ExprCmpEq
	(ExprCmpEq* n)
{
}
void AstToDotConverter
	::_accept_children_ExprCmpEq
	(ExprCmpEq* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprCmpNe
	(ExprCmpNe* n)
{
}
void AstToDotConverter
	::_print_ExprCmpNe
	(ExprCmpNe* n)
{
}
void AstToDotConverter
	::_accept_children_ExprCmpNe
	(ExprCmpNe* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprCaseCmpEq
	(ExprCaseCmpEq* n)
{
}
void AstToDotConverter
	::_print_ExprCaseCmpEq
	(ExprCaseCmpEq* n)
{
}
void AstToDotConverter
	::_accept_children_ExprCaseCmpEq
	(ExprCaseCmpEq* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprCaseCmpNe
	(ExprCaseCmpNe* n)
{
}
void AstToDotConverter
	::_print_ExprCaseCmpNe
	(ExprCaseCmpNe* n)
{
}
void AstToDotConverter
	::_accept_children_ExprCaseCmpNe
	(ExprCaseCmpNe* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprCmpLt
	(ExprCmpLt* n)
{
}
void AstToDotConverter
	::_print_ExprCmpLt
	(ExprCmpLt* n)
{
}
void AstToDotConverter
	::_accept_children_ExprCmpLt
	(ExprCmpLt* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprCmpLe
	(ExprCmpLe* n)
{
}
void AstToDotConverter
	::_print_ExprCmpLe
	(ExprCmpLe* n)
{
}
void AstToDotConverter
	::_accept_children_ExprCmpLe
	(ExprCmpLe* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprCmpGt
	(ExprCmpGt* n)
{
}
void AstToDotConverter
	::_print_ExprCmpGt
	(ExprCmpGt* n)
{
}
void AstToDotConverter
	::_accept_children_ExprCmpGt
	(ExprCmpGt* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprCmpGe
	(ExprCmpGe* n)
{
}
void AstToDotConverter
	::_print_ExprCmpGe
	(ExprCmpGe* n)
{
}
void AstToDotConverter
	::_accept_children_ExprCmpGe
	(ExprCmpGe* n)
{
}

void AstToDotConverter
	::_build_node_vec_ExprBitLsl
	(ExprBitLsl* n)
{
}
void AstToDotConverter
	::_print_ExprBitLsl
	(ExprBitLsl* n)
{
}
void AstToDotConverter
	::_accept_children_ExprBitLsl
	(ExprBitLsl* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprBitLsr
	(ExprBitLsr* n)
{
}
void AstToDotConverter
	::_print_ExprBitLsr
	(ExprBitLsr* n)
{
}
void AstToDotConverter
	::_accept_children_ExprBitLsr
	(ExprBitLsr* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprBitAsr
	(ExprBitAsr* n)
{
}
void AstToDotConverter
	::_print_ExprBitAsr
	(ExprBitAsr* n)
{
}
void AstToDotConverter
	::_accept_children_ExprBitAsr
	(ExprBitAsr* n)
{
}

void AstToDotConverter
	::_build_node_vec_ExprBinopPlus
	(ExprBinopPlus* n)
{
}
void AstToDotConverter
	::_print_ExprBinopPlus
	(ExprBinopPlus* n)
{
}
void AstToDotConverter
	::_accept_children_ExprBinopPlus
	(ExprBinopPlus* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprBinopMinus
	(ExprBinopMinus* n)
{
}
void AstToDotConverter
	::_print_ExprBinopMinus
	(ExprBinopMinus* n)
{
}
void AstToDotConverter
	::_accept_children_ExprBinopMinus
	(ExprBinopMinus* n)
{
}

void AstToDotConverter
	::_build_node_vec_ExprMul
	(ExprMul* n)
{
}
void AstToDotConverter
	::_print_ExprMul
	(ExprMul* n)
{
}
void AstToDotConverter
	::_accept_children_ExprMul
	(ExprMul* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprDiv
	(ExprDiv* n)
{
}
void AstToDotConverter
	::_print_ExprDiv
	(ExprDiv* n)
{
}
void AstToDotConverter
	::_accept_children_ExprDiv
	(ExprDiv* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprMod
	(ExprMod* n)
{
}
void AstToDotConverter
	::_print_ExprMod
	(ExprMod* n)
{
}
void AstToDotConverter
	::_accept_children_ExprMod
	(ExprMod* n)
{
}

void AstToDotConverter
	::_build_node_vec_ExprUnopPlus
	(ExprUnopPlus* n)
{
}
void AstToDotConverter
	::_print_ExprUnopPlus
	(ExprUnopPlus* n)
{
}
void AstToDotConverter
	::_accept_children_ExprUnopPlus
	(ExprUnopPlus* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprUnopMinus
	(ExprUnopMinus* n)
{
}
void AstToDotConverter
	::_print_ExprUnopMinus
	(ExprUnopMinus* n)
{
}
void AstToDotConverter
	::_accept_children_ExprUnopMinus
	(ExprUnopMinus* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprLogNot
	(ExprLogNot* n)
{
}
void AstToDotConverter
	::_print_ExprLogNot
	(ExprLogNot* n)
{
}
void AstToDotConverter
	::_accept_children_ExprLogNot
	(ExprLogNot* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprBitNot
	(ExprBitNot* n)
{
}
void AstToDotConverter
	::_print_ExprBitNot
	(ExprBitNot* n)
{
}
void AstToDotConverter
	::_accept_children_ExprBitNot
	(ExprBitNot* n)
{
}

void AstToDotConverter
	::_build_node_vec_ExprUnopBitOr
	(ExprUnopBitOr* n)
{
}
void AstToDotConverter
	::_print_ExprUnopBitOr
	(ExprUnopBitOr* n)
{
}
void AstToDotConverter
	::_accept_children_ExprUnopBitOr
	(ExprUnopBitOr* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprUnopBitNor
	(ExprUnopBitNor* n)
{
}
void AstToDotConverter
	::_print_ExprUnopBitNor
	(ExprUnopBitNor* n)
{
}
void AstToDotConverter
	::_accept_children_ExprUnopBitNor
	(ExprUnopBitNor* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprUnopBitAnd
	(ExprUnopBitAnd* n)
{
}
void AstToDotConverter
	::_print_ExprUnopBitAnd
	(ExprUnopBitAnd* n)
{
}
void AstToDotConverter
	::_accept_children_ExprUnopBitAnd
	(ExprUnopBitAnd* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprUnopBitNand
	(ExprUnopBitNand* n)
{
}
void AstToDotConverter
	::_print_ExprUnopBitNand
	(ExprUnopBitNand* n)
{
}
void AstToDotConverter
	::_accept_children_ExprUnopBitNand
	(ExprUnopBitNand* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprUnopBitXor
	(ExprUnopBitXor* n)
{
}
void AstToDotConverter
	::_print_ExprUnopBitXor
	(ExprUnopBitXor* n)
{
}
void AstToDotConverter
	::_accept_children_ExprUnopBitXor
	(ExprUnopBitXor* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprUnopBitXnor
	(ExprUnopBitXnor* n)
{
}
void AstToDotConverter
	::_print_ExprUnopBitXnor
	(ExprUnopBitXnor* n)
{
}
void AstToDotConverter
	::_accept_children_ExprUnopBitXnor
	(ExprUnopBitXnor* n)
{
}

void AstToDotConverter
	::_build_node_vec_ExprLiteral
	(ExprLiteral* n)
{
}
void AstToDotConverter
	::_print_ExprLiteral
	(ExprLiteral* n)
{
}
void AstToDotConverter
	::_accept_children_ExprLiteral
	(ExprLiteral* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprSized
	(ExprSized* n)
{
}
void AstToDotConverter
	::_print_ExprSized
	(ExprSized* n)
{
}
void AstToDotConverter
	::_accept_children_ExprSized
	(ExprSized* n)
{
}

void AstToDotConverter
	::_build_node_vec_ExprRange
	(ExprRange* n)
{
}
void AstToDotConverter
	::_print_ExprRange
	(ExprRange* n)
{
}
void AstToDotConverter
	::_accept_children_ExprRange
	(ExprRange* n)
{
}

void AstToDotConverter
	::_build_node_vec_ExprCat
	(ExprCat* n)
{
}
void AstToDotConverter
	::_print_ExprCat
	(ExprCat* n)
{
}
void AstToDotConverter
	::_accept_children_ExprCat
	(ExprCat* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprRepl
	(ExprRepl* n)
{
}
void AstToDotConverter
	::_print_ExprRepl
	(ExprRepl* n)
{
}
void AstToDotConverter
	::_accept_children_ExprRepl
	(ExprRepl* n)
{
}

void AstToDotConverter
	::_build_node_vec_ExprDollarSigned
	(ExprDollarSigned* n)
{
}
void AstToDotConverter
	::_print_ExprDollarSigned
	(ExprDollarSigned* n)
{
}
void AstToDotConverter
	::_accept_children_ExprDollarSigned
	(ExprDollarSigned* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprDollarUnsigned
	(ExprDollarUnsigned* n)
{
}
void AstToDotConverter
	::_print_ExprDollarUnsigned
	(ExprDollarUnsigned* n)
{
}
void AstToDotConverter
	::_accept_children_ExprDollarUnsigned
	(ExprDollarUnsigned* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprDollarClog2
	(ExprDollarClog2* n)
{
}
void AstToDotConverter
	::_print_ExprDollarClog2
	(ExprDollarClog2* n)
{
}
void AstToDotConverter
	::_accept_children_ExprDollarClog2
	(ExprDollarClog2* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprDollarIsvtype
	(ExprDollarIsvtype* n)
{
}
void AstToDotConverter
	::_print_ExprDollarIsvtype
	(ExprDollarIsvtype* n)
{
}
void AstToDotConverter
	::_accept_children_ExprDollarIsvtype
	(ExprDollarIsvtype* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprDollarPow
	(ExprDollarPow* n)
{
}
void AstToDotConverter
	::_print_ExprDollarPow
	(ExprDollarPow* n)
{
}
void AstToDotConverter
	::_accept_children_ExprDollarPow
	(ExprDollarPow* n)
{
}

void AstToDotConverter
	::_build_node_vec_ExprIdentEtc
	(ExprIdentEtc* n)
{
}
void AstToDotConverter
	::_print_ExprIdentEtc
	(ExprIdentEtc* n)
{
}
void AstToDotConverter
	::_accept_children_ExprIdentEtc
	(ExprIdentEtc* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprIdentEtc_FirstItem
	(ExprIdentEtc_FirstItem* n)
{
}
void AstToDotConverter
	::_print_ExprIdentEtc_FirstItem
	(ExprIdentEtc_FirstItem* n)
{
}
void AstToDotConverter
	::_accept_children_ExprIdentEtc_FirstItem
	(ExprIdentEtc_FirstItem* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprIdentEtc_NonSelfItem
	(ExprIdentEtc_NonSelfItem* n)
{
}
void AstToDotConverter
	::_print_ExprIdentEtc_NonSelfItem
	(ExprIdentEtc_NonSelfItem* n)
{
}
void AstToDotConverter
	::_accept_children_ExprIdentEtc_NonSelfItem
	(ExprIdentEtc_NonSelfItem* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprIdentEtc_ItemEnd
	(ExprIdentEtc_ItemEnd* n)
{
}
void AstToDotConverter
	::_print_ExprIdentEtc_ItemEnd
	(ExprIdentEtc_ItemEnd* n)
{
}
void AstToDotConverter
	::_accept_children_ExprIdentEtc_ItemEnd
	(ExprIdentEtc_ItemEnd* n)
{
}
void AstToDotConverter
	::_build_node_vec_ExprIdentEtc_ItemEndIndex
	(ExprIdentEtc_ItemEndIndex* n)
{
}
void AstToDotConverter
	::_print_ExprIdentEtc_ItemEndIndex
	(ExprIdentEtc_ItemEndIndex* n)
{
}
void AstToDotConverter
	::_accept_children_ExprIdentEtc_ItemEndIndex
	(ExprIdentEtc_ItemEndIndex* n)
{
}

// Call a member function via `a plus b` instead of `a.plus(b)`
void AstToDotConverter
	::_build_node_vec_ExprCallSubprog_PseudoOper
	(ExprCallSubprog_PseudoOper* n)
{
}
void AstToDotConverter
	::_print_ExprCallSubprog_PseudoOper
	(ExprCallSubprog_PseudoOper* n)
{
}
void AstToDotConverter
	::_accept_children_ExprCallSubprog_PseudoOper
	(ExprCallSubprog_PseudoOper* n)
{
}

} // namespace fling_hdl
