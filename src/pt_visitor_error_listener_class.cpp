#include "src/pt_visitor_error_listener_class.hpp"

namespace fling_hdl
{

PtVisitorErrorListener::~PtVisitorErrorListener()
{
}

void PtVisitorErrorListener::syntaxError(antlr4::Recognizer *recognizer, 
	antlr4::Token *offendingSymbol, size_t line, 
	size_t charPositionInLine, const std::string &msg, 
	std::exception_ptr e)
{
	printerr("Syntax error on line ", line, 
		", position ", charPositionInLine, 
		":  ", msg, "\n");
	exit(1);
}
void PtVisitorErrorListener::reportAmbiguity(antlr4::Parser *recognizer, 
	const antlr4::dfa::DFA &dfa, size_t startIndex, size_t stopIndex, 
	bool exact, const antlrcpp::BitSet &ambigAlts, 
	antlr4::atn::ATNConfigSet *configs)
{
}

void PtVisitorErrorListener::reportAttemptingFullContext
	(antlr4::Parser *recognizer, const antlr4::dfa::DFA &dfa, 
	size_t startIndex, size_t stopIndex,
	const antlrcpp::BitSet &conflictingAlts, 
	antlr4::atn::ATNConfigSet *configs)
{
}

void PtVisitorErrorListener::reportContextSensitivity
	(antlr4::Parser *recognizer, const antlr4::dfa::DFA &dfa, 
	size_t startIndex, size_t stopIndex, size_t prediction, 
	antlr4::atn::ATNConfigSet *configs)
{
}

} // namespace fling_hdl
