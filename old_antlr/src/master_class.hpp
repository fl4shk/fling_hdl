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

	set<string> _src_filename_set;
	map<string, string> _src_filename_to_dst_filename_map;

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
		RunType run_type = RunType::OutVerilog;
		string out_dir, top_ident;
		bool need_out_dir = true, need_top_ident = true;
	public:		// functions
		inline Opt() = default;
		GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Opt);
		inline ~Opt() = default;

		// Returns the output file path as a string.
		inline string create_ofile_dirs(const string& ifile_path_str,
			const string& ofile_ext) const
		{
			fs::path pre_ofile_path = ifile_path_str;
			pre_ofile_path.replace_extension(ofile_ext);

			const fs::path ret = sconcat(out_dir, "/", pre_ofile_path);

			fs::path full_odir_path = ret;
			full_odir_path.remove_filename();

			fs::create_directories(full_odir_path);

			return static_cast<string>(ret);
		}
	} _opt;


public:		// functions
	Master(int s_argc, char** s_argv);
	~Master();
	int run();

	GEN_GETTER_BY_CON_REF(src_filename_set);
	GEN_GETTER_BY_CON_REF(opt);

private:		// functions
	inline void _usage() const
	{
		printerr("Usage:  ", _argv[0], " <options> <input files...>\n");
		exit(1);
	}
	void _create_ofile_dirs(const string& ofile_ext,
		const map<string, AstEtc>& ast_etc_map);
};

} // namespace fling_hdl

#endif		// src_master_class_hpp
