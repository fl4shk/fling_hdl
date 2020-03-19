#ifndef src_err_warn_class_hpp
#define src_err_warn_class_hpp

// src/err_warn_class.hpp

#include "misc_includes.hpp"

#include "ANTLRErrorListener.h"
#include "gen_src/FlingHdlGrammarLexer.h"
#include "gen_src/FlingHdlGrammarParser.h"
#include "gen_src/FlingHdlGrammarVisitor.h"

namespace fling_hdl
{

class ErrWarn
{
protected:		// variables
	string _filename;
	antlr4::ParserRuleContext* _ctx = nullptr;
public:		// functions
	inline ErrWarn() = default;
	inline ErrWarn(const string& s_filename,
		antlr4::ParserRuleContext* s_ctx)
		: _filename(s_filename), _ctx(s_ctx)
	{
	}
	inline ErrWarn(string&& s_filename,
		antlr4::ParserRuleContext* s_ctx)
		: _filename(move(s_filename)), _ctx(s_ctx)
	{
	}
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(ErrWarn);
	virtual inline ~ErrWarn() = default;

	virtual void warn(const string& msg) const
	{
		printerr("Warning in file \"", filename(), "\" on line ", line(),
			", position ", pos_in_line(), ":  ", msg, "\n");
	}
	virtual void err(const string& msg) const
	{
		printerr("Error in file \"", filename(), "\" on line ", line(),
			", position ", pos_in_line(), ":  ", msg, "\n");
		exit(1);
	}
	inline size_t line() const
	{
		return ctx()->getStart()->getLine();
	}
	inline size_t pos_in_line() const
	{
		return ctx()->getStart()->getCharPositionInLine();
	}

	GEN_GETTER_AND_SETTER_BY_CON_REF(filename);
	GEN_SETTER_BY_RVAL_REF(filename);
	GEN_GETTER_AND_SETTER_BY_VAL(ctx);

};

} // namespace fling_hdl


#endif		// src_err_warn_class_hpp
