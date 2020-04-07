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

	unique_ptr<PtVisitor> _pt_visitor;
	unique_ptr<AstToDotConverter> _ast_to_dot_converter;
	map<string, AstEtc>* _ast_etc_map = nullptr;
	set<string> _filename_set;

	struct
	{
		bool dot;
		string outdir;
	} _opt;


public:		// functions
	Compiler(int s_argc, char** s_argv);
	~Compiler();
	int run();
};

} // namespace fling_hdl

#endif		// src_compiler_class_hpp
