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

#ifndef src_ast_ast_visitor_class_hpp
#define src_ast_ast_visitor_class_hpp

// src/ast/ast_visitor_class.hpp

#include "../misc_includes.hpp"

#include "list_of_ast_node_classes_define.hpp"

namespace fling_hdl
{

namespace ast
{

#define X(name) \
	class name;
LIST_OF_AST_NODE_CLASSES(X)
#undef X

class AstVisitor: public AstVisitorBase
{
public:		// functions
	inline AstVisitor() = default;
	virtual inline ~AstVisitor() = default;

	#define GEN_VISIT_FUNC(name) \
		virtual void visit##name(ast::name* node) = 0;
	LIST_OF_AST_NODE_CLASSES(GEN_VISIT_FUNC)
	#undef GEN_VISIT_FUNC

};

} // namespace ast

} // namespace fling_hdl

#endif		// src_ast_ast_visitor_class_hpp
