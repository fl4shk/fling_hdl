//#ifndef src_list_of_sym_data_classes_define_hpp
//#define src_list_of_sym_data_classes_define_hpp

// src/list_of_sym_data_classes_define.hpp

//#include "misc_includes.hpp"

#define LIST_OF_SYM_DATA_CLASSES(X) \
	X(VarEtc) \
	\
	X(DeclParamOrArgList) \
	\
	X(DeclParamItemVar) \
	X(DeclParamItemType) \
	X(DeclParamItemModule) \
	X(DeclArgItemVar) \
	\
	X(InstParamItemVar) \
	X(InstParamItemType) \
	X(InstParamItemModule) \
	X(InstArgItemVar) \
	\
	X(AliasValue) \
	X(AliasType) \
	X(AliasModule) \
	\
	/* X(Mixin) */ \
	X(Class) \
	\
	X(Scope) \
	X(Package) \
	\
	X(Module) \
	X(InstModule) \

//#endif		// src_list_of_sym_data_classes_define_hpp
