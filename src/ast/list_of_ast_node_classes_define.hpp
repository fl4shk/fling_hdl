//#ifndef src_ast_list_of_ast_node_classes_define_hpp
//#define src_ast_list_of_ast_node_classes_define_hpp

// src/ast/list_of_ast_node_classes_define.hpp

#define LIST_OF_AST_NODE_CLASSES(X) \
	X(Program) \
	\
	X(DeclPackage) \
	X(Import) \
	\
	X(ParamOrArgList) \
	X(DeclParamListItem) \
	X(DeclArgListItem) \
	X(InstParamOrArgListNamedItem) \
	\
	X(DeclModule) \
	X(DeclModuleScope) \
	\
	X(Modinst) \
	\
	X(GenIf) \
	X(GenSwitchEtc) \
	X(GenSwitchEtcCase) \
	X(GenSwitchEtcDefault) \
	X(GenFor) \

//#endif		// src_ast_list_of_ast_node_classes_define_hpp
