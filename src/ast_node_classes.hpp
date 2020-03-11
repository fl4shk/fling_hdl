#ifndef src_ast_node_classes_hpp
#define src_ast_node_classes_hpp

// src/ast_node_classes.hpp

#include "misc_includes.hpp"

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
};

class DeclPackage;
class DeclModule;

class DeclType;
class DeclSubprog;
class DeclAlias;

class Program: public Base
{
private:		// variables
	vector<variant<DeclPackage, DeclModule, DeclType, DeclSubprog,
		DeclAlias>> _children;
public:		// functions
	SHARED_FUNC_CONTENTS(Program);

	GEN_GETTER_BY_CON_REF(children)
	GEN_SETTER_BY_RVAL_REF(children)
};

class DeclPackage: public Base
{
private:		// variables
	vector
public:		// functions
};

#undef SHARED_FUNC_CONTENTS

} // namespace ast

} // namespace fling_hdl

#endif		// src_ast_node_classes_hpp
