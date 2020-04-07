#ifndef liborangepower_string_extra_stuff_hpp
#define liborangepower_string_extra_stuff_hpp


#include "misc_includes.hpp"
#include <string.h>
#include <libgen.h>

namespace liborangepower
{

namespace strings
{

inline std::unique_ptr<char[]>&& get_temp_path(const string& path)
{
	std::unique_ptr<char[]> temp_path(new char[path.size() + 1]);
	temp_path[path.size()] = '\0';

	for (size_t i=0; i<path.size(); ++i)
	{
		temp_path[i] = path.at(i);
	}

	return std::move(temp_path);
}

inline std::string dirname(const string& path)
{
	std::string ret;

	auto&& temp_path = std::move(get_temp_path(path));
	auto modded_path = dirname(temp_path.get());

	for (char c=modded_path[0]; c!='\0'; ++c)
	{
		ret += c;
	}

	return ret;
}
inline std::string basename(const string& path)
{
	std::string ret;
	auto&& temp_path = std::move(get_temp_path(path));
	auto modded_path = basename(temp_path.get());

	for (char c=modded_path[0]; c!='\0'; ++c)
	{
		ret += c;
	}

	return ret;
}

} // namespace strings

} // namespace liborangepower

#endif		// liborangepower_string_extra_stuff_hpp