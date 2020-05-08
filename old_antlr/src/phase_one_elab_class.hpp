#ifndef src_phase_one_elab_class_hpp
#define src_phase_one_elab_class_hpp

// src/phase_one_elab_class.hpp

#include "misc_includes.hpp"
#include "multi_pass_ast_visitor_class.hpp"
#include "symbol_table_builder_class.hpp"

namespace fling_hdl
{

class PhaseOneElab final: public MultiPassAstVisitor
{
public:		// types
	enum class Stage
	{
		NonBuildSymTable,
		BuildSymTable,
	};

private:		// variables
	unique_ptr<SymbolTableBuilder> _sym_table_builder;

private:		// functions
};

} // namespace fling_hdl


#endif		// src_phase_one_elab_class_hpp
