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

class ImportItem: public Base
{
public:		// variables
	BaseSptrList item_list;
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
	BaseSptr typenm;
	BaseSptrList opt_def_val_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclArgListItem, Base);
};

class StrAndNode: public Base
{
public:		// variables
	string str;
	BaseSptr node;
public:		// functions
	SHARED_FUNC_CONTENTS(StrAndNode, Base);
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

class Scope: public Base
{
public:		// variables
	BaseSptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(Scope, Base);
};
//--------

//--------
class Modinst: public Base
{
public:		// variables
	string ident;
	BaseSptr modnm, arg_list;
public:		// functions
	SHARED_FUNC_CONTENTS(Modinst, Base);
};
//--------

//--------
class GenIf: public Base
{
public:		// variables
	BaseSptr if_expr, if_scope;
	BaseSptrList opt_elif_expr_list, opt_elif_scope_list;
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

class GenCase: public Base
{
public:		// variables
	BaseSptrList expr_list;
	BaseSptr scope;
public:		// functions
	SHARED_FUNC_CONTENTS(GenCase, Base);
};

class GenDefault: public Base
{
public:		// variables
	BaseSptr scope;
public:		// functions
	SHARED_FUNC_CONTENTS(GenDefault, Base);
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
class DeclModuleBehavComb: public Base
{
public:		// variables
	BaseSptr scope;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclModuleBehavComb, Base);
};

class DeclModuleBehavSeq: public Base
{
public:		// variables
	BaseSptrList edge_item_list;
	BaseSptr scope;
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
	BaseSptr expr;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclModuleBehavSeqEdgeItem, Base);
};
//--------

//--------
class BehavIf: public GenIf
{
public:		// functions
	SHARED_FUNC_CONTENTS(BehavIf, GenIf);
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
	string ident;
	BaseSptr range, scope;
public:		// functions
	SHARED_FUNC_CONTENTS(BehavFor, Base);
};

class BehavWhile: public Base
{
public:		// variables
	BaseSptr range, scope;
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
	BaseSptr lhs;
	Kind kind;
	BaseSptr rhs;
public:		// functions
	SHARED_FUNC_CONTENTS(BehavAssign, Base);
};
//--------

//--------
class DeclStruct: public Base
{
public:		// variables
	string ident;
	BaseSptr opt_param_list, scope;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclStruct, Base);
};
//--------

//--------
class DeclEnum: public Base
{
public:		// variables
	string ident;
	BaseSptr opt_typenm;
	BaseSptrList item_list;
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
	BaseSptr opt_param_list, arg_list, opt_ret_typenm, scope;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclSubprog, Base);
};
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
	BaseSptr typenm, val;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclVarEtc, Base);
};

class WireAssign: public Base
{
public:		// variables
	BaseSptr lhs, rhs;
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
	BaseSptr rhs;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclAlias, Base);
};
//--------

//--------
class NamedScope: public Base
{
public:		// variables
	// Expected child type:  StrAndNode, where `node` is intended to be an
	// instance `ParamOrArgList`
	BaseSptrList item_list;
public:		// functions
	SHARED_FUNC_CONTENTS(NamedScope, Base);
};
//--------

//--------
class ExprBase: public Base
{
public:		// variables
	LogicValue val;
public:		// functions
	SHARED_FUNC_CONTENTS_2(ExprBase, Base);
};

class MuxExpr: public ExprBase
{
public:		// variables
	BaseSptr cond, when_true, when_false;
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
	BaseSptr left, right;
public:		// functions
	SHARED_FUNC_CONTENTS(BinopExpr, ExprBase);
};

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
	BaseSptr arg;
public:		// functions
	SHARED_FUNC_CONTENTS(UnopExpr, ExprBase);
};

class LitValExpr: public ExprBase
{
public:		// types
	enum class Kind
	{
		Number,
		HighImped,
		Unknown,
	};
public:		// variables
	Kind kind;
	BaseSptr opt_expr;
public:		// functions
	SHARED_FUNC_CONTENTS(LitValExpr, ExprBase);
};

//--------


} // namespace ast
#undef SHARED_FUNC_CONTENTS
#undef SHARED_FUNC_CONTENTS_2

#undef CONV_ENUM_CASE
#undef CONV_KIND_CASE
#undef CONV_ENUM_SWITCH

} // namespace fling_hdl

#endif		// src_ast_ast_node_classes_hpp
