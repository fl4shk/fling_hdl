#include "ast_visitor_class.hpp"
#include "ast_node_classes.hpp"
#include "liborangepower_src/cpp_magic.hpp"

namespace fling_hdl
{

using namespace ast;

#define _INNER_ACCEPT(item) \
	_inner_accept_children(#item, n->item)
#define ACCEPT(...) \
	EVAL(MAP(_INNER_ACCEPT, SEMICOLON, __VA_ARGS__))

void AstVisitor::_inner_accept_children(const string& memb_name, 
	const BaseSptr& node)
{
	if (node)
	{
		_memb_name = memb_name;
		node->accept(this);
	}
}

void AstVisitor::_inner_accept_children(const string& memb_name,
	const BaseSptrList& node_list)
{
	size_t i = 0;
	for (const auto& p: node_list)
	{
		_memb_name = sconcat(memb_name, "[", i, "]");
		p.data->accept(this);
		++i;
	}
}

void AstVisitor::_accept_children
	(Program* n)
{
	ACCEPT(item_list);
}
void AstVisitor::_accept_children
	(DeclPackage* n)
{
	ACCEPT(item_list);
}
void AstVisitor::_accept_children
	(ParamOrArgList* n)
{
	ACCEPT(item_list);
}
void AstVisitor::_accept_children
	(DeclParamList_Item* n)
{
	ACCEPT(ident_list, opt_typename_or_modname, opt_expr_list,
		opt_typename_or_modname_list);
}
void AstVisitor::_accept_children
	(DeclArgList_Item* n)
{
	ACCEPT(ident_list, typename_or_modname, opt_expr_list);
}
void AstVisitor::_accept_children
	(InstParamList_Named_Item* n)
{
	ACCEPT(item);
}
void AstVisitor::_accept_children
	(InstArgList_Named_Item* n)
{
	ACCEPT(expr);
}
void AstVisitor::_accept_children
	(DeclModule* n)
{
	ACCEPT(opt_param_list, arg_list, opt_import_list, item_list);
}
void AstVisitor::_accept_children
	(InstModule* n)
{
	ACCEPT(typename_or_modname, arg_list);
}
void AstVisitor::_accept_children
	(GenIf* n)
{
	ACCEPT(cond, item_list, elif_list, opt_else);
}
void AstVisitor::_accept_children
	(GenIf_Elif* n)
{
	ACCEPT(cond, item_list);
}
void AstVisitor::_accept_children
	(GenIf_Else* n)
{
	ACCEPT(item_list);
}
void AstVisitor::_accept_children
	(GenSwitch* n)
{
	ACCEPT(cond, opt_case_list, opt_default);
}
void AstVisitor::_accept_children
	(GenSwitch_Case* n)
{
	ACCEPT(expr_list, item_list);
}
void AstVisitor::_accept_children
	(GenSwitch_Default* n)
{
	ACCEPT(item_list);
}
void AstVisitor::_accept_children
	(GenFor* n)
{
	ACCEPT(expr, item_list);
}
void AstVisitor::_accept_children
	(ContAssign* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(Behav* n)
{
	ACCEPT(opt_edge_list, scope);
}
void AstVisitor::_accept_children
	(Behav_SeqEdgeListItem* n)
{
	ACCEPT(expr);
}
void AstVisitor::_accept_children
	(Behav_Scope* n)
{
	ACCEPT(item_list);
}
void AstVisitor::_accept_children
	(If* n)
{
	ACCEPT(cond, scope, elif_list, opt_else);
}
void AstVisitor::_accept_children
	(If_Elif* n)
{
	ACCEPT(cond, scope);
}
void AstVisitor::_accept_children
	(If_Else* n)
{
	ACCEPT(scope);
}
void AstVisitor::_accept_children
	(Switch* n)
{
	_accept_children(static_cast<GenSwitch*>(n));
}
void AstVisitor::_accept_children
	(Switchz* n)
{
	_accept_children(static_cast<GenSwitch*>(n));
}
void AstVisitor::_accept_children
	(SwitchOrSwitchz_Case* n)
{
	ACCEPT(expr_list, scope);
}
void AstVisitor::_accept_children
	(SwitchOrSwitchz_Default* n)
{
	ACCEPT(scope);
}
void AstVisitor::_accept_children
	(For* n)
{
	ACCEPT(expr, scope);
}
void AstVisitor::_accept_children
	(While* n)
{
	ACCEPT(expr, scope);
}
void AstVisitor::_accept_children
	(NonBlkAssign* n)
{
	_accept_children(static_cast<ContAssign*>(n));
}
void AstVisitor::_accept_children
	(BlkAssign* n)
{
	_accept_children(static_cast<ContAssign*>(n));
}
void AstVisitor::_accept_children
	(DeclWire* n)
{
	ACCEPT(ident_list, typename_or_modname, opt_expr_list);
}
void AstVisitor::_accept_children
	(DeclVar* n)
{
	_accept_children(static_cast<DeclWire*>(n));
}
void AstVisitor::_accept_children
	(DeclConst* n)
{
	ACCEPT(ident_list, typename_or_modname, expr_list);
}
void AstVisitor::_accept_children
	(DeclEnum* n)
{
	ACCEPT(opt_typename_or_modname, ident_list);
}
void AstVisitor::_accept_children
	(DeclMixin* n)
{
}
void AstVisitor::_accept_children
	(DeclClass* n)
{
}
void AstVisitor::_accept_children
	(DeclClass_DeclVar* n)
{
}
void AstVisitor::_accept_children
	(DeclClsOrMxn_DeclType* n)
{
}
void AstVisitor::_accept_children
	(DeclClsOrMxn_DeclAliasOrConst* n)
{
}
void AstVisitor::_accept_children
	(DeclClsOrMxn_DeclSubprogFullDefn* n)
{
}
void AstVisitor::_accept_children
	(DeclClsOrMxn_DeclSubprogAbstract* n)
{
}
void AstVisitor::_accept_children
	(DeclFunc* n)
{
}
void AstVisitor::_accept_children
	(DeclFunc_Header* n)
{
}
void AstVisitor::_accept_children
	(DeclFunc_Return* n)
{
}
void AstVisitor::_accept_children
	(DeclTask* n)
{
}
void AstVisitor::_accept_children
	(DeclTask_Header* n)
{
}
void AstVisitor::_accept_children
	(DeclProc* n)
{
}
void AstVisitor::_accept_children
	(DeclProc_Header* n)
{
}
void AstVisitor::_accept_children
	(DeclAlias_Value* n)
{
}
void AstVisitor::_accept_children
	(DeclAlias_Type* n)
{
}
void AstVisitor::_accept_children
	(DeclAlias_Module* n)
{
}
void AstVisitor::_accept_children
	(IdentList* n)
{
}
void AstVisitor::_accept_children
	(ScopedIdent* n)
{
}
void AstVisitor::_accept_children
	(ImportList* n)
{
}
void AstVisitor::_accept_children
	(TypenameOrModname_Special* n)
{
}
void AstVisitor::_accept_children
	(TypenameOrModname_Cstm* n)
{
}
void AstVisitor::_accept_children
	(TypenameOrModname_Typeof* n)
{
}
void AstVisitor::_accept_children
	(TypenameOrModname_Cstm_Item* n)
{
}
void AstVisitor::_accept_children
	(TypenameOrModname_Builtin* n)
{
}
void AstVisitor::_accept_children
	(ExprMux* n)
{
}
void AstVisitor::_accept_children
	(ExprLogOr* n)
{
}
void AstVisitor::_accept_children
	(ExprLogAnd* n)
{
}
void AstVisitor::_accept_children
	(ExprBinopBitOr* n)
{
}
void AstVisitor::_accept_children
	(ExprBinopBitNor* n)
{
}
void AstVisitor::_accept_children
	(ExprBinopBitAnd* n)
{
}
void AstVisitor::_accept_children
	(ExprBinopBitNand* n)
{
}
void AstVisitor::_accept_children
	(ExprBinopBitXor* n)
{
}
void AstVisitor::_accept_children
	(ExprBinopBitXnor* n)
{
}
void AstVisitor::_accept_children
	(ExprCmpEq* n)
{
}
void AstVisitor::_accept_children
	(ExprCmpNe* n)
{
}
void AstVisitor::_accept_children
	(ExprCaseCmpEq* n)
{
}
void AstVisitor::_accept_children
	(ExprCaseCmpNe* n)
{
}
void AstVisitor::_accept_children
	(ExprCmpLt* n)
{
}
void AstVisitor::_accept_children
	(ExprCmpLe* n)
{
}
void AstVisitor::_accept_children
	(ExprCmpGt* n)
{
}
void AstVisitor::_accept_children
	(ExprCmpGe* n)
{
}
void AstVisitor::_accept_children
	(ExprBitLsl* n)
{
}
void AstVisitor::_accept_children
	(ExprBitLsr* n)
{
}
void AstVisitor::_accept_children
	(ExprBitAsr* n)
{
}
void AstVisitor::_accept_children
	(ExprBinopPlus* n)
{
}
void AstVisitor::_accept_children
	(ExprBinopMinus* n)
{
}
void AstVisitor::_accept_children
	(ExprMul* n)
{
}
void AstVisitor::_accept_children
	(ExprDiv* n)
{
}
void AstVisitor::_accept_children
	(ExprMod* n)
{
}
void AstVisitor::_accept_children
	(ExprUnopPlus* n)
{
}
void AstVisitor::_accept_children
	(ExprUnopMinus* n)
{
}
void AstVisitor::_accept_children
	(ExprLogNot* n)
{
}
void AstVisitor::_accept_children
	(ExprBitNot* n)
{
}
void AstVisitor::_accept_children
	(ExprUnopBitOr* n)
{
}
void AstVisitor::_accept_children
	(ExprUnopBitNor* n)
{
}
void AstVisitor::_accept_children
	(ExprUnopBitAnd* n)
{
}
void AstVisitor::_accept_children
	(ExprUnopBitNand* n)
{
}
void AstVisitor::_accept_children
	(ExprUnopBitXor* n)
{
}
void AstVisitor::_accept_children
	(ExprUnopBitXnor* n)
{
}
void AstVisitor::_accept_children
	(ExprLiteral* n)
{
}
void AstVisitor::_accept_children
	(ExprSized* n)
{
}
void AstVisitor::_accept_children
	(ExprRange* n)
{
}
void AstVisitor::_accept_children
	(ExprCat* n)
{
}
void AstVisitor::_accept_children
	(ExprRepl* n)
{
}
void AstVisitor::_accept_children
	(ExprDollarSigned* n)
{
}
void AstVisitor::_accept_children
	(ExprDollarUnsigned* n)
{
}
void AstVisitor::_accept_children
	(ExprDollarClog2* n)
{
}
void AstVisitor::_accept_children
	(ExprDollarIsvtype* n)
{
}
void AstVisitor::_accept_children
	(ExprDollarPow* n)
{
}
void AstVisitor::_accept_children
	(ExprIdentEtc* n)
{
}
void AstVisitor::_accept_children
	(ExprIdentEtc_FirstItem* n)
{
}
void AstVisitor::_accept_children
	(ExprIdentEtc_NonSelfItem* n)
{
}
void AstVisitor::_accept_children
	(ExprIdentEtc_ItemEnd* n)
{
}
void AstVisitor::_accept_children
	(ExprIdentEtc_ItemEndIndex* n)
{
}
void AstVisitor::_accept_children
	(ExprCallSubprog_PseudoOper* n)
{
}

} // namespace fling_hdl
