#ifndef src_interpreter_class_hpp
#define src_interpreter_class_hpp

// src/interpreter_class.hpp

#include "misc_includes.hpp"

namespace fling_hdl
{

class SemAnalyzer;

class Interpreter final
{
private:		// variables
	SemAnalyzer* _sem_analyzer = nullptr;

public:		// functions
	inline Interpreter(SemAnalyzer* s_sem_analyzer)
		: _sem_analyzer(s_sem_analyzer)
	{
	}
	inline ~Interpreter() = default;
	int run();
};

}

#endif		// src_interpreter_class_hpp
