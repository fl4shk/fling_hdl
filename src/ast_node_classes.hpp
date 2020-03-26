#ifndef src_ast_node_classes_hpp
#define src_ast_node_classes_hpp

// src/ast_node_classes.hpp

#include "misc_includes.hpp"
#include "expr_value_class.hpp"

#include "err_warn_class.hpp"

#include "list_of_ast_node_classes_define.hpp"

namespace fling_hdl
{

namespace ast
{

#define SHARED_FUNC_CONTENTS(name, base_name) \
	inline name() = default; \
	inline name(const ErrWarn& s_ew) \
		: base_name(s_ew) \
	{ \
	} \
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(name); \
	virtual inline ~name() = default; \
	virtual inline string id() const \
	{ \
		return string(#name); \
	}

#define X(name) \
	class name;
LIST_OF_AST_NODE_CLASSES(X)
#undef X

class Base
{
protected:		// variables
	ExprValue _val;
	ErrWarn _ew;
	//list<shared_ptr<Base>> _children;
public:		// functions
	inline Base() = default;
	inline Base(const ErrWarn& s_ew)
		: _ew(s_ew)
	{
	}
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Base);
	virtual inline ~Base() = default;
	virtual inline string id() const
	{
		return string("Base");
	}

	//template<typename FirstArgType, typename... RemArgTypes>
	//void append_children(FirstArgType&& first_child,
	//	RemArgTypes&&...  rem_children)
	//{
	//}
};

class Program: public Base
{
public:		// functions
	SHARED_FUNC_CONTENTS(Program, Base);
};

class DeclPackage: public Base
{
public:		// variables
public:		// functions
	SHARED_FUNC_CONTENTS(DeclPackage, Base);
};



#undef SHARED_FUNC_CONTENTS
#undef BASE_OF

} // namespace ast

} // namespace fling_hdl

#endif		// src_ast_node_classes_hpp
