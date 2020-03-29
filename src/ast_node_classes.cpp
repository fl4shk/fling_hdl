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

#define idcmp(...) if (_inner_idcmp<__VA_ARGS__>(node))

// "Node as"
#define ndas \
	static_cast<TYPE*>(node)

#define wrap(item) \
	sconcat(#item, "(", ndas->item, ")")

#define wrap_conv(name) \
	sconcat(#name, "(", TYPE::conv_##name(ndas->name), ")")
#define wrap_conv_2(name) \
	sconcat(#name, "(", conv_##name(ndas->name), ")")


std::ostream& operator << (std::ostream& os, const BaseSptrList& list)
{
	for (const auto& item: list)
	{
		osprintout(os, item.data, ",\n");
	}
	return os;
}

std::ostream& operator << (std::ostream& os, Base* node)
{
	if (node == nullptr)
	{
		osprintout(os, "nullptr");
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
			osprintout(os, wrap(ident_list), ",");

			if (std::holds_alternative<DeclParamList_Item::LocalVar>
				(ndas->post_ident_list))
			{
				auto& local_var = std::get<DeclParamList_Item::LocalVar>
					(ndas->post_ident_list);

				osprintout(os, strappcom2("kind(local_var)",
					sconcat("typename_or_modname(", 
						local_var.typename_or_modname, ")"),
					sconcat("opt_expr_list(",
						local_var.opt_expr_list, ")")));
			}
			else if (std::holds_alternative<DeclParamList_Item
				::LocalTypename>(ndas->post_ident_list))
			{
				auto& local_typename = std::get<DeclParamList_Item
					::LocalTypename>(ndas->post_ident_list);

				osprintout(os, strappcom2("kind(typename)",
					sconcat("opt_typename_or_modname_list(",
						local_typename.opt_typename_or_modname_list,
						")")));
			}
			else if (std::holds_alternative<DeclParamList_Item
				::LocalModname>(ndas->post_ident_list))
			{
				auto& local_modname = std::get<DeclParamList_Item
					::LocalModname>(ndas->post_ident_list);

				osprintout(os, strappcom2("kind(modname)",
					sconcat("opt_typename_or_modname_list(",
						local_modname.opt_typename_or_modname_list,
						")")));
			}
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
			osprintout(os, strappcom2(wrap(cond), wrap(case_list),
				wrap(opt_default)));
		}
		else idcmp(GenSwitch_Case)
		{
			#undef TYPE
			#define TYPE GenSwitch_Case
			osprintout(os, strappcom2(wrap(expr), wrap(item_list)));
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
			osprintout(os, strappcom2(wrap_conv(kind),
				wrap(behav_seq_edge_list), wrap(scope)));
		}
		else idcmp(Behav_SeqEdgeList)
		{
			#undef TYPE
			#define TYPE Behav_SeqEdgeList
			osprintout(os, wrap(item_list));
		}
		else idcmp(Behav_SeqEdgeList_Item)
		{
			#undef TYPE
			#define TYPE Behav_SeqEdgeList_Item
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
			osprintout(os, strappcom2(wrap(cond), wrap(case_list),
				wrap(opt_default)));
		}
		else idcmp(SwitchOrSwitchz_Case)
		{
			#undef TYPE
			#define TYPE SwitchOrSwitchz_Case
			osprintout(os, strappcom2(wrap(expr), wrap(scope)));
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
				wrap(param_list), wrap(opt_extends), wrap(item_list)));
		}
		else idcmp(DeclClass)
		{
			#undef TYPE
			#define TYPE DeclClass
			osprintout(os, strappcom2(wrap(is_base), wrap(ident),
				wrap(param_list), wrap(opt_extends), wrap(item_list),
				wrap(is_signed), wrap(is_packed)));
		}
		else idcmp(DeclClass_DeclVar)
		{
			#undef TYPE
			#define TYPE DeclClass_DeclVar
			osprintout(os, strappcom2(wrap(ident_list),
				wrap(typename_or_modname), wrap(opt_expr_list),
				wrap_conv_2(acc_spec), wrap(is_static)));
		}
		else idcmp(DeclClsOrMxn_DeclEnum)
		{
			#undef TYPE
			#define TYPE DeclClsOrMxn_DeclEnum
			osprintout(os, strappcom2(wrap(ident),
				wrap(opt_typename_or_modname), wrap(ident_list),
				wrap_conv_2(acc_spec)));
		}
		else idcmp(DeclClsOrMxn_DeclClass)
		{
			#undef TYPE
			#define TYPE DeclClsOrMxn_DeclClass
			osprintout(os, strappcom2(wrap(is_base), wrap(ident),
				wrap(param_list), wrap(opt_extends), wrap(item_list),
				wrap(is_signed), wrap(is_packed), wrap_conv_2(acc_spec)));
		}
		else idcmp(DeclClsOrMxn_DeclMixin)
		{
			#undef TYPE
			#define TYPE DeclClsOrMxn_DeclMixin
			osprintout(os, strappcom2(wrap(is_base), wrap(ident),
				wrap(param_list), wrap(opt_extends), wrap(item_list),
				wrap_conv_2(acc_spec)));
		}
		else idcmp(DeclClsOrMxn_DeclSubprogFullDefn)
		{
			#undef TYPE
			#define TYPE DeclClsOrMxn_DeclSubprogFullDefn
			osprintout(os, strappcom2(wrap_conv_2(acc_spec),
				wrap_conv(kind), wrap(is_virtual), wrap(is_static),
				wrap(is_const), wrap(subprog)));
		}
		else idcmp(DeclClsOrMxn_DeclSubprogAbstract)
		{
			#undef TYPE
			#define TYPE DeclClsOrMxn_DeclSubprogAbstract
			osprintout(os, strappcom2(wrap_conv_2(acc_spec),
				wrap_conv(kind), wrap(is_const), wrap(header)));
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
		else idcmp(DeclFunc_Return, DeclFunc_Expr)
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
		else idcmp(IdentList)
		{
			#undef TYPE
			#define TYPE IdentList
		}


		osprintout(os, ")");
	}
	return os;
}
