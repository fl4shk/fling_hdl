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

#define wrap(a, b) \
	#a, "(", b, ")"

// "Node as"
#define ndas(type) \
	static_cast<type*>(node)

std::ostream& operator << (std::ostream& os, const BaseSptrList& list)
{
	for (const auto& item: list)
	{
		osprintout(os, item, ",\n");
	}
	return os;
}

std::ostream& operator << (std::ostream& os, Base* node)
{
	osprintout(os, node->id(), "(", wrap(fp, node->fp()), "\n");
	idcmp(Program)
	{
		osprintout(os, wrap("item_list", ndas(Program)->item_list));
	}
	else idcmp(DeclPackage)
	{
	}
	else idcmp(DeclParamList)
	{
	}
	else idcmp(DeclParamList_Item)
	{
	}

	osprintout(os, ")");
	return os;
}
