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
	ACCEPT(opt_param_list, opt_extends, item_list);
}
void AstVisitor::_accept_children
	(DeclClass* n)
{
	_accept_children(static_cast<DeclMixin*>(n));
}
void AstVisitor::_accept_children
	(DeclClass_DeclVar* n)
{
	ACCEPT(decl_var);
}
void AstVisitor::_accept_children
	(DeclClsOrMxn_DeclType* n)
{
	ACCEPT(decl_type);
}
void AstVisitor::_accept_children
	(DeclClsOrMxn_DeclAliasOrConst* n)
{
	ACCEPT(decl_alias_or_const);
}
void AstVisitor::_accept_children
	(DeclClsOrMxn_DeclSubprogFullDefn* n)
{
	ACCEPT(subprog);
}
void AstVisitor::_accept_children
	(DeclClsOrMxn_DeclSubprogAbstract* n)
{
	ACCEPT(header);
}
void AstVisitor::_accept_children
	(DeclFunc* n)
{
	ACCEPT(header, scope);
}
void AstVisitor::_accept_children
	(DeclFunc_Header* n)
{
	ACCEPT(opt_param_list, arg_list, return_typename);
}
void AstVisitor::_accept_children
	(DeclFunc_Return* n)
{
	ACCEPT(expr);
}
void AstVisitor::_accept_children
	(DeclFunc_Defer* n)
{
	ACCEPT(expr);
}
void AstVisitor::_accept_children
	(DeclTask* n)
{
	_accept_children(static_cast<DeclFunc*>(n));
}
void AstVisitor::_accept_children
	(DeclTask_Header* n)
{
	ACCEPT(opt_param_list, arg_list);
}
void AstVisitor::_accept_children
	(DeclProc* n)
{
	ACCEPT(header, item_list);
}
void AstVisitor::_accept_children
	(DeclProc_Header* n)
{
	_accept_children(static_cast<DeclTask_Header*>(n));
}
void AstVisitor::_accept_children
	(DeclAlias_Value* n)
{
	ACCEPT(ident_list, typename_or_modname, expr_list);
}
void AstVisitor::_accept_children
	(DeclAlias_Type* n)
{
	ACCEPT(ident_list, typename_or_modname_list);
}
void AstVisitor::_accept_children
	(DeclAlias_Module* n)
{
	_accept_children(static_cast<DeclAlias_Type*>(n));
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
	ACCEPT(item_list);
}
void AstVisitor::_accept_children
	(ImportList_Item* n)
{
	ACCEPT(scoped_ident);
}
void AstVisitor::_accept_children
	(TypenameOrModname_Special* n)
{
}
void AstVisitor::_accept_children
	(TypenameOrModname_Cstm* n)
{
	ACCEPT(item_list, arr_dim_list);
}
void AstVisitor::_accept_children
	(TypenameOrModname_Typeof* n)
{
	ACCEPT(expr);
}
void AstVisitor::_accept_children
	(TypenameOrModname_Cstm_Item* n)
{
	ACCEPT(opt_param_list);
}
void AstVisitor::_accept_children
	(TypenameOrModname_Builtin* n)
{
	ACCEPT(opt_param_list, arr_dim_list);
}
void AstVisitor::_accept_children
	(ExprMux* n)
{
	ACCEPT(cond, when_true, when_false);
}
void AstVisitor::_accept_children
	(ExprLogOr* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprLogAnd* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprBinopBitOr* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprBinopBitNor* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprBinopBitAnd* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprBinopBitNand* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprBinopBitXor* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprBinopBitXnor* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprCmpEq* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprCmpNe* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprCaseCmpEq* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprCaseCmpNe* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprCmpLt* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprCmpLe* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprCmpGt* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprCmpGe* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprBitLsl* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprBitLsr* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprBitAsr* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprBinopPlus* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprBinopMinus* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprMul* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprDiv* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprMod* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprUnopPlus* n)
{
	ACCEPT(to_feed);
}
void AstVisitor::_accept_children
	(ExprUnopMinus* n)
{
	ACCEPT(to_feed);
}
void AstVisitor::_accept_children
	(ExprLogNot* n)
{
	ACCEPT(to_feed);
}
void AstVisitor::_accept_children
	(ExprBitNot* n)
{
	ACCEPT(to_feed);
}
void AstVisitor::_accept_children
	(ExprUnopBitOr* n)
{
	ACCEPT(to_feed);
}
void AstVisitor::_accept_children
	(ExprUnopBitNor* n)
{
	ACCEPT(to_feed);
}
void AstVisitor::_accept_children
	(ExprUnopBitAnd* n)
{
	ACCEPT(to_feed);
}
void AstVisitor::_accept_children
	(ExprUnopBitNand* n)
{
	ACCEPT(to_feed);
}
void AstVisitor::_accept_children
	(ExprUnopBitXor* n)
{
	ACCEPT(to_feed);
}
void AstVisitor::_accept_children
	(ExprUnopBitXnor* n)
{
	ACCEPT(to_feed);
}
void AstVisitor::_accept_children
	(ExprLiteral* n)
{
	ACCEPT(opt_size);
}
void AstVisitor::_accept_children
	(ExprSized* n)
{
	ACCEPT(dst_size, src);
}
void AstVisitor::_accept_children
	(ExprRange* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprCat* n)
{
	ACCEPT(item_list);
}
void AstVisitor::_accept_children
	(ExprRepl* n)
{
	ACCEPT(amount, to_repl);
}
void AstVisitor::_accept_children
	(ExprDollarSigned* n)
{
	ACCEPT(to_feed);
}
void AstVisitor::_accept_children
	(ExprDollarUnsigned* n)
{
	ACCEPT(to_feed);
}
void AstVisitor::_accept_children
	(ExprDollarClog2* n)
{
	ACCEPT(to_feed);
}
void AstVisitor::_accept_children
	(ExprDollarIsvtype* n)
{
	ACCEPT(to_feed);
}
void AstVisitor::_accept_children
	(ExprDollarPow* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(ExprIdentEtc* n)
{
	ACCEPT(opt_typename_or_modname, first_item, opt_later_item_list);
}
void AstVisitor::_accept_children
	(ExprIdentEtc_FirstItem* n)
{
	ACCEPT(opt_non_self_item);
}
void AstVisitor::_accept_children
	(ExprIdentEtc_NonSelfItem* n)
{
	ACCEPT(opt_param_list, opt_arg_list, end_item_list);
}
void AstVisitor::_accept_children
	(ExprIdentEtc_ItemEnd* n)
{
	ACCEPT(opt_index);
}
void AstVisitor::_accept_children
	(ExprIdentEtc_ItemEndIndex* n)
{
	ACCEPT(left, opt_right);
}
void AstVisitor::_accept_children
	(ExprCast* n)
{
	ACCEPT(to_cast, typename_or_modname);
}
void AstVisitor::_accept_children
	(ExprCallSubprog_PseudoOper* n)
{
	ACCEPT(left, right, opt_param_list);
}

} // namespace fling_hdl
