#ifndef src_interpreter_class_hpp
#define src_interpreter_class_hpp

// src/interpreter_class.hpp

#include "misc_includes.hpp"
#include "sem_analyzer_and_eval_class.hpp"

namespace fling_hdl
{

class Interpreter final: public AstVisitor
{
public:		// functions
	Interpreter(AstEtcMap* s_ast_etc_map);
	~Interpreter();
	int run();

private:		// functions
};

}

#endif		// src_interpreter_class_hpp
