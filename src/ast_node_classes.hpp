#ifndef src_ast_node_classes_hpp
#define src_ast_node_classes_hpp

// src/ast_node_classes.hpp

#include "misc_includes.hpp"
#include "liborangepower_src/cpp_magic.hpp"

namespace fling_hdl
{

class Symbol;

namespace ast
{

#define SHARED_FUNC_CONTENTS_2(name, base_name) \
	inline name() = default; \
	inline name(Base* s_parent, const FilePos& s_fp) \
		: base_name(s_parent, s_fp) \
	{ \
		if (_parent != nullptr) \
		{ \
			_level = _parent->level() + static_cast<size_t>(1); \
		} \
		else \
		{ \
			_level = 0; \
		} \
	} \
	GEN_MOVE_ONLY_CONSTRUCTORS_AND_ASSIGN(name); \
	virtual inline ~name() = default; \
	virtual inline string id() const \
	{ \
		return string(#name); \
	}
#define SHARED_FUNC_CONTENTS(name, base_name) \
	SHARED_FUNC_CONTENTS_2(name, base_name) \
	virtual void accept(AstVisitor* visitor) \
	{ \
		visitor->visit##name(this); \
	}

#define CONV_ENUM_CASE(type, which) \
	case type::which: \
		return #which;
#define CONV_KIND_CASE(which) \
	CONV_ENUM_CASE(Kind, which)
#define CONV_ENUM_SWITCH(CONV_CASE, ...) \
	switch (to_conv) \
	{ \
	/* -------- */ \
	EVAL(MAP(CONV_CASE, EMPTY, __VA_ARGS__)) \
	default: \
		return "Eek!"; \
	/* -------- */ \
	}

class Base;
using BaseSptr = shared_ptr<Base>;
using BaseSptrList = IndCircLinkList<BaseSptr>;
using BaseWptr = weak_ptr<Base>;

class Base
{
public:		// types
protected:		// variables
	Base* _parent = nullptr;
	FilePos _fp;
	size_t _level = 0;

public:		// variables
	Symbol* sym = nullptr;

public:		// functions
	inline Base() = default;
	inline Base(Base* s_parent, const FilePos& s_fp)
		: _parent(s_parent), _fp(s_fp)
	{
	}
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(Base);
	virtual inline ~Base() = default;
	virtual inline string id() const
	{
		return string("Base");
	}
	virtual inline void accept(AstVisitor* visitor)
	{
		// Derived classes should fill this in
	}

	GEN_GETTER_BY_VAL(parent);
	GEN_GETTER_AND_SETTER_BY_VAL(fp);
	GEN_GETTER_BY_VAL(level);

};


} // namespace ast

} // namespace fling_hdl

#endif		// src_ast_node_classes_hpp
