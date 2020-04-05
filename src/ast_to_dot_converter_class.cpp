#include "ast_to_dot_converter_class.hpp"

namespace fling_hdl
{


void AstToDotConverter::convert(const string& dst_filename,
	const string& src_filename, ast::Base* root)
{
	_file.open(dst_filename, std::ios_base::out | std::ios_base::trunc);

	osprintout(_file,
		"digraph ", src_filename, "\n",
		"{\n",
		"\tordering=out;\n",
		"\tclusterrank=global;\n",
		"\tsize=\"6,4\";\n",
		"\tratio=fill;\n",
		"\tremincross=true;\n",
		"\trankdir=LR;\n",
		"\tstyle=\"invis\";\n",
		"\tnode [fontname=Helvetica];\n");

	osprintout(_file,
		"}\n");
}

} // namespace fling_hdl
