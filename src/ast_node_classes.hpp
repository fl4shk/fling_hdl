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
public:		// variables
	ExprValue val;
	ErrWarn ew;
public:		// functions
	inline Base() = default;
	inline Base(const ErrWarn& s_ew)
		: ew(s_ew)
	{
	}
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Base);
	virtual inline ~Base() = default;
	virtual inline string id() const
	{
		return string("Base");
	}

	//virtual inline void eval()
	//{
	//}
};


template<typename ChildType>
class HasChildrenBase: public Base
{
public:		// variables
	using Child = ChildType;
	vector<Child> children;
public:		// functions
	SHARED_FUNC_CONTENTS(HasChildrenBase, Base);
};

template<typename ScopeType>
class IfBase: public Base
{
public:		// variables
	class OneIf
	{
	public:		// variables
		shared_ptr<Expr> expr;
		shared_ptr<ScopeType> scope;
	};
	vector<OneIf> _one_if_vec;
	optional<shared_ptr<ScopeType>> _opt_else_scope;
public:		// functions
	SHARED_FUNC_CONTENTS(IfBase, Base);
};

template<typename ScopeType>
class SwitchBase: public Base
{
public:		// variables
	class CaseItem
	{
	public:		// variables
		shared_ptr<ExprList> expr_list;
		shared_ptr<ScopeType> scope;
	};
	shared_ptr<Expr> to_switch;
	vector<CaseItem> case_item_vec;
	optional<shared_ptr<ScopeType>> opt_default_scope;
public:		// functions
	SHARED_FUNC_CONTENTS(SwitchBase, Base);
};

template<typename ScopeType>
class ForBase: public Base
{
public:		// variables
	string name;
	shared_ptr<Expr> expr_range;
	shared_ptr<ScopeType> scope;
public:		// functions
	SHARED_FUNC_CONTENTS(ForBase, Base);
};
template<typename ScopeType>
class WhileBase: public Base
{
public:		// variables
	shared_ptr<Expr> expr_range;
	shared_ptr<ScopeType> scope;
public:		// functions
	SHARED_FUNC_CONTENTS(WhileBase, Base);
};

template<typename HeaderType, typename ScopeType>
class DeclSubprogBase: public Base
{
public:		// variables
	shared_ptr<HeaderType> header;
	shared_ptr<ScopeType> scope;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclSubprogBase, Base);
};


using BaseClassOfProgram = HasChildrenBase<variant<shared_ptr<DeclPackage>,
	shared_ptr<DeclModule>, shared_ptr<DeclType>, shared_ptr<DeclSubprog>,
	shared_ptr<DeclAlias>>>;
class Program: public BaseClassOfProgram
{
public:		// functions
	SHARED_FUNC_CONTENTS(Program, BaseClassOfProgram);
};

using BaseClassOfDeclPackage = HasChildrenBase<variant
	<shared_ptr<DeclPackage>, shared_ptr<DeclModule>, shared_ptr<DeclType>,
	shared_ptr<DeclSubprog>, shared_ptr<DeclAlias>,
	shared_ptr<DeclConst>>>;
class DeclPackage: public BaseClassOfDeclPackage
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclPackage, BaseClassOfDeclPackage);
};

using BaseClassOfDeclParamList = HasChildrenBase
	<shared_ptr<DeclParamList_Item>>;
class DeclParamList: public BaseClassOfDeclParamList
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclParamList, BaseClassOfDeclParamList);
};

class DeclParamList_Item: public Base
{
public:		// variables
	enum class Kind
	{
		Val,
		Type,
		Module,
	};
	shared_ptr<IdentList> _name_list;
	Kind _kind;
	optional<variant<shared_ptr<ExprList>,
		shared_ptr<TypenameOrModnameList>>> _opt_def_val_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclParamList_Item, Base);
};

using BaseClassOfDeclArgList = HasChildrenBase
	<shared_ptr<DeclArgList_Item>>;
class DeclArgList: public BaseClassOfDeclArgList
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclArgList, BaseClassOfDeclArgList);
};

class DeclArgList_Item: public Base
{
public:		// variables
	enum class PortType
	{
		Input,
		Output,
		Inout,
		Interface
	};
	shared_ptr<IdentList> name_list;
	PortType port_type;
	optional<shared_ptr<ExprList>> opt_def_val_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclArgList_Item, Base);
};

class InstParamList: public Base
{
public:		// variables
	optional<variant<shared_ptr<InstParamList_Pos>,
		shared_ptr<InstParamList_Named>>> opt_list;
public:		// functions
	SHARED_FUNC_CONTENTS(InstParamList, Base);
};

using BaseClassOfInstParamList_Pos = HasChildrenBase<variant
	<shared_ptr<Expr>, shared_ptr<TypenameOrModname>>>;
class InstParamList_Pos: public BaseClassOfInstParamList_Pos
{
public:		// functions
	SHARED_FUNC_CONTENTS(InstParamList_Pos, BaseClassOfInstParamList_Pos);
};

using BaseClassOfInstParamList_Named = HasChildrenBase
	<shared_ptr<InstParamList_Named_Item>>;
class InstParamList_Named: public BaseClassOfInstParamList_Named
{
public:		// functions
	SHARED_FUNC_CONTENTS(InstParamList_Named,
		BaseClassOfInstParamList_Named);
};

class InstParamList_Named_Item: public Base
{
public:		// variables
	string name;
	typename InstParamList_Pos::Child rhs;
public:		// functions
	SHARED_FUNC_CONTENTS(InstParamList_Named_Item, Base);
};

class InstArgList: public Base
{
public:		// variables
	optional<variant<shared_ptr<ExprList>,
		shared_ptr<InstArgList_Named>>> opt_list;
public:		// functions
	SHARED_FUNC_CONTENTS(InstArgList, Base);
};

using BaseClassOfInstArgList_Named = HasChildrenBase
	<shared_ptr<InstArgList_Named_Item>>;
class InstArgList_Named: public BaseClassOfInstArgList_Named
{
public:		// functions
	SHARED_FUNC_CONTENTS(InstArgList_Named, BaseClassOfInstArgList_Named);
};

class InstArgList_Named_Item: public Base
{
private:		// variables
	string _name;
	shared_ptr<Expr> _expr;
public:		// functions
	SHARED_FUNC_CONTENTS(InstArgList_Named_Item, Base);
};

class DeclModule: public Base
{
public:		// variables
	using OptDeclParamList = optional<shared_ptr<DeclParamList>>;
	using OptImportList = optional<shared_ptr<ImportList>>;
	string name;
	OptDeclParamList opt_decl_param_list;
	shared_ptr<DeclArgList> decl_arg_list;
	OptImportList opt_import_list;
	shared_ptr<DeclModule_Scope> scope;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclModule, Base);
};


using BaseClassOfDeclModule_Scope = HasChildrenBase<variant
	<shared_ptr<InstModule>, shared_ptr<Expr_CallSubprog_Regular>,
	shared_ptr<Expr_CallSubprog_PseudoOper>, shared_ptr<Gen>,
	shared_ptr<ContAssign>, shared_ptr<ImportList>, shared_ptr<Behav>,
	shared_ptr<DeclWire>, shared_ptr<DeclVar>, shared_ptr<DeclConst>,
	shared_ptr<DeclType>, shared_ptr<DeclSubprog>, shared_ptr<DeclAlias>>>;
class DeclModule_Scope: public BaseClassOfDeclModule_Scope
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclModule_Scope, BaseClassOfDeclModule_Scope);
};

class InstModule: public Base
{
public:		// variables
	string name;
	shared_ptr<TypenameOrModname> typename_or_modname;
	shared_ptr<InstArgList> inst_arg_list;
public:		// functions
	SHARED_FUNC_CONTENTS(InstModule, Base);
};

class Gen: public Base
{
public:		// variables
	using SpecificGen = variant<shared_ptr<Gen_If>,
		shared_ptr<Gen_Switch>, shared_ptr<Gen_For>>;
	SpecificGen specific_generate;
public:		// functions
	SHARED_FUNC_CONTENTS(Gen, Base);
};

using BaseClassOfGen_If = IfBase<DeclModule_Scope>;
class Gen_If: public BaseClassOfGen_If
{
public:		// functions
	SHARED_FUNC_CONTENTS(Gen_If, BaseClassOfGen_If);
};

using BaseClassOfGen_Switch = SwitchBase<DeclModule_Scope>;
class Gen_Switch: public BaseClassOfGen_Switch
{
public:		// functions
	SHARED_FUNC_CONTENTS(Gen_Switch, BaseClassOfGen_Switch);
};

class Gen_For: public Base
{
public:		// variables
	string label, name;
	shared_ptr<Expr> range;
	shared_ptr<DeclModule_Scope> scope;
public:		// functions
	SHARED_FUNC_CONTENTS(Gen_For, Base);
};

class ContAssign: public Base
{
public:		// variables
	shared_ptr<Expr> lhs, rhs;
public:		// functions
	SHARED_FUNC_CONTENTS(ContAssign, Base);
};

class Behav: public Base
{
public:		// variables
	enum class Kind
	{
		Initial,
		Comb,
		Seq,
	};
	Kind _kind;
	optional<shared_ptr<Behav_Seq_EdgeList>> _opt_edge_list;
	shared_ptr<Behav_Scope> _scope;
public:		// functions
	SHARED_FUNC_CONTENTS(Behav, Base);
};

using BaseClassOfBehav_Seq_EdgeList = HasChildrenBase
	<shared_ptr<Behav_Seq_EdgeList_Item>>;
class Behav_Seq_EdgeList: public BaseClassOfBehav_Seq_EdgeList
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Seq_EdgeList,
		BaseClassOfBehav_Seq_EdgeList);
};

class Behav_Seq_EdgeList_Item: public Base
{
public:		// variables
	enum class Kind
	{
		Posedge,
		Negedge,
	};
	Kind kind;
	shared_ptr<Expr> expr;
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Seq_EdgeList_Item, Base);
};

using BaseClassOfBehav_Scope = HasChildrenBase<variant<
	shared_ptr<Behav_Scope>, shared_ptr<DeclAlias>, shared_ptr<DeclVar>,
	shared_ptr<DeclConst>, shared_ptr<DeclType>,
	shared_ptr<Behav_Item_BlkAssign>, shared_ptr<Behav_Item_NonBlkAssign>,
	shared_ptr<Behav_Item_If>, shared_ptr<Behav_Item_Switch>,
	shared_ptr<Behav_Item_Switchz>, shared_ptr<Behav_Item_For>,
	shared_ptr<Behav_Item_While>, shared_ptr<Expr_CallSubprog_Regular>,
	shared_ptr<Expr_CallSubprog_PseudoOper>>>;
class Behav_Scope: public BaseClassOfBehav_Scope
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Scope, BaseClassOfBehav_Scope);
};

using BaseClassOfBehav_Item_If = IfBase<Behav_Scope>;
class Behav_Item_If: public BaseClassOfBehav_Item_If
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Item_If, BaseClassOfBehav_Item_If);
};
using BaseClassOfBehav_Item_Switch = SwitchBase<Behav_Scope>;
class Behav_Item_Switch: public BaseClassOfBehav_Item_Switch
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Item_Switch, BaseClassOfBehav_Item_Switch);
};
using BaseClassOfBehav_Item_Switchz = SwitchBase<Behav_Scope>;
class Behav_Item_Switchz: public BaseClassOfBehav_Item_Switchz
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Item_Switchz,
		BaseClassOfBehav_Item_Switchz);
};
using BaseClassOfBehav_Item_For = ForBase<Behav_Scope>;
class Behav_Item_For: public BaseClassOfBehav_Item_For
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Item_For, BaseClassOfBehav_Item_For);
};
using BaseClassOfBehav_Item_While = WhileBase<Behav_Scope>;
class Behav_Item_While: public BaseClassOfBehav_Item_While
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Item_While, BaseClassOfBehav_Item_While);
};

class Behav_Item_NonBlkAssign: public ContAssign
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Item_NonBlkAssign, ContAssign);
};
class Behav_Item_BlkAssign: public ContAssign
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Item_BlkAssign, ContAssign);
};

class DeclWire: public Base
{
public:		// variables
	shared_ptr<IdentList> name_list;
	shared_ptr<TypenameOrModname> typename_or_modname;
	optional<shared_ptr<ExprList>> opt_expr_list;
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
	shared_ptr<IdentList> name_list;
	shared_ptr<TypenameOrModname> typename_or_modname;
	shared_ptr<ExprList> expr_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclConst, Base);
};

class DeclType: public Base
{
public:		// variables
	variant<shared_ptr<DeclEnum>, shared_ptr<DeclClass>,
		shared_ptr<DeclMixin>> item;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclType, Base);
};

class DeclEnum: public Base
{
public:		// variables
	string name;

	optional<shared_ptr<TypenameOrModname>> opt_typename_or_modname;

	shared_ptr<IdentList> ident_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclEnum, Base);
};

using BaseClassOfDeclClass = HasChildrenBase<variant
	<shared_ptr<DeclClass_Item_DeclVar>,
	shared_ptr<DeclClsOrMxn_Item_DeclType>,
	shared_ptr<DeclClsOrMxn_Item_DeclAliasOrConst>,
	shared_ptr<DeclClsOrMxn_Item_DeclSubprog_FullDefn>,
	shared_ptr<DeclClsOrMxn_Item_DeclSubprog_Abstract>,
	shared_ptr<ImportList>>>;
class DeclClass: public BaseClassOfDeclClass
{
public:		// variables
	bool is_base = false,
		is_signed = false,
		is_packed = false;
	string name;
	shared_ptr<DeclParamList> param_list;
	optional<shared_ptr<TypenameOrModnameList>> opt_extends;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClass, BaseClassOfDeclClass);

};

enum class AccessSpecifier
{
	Pub,
	Prot,
	Priv,
};

class DeclClass_Item_DeclVar: public Base
{
public:		// variables
	AccessSpecifier access_spec = AccessSpecifier::Pub;
	bool is_static = false;
	shared_ptr<DeclVar> decl_var;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClass_Item_DeclVar, Base);
};

class DeclClsOrMxn_Item_DeclType: public Base
{
public:		// variables
	AccessSpecifier access_spec = AccessSpecifier::Pub;
	shared_ptr<DeclType> decl_type;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClsOrMxn_Item_DeclType, Base);
};

class DeclClsOrMxn_Item_DeclAliasOrConst: public Base
{
public:		// variables
	AccessSpecifier access_spec = AccessSpecifier::Pub;
	bool is_static = false;
	variant<shared_ptr<DeclAlias>, shared_ptr<DeclConst>> item;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClsOrMxn_Item_DeclAliasOrConst, Base);
};

class DeclClsOrMxn_Item_DeclSubprog_FullDefn: public Base
{
public:		// variables
	AccessSpecifier access_spec = AccessSpecifier::Pub;
	bool is_virtual = false;
	bool is_static = false;
	bool is_const = false;
	shared_ptr<DeclSubprog> decl_subprog;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClsOrMxn_Item_DeclSubprog_FullDefn, Base);
};


class DeclClsOrMxn_Item_DeclSubprog_Abstract: public Base
{
public:		// variables
	AccessSpecifier access_spec = AccessSpecifier::Pub;
	bool is_const = false;
	variant<shared_ptr<DeclFunc_Header>, shared_ptr<DeclTask_Header>,
		shared_ptr<DeclProc_Header>> header;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClsOrMxn_Item_DeclSubprog_Abstract, Base);
};

using BaseClassOfDeclMixin = HasChildrenBase<variant
	<shared_ptr<DeclClsOrMxn_Item_DeclType>,
	shared_ptr<DeclClsOrMxn_Item_DeclAliasOrConst>,
	shared_ptr<DeclClsOrMxn_Item_DeclSubprog_FullDefn>,
	shared_ptr<DeclClsOrMxn_Item_DeclSubprog_Abstract>,
	shared_ptr<ImportList>>>;
class DeclMixin: public BaseClassOfDeclMixin
{
public:		// variables
	bool is_base = false;
	string name;
	shared_ptr<DeclParamList> param_list;
	optional<shared_ptr<TypenameOrModnameList>> opt_extends;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclMixin, BaseClassOfDeclMixin);
};

class DeclSubprog: public Base
{
public:		// variables
	variant<shared_ptr<DeclFunc>, shared_ptr<DeclTask>,
		shared_ptr<DeclProc>> item;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclSubprog, Base);
};

using BaseClassOfDeclFunc = DeclSubprogBase<DeclFunc_Header,
	DeclFunc_Scope>;
class DeclFunc: public BaseClassOfDeclFunc
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclFunc, BaseClassOfDeclFunc);
};

class DeclFunc_Header: public Base
{
public:		// variables
	string name;
	optional<shared_ptr<DeclParamList>> opt_param_list;
	shared_ptr<DeclArgList> arg_list;
	shared_ptr<TypenameOrModname> rtn_type;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclFunc_Header, Base);
};

using BaseClassOfDeclFunc_Scope = HasChildrenBase<variant
	<shared_ptr<Expr>, // return
	shared_ptr<DeclFunc_Scope>, shared_ptr<DeclAlias>,
	shared_ptr<DeclVar>, shared_ptr<DeclConst>, shared_ptr<DeclType>,
	shared_ptr<Behav_Item_BlkAssign>,
	shared_ptr<DeclFunc_Item_If>, shared_ptr<DeclFunc_Item_Switch>,
	shared_ptr<DeclFunc_Item_Switchz>, shared_ptr<DeclFunc_Item_For>,
	shared_ptr<DeclFunc_Item_While>, shared_ptr<Expr_CallSubprog_Regular>,
	shared_ptr<Expr_CallSubprog_PseudoOper>>>;
class DeclFunc_Scope: public BaseClassOfDeclFunc_Scope
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclFunc_Scope, BaseClassOfDeclFunc_Scope);
};

using BaseClassOfDeclFunc_Item_If = IfBase<DeclFunc_Scope>;
class DeclFunc_Item_If: public BaseClassOfDeclFunc_Item_If
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclFunc_Item_If, BaseClassOfDeclFunc_Item_If);
};

using BaseClassOfDeclFunc_Item_Switch = SwitchBase<DeclFunc_Scope>;
class DeclFunc_Item_Switch: public BaseClassOfDeclFunc_Item_Switch
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclFunc_Item_Switch,
		BaseClassOfDeclFunc_Item_Switch);
};
using BaseClassOfDeclFunc_Item_Switchz = SwitchBase<DeclFunc_Scope>;
class DeclFunc_Item_Switchz: public BaseClassOfDeclFunc_Item_Switchz
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclFunc_Item_Switchz,
		BaseClassOfDeclFunc_Item_Switchz);
};

using BaseClassOfDeclFunc_Item_For = ForBase<DeclFunc_Scope>;
class DeclFunc_Item_For: public BaseClassOfDeclFunc_Item_For
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclFunc_Item_For, ForBase<DeclFunc_Scope>);
};

using BaseClassOfDeclFunc_Item_While = WhileBase<DeclFunc_Scope>;
class DeclFunc_Item_While: public BaseClassOfDeclFunc_Item_While
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclFunc_Item_While,
	BaseClassOfDeclFunc_Item_While);
};

using BaseClassOfDeclTask = DeclSubprogBase<DeclTask_Header,
	DeclTask_Scope>;
class DeclTask: public BaseClassOfDeclTask
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclTask, BaseClassOfDeclTask);
};

class DeclTask_Header: public Base
{
public:		// variables
	string name;
	optional<shared_ptr<DeclParamList>> opt_param_list;
	shared_ptr<DeclArgList> arg_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclTask_Header, Base);
};


using BaseClassOfDeclTask_Scope = HasChildrenBase<variant
	<shared_ptr<DeclTask_Scope>, shared_ptr<DeclAlias>,
	shared_ptr<DeclVar>, shared_ptr<DeclConst>, shared_ptr<DeclType>,
	shared_ptr<Behav_Item_BlkAssign>, shared_ptr<Behav_Item_NonBlkAssign>,
	shared_ptr<DeclTask_Item_If>, shared_ptr<DeclTask_Item_Switch>,
	shared_ptr<DeclTask_Item_Switchz>, shared_ptr<DeclTask_Item_For>,
	shared_ptr<DeclTask_Item_While>, shared_ptr<Expr_CallSubprog_Regular>,
	shared_ptr<Expr_CallSubprog_PseudoOper>>>;
class DeclTask_Scope: public BaseClassOfDeclTask_Scope
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclTask_Scope, BaseClassOfDeclTask_Scope);
};


using BaseClassOfDeclTask_Item_If = IfBase<DeclTask_Scope>;
class DeclTask_Item_If: public BaseClassOfDeclTask_Item_If
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclTask_Item_If, BaseClassOfDeclTask_Item_If);
};

using BaseClassOfDeclTask_Item_Switch = SwitchBase<DeclTask_Scope>;
class DeclTask_Item_Switch: public BaseClassOfDeclTask_Item_Switch
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclTask_Item_Switch,
		BaseClassOfDeclTask_Item_Switch);
};

using BaseClassOfDeclTask_Item_Switchz = SwitchBase<DeclTask_Scope>;
class DeclTask_Item_Switchz: public BaseClassOfDeclTask_Item_Switchz
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclTask_Item_Switchz,
		BaseClassOfDeclTask_Item_Switchz);
};
using BaseClassOfDeclTask_Item_For = ForBase<DeclTask_Scope>;
class DeclTask_Item_For: public BaseClassOfDeclTask_Item_For
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclTask_Item_For, BaseClassOfDeclTask_Item_For);
};
using BaseClassOfDeclTask_Item_While = WhileBase<DeclTask_Scope>;
class DeclTask_Item_While: public BaseClassOfDeclTask_Item_While
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclTask_Item_While,
		BaseClassOfDeclTask_Item_While);
};

using BaseClassOfDeclProc = DeclSubprogBase<DeclProc_Header,
	DeclModule_Scope>;
class DeclProc: public BaseClassOfDeclProc
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclProc, BaseClassOfDeclProc);
};

class DeclProc_Header: public Base
{
public:		// variables
	string name;
	optional<shared_ptr<DeclParamList>> opt_param_list;
	shared_ptr<DeclProc_ArgList> arg_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclProc_Header, Base);
};

using BaseClassOfDeclProc_ArgList = HasChildrenBase
	<shared_ptr<DeclProc_ArgList_Item>>;
class DeclProc_ArgList: public BaseClassOfDeclProc_ArgList
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclProc_ArgList, BaseClassOfDeclProc_ArgList);
};

class DeclProc_ArgList_Item: public Base
{
public:		// variables
	shared_ptr<IdentList> name_list;
	bool is_ref = false;
	shared_ptr<TypenameOrModname> typename_or_modname;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclProc_ArgList_Item, Base);
};

class DeclAlias: public Base
{
public:		// variables
	variant<shared_ptr<DeclAlias_Value>, shared_ptr<DeclAlias_Type>,
		shared_ptr<DeclAlias_Module>> item;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclAlias, Base);
};

class DeclAlias_Value: public Base
{
public:		// variables
	shared_ptr<IdentList> name_list;
	shared_ptr<TypenameOrModname> typename_or_modname;
	shared_ptr<ExprList> expr_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclAlias_Value, Base);
};

class DeclAlias_Type: public Base
{
public:		// variables
	shared_ptr<IdentList> name_list;
	shared_ptr<TypenameOrModnameList> typename_or_modname_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclAlias_Type, Base);
};
class DeclAlias_Module: public Base
{
public:		// variables
	shared_ptr<IdentList> name_list;
	shared_ptr<TypenameOrModnameList> typename_or_modname_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclAlias_Module, Base);
};

using BaseClassOfIdentList = HasChildrenBase<string>;
class IdentList: public BaseClassOfIdentList
{
public:		// functions
	SHARED_FUNC_CONTENTS(IdentList, BaseClassOfIdentList);
};

class ScopedIdent: public IdentList
{
public:		// functions
	SHARED_FUNC_CONTENTS(ScopedIdent, IdentList);
};

using BaseClassOfExprList = HasChildrenBase<Expr>;
class ExprList: public BaseClassOfExprList
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprList, BaseClassOfExprList);
};

using BaseClassOfTypenameOrModnameList
	= HasChildrenBase<TypenameOrModname>;
class TypenameOrModnameList: public BaseClassOfTypenameOrModnameList
{
public:		// functions
	SHARED_FUNC_CONTENTS(TypenameOrModnameList,
		BaseClassOfTypenameOrModnameList);
};

using BaseClassOfImportList = HasChildrenBase<ScopedIdent>;
class ImportList: public BaseClassOfImportList
{
public:		// functions
	SHARED_FUNC_CONTENTS(ImportList, BaseClassOfImportList);
};

class TypenameOrModname_SelfT: public Base
{
public:		// functions
	SHARED_FUNC_CONTENTS(TypenameOrModname_SelfT, Base);
};
class TypenameOrModname_RetT: public Base
{
public:		// functions
	SHARED_FUNC_CONTENTS(TypenameOrModname_RetT, Base);
};

class TypenameOrModname: public Base
{
public:		// variables
	variant<shared_ptr<TypenameOrModname_Cstm>,
		shared_ptr<TypenameOrModname_SelfT>,
		shared_ptr<TypenameOrModname_RetT>,
		shared_ptr<TypenameOrModname_Builtin>> item;
public:		// functions
	SHARED_FUNC_CONTENTS(TypenameOrModname, Base);
};

class TypenameOrModname_Cstm: public Base
{
public:		// variables
	vector<shared_ptr<TypenameOrModname_Cstm_Item>> item_vec;

	using OneArrDim = variant<shared_ptr<Expr>,
		shared_ptr<TypenameOrModname_Builtin>>;
	vector<optional<OneArrDim>> arr_dim_vec;
public:		// functions
	SHARED_FUNC_CONTENTS(TypenameOrModname_Cstm, Base);
};

class TypenameOrModname_Cstm_Item: public Base
{
public:		// variables
	shared_ptr<ScopedIdent> scoped_ident;
	optional<shared_ptr<InstParamList>> opt_param_list;
public:		// functions
	SHARED_FUNC_CONTENTS(TypenameOrModname_Cstm_Item, Base);
};

class TypenameOrModname_Builtin: public Base
{
public:		// variables
	enum class Kind
	{
		Logic,
		SignedLogic,

		Integer,
		SizeT,
		Range,

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

		Void,
		Auto,
	};
	Kind kind;
	optional<shared_ptr<InstParamList>> opt_param_list;
	using OneArrDim = variant<shared_ptr<Expr>,
		shared_ptr<TypenameOrModname_Builtin>>;
	vector<optional<OneArrDim>> arr_dim_vec;
public:		// functions
	SHARED_FUNC_CONTENTS(TypenameOrModname_Builtin, Base);
};


class Expr: public Base
{
public:		// variables
	variant<shared_ptr<Expr_Mux>,

		shared_ptr<Expr_LogOr>, shared_ptr<Expr_LogAnd>,

		shared_ptr<Expr_BinopBitOr>, shared_ptr<Expr_BinopBitNor>,
		shared_ptr<Expr_BinopBitAnd>, shared_ptr<Expr_BinopBitNand>,
		shared_ptr<Expr_BinopBitXor>, shared_ptr<Expr_BinopBitXnor>,

		shared_ptr<Expr_CmpEq>, shared_ptr<Expr_CmpNe>,
		shared_ptr<Expr_CaseCmpEq>, shared_ptr<Expr_CaseCmpNe>,

		shared_ptr<Expr_CmpLt>, shared_ptr<Expr_CmpLe>,
		shared_ptr<Expr_CmpGt>, shared_ptr<Expr_CmpGe>,

		shared_ptr<Expr_BitLsl>, shared_ptr<Expr_BitLsr>,
		shared_ptr<Expr_BitAsr>,

		shared_ptr<Expr_BinopPlus>, shared_ptr<Expr_BinopMinus>,

		shared_ptr<Expr_Mul>, shared_ptr<Expr_Div>, shared_ptr<Expr_Mod>,

		shared_ptr<Expr_UnopPlus>, shared_ptr<Expr_UnopMinus>,
		shared_ptr<Expr_LogNot>, shared_ptr<Expr_BitNot>,

		shared_ptr<Expr_UnopBitOr>, shared_ptr<Expr_UnopBitNor>,
		shared_ptr<Expr_UnopBitAnd>, shared_ptr<Expr_UnopBitNand>,
		shared_ptr<Expr_UnopBitXor>, shared_ptr<Expr_UnopBitXnor>,

		shared_ptr<Expr_Literal>, shared_ptr<Expr_Sized>,
		shared_ptr<Expr_Range>, shared_ptr<Expr_Cat>,
		shared_ptr<Expr_Repl>, shared_ptr<Expr_KwDollarFuncOf_NonPow>,
		shared_ptr<Expr_KwDollarFuncOf_Pow>,
		shared_ptr<Expr_IdentEtcAndOptKwDollarFuncOf>,
		shared_ptr<Expr_IdentEtc>,
		shared_ptr<Expr_IdentEtc_Item>,
		shared_ptr<Expr_IdentEtc_Item_End_Index>,
		shared_ptr<Expr_IdentEtc_Item_End_SubprogCallSuffix>,
		shared_ptr<Expr_IdentEtc_Item_End_KwDollarOper>,
		shared_ptr<Expr_CallSubprog_Regular>,
		shared_ptr<Expr_CallSubprog_PseudoOper>> item;
public:		// functions
	SHARED_FUNC_CONTENTS(Expr, Base);
};

class Expr_Mux: public Base
{
public:		// variables
	shared_ptr<Expr> cond, when_true, when_false;
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_Mux, Base);
};

class ExprBinopBase: public Base
{
public:		// variables
	shared_ptr<Expr> left, right;
public:		// functions
	SHARED_FUNC_CONTENTS(ExprBinopBase, Base);
};
class ExprUnopBase: public Base
{
public:		// variables
	shared_ptr<Expr> arg;
public:		// functions
	SHARED_FUNC_CONTENTS(ExprUnopBase, Base);
};

class Expr_LogOr: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_LogOr, ExprBinopBase);
};
class Expr_LogAnd: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_LogAnd, ExprBinopBase);
};

class Expr_BinopBitOr: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BinopBitOr, ExprBinopBase);
};
class Expr_BinopBitNor: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BinopBitNor, ExprBinopBase);
};
class Expr_BinopBitAnd: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BinopBitAnd, ExprBinopBase);
};
class Expr_BinopBitNand: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BinopBitNand, ExprBinopBase);
};
class Expr_BinopBitXor: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BinopBitXor, ExprBinopBase);
};
class Expr_BinopBitXnor: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BinopBitXnor, ExprBinopBase);
};

class Expr_CmpEq: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_CmpEq, ExprBinopBase);
};
class Expr_CmpNe: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_CmpNe, ExprBinopBase);
};
class Expr_CaseCmpEq: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_CaseCmpEq, ExprBinopBase);
};
class Expr_CaseCmpNe: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_CaseCmpNe, ExprBinopBase);
};

class Expr_CmpLt: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_CmpLt, ExprBinopBase);
};
class Expr_CmpLe: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_CmpLe, ExprBinopBase);
};
class Expr_CmpGt: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_CmpGt, ExprBinopBase);
};
class Expr_CmpGe: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_CmpGe, ExprBinopBase);
};

class Expr_BitLsl: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BitLsl, ExprBinopBase);
};
class Expr_BitLsr: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BitLsr, ExprBinopBase);
};
class Expr_BitAsr: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BitAsr, ExprBinopBase);
};

class Expr_BinopPlus: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BinopPlus, ExprBinopBase);
};
class Expr_BinopMinus: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BinopMinus, ExprBinopBase);
};

class Expr_Mul: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_Mul, ExprBinopBase);
};
class Expr_Div: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_Div, ExprBinopBase);
};
class Expr_Mod: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_Mod, ExprBinopBase);
};

class Expr_UnopPlus: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_UnopPlus, ExprUnopBase);
};
class Expr_UnopMinus: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_UnopMinus, ExprUnopBase);
};
class Expr_LogNot: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_LogNot, ExprUnopBase);
};
class Expr_BitNot: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BitNot, ExprUnopBase);
};

class Expr_UnopBitOr: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_UnopBitOr, ExprUnopBase);
};
class Expr_UnopBitNor: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_UnopBitNor, ExprUnopBase);
};
class Expr_UnopBitAnd: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_UnopBitAnd, ExprUnopBase);
};
class Expr_UnopBitNand: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_UnopBitNand, ExprUnopBase);
};
class Expr_UnopBitXor: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_UnopBitXor, ExprUnopBase);
};
class Expr_UnopBitXnor: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_UnopBitXnor, ExprUnopBase);
};

class Expr_Literal: public Base
{
public:		// variables
	enum class Kind
	{
		Uint,
		Float,
		String,
		HighZ,
		UnkX,
	};
	Kind kind;
	variant<BigNum, double, string> item;
	optional<shared_ptr<Expr>> opt_expr;
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_Literal, Base);
};
class Expr_Sized: public Base
{
public:		// variables
	shared_ptr<Expr> size, to_size;
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_Sized, Base);
};
class Expr_Range: public Base
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_Range, Base);
};
class Expr_Cat: public Base
{
public:		// variables
	shared_ptr<ExprList> expr_list;
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_Cat, Base);
};
class Expr_Repl: public Base
{
public:		// variables
	shared_ptr<Expr> width, to_repl;
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_Repl, Base);
};
class Expr_KwDollarFuncOf_NonPow: public Base
{
public:		// variables
	enum class Kind
	{
		Signed,
		Unsigned,
		Clog2,
	};
	Kind kind;
	shared_ptr<Expr> arg;
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_KwDollarFuncOf_NonPow, Base);
};
class Expr_KwDollarFuncOf_Pow: public Base
{
public:		// variables
	shared_ptr<Expr> left, right;
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_KwDollarFuncOf_Pow, Base);
};
class Expr_IdentEtcAndOptKwDollarFuncOf: public Base
{
public:		// variables
	enum class KwDollarFuncOf
	{
		Size,
		Range,
		High,
		Low,
	};
	optional<KwDollarFuncOf> opt_kw_dollar_func_of;
	shared_ptr<Expr_IdentEtc> ident_etc;
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_IdentEtcAndOptKwDollarFuncOf, Base);
};

using BaseClassOfExpr_IdentEtc = HasChildrenBase
	<shared_ptr<Expr_IdentEtc_Item>>;
class Expr_IdentEtc: public BaseClassOfExpr_IdentEtc
{
public:		// variables
	optional<shared_ptr<TypenameOrModname>> opt_typename_or_modname;
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_IdentEtc, BaseClassOfExpr_IdentEtc);
};
using BaseClassOfExpr_IdentEtc_Item = HasChildrenBase<variant
	<shared_ptr<Expr_IdentEtc_Item_End_Index>,
	shared_ptr<Expr_IdentEtc_Item_End_SubprogCallSuffix>,
	shared_ptr<Expr_IdentEtc_Item_End_KwDollarOper>>>;
class Expr_IdentEtc_Item: public BaseClassOfExpr_IdentEtc_Item
{
public:		// variables
	string name;
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_IdentEtc_Item,
		BaseClassOfExpr_IdentEtc_Item);
};
class Expr_IdentEtc_Item_End_Index: public Base
{
public:		// variables
	shared_ptr<Expr> expr;
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_IdentEtc_Item_End_Index, Base);
};
class Expr_IdentEtc_Item_End_SubprogCallSuffix: public Base
{
public:		// variables
	optional<shared_ptr<InstParamList>> opt_param_list;
	shared_ptr<InstArgList> arg_list;
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_IdentEtc_Item_End_SubprogCallSuffix, Base);
};
class Expr_IdentEtc_Item_End_KwDollarOper: public Base
{
public:		// variables
	enum class Kind
	{
		Firstel,
		Lastel,
	};
	Kind kind;
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_IdentEtc_Item_End_KwDollarOper, Base);
};


using BaseClassOfExpr_CallSubprog_Regular = HasChildrenBase
	<shared_ptr<Expr_IdentEtc_Item>>;
class Expr_CallSubprog_Regular: public BaseClassOfExpr_CallSubprog_Regular
{
public:		// variables
	optional<shared_ptr<TypenameOrModname>> opt_typename_or_modname;
	string name;
	optional<shared_ptr<InstParamList>> opt_param_list;
	shared_ptr<InstArgList> arg_list;
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_CallSubprog_Regular,
		BaseClassOfExpr_CallSubprog_Regular);
};
class Expr_CallSubprog_PseudoOper: public Base
{
public:		// variables
	variant<shared_ptr<Expr_IdentEtc>, shared_ptr<Expr>> left;
	string name;
	optional<shared_ptr<InstParamList>> opt_param_list;
	shared_ptr<Expr> right;
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_CallSubprog_PseudoOper, Base);
};


#undef SHARED_FUNC_CONTENTS

} // namespace ast

} // namespace fling_hdl

#endif		// src_ast_node_classes_hpp
