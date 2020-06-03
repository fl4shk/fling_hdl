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

#define AST_VISITOR AstVisitor

namespace fling_hdl
{

//class Symbol;

namespace ast
{

//--------
using Base = AstNodeBase;
using BaseUptr = AstNodeBaseUptr;
using BaseUptrList = AstNodeBaseUptrList;
//--------

//--------
class Program: public Base
{
public:		// variables
	CHILDREN
	(
		MEMB_VAR(BaseUptrList, item_list)
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
		MEMB_VAR(string, ident)
	);

	CHILDREN
	(
		MEMB_VAR(BaseUptrList, item_list)
	)
public:		// functions
	SHARED_CONTENTS(DeclPackage, Base);
};

class Import: public Base
{
public:		// variables
	CHILDREN
	(
		MEMB_VAR(BaseUptrList, item_list)
	);
public:		// functions
	SHARED_CONTENTS(Import, Base);
};

class ImportItem: public Base
{
public:		// variables
	DATA
	(
		MEMB_VAR(bool, ends_with_all)
	);

	CHILDREN
	(
		MEMB_VAR(BaseUptrList, item_list)
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
		MEMB_VAR(BaseUptrList, item_list)
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
		MEMB_VAR(string, ident),
		MEMB_VAR(Kind, kind)
	);

	CHILDREN
	(
		MEMB_VAR(BaseUptr, opt_typenm),

		// Default value list, the type of which is dependent upon the
		// value of `kind`.
		MEMB_VAR(BaseUptr, opt_def_val)
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
		MEMB_VAR(string, ident),
		MEMB_VAR(Kind, kind)
	);

	CHILDREN
	(
		MEMB_VAR(BaseUptr, typenm),
		MEMB_VAR(BaseUptr, opt_def_val)
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
		MEMB_VAR(string, str)
	);

	CHILDREN
	(
		MEMB_VAR(BaseUptr, node)
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
		MEMB_VAR(string, ident)
	);

	CHILDREN
	(
		MEMB_VAR(BaseUptr, opt_param_list),
		MEMB_VAR(BaseUptr, arg_list),
		MEMB_VAR(BaseUptr, scope)
	);
public:		// functions
	SHARED_CONTENTS(DeclModule, Base);
};

class Scope: public Base
{
public:		// variables
	CHILDREN
	(
		MEMB_VAR(BaseUptrList, item_list)
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
		MEMB_VAR(string, ident)
	);

	CHILDREN
	(
		MEMB_VAR(BaseUptr, modnm),
		MEMB_VAR(BaseUptr, arg_list)
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
		MEMB_VAR(BaseUptr, if_expr),
		MEMB_VAR(BaseUptr, if_scope),
		MEMB_VAR(BaseUptrList, opt_elif_list),
		MEMB_VAR(BaseUptr, opt_else_scope)
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
		MEMB_VAR(Kind, kind)
	)

	CHILDREN
	(
		MEMB_VAR(BaseUptr, expr),
		MEMB_VAR(BaseUptr, opt_default),
		MEMB_VAR(BaseUptrList, opt_case_list)
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
		MEMB_VAR(BaseUptrList, expr_list),
		MEMB_VAR(BaseUptr, scope)
	)
public:		// functions
	SHARED_CONTENTS(GenCase, Base);
};

class GenDefault: public Base
{
public:		// variables
	CHILDREN
	(
		MEMB_VAR(BaseUptr, scope)
	);
public:		// functions
	SHARED_CONTENTS(GenDefault, Base);
};

class GenFor: public Base
{
public:		// variables
	DATA
	(
		MEMB_VAR(string, label),
		MEMB_VAR(string, iter_ident)
	);

	CHILDREN
	(
		MEMB_VAR(BaseUptr, range),
		MEMB_VAR(BaseUptr, scope)
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
		MEMB_VAR(BaseUptr, scope)
	);
public:		// functions
	SHARED_CONTENTS(DeclModuleBehavComb, Base);
};

class DeclModuleBehavSeq: public Base
{
public:		// variables
	CHILDREN
	(
		MEMB_VAR(BaseUptrList, edge_item_list),
		MEMB_VAR(BaseUptr, scope)
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
		MEMB_VAR(Kind, kind)
	);

	CHILDREN
	(
		MEMB_VAR(BaseUptr, expr)
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
		MEMB_VAR(string, iter_ident)
	);

	CHILDREN
	(
		MEMB_VAR(BaseUptr, range),
		MEMB_VAR(BaseUptr, scope)
	);
public:		// functions
	SHARED_CONTENTS(BehavFor, Base);
};

class BehavWhile: public Base
{
public:		// variables
	CHILDREN
	(
		MEMB_VAR(BaseUptr, expr),
		MEMB_VAR(BaseUptr, scope)
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
		MEMB_VAR(Kind, kind)
	);

	CHILDREN
	(
		MEMB_VAR(BaseUptr, lhs),
		MEMB_VAR(BaseUptr, rhs)
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
		MEMB_VAR(string, ident),
		MEMB_VAR(bool, is_packed),
		MEMB_VAR(bool, is_signed)
	);

	CHILDREN
	(
		MEMB_VAR(BaseUptr, opt_param_list),
		MEMB_VAR(BaseUptr, scope)
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
		MEMB_VAR(string, ident)
	);

	CHILDREN
	(
		MEMB_VAR(BaseUptr, opt_typenm),
		MEMB_VAR(BaseUptrList, item_list)
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
		MEMB_VAR(Kind, kind),
		MEMB_VAR(string, ident)
	);

	CHILDREN
	(
		MEMB_VAR(BaseUptr, opt_param_list),
		MEMB_VAR(BaseUptr, arg_list),
		MEMB_VAR(BaseUptr, opt_ret_typenm),
		MEMB_VAR(BaseUptr, scope)
	);
public:		// functions
	SHARED_CONTENTS(DeclSubprog, Base);
};
BUILD_KIND_OPERATOR_LSHIFT(DeclSubprog);
//--------

//--------
class DeclVarEtcList: public Base
{
public:		// variables
	CHILDREN
	(
		MEMB_VAR(BaseUptrList, item_list)
	);
public:		// functions
	SHARED_CONTENTS(DeclVarEtcList, Base);
};

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
		MEMB_VAR(Kind, kind),
		MEMB_VAR(string, ident)
	);

	CHILDREN
	(
		MEMB_VAR(BaseUptr, typenm),
		MEMB_VAR(BaseUptr, val)
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
		MEMB_VAR(BaseUptr, lhs),
		MEMB_VAR(BaseUptr, rhs)
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
		MEMB_VAR(string, ident),
		MEMB_VAR(Kind, kind)
	);

	CHILDREN
	(
		MEMB_VAR(BaseUptr, rhs)
	);
public:		// functions
	SHARED_CONTENTS(DeclAlias, Base);
};
BUILD_KIND_OPERATOR_LSHIFT(DeclAlias);
//--------

////--------
//class NamedScope: public Base
//{
//public:		// variables
//	CHILDREN
//	(
//		// Expected child type:  `StrAndNode`, where `node` is intended to
//		// be an instance of `ParamOrArgList`
//		MEMB_VAR(BaseUptrList, item_list)
//	);
//public:		// functions
//	SHARED_CONTENTS(NamedScope, Base);
//};
//--------

//--------
class ExprBase: public Base
{
public:		// variables
	DATA
	(
		//MEMB_VAR(LogicValue, val),
		MEMB_VAR(bool, is_self_determined)
	);
public:		// functions
	SHARED_FUNC_CONTENTS_2(ExprBase, Base);
};

class MuxExpr: public ExprBase
{
public:		// variables
	CHILDREN
	(
		MEMB_VAR(BaseUptr, cond),
		MEMB_VAR(BaseUptr, when_true),
		MEMB_VAR(BaseUptr, when_false)
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
		MEMB_VAR(Kind, kind)
	);

	CHILDREN
	(
		MEMB_VAR(BaseUptr, left),
		MEMB_VAR(BaseUptr, right)
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
		MEMB_VAR(Kind, kind)
	);

	CHILDREN
	(
		MEMB_VAR(BaseUptr, arg)
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
		MEMB_VAR(Kind, kind),
		MEMB_VAR(string, opt_num_str),
		MEMB_VAR(BigNum, opt_num)
	);

	CHILDREN
	(
		MEMB_VAR(BaseUptr, opt_expr)
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
		MEMB_VAR(Kind, kind)
	);

	CHILDREN
	(
		MEMB_VAR(BaseUptr, arg), 
		MEMB_VAR(BaseUptr, opt_second_arg)
	);
public:		// functions
	SHARED_CONTENTS(CallDollarFuncExpr, ExprBase);
};
BUILD_KIND_OPERATOR_LSHIFT(CallDollarFuncExpr);

//class String: public Base
//{
//public:		// variables
//	DATA
//	(
//		MEMB_VAR(string, data)
//	);
//public:		// functions
//	SHARED_CONTENTS(String, Base);
//};

class IdentExprSuffix: public Base
{
public:		// variables
	DATA
	(
		MEMB_VAR(bool, part_sel_is_minus_colon)
	);

	CHILDREN
	(
		// Access members or array elements
		MEMB_VAR(BaseUptrList, acc_memb_or_arr_list),

		MEMB_VAR(BaseUptr, opt_range_etc),
		MEMB_VAR(BaseUptr, opt_part_sel_right)
	);
public:		// functions
	SHARED_CONTENTS(IdentExprSuffix, Base);
};

class IdentExpr: public ExprBase
{
public:		// variables
	CHILDREN
	(
		// Expected list type (from `flingIdentExprStart`,
		// `flingTypenmCstmChainItem`, etc.):  `StrAndNode`,
		// storing a `MiscIdent` and optionally a `ParamOrArgList`
		MEMB_VAR(BaseUptrList, prologue_list),
		MEMB_VAR(BaseUptr, opt_arg_list),

		MEMB_VAR(BaseUptr, suffix)
	);
public:		// functions
	SHARED_CONTENTS(IdentExpr, ExprBase);
};

class CatExpr: public ExprBase
{
public:		// variables
	CHILDREN
	(
		MEMB_VAR(BaseUptrList, item_list)
	);
public:		// functions
	SHARED_CONTENTS(CatExpr, ExprBase);
};

class ReplExpr: public ExprBase
{
public:		// variables

	CHILDREN
	(
		MEMB_VAR(BaseUptr, amount),
		MEMB_VAR(BaseUptr, to_repl)
	);
public:		// functions
	SHARED_CONTENTS(ReplExpr, ExprBase);
};

class SizedExpr: public ExprBase
{
public:		// variables
	CHILDREN
	(
		MEMB_VAR(BaseUptr, lit_num),
		MEMB_VAR(BaseUptr, width)
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
		MEMB_VAR(BaseUptr, arg),
		MEMB_VAR(BaseUptr, opt_second_arg)
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
		MEMB_VAR(Kind, kind)
	);

	CHILDREN
	(
		MEMB_VAR(BaseUptr, opt_ident_expr),
		MEMB_VAR(BaseUptr, opt_vec_dim),
		MEMB_VAR(BaseUptrList, opt_arr_dim_list)
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

#include "../liborangepower_src/lang/ast_node_base_class_undefines.hpp"

} // namespace fling_hdl

#endif		// src_ast_ast_node_classes_hpp
