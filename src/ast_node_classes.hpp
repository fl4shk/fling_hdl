#ifndef src_ast_node_classes_hpp
#define src_ast_node_classes_hpp

// src/ast_node_classes.hpp

#include "misc_includes.hpp"
#include "expr_value_class.hpp"

#include "file_pos_class.hpp"
#include "liborangepower_src/cpp_magic.hpp"
#include "ast_visitor_class.hpp"

namespace fling_hdl
{

namespace ast
{

#define SHARED_FUNC_CONTENTS_2(name, base_name) \
	inline name() = default; \
	inline name(Base* s_parent, const FilePos& s_fp) \
		: base_name(s_parent, s_fp) \
	{ \
		_level = _parent->level() + static_cast<size_t>(1); \
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

class Base;
using BaseSptr = shared_ptr<Base>;
using BaseSptrList = IndCircLinkList<BaseSptr>;

class Base
{
protected:		// variables
	Base* _parent = nullptr;
	FilePos _fp;
	size_t _level = 0;

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

class Program: public Base
{
public:		// variables
	BaseSptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(Program, Base);
};

class DeclPackage: public Base
{
public:		// variables
	string ident;
	BaseSptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclPackage, Base);
};

// This covers both declarations of parameter/argument lists and
// instantions of parameter/argument lists
class ParamOrArgList: public Base
{
public:		// variables
	BaseSptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(ParamOrArgList, Base);
};

class DeclParamList_Item: public Base
{
public:		// types
	enum class Kind
	{
		Var,
		Typename,
		Modname,
	};
	static string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			Var,
			Typename,
			Modname);
	}

public:		// variables
	BaseSptr ident_list;
	Kind kind;
	BaseSptr opt_typename_or_modname;
	BaseSptrList opt_expr_list, opt_typename_or_modname_list;

public:		// functions
	SHARED_FUNC_CONTENTS(DeclParamList_Item, Base);
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
	static inline string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			Input,
			Output,
			Inout,
			Interface)
	}
public:		// variables
	BaseSptr ident_list;
	Kind kind;
	BaseSptr typename_or_modname;
	BaseSptrList opt_expr_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclArgList_Item, Base);
};

class InstParamList_Named_Item: public Base
{
public:		// variables
	string ident;
	// Expr or TypenameOrModname
	BaseSptr item;
public:		// functions
	SHARED_FUNC_CONTENTS(InstParamList_Named_Item, Base);
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
	BaseSptr opt_param_list, arg_list, opt_import_list;
	BaseSptrList item_list;
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

class GenIf: public Base
{
public:		// variables
	BaseSptr cond;
	BaseSptrList item_list, elif_list;
	BaseSptr opt_else;
public:		// functions
	SHARED_FUNC_CONTENTS(GenIf, Base);
};
class GenIf_Elif: public Base
{
public:		// variables
	BaseSptr cond;
	BaseSptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(GenIf_Elif, Base);
};
class GenIf_Else: public Base
{
public:		// variables
	BaseSptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(GenIf_Else, Base);
};

class GenSwitch: public Base
{
public:		// variables
	BaseSptr cond;
	BaseSptrList opt_case_list;
	BaseSptr opt_default;
public:		// functions
	SHARED_FUNC_CONTENTS(GenSwitch, Base);
};
class GenSwitch_Case: public Base
{
public:		// variables
	BaseSptrList expr_list, item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(GenSwitch_Case, Base);
};
class GenSwitch_Default: public Base
{
public:		// variables
	BaseSptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(GenSwitch_Default, Base);
};

class GenFor: public Base
{
public:		// variables
	string label, ident;
	BaseSptr expr;
	BaseSptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(GenFor, Base);
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
	static string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			Initial,
			Comb,
			Seq);
	}
public:		// variables
	Kind kind;
	BaseSptrList opt_edge_list;
	BaseSptr scope;
public:		// functions
	SHARED_FUNC_CONTENTS(Behav, Base);
};

class Behav_SeqEdgeListItem: public Base
{
public:		// types
	enum class Kind
	{
		Posedge,
		Negedge,
	};
	static inline string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			Posedge,
			Negedge);
	}
public:		// variables
	Kind kind;
	BaseSptr expr;
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_SeqEdgeListItem, Base);
};

// This is used for behavioral blocks, functions, and tasks
class Behav_Scope: public Base
{
public:		// variables
	BaseSptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Scope, Base);
};

class If: public Base
{
public:		// variables
	BaseSptr cond, scope;
	BaseSptrList elif_list;
	BaseSptr opt_else;
public:		// functions
	SHARED_FUNC_CONTENTS(If, Base);
};
class If_Elif: public Base
{
public:		// variables
	BaseSptr cond, scope;
public:		// functions
	SHARED_FUNC_CONTENTS(If_Elif, Base);
};
class If_Else: public Base
{
public:		// variables
	BaseSptr scope;
public:		// functions
	SHARED_FUNC_CONTENTS(If_Else, Base);
};

class Switch: public GenSwitch
{
public:		// functions
	SHARED_FUNC_CONTENTS(Switch, GenSwitch);
};
class Switchz: public Switch
{
public:		// functions
	SHARED_FUNC_CONTENTS(Switchz, Switch);
};
class SwitchOrSwitchz_Case: public Base
{
public:		// variables
	BaseSptrList expr_list;
	BaseSptr scope;
public:		// functions
	SHARED_FUNC_CONTENTS(SwitchOrSwitchz_Case, Base);
};
class SwitchOrSwitchz_Default: public Base
{
public:		// variables
	BaseSptr scope;
public:		// functions
	SHARED_FUNC_CONTENTS(SwitchOrSwitchz_Default, Base);
};

class For: public Base
{
public:		// variables
	string ident;
	BaseSptr expr, scope;
public:		// functions
	SHARED_FUNC_CONTENTS(For, Base);
};
class While: public Base
{
public:		// variables
	BaseSptr expr, scope;
public:		// functions
	SHARED_FUNC_CONTENTS(While, Base);
};

class NonBlkAssign: public ContAssign
{
public:		// functions
	SHARED_FUNC_CONTENTS(NonBlkAssign, ContAssign);
};
class BlkAssign: public ContAssign
{
public:		// functions
	SHARED_FUNC_CONTENTS(BlkAssign, ContAssign);
};

class DeclWire: public Base
{
public:		// variables
	BaseSptr ident_list, typename_or_modname;
	BaseSptrList opt_expr_list;
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
	BaseSptr ident_list, typename_or_modname;
	BaseSptrList expr_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclConst, Base);
};

class DeclEnum: public Base
{
public:		// variables
	string ident;
	BaseSptr opt_typename_or_modname, ident_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclEnum, Base);
};

class DeclMixin: public Base
{
public:		// variables
	bool is_base = false;
	string ident;
	BaseSptr opt_param_list;
	BaseSptrList opt_extends, item_list;
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
inline string conv_acc_spec(AccSpec to_conv)
{
	#define CONV_ACC_SPEC_CASE(which) \
		CONV_ENUM_CASE(AccSpec, which)
	CONV_ENUM_SWITCH(CONV_ACC_SPEC_CASE,
		Pub,
		Prot,
		Priv);
	#undef CONV_ACC_SPEC_CASE
}

class DeclClsOrMxn_ItemBase: public Base
{
public:		// variables
	AccSpec acc_spec = AccSpec::Pub;
public:		// functions
	SHARED_FUNC_CONTENTS_2(DeclClsOrMxn_ItemBase, Base);
};

class DeclClass_DeclVar: public DeclClsOrMxn_ItemBase
{
public:		// variables
	bool is_static = false;
	BaseSptr decl_var;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClass_DeclVar, DeclClsOrMxn_ItemBase);
};


class DeclClsOrMxn_DeclType: public DeclClsOrMxn_ItemBase
{
public:		// variables
	BaseSptr decl_type;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClsOrMxn_DeclType, DeclClsOrMxn_ItemBase);
};

class DeclClsOrMxn_DeclAliasOrConst: public DeclClsOrMxn_ItemBase
{
public:		// variables
	bool is_static = false;
	BaseSptr decl_alias_or_const;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClsOrMxn_DeclAliasOrConst,
		DeclClsOrMxn_ItemBase);
};

class DeclClsOrMxn_DeclSubprogFullDefn: public DeclClsOrMxn_ItemBase
{
public:		// variables
	bool is_virtual = false, is_static = false, is_const = false;
	BaseSptr subprog;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClsOrMxn_DeclSubprogFullDefn,
		DeclClsOrMxn_ItemBase);
};

class DeclClsOrMxn_DeclSubprogAbstract: public DeclClsOrMxn_ItemBase
{
public:		// variables
	bool is_const = false;
	BaseSptr header;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClsOrMxn_DeclSubprogAbstract,
		DeclClsOrMxn_ItemBase);
};

class DeclFunc: public Base
{
public:		// variables
	BaseSptr header, scope;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclFunc, Base);
};

class DeclFunc_Header: public Base
{
public:		// variables
	string ident;
	BaseSptr opt_param_list, arg_list, return_typename;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclFunc_Header, Base);
};

class DeclFunc_Return: public Base
{
public:		// variables
	BaseSptr expr;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclFunc_Return, Base);
};

class DeclTask: public DeclFunc
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclTask, DeclFunc);
};

class DeclTask_Header: public Base
{
public:		// variables
	string ident;
	BaseSptr opt_param_list, arg_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclTask_Header, Base);
};

class DeclProc: public Base
{
public:		// variables
	BaseSptr header;
	BaseSptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclProc, Base);
};

class DeclProc_Header: public DeclTask_Header
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclProc_Header, DeclTask_Header);
};

class DeclAlias_Value: public Base
{
public:		// variables
	BaseSptr ident_list, typename_or_modname;
	BaseSptrList expr_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclAlias_Value, Base);
};

class DeclAlias_Type: public Base
{
public:		// variables
	BaseSptr ident_list;
	BaseSptrList typename_or_modname_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclAlias_Type, Base);
};

class DeclAlias_Module: public DeclAlias_Type
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclAlias_Module, DeclAlias_Type);
};

class IdentList: public Base
{
public:		// variables
	IndCircLinkList<string> data;
public:		// functions
	SHARED_FUNC_CONTENTS(IdentList, Base);
};
class ScopedIdent: public IdentList
{
public:		// functions
	SHARED_FUNC_CONTENTS(ScopedIdent, IdentList);
};
class ImportList: public Base
{
public:		// variables
	BaseSptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(ImportList, Base);
};
class TypenameOrModname_Special: public Base
{
public:		// types
	enum class Kind
	{
		SelfT,
		RetT,
	};
	static string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			SelfT,
			RetT)
	}
public:		// variables
	Kind kind;
public:		// variables
	SHARED_FUNC_CONTENTS(TypenameOrModname_Special, Base);
};


class TypenameOrModname_Cstm: public Base
{
public:		// variables
	BaseSptrList item_list, arr_dim_list;
public:		// functions
	SHARED_FUNC_CONTENTS(TypenameOrModname_Cstm, Base);
};

class TypenameOrModname_Typeof: public TypenameOrModname_Cstm
{
public:		// variables
	BaseSptr expr;
public:		// functions
	SHARED_FUNC_CONTENTS(TypenameOrModname_Typeof, TypenameOrModname_Cstm);
};

class TypenameOrModname_Cstm_Item: public Base
{
public:		// variables
	string ident;
	BaseSptr opt_param_list;
public:		// functions
	SHARED_FUNC_CONTENTS(TypenameOrModname_Cstm_Item, Base);
};

class TypenameOrModname_Builtin: public Base
{
public:		// types
	enum class Kind
	{
		Logic,
		SignedLogic,

		Integer,
		SizeT,
		Range,
		//Float,
		String,

		U8,
		I8,
		U16,
		I16,
		U32,
		I32,
		U64,
		I64,
		U128,
		I128,

		Auto,
		Void,
	};
	static string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			Logic,
			SignedLogic,

			Integer,
			SizeT,
			Range,
			//Float,
			String,

			U8,
			I8,
			U16,
			I16,
			U32,
			I32,
			U64,
			I64,
			U128,
			I128,

			Auto,
			Void);
	}
public:		// variables
	Kind kind;
	BaseSptr opt_param_list;
	BaseSptrList arr_dim_list;
public:		// functions
	SHARED_FUNC_CONTENTS(TypenameOrModname_Builtin, Base);
};

class ExprMux: public Base
{
public:		// variables
	BaseSptr cond, when_true, when_false;
public:		// functions
	SHARED_FUNC_CONTENTS(ExprMux, Base);
};

class ExprUnopBase: public Base
{
public:		// variables
	// More like, we need to feed *our* childrens
	BaseSptr to_feed;
public:		// functions
	SHARED_FUNC_CONTENTS_2(ExprUnopBase, Base);
};

class ExprBinopBase: public Base
{
public:		// variables
	BaseSptr left, right;
public:		// functions
	SHARED_FUNC_CONTENTS_2(ExprBinopBase, Base);
};

class ExprLogOr: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprLogOr, ExprBinopBase);
};
class ExprLogAnd: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprLogAnd, ExprBinopBase);
};
class ExprBinopBitOr: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprBinopBitOr, ExprBinopBase);
};
class ExprBinopBitNor: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprBinopBitNor, ExprBinopBase);
};
class ExprBinopBitAnd: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprBinopBitAnd, ExprBinopBase);
};
class ExprBinopBitNand: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprBinopBitNand, ExprBinopBase);
};
class ExprBinopBitXor: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprBinopBitXor, ExprBinopBase);
};
class ExprBinopBitXnor: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprBinopBitXnor, ExprBinopBase);
};
class ExprCmpEq: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprCmpEq, ExprBinopBase);
};
class ExprCmpNe: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprCmpNe, ExprBinopBase);
};
class ExprCaseCmpEq: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprCaseCmpEq, ExprBinopBase);
};
class ExprCaseCmpNe: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprCaseCmpNe, ExprBinopBase);
};
class ExprCmpLt: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprCmpLt, ExprBinopBase);
};
class ExprCmpLe: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprCmpLe, ExprBinopBase);
};
class ExprCmpGt: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprCmpGt, ExprBinopBase);
};
class ExprCmpGe: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprCmpGe, ExprBinopBase);
};

class ExprBitLsl: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprBitLsl, ExprBinopBase);
};
class ExprBitLsr: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprBitLsr, ExprBinopBase);
};
class ExprBitAsr: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprBitAsr, ExprBinopBase);
};

class ExprBinopPlus: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprBinopPlus, ExprBinopBase);
};
class ExprBinopMinus: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprBinopMinus, ExprBinopBase);
};

class ExprMul: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprMul, ExprBinopBase);
};
class ExprDiv: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprDiv, ExprBinopBase);
};
class ExprMod: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprMod, ExprBinopBase);
};

class ExprUnopPlus: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprUnopPlus, ExprUnopBase);
};
class ExprUnopMinus: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprUnopMinus, ExprUnopBase);
};
class ExprLogNot: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprLogNot, ExprUnopBase);
};
class ExprBitNot: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprBitNot, ExprUnopBase);
};
class ExprUnopBitOr: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprUnopBitOr, ExprUnopBase);
};
class ExprUnopBitNor: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprUnopBitNor, ExprUnopBase);
};
class ExprUnopBitAnd: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprUnopBitAnd, ExprUnopBase);
};
class ExprUnopBitNand: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprUnopBitNand, ExprUnopBase);
};
class ExprUnopBitXor: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprUnopBitXor, ExprUnopBase);
};
class ExprUnopBitXnor: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprUnopBitXnor, ExprUnopBase);
};

class ExprLiteral: public Base
{
public:		// types
	enum class Kind
	{
		DecNum,
		HexNum,
		OctNum,
		BinNum,
		//Float,
		String,
		HighZ,
		UnkX,
	};
	static string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			DecNum,
			HexNum,
			OctNum,
			BinNum,
			//Float,
			String,
			HighZ,
			UnkX)
	}

public:		// variables
	Kind kind;
	string text;
	BaseSptr opt_size;
public:		// functions
	SHARED_FUNC_CONTENTS(ExprLiteral, Base);
};
class ExprSized: public Base
{
public:		// variables
	BaseSptr dst_size, src;
public:		// functions
	SHARED_FUNC_CONTENTS(ExprSized, Base);
};

class ExprRange: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprRange, ExprBinopBase);
};

class ExprCat: public Base
{
public:		// variables
	BaseSptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(ExprCat, Base);
};

class ExprRepl: public Base
{
public:		// variables
	BaseSptr amount, to_repl;
public:		// functions
	SHARED_FUNC_CONTENTS(ExprRepl, Base);
};

class ExprDollarSigned: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprDollarSigned, ExprUnopBase);
};
class ExprDollarUnsigned: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprDollarUnsigned, ExprUnopBase);
};
class ExprDollarClog2: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprDollarClog2, ExprUnopBase);
};
class ExprDollarIsvtype: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprDollarIsvtype, ExprUnopBase);
};
class ExprDollarPow: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprDollarPow, ExprBinopBase);
};


class ExprIdentEtc: public Base
{
public:		// types
	enum class SuffKind
	{
		None,
		DollarSize,
		DollarRange,
		DollarHigh,
		DollarLow,
	};
	static string conv_suff_kind(SuffKind to_conv)
	{
		#define CONV_SUFF_KIND_CASE(which) \
			CONV_ENUM_CASE(SuffKind, which) 
		CONV_ENUM_SWITCH(CONV_SUFF_KIND_CASE,
			None,
			DollarSize,
			DollarRange,
			DollarHigh,
			DollarLow);
		#undef CONV_SUFF_KIND_CASE
	}
public:		// variables
	BaseSptr opt_typename_or_modname, first_item;
	BaseSptrList opt_later_item_list;
	SuffKind suff_kind = SuffKind::None;
public:		// functions
	SHARED_FUNC_CONTENTS(ExprIdentEtc, Base);
};

class ExprIdentEtc_FirstItem: public Base
{
public:		// types
	enum class Kind
	{
		Self,
		NonSelf,
	};
	static string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			Self,
			NonSelf);
	}
public:		// variables
	Kind kind;
	BaseSptr opt_non_self_item;
public:		// functions
	SHARED_FUNC_CONTENTS(ExprIdentEtc_FirstItem, Base);
};

class ExprIdentEtc_NonSelfItem: public Base
{
public:		// variables
	string ident;
	BaseSptr opt_param_list, opt_arg_list;
	BaseSptrList end_item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(ExprIdentEtc_NonSelfItem, Base);
};

class ExprIdentEtc_ItemEnd: public Base
{
public:		// types
	enum class Kind
	{
		ArrIndex,
		DollarFirstel,
		DollarLastel,
	};
	static string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			ArrIndex,
			DollarFirstel,
			DollarLastel);
	}
public:		// variables
	Kind kind;
	BaseSptr opt_index;
public:		// functions
	SHARED_FUNC_CONTENTS(ExprIdentEtc_ItemEnd, Base);
};

class ExprIdentEtc_ItemEndIndex: public Base
{
public:		// types
	enum class Kind
	{
		Single,
		PlusColon,
		MinusColon
	};
	static string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			Single,
			PlusColon,
			MinusColon);
	}
public:		// variables
	Kind kind = Kind::Single;
	BaseSptr left, opt_right;
public:		// functions
	SHARED_FUNC_CONTENTS(ExprIdentEtc_ItemEndIndex, Base);
};

// Call a member function via `a plus b` instead of `a.plus(b)`
class ExprCallSubprog_PseudoOper: public ExprBinopBase
{
public:		// variables
	string ident;
	BaseSptr opt_param_list; 
public:		// functions
	SHARED_FUNC_CONTENTS(ExprCallSubprog_PseudoOper, ExprBinopBase);
};

#undef SHARED_FUNC_CONTENTS
#undef CONV_ENUM_CASE
#undef CONV_KIND_CASE
#undef CONV_ENUM_SWITCH


} // namespace ast

} // namespace fling_hdl

std::ostream& operator << (std::ostream& os, fling_hdl::ast::Base* node);

inline std::ostream& operator << (std::ostream& os,
	fling_hdl::ast::BaseSptr& node)
{
	os << node.get();
	return os;
}

#endif		// src_ast_node_classes_hpp
