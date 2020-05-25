#ifndef src_ast_ast_node_classes_hpp
#define src_ast_ast_node_classes_hpp

// src/ast/ast_node_classes.hpp

#include "../misc_includes.hpp"
#include "../liborangepower_src/cpp_magic.hpp"
#include "../logic_value_class.hpp"
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

#define BUILD_KIND_OPERATOR_LSHIFT(type) \
	inline std::ostream& operator << (std::ostream& os, \
		type::Kind to_conv) \
	{ \
		os << type::conv_kind(to_conv); \
		return os; \
	}
//--------

//--------
class Base;
using BaseUptr = unique_ptr<Base>;
using BaseUptrList = IndCircLinkList<BaseUptr>;
//using BaseWptr = weak_ptr<Base>;

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
	GEN_GETTER_AND_SETTER_BY_CON_REF(fp);
	GEN_GETTER_BY_VAL(level);

};
//--------

//--------
class Program: public Base
{
public:		// variables
	BaseUptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(Program, Base);
};
//--------

//--------
class DeclPackage: public Base
{
public:		// variables
	string ident;
	BaseUptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclPackage, Base);
};

class Import: public Base
{
public:		// variables
	BaseUptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(Import, Base);
};

class ImportItem: public Base
{
public:		// variables
	BaseUptrList item_list;
	bool ends_with_all = false;
public:		// functions
	SHARED_FUNC_CONTENTS(ImportItem, Base);
};
//--------

//--------
// This covers both declarations of parameter/argument lists and
// instantions of parameter/argument lists
class ParamOrArgList: public Base
{
public:		// variables
	BaseUptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(ParamOrArgList, Base);
};

class DeclParamSublistItem: public Base
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
	BaseUptr opt_typenm;

	// Default value list, the type of which is dependent upon the value of
	// `kind`.
	BaseUptrList opt_def_val;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclParamSublistItem, Base);
};
BUILD_KIND_OPERATOR_LSHIFT(DeclParamSublistItem);

class DeclArgSublistItem: public Base
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
	BaseUptr typenm;
	BaseUptrList opt_def_val;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclArgSublistItem, Base);
};
BUILD_KIND_OPERATOR_LSHIFT(DeclArgSublistItem);

class StrAndNode: public Base
{
public:		// variables
	string str;
	BaseUptr node;
public:		// functions
	SHARED_FUNC_CONTENTS(StrAndNode, Base);
};
//--------

//--------
class DeclModule: public Base
{
public:		// variables
	string ident;
	BaseUptr opt_param_list, arg_list, scope;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclModule, Base);
};

class Scope: public Base
{
public:		// variables
	BaseUptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(Scope, Base);
};
//--------

//--------
class Modinst: public Base
{
public:		// variables
	string ident;
	BaseUptr modnm, arg_list;
public:		// functions
	SHARED_FUNC_CONTENTS(Modinst, Base);
};
//--------

//--------
class GenIf: public Base
{
public:		// variables
	BaseUptr if_expr, if_scope;
	BaseUptrList opt_elif_list;
	BaseUptr opt_else_scope;
public:		// functions
	SHARED_FUNC_CONTENTS(GenIf, Base);
};
class GenElif: public Base
{
public:		// variables
	BaseUptr expr, scope;
public:		// variables
	SHARED_FUNC_CONTENTS(GenElif, Base);
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
	BaseUptr expr, opt_default;
	BaseUptrList opt_case_list;
public:		// functions
	SHARED_FUNC_CONTENTS(GenSwitchEtc, Base);
};
BUILD_KIND_OPERATOR_LSHIFT(GenSwitchEtc);

class GenCase: public Base
{
public:		// variables
	BaseUptrList expr_list;
	BaseUptr scope;
public:		// functions
	SHARED_FUNC_CONTENTS(GenCase, Base);
};

class GenDefault: public Base
{
public:		// variables
	BaseUptr scope;
public:		// functions
	SHARED_FUNC_CONTENTS(GenDefault, Base);
};

class GenFor: public Base
{
public:		// variables
	string label, iter_ident;
	BaseUptr range, scope;
public:		// functions
	SHARED_FUNC_CONTENTS(GenFor, Base);
};
//--------

//--------
class DeclModuleBehavComb: public Base
{
public:		// variables
	BaseUptr scope;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclModuleBehavComb, Base);
};

class DeclModuleBehavSeq: public Base
{
public:		// variables
	BaseUptrList edge_item_list;
	BaseUptr scope;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclModuleBehavSeq, Base);
};
class DeclModuleBehavSeqEdgeItem: public Base
{
public:		// types
	enum class Kind
	{
		Posedge,
		Negedge,
	};
	static string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			Posedge,
			Negedge);
	}
public:		// variables
	Kind kind;
	BaseUptr expr;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclModuleBehavSeqEdgeItem, Base);
};
BUILD_KIND_OPERATOR_LSHIFT(DeclModuleBehavSeqEdgeItem);
//--------

//--------
class BehavIf: public GenIf
{
public:		// functions
	SHARED_FUNC_CONTENTS(BehavIf, GenIf);
};
class BehavElif: public GenElif
{
public:		// functions
	SHARED_FUNC_CONTENTS(BehavElif, GenElif);
};

class BehavSwitchEtc: public GenSwitchEtc
{
public:		// functions
	SHARED_FUNC_CONTENTS(BehavSwitchEtc, GenSwitchEtc);
};

class BehavCase: public GenCase
{
public:		// functions
	SHARED_FUNC_CONTENTS(BehavCase, GenCase);
};

class BehavDefault: public GenDefault
{
public:		// functions
	SHARED_FUNC_CONTENTS(BehavDefault, GenDefault);
};

class BehavFor: public Base
{
public:		// variables
	string iter_ident;
	BaseUptr range, scope;
public:		// functions
	SHARED_FUNC_CONTENTS(BehavFor, Base);
};

class BehavWhile: public Base
{
public:		// variables
	BaseUptr expr, scope;
public:		// functions
	SHARED_FUNC_CONTENTS(BehavWhile, Base);
};
//--------

//--------
class BehavAssign: public Base
{
public:		// types
	enum class Kind
	{
		Blk,
		NonBlk,
	};
	static string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			Blk,
			NonBlk);
	}
public:		// variables
	BaseUptr lhs;
	Kind kind;
	BaseUptr rhs;
public:		// functions
	SHARED_FUNC_CONTENTS(BehavAssign, Base);
};
BUILD_KIND_OPERATOR_LSHIFT(BehavAssign);
//--------

//--------
class DeclStruct: public Base
{
public:		// variables
	string ident;
	BaseUptr opt_param_list, scope;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclStruct, Base);
};
//--------

//--------
class DeclEnum: public Base
{
public:		// variables
	string ident;
	BaseUptr opt_typenm;
	BaseUptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclEnum, Base);
};
//--------

//--------
class DeclSubprog: public Base
{
public:		// types
	enum class Kind
	{
		Func,
		Task
	};
	static string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			Func,
			Task);
	}
public:		// variables
	Kind kind;
	string ident;
	BaseUptr opt_param_list, arg_list, opt_ret_typenm, scope;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclSubprog, Base);
};
BUILD_KIND_OPERATOR_LSHIFT(DeclSubprog);
//--------

//--------
class DeclVarEtc: public Base
{
public:		// types
	enum class Kind
	{
		Const,
		Var,
		Wire,
	};
	static string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			Const,
			Var,
			Wire);
	}
public:		// variables
	Kind kind;
	string ident;
	BaseUptr typenm, val;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclVarEtc, Base);
};
BUILD_KIND_OPERATOR_LSHIFT(DeclVarEtc);

class WireAssign: public Base
{
public:		// variables
	BaseUptr lhs, rhs;
public:		// functions
	SHARED_FUNC_CONTENTS(WireAssign, Base);
};
//--------

//--------
class DeclAlias: public Base
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
			Task)
	}
public:		// variables
	string ident;
	Kind kind;
	BaseUptr rhs;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclAlias, Base);
};
BUILD_KIND_OPERATOR_LSHIFT(DeclAlias);
//--------

//--------
class NamedScope: public Base
{
public:		// variables
	// Expected child type:  StrAndNode, where `node` is intended to be an
	// instance of `ParamOrArgList`
	BaseUptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(NamedScope, Base);
};
//--------

//--------
class ExprBase: public Base
{
public:		// variables
	//LogicValue val;
	bool is_self_determined;
public:		// functions
	SHARED_FUNC_CONTENTS_2(ExprBase, Base);
};

class MuxExpr: public ExprBase
{
public:		// variables
	BaseUptr cond, when_true, when_false;
public:		// functions
	SHARED_FUNC_CONTENTS(MuxExpr, ExprBase);
};

class BinopExpr: public ExprBase
{
public:		// types
	enum class Kind
	{
		Logor,
		Logand,

		CmpEq,
		CmpNe,
		CaseCmpEq,
		CaseCmpNe,

		CmpLt,
		CmpGt,
		CmpLe,
		CmpGe,

		Plus,
		Minus,

		Mul,
		Div,
		Mod,

		Bitor,
		Bitnor,

		Bitand,
		Bitnand,

		Bitxor,
		Bitxnor,

		Lsl,
		Lsr,
		Asr,
	};
	static string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			Logor,
			Logand,

			CmpEq,
			CmpNe,
			CaseCmpEq,
			CaseCmpNe,

			CmpLt,
			CmpGt,
			CmpLe,
			CmpGe,

			Plus,
			Minus,

			Mul,
			Div,
			Mod,

			Bitor,
			Bitnor,

			Bitand,
			Bitnand,

			Bitxor,
			Bitxnor,

			Lsl,
			Lsr,
			Asr);
	}
public:		// variables
	Kind kind;
	BaseUptr left, right;
public:		// functions
	SHARED_FUNC_CONTENTS(BinopExpr, ExprBase);
};
BUILD_KIND_OPERATOR_LSHIFT(BinopExpr);

class UnopExpr: public ExprBase
{
public:		// types
	enum class Kind
	{
		Plus,
		Minus,

		Bitnot,
		Lognot,

		Bitor,
		Bitnor,

		Bitand,
		Bitnand,

		Bitxor,
		Bitxnor,
	};
	static string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			Plus,
			Minus,

			Bitnot,
			Lognot,

			Bitor,
			Bitnor,

			Bitand,
			Bitnand,

			Bitxor,
			Bitxnor);
	}
public:		// variables
	Kind kind;
	BaseUptr arg;
public:		// functions
	SHARED_FUNC_CONTENTS(UnopExpr, ExprBase);
};
BUILD_KIND_OPERATOR_LSHIFT(UnopExpr);

class LitValExpr: public ExprBase
{
public:		// types
	enum class Kind
	{
		Number,
		HighImped,
		Unknown,
	};
	static string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			Number,
			HighImped,
			Unknown);
	}
public:		// variables
	Kind kind;
	string opt_num_str;
	BigNum opt_num;
	BaseUptr opt_expr;
public:		// functions
	SHARED_FUNC_CONTENTS(LitValExpr, ExprBase);
};
BUILD_KIND_OPERATOR_LSHIFT(LitValExpr);

class CallDollarFuncExpr: public ExprBase
{
public:		// types
	enum class Kind
	{
		Size,
		Range,
		High,
		Low,

		Unsigned,
		Signed,
		IsUnsigned,
		IsSigned,

		Pow,
	};
	static string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			Size,
			Range,
			High,
			Low,

			Unsigned,
			Signed,
			IsUnsigned,
			IsSigned,

			Pow);
	}
public:		// variables
	Kind kind;
	BaseUptr arg, opt_second_arg;
public:		// functions
	SHARED_FUNC_CONTENTS(CallDollarFuncExpr, ExprBase);
};
BUILD_KIND_OPERATOR_LSHIFT(CallDollarFuncExpr);

class String: public Base
{
public:		// variables
	string data;
public:		// functions
	SHARED_FUNC_CONTENTS(String, Base);
};

class IdentExprSuffix: public Base
{
public:		// variables
	// Access members or array elements
	BaseUptrList acc_memb_or_arr_list;

	BaseUptr opt_range_etc;
	bool part_sel_is_minus_colon = false;
	BaseUptr opt_part_sel_right;
public:		// functions
	SHARED_FUNC_CONTENTS(IdentExprSuffix, Base);
};

class IdentExpr: public ExprBase
{
public:		// variables
	BaseUptrList prologue_list;
	BaseUptr opt_arg_list;

	BaseUptr suffix;
public:		// functions
	SHARED_FUNC_CONTENTS(IdentExpr, ExprBase);
};

class CatExpr: public ExprBase
{
public:		// variables
	BaseUptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(CatExpr, ExprBase);
};

class ReplExpr: public ExprBase
{
public:		// variables
	BaseUptr amount, to_repl;
public:		// functions
	SHARED_FUNC_CONTENTS(ReplExpr, ExprBase);
};

class SizedExpr: public ExprBase
{
public:		// variables
	BaseUptr lit_num, width;
public:		// functions
	SHARED_FUNC_CONTENTS(SizedExpr, ExprBase);
};
//--------

//--------
class NonDollarFuncRange: public Base
{
public:		// variables
	BaseUptr arg, opt_second_arg;
public:		// functions
	SHARED_FUNC_CONTENTS(NonDollarFuncRange, Base);
};
//--------

//--------
class Typenm: public Base
{
public:		// types
	enum class Kind
	{
		Cstm,
		Logic,
		SignedLogic,
		Integer,
	};
	static string conv_kind(Kind to_conv)
	{
		CONV_ENUM_SWITCH(CONV_KIND_CASE,
			Cstm,
			Logic,
			SignedLogic,
			Integer);
	}
public:		// variables
	Kind kind;
	BaseUptr opt_ident_expr, opt_vec_dim;
	BaseUptrList opt_arr_dim_list;
public:		// functions
	SHARED_FUNC_CONTENTS(Typenm, Base);
};
BUILD_KIND_OPERATOR_LSHIFT(Typenm);

class Modnm: public IdentExpr
{
public:		// functions
	SHARED_FUNC_CONTENTS(Modnm, IdentExpr);
};
//--------


} // namespace ast
#undef SHARED_FUNC_CONTENTS
#undef SHARED_FUNC_CONTENTS_2

#undef CONV_ENUM_CASE
#undef CONV_KIND_CASE
#undef CONV_ENUM_SWITCH

#undef BUILD_KIND_OPERATOR_LSHIFT

} // namespace fling_hdl

#endif		// src_ast_ast_node_classes_hpp
