#ifndef src_compiler_class_hpp
#define src_compiler_class_hpp

// src/compiler_class.hpp

#include "misc_includes.hpp"
#include "ANTLRErrorListener.h"
#include "gen_src/FlingHdlGrammarLexer.h"
#include "gen_src/FlingHdlGrammarParser.h"
#include "gen_src/FlingHdlGrammarVisitor.h"

namespace fling_hdl
{

class Compiler : public FlingHdlGrammarVisitor
{
public:		// typedefs
	using ParserRuleContext = antlr4::ParserRuleContext;

private:		// variables
	FlingHdlGrammarParser::FlingProgramContext* _program_ctx = nullptr;

	std::stack<string> _str_stack;
	std::stack<BigNum> _num_stack;

private:		// stack functions
	inline void _push_str(const string& to_push)
	{
		_str_stack.push(to_push);
	}
	inline auto _get_top_str()
	{
		return _str_stack.top();
	}
	inline auto _pop_str()
	{
		auto ret = _str_stack.top();
		_str_stack.pop();
		return ret;
	}

	inline void _push_num(const BigNum& to_push)
	{
		_num_stack.push(to_push);
	}
	inline auto _get_top_num()
	{
		return _num_stack.top();
	}
	inline auto _pop_num()
	{
		auto ret = _num_stack.top();
		_num_stack.pop();
		return ret;
	}

public:		// functions
	Compiler(FlingHdlGrammarParser& parser);
	int run();

private:		// error/warning functions
	inline void _err(ParserRuleContext* ctx, const std::string& msg)
	{
		if (ctx == nullptr)
		{
			printerr("Error:  ", msg, "\n");
		}
		else
		{
			auto tok = ctx->getStart();
			const size_t line = tok->getLine();
			const size_t pos_in_line = tok->getCharPositionInLine();
			//printerr("Error in file \"", *__file_name, "\", on line ",
			//	line, ", position ", pos_in_line, ":  ", msg, "\n");
			printerr("Error on line ", line, ", position ", pos_in_line, 
				":  ", msg, "\n");
		}
		exit(1);
	}
	inline void _err(const std::string& msg)
	{
		//printerr("Error in file \"", *__file_name, "\":  ", msg, "\n");
		printerr("Error:  ", msg, "\n");
		exit(1);
	}


	inline void _warn(ParserRuleContext* ctx, const std::string& msg)
	{
		if (ctx == nullptr)
		{
			printerr("Error:  ", msg, "\n");
		}
		else
		{
			auto tok = ctx->getStart();
			const size_t line = tok->getLine();
			const size_t pos_in_line = tok->getCharPositionInLine();
			//printerr("Error in file \"", *__file_name, "\", on line ",
			//	line, ", position ", pos_in_line, ":  ", msg, "\n");
			printerr("Warning on line ", line, ", position ", pos_in_line, 
				":  ", msg, "\n");
		}
	}
	inline void _warn(const std::string& msg)
	{
		printerr("Warning:  ", msg, "\n");
	}

private:		// visitor functions
};

} // namespace fling_hdl


#endif		// src_compiler_class_hpp
