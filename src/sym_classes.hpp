#ifndef src_sym_classes_hpp
#define src_sym_classes_hpp

// src/sym_classes.hpp

#include "misc_includes.hpp"
#include "ast_node_classes.hpp"

namespace fling_hdl
{

namespace sym
{

class DeclClass final
{
private:		// variables
	ast::DeclClass* _n = nullptr;
public:		// functions
	GEN_GETTER_BY_VAL(n);
};

} // namespace sym

} // namespace fling_hdl

#endif		// src_sym_classes_hpp
