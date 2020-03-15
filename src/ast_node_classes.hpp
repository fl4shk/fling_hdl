#ifndef src_ast_node_classes_hpp
#define src_ast_node_classes_hpp

// src/ast_node_classes.hpp

#include "misc_includes.hpp"
#include "expr_value_class.hpp"

namespace fling_hdl
{

namespace ast
{

#define SHARED_FUNC_CONTENTS(name) \
	inline name() = default; \
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(name); \
	virtual inline ~name() = default; \
	virtual inline string id() const \
	{ \
		return string(#name); \
	}

class Base
{
public:		// variables
	ExprValue ev;
public:		// functions
	SHARED_FUNC_CONTENTS(Base);
	//virtual inline void eval()
	//{
	//}
};

class DeclPackage;
class DeclModule;

class DeclType;
class DeclSubprog;
class DeclAlias;

template<typename ChildType>
class HasChildrenBase: public Base
{
public:		// variables
	using Child = ChildType;
	vector<Child> children;
public:		// functions
	SHARED_FUNC_CONTENTS(HasChildrenBase)
};

class Expr;

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
	SHARED_FUNC_CONTENTS(IfBase);
};

class ExprList;
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
	SHARED_FUNC_CONTENTS(SwitchBase);
};

template<typename ScopeType>
class ForBase: public Base
{
public:		// variables
	string name;
	shared_ptr<Expr> expr_range;
	shared_ptr<ScopeType> scope;
public:		// functions
	SHARED_FUNC_CONTENTS(ForBase);
};
template<typename ScopeType>
class WhileBase: public Base
{
public:		// variables
	shared_ptr<Expr> expr_range;
	shared_ptr<ScopeType> scope;
public:		// functions
	SHARED_FUNC_CONTENTS(WhileBase);
};

template<typename HeaderType, typename ScopeType>
class DeclSubprogBase
{
public:		// variables
	shared_ptr<HeaderType> header;
	shared_ptr<ScopeType> scope;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclSubprogBase);
};


class Program: public HasChildrenBase<variant<shared_ptr<DeclPackage>,
	shared_ptr<DeclModule>, shared_ptr<DeclType>, shared_ptr<DeclSubprog>,
	shared_ptr<DeclAlias>>>
{
public:		// functions
	SHARED_FUNC_CONTENTS(Program);
};

class DeclConst;

class DeclPackage: public HasChildrenBase<variant<shared_ptr<DeclPackage>,
	shared_ptr<DeclModule>, shared_ptr<DeclType>, shared_ptr<DeclSubprog>,
	shared_ptr<DeclAlias>, shared_ptr<DeclConst>>>
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclPackage);
};

class DeclParamList_Item;
class DeclParamList: public HasChildrenBase<shared_ptr<DeclParamList_Item>>
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclParamList);
};

class IdentList;
class TypenameOrModnameList;

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
	SHARED_FUNC_CONTENTS(DeclParamList_Item);
};

class DeclArgList_Item;
class DeclArgList: public HasChildrenBase<shared_ptr<DeclArgList_Item>>
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclArgList);
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
	SHARED_FUNC_CONTENTS(DeclArgList_Item);
};

class InstParamList_Pos;
class InstParamList_Named;
class InstParamList: public Base
{
public:		// variables
	optional<variant<shared_ptr<InstParamList_Pos>,
		shared_ptr<InstParamList_Named>>> opt_list;
public:		// functions
	SHARED_FUNC_CONTENTS(InstParamList);
};

class TypenameOrModname;
class InstParamList_Pos: public HasChildrenBase<variant<shared_ptr<Expr>,
	shared_ptr<TypenameOrModname>>>
{
public:		// functions
	SHARED_FUNC_CONTENTS(InstParamList_Pos);
};

class InstParamList_Named_Item;
class InstParamList_Named:
	public HasChildrenBase<shared_ptr<InstParamList_Named_Item>>
{
public:		// functions
	SHARED_FUNC_CONTENTS(InstParamList_Named);
};

class InstParamList_Named_Item: public Base
{
public:		// variables
	string name;
	typename InstParamList_Pos::Child rhs;
public:		// functions
	SHARED_FUNC_CONTENTS(InstParamList_Named_Item);
};

class InstArgList_Named;
class InstArgList: public Base
{
public:		// variables
	optional<variant<shared_ptr<ExprList>,
		shared_ptr<InstArgList_Named>>> opt_list;
public:		// functions
	SHARED_FUNC_CONTENTS(InstArgList);
};

class InstArgList_Named_Item;
class InstArgList_Named:
	public HasChildrenBase<shared_ptr<InstArgList_Named_Item>>
{
public:		// functions
	SHARED_FUNC_CONTENTS(InstArgList_Named);
};

class InstArgList_Named_Item: public Base
{
private:		// variables
	string _name;
	shared_ptr<Expr> _expr;
public:		// functions
	SHARED_FUNC_CONTENTS(InstArgList_Named_Item);
};

class ImportList;
class DeclModule_Scope;
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
	SHARED_FUNC_CONTENTS(DeclModule);
};

class InstModule;
class Expr_CallSubprog;
class Gen;
class ContAssign;
class Behav;
class DeclWire;
class DeclVar;

class DeclModule_Scope: public HasChildrenBase<variant
	<shared_ptr<InstModule>, shared_ptr<Expr_CallSubprog>,
	shared_ptr<Gen>, shared_ptr<ContAssign>, shared_ptr<ImportList>,
	shared_ptr<Behav>, shared_ptr<DeclWire>, shared_ptr<DeclVar>,
	shared_ptr<DeclConst>, shared_ptr<DeclType>, shared_ptr<DeclSubprog>,
	shared_ptr<DeclAlias>>>
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclModule_Scope);
};

class InstModule: public Base
{
public:		// variables
	string name;
	shared_ptr<TypenameOrModname> typename_or_modname;
	shared_ptr<InstArgList> inst_arg_list;
public:		// functions
	SHARED_FUNC_CONTENTS(InstModule);
};

class Gen_If;
class Gen_Switch;
class Gen_For;
class Gen: public Base
{
public:		// variables
	using SpecificGen = variant<shared_ptr<Gen_If>,
		shared_ptr<Gen_Switch>, shared_ptr<Gen_For>>;
	SpecificGen specific_generate;
public:		// functions
	SHARED_FUNC_CONTENTS(Gen);
};

class Gen_If: public IfBase<DeclModule_Scope>
{
public:		// functions
	SHARED_FUNC_CONTENTS(Gen_If);
};

class Gen_Switch: public SwitchBase<DeclModule_Scope>
{
public:		// functions
	SHARED_FUNC_CONTENTS(Gen_Switch);
};

class Gen_For: public Base
{
public:		// variables
	string label, name;
	shared_ptr<Expr> range;
	shared_ptr<DeclModule_Scope> scope;
public:		// functions
	SHARED_FUNC_CONTENTS(Gen_For);
};

class ContAssign: public Base
{
public:		// variables
	shared_ptr<Expr> lhs, rhs;
public:		// functions
	SHARED_FUNC_CONTENTS(ContAssign);
};

class Behav_Seq_EdgeList;
class Behav_Scope;
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
	SHARED_FUNC_CONTENTS(Behav);
};

class Behav_Seq_EdgeList_Item;
class Behav_Seq_EdgeList:
	public HasChildrenBase<shared_ptr<Behav_Seq_EdgeList_Item>>
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Seq_EdgeList);
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
	SHARED_FUNC_CONTENTS(Behav_Seq_EdgeList_Item);
};

class Behav_Item_BlkAssign;
class Behav_Item_NonBlkAssign;

class Behav_Item_If;
class Behav_Item_Switch;
class Behav_Item_Switchz;
class Behav_Item_For;
class Behav_Item_While;
class Behav_Scope: public HasChildrenBase<variant<shared_ptr<Behav_Scope>,
	shared_ptr<DeclAlias>, shared_ptr<DeclVar>, shared_ptr<DeclConst>,
	shared_ptr<DeclType>, shared_ptr<Behav_Item_BlkAssign>,
	shared_ptr<Behav_Item_NonBlkAssign>, shared_ptr<Behav_Item_If>,
	shared_ptr<Behav_Item_Switch>, shared_ptr<Behav_Item_Switchz>,
	shared_ptr<Behav_Item_For>, shared_ptr<Behav_Item_While>,
	shared_ptr<Expr_CallSubprog>>>
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Scope);
};

class Behav_Item_If: public IfBase<Behav_Scope>
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Item_If);
};
class Behav_Item_Switch: public SwitchBase<Behav_Scope>
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Item_Switch);
};
class Behav_Item_Switchz: public SwitchBase<Behav_Scope>
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Item_Switchz);
};
class Behav_Item_For: public ForBase<Behav_Scope>
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Item_For);
};
class Behav_Item_While: public WhileBase<Behav_Scope>
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Item_While);
};

class Behav_Item_NonBlkAssign: public ContAssign
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Item_NonBlkAssign);
};
class Behav_Item_BlkAssign: public ContAssign
{
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Item_BlkAssign);
};

class DeclWire: public Base
{
public:		// variables
	shared_ptr<IdentList> name_list;
	shared_ptr<TypenameOrModname> typename_or_modname;
	optional<shared_ptr<ExprList>> opt_expr_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclWire);
};
class DeclVar: public DeclWire
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclVar);
};
class DeclConst: public Base
{
public:		// variables
	shared_ptr<IdentList> name_list;
	shared_ptr<TypenameOrModname> typename_or_modname;
	shared_ptr<ExprList> expr_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclConst);
};

class DeclEnum;
class DeclClass;
class DeclMixin;
class DeclType: public Base
{
public:		// variables
	variant<shared_ptr<DeclEnum>, shared_ptr<DeclClass>,
		shared_ptr<DeclMixin>> item;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclType);
};

class DeclEnum: public Base
{
public:		// variables
	string name;

	optional<shared_ptr<TypenameOrModname>> opt_typename_or_modname;

	shared_ptr<IdentList> ident_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclEnum);
};

class DeclClass_Item_DeclVar;
class DeclClsOrMxn_Item_DeclType;
class DeclClsOrMxn_Item_DeclAliasOrConst;
class DeclClsOrMxn_Item_DeclSubprog_FullDefn;
class DeclClsOrMxn_Item_DeclSubprog_Abstract;
class DeclClass: public HasChildrenBase<variant
	<shared_ptr<DeclClass_Item_DeclVar>,
	shared_ptr<DeclClsOrMxn_Item_DeclType>,
	shared_ptr<DeclClsOrMxn_Item_DeclAliasOrConst>,
	shared_ptr<DeclClsOrMxn_Item_DeclSubprog_FullDefn>,
	shared_ptr<DeclClsOrMxn_Item_DeclSubprog_Abstract>,
	shared_ptr<ImportList>>>
{
public:		// variables
	bool is_base = false,
		is_signed = false,
		is_packed = false;
	string name;
	shared_ptr<DeclParamList> param_list;
	optional<shared_ptr<TypenameOrModnameList>> opt_extends;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClass);

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
	SHARED_FUNC_CONTENTS(DeclClass_Item_DeclVar);
};

class DeclClsOrMxn_Item_DeclType: public Base
{
public:		// variables
	AccessSpecifier access_spec = AccessSpecifier::Pub;
	shared_ptr<DeclType> decl_type;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClsOrMxn_Item_DeclType);
};

class DeclClsOrMxn_Item_DeclAliasOrConst: public Base
{
public:		// variables
	AccessSpecifier access_spec = AccessSpecifier::Pub;
	bool is_static = false;
	variant<shared_ptr<DeclAlias>, shared_ptr<DeclConst>> item;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClsOrMxn_Item_DeclAliasOrConst);
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
	SHARED_FUNC_CONTENTS(DeclClsOrMxn_Item_DeclSubprog_FullDefn);
};

class DeclFunc_Header;
class DeclTask_Header;
class DeclProc_Header;

class DeclClsOrMxn_Item_DeclSubprog_Abstract: public Base
{
public:		// variables
	AccessSpecifier access_spec = AccessSpecifier::Pub;
	bool is_const = false;
	variant<shared_ptr<DeclFunc_Header>, shared_ptr<DeclTask_Header>,
		shared_ptr<DeclProc_Header>> header;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclClsOrMxn_Item_DeclSubprog_Abstract);
};

class DeclMixin: public HasChildrenBase<variant
	<shared_ptr<DeclClsOrMxn_Item_DeclType>,
	shared_ptr<DeclClsOrMxn_Item_DeclAliasOrConst>,
	shared_ptr<DeclClsOrMxn_Item_DeclSubprog_FullDefn>,
	shared_ptr<DeclClsOrMxn_Item_DeclSubprog_Abstract>,
	shared_ptr<ImportList>>>
{
public:		// variables
	bool is_base = false;
	string name;
	shared_ptr<DeclParamList> param_list;
	optional<shared_ptr<TypenameOrModnameList>> opt_extends;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclMixin);
};

class DeclFunc;
class DeclTask;
class DeclProc;
class DeclSubprog: public Base
{
public:		// variables
	variant<shared_ptr<DeclFunc>, shared_ptr<DeclTask>,
		shared_ptr<DeclProc>> item;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclSubprog);
};

class DeclFunc_Scope;
class DeclFunc: public DeclSubprogBase<DeclFunc_Header,
	DeclFunc_Scope>
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclFunc);
};

class DeclFunc_Header: public Base
{
public:		// variables
	string name;
	optional<shared_ptr<DeclParamList>> opt_param_list;
	shared_ptr<DeclArgList> arg_list;
	shared_ptr<TypenameOrModname> rtn_type;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclFunc_Header);
};

class DeclFunc_Item_If;
class DeclFunc_Item_Switch;
class DeclFunc_Item_Switchz;
class DeclFunc_Item_For;
class DeclFunc_Item_While;
class DeclFunc_Scope: public HasChildrenBase<variant
	<shared_ptr<Expr>, // return
	shared_ptr<DeclFunc_Scope>, shared_ptr<DeclAlias>,
	shared_ptr<DeclVar>, shared_ptr<DeclConst>, shared_ptr<DeclType>,
	shared_ptr<Behav_Item_BlkAssign>,
	shared_ptr<DeclFunc_Item_If>, shared_ptr<DeclFunc_Item_Switch>,
	shared_ptr<DeclFunc_Item_Switchz>, shared_ptr<DeclFunc_Item_For>,
	shared_ptr<DeclFunc_Item_While>, shared_ptr<Expr_CallSubprog>>>
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclFunc_Scope);
};

class DeclFunc_Item_If: public IfBase<DeclFunc_Scope>
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclFunc_Item_If);
};

class DeclFunc_Item_Switch: public SwitchBase<DeclFunc_Scope>
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclFunc_Item_Switch);
};
class DeclFunc_Item_Switchz: public SwitchBase<DeclFunc_Scope>
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclFunc_Item_Switchz);
};
class DeclFunc_Item_For: public ForBase<DeclFunc_Scope>
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclFunc_Item_For);
};
class DeclFunc_Item_While: public WhileBase<DeclFunc_Scope>
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclFunc_Item_While);
};


class DeclTask_Header;
class DeclTask_Scope;
class DeclTask: public DeclSubprogBase<DeclTask_Header, DeclTask_Scope>
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclTask);
};

class DeclTask_Header: public Base
{
public:		// variables
	string name;
	optional<shared_ptr<DeclParamList>> opt_param_list;
	shared_ptr<DeclArgList> arg_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclTask_Header);
};

class DeclTask_Item_If;
class DeclTask_Item_Switch;
class DeclTask_Item_Switchz;
class DeclTask_Item_For;
class DeclTask_Item_While;
class DeclTask_Scope: public HasChildrenBase<variant
	<shared_ptr<DeclTask_Scope>, shared_ptr<DeclAlias>,
	shared_ptr<DeclVar>, shared_ptr<DeclConst>, shared_ptr<DeclType>,
	shared_ptr<Behav_Item_BlkAssign>, shared_ptr<Behav_Item_NonBlkAssign>,
	shared_ptr<DeclTask_Item_If>, shared_ptr<DeclTask_Item_Switch>,
	shared_ptr<DeclTask_Item_Switchz>, shared_ptr<DeclTask_Item_For>,
	shared_ptr<DeclTask_Item_While>, shared_ptr<Expr_CallSubprog>>>
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclTask_Scope);
};


class DeclTask_Item_If: public IfBase<DeclTask_Scope>
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclTask_Item_If);
};

class DeclTask_Item_Switch: public SwitchBase<DeclTask_Scope>
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclTask_Item_Switch);
};
class DeclTask_Item_Switchz: public SwitchBase<DeclTask_Scope>
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclTask_Item_Switchz);
};
class DeclTask_Item_For: public ForBase<DeclTask_Scope>
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclTask_Item_For);
};
class DeclTask_Item_While: public WhileBase<DeclTask_Scope>
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclTask_Item_While);
};

class DeclProc_Header;
class DeclProc: public DeclSubprogBase<DeclProc_Header, DeclModule_Scope>
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclProc);
};

class DeclProc_ArgList;
class DeclProc_Header: public Base
{
public:		// variables
	string name;
	optional<shared_ptr<DeclParamList>> opt_param_list;
	shared_ptr<DeclProc_ArgList> arg_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclProc_Header);
};

class DeclProc_ArgList_Item;
class DeclProc_ArgList: public HasChildrenBase
	<shared_ptr<DeclProc_ArgList_Item>>
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclProc_ArgList);
};

class DeclProc_ArgList_Item: public Base
{
public:		// variables
	shared_ptr<IdentList> name_list;
	bool is_ref = false;
	shared_ptr<TypenameOrModname> typename_or_modname;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclProc_ArgList_Item);
};

class DeclAlias_Value;
class DeclAlias_Type;
class DeclAlias_Module;
class DeclAlias: public Base
{
public:		// variables
	variant<shared_ptr<DeclAlias_Value>, shared_ptr<DeclAlias_Type>,
		shared_ptr<DeclAlias_Module>> item;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclAlias);
};

class DeclAlias_Value: public Base
{
public:		// variables
	shared_ptr<IdentList> name_list;
	shared_ptr<TypenameOrModname> typename_or_modname;
	shared_ptr<ExprList> expr_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclAlias_Value);
};

class DeclAlias_Type: public Base
{
public:		// variables
	shared_ptr<IdentList> name_list;
	shared_ptr<TypenameOrModnameList> typename_or_modname_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclAlias_Type);
};
class DeclAlias_Module: public Base
{
public:		// variables
	shared_ptr<IdentList> name_list;
	shared_ptr<TypenameOrModnameList> typename_or_modname_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclAlias_Module);
};

class IdentList: public HasChildrenBase<string>
{
public:		// functions
	SHARED_FUNC_CONTENTS(IdentList);
};

class ScopedIdent: public IdentList
{
public:		// functions
	SHARED_FUNC_CONTENTS(ScopedIdent);
};

class ExprList: public HasChildrenBase<Expr>
{
public:		// functions
	SHARED_FUNC_CONTENTS(ExprList);
};

class TypenameOrModnameList: public HasChildrenBase<TypenameOrModname>
{
public:		// functions
	SHARED_FUNC_CONTENTS(TypenameOrModnameList);
};

class ImportList: public HasChildrenBase<ScopedIdent>
{
public:		// functions
	SHARED_FUNC_CONTENTS(ImportList);
};

class TypenameOrModname_SelfT: public Base
{
public:		// functions
	SHARED_FUNC_CONTENTS(TypenameOrModname_SelfT);
};
class TypenameOrModname_RetT: public Base
{
public:		// functions
	SHARED_FUNC_CONTENTS(TypenameOrModname_RetT);
};

class TypenameOrModname_Cstm;
class TypenameOrModname_Builtin;
class TypenameOrModname: public Base
{
public:		// variables
	variant<shared_ptr<TypenameOrModname_Cstm>,
		shared_ptr<TypenameOrModname_SelfT>,
		shared_ptr<TypenameOrModname_RetT>,
		shared_ptr<TypenameOrModname_Builtin>> item;
public:		// functions
	SHARED_FUNC_CONTENTS(TypenameOrModname);
};

class TypenameOrModname_Cstm_Item;
class TypenameOrModname_Cstm: public Base
{
public:		// variables
	vector<shared_ptr<TypenameOrModname_Cstm_Item>> item_vec;

	using OneArrDim = variant<shared_ptr<Expr>,
		shared_ptr<TypenameOrModname_Builtin>>;
	vector<optional<OneArrDim>> arr_dim_vec;
public:		// functions
	SHARED_FUNC_CONTENTS(TypenameOrModname_Cstm);
};

class TypenameOrModname_Cstm_Item: public Base
{
public:		// variables
	shared_ptr<ScopedIdent> scoped_ident;
	optional<shared_ptr<InstParamList>> opt_param_list;
public:		// functions
	SHARED_FUNC_CONTENTS(TypenameOrModname_Cstm_Item);
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
	SHARED_FUNC_CONTENTS(TypenameOrModname_Builtin);
};

class Expr_Mux;

class Expr_LogOr;
class Expr_LogAnd;

class Expr_BinopBitOr;
class Expr_BinopBitNor;
class Expr_BinopBitAnd;
class Expr_BinopBitNand;
class Expr_BinopBitXor;
class Expr_BinopBitXnor;

class Expr_CmpEq;
class Expr_CmpNe;
class Expr_CaseCmpEq;
class Expr_CaseCmpNe;

class Expr_CmpLt;
class Expr_CmpLe;
class Expr_CmpGt;
class Expr_CmpGe;

class Expr_BitLsl;
class Expr_BitLsr;
class Expr_BitAsr;

class Expr_BinopPlus;
class Expr_BinopMinus;

class Expr_Mul;
class Expr_Div;
class Expr_Mod;

class Expr_UnopPlus;
class Expr_UnopMinus;
class Expr_LogNot;
class Expr_BitNot;

class Expr_UnopBitOr;
class Expr_UnopBitNor;
class Expr_UnopBitAnd;
class Expr_UnopBitNand;
class Expr_UnopBitXor;
class Expr_UnopBitXnor;

class Expr_Literal;
class Expr_Sized;
class Expr_Range;
class Expr_Cat;
class Expr_Repl;
class Expr_KwDollarFuncOf_NonPow;
class Expr_KwDollarFuncOf_Pow;
class Expr_IdentEtcAndOptKwDollarFuncOf;
class Expr_IdentEtc;
class Expr_IdentEtc_Item;
class Expr_IdentEtc_Item_End_Index;
class Expr_IdentEtc_Item_End_SubprogCallSuffix;
class Expr_IdentEtc_Item_End_KwDollarOper;
class Expr_CallSubprog_Regular;
class Expr_CallSubprog_PseudoOper;

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
	SHARED_FUNC_CONTENTS(Expr);
};

class Expr_Mux: public Base
{
public:		// variables
	shared_ptr<Expr> cond, when_true, when_false;
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_Mux);
};

class ExprBinopBase: public Base
{
public:		// variables
	shared_ptr<Expr> left, right;
public:		// functions
	SHARED_FUNC_CONTENTS(ExprBinopBase);
};
class ExprUnopBase: public Base
{
public:		// variables
	shared_ptr<Expr> arg;
public:		// functions
	SHARED_FUNC_CONTENTS(ExprUnopBase);
};

class Expr_LogOr: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_LogOr);
};
class Expr_LogAnd: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_LogAnd);
};

class Expr_BinopBitOr: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BinopBitOr);
};
class Expr_BinopBitNor: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BinopBitNor);
};
class Expr_BinopBitAnd: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BinopBitAnd);
};
class Expr_BinopBitNand: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BinopBitNand);
};
class Expr_BinopBitXor: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BinopBitXor);
};
class Expr_BinopBitXnor: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BinopBitXnor);
};

class Expr_CmpEq: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_CmpEq);
};
class Expr_CmpNe: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_CmpNe);
};
class Expr_CaseCmpEq: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_CaseCmpEq);
};
class Expr_CaseCmpNe: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_CaseCmpNe);
};

class Expr_CmpLt: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_CmpLt);
};
class Expr_CmpLe: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_CmpLe);
};
class Expr_CmpGt: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_CmpGt);
};
class Expr_CmpGe: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_CmpGe);
};

class Expr_BitLsl: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BitLsl);
};
class Expr_BitLsr: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BitLsr);
};
class Expr_BitAsr: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BitAsr);
};

class Expr_BinopPlus: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BinopPlus);
};
class Expr_BinopMinus: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BinopMinus);
};

class Expr_Mul: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_Mul);
};
class Expr_Div: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_Div);
};
class Expr_Mod: public ExprBinopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_Mod);
};

class Expr_UnopPlus: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_UnopPlus);
};
class Expr_UnopMinus: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_UnopMinus);
};
class Expr_LogNot: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_LogNot);
};
class Expr_BitNot: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_BitNot);
};

class Expr_UnopBitOr: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_UnopBitOr);
};
class Expr_UnopBitNor: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_UnopBitNor);
};
class Expr_UnopBitAnd: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_UnopBitAnd);
};
class Expr_UnopBitNand: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_UnopBitNand);
};
class Expr_UnopBitXor: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_UnopBitXor);
};
class Expr_UnopBitXnor: public ExprUnopBase
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_UnopBitXnor);
};

// Continue here
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
	SHARED_FUNC_CONTENTS(Expr_Literal);
};
class Expr_Sized: public Base
{
public:		// variables
	shared_ptr<Expr> size, to_size;
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_Sized);
};
class Expr_Range: public Base
{
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_Range);
};
class Expr_Cat: public Base
{
public:		// variables
	shared_ptr<ExprList> expr_list;
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_Cat);
};
class Expr_Repl: public Base
{
public:		// variables
	shared_ptr<Expr> width, to_repl;
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_Repl);
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
	SHARED_FUNC_CONTENTS(Expr_KwDollarFuncOf_NonPow);
};
class Expr_KwDollarFuncOf_Pow: public Base
{
public:		// variables
	shared_ptr<Expr> left, right;
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_KwDollarFuncOf_Pow);
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
	SHARED_FUNC_CONTENTS(Expr_IdentEtcAndOptKwDollarFuncOf);
};
class Expr_IdentEtc: public Base
{
public:		// variables
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_IdentEtc);
};
class Expr_IdentEtc_Item: public Base
{
public:		// variables
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_IdentEtc_Item);
};
class Expr_IdentEtc_Item_End_Index: public Base
{
public:		// variables
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_IdentEtc_Item_End_Index);
};
class Expr_IdentEtc_Item_End_SubprogCallSuffix: public Base
{
public:		// variables
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_IdentEtc_Item_End_SubprogCallSuffix);
};
class Expr_IdentEtc_Item_End_KwDollarOper: public Base
{
public:		// variables
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_IdentEtc_Item_End_KwDollarOper);
};
class Expr_CallSubprog_Regular: public Base
{
public:		// variables
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_CallSubprog_Regular);
};
class Expr_CallSubprog_PseudoOper: public Base
{
public:		// variables
public:		// functions
	SHARED_FUNC_CONTENTS(Expr_CallSubprog_PseudoOper);
};


#undef SHARED_FUNC_CONTENTS

} // namespace ast

} // namespace fling_hdl

#endif		// src_ast_node_classes_hpp
