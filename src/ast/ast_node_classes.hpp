// This file is part of Fling HDL.
//
// Copyright 2020 Andrew Clark (FL4SHK)
//
// Fling HDL is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Fling HDL is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Fling HDL.  If not, see <https://www.gnu.org/licenses/>.

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
#define CTAGS_MEMB_VAR(type, name) \
	type, name

#define MEMB_VAR(type, name) \
	type name
#define COPY_MEMB_VAR(type, name) \
	name = casted_to_copy->name
#define INNER_WRAP_DATA(type, name) \
	ret += sconcat(#name, ":  ", name) 

#define PLUS_RAW_NEWLINE() + "\\n";

#define DATA(...) \
	IF (HAS_ARGS(__VA_ARGS__)) \
	( \
		EVAL(MAP_PAIRS(MEMB_VAR, SEMICOLON, __VA_ARGS__)); \
		\
		virtual inline void copy_data(Base* to_copy) \
		{ \
			Self* casted_to_copy = static_cast<Self*>(to_copy); \
			EVAL(MAP_PAIRS(COPY_MEMB_VAR, SEMICOLON, __VA_ARGS__)); \
		} \
		virtual inline string wrap_data() const \
		{ \
			string ret; \
			EVAL(MAP_PAIRS(INNER_WRAP_DATA, PLUS_RAW_NEWLINE, \
				__VA_ARGS__)); \
			return ret; \
		} \
	)

#define INNER_ACCEPT_CHILDREN(type, name) \
	_inner_accept_children(visitor, #name, name)
#define INNER_DUP(type, name) \
	_inner_dup(ret_ptr, ret_ptr->name, name)

#define CHILDREN(...) \
	IF (HAS_ARGS(__VA_ARGS__)) \
	( \
		EVAL(MAP_PAIRS(MEMB_VAR, SEMICOLON, __VA_ARGS__)); \
		\
		virtual inline void accept_children(AstVisitor* visitor) \
		{ \
			EVAL(MAP_PAIRS(INNER_ACCEPT_CHILDREN, SEMICOLON, \
				__VA_ARGS__)); \
		} \
		\
		virtual inline BaseUptr dup(Base* s_parent) const \
		{ \
			Self* ret_ptr = new Self(s_parent, fp()); \
			\
			EVAL(MAP_PAIRS(INNER_DUP, SEMICOLON, __VA_ARGS__)); \
			\
			return BaseUptr(ret_ptr); \
		} \
	)


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
	} \
	using Self = name;
#define SHARED_CONTENTS(name, base_name) \
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

	// Derived classes should fill these in
	virtual inline void accept(AstVisitor* visitor)
	{
	}
	virtual inline void copy_data(BaseUptr& to_copy)
	{
	}
	virtual inline string wrap_data() const
	{
		return "";
	}
	virtual inline BaseUptr dup(Base* s_parent) const
	{
		return BaseUptr(nullptr);
	}
	virtual inline void accept_children(AstVisitor* visitor)
	{
	}
	virtual inline void accept_children(AstVisitor* visitor,
		const BaseUptr& other)
	{
	}

	GEN_GETTER_BY_VAL(parent);
	GEN_GETTER_BY_CON_REF(fp);
	GEN_GETTER_BY_VAL(level);

protected:		// functions
	static inline void _inner_accept_children(AstVisitor* visitor,
		const string& memb_name, BaseUptr& child)
	{
		if (child)
		{
			visitor->set_memb_name(memb_name);
			child->accept(visitor);
		}
	}
	static inline void _inner_accept_children(AstVisitor* visitor,
		const string& memb_name, BaseUptrList& child_list)
	{
		size_t i = 0;
		for (const auto& child: child_list)
		{
			visitor->set_memb_name(sconcat(memb_name, "[", i, "]"));
			child.data->accept(visitor);
			++i;
		}
	}

	static inline void _inner_dup(Base* s_parent, BaseUptr& item,
		const BaseUptr& other_item)
	{
		if (other_item)
		{
			item = other_item->dup(s_parent);
		}
	}
	static inline void _inner_dup(Base* s_parent, BaseUptrList& item_list,
		const BaseUptrList& other_item_list)
	{
		for (const auto& other_item: other_item_list)
		{
			item_list.push_back(other_item.data->dup(s_parent));
		}
	}
};
//--------

//--------
class Program: public Base
{
public:		// variables
	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptrList, item_list)
	);
public:		// functions
	SHARED_CONTENTS(Program, Base);
};
//--------

//--------
class DeclPackage: public Base
{
public:		// variables
	DATA
	(
		CTAGS_MEMB_VAR(string, ident)
	);

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptrList, item_list)
	)
public:		// functions
	SHARED_CONTENTS(DeclPackage, Base);
};

class Import: public Base
{
public:		// variables
	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptrList, item_list)
	);
public:		// functions
	SHARED_CONTENTS(Import, Base);
};

class ImportItem: public Base
{
public:		// variables
	DATA
	(
		CTAGS_MEMB_VAR(bool, ends_with_all)
	);

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptrList, item_list)
	);
public:		// functions
	SHARED_CONTENTS(ImportItem, Base);
};
//--------

//--------
// This covers both declarations of parameter/argument lists and
// instantions of parameter/argument lists
class ParamOrArgList: public Base
{
public:		// variables
	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptrList, item_list)
	);
public:		// functions
	SHARED_CONTENTS(ParamOrArgList, Base);
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
	DATA
	(
		CTAGS_MEMB_VAR(string, ident),
		CTAGS_MEMB_VAR(Kind, kind)
	);

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, opt_typenm),

		// Default value list, the type of which is dependent upon the
		// value of `kind`.
		CTAGS_MEMB_VAR(BaseUptrList, opt_def_val)
	);
public:		// functions
	SHARED_CONTENTS(DeclParamSublistItem, Base);
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
	DATA
	(
		CTAGS_MEMB_VAR(string, ident),
		CTAGS_MEMB_VAR(Kind, kind)
	);

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, typenm),
		CTAGS_MEMB_VAR(BaseUptrList, opt_def_val)
	);
public:		// functions
	SHARED_CONTENTS(DeclArgSublistItem, Base);
};
BUILD_KIND_OPERATOR_LSHIFT(DeclArgSublistItem);

class StrAndNode: public Base
{
public:		// variables
	DATA
	(
		CTAGS_MEMB_VAR(string, str)
	);

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, node)
	);
public:		// functions
	SHARED_CONTENTS(StrAndNode, Base);
};
//--------

//--------
class DeclModule: public Base
{
public:		// variables
	DATA
	(
		CTAGS_MEMB_VAR(string, ident)
	);

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, opt_param_list),
		CTAGS_MEMB_VAR(BaseUptr, arg_list),
		CTAGS_MEMB_VAR(BaseUptr, scope)
	);
public:		// functions
	SHARED_CONTENTS(DeclModule, Base);
};

class Scope: public Base
{
public:		// variables
	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptrList, item_list)
	);
public:		// functions
	SHARED_CONTENTS(Scope, Base);
};
//--------

//--------
class Modinst: public Base
{
public:		// variables
	DATA
	(
		CTAGS_MEMB_VAR(string, ident)
	);

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, modnm),
		CTAGS_MEMB_VAR(BaseUptr, arg_list)
	);
public:		// functions
	SHARED_CONTENTS(Modinst, Base);
};
//--------

//--------
class GenIf: public Base
{
public:		// variables
	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, if_expr),
		CTAGS_MEMB_VAR(BaseUptr, if_scope),
		CTAGS_MEMB_VAR(BaseUptrList, opt_elif_list),
		CTAGS_MEMB_VAR(BaseUptr, opt_else_scope)
	);
public:		// functions
	SHARED_CONTENTS(GenIf, Base);
};
class GenElif: public Base
{
public:		// variables
	BaseUptr expr, scope;
public:		// variables
	SHARED_CONTENTS(GenElif, Base);
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
	DATA
	(
		CTAGS_MEMB_VAR(Kind, kind)
	)

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, expr),
		CTAGS_MEMB_VAR(BaseUptr, opt_default),
		CTAGS_MEMB_VAR(BaseUptrList, opt_case_list)
	);
public:		// functions
	SHARED_CONTENTS(GenSwitchEtc, Base);
};
BUILD_KIND_OPERATOR_LSHIFT(GenSwitchEtc);

class GenCase: public Base
{
public:		// variables
	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptrList, expr_list),
		CTAGS_MEMB_VAR(BaseUptr, scope)
	)
public:		// functions
	SHARED_CONTENTS(GenCase, Base);
};

class GenDefault: public Base
{
public:		// variables
	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, scope)
	);
public:		// functions
	SHARED_CONTENTS(GenDefault, Base);
};

class GenFor: public Base
{
public:		// variables
	DATA
	(
		CTAGS_MEMB_VAR(string, label),
		CTAGS_MEMB_VAR(string, iter_ident)
	);

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, range),
		CTAGS_MEMB_VAR(BaseUptr, scope)
	);
public:		// functions
	SHARED_CONTENTS(GenFor, Base);
};
//--------

//--------
class DeclModuleBehavComb: public Base
{
public:		// variables
	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, scope)
	);
public:		// functions
	SHARED_CONTENTS(DeclModuleBehavComb, Base);
};

class DeclModuleBehavSeq: public Base
{
public:		// variables
	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptrList, edge_item_list),
		CTAGS_MEMB_VAR(BaseUptr, scope)
	);
public:		// functions
	SHARED_CONTENTS(DeclModuleBehavSeq, Base);
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
	DATA
	(
		CTAGS_MEMB_VAR(Kind, kind)
	);

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, expr)
	);
public:		// functions
	SHARED_CONTENTS(DeclModuleBehavSeqEdgeItem, Base);
};
BUILD_KIND_OPERATOR_LSHIFT(DeclModuleBehavSeqEdgeItem);
//--------

//--------
class BehavIf: public GenIf
{
public:		// functions
	SHARED_CONTENTS(BehavIf, GenIf);
};
class BehavElif: public GenElif
{
public:		// functions
	SHARED_CONTENTS(BehavElif, GenElif);
};

class BehavSwitchEtc: public GenSwitchEtc
{
public:		// functions
	SHARED_CONTENTS(BehavSwitchEtc, GenSwitchEtc);
};

class BehavCase: public GenCase
{
public:		// functions
	SHARED_CONTENTS(BehavCase, GenCase);
};

class BehavDefault: public GenDefault
{
public:		// functions
	SHARED_CONTENTS(BehavDefault, GenDefault);
};

class BehavFor: public Base
{
public:		// variables
	DATA
	(
		CTAGS_MEMB_VAR(string, iter_ident)
	);

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, range),
		CTAGS_MEMB_VAR(BaseUptr, scope)
	);
public:		// functions
	SHARED_CONTENTS(BehavFor, Base);
};

class BehavWhile: public Base
{
public:		// variables
	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, expr),
		CTAGS_MEMB_VAR(BaseUptr, scope)
	);
public:		// functions
	SHARED_CONTENTS(BehavWhile, Base);
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
	DATA
	(
		CTAGS_MEMB_VAR(Kind, kind)
	);

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, lhs),
		CTAGS_MEMB_VAR(BaseUptr, rhs)
	);
public:		// functions
	SHARED_CONTENTS(BehavAssign, Base);
};
BUILD_KIND_OPERATOR_LSHIFT(BehavAssign);
//--------

//--------
class DeclStruct: public Base
{
public:		// variables
	DATA
	(
		CTAGS_MEMB_VAR(string, ident)
	);

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, opt_param_list),
		CTAGS_MEMB_VAR(BaseUptr, scope)
	);
public:		// functions
	SHARED_CONTENTS(DeclStruct, Base);
};
//--------

//--------
class DeclEnum: public Base
{
public:		// variables
	DATA
	(
		CTAGS_MEMB_VAR(string, ident)
	);

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, opt_typenm),
		CTAGS_MEMB_VAR(BaseUptrList, item_list)
	);
public:		// functions
	SHARED_CONTENTS(DeclEnum, Base);
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
	DATA
	(
		CTAGS_MEMB_VAR(Kind, kind),
		CTAGS_MEMB_VAR(string, ident)
	);

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, opt_param_list),
		CTAGS_MEMB_VAR(BaseUptr, arg_list),
		CTAGS_MEMB_VAR(BaseUptr, opt_ret_typenm),
		CTAGS_MEMB_VAR(BaseUptr, scope)
	);
public:		// functions
	SHARED_CONTENTS(DeclSubprog, Base);
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
	DATA
	(
		CTAGS_MEMB_VAR(Kind, kind),
		CTAGS_MEMB_VAR(string, ident)
	);

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, typenm),
		CTAGS_MEMB_VAR(BaseUptr, val)
	);
public:		// functions
	SHARED_CONTENTS(DeclVarEtc, Base);
};
BUILD_KIND_OPERATOR_LSHIFT(DeclVarEtc);

class WireAssign: public Base
{
public:		// variables

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, lhs),
		CTAGS_MEMB_VAR(BaseUptr, rhs)
	);
public:		// functions
	SHARED_CONTENTS(WireAssign, Base);
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
	DATA
	(
		CTAGS_MEMB_VAR(string, ident),
		CTAGS_MEMB_VAR(Kind, kind)
	);

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, rhs)
	);
public:		// functions
	SHARED_CONTENTS(DeclAlias, Base);
};
BUILD_KIND_OPERATOR_LSHIFT(DeclAlias);
//--------

//--------
class NamedScope: public Base
{
public:		// variables
	CHILDREN
	(
		// Expected child type:  StrAndNode, where `node` is intended to be
		// an instance of `ParamOrArgList`
		CTAGS_MEMB_VAR(BaseUptrList, item_list)
	);
public:		// functions
	SHARED_CONTENTS(NamedScope, Base);
};
//--------

//--------
class ExprBase: public Base
{
public:		// variables
	DATA
	(
		//CTAGS_MEMB_VAR(LogicValue, val),
		CTAGS_MEMB_VAR(bool, is_self_determined)
	);
public:		// functions
	SHARED_FUNC_CONTENTS_2(ExprBase, Base);
};

class MuxExpr: public ExprBase
{
public:		// variables
	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, cond),
		CTAGS_MEMB_VAR(BaseUptr, when_true),
		CTAGS_MEMB_VAR(BaseUptr, when_false)
	);
public:		// functions
	SHARED_CONTENTS(MuxExpr, ExprBase);
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
	DATA
	(
		CTAGS_MEMB_VAR(Kind, kind)
	);

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, left),
		CTAGS_MEMB_VAR(BaseUptr, right)
	);
public:		// functions
	SHARED_CONTENTS(BinopExpr, ExprBase);
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
	DATA
	(
		CTAGS_MEMB_VAR(Kind, kind)
	);

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, arg)
	);
public:		// functions
	SHARED_CONTENTS(UnopExpr, ExprBase);
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
	DATA
	(
		CTAGS_MEMB_VAR(Kind, kind),
		CTAGS_MEMB_VAR(string, opt_num_str),
		CTAGS_MEMB_VAR(BigNum, opt_num)
	);

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, opt_expr)
	);
public:		// functions
	SHARED_CONTENTS(LitValExpr, ExprBase);
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
	DATA
	(
		CTAGS_MEMB_VAR(Kind, kind)
	);

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, arg), 
		CTAGS_MEMB_VAR(BaseUptr, opt_second_arg)
	);
public:		// functions
	SHARED_CONTENTS(CallDollarFuncExpr, ExprBase);
};
BUILD_KIND_OPERATOR_LSHIFT(CallDollarFuncExpr);

class String: public Base
{
public:		// variables
	DATA
	(
		CTAGS_MEMB_VAR(string, data)
	);
public:		// functions
	SHARED_CONTENTS(String, Base);
};

class IdentExprSuffix: public Base
{
public:		// variables
	DATA
	(
		CTAGS_MEMB_VAR(bool, part_sel_is_minus_colon)
	);

	CHILDREN
	(
		// Access members or array elements
		CTAGS_MEMB_VAR(BaseUptrList, acc_memb_or_arr_list),

		CTAGS_MEMB_VAR(BaseUptr, opt_range_etc),
		CTAGS_MEMB_VAR(BaseUptr, opt_part_sel_right)
	);
public:		// functions
	SHARED_CONTENTS(IdentExprSuffix, Base);
};

class IdentExpr: public ExprBase
{
public:		// variables
	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptrList, prologue_list),
		CTAGS_MEMB_VAR(BaseUptr, opt_arg_list),

		CTAGS_MEMB_VAR(BaseUptr, suffix)
	);
public:		// functions
	SHARED_CONTENTS(IdentExpr, ExprBase);
};

class CatExpr: public ExprBase
{
public:		// variables
	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptrList, item_list)
	);
public:		// functions
	SHARED_CONTENTS(CatExpr, ExprBase);
};

class ReplExpr: public ExprBase
{
public:		// variables

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, amount),
		CTAGS_MEMB_VAR(BaseUptr, to_repl)
	);
public:		// functions
	SHARED_CONTENTS(ReplExpr, ExprBase);
};

class SizedExpr: public ExprBase
{
public:		// variables
	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, lit_num),
		CTAGS_MEMB_VAR(BaseUptr, width)
	);
public:		// functions
	SHARED_CONTENTS(SizedExpr, ExprBase);
};
//--------

//--------
class NonDollarFuncRange: public Base
{
public:		// variables
	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, arg),
		CTAGS_MEMB_VAR(BaseUptr, opt_second_arg)
	);
public:		// functions
	SHARED_CONTENTS(NonDollarFuncRange, Base);
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
	DATA
	(
		CTAGS_MEMB_VAR(Kind, kind)
	);

	CHILDREN
	(
		CTAGS_MEMB_VAR(BaseUptr, opt_ident_expr),
		CTAGS_MEMB_VAR(BaseUptr, opt_vec_dim),
		CTAGS_MEMB_VAR(BaseUptrList, opt_arr_dim_list)
	);
public:		// functions
	SHARED_CONTENTS(Typenm, Base);
};
BUILD_KIND_OPERATOR_LSHIFT(Typenm);

class Modnm: public IdentExpr
{
public:		// functions
	SHARED_CONTENTS(Modnm, IdentExpr);
};
//--------


} // namespace ast

#undef CTAGS_MEMB_VAR
#undef MEMB_VAR
#undef COPY_MEMB_VAR
#undef INNER_WRAP_DATA
#undef PLUS_RAW_NEWLINE
#undef DATA

#undef INNER_ACCEPT_CHILDREN
#undef INNER_DUP
#undef CHILDREN

#undef SHARED_CONTENTS
#undef SHARED_FUNC_CONTENTS_2

#undef CONV_ENUM_CASE
#undef CONV_KIND_CASE
#undef CONV_ENUM_SWITCH

#undef BUILD_KIND_OPERATOR_LSHIFT

} // namespace fling_hdl

#endif		// src_ast_ast_node_classes_hpp
