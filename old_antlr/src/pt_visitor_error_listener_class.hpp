#ifndef src_pt_visitor_error_listener_class_hpp
#define src_pt_visitor_error_listener_class_hpp

// src/pt_visitor_error_listener_class.hpp

#include "misc_includes.hpp"
#include "ANTLRErrorListener.h"

namespace fling_hdl
{

class PtVisitorErrorListener : public antlr4::ANTLRErrorListener
{
private:		// variables
	string* _filename = nullptr;
public:		// functions
	inline PtVisitorErrorListener(string* s_filename)
		: _filename(s_filename)
	{
	}
	virtual inline ~PtVisitorErrorListener() = default;

	void syntaxError(antlr4::Recognizer *recognizer, 
		antlr4::Token *offendingSymbol, size_t line, 
		size_t charPositionInLine, const std::string &msg, 
		std::exception_ptr e);
	void reportAmbiguity(antlr4::Parser *recognizer, 
		const antlr4::dfa::DFA &dfa, size_t startIndex, size_t stopIndex, 
		bool exact, const antlrcpp::BitSet &ambigAlts, 
		antlr4::atn::ATNConfigSet *configs);
	
	void reportAttemptingFullContext(antlr4::Parser *recognizer, 
		const antlr4::dfa::DFA &dfa, size_t startIndex, size_t stopIndex,
		const antlrcpp::BitSet &conflictingAlts, 
		antlr4::atn::ATNConfigSet *configs);

	void reportContextSensitivity(antlr4::Parser *recognizer, 
		const antlr4::dfa::DFA &dfa, size_t startIndex, size_t stopIndex,
		size_t prediction, antlr4::atn::ATNConfigSet *configs);
};

} // namespace fling_hdl

#endif		// src_pt_visitor_error_listener_class_hpp
