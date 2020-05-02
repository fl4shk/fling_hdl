#ifndef src_sym_data_scope_and_package_etc_classes_hpp
#define src_sym_data_scope_and_package_etc_classes_hpp

// src/sym_data/scope_and_package_etc_classes.hpp

#include "../misc_includes.hpp"

namespace fling_hdl
{
namespace sym_data
{

//--------
// Class for unnamed scopes
class Scope: public Base
{
public:		// functions
	Scope();
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Scope);
	virtual ~Scope();
};

// Class for packages, which are the only kinds of symbols that `import`
// statements work with.
class Package final: public Scope
{
public:		// functions
	Package();
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Package);
	virtual ~Package();
};
//--------

} // namespace sym_data
} // namespace fling_hdl

#endif		// src_sym_data_scope_and_package_etc_classes_hpp
