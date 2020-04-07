#ifndef src_compiler_class_hpp
#define src_compiler_class_hpp

// src/compiler_class.hpp

#include "pt_visitor_class.hpp"
#include "ast_to_dot_converter_class.hpp"

namespace fling_hdl
{

class Compiler final
{
private:		// variables
	int _argc;
	char** _argv;

	map<string, AstEtc>* _ast_etc_map = nullptr;
	set<string> _filename_set;

	class Opt final
	{
	public:		// variables
		bool dot = false;
		string outdir = ".";
	public:		// functions
		inline Opt() = default;
		GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Opt);
		inline ~Opt() = default;
	} _opt;


public:		// functions
	Compiler(int s_argc, char** s_argv);
	~Compiler();
	int run();

	GEN_GETTER_BY_CON_REF(filename_set);
	GEN_GETTER_BY_CON_REF(opt);
};

} // namespace fling_hdl

#endif		// src_compiler_class_hpp
