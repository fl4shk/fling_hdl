//#ifndef src_ast_list_of_ast_node_classes_define_hpp
//#define src_ast_list_of_ast_node_classes_define_hpp

// src/ast/list_of_ast_node_classes_define.hpp

#define LIST_OF_AST_NODE_CLASSES(X) \
	X(Program) \
	\
	X(DeclPackage) \
	X(Import) \
	X(ImportItem) \
	\
	X(ParamOrArgList) \
	X(DeclParamListItem) \
	X(DeclArgListItem) \
	X(StrAndNode) \
	\
	X(DeclModule) \
	X(Scope) \
	\
	X(Modinst) \
	\
	X(GenIf) \
	X(GenElif) \
	X(GenSwitchEtc) \
	X(GenCase) \
	X(GenDefault) \
	X(GenFor) \
	\
	X(DeclModuleBehavComb) \
	X(DeclModuleBehavSeq) \
	X(DeclModuleBehavSeqEdgeItem) \
	\
	X(BehavIf) \
	X(BehavElif) \
	X(BehavSwitchEtc) \
	X(BehavCase) \
	X(BehavDefault) \
	X(BehavFor) \
	X(BehavWhile) \
	\
	X(BehavAssign) \
	\
	X(DeclStruct) \
	\
	X(DeclEnum) \
	\
	X(DeclSubprog) \
	\
	X(DeclVarEtc) \
	X(WireAssign) \
	\
	X(DeclAlias) \
	\
	X(NamedScope) \
	\
	X(MuxExpr) \
	X(BinopExpr) \
	X(UnopExpr) \
	X(LitValExpr) \
	X(CallDollarFuncExpr) \
	X(String) \
	X(IdentExprSuffix) \
	X(IdentExpr) \
	X(CatExpr) \
	X(ReplExpr) \
	X(SizedExpr) \
	\
	X(NonDollarFuncRange) \
	\
	X(Typenm) \
	X(Modnm) \

//#endif		// src_ast_list_of_ast_node_classes_define_hpp
