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

	GEN_GETTER_BCR_AND_SETTER_BRR(children);
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
class DeclParamList: public HasChildrenBase<DeclParamList_Item*>
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

	GEN_GETTER_BCR_AND_SETTER_BRR(name_list);
	GEN_GETTER_AND_SETTER_BY_VAL(kind);
	GEN_GETTER_BCR_AND_SETTER_BRR(opt_def_val_list);
};

class DeclArgList_Item;
class DeclArgList: public HasChildrenBase<DeclArgList_Item*>
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

	GEN_GETTER_BCR_AND_SETTER_BRR(name_list);
	GEN_GETTER_AND_SETTER_BY_VAL(port_type);
	GEN_GETTER_BCR_AND_SETTER_BRR(opt_def_val_list);
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

	GEN_GETTER_BCR_AND_SETTER_BRR(opt_list);
};

class Expr;
class TypenameOrModname;
class InstParamList_Pos: public HasChildrenBase<variant<Expr*,
	TypenameOrModname*>>
{
public:		// functions
	SHARED_FUNC_CONTENTS(InstParamList_Pos);
};

class InstParamList_Named_Item;
class InstParamList_Named:
	public HasChildrenBase<InstParamList_Named_Item*>
{
public:		// functions
	SHARED_FUNC_CONTENTS(InstParamList_Named);
};

class Ident;
class InstParamList_Named_Item: public Base
{
public:		// types
	using Rhs = typename InstParamList_Pos::Child;

private:		// variables
	shared_ptr<Ident> _name = nullptr;
	Rhs _rhs;
public:		// functions
	SHARED_FUNC_CONTENTS(InstParamList_Named_Item);

	GEN_GETTER_AND_SETTER_BY_VAL(name);
	GEN_GETTER_BCR_AND_SETTER_BRR(rhs);
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

#undef SHARED_FUNC_CONTENTS

} // namespace ast

} // namespace fling_hdl

#endif		// src_ast_node_classes_hpp
