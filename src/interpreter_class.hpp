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
	map<string, AstEtc>* _ast_etc_map;

public:		// functions
	inline Interpreter() = default;
	inline ~Interpreter() = default;
	int run(const map<string, AstEtc>& ast_etc_map);
};

}

#endif		// src_interpreter_class_hpp
