#include "ast_visitor_class.hpp"
#include "ast_node_classes.hpp"
#include "../liborangepower_src/cpp_magic.hpp"

namespace fling_hdl
{

using namespace ast;

#define _INNER_ACCEPT(item) \
	_inner_accept_children(#item, n->item)
#define ACCEPT(...) \
	EVAL(MAP(_INNER_ACCEPT, SEMICOLON, __VA_ARGS__))

//DeclModule* temp = nullptr;

//--------
void AstVisitor::_inner_accept_children(const string& memb_name, 
	const BaseSptr& node)
{
	//if (temp != nullptr)
	//{
	//	printout("I have temp.\n");
	//}

	if (node)
	{
		_memb_name = memb_name;
		node->accept(this);
	}
}

void AstVisitor::_inner_accept_children(const string& memb_name,
	const BaseSptrList& node_list)
{
	//if (temp != nullptr)
	//{
	//	printout("I have temp.\n");
	//}

	size_t i = 0;
	for (const auto& p: node_list)
	{
		_memb_name = sconcat(memb_name, "[", i, "]");
		p.data->accept(this);
		++i;
	}
}
//--------

//--------
void AstVisitor::_accept_children
	(Program* n)
{
	ACCEPT(item_list);
}
//--------

//--------
void AstVisitor::_accept_children
	(DeclPackage* n)
{
	ACCEPT(item_list);
}
void AstVisitor::_accept_children
	(Import* n)
{
	ACCEPT(item_list);
}
void AstVisitor::_accept_children
	(ImportItem* n)
{
	ACCEPT(item_list);
}
//--------

//--------
void AstVisitor::_accept_children
	(ParamOrArgList* n)
{
	ACCEPT(item_list);
}
void AstVisitor::_accept_children
	(DeclParamListItem* n)
{
	ACCEPT(opt_typenm, opt_def_val_list);
}
void AstVisitor::_accept_children
	(DeclArgListItem* n)
{
	ACCEPT(typenm, opt_def_val_list);
}
//--------

//--------
void AstVisitor::_accept_children
	(StrAndNode* n)
{
	ACCEPT(node);
}
//--------

//--------
void AstVisitor::_accept_children
	(DeclModule* n)
{
	ACCEPT(opt_param_list, arg_list, scope);
}
void AstVisitor::_accept_children
	(Scope* n)
{
	ACCEPT(item_list);
}
//--------

//--------
void AstVisitor::_accept_children
	(Modinst* n)
{
	ACCEPT(modnm, arg_list);
}
//--------

//--------
void AstVisitor::_accept_children
	(GenIf* n)
{
	ACCEPT(if_expr, if_scope, opt_elif_list, opt_else_scope);
}
void AstVisitor::_accept_children
	(GenElif* n)
{
	ACCEPT(expr, scope);
}
void AstVisitor::_accept_children
	(GenSwitchEtc* n)
{
	ACCEPT(expr, opt_default, opt_case_list);
}
void AstVisitor::_accept_children
	(GenCase* n)
{
	ACCEPT(expr_list, scope);
}
void AstVisitor::_accept_children
	(GenDefault* n)
{
	ACCEPT(scope);
}
void AstVisitor::_accept_children
	(GenFor* n)
{
	ACCEPT(range, scope);
}
//--------

//--------
void AstVisitor::_accept_children
	(DeclModuleBehavComb* n)
{
	ACCEPT(scope);
}
void AstVisitor::_accept_children
	(DeclModuleBehavSeq* n)
{
	ACCEPT(edge_item_list, scope);
}
void AstVisitor::_accept_children
	(DeclModuleBehavSeqEdgeItem* n)
{
	ACCEPT(expr);
}
//--------

//--------
void AstVisitor::_accept_children
	(BehavIf* n)
{
	//_accept_children(static_cast<GenIf*>(n));
	ACCEPT(if_expr, if_scope, opt_elif_list, opt_else_scope);
}
void AstVisitor::_accept_children
	(BehavElif* n)
{
	//_accept_children(static_cast<GenElif*>(n));
	ACCEPT(expr, scope);
}
void AstVisitor::_accept_children
	(BehavSwitchEtc* n)
{
	//_accept_children(static_cast<GenSwitchEtc*>(n));
	ACCEPT(expr, opt_default, opt_case_list);
}
void AstVisitor::_accept_children
	(BehavCase* n)
{
	//_accept_children(static_cast<GenCase*>(n));
	ACCEPT(expr_list, scope);
}
void AstVisitor::_accept_children
	(BehavDefault* n)
{
	//_accept_children(static_cast<GenDefault*>(n));
	ACCEPT(scope);
}
void AstVisitor::_accept_children
	(BehavFor* n)
{
	ACCEPT(range, scope);
}
void AstVisitor::_accept_children
	(BehavWhile* n)
{
	ACCEPT(expr, scope);
}
//--------

//--------
void AstVisitor::_accept_children
	(BehavAssign* n)
{
	ACCEPT(lhs, rhs);
}
//--------

//--------
void AstVisitor::_accept_children
	(DeclStruct* n)
{
	ACCEPT(opt_param_list, scope);
}
//--------

//--------
void AstVisitor::_accept_children
	(DeclEnum* n)
{
	ACCEPT(opt_typenm, item_list);
}
//--------

//--------
void AstVisitor::_accept_children
	(DeclSubprog* n)
{
	ACCEPT(opt_param_list, arg_list, opt_ret_typenm, scope);
}
//--------

//--------
void AstVisitor::_accept_children
	(DeclVarEtc* n)
{
	ACCEPT(typenm, val);
}
void AstVisitor::_accept_children
	(WireAssign* n)
{
	ACCEPT(lhs, rhs);
}
//--------

//--------
void AstVisitor::_accept_children
	(DeclAlias* n)
{
	ACCEPT(rhs);
}
//--------

//--------
void AstVisitor::_accept_children
	(NamedScope* n)
{
	ACCEPT(item_list);
}
//--------

//--------
void AstVisitor::_accept_children
	(MuxExpr* n)
{
	ACCEPT(cond, when_true, when_false);
}
void AstVisitor::_accept_children
	(BinopExpr* n)
{
	ACCEPT(left, right);
}
void AstVisitor::_accept_children
	(UnopExpr* n)
{
	ACCEPT(arg);
}
void AstVisitor::_accept_children
	(LitValExpr* n)
{
	ACCEPT(opt_expr);
}
void AstVisitor::_accept_children
	(CallDollarFuncExpr* n)
{
	ACCEPT(arg, opt_second_arg);
}
void AstVisitor::_accept_children
	(String* n)
{
}
void AstVisitor::_accept_children
	(IdentExprSuffix* n)
{
	ACCEPT(acc_memb_or_arr_list, opt_range_etc, opt_part_sel_right);
}
void AstVisitor::_accept_children
	(IdentExpr* n)
{
	ACCEPT(prologue_list, opt_arg_list, suffix);
}
void AstVisitor::_accept_children
	(CatExpr* n)
{
	ACCEPT(item_list);
}
void AstVisitor::_accept_children
	(ReplExpr* n)
{
	ACCEPT(amount, to_repl);
}
void AstVisitor::_accept_children
	(SizedExpr* n)
{
	ACCEPT(lit_num, width);
}
//--------

//--------
void AstVisitor::_accept_children
	(NonDollarFuncRange* n)
{
	ACCEPT(arg, opt_second_arg);
}
//--------

//--------
void AstVisitor::_accept_children
	(Typenm* n)
{
	ACCEPT(opt_ident_expr, opt_vec_dim, opt_arr_dim_list);
}
void AstVisitor::_accept_children
	(Modnm* n)
{
	_accept_children(static_cast<IdentExpr*>(n));
}
//--------

} // namespace fling_hdl
