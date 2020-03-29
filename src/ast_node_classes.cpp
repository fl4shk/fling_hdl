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
			osprintout(os, strappcom2(wrap(item_list)));
		}
		else idcmp(DeclParamList_Item)
		{
			#undef TYPE
			#define TYPE DeclParamList_Item
			osprintout(os, strappcom2(wrap(ident_list)));

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

		osprintout(os, ")");
	}
	return os;
}
