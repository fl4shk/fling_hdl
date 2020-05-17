#ifndef src_ast_ast_node_classes_hpp
#define src_ast_ast_node_classes_hpp

// src/ast/ast_node_classes.hpp

#include "../misc_includes.hpp"
#include "../liborangepower_src/cpp_magic.hpp"
#include "ast_visitor_class.hpp"

namespace fling_hdl
{

//class Symbol;

namespace ast
{

//--------
#define SHARED_FUNC_CONTENTS_2(name, base_name) \
	inline name() = default; \
	inline name(Base* s_parent, const FilePos& s_fp) \
		: base_name(s_parent, s_fp) \
	{ \
		if (_parent != nullptr) \
		{ \
			_level = _parent->level() + static_cast<size_t>(1); \
		} \
		else \
		{ \
			_level = 0; \
		} \
	} \
	GEN_MOVE_ONLY_CONSTRUCTORS_AND_ASSIGN(name); \
	virtual inline ~name() = default; \
	virtual inline string id() const \
	{ \
		return string(#name); \
	}
#define SHARED_FUNC_CONTENTS(name, base_name) \
	SHARED_FUNC_CONTENTS_2(name, base_name) \
	virtual void accept(AstVisitor* visitor) \
	{ \
		visitor->visit##name(this); \
	}

#define CONV_ENUM_CASE(type, which) \
	case type::which: \
		return #which;
#define CONV_KIND_CASE(which) \
	CONV_ENUM_CASE(Kind, which)
#define CONV_ENUM_SWITCH(CONV_CASE, ...) \
	switch (to_conv) \
	{ \
	/* -------- */ \
	EVAL(MAP(CONV_CASE, EMPTY, __VA_ARGS__)) \
	default: \
		return "Eek!"; \
	/* -------- */ \
	}
//--------

//--------
class Base;
using BaseSptr = shared_ptr<Base>;
using BaseSptrList = IndCircLinkList<BaseSptr>;
using BaseWptr = weak_ptr<Base>;

class Base
{
public:		// types
protected:		// variables
	Base* _parent = nullptr;
	FilePos _fp;
	size_t _level = 0;

//public:		// variables
//	Symbol* sym = nullptr;

public:		// functions
	inline Base() = default;
	inline Base(Base* s_parent, const FilePos& s_fp)
		: _parent(s_parent), _fp(s_fp)
	{
	}
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Base);
	virtual inline ~Base() = default;
	virtual inline string id() const
	{
		return string("Base");
	}
	virtual inline void accept(AstVisitor* visitor)
	{
		// Derived classes should fill this in
	}

	GEN_GETTER_BY_VAL(parent);
	GEN_GETTER_AND_SETTER_BY_VAL(fp);
	GEN_GETTER_BY_VAL(level);

};
//--------

//--------
class Program: public Base
{
public:		// variables
	BaseSptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(Program, Base);
};
//--------

//--------
class DeclPackage: public Base
{
public:		// variables
	string ident;
	BaseSptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclPackage, Base);
};

class Import: public Base
{
public:		// variables
	BaseSptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(Import, Base);
};
//--------

//--------
// This covers both declarations of parameter/argument lists and
// instantions of parameter/argument lists
class ParamOrArgList: public Base
{
public:		// variables
	BaseSptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(ParamOrArgList, Base);
};

class DeclParamListItem: public Base
{
public:		// types
	enum class Kind
	{
		Var,
		Range,

		Type,
		Module,

		Func,
		Task,
	};
	static string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			Var,
			Range,

			Type,
			Module,

			Func,
			Task);
	}
public:		// variables
	string ident;
	Kind kind;
	BaseSptr opt_typenm_or_modnm;

	// Default value list, the type of which is dependent upon the value of
	// `kind`.
	BaseSptrList opt_def_val_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclParamListItem, Base);
};

class DeclArgListItem: public Base
{
public:		// types
	// This is just the port direction
	enum class Kind
	{
		Input,
		Output,
		Inout,
	};
	static string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			Input,
			Output,
			Inout);
	}
public:		// variables
	string ident;
	Kind kind;
	BaseSptr typenm_or_modnm;
	BaseSptrList opt_def_val_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclArgListItem, Base);
};

class InstParamOrArgListNamedItem: public Base
{
public:		// variables
	string ident;
	BaseSptr item;
public:		// functions
	SHARED_FUNC_CONTENTS(InstParamOrArgListNamedItem, Base);
};
//--------

//--------
class DeclModule: public Base
{
public:		// variables
	string ident;
	BaseSptr opt_param_list, arg_list, scope;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclModule, Base);
};

class DeclModuleScope: public Base
{
public:		// variables
	BaseSptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclModuleScope, Base);
};
//--------

//--------
class Modinst: public Base
{
public:		// variables
	string ident;
	BaseSptr typnm_or_modnm, arg_list;
public:		// functions
	SHARED_FUNC_CONTENTS(Modinst, Base);
};
//--------

//--------
class GenIf: public Base
{
public:		// variables
	BaseSptr if_expr, if_scope;
	BaseSptrList opt_else_if_expr_list, opt_else_if_scope_list;
	BaseSptr opt_else_scope;
public:		// functions
	SHARED_FUNC_CONTENTS(GenIf, Base);
};

class GenSwitchEtc: public Base
{
public:		// types
	enum class Kind
	{
		Switch,
		Switchz,
	};
	static string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			Switch,
			Switchz);
	}
public:		// variables
	Kind kind;
	BaseSptr expr, opt_default;
	BaseSptrList opt_case_list;
public:		// functions
	SHARED_FUNC_CONTENTS(GenSwitchEtc, Base);
};

class GenSwitchEtcCase: public Base
{
public:		// variables
	BaseSptrList expr_list;
	BaseSptr scope;
public:		// functions
	SHARED_FUNC_CONTENTS(GenSwitchEtcCase, Base);
};

class GenSwitchEtcDefault: public Base
{
public:		// variables
	BaseSptr scope;
public:		// functions
	SHARED_FUNC_CONTENTS(GenSwitchEtcDefault, Base);
};

class GenFor: public Base
{
public:		// variables
	string label, iter_ident;
	BaseSptr range, scope;
public:		// functions
	SHARED_FUNC_CONTENTS(GenFor, Base);
};
//--------

//--------
//--------



} // namespace ast
#undef SHARED_FUNC_CONTENTS
#undef SHARED_FUNC_CONTENTS_2

#undef CONV_ENUM_CASE
#undef CONV_KIND_CASE
#undef CONV_ENUM_SWITCH

} // namespace fling_hdl

#endif		// src_ast_ast_node_classes_hpp
