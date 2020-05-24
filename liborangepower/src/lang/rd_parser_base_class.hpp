#ifndef liborangepower_rd_parser_base_class_hpp
#define liborangepower_rd_parser_base_class_hpp

#include "../misc/misc_includes.hpp"
#include "../misc/misc_output_classes.hpp"
#include "../misc/misc_input_classes.hpp"
#include "../strings/sconcat_etc.hpp"
#include "file_pos_class.hpp"

#include <variant>
#include <optional>
#include <memory>
#include <fstream>
#include <string>
#include <map>
#include <set>

namespace liborangepower
{

using misc_output::printout;
using misc_output::printerr;
using misc_output::osprintout;
using strings::sconcat;

namespace lang
{

// A base class for parsing LL(1) grammars via recursive descent.
template<typename LexerType, typename DerivedType>
class RdParserBase
{
public:		// types
	//--------
	using TokType = LexerType::TokType;
	using LexerState = LexerType::State;

	using TokSet = std::set<TokType>;

	using ParseRet = std::optional<TokSet>;

	using ParseFunc = ParseRet (DerivedType::*)();
	//--------

	//--------
	friend class PrologueAndEpilogue;
	class PrologueAndEpilogue final
	{
	private:		// variables
		RdParserBase* _parser = nullptr;
		string _parent_parse_func_str;
		TokSet _parent_wanted_tok_set;

	public:		// functions
		inline PrologueAndEpilogue(RdParserBase* s_parser,
			string&& s_parse_func_str)
			: _parser(s_parser)
		{
			_parent_parse_func_str = std::move(_parser->_parse_func_str);
			_parser->_parse_func_str = std::move(s_parse_func_str);

			_parent_wanted_tok_set = std::move(_parser->_wanted_tok_set);
		}
		GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(PrologueAndEpilogue);
		inline ~PrologueAndEpilogue()
		{
			_parser->_parse_func_str = std::move(_parent_parse_func_str);
			_parser->_wanted_tok_set = std::move(_parent_wanted_tok_set);
		}

		inline void parent_wanted_tok_set_merge
			(const ParseRet& to_merge_from)
		{
			_parser->_tok_set_merge(_parent_wanted_tok_set, to_merge_from);
		}

		//inline void internal_err(const std::string& msg="") const
		//{
		//	_parser->_internal_err(_parser->_parse_func_str, msg);
		//}
	};
	//--------

protected:		// variables
	std::string _filename, _text;
	std::unique_ptr<LexerType> _lexer;

	string _parse_func_str;

	bool _just_get_valid_tokens = false;

	//bool _debug = false;

protected:		// variables
	//bool _found_wanted_tok;
	TokSet _wanted_tok_set;

public:		// functions
	inline RdParserBase(const std::string& s_filename)
		: _filename(s_filename)
	{
		if (auto&& f = std::ifstream(filename()); true)
		{
			_text = misc_input::get_istream_as_str(f);
		}
		
		_lexer.reset(new LexerType(_filename, &_text));
		_next_tok();

		//_lexer.reset(new LexerType(_filename, _text));
		//_next_tok();
	}
	GEN_CM_BOTH_CONSTRUCTORS_AND_ASSIGN(RdParserBase);
	virtual inline ~RdParserBase() = default;

	inline FilePos lex_file_pos() const
	{
		return _lexer->file_pos();
	}
	inline auto lex_tok() const
	{
		return _lexer->tok();
	}
	inline const auto& lex_s() const
	{
		return _lexer->s();
	}
	inline const auto& lex_n() const
	{
		return _lexer->n();
	}

	inline auto prev_lex_tok() const
	{
		return _lexer->prev_state().tok();
	}
	inline const auto& prev_lex_s() const
	{
		return _lexer->prev_state().s();
	}
	inline const auto& prev_lex_n() const
	{
		return _lexer->prev_state().n();
	}

	GEN_GETTER_BY_CON_REF(filename);
	GEN_GETTER_BY_VAL(just_get_valid_tokens);

protected:		// functions
	inline DerivedType* _self()
	{
		return static_cast<DerivedType*>(this);
	}
	inline auto _next_tok()
	{
		return _lexer->next_tok();
	}

	virtual inline void _pfs_internal_err(const std::string& msg="") const
	{
		_internal_err(_parse_func_str, msg);
	}
	virtual inline void _internal_err(const std::string& func_str,
		const std::string& msg="") const
	{
		string full_msg = sconcat(func_str, "():  Internal error");
		if (msg.size() == 0)
		{
			full_msg += ".";
		}
		else // if (msg.size() > 0)
		{
			full_msg += sconcat(":  ", msg);
		}

		lex_file_pos().err(full_msg);
	}

	inline void _tok_set_merge(TokSet& tok_set,
		const ParseRet& to_merge_from)
	{
		// Check for duplicate tokens, i.e. a non-LL(1) grammar, and spit
		// out an error if duplicate tokens were found.
		for (const auto& outer_item: tok_set)
		{
			for (const auto& inner_item: *to_merge_from)
			{
				if (outer_item == inner_item)
				{
					_internal_err("_tok_set_merge", sconcat(":  ",
						"Duplicate token \"", _lexer->tok_to_string_map()
						.at(outer_item), "\"."));
				}
			}
		}

		TokSet temp_to_merge_from = *to_merge_from;

		tok_set.merge(temp_to_merge_from);
	}

	inline void _wanted_tok_set_merge(const ParseRet& to_merge_from)
	{
		_tok_set_merge(_wanted_tok_set, to_merge_from);
	}

	inline bool _check_parse(TokSet& tok_set, const ParseFunc& parse_func)
	{
		const bool old_just_get_valid_tokens = just_get_valid_tokens();
		_just_get_valid_tokens = true;
		const auto parse_ret = (_self()->*parse_func)();
		_just_get_valid_tokens = old_just_get_valid_tokens;

		_tok_set_merge(tok_set, parse_ret);

		if (parse_ret->count(lex_tok()) > 0)
		{
			//_found_wanted_tok = true;
			return true;
		}
		else
		{
			return false;
		}
	}
	inline bool _check_parse(const ParseFunc& parse_func)
	{
		return _check_parse(_wanted_tok_set, parse_func);
	}

private:		// functions
	template<typename... RemArgTypes>
	inline void _inner_get_valid_tok_set(TokSet& ret,
		const ParseFunc& first_parse_func, RemArgTypes&&... rem_args)
	{
		_check_parse(ret, first_parse_func);

		if constexpr (sizeof...(rem_args) > 0)
		{
			_inner_get_valid_tok_set(ret, rem_args...);
		}
	}

public:		// functions
	template<typename... RemArgTypes>
	inline TokSet _get_valid_tok_set(const ParseFunc& first_parse_func,
		RemArgTypes&&... rem_args)
	{
		TokSet ret;
		_inner_get_valid_tok_set(ret, first_parse_func, rem_args...);
		return ret;
	}

	inline bool _attempt_parse_basic(const ParseFunc& parse_func)
	{
		if (_check_parse(parse_func))
		{
			(_self()->*parse_func)();
			return true;
		}
		else
		{
			return false;
		}
	}
	inline bool _attempt_parse_ifelse(const ParseFunc& parse_func)
	{
		_wanted_tok_set_merge(_get_valid_tok_set(parse_func));

		return _attempt_parse_basic(parse_func);
	}

	//inline void _fail_if_not_found_wanted_tok() const
	//{
	//	if (!_found_wanted_tok)
	//	{
	//		_expect(_wanted_tok_set);
	//	}
	//}

private:		// functions
	template<typename... RemArgTypes>
	inline std::optional<TokType> _cmp_tok(TokType to_cmp,
		TokType first_tok, RemArgTypes&&... rem_args) const
	{
		if (to_cmp == first_tok)
		{
			return first_tok;
		}
		else if constexpr (sizeof...(rem_args) > 0)
		{
			return _cmp_tok(to_cmp, rem_args...);
		}
		else
		{
			return std::nullopt;
		}
	}
	inline std::optional<TokType> _cmp_tok(TokType to_cmp,
		const TokSet& tok_set) const
	{
		for (const auto& tok: tok_set)
		{
			if (to_cmp == tok)
			{
				return tok;
			}
		}

		return std::nullopt;
	}

protected:		// functions
	template<typename... RemArgTypes>
	inline std::optional<TokType> _cmp_lex_tok(TokType first_tok,
		RemArgTypes&&... rem_args) const
	{
		return _cmp_tok(lex_tok, first_tok, rem_args...);
	}
	inline std::optional<TokType> _cmp_lex_tok(const TokSet& tok_set)
		const
	{
		return _cmp_tok(lex_tok(), tok_set);
	}

	template<typename... RemArgTypes>
	inline std::optional<TokType> _cmp_prev_lex_tok(TokType first_tok,
		RemArgTypes&&... rem_args) const
	{
		return _cmp_tok(prev_lex_tok, first_tok, rem_args...);
	}
	inline std::optional<TokType> _cmp_prev_lex_tok(const TokSet& tok_set)
		const
	{
		return _cmp_tok(prev_lex_tok(), tok_set);
	}

	void _inner_expect_fail(const TokSet& tok_set) const
	{
		std::string msg = sconcat("Expected one of the following tokens:",
			"  {");

		decltype(tok_set.size()) i = 0;

		for (const auto& p: tok_set)
		{
			msg += _lexer->tok_to_string_map().at(p);

			if ((i + 1) < tok_set.size())
			{
				msg += ", ";
			}

			++i;
		}

		msg += sconcat("}");

		lex_file_pos().err(msg);
	}

private:		// functions
	template<typename... RemArgTypes>
	bool _inner_expect(TokSet& tok_set, TokType first_tok,
		RemArgTypes&&... rem_args) const
	{
		tok_set.insert(first_tok);

		if (lex_tok() == first_tok)
		{
			return true;
		}
		else if constexpr (sizeof...(rem_args) > 0)
		{
			return _inner_expect(tok_set, rem_args...);
		}
		else
		{
			return false;
		}
	}

protected:		// functions
	template<typename... RemArgTypes>
	void _expect(TokType first_tok, RemArgTypes&&... rem_args) const
	{
		TokSet tok_set;

		if (!_inner_expect(tok_set, first_tok, rem_args...))
		{
			_inner_expect_fail(tok_set);
		}
	}
	void _expect_wanted_tok()
	{
		if (!_cmp_lex_tok(_wanted_tok_set))
		{
			_inner_expect_fail(_wanted_tok_set);
		}
	}

//private:		// functions
//	template<typename... RemArgTypes>
//	bool _inner_sel_parse(TokSet& tok_set, TokType first_tok,
//		ParseFunc first_parse_func, RemArgTypes&&... rem_args)
//	{
//		tok_set.insert(first_tok);
//
//		if (_lexer->tok() == first_tok)
//		{
//			(_self()->*first_parse_func)();
//			return true;
//		}
//		else if constexpr (sizeof...(rem_args) > 0)
//		{
//			return _inner_sel_parse(tok_set, rem_args...);
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//protected:		// functions
//	template<typename... RemArgTypes>
//	void _sel_parse(TokType first_tok, ParseFunc first_parse_func,
//		RemArgTypes&&... rem_args)
//	{
//		TokSet tok_set;
//
//		if (!_inner_sel_parse(tok_set, first_tok, first_parse_func,
//			rem_args...))
//		{
//			_inner_expect_fail(tok_set);
//		}
//	}
};


} // namespace lang

} // namespace liborangepower


#endif		// liborangepower_rd_parser_base_class_hpp
