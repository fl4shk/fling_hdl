#ifndef src_ast_node_classes_hpp
#define src_ast_node_classes_hpp

// src/ast_node_classes.hpp

#include "misc_includes.hpp"
#include "expr_value_class.hpp"

namespace fling_hdl
{

class AstVisitor;

namespace ast
{

#define SHARED_FUNC_CONTENTS(name) \
	inline name() = default; \
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(name); \
	virtual inline ~name() = default; \
	virtual void accept(AstVisitor& visitor); \
	virtual inline string id() const \
	{ \
		return string(#name); \
	}
#define GEN_AST_GETTER_AND_SETTER(name) \
	GEN_GETTER_BCR_AND_SETTER_BRR(name)

class Base
{
public:		// functions
	SHARED_FUNC_CONTENTS(Base)
	virtual inline void eval()
	{
	}
};

class DeclPackage;
class DeclModule;

class DeclType;
class DeclSubprog;
class DeclAlias;

template<typename ChildType>
class HasChildrenBase: public Base
{
public:		// types
	using Child = ChildType;
protected:		// variables
	vector<Child> _children;
public:		// functions
	SHARED_FUNC_CONTENTS(HasChildrenBase)

	GEN_AST_GETTER_AND_SETTER(children);
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
class ExprList;
class TypenameOrModnameList;

class DeclParamList_Item: public Base
{
public:		// types
	enum class Kind
	{
		Val,
		Type,
		Module,
	};
	using OptDefValList = optional<variant<shared_ptr<ExprList>,
		shared_ptr<TypenameOrModnameList>>>;
private:		// variables
	shared_ptr<IdentList> _name_list = nullptr;
	Kind _kind;
	OptDefValList _opt_def_val_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclParamList_Item);

	GEN_AST_GETTER_AND_SETTER(name_list);
	GEN_GETTER_AND_SETTER_BY_VAL(kind);
	GEN_AST_GETTER_AND_SETTER(opt_def_val_list);
};

class DeclArgList_Item;
class DeclArgList: public HasChildrenBase<shared_ptr<DeclArgList_Item>>
{
public:		// functions
	SHARED_FUNC_CONTENTS(DeclArgList);
};

class DeclArgList_Item: public Base
{
public:		// types
	enum class PortType
	{
		Input,
		Output,
		Inout,
		Interface
	};
	using OptDefValList = optional<shared_ptr<ExprList>>;
private:		// variables
	shared_ptr<IdentList> _name_list;
	PortType _port_type;
	OptDefValList _opt_def_val_list;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclArgList_Item);

	GEN_AST_GETTER_AND_SETTER(name_list);
	GEN_GETTER_AND_SETTER_BY_VAL(port_type);
	GEN_AST_GETTER_AND_SETTER(opt_def_val_list);
};

class InstParamList_Pos;
class InstParamList_Named;
class InstParamList: public Base
{
public:		// types
	using OptList = optional<variant<shared_ptr<InstParamList_Pos>,
		shared_ptr<InstParamList_Named>>>;
private:		// variables
	OptList _opt_list;
public:		// functions
	SHARED_FUNC_CONTENTS(InstParamList);

	GEN_AST_GETTER_AND_SETTER(opt_list);
};

class Expr;
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
public:		// types
	using Rhs = typename InstParamList_Pos::Child;

private:		// variables
	string _name;
	Rhs _rhs;
public:		// functions
	SHARED_FUNC_CONTENTS(InstParamList_Named_Item);

	GEN_AST_GETTER_AND_SETTER(name);
	GEN_AST_GETTER_AND_SETTER(rhs);
};

class InstArgList_Named;
class InstArgList: public Base
{
public:		// types
	using OptList = optional<variant<shared_ptr<ExprList>,
		shared_ptr<InstArgList_Named>>>;
private:		// variables
	OptList _opt_list;
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

	GEN_AST_GETTER_AND_SETTER(name);
	GEN_AST_GETTER_AND_SETTER(expr);
};

class ImportList;
class DeclModule_Scope;
class DeclModule: public Base
{
public:		// types
	using OptDeclParamList = optional<shared_ptr<DeclParamList>>;
	using OptImportList = optional<shared_ptr<ImportList>>;
private:		// variables
	string _name;
	OptDeclParamList _opt_decl_param_list;
	shared_ptr<DeclArgList> _decl_arg_list;
	OptImportList _opt_import_list;
	shared_ptr<DeclModule_Scope> _scope;
public:		// functions
	SHARED_FUNC_CONTENTS(DeclModule);

	GEN_AST_GETTER_AND_SETTER(name);
	GEN_AST_GETTER_AND_SETTER(opt_decl_param_list);
	GEN_AST_GETTER_AND_SETTER(decl_arg_list);
	GEN_AST_GETTER_AND_SETTER(opt_import_list);
	GEN_AST_GETTER_AND_SETTER(scope);
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
private:		// variables
	string _name;
	shared_ptr<TypenameOrModname> _typename_or_modname;
	shared_ptr<InstArgList> _inst_arg_list;
public:		// functions
	SHARED_FUNC_CONTENTS(InstModule);

	GEN_AST_GETTER_AND_SETTER(name);
	GEN_AST_GETTER_AND_SETTER(typename_or_modname);
	GEN_AST_GETTER_AND_SETTER(inst_arg_list);
};

class Gen_If;
class Gen_Switch;
class Gen_For;
class Gen: public Base
{
public:		// types
	using SpecificGen = variant<shared_ptr<Gen_If>,
		shared_ptr<Gen_Switch>, shared_ptr<Gen_For>>;
private:		// variables
	SpecificGen _specific_generate;
public:		// functions
	SHARED_FUNC_CONTENTS(Gen);

	GEN_AST_GETTER_AND_SETTER(specific_generate);
};

class Gen_If_Elif;
class Gen_If_Else;
class Gen_If: public Base
{
public:		// types
	using GenElifVec = vector<shared_ptr<Gen_If_Elif>>;
	using OptGenElse = optional<shared_ptr<Gen_If_Else>>;
private:		// variables
	shared_ptr<Expr> _expr;
	shared_ptr<DeclModule_Scope> _scope;
	GenElifVec _gen_elif_vec;
	OptGenElse _opt_gen_else;

public:		// functions
	SHARED_FUNC_CONTENTS(Gen_If);

	GEN_AST_GETTER_AND_SETTER(expr);
	GEN_AST_GETTER_AND_SETTER(scope);
	GEN_AST_GETTER_AND_SETTER(gen_elif_vec);
	GEN_AST_GETTER_AND_SETTER(opt_gen_else);
};

class Gen_If_Elif: public Base
{
private:		// variables
	shared_ptr<Expr> _expr;
	shared_ptr<DeclModule_Scope> _scope;
public:		// functions
	SHARED_FUNC_CONTENTS(Gen_If_Elif);

	GEN_AST_GETTER_AND_SETTER(expr);
	GEN_AST_GETTER_AND_SETTER(scope);
};

class Gen_If_Else: public Base
{
private:		// variables
	shared_ptr<DeclModule_Scope> _scope;
public:		// functions
	SHARED_FUNC_CONTENTS(Gen_If_Else);

	GEN_AST_GETTER_AND_SETTER(scope);
};

class Gen_Switch_Default;
class Gen_Switch_Case;
class Gen_Switch: public Base
{
public:		// types
	using OptGenDefault = optional<shared_ptr<Gen_Switch_Default>>;
	using GenCaseVec = vector<shared_ptr<Gen_Switch_Case>>;
private:		// variables
};

class Gen_Switch_Default: public Base
{
private:		// variables
	shared_ptr<DeclModule_Scope> _scope;
public:		// functions
	SHARED_FUNC_CONTENTS(Gen_Switch_Default);

	GEN_AST_GETTER_AND_SETTER(scope);
};
class Gen_Switch_Case: public Base
{
private:		// variables
	shared_ptr<Expr> _expr;
	shared_ptr<DeclModule_Scope> _scope;
public:		// functions
	SHARED_FUNC_CONTENTS(Gen_Switch_Case);

	GEN_AST_GETTER_AND_SETTER(expr);
	GEN_AST_GETTER_AND_SETTER(scope);
};

class Gen_For: public Base
{
private:		// variables
	string _label, _var_name;
	shared_ptr<Expr> _range;
	shared_ptr<DeclModule_Scope> _scope;
public:		// functions
	SHARED_FUNC_CONTENTS(Gen_For);

	GEN_AST_GETTER_AND_SETTER(label);
	GEN_AST_GETTER_AND_SETTER(var_name);
	GEN_AST_GETTER_AND_SETTER(range);
	GEN_AST_GETTER_AND_SETTER(scope);
};

class ContAssign: public Base
{
private:		// variables
	shared_ptr<Expr> _lhs, _rhs;
public:		// functions
	SHARED_FUNC_CONTENTS(ContAssign);

	GEN_AST_GETTER_AND_SETTER(lhs);
	GEN_AST_GETTER_AND_SETTER(rhs);
};

class Behav_Seq_EdgeList;
class Behav_Scope;
class Behav: public Base
{
public:		// types
	enum class Kind
	{
		Initial,
		Comb,
		Seq,
	};
	using OptEdgeList = optional<shared_ptr<Behav_Seq_EdgeList>>;
private:		// variables
	Kind _kind;
	OptEdgeList _opt_edge_list;
	shared_ptr<Behav_Scope> _scope;
public:		// functions
	SHARED_FUNC_CONTENTS(Behav);

	GEN_GETTER_AND_SETTER_BY_VAL(kind);
	GEN_AST_GETTER_AND_SETTER(opt_edge_list);
	GEN_AST_GETTER_AND_SETTER(scope);
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
public:		// types
	enum class Kind
	{
		Posedge,
		Negedge,
	};
private:		// variables
	Kind _kind;
	shared_ptr<Expr> _expr;
public:		// functions
	SHARED_FUNC_CONTENTS(Behav_Seq_EdgeList_Item);

	GEN_GETTER_AND_SETTER_BY_VAL(kind);
	GEN_AST_GETTER_AND_SETTER(expr);
};

class Behav_BlkAssign;
class Behav_NonBlkAssign;
class Behav_If;
class Behav_SwitchOrSwitchz;
class Behav_For;
class Behav_While;

#undef SHARED_FUNC_CONTENTS
#undef GEN_AST_GETTER_AND_SETTER

} // namespace ast

} // namespace fling_hdl

#endif		// src_ast_node_classes_hpp
