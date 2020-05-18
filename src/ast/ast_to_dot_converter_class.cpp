#include "ast_to_dot_converter_class.hpp"

namespace fling_hdl
{


void AstToDotConverter::convert(const string& dst_filename,
	size_t max_ast_level, const ast::BaseSptr& ast_root)
{
	_max_ast_level = max_ast_level;
	_file.open(dst_filename, std::ios_base::out | std::ios_base::trunc);

	osprintout(_file,
		"digraph ", "file", "\n",
		"{\n",
		"\tordering=out;\n",
		"\tclusterrank=global;\n",
		"\tsize=\"6,4\";\n",
		"\tratio=fill;\n",
		"\tremincross=true;\n",
		"\trankdir=LR;\n",
		"\tstyle=\"invis\";\n",
		"\tnode [fontname=Helvetica];\n");

	_state = State::BuildNodeVec;
	ast_root->accept(this);

	_state = State::BuildLabelMap;
	ast_root->accept(this);

	_state = State::BuildConnMap;
	ast_root->accept(this);

	for (size_t level=0; level<=max_ast_level; ++level)
	//for (size_t level=0; level<_node_vec.size(); ++level)
	{
		_print_dot_subgraph_cluster(level);
	}
	for (size_t level=0; level<=max_ast_level; ++level)
	{
		_print_dot_wires(level);
	}

	osprintout(_file,
		"}\n");

	_file.close();
}

void AstToDotConverter::_print_dot_subgraph_cluster(size_t level)
{
	osprintout(_file,
		"\tnode [color=\"", _color(level), ",1.0,1.0\"];\n",
		"\tsubgraph cluster_", level, "\n",
		"\t{\n",
		"\t\trank=same;\n");

	for (const auto& p: _node_vec.at(level))
	{
		const auto& label = _label_map.at(p);
		osprintout(_file,
			"\t\t", _node_name(p), " [label=\"", label, "\"];\n");
	}

	osprintout(_file,
		"\t}\n\n");
}
void AstToDotConverter::_print_dot_wires(size_t level)
{
	for (const auto& p: _node_vec.at(level))
	{
		//if (_conn_map.count(p) == 0)
		//{
		//	//printout("RIP\n");
		//	continue;
		//}

		//const auto& conn = _conn_map.at(p);
		//osprintout(_file,
		//	"\t", _node_name(p), " -> ", _node_name(conn),
		//		" [color=\"", _color(level), ",1.0,1.0\"];\n");

		if (_conn_map.count(p) == 0)
		{
			continue;
		}
		for (const auto& q: _conn_map.at(p))
		{
			osprintout(_file,
				"\t", _node_name(p), " -> ", _node_name(q),
					" [color=\"", _color(level), ",1.0,1.0\"];\n");
		}
		osprintout(_file,
			"\n");
	}

	osprintout(_file,
		"\n");
}


#define _INNER_WRAP(item) \
	sconcat(#item, ":  ", n->item)
#define wrap(...) \
	EVAL(MAP(_INNER_WRAP, COMMA, __VA_ARGS__))


#define _INNER_WRAP_CONV(item) \
	sconcat(#item, ":  ", n->conv_##item(n->item))
#define wrap_conv(...) \
	EVAL(MAP(_INNER_WRAP_CONV, COMMA, __VA_ARGS__))

#define _INNER_WRAP_CONV_2(item, ...) \
	sconcat(#item, ":  ", conv_##item(n->item))
#define wrap_conv_2(...) \
	EVAL(MAP(_INNER_WRAP_CONV_2, COMMA, __VA_ARGS__))


#define build(type, ...) \
	void AstToDotConverter::_build_label_map(type* n) \
	{ \
		auto temp = sconcat(_memb_name, "\\n", "id:  ", n->id()); \
		auto to_append = _strjoin2_raw_newline(__VA_ARGS__); \
		if (to_append.size() != 0) \
		{ \
			temp += sconcat("\\n---- ---- ---- ----\\n", to_append); \
		} \
		_label_map[n] = move(temp); \
	}




} // namespace fling_hdl