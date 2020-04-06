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
		Print,
	};

protected:		// variables
	fstream _file;
	string _name;
	size_t _k, _max_ast_level;
	State _state;
	vector<set<Base*>> _node_vec;
public:		// functions
	inline AstToDotConverter() = default;
	virtual ~AstToDotConverter() = default;

	virtual void convert(size_t max_ast_level, const string& dst_filename,
		const string& src_filename, Base* root);

protected:		// misc. functions
	virtual void _print_node(Base* to_print, const string& lab);
	virtual void _print_conn(Base* parent, Base* child);
	virtual void _print_conn(Base* parent, const string& child);
	inline void _update_node_vec_size(Base* some_ast)
	{
		while (some_ast->level() >= _node_vec.size())
		{
			_node_vec.push_back(set<Base*>());
		}
	}

protected:		// visitor functions
	#define GEN_VISIT_FUNCS(name) \
		virtual inline void visit##name(ast::name* node) \
		{ \
			switch (_state) \
			{ \
			/* -------- */ \
			case State::BuildNodeVec: \
				{ \
					_update_node_vec_size(node); \
					visit##name##_build_node_vec(node); \
				} \
				break; \
			case State::Print: \
				visit##name##_print(node); \
				break; \
			/* -------- */ \
			} \
		} \
		virtual void visit##name##_build_node_vec(ast::name* node); \
		virtual void visit##name##_print(ast::name* node);
	LIST_OF_AST_NODE_CLASSES(GEN_VISIT_FUNCS)
	#undef GEN_VISIT_FUNCS
};

} // namespace fling_hdl


#endif		// src_ast_to_dot_converter_class_hpp
