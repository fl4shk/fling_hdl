#ifndef src_interpreter_class_hpp
#define src_interpreter_class_hpp

// src/interpreter_class.hpp

#include "misc_includes.hpp"
#include "pt_visitor_class.hpp"

namespace fling_hdl
{

class Interpreter final
{
private:		// variables
	PtVisitor* _pt_visitor = nullptr;

public:		// functions
	inline Interpreter(PtVisitor* s_pt_visitor)
		: _pt_visitor(s_pt_visitor)
	{
	}
	inline ~Interpreter() = default;
	int run();

private:		// functions
	inline const auto& _ast_etc_map() const
	{
		return _pt_visitor->ast_etc_map();
	}
};

}

#endif		// src_interpreter_class_hpp
