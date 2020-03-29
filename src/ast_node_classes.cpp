#include "ast_node_classes.hpp"
#include "ast_visitor_class.hpp"

using namespace fling_hdl;
using namespace fling_hdl::ast;

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
#define idcmp(...) if (_inner_idcmp<__VA_ARGS__>(node))

#define wrap(a, b) \
	a, "(", b, ")"


std::ostream& operator << (std::ostream& os, Base* node)
{
	osprintout(os, node->id(), "(", wrap("fp", node->fp()));
	idcmp(Program)
	{
		
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

	osprintout(os, ")\n");
	return os;
}
