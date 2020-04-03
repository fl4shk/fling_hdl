#include "ast_node_classes.hpp"
#include "ast_visitor_class.hpp"


namespace fling_hdl
{

namespace ast
{

template<typename FirstType, typename... RemArgTypes>
inline bool _inner_idcmp(Base* node)
{
	if (node->id() == FirstType().id())
	{
		return true;
	}
	else if constexpr (sizeof...(RemArgTypes) > 0)
	{
		return _inner_idcmp<RemArgTypes...>(node);
	}
	else
	{
		return false;
	}
}


} // namespace ast

} // namespace fling_hdl

using namespace fling_hdl;
using namespace fling_hdl::ast;

#define idcmp(...) \
	if (_inner_idcmp<__VA_ARGS__>(node))

// "Node as"
#define ndas \
	static_cast<TYPE*>(node)

#define wrap(item) \
	sconcat(#item, "(", ndas->item, ")")

#define wrap_conv(name) \
	sconcat(#name, "(", TYPE::conv_##name(ndas->name), ")")
#define wrap_conv_2(name) \
	sconcat(#name, "(", conv_##name(ndas->name), ")")


std::ostream& operator << (std::ostream& os, Base* node)
{
	if (node == nullptr)
	{
		osprintout(os, "<None>");
	}
	else // if (node != nullptr)
	{
		osprintout(os, node->id(), "(", "fp", "(", node->fp(), ")", "\n");
		idcmp(Program)
		{
			#undef TYPE
			#define TYPE Program
			osprintout(os, wrap(item_list));
		}
		else idcmp(DeclPackage)
		{
			#undef TYPE
			#define TYPE DeclPackage
			osprintout(os, strappcom2(wrap(ident), wrap(item_list)));
		}
		else idcmp(DeclParamList)
		{
			#undef TYPE
			#define TYPE DeclParamList
			osprintout(os, wrap(item_list));
		}
		else idcmp(DeclParamList_Item)
		{
			#undef TYPE
			#define TYPE DeclParamList_Item
			osprintout(os, strappcom2(wrap(ident_list), wrap_conv(kind),
				wrap(opt_typename_or_modname), wrap(opt_expr_list),
				wrap(opt_typename_or_modname_list)));
		}
		else idcmp(DeclArgList)
		{
			#undef TYPE
			#define TYPE DeclArgList
			osprintout(os, wrap(item_list));
		}
		else idcmp(DeclArgList_Item)
		{
			#undef TYPE
			#define TYPE DeclArgList_Item
			osprintout(os, strappcom2(wrap(ident_list), wrap_conv(kind),
				wrap(typename_or_modname), wrap(opt_expr_list)));
		}
		else idcmp(InstParamList)
		{
			#undef TYPE
			#define TYPE InstParamList
			osprintout(os, wrap(opt_item_list));
		}
		else idcmp(InstParamList_Named_Item)
		{
			#undef TYPE
			#define TYPE InstParamList_Named_Item
			osprintout(os, strappcom2(wrap(ident), wrap(item)));
		}
		else idcmp(InstArgList)
		{
			#undef TYPE
			#define TYPE InstArgList
			osprintout(os, wrap(opt_item_list));
		}
		else idcmp(InstArgList_Named_Item)
		{
			#undef TYPE
			#define TYPE InstArgList_Named_Item
			osprintout(os, strappcom2(wrap(ident), wrap(expr)));
		}
		else idcmp(DeclModule)
		{
			#undef TYPE
			#define TYPE DeclModule
			osprintout(os, strappcom2(wrap(ident), wrap(opt_param_list),
				wrap(arg_list), wrap(opt_import_list), wrap(item_list)));
		}
		else idcmp(InstModule)
		{
			#undef TYPE
			#define TYPE InstModule
			osprintout(os, strappcom2(wrap(ident),
				wrap(typename_or_modname), wrap(arg_list)));
		}
		else idcmp(GenIf)
		{
			#undef TYPE
			#define TYPE GenIf
			osprintout(os, strappcom2(wrap(cond), wrap(item_list),
				wrap(elif_list), wrap(opt_else)));
		}
		else idcmp(GenIf_Elif)
		{
			#undef TYPE
			#define TYPE GenIf_Elif
			osprintout(os, strappcom2(wrap(cond), wrap(item_list)));
		}
		else idcmp(GenIf_Else)
		{
			#undef TYPE
			#define TYPE GenIf_Else
			osprintout(os, wrap(item_list));
		}
		else idcmp(GenSwitch)
		{
			#undef TYPE
			#define TYPE GenSwitch
			osprintout(os, strappcom2(wrap(cond), wrap(opt_case_list),
				wrap(opt_default)));
		}
		else idcmp(GenSwitch_Case)
		{
			#undef TYPE
			#define TYPE GenSwitch_Case
			osprintout(os, strappcom2(wrap(expr_list), wrap(item_list)));
		}
		else idcmp(GenSwitch_Default)
		{
			#undef TYPE
			#define TYPE GenSwitch_Default
			osprintout(os, wrap(item_list));
		}
		else idcmp(GenFor)
		{
			#undef TYPE
			#define TYPE GenFor
			osprintout(os, strappcom2(wrap(label), wrap(ident)));
		}
		else idcmp(ContAssign)
		{
			#undef TYPE
			#define TYPE ContAssign
			osprintout(os, strappcom2(wrap(left), wrap(right)));
		}
		else idcmp(Behav)
		{
			#undef TYPE
			#define TYPE Behav
			osprintout(os, strappcom2(wrap_conv(kind), wrap(opt_edge_list),
				wrap(scope)));
		}
		else idcmp(Behav_SeqEdgeListItem)
		{
			#undef TYPE
			#define TYPE Behav_SeqEdgeListItem
			osprintout(os, strappcom2(wrap_conv(kind), wrap(expr)));
		}
		else idcmp(Behav_Scope)
		{
			#undef TYPE
			#define TYPE Behav_Scope
			osprintout(os, wrap(item_list));
		}
		else idcmp(If)
		{
			#undef TYPE
			#define TYPE If
			osprintout(os, strappcom2(wrap(cond), wrap(scope),
				wrap(elif_list), wrap(opt_else)));
		}
		else idcmp(If_Elif)
		{
			#undef TYPE
			#define TYPE If_Elif
			osprintout(os, strappcom2(wrap(cond), wrap(scope)));
		}
		else idcmp(If_Else)
		{
			#undef TYPE
			#define TYPE If_Else
			osprintout(os, wrap(scope));
		}
		else idcmp(Switch, Switchz)
		{
			#undef TYPE
			#define TYPE Switch
			osprintout(os, strappcom2(wrap(cond), wrap(opt_case_list),
				wrap(opt_default)));
		}
		else idcmp(SwitchOrSwitchz_Case)
		{
			#undef TYPE
			#define TYPE SwitchOrSwitchz_Case
			osprintout(os, strappcom2(wrap(expr_list), wrap(scope)));
		}
		else idcmp(SwitchOrSwitchz_Default)
		{
			#undef TYPE
			#define TYPE SwitchOrSwitchz_Default
			osprintout(os, wrap(scope));
		}
		else idcmp(For)
		{
			#undef TYPE
			#define TYPE For
			osprintout(os, strappcom2(wrap(ident), wrap(expr),
				wrap(scope)));
		}
		else idcmp(While)
		{
			#undef TYPE
			#define TYPE While
			osprintout(os, strappcom2(wrap(expr), wrap(scope)));
		}
		else idcmp(NonBlkAssign, BlkAssign)
		{
			#undef TYPE
			#define TYPE NonBlkAssign
			osprintout(os, strappcom2(wrap(left), wrap(right)));
		}
		else idcmp(DeclWire, DeclVar)
		{
			#undef TYPE
			#define TYPE DeclWire
			osprintout(os, strappcom2(wrap(ident_list),
				wrap(typename_or_modname), wrap(opt_expr_list)));
		}
		else idcmp(DeclConst)
		{
			#undef TYPE
			#define TYPE DeclConst
			osprintout(os, strappcom2(wrap(ident_list),
				wrap(typename_or_modname), wrap(expr_list)));
		}
		else idcmp(DeclEnum)
		{
			#undef TYPE
			#define TYPE DeclEnum
			osprintout(os, strappcom2(wrap(ident),
				wrap(opt_typename_or_modname), wrap(ident_list)));
		}
		else idcmp(DeclMixin)
		{
			#undef TYPE
			#define TYPE DeclMixin
			osprintout(os, strappcom2(wrap(is_base), wrap(ident),
				wrap(opt_param_list), wrap(opt_extends), wrap(item_list)));
		}
		else idcmp(DeclClass)
		{
			#undef TYPE
			#define TYPE DeclClass
			osprintout(os, strappcom2(wrap(is_base), wrap(ident),
				wrap(opt_param_list), wrap(opt_extends), wrap(item_list),
				wrap(is_signed), wrap(is_packed)));
		}
		else idcmp(DeclClsOrMxn_ItemBase)
		{
			#undef TYPE
			#define TYPE DeclClsOrMxn_ItemBase
			osprintout(os, strappcom2(wrap_conv_2(acc_spec)));
		}
		else idcmp(DeclClass_DeclVar)
		{
			#undef TYPE
			#define TYPE DeclClass_DeclVar
			osprintout(os, strappcom2(wrap_conv_2(acc_spec),
				wrap(is_static), wrap(decl_var)));
		}
		else idcmp(DeclClsOrMxn_DeclType)
		{
			#undef TYPE
			#define TYPE DeclClsOrMxn_DeclType
			osprintout(os, strappcom2(wrap_conv_2(acc_spec),
				wrap(decl_type)));
		}
		else idcmp(DeclClsOrMxn_DeclAliasOrConst)
		{
			#undef TYPE
			#define TYPE DeclClsOrMxn_DeclAliasOrConst
			osprintout(os, strappcom2(wrap_conv_2(acc_spec),
				wrap(is_static), wrap(decl_alias_or_const)));
		}
		else idcmp(DeclClsOrMxn_DeclSubprogFullDefn)
		{
			#undef TYPE
			#define TYPE DeclClsOrMxn_DeclSubprogFullDefn
			osprintout(os, strappcom2(wrap_conv_2(acc_spec),
				wrap(is_virtual), wrap(is_static), wrap(is_const),
				wrap(subprog)));
		}
		else idcmp(DeclClsOrMxn_DeclSubprogAbstract)
		{
			#undef TYPE
			#define TYPE DeclClsOrMxn_DeclSubprogAbstract
			osprintout(os, strappcom2(wrap_conv_2(acc_spec),
				wrap(is_const), wrap(header)));
		}
		else idcmp(DeclFunc)
		{
			#undef TYPE
			#define TYPE DeclFunc
			osprintout(os, strappcom2(wrap(header), wrap(item_list)));
		}
		else idcmp(DeclFunc_Header)
		{
			#undef TYPE
			#define TYPE DeclFunc_Header
			osprintout(os, strappcom2(wrap(ident), wrap(opt_param_list),
				wrap(arg_list), wrap(return_typename)));
		}
		else idcmp(DeclFunc_Return)
		{
			#undef TYPE
			#define TYPE DeclFunc_Return
			osprintout(os, wrap(expr));
		}
		else idcmp(DeclTask)
		{
			#undef TYPE
			#define TYPE DeclTask
			osprintout(os, strappcom2(wrap(header), wrap(item_list)));
		}
		else idcmp(DeclTask_Header)
		{
			#undef TYPE
			#define TYPE DeclTask_Header
			osprintout(os, strappcom2(wrap(ident), wrap(opt_param_list),
				wrap(arg_list)));
		}
		else idcmp(DeclProc)
		{
			#undef TYPE
			#define TYPE DeclProc
			osprintout(os, strappcom2(wrap(header), wrap(item_list)));
		}
		else idcmp(DeclProc_Header)
		{
			#undef TYPE
			#define TYPE DeclProc_Header
			osprintout(os, strappcom2(wrap(ident), wrap(opt_param_list),
				wrap(arg_list)));
		}
		else idcmp(DeclAlias_Value)
		{
			#undef TYPE
			#define TYPE DeclAlias_Value
			osprintout(os, strappcom2(wrap(ident_list),
				wrap(typename_or_modname), wrap(expr_list)));
		}
		else idcmp(DeclAlias_Type, DeclAlias_Module)
		{
			#undef TYPE
			#define TYPE DeclAlias_Type
			osprintout(os, strappcom2(wrap(ident_list),
				wrap(typename_or_modname_list)));
		}
		else idcmp(IdentList, ScopedIdent)
		{
			#undef TYPE
			#define TYPE IdentList
			osprintout(os, wrap(data));
		}
		else idcmp(ImportList)
		{
			#undef TYPE
			#define TYPE ImportList
			osprintout(os, wrap(item_list));
		}
		else idcmp(TypenameOrModname)
		{
			#undef TYPE
			#define TYPE TypenameOrModname
			osprintout(os, strappcom2(wrap_conv(kind), wrap(opt_child)));
		}
		else idcmp(TypenameOrModname_Cstm)
		{
			#undef TYPE
			#define TYPE TypenameOrModname_Cstm
			osprintout(os, strappcom2(wrap(item_list),
				wrap(arr_dim_list)));
		}
		else idcmp(TypenameOrModname_Cstm_Item)
		{
			#undef TYPE
			#define TYPE TypenameOrModname_Cstm_Item
			osprintout(os, strappcom2(wrap(ident), wrap(opt_param_list)));
		}
		else idcmp(TypenameOrModname_Builtin)
		{
			#undef TYPE
			#define TYPE TypenameOrModname_Builtin
			osprintout(os, strappcom2(wrap_conv(kind),
				wrap(opt_param_list), wrap(arr_dim_list)));
		}
		else idcmp(ExprMux)
		{
			#undef TYPE
			#define TYPE ExprMux
			osprintout(os, strappcom2(wrap(cond), wrap(when_true),
				wrap(when_false)));
		}
		else idcmp(ExprUnopBase)
		{
			#undef TYPE
			#define TYPE ExprUnopBase
			osprintout(os, wrap(to_feed));
		}
		else idcmp(ExprBinopBase,
			ExprLogOr, ExprLogAnd,
			ExprBinopBitOr, ExprBinopBitNor,
			ExprBinopBitAnd, ExprBinopBitNand,
			ExprBinopBitXor, ExprBinopBitXnor,
			ExprCmpEq, ExprCmpNe, ExprCaseCmpEq, ExprCaseCmpNe,
			ExprCmpLt, ExprCmpLe, ExprCmpGt, ExprCmpGe,
			ExprBitLsl, ExprBitLsr, ExprBitAsr,
			ExprBinopPlus, ExprBinopMinus,
			ExprMul, ExprDiv, ExprMod)
		{
			#undef TYPE
			#define TYPE ExprBinopBase
			osprintout(os, strappcom2(wrap(left), wrap(right)));
		}
		else idcmp(ExprUnopPlus, ExprUnopMinus,
			ExprLogNot, ExprBitNot,
			ExprUnopBitOr, ExprUnopBitNor,
			ExprUnopBitAnd, ExprUnopBitNand,
			ExprUnopBitXor, ExprUnopBitXnor)
		{
			#undef TYPE
			#define TYPE ExprUnopPlus
			osprintout(os, wrap(to_feed));
		}
		else idcmp(ExprLiteral)
		{
			#undef TYPE
			#define TYPE ExprLiteral
			osprintout(os, strappcom2(wrap(text), wrap(opt_size)));
		}
		else idcmp(ExprSized)
		{
			#undef TYPE
			#define TYPE ExprSized
			osprintout(os, strappcom2(wrap(dst_size), wrap(src)));
		}
		else idcmp(ExprRange)
		{
			#undef TYPE
			#define TYPE ExprRange
			osprintout(os, strappcom2(wrap(left), wrap(right)));
		}
		else idcmp(ExprCat)
		{
			#undef TYPE
			#define TYPE ExprCat
			osprintout(os, wrap(item_list));
		}
		else idcmp(ExprRepl)
		{
			#undef TYPE
			#define TYPE ExprRepl
			osprintout(os, strappcom2(wrap(amount), wrap(to_repl)));
		}
		else idcmp(ExprDollarSigned, ExprDollarUnsigned,
			ExprDollarClog2,
			ExprDollarIsvtype)
		{
			#undef TYPE
			#define TYPE ExprDollarSigned
			osprintout(os, wrap(to_feed));
		}
		else idcmp(ExprDollarPow)
		{
			#undef TYPE
			#define TYPE ExprDollarPow
			osprintout(os, strappcom2(wrap(left), wrap(right)));
		}
		else idcmp(ExprIdentEtc)
		{
			#undef TYPE
			#define TYPE ExprIdentEtc
			osprintout(os, strappcom2(wrap(opt_typename_or_modname),
				wrap(first_item), wrap(opt_later_item_list),
				wrap_conv(suff_kind)));
		}
		else idcmp(ExprIdentEtc_FirstItem)
		{
			#undef TYPE
			#define TYPE ExprIdentEtc_FirstItem
			osprintout(os, strappcom2(wrap_conv(kind),
				wrap(opt_non_self_item)));
		}
		else idcmp(ExprIdentEtc_NonSelfItem)
		{
			#undef TYPE
			#define TYPE ExprIdentEtc_NonSelfItem
			osprintout(os, strappcom2(wrap(ident), wrap(opt_param_list),
				wrap(opt_arg_list), wrap(end_item_list)));
		}
		else idcmp(ExprIdentEtc_ItemEnd)
		{
			#undef TYPE
			#define TYPE ExprIdentEtc_ItemEnd
			osprintout(os, strappcom2(wrap_conv(kind), wrap(opt_index)));
		}
		else idcmp(ExprIdentEtc_ItemEndIndex)
		{
			#undef TYPE
			#define TYPE ExprIdentEtc_ItemEndIndex
			osprintout(os, strappcom2(wrap_conv(kind), wrap(left),
				wrap(opt_right)));
		}
		else idcmp(ExprCallSubprog_PseudoOper)
		{
			#undef TYPE
			#define TYPE ExprCallSubprog_PseudoOper
			osprintout(os, strappcom2(wrap(left), wrap(right), wrap(ident),
				wrap(opt_param_list)));
		}
		else
		{
			#undef TYPE
			osprintout(os, "Internal Error");
		}

		osprintout(os, ")");
	}
	return os;
}
