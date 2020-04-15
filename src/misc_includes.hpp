#ifndef src_misc_includes_hpp
#define src_misc_includes_hpp

// src/misc_includes.hpp

#include "liborangepower_src/misc/misc_includes.hpp"
#include "liborangepower_src/misc/misc_output_classes.hpp"
#include "liborangepower_src/misc/misc_input_classes.hpp"
#include "liborangepower_src/misc/misc_types.hpp"
#include "liborangepower_src/misc/misc_utility_funcs.hpp"
#include "liborangepower_src/misc/misc_bitwise_funcs.hpp"
#include "liborangepower_src/misc/misc_defines.hpp"
#include "liborangepower_src/gen_class_innards_defines.hpp"
#include "liborangepower_src/strings/string_conversion_stuff.hpp"
#include "liborangepower_src/strings/string_extra_stuff.hpp"
#include "liborangepower_src/strings/sconcat_etc.hpp"
#include "liborangepower_src/containers/linked_list_classes.hpp"
#include "liborangepower_src/gmp_stuff/gmp_stuff.hpp"
#include "liborangepower_src/arg_parsing_stuff.hpp"

using namespace liborangepower::misc_output;
using namespace liborangepower::misc_input;
using namespace liborangepower::integer_types;
using namespace liborangepower::misc_util;
using namespace liborangepower::bitwise;
using namespace liborangepower::strings;
using namespace liborangepower::containers;
using namespace liborangepower::bignum;
using namespace liborangepower::arg_parse;

#include <stack>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <variant>
#include <optional>
#include <type_traits>
#include <memory>
#include <map>
#include <set>
#include <array>
#include <filesystem>
#include <system_error>

#include <string.h>
#include <libgen.h>

using std::stack;
using std::vector;
using std::string;
using std::variant;
using std::optional;
using std::unique_ptr;
using std::shared_ptr;
using std::make_shared;
using std::hash;
using std::move;
using std::map;
using std::set;
using std::stringstream;
using std::fstream;
using std::error_code;
namespace fs = std::filesystem;

#endif		// src_misc_includes_hpp
