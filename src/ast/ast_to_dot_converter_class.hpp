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

#ifndef src_ast_ast_to_dot_converter_class_hpp
#define src_ast_ast_to_dot_converter_class_hpp

// src/ast/ast_to_dot_converter_class.hpp

#include "../misc_includes.hpp"
#include "ast_visitor_class.hpp"
#include "ast_node_classes.hpp"

namespace fling_hdl
{
namespace ast
{

class AstToDotConverter: public AstVisitor
{
public:		// types
	enum class State
	{
		BuildNodeVec,
		BuildLabelMap,
		BuildConnMap,
	};

protected:		// variables
	fstream _file;
	string _name;
	size_t _max_ast_level;
	State _state;
	vector<vector<Base*>> _node_vec;
	map<Base*, string> _label_map;

	// For easy iteration
	map<Base*, vector<Base*>> _conn_map;
public:		// functions
	inline AstToDotConverter() = default;
	virtual ~AstToDotConverter() = default;

	virtual void convert(const string& dst_filename,
		size_t max_ast_level, const BaseUptr& ast_root);

protected:		// misc. functions
	void _print_dot_subgraph_cluster(size_t level);
	void _print_dot_wires(size_t level);
	inline double _color(size_t level) const
	{
		return (static_cast<double>(level) / (_max_ast_level + 2.0));
	}
	inline void _update_node_vec_size(Base* some_ast)
	{
		while (_node_vec.size() <= some_ast->level())
		{
			_node_vec.push_back(vector<Base*>());
		}
	}
	static std::uintptr_t _ast_to_uintptr(Base* some_ast)
	{
		std::uintptr_t ret;
		memcpy(&ret, &some_ast, sizeof(std::uintptr_t));
		return ret;
	}
	static inline string _node_name(Base* p)
	{
		return sconcat(p->id(), "_", _ast_to_uintptr(p));
	}
	template<typename... ArgTypes>
	static inline string _strjoin2_raw_newline(ArgTypes&&... args)
	{
		return strjoin2("\\n", args...);
	}

protected:		// visitor functions
	virtual void _build_label_map(Base* n);
	virtual void _build_conn_map(Base* n);
	#define GEN_VISIT_FUNC(type) \
		virtual void visit##type(type* n);
	LIST_OF_AST_NODE_CLASSES(GEN_VISIT_FUNC)
	#undef GEN_VISIT_FUNC
};

} // namespace ast
} // namespace fling_hdl

#endif		// src_ast_ast_to_dot_converter_class_hpp
