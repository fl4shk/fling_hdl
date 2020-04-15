#include "ast_to_dot_converter_class.hpp"
#include "pt_visitor_class.hpp"

namespace fling_hdl
{

using namespace ast;

void AstToDotConverter::convert(const string& dst_filename,
	const AstEtc& ast_etc)
{
	_max_ast_level = ast_etc.max_ast_level();
	const auto& root = ast_etc.ast();
	_file.open(dst_filename, std::ios_base::out | std::ios_base::trunc);

	osprintout(_file,
		"digraph ", "file", "\n",
		"{\n",
		"\tordering=out;\n",
		"\tclusterrank=global;\n",
		"\tsize=\"6,4\";\n",
		"\tratio=fill;\n",
		"\tremincross=true;\n",
		"\trankdir=LR;\n",
		"\tstyle=\"invis\";\n",
		"\tnode [fontname=Helvetica];\n");

	_state = State::BuildNodeVec;
	root->accept(this);

	_state = State::BuildLabelMap;
	root->accept(this);

	_state = State::BuildConnMap;
	root->accept(this);

	for (size_t level=0; level<=_max_ast_level; ++level)
	//for (size_t level=0; level<_node_vec.size(); ++level)
	{
		_print_dot_subgraph_cluster(level);
	}
	for (size_t level=0; level<=_max_ast_level; ++level)
	{
		_print_dot_wires(level);
	}

	osprintout(_file,
		"}\n");

	_file.close();
}

void AstToDotConverter::_print_dot_subgraph_cluster(size_t level)
{
	osprintout(_file,
		"\tnode [color=\"", _color(level), ",1.0,1.0\"];\n",
		"\tsubgraph cluster_", level, "\n",
		"\t{\n",
		"\t\trank=same;\n");

	for (const auto& p: _node_vec.at(level))
	{
		const auto& label = _label_map.at(p);
		osprintout(_file,
			"\t\t", _node_name(p), " [label=\"", label, "\"];\n");
	}

	osprintout(_file,
		"\t}\n\n");
}
void AstToDotConverter::_print_dot_wires(size_t level)
{
	for (const auto& p: _node_vec.at(level))
	{
		//if (_conn_map.count(p) == 0)
		//{
		//	//printout("RIP\n");
		//	continue;
		//}

		//const auto& conn = _conn_map.at(p);
		//osprintout(_file,
		//	"\t", _node_name(p), " -> ", _node_name(conn),
		//		" [color=\"", _color(level), ",1.0,1.0\"];\n");

		if (_conn_map.count(p) == 0)
		{
			continue;
		}
		for (const auto& q: _conn_map.at(p))
		{
			osprintout(_file,
				"\t", _node_name(p), " -> ", _node_name(q),
					" [color=\"", _color(level), ",1.0,1.0\"];\n");
		}
		osprintout(_file,
			"\n");
	}

	osprintout(_file,
		"\n");
}


#define _INNER_WRAP(item) \
	sconcat(#item, ":  ", n->item)
#define wrap(...) \
	EVAL(MAP(_INNER_WRAP, COMMA, __VA_ARGS__))


#define _INNER_WRAP_CONV(item) \
	sconcat(#item, ":  ", n->conv_##item(n->item))
#define wrap_conv(...) \
	EVAL(MAP(_INNER_WRAP_CONV, COMMA, __VA_ARGS__))

#define _INNER_WRAP_CONV_2(item, ...) \
	sconcat(#item, ":  ", conv_##item(n->item))
#define wrap_conv_2(...) \
	EVAL(MAP(_INNER_WRAP_CONV_2, COMMA, __VA_ARGS__))


#define build(type, ...) \
	void AstToDotConverter::_build_label_map(type* n) \
	{ \
		auto temp = sconcat(_memb_name, "\\n", "id:  ", n->id()); \
		auto to_append = _strjoin2_raw_newline(__VA_ARGS__); \
		if (to_append.size() != 0) \
		{ \
			temp += sconcat("\\n---- ---- ---- ----\\n", to_append); \
		} \
		_label_map[n] = move(temp); \
	}


build(Program)

build(DeclPackage, wrap(ident))

build(ParamOrArgList)
build(DeclParamList_Item, wrap_conv(kind))
build(DeclArgList_Item, wrap_conv(kind))
build(InstParamOrArgList_PosItemParpk)
build(InstParamOrArgList_PosItemUnparpk, wrap(ident))
build(InstParamList_NamedItem, wrap(ident))
build(InstArgList_NamedItem, wrap(ident))

build(DeclModule, wrap(ident))
build(InstModule, wrap(ident))

build(GenIf)
build(GenIf_Elif)
build(GenIf_Else)

build(GenSwitch)
build(GenSwitch_Case)
build(GenSwitch_Default)

build(GenFor, wrap(label, ident))

build(ContAssign)

build(Behav, wrap_conv(kind))
build(Behav_SeqEdgeListItem, wrap_conv(kind))
build(Behav_Scope)

build(If)
build(If_Elif)
build(If_Else)

build(Switch)
build(Switchz)
build(SwitchOrSwitchz_Case)
build(SwitchOrSwitchz_Default)

build(For, wrap(ident))
build(While)

build(NonBlkAssign)
build(BlkAssign)

build(DeclWire)
build(DeclVar)
build(DeclConst)

build(DeclEnum, wrap(ident))

build(DeclMixin, wrap(is_base, ident))

build(DeclClass, wrap(is_base, ident, is_signed, is_packed))

build(DeclClass_DeclVar, wrap_conv_2(acc_spec), wrap(is_static))
build(DeclClsOrMxn_DeclType, wrap_conv_2(acc_spec))
build(DeclClsOrMxn_DeclAliasOrConst, wrap_conv_2(acc_spec),
	wrap(is_static))

build(DeclClsOrMxn_DeclSubprogFullDefn, wrap_conv_2(acc_spec),
	wrap(is_virtual, is_static, is_const))
build(DeclClsOrMxn_DeclSubprogAbstract, wrap_conv_2(acc_spec),
	wrap(is_const))

build(DeclFunc)
build(DeclFunc_Header, wrap(ident))
build(DeclFunc_Return)
build(DeclFunc_Defer)

build(DeclTask)
build(DeclTask_Header, wrap(ident))

build(DeclProc)
build(DeclProc_Header, wrap(ident))

build(DeclAlias_Value)
build(DeclAlias_Type)
build(DeclAlias_Module)

void AstToDotConverter::_build_label_map
	(IdentList* n)
{
	auto to_insert = sconcat(_memb_name, "\\n", "id:  ", n->id(),
		"\\n---- ---- ---- ----\\ndata:  ");


	for (auto iter=n->data.begin(); iter!=n->data.end(); ++iter)
	{
		to_insert += iter->data;

		auto temp = iter;
		++temp;
		if (temp != n->data.end())
		{
			to_insert += ", ";
		}
	}
	_label_map[n] = move(to_insert);
}

void AstToDotConverter::_build_label_map
	(ScopedIdent* n)
{
	_build_label_map(static_cast<IdentList*>(n));
}

build(ImportList)
build(ImportList_Item, wrap(has_all))

build(TypenameOrModname_Special, wrap(is_dyn, is_weakref),
	wrap_conv(kind))
build(TypenameOrModname_Cstm, wrap(is_dyn, is_weakref))
build(TypenameOrModname_Typeof)
build(TypenameOrModname_Cstm_Item, wrap(is_dyn, is_weakref, ident))
build(TypenameOrModname_Builtin, wrap(is_dyn, is_weakref), wrap_conv(kind))

#define X(basic_label) \
	build(basic_label)
EVAL(MAP(X, EMPTY,
	ExprMux,

	ExprLogOr,
	ExprLogAnd,
	ExprBinopBitOr, ExprBinopBitNor,
	ExprBinopBitAnd, ExprBinopBitNand,
	ExprBinopBitXor, ExprBinopBitXnor,
	ExprCmpEq, ExprCmpNe, ExprCaseCmpEq, ExprCaseCmpNe,
	ExprCmpLt, ExprCmpLe, ExprCmpGt, ExprCmpGe,
	ExprBitLsl, ExprBitLsr, ExprBitAsr,
	ExprBinopPlus, ExprBinopMinus,
	ExprMul, ExprDiv, ExprMod,

	ExprUnopPlus, ExprUnopMinus,
	ExprLogNot, ExprBitNot,
	ExprUnopBitOr, ExprUnopBitNor,
	ExprUnopBitAnd, ExprUnopBitNand,
	ExprUnopBitXor, ExprUnopBitXnor))

build(ExprLiteral, wrap_conv(kind), wrap(text))

EVAL(MAP(X, EMPTY,
	ExprSized,
	ExprRange,
	ExprCat,
	ExprRepl,
	ExprDollarSigned,
	ExprDollarUnsigned,
	ExprDollarClog2,
	ExprDollarIsvtype,
	ExprDollarPow))
#undef X

build(ExprIdentEtc, wrap_conv(suff_kind))
build(ExprIdentEtc_FirstItem, wrap_conv(kind))
build(ExprIdentEtc_NonSelfItem, wrap(opt_ident))
build(ExprIdentEtc_ItemEnd, wrap_conv(kind))
build(ExprIdentEtc_ItemEndIndex, wrap_conv(kind))
build(ExprCast)
build(ExprCallSubprog_PseudoOper, wrap(ident))


} // namespace fling_hdl
