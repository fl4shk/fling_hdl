#ifndef src_misc_includes_hpp
#define src_misc_includes_hpp

// src/misc_includes.hpp

#include "liborangepower_src/misc_includes.hpp"
#include "liborangepower_src/misc_output_classes.hpp"
#include "liborangepower_src/misc_input_classes.hpp"
#include "liborangepower_src/misc_types.hpp"
#include "liborangepower_src/misc_utility_funcs.hpp"
#include "liborangepower_src/misc_bitwise_funcs.hpp"
#include "liborangepower_src/misc_defines.hpp"
#include "liborangepower_src/gen_class_innards_defines.hpp"
#include "liborangepower_src/string_conversion_stuff.hpp"
#include "liborangepower_src/gmp_stuff.hpp"

using namespace liborangepower::misc_output;
using namespace liborangepower::misc_input;
using namespace liborangepower::integer_types;
using namespace liborangepower::misc_util;
using namespace liborangepower::bitwise;
using namespace liborangepower::strings;
using namespace liborangepower::bignum;

#include <stack>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <variant>
#include <optional>
#include <type_traits>

using std::stack;
using std::vector;
using std::string;
using std::variant;
using std::optional;

#endif		// src_misc_includes_hpp
