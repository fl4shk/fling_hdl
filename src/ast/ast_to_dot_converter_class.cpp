// This file is part of Fling HDL.
//
// Copyright 2020 Andrew Clark (FL4SHK)
//
// Fling HDL is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Fling HDL is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Fling HDL.  If not, see <https://www.gnu.org/licenses/>.

#include "ast_to_dot_converter_class.hpp"

namespace fling_hdl
{
namespace ast
{

void AstToDotConverter::convert(const string& dst_filename,
	size_t max_ast_level, const BaseUptr& ast_root)
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

void AstToDotConverter::_build_label_map(Base* n)
{
	auto temp = sconcat(_memb_name, "\\n", "id:  ", n->id()); \

	const auto wrapped_data = n->wrap_data();

	if (wrapped_data.size() > 0)
	{
		temp += sconcat("\\n---- ---- ---- ----\\n", wrapped_data); \
	}

	_label_map[n] = move(temp);
}

void AstToDotConverter::_build_conn_map(Base* n)
{
	if (n->parent() != nullptr)
	{
		_conn_map[n->parent()].push_back(n);
	}
	//else
	//{
	//	printout("testificate\n");
	//}
}

#define GEN_VISIT_FUNC(type) \
	void AstToDotConverter::visit##type(type* n) \
	{ \
		switch (_state) \
		{ \
		/* -------- */ \
		case State::BuildNodeVec: \
			_update_node_vec_size(n); \
			_node_vec.at(n->level()).push_back(n); \
			break; \
		case State::BuildLabelMap: \
			_build_label_map(n); \
			break; \
		case State::BuildConnMap: \
			_build_conn_map(n); \
			break; \
		/* -------- */ \
		} \
		n->accept_children(this); \
	}
LIST_OF_AST_NODE_CLASSES(GEN_VISIT_FUNC)
#undef GEN_VISIT_FUNC

} // namespace ast
} // namespace fling_hdl
