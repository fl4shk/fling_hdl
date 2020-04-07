#ifndef src_ast_to_dot_converter_class_hpp
#define src_ast_to_dot_converter_class_hpp

// src/ast_to_dot_converter_class.hpp

#include "misc_includes.hpp"
#include "ast_visitor_class.hpp"
#include "ast_node_classes.hpp"

namespace fling_hdl
{


class AstToDotConverter: public AstVisitor
{
public:		// types
	using Uptr = std::uintptr_t;
	using Base = ast::Base;

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
	vector<set<Base*>> _node_vec;
	map<Base*, string> _label_map;

	// For easy iteration
	map<Base*, Base*> _conn_map;
public:		// functions
	inline AstToDotConverter() = default;
	virtual ~AstToDotConverter() = default;

	virtual void convert(size_t max_ast_level, const string& dst_filename,
		const string& src_filename, Base* root);

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
			_node_vec.push_back(set<Base*>());
		}
	}
	static std::uintptr_t _ast_to_uintptr(Base* some_ast)
	{
		std::uintptr_t ret;
		memcpy(&ret, some_ast, sizeof(std::uintptr_t));
		return ret;
	}
	static inline string _node_name(Base* p)
	{
		return sconcat(p->id(), "_", _ast_to_uintptr(p));
	}

protected:		// visitor functions
	#define GEN_VISIT_FUNCS(name) \
		virtual inline void visit##name(ast::name* n) \
		{ \
			switch (_state) \
			{ \
			/* -------- */ \
			case State::BuildNodeVec: \
				_update_node_vec_size(n); \
				_node_vec.at(n->level()).insert(n); \
				break; \
			case State::BuildLabelMap: \
				_build_label_map(n); \
				break; \
			case State::BuildConnMap: \
				if (n->parent() != nullptr) \
				{ \
					_conn_map[n->parent()] = n; \
				} \
				break; \
			/* -------- */ \
			} \
			_accept_children(n); \
		} \
		virtual void _build_label_map(ast::name* n);
	LIST_OF_AST_NODE_CLASSES(GEN_VISIT_FUNCS)
	#undef GEN_VISIT_FUNCS

};

} // namespace fling_hdl


#endif		// src_ast_to_dot_converter_class_hpp
