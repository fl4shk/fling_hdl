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

#include "parser_class.hpp"
#include "../liborangepower_src/metaprog_defines.hpp"
#include "parser_class_defines.hpp"

namespace fling_hdl
{

using namespace ast;

//--------
auto Parser::_parse_flingRange() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingNonSimpleRange,
				_parse_flingExpr
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingRange);

		return std::nullopt;
	}
}
auto Parser::_parse_flingNonSimpleRange() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(KwDollarRange),
				TOK_PARSE_FUNC(KwRange)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingNonSimpleRange);

		return std::nullopt;
	}
}
auto Parser::_parse_flingSimpleRangeSuffix() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctRangeSeparator)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingSimpleRangeSuffix);

		return std::nullopt;
	}
}
auto Parser::_parse_flingExprOrRange() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingExpr,
				_parse_flingNonSimpleRange
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingExprOrRange);

		return std::nullopt;
	}
}
//--------

//--------
auto Parser::_parse_flingTypenmCstmChainItem() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				TOK_PARSE_FUNC(PunctScopeAccess)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingTypenmCstmChainItem);

		return std::nullopt;
	}
}
auto Parser::_parse_flingTypenm() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingIdentExprStart,
				TOK_PARSE_FUNC(KwLogic),
				TOK_PARSE_FUNC(KwInteger)
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingTypenm);

		return std::nullopt;
	}
}
auto Parser::_parse_flingModnm() -> ParseRet
{
	if (just_get_valid_tokens())
	{
		return GET_VALID_TOK_SET
			(
				_parse_flingIdentExprStart
			);
	}
	else // if (!just_get_valid_tokens())
	{
		PROLOGUE_AND_EPILOGUE(_parse_flingModnm);

		return std::nullopt;
	}
}
//--------
} // namespace fling_hdl
