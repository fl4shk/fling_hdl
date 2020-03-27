#ifndef src_ast_node_classes_hpp
#define src_ast_node_classes_hpp

// src/ast_node_classes.hpp

#include "misc_includes.hpp"
#include "expr_value_class.hpp"

#include "err_warn_class.hpp"

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

class Base;
using BaseSptr = shared_ptr<Base>;
using OptBaseSptr = optional<BaseSptr>;

class Base
{
public:		// types
	using Children = IndCircLinkList<BaseSptr>;

protected:		// variables
	ExprValue _val;
	ErrWarn _ew;
	Children _children;

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

	GEN_GETTER_AND_SETTER_BY_CON_REF(val);
	GEN_GETTER_AND_SETTER_BY_VAL(ew);

	template<typename... RemArgTypes>
	void append_children(shared_ptr<Base>&& first_child,
		RemArgTypes&&...  rem_children)
	{
		_children.push_back(move(first_child));

		if constexpr (sizeof...(rem_children) > 0)
		{
			append_children(rem_children...);
		}
	}
	GEN_GETTERS_BY_CON_REF_AND_REF(children);
};

class Program: public Base
{
public:		// functions
	SHARED_FUNC_CONTENTS(Program, Base);
};

class DeclPackage: public Base
{
public:		// variables
	string ident;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclPackage, Base);
};

class DeclParamList: public Base
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclParamList, Base);
};

class DeclParamList_Item: public Base
{
public:		// types
	class LocalVar final
	{
	public:		// variables
		BaseSptr typename_or_modname;
		OptBaseSptr opt_expr_list;
	public:		// functions
		inline LocalVar() = default;
		GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(LocalVar);
		inline ~LocalVar() = default;
	};

	class LocalTypename
	{
	public:		// variables
		OptBaseSptr opt_typename_or_modname_list;
	public:		// functions
		inline LocalTypename() = default;
		GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(LocalTypename);
		inline ~LocalTypename() = default;
	};
	class LocalModname final: public LocalTypename
	{
	public:		// variables
		OptBaseSptr opt_typename_or_modname_list;
	public:		// functions
		inline LocalModname() = default;
		GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(LocalModname);
		inline ~LocalModname() = default;
	};

public:		// variables
	BaseSptr ident_list;
	variant<LocalVar, LocalTypename, LocalModname> post_ident_list;

public:		// functions
	SHARED_FUNC_CONTENTS(DeclParamList_Item, Base);
};

class DeclArgList: public Base
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclArgList, Base);
};

// This covers both regular argument lists and those for `proc`s
class DeclArgList_Item: public Base
{
public:		// types
	enum class Kind
	{
		Input,
		Output,
		Inout,
		Interface,
	};
public:		// variables
	BaseSptr ident_list;
	Kind kind;
	BaseSptr typename_or_modname;
	OptBaseSptr opt_expr_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclArgList_Item, Base);
};

class InstParamList: public Base
{
public:		// variables
	bool named = false;
public:		// functions
	SHARED_FUNC_CONTENTS(InstParamList, Base);
};
class InstParamList_Pos_Item: public Base
{
public:		// variables
	BaseSptr item;
public:		// functions
	SHARED_FUNC_CONTENTS(InstParamList_Pos_Item, Base);
};
class InstParamList_Named_Item: public Base
{
public:		// variables
	string ident;
	BaseSptr item;
public:		// functions
	SHARED_FUNC_CONTENTS(InstParamList_Named_Item, Base);
};

class InstArgList: public Base
{
public:		// variables
	bool named = false;
public:		// functions
	SHARED_FUNC_CONTENTS(InstArgList, Base);
};

class InstArgList_Named_Item: public Base
{
public:		// variables
	string ident;
	BaseSptr expr;
public:		// functions
	SHARED_FUNC_CONTENTS(InstArgList_Named_Item, Base);
};

class DeclModule: public Base
{
public:		// variables
	string ident;
	OptBaseSptr opt_param_list;
	BaseSptr arg_list;
	OptBaseSptr opt_import_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclModule, Base);
};

class InstModule: public Base
{
public:		// variables
	string ident;
	BaseSptr typename_or_modname, arg_list;
public:		// functions
	SHARED_FUNC_CONTENTS(InstModule, Base);
};

class Gen_If: public Base
{
public:		// variables
	BaseSptr expr;
	IndCircLinkList<BaseSptr> list_elif;
	OptBaseSptr opt_else;
public:		// functions
	SHARED_FUNC_CONTENTS(Gen_If, Base);
};
class Gen_If_Elif: public Base
{
public:		// variables
	BaseSptr expr;
public:		// functions
	SHARED_FUNC_CONTENTS(Gen_If_Elif, Base);
};
class Gen_If_Else: public Base
{
public:		// functions
	SHARED_FUNC_CONTENTS(Gen_If_Else, Base);
};

class Gen_Switch: public Base
{
public:		// variables
	BaseSptr expr;
	IndCircLinkList<BaseSptr> list_case;
	OptBaseSptr opt_default;
public:		// functions
	SHARED_FUNC_CONTENTS(Gen_Switch, Base);
};
class Gen_Switch_Case: public Base
{
public:		// variables
	BaseSptr expr;
public:		// functions
	SHARED_FUNC_CONTENTS(Gen_Switch_Case, Base);
};
class Gen_Switch_Default: public Base
{
public:		// functions
	SHARED_FUNC_CONTENTS(Gen_Switch_Default, Base);
};

class Gen_For: public Base
{
public:		// variables
	string label, ident;
	BaseSptr expr;
public:		// functions
	SHARED_FUNC_CONTENTS(Gen_For, Base);
};

class ContAssign: public Base
{
public:		// variables
	BaseSptr left, right;
public:		// functions
	SHARED_FUNC_CONTENTS(ContAssign, Base);
};

class Behav: public Base
{
public:		// types
	enum class Kind
	{
		Initial,
		Comb,
		Seq,
	};
public:		// variables
	Kind kind;
	OptBaseSptr behav_seq_edge_list;
public:		// functions
	SHARED_FUNC_CONTENTS(Behav, Base);
};

class Behav_Seq_EdgeList: public Base
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Seq_EdgeList, Base);
};

class Behav_Seq_EdgeList_Item: public Base
{
public:		// types
	enum class Kind
	{
		Posedge,
		Negedge,
	};
public:		// variables
	Kind kind;
	BaseSptr expr;
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Seq_EdgeList_Item, Base);
};

class Behav_If: public Gen_If
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_If, Gen_If);
};
class Behav_If_Elif: public Gen_If_Elif
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_If_Elif, Gen_If_Elif);
};
class Behav_If_Else: public Gen_If_Else
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_If_Else, Gen_If_Else);
};

class Behav_Switch: public Gen_Switch
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Switch, Gen_Switch);
};
class Behav_Switchz: public Gen_Switch
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Switchz, Gen_Switch);
};
class Behav_SwitchOrSwitchz_Case: public Gen_Switch_Case
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_SwitchOrSwitchz_Case, Gen_Switch_Case);
};
class Behav_SwitchOrSwitchz_Default: public Gen_Switch_Default
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_SwitchOrSwitchz_Default,
		Gen_Switch_Default);
};

class Behav_For: public Base
{
public:		// variables
	string ident;
	BaseSptr expr;
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_For, Base);
};
class Behav_While: public Base
{
public:		// variables
	BaseSptr expr;
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_While, Base);
};

class Behav_NonBlkAssign: public ContAssign
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_NonBlkAssign, ContAssign);
};
class Behav_BlkAssign: public ContAssign
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_BlkAssign, ContAssign);
};

class DeclWire: public Base
{
public:		// variables
	BaseSptr ident_list, typename_or_modname;
	OptBaseSptr opt_expr_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclWire, Base);
};
class DeclVar: public DeclWire
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclVar, DeclWire);
};
class DeclConst: public Base
{
public:		// variables
	BaseSptr ident_list, typename_or_modname, expr_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclConst, Base);
};

class DeclEnum: public Base
{
public:		// variables
	string ident;
	OptBaseSptr opt_typename_or_modname;
	BaseSptr ident_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclEnum, Base);
};

class DeclMixin: public Base
{
public:		// variables
	bool is_base = false;
	string ident;
	BaseSptr param_list;
	OptBaseSptr opt_extends;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclMixin, Base);
};
class DeclClass: public DeclMixin
{
public:		// variables
	bool is_signed = false, is_packed = false;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClass, DeclMixin);
};

enum class AccSpec
{
	Pub,
	Prot,
	Priv,
};

class DeclClass_DeclVar: public DeclVar
{
public:		// variables
	AccSpec acc_spec = AccSpec::Pub;
	bool is_static = false;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClass_DeclVar, DeclVar);
};


class DeclClsOrMxn_DeclEnum: public DeclEnum
{
public:		// variables
	AccSpec acc_spec = AccSpec::Pub;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClsOrMxn_DeclEnum, DeclEnum);
};
class DeclClsOrMxn_DeclClass: public DeclClass
{
public:		// variables
	AccSpec acc_spec = AccSpec::Pub;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClsOrMxn_DeclClass, DeclClass);
};
class DeclClsOrMxn_DeclMixin: public DeclMixin
{
public:		// variables
	AccSpec acc_spec = AccSpec::Pub;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClsOrMxn_DeclMixin, DeclMixin);
};

class DeclClsOrMxn_DeclSubprogFullDefn: public Base
{
public:		// types
	enum class Kind
	{
		Func,
		Task,
		Proc,
	};
public:		// variables
	AccSpec acc_spec = AccSpec::Pub;
	Kind kind;
	bool is_virtual = false;
	bool is_static = false;
	bool is_const = false;
	BaseSptr subprog;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClsOrMxn_DeclSubprogFullDefn, Base);
};

class DeclClsOrMxn_DeclSubprogAbstract: public Base
{
public:		// types
	using Kind = typename DeclClsOrMxn_DeclSubprogFullDefn::Kind;
public:		// variables
	AccSpec acc_spec = AccSpec::Pub;
	Kind kind;
	bool is_const = false;
	BaseSptr header;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClsOrMxn_DeclSubprogAbstract, Base);
};

#undef SHARED_FUNC_CONTENTS

} // namespace ast

} // namespace fling_hdl

#endif		// src_ast_node_classes_hpp
