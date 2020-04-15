#include "sem_analyzer_and_eval_class.hpp"
#include "ast_node_classes.hpp"

namespace fling_hdl
{

using namespace ast;

SemAnalyzerAndEval::SemAnalyzerAndEval(AstEtcMap* s_ast_etc_map)
	: _ast_etc_map(s_ast_etc_map)
{
}
SemAnalyzerAndEval::~SemAnalyzerAndEval()
{
}

void SemAnalyzerAndEval::visitProgram(Program* n)
{
}

} // namespace fling_hdl
