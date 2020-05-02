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
Module::~Module()
{
}

InstModule::InstModule(Symbol* s_modnm)
	: Base(), _modnm(s_modnm)
{
}
InstModule::~InstModule()
{
}
//--------

} // namespace sym_data
} // namespace fling_hdl
