#ifndef src_sym_data_module_etc_classes_hpp
#define src_sym_data_module_etc_classes_hpp

// src/sym_data/module_etc_classes.hpp

#include "../misc_includes.hpp"

namespace fling_hdl
{
namespace sym_data
{

//--------
class Module final: public Base
{
public:		// functions
	Module();
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Module);
	virtual inline ~Module() = default;
};

class InstModule final: public Base
{
private:		// variables
	Symbol* _modnm = nullptr;

public:		// functions
	InstModule(Symbol* s_modnm);
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(InstModule);
	virtual inline ~InstModule() = default;
};
//--------

} // namespace sym_data
} // namespace fling_hdl


#endif		// src_sym_data_module_etc_classes_hpp
