#include "sym_data_classes.hpp"


namespace fling_hdl
{
namespace sym_data
{

//--------
Module::Module()
	: Base()
{
}

InstModule::InstModule(Symbol* s_modnm)
	: Base(), _modnm(s_modnm)
{
}
//--------

} // namespace sym_data
} // namespace fling_hdl
