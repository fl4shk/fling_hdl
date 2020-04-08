#ifndef src_master_class_hpp
#define src_master_class_hpp

// src/master_class.hpp

#include "pt_visitor_class.hpp"
#include "ast_to_dot_converter_class.hpp"

namespace fling_hdl
{

// This is a glorified command-line argument parser and simple driver for
// the *main* classes.
class Master final
{
private:		// variables
	int _argc;
	char** _argv;

	set<string> _filename_set;

	class Opt final
	{
	public:		// types
		enum class RunType
		{
			OutVerilog,
			OutDot,
			Interpret,
		};
	public:		// variables
		RunType run_type;
		string out_dir;
	public:		// functions
		inline Opt() = default;
		GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Opt);
		inline ~Opt() = default;
	} _opt;


public:		// functions
	Master(int s_argc, char** s_argv);
	~Master();
	int run();

	GEN_GETTER_BY_CON_REF(filename_set);
	GEN_GETTER_BY_CON_REF(opt);
};

} // namespace fling_hdl

#endif		// src_master_class_hpp
