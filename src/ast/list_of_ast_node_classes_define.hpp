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
	X(DeclParamSublistItem) \
	X(DeclArgSublistItem) \
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
	X(DeclVarEtcList) \
	X(DeclVarEtc) \
	X(WireAssign) \
	\
	X(DeclAliasList) \
	X(DeclAlias) \
	\
	/* X(NamedScope) */ \
	\
	X(MuxExpr) \
	X(BinopExpr) \
	X(UnopExpr) \
	X(LitValExpr) \
	X(CallDollarFuncExpr) \
	/* X(String) */ \
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
