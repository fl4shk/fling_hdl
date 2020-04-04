grammar FlingHdlGrammar;

//--------
// Parser rules
flingProgram:
	flingProgram_Item*
	EOF
	;

flingProgram_Item:
	flingDeclPackage
	| flingDeclModule
	| flingDeclType
	| flingDeclSubprog
	| flingDeclAlias
	| flingDeclConst
	;
//--------

//--------
flingDeclPackage:
	KwPackage flingIdent
	'{'
		flingDeclPackage_Item*
	'}'
	;

flingDeclPackage_Item:
	flingDeclPackage
	| flingDeclModule
	| flingDeclType
	| flingDeclSubprog
	| flingDeclAlias
	| flingDeclConst
	;
//--------

//--------
flingDeclParamList:
	'<'
		flingDeclParamList_Item
		(';' flingDeclParamList_Item)*
		';'?
	'>'
	;
flingDeclParamList_Item:
	flingIdentList ':'
		(
			flingTypenameOrModname ('=' flingExprList)?
			| (KwType | KwModule) ('=' flingTypenameOrModnameList)?
		)
	;

flingDeclArgList:
	'('
		(
			flingDeclArgList_Item
			(';' flingDeclArgList_Item)*
			';'?
		)?
	')'
	;
flingDeclArgList_Item:
	flingIdentList ':'
		(KwInput | KwOutput | KwInout | KwInterface)
		flingTypenameOrModname ('=' flingExprList)?
	;
//--------

//--------
flingInstParamList:
	'<'
		(
			flingInstParamList_Pos
			| flingInstParamList_Named
		)?
	'>'
	;

flingInstParamList_Pos:
	flingInstParamList_Pos_Item
	(',' flingInstParamList_Pos_Item)*
	;
flingInstParamList_Pos_Item:
	flingExpr | flingTypenameOrModname
	;

flingInstParamList_Named:
	flingInstParamList_Named_Item
	(',' flingInstParamList_Named_Item)*
	;
flingInstParamList_Named_Item:
	flingIdent PunctMapTo flingInstParamList_Pos_Item
	;

flingInstArgList:
	'('
		(
			flingInstArgList_Pos
			| flingInstArgList_Named
		)?
	')'
	;

flingInstArgList_Pos:
	flingExprList
	;

flingInstArgList_Named:
	flingInstArgList_Named_Item
	(',' flingInstArgList_Named_Item)*
	;

flingInstArgList_Named_Item:
	flingIdent PunctMapTo flingExpr
	;
//--------

//--------
flingDeclModule:
	KwModule flingIdent flingDeclParamList? flingDeclArgList
		flingImportList?
	flingDeclModule_Scope
	;

flingDeclModule_Scope:
	'{'
		flingDeclModule_Item*
	'}'
	;

flingDeclModule_Item:
	flingInstModule

	// This is a `proc` call
	| flingExpr ';'
	| flingGen
	| flingContAssign
	| flingImportList

	| flingBehav
	| flingDeclWire
	| flingDeclVar
	| flingDeclConst

	| flingDeclType
	| flingDeclSubprog
	| flingDeclAlias
	;
//--------

//--------
flingInstModule:
	flingIdent ':' KwModule flingTypenameOrModname flingInstArgList ';'
	;
//--------

//--------
flingGen:
	flingGen_If
	| flingGen_Switch
	| flingGen_For
	;

flingGen_If:
	KwGen KwIf flingExpr flingDeclModule_Scope
	flingGen_If_Elif*
	flingGen_If_Else?
	;
flingGen_If_Elif:
	KwGen KwElif flingExpr flingDeclModule_Scope
	;
flingGen_If_Else:
	KwGen KwElse flingDeclModule_Scope
	;

flingGen_Switch:
	KwGen KwSwitch flingExpr
	'{'
		(
			flingGen_Switch_Default? flingGen_Switch_Case*
			| flingGen_Switch_Case+ flingGen_Switch_Default
		)
	'}'
	;
flingGen_Switch_Default:
	KwDefault flingDeclModule_Scope
	;
flingGen_Switch_Case:
	flingExprList flingDeclModule_Scope
	;

flingGen_For:
	KwGen '[' flingIdent ']' KwFor flingIdent ':' flingExpr
		flingDeclModule_Scope
	;
//--------

//--------
flingContAssign:
	flingExpr PunctNonBlkAssign flingExpr ';'
	;
//--------

//--------
flingBehav:
	(
		KwInitial
		| KwComb
		| KwSeq flingBehav_Seq_EdgeList
	)
	flingBehav_Scope
	;

flingBehav_Seq_EdgeList:
	flingBehav_Seq_EdgeList_Item
	(',' flingBehav_Seq_EdgeList_Item)*
	;
flingBehav_Seq_EdgeList_Item:
	(KwPosedge | KwNegedge) flingExpr
	;

flingBehav_Scope:
	'{'
		flingBehav_Item*
	'}'
	;

flingBehav_Item:
	flingBehav_Scope
	| flingDeclAlias
	| flingDeclVar
	| flingDeclConst
	| flingDeclType

	| flingBehav_Item_BlkAssign
	| flingBehav_Item_NonBlkAssign

	| flingBehav_Item_If
	| flingBehav_Item_SwitchOrSwitchz
	| flingBehav_Item_For
	| flingBehav_Item_While

	// Call a `func` or a `task`
	| flingExpr ';'
	;


flingBehav_Item_If:
	KwIf flingExpr flingBehav_Scope
	flingBehav_Item_If_Elif*
	flingBehav_Item_If_Else?
	;
flingBehav_Item_If_Elif:
	KwElif flingExpr flingBehav_Scope
	;
flingBehav_Item_If_Else:
	KwElse flingBehav_Scope
	;

flingBehav_Item_SwitchOrSwitchz:
	(KwSwitch | KwSwitchz) flingExpr
	'{'
		(
			flingBehav_Item_SwitchOrSwitchz_Default?
				flingBehav_Item_SwitchOrSwitchz_Case*
			| flingBehav_Item_SwitchOrSwitchz_Case+
				flingBehav_Item_SwitchOrSwitchz_Default
		)
	'}'
	;
flingBehav_Item_SwitchOrSwitchz_Default:
	KwDefault flingBehav_Scope
	;
flingBehav_Item_SwitchOrSwitchz_Case:
	flingExprList flingBehav_Scope
	;

flingBehav_Item_For:
	KwFor flingIdent ':' flingExpr
		flingBehav_Scope
	;

flingBehav_Item_While:
	KwWhile flingExpr flingBehav_Scope
	;

flingBehav_Item_NonBlkAssign:
	flingExpr PunctNonBlkAssign flingExpr ';'
	;
flingBehav_Item_BlkAssign:
	flingExpr PunctBlkAssign flingExpr ';'
	;
//--------

//--------
flingDeclWire:
	flingIdentList ':' KwWire flingTypenameOrModname ('=' flingExprList)?
		';'
	;

flingDeclVar:
	flingIdentList ':' flingTypenameOrModname ('=' flingExprList)? ';'
	;

flingDeclConst:
	flingIdentList ':' KwConst flingTypenameOrModname '=' flingExprList ';'
	;
//--------

//--------
flingDeclType:
	flingDeclEnum
	| flingDeclClass
	| flingDeclMixin
	;
//--------

//--------
flingDeclEnum:
	KwEnum flingIdent (':' flingTypenameOrModname)?
	'{'
		flingIdentList ','?
	'}'
	;
//--------

//--------
flingDeclClass:
	KwBase? KwClass (KwSigned? KwPacked)? flingIdent flingDeclParamList?
		flingDeclClsOrMxn_Extends?
	'{'
		flingDeclClass_Item*
	'}'
	;

flingDeclClsOrMxn_Extends:
	KwExtends flingTypenameOrModnameList
	;


flingDeclClass_Item:
	flingDeclClass_Item_DeclVar
	| flingDeclClsOrMxn_Item
	;
flingDeclClass_Item_DeclVar:
	flingDeclClsOrMxn_AccessSpecifier? KwStatic? flingDeclVar
	;

flingDeclClsOrMxn_Item:
	flingDeclClsOrMxn_Item_DeclType 
	| flingDeclClsOrMxn_Item_DeclAliasOrConst
	| flingDeclClsOrMxn_Item_DeclSubprog

	| flingImportList
	;

flingDeclClsOrMxn_Item_DeclType:
	flingDeclClsOrMxn_AccessSpecifier? flingDeclType
	;
flingDeclClsOrMxn_Item_DeclAliasOrConst:
	flingDeclClsOrMxn_AccessSpecifier? KwStatic?
	(flingDeclAlias | flingDeclConst)
	;

flingDeclClsOrMxn_AccessSpecifier:
	KwPub | KwProt | KwPriv
	;

flingDeclClsOrMxn_Item_DeclSubprog:
	flingDeclClsOrMxn_Item_DeclSubprog_FullDefn
	| flingDeclClsOrMxn_Item_DeclSubprog_Abstract
	;
flingDeclClsOrMxn_Item_DeclSubprog_FullDefn:
	flingDeclClsOrMxn_AccessSpecifier?
	(KwVirtual | KwStatic)? KwConst? flingDeclSubprog
	;
flingDeclClsOrMxn_Item_DeclSubprog_Abstract:
	flingDeclClsOrMxn_AccessSpecifier?
	KwAbstract KwConst?
	(
		flingDeclFunc_Header
		| flingDeclTask_Header
		| flingDeclProc_Header
	)
	';'
	;

flingDeclMixin:
	KwBase? KwMixin flingIdent flingDeclParamList?
		flingDeclClsOrMxn_Extends?
	'{'
		flingDeclClsOrMxn_Item*
	'}'
	;
//--------

//--------
flingDeclSubprog:
	flingDeclFunc
	| flingDeclTask
	| flingDeclProc
	;

flingDeclFunc:
	flingDeclFunc_Header flingDeclFunc_Scope
	;
flingDeclFunc_Header:
	KwFunc flingIdent flingDeclParamList? flingDeclArgList
		':' flingTypenameOrModname
	;

flingDeclFunc_Scope:
	'{'
		flingDeclFunc_Item*
	'}'
	;
flingDeclFunc_Item:
	// Return statement or call a `func`
	KwReturn? flingExpr ';'
	| flingDeclFunc_Scope
	| flingDeclAlias
	| flingDeclVar
	| flingDeclConst
	| flingDeclType

	| flingBehav_Item_BlkAssign

	| flingDeclFunc_Item_If
	| flingDeclFunc_Item_SwitchOrSwitchz
	| flingDeclFunc_Item_For
	| flingDeclFunc_Item_While
	;

flingDeclFunc_Item_If:
	KwIf flingExpr flingDeclFunc_Scope
	flingDeclFunc_Item_If_Elif*
	flingDeclFunc_Item_If_Else?
	;
flingDeclFunc_Item_If_Elif:
	KwElif flingExpr flingDeclFunc_Scope
	;
flingDeclFunc_Item_If_Else:
	KwElse flingDeclFunc_Scope
	;

flingDeclFunc_Item_SwitchOrSwitchz:
	(KwSwitch | KwSwitchz) flingExpr
	'{'
		(
			flingDeclFunc_Item_SwitchOrSwitchz_Default?
				flingDeclFunc_Item_SwitchOrSwitchz_Case*
			| flingDeclFunc_Item_SwitchOrSwitchz_Case+
				flingDeclFunc_Item_SwitchOrSwitchz_Default
		)
	'}'
	;
flingDeclFunc_Item_SwitchOrSwitchz_Default:
	KwDefault flingDeclFunc_Scope
	;
flingDeclFunc_Item_SwitchOrSwitchz_Case:
	flingExprList flingDeclFunc_Scope
	;

flingDeclFunc_Item_For:
	KwFor flingIdent ':' flingExpr
		flingDeclFunc_Scope
	;

flingDeclFunc_Item_While:
	KwWhile flingExpr flingDeclFunc_Scope
	;

flingDeclTask:
	flingDeclTask_Header flingDeclTask_Scope
	;

flingDeclTask_Header:
	KwTask flingIdent flingDeclParamList? flingDeclArgList
	;
flingDeclTask_Scope:
	'{'
		flingDeclTask_Item*
	'}'
	;
flingDeclTask_Item:
	flingDeclTask_Scope
	| flingDeclAlias
	| flingDeclVar
	| flingDeclConst
	| flingDeclType

	| flingBehav_Item_BlkAssign
	| flingBehav_Item_NonBlkAssign

	| flingDeclTask_Item_If
	| flingDeclTask_Item_SwitchOrSwitchz
	| flingDeclTask_Item_For
	| flingDeclTask_Item_While

	// Call a `func` or a `task`
	| flingExpr ';'

	;

flingDeclTask_Item_If:
	KwIf flingExpr flingDeclTask_Scope
	flingDeclTask_Item_If_Elif*
	flingDeclTask_Item_If_Else?
	;
flingDeclTask_Item_If_Elif:
	KwElif flingExpr flingDeclTask_Scope
	;
flingDeclTask_Item_If_Else:
	KwElse flingDeclTask_Scope
	;

flingDeclTask_Item_SwitchOrSwitchz:
	(KwSwitch | KwSwitchz) flingExpr
	'{'
		(
			flingDeclTask_Item_SwitchOrSwitchz_Default?
				flingDeclTask_Item_SwitchOrSwitchz_Case*
			| flingDeclTask_Item_SwitchOrSwitchz_Case+
				flingDeclTask_Item_SwitchOrSwitchz_Default
		)
	'}'
	;
flingDeclTask_Item_SwitchOrSwitchz_Default:
	KwDefault flingDeclTask_Scope
	;
flingDeclTask_Item_SwitchOrSwitchz_Case:
	flingExprList flingDeclTask_Scope
	;

flingDeclTask_Item_For:
	KwFor flingIdent ':' flingExpr
		flingDeclTask_Scope
	;

flingDeclTask_Item_While:
	KwWhile flingExpr flingDeclTask_Scope
	;

flingDeclProc:
	flingDeclProc_Header flingDeclModule_Scope
	;
flingDeclProc_Header:
	KwProc flingIdent flingDeclParamList? flingDeclProc_ArgList
	;
flingDeclProc_ArgList:
	'('
		flingDeclProc_ArgList_Item
		(';' flingDeclProc_ArgList_Item)*
		';'?
	')'
	;
flingDeclProc_ArgList_Item:
	flingIdentList ':' (KwInput | KwInout) flingTypenameOrModname
		('=' flingExprList)?
	;
//--------

//--------
flingDeclAlias:
	flingDeclAlias_Value
	| flingDeclAlias_Type
	| flingDeclAlias_Module
	;
flingDeclAlias_Value:
	KwAlias flingIdentList ':' flingTypenameOrModname '=' flingExprList ';'
	;
flingDeclAlias_Type:
	KwAlias flingIdentList ':' KwType '=' flingTypenameOrModnameList ';'
	;
flingDeclAlias_Module:
	KwAlias flingIdentList ':' KwModule '=' flingTypenameOrModnameList ';'
	;
//--------

//--------
flingIdent:
	MiscIdent
	;
flingIdentList:
	flingIdent (',' flingIdent)*
	;
flingScopedIdent:
	flingIdent (PunctScopeAccess flingIdent)*
	;

// Don't need an AST node specifically for this
flingExprList:
	flingExpr (',' flingExpr)*
	;
// Don't need an AST node specifically for this
flingTypenameOrModnameList:
	flingTypenameOrModname (',' flingTypenameOrModname)*
	;

flingImportList:
	KwImport flingScopedIdent (',' flingScopedIdent)*
	;
//--------

//--------
flingTypenameOrModname:
	flingTypenameOrModname_Cstm
	| flingTypenameOrModname_Typeof
	| flingTypenameOrModname_Builtin

	| KwSelfT
	| KwRetT
	;

flingTypenameOrModname_Cstm:
	flingTypenameOrModname_Cstm_Item
	(PunctScopeAccess flingTypenameOrModname_Cstm_Item)*
		flingTypenameOrModname_ArrDim*
	;
flingTypenameOrModname_Typeof:
	KwTypeof '(' flingExpr ')'
	(PunctScopeAccess flingTypenameOrModname_Cstm_Item)*
		flingTypenameOrModname_ArrDim*
	;

flingTypenameOrModname_Cstm_Item:
	flingIdent flingInstParamList?
	;

flingTypenameOrModname_ArrDim:
	'[' (flingExpr | flingTypenameOrModname)? ']'
	;

flingTypenameOrModname_Builtin:
	(
		KwSigned? KwLogic flingInstParamList?

		| KwInteger
		| KwSizeT
		| KwRange
		| KwString

		| KwU8
		| KwI8
		| KwU16
		| KwI16
		| KwU32
		| KwI32
		| KwU64
		| KwI64
		| KwU128
		| KwI128

		| KwAuto
	) flingTypenameOrModname_ArrDim*
	| KwVoid
	;
//--------

//--------
flingExpr:
	KwMux '(' flingExpr ',' flingExpr ',' flingExpr ')' 
	| flingExpr_Mux
	;

flingExpr_Mux:
	flingExpr_LogOr (PunctLogOr flingExpr)?
	;

flingExpr_LogOr:
	flingExpr_LogAnd (PunctLogAnd flingExpr)?
	;

flingExpr_LogAnd:
	flingExpr_BitOr_Or_BitNor ((PunctBitOr | PunctBitNor) flingExpr)?
	;

flingExpr_BitOr_Or_BitNor:
	flingExpr_BitAnd_Or_BitNand ((PunctBitAnd | PunctBitNand) flingExpr)?
	;

flingExpr_BitAnd_Or_BitNand:
	flingExpr_BitXor_Or_BitXnor ((PunctBitXor | PunctBitXnor) flingExpr)?
	;

flingExpr_BitXor_Or_BitXnor:
	flingExpr_CmpEqEtc
		((PunctCmpEq | PunctCmpNe | PunctCaseCmpEq | PunctCaseCmpNe)
		flingExpr)?
	;

flingExpr_CmpEqEtc:
	flingExpr_CmpLtEtc
		((PunctCmpLt | PunctCmpLe | PunctCmpGt | PunctCmpGe) flingExpr)?
	;

flingExpr_CmpLtEtc:
	flingExpr_BitShift ((KwLsl | KwLsr | KwAsr) flingExpr)?
	;

flingExpr_BitShift:
	flingExpr_BinaryPlus_Or_BinaryMinus
		((PunctPlus | PunctMinus) flingExpr)?
	;

flingExpr_BinaryPlus_Or_BinaryMinus:
	flingExpr_Mul_Or_Div_Or_Mod
		((PunctMul | PunctDiv | PunctMod) flingExpr)?
	;

flingExpr_Mul_Or_Div_Or_Mod:
	(
		PunctPlus | PunctMinus | PunctLogNot | PunctBitNot

		// Reduction operators
		| PunctBitOr | PunctBitNor | PunctBitAnd | PunctBitNand
		| PunctBitXor | PunctBitXnor
	) flingExpr

	| flingExpr_Unary
	;

flingExpr_Unary:
	flingExpr_Unary_ItemFromMajority
	| flingExpr_Range
	| flingExpr_CallSubprog_PseudoOper
	;

flingExpr_Unary_ItemFromMajority:
	flingExpr_Literal
	| flingExpr_Sized
	| flingExpr_Cat
	| flingExpr_Repl
	| flingExpr_KwDollarFuncOf
	| flingExpr_IdentEtc
	| '(' flingExpr ')'
	;

flingExpr_Literal:
	LitDecNum
	| LitHexNum
	| LitOctNum
	| LitBinNum
	//| LitFloatNum
	| LitString
	| KwHighZ ('(' flingExpr ')')?
	| KwUnkX ('(' flingExpr ')')?
	;
flingExpr_Sized:
	KwSized '(' flingExpr ',' flingExpr ')'
	;

flingExpr_Range:
	flingExpr_Range_DotDot
	| flingExpr_Range_CallFunc
	;

flingExpr_Range_DotDot:
	flingExpr_Unary_ItemFromMajority PunctColon flingExpr
	;
flingExpr_Range_CallFunc:
	KwRange '(' flingExpr ',' flingExpr ')'
	;

flingExpr_Cat:
	KwCat '(' flingExprList ')'
	;

flingExpr_Repl:
	KwRepl '(' flingExpr ',' flingExpr ')'
	;
flingExpr_KwDollarFuncOf:
	flingExpr_KwDollarFuncOf_NonPow
	| flingExpr_KwDollarFuncOf_Pow
	;

flingExpr_KwDollarFuncOf_NonPow:
	(KwDollarSigned | KwDollarUnsigned | KwDollarClog2 | KwDollarIsvtype)
		'(' flingExpr ')'
	;

flingExpr_KwDollarFuncOf_Pow:
	KwDollarPow '(' flingExpr ',' flingExpr ')'
	;

flingExpr_IdentEtc:
	(flingTypenameOrModname PunctScopeAccess)?
	flingExpr_IdentEtc_FirstItem
	(PunctMemberAccess flingExpr_IdentEtc_NonSelfItem)*

	(KwDollarSize | KwDollarRange | KwDollarHigh | KwDollarLow)?
	;
flingExpr_IdentEtc_FirstItem:
	KwSelf
	| flingExpr_IdentEtc_NonSelfItem
	;

flingExpr_IdentEtc_NonSelfItem:
	flingIdent (flingInstParamList? flingInstArgList)?
		flingExpr_IdentEtc_Item_End*
	;

flingExpr_IdentEtc_Item_End:
	flingExpr_IdentEtc_Item_End_Index
	| KwDollarFirstel
	| KwDollarLastel
	;
flingExpr_IdentEtc_Item_End_Index:
	'[' flingExpr ((PunctPlusColon | PunctMinusColon) flingExpr)? ']'
	;

// Call a member function via `a plus b` instead of `a.plus(b)`
flingExpr_CallSubprog_PseudoOper:
	(
		flingExpr_Unary_ItemFromMajority
		| flingExpr_Range_CallFunc
	)
	flingIdent flingInstParamList? flingExpr
	;
//--------


// Lexer rules
//--------
LexWhitespace: (' ' | '\t' | '\r' | '\n') -> skip ;

LexLineComment: ('//' ~('\n')+) -> skip ;
//--------

//--------
fragment FragDecNum:
	[0-9] [0-9_]*
	;
LitDecNum: FragDecNum ;
LitHexNum: '0x' [0-9a-fA-F] [0-9a-fA-F_]* ;
LitOctNum: '0o' [0-7] [0-7_]* ;
LitBinNum: '0b' [0-1] [0-1_]* ;


fragment FragFloatFrac:
	FragDecNum? '.' FragDecNum
	| FragDecNum '.'
	;
fragment FragFloatExpPart:
	'e' FragFloatSign? FragDecNum
	| 'E' FragFloatSign? FragDecNum
	;
fragment FragFloatSign: '+' | '-' ;
fragment FragFloatSuffix: 'f' | 'd' | 'l' | 'F' | 'D' | 'L' ;

LitFloatNum: 
	(
		FragFloatFrac FragFloatExpPart? FragFloatSuffix?
		| FragDecNum FragFloatExpPart FragFloatSuffix?
	)
	;


fragment FragEscapeSequence:
	FragBasicEscapeSequence
	| FragHexEscapeSequence
	;

fragment FragBasicEscapeSequence:
	'\\' ['"?abfnrtv\\]
	;

fragment FragHexEscapeSequence:
	'\\x' [A-Fa-f0-9_]+
	;

fragment FragChar:
	~["\\]
	| FragEscapeSequence
	;


LitString: '"' FragChar* '"' ;
//--------

//--------
PunctNonBlkAssign: ':=' ;
PunctBlkAssign: '=' ;
//--------

//--------
PunctLogOr: '||' ;
PunctLogAnd: '&&' ;

PunctCmpEq: '==' ;
PunctCmpNe: '!=' ;
PunctCaseCmpEq: '===' ;
PunctCaseCmpNe: '!==' ;

PunctCmpLt: '<' ;
PunctCmpGt: '>' ;
PunctCmpLe: '<=' ;
PunctCmpGe: '>=' ;


PunctPlus: '+' ;
PunctMinus: '-' ;

PunctMul: '*' ;
PunctDiv: '/' ;
PunctMod: '%' ;

PunctBitOr: '|' ;
PunctBitNor: '~|' ;

PunctBitAnd: '&' ;
PunctBitNand: '~&' ;

PunctBitXor: '^' ;
PunctBitXnor: '^~' | '~^' ;

KwLsl: 'lsl' ;
KwLsr: 'lsr' ;
KwAsr: 'asr' ;

PunctBitNot: '~' ;
PunctLogNot: '!' ;
//--------

//--------
PunctMapTo: '=>' ;
//--------

//--------
PunctMemberAccess: '.' ;
PunctScopeAccess: '::' ;
//--------

//--------
PunctLParen: '(' ;
PunctRParen: ')' ;
PunctLBracket: '[' ;
PunctRBracket: ']' ;
PunctLBrace: '{' ;
PunctRBrace: '}' ;
PunctSemicolon: ';' ;
PunctColon: ':' ;
PunctPlusColon: '+:' ;
PunctMinusColon: '-:' ;
PunctComma: ',' ;
//PunctParamPack: '...' ;
//--------


//--------
KwIf: 'if' ;
KwElif: 'elif' ;
KwElse: 'else' ;
KwMux: 'mux' ;

KwSwitch: 'switch' ;
KwSwitchz: 'switchz' ;
KwDefault: 'default' ;

KwFor: 'for' ;
KwWhile: 'while' ;

KwBreak: 'break' ;
KwContinue: 'continue' ;
//--------

//--------
KwModule: 'module' ;
KwPackage: 'package' ;

KwInput: 'input' ;
KwOutput: 'output' ;
KwInout: 'inout' ;
KwInterface: 'interface' ;

KwGen: 'gen' ;

KwInitial: 'initial' ;
KwComb: 'comb' ;

KwSeq: 'seq' ;
KwPosedge: 'posedge' ;
KwNegedge: 'negedge' ;

KwFunc: 'func' ;
KwTask: 'task' ;

KwImport: 'import' ;
KwAll: 'all' ;

KwWire: 'wire' ;
KwLogic: 'logic' ;

KwConst: 'const' ;
//KwUnsigned: 'unsigned' ;
KwSigned: 'signed' ;

KwInteger: 'integer' ;
KwSizeT: 'size_t' ;

KwU8: 'u8' ;
KwI8: 'i8' ;
KwU16: 'u16' ;
KwI16: 'i16' ;
KwU32: 'u32' ;
KwI32: 'i32' ;
KwU64: 'u64' ;
KwI64: 'i64' ;
KwU128: 'u128' ;
KwI128: 'i128' ;

KwReturn: 'return' ;
KwRetT: 'ret_t' ;

KwAuto: 'auto' ;

KwRange: 'range' ;

KwHighZ: 'high_z' ;
KwUnkX: 'unk_x' ;
KwSized: 'sized' ;
KwCat: 'cat' ;
KwRepl: 'repl' ;
KwAs: 'as' ;

KwDollarSize: '$size' ;
KwDollarRange: '$range' ;
KwDollarHigh: '$high' ;
KwDollarLow: '$low' ;
KwDollarFirstel: '$firstel' ;
KwDollarLastel: '$lastel' ;
KwDollarSigned: '$signed' ;
KwDollarUnsigned: '$unsigned' ;

KwDollarPow: '$pow' ;
KwDollarClog2: '$clog2' ;

//KwDollarDisplay: '$display' ;
//KwDollarMonitor: '$monitor' ;
//KwDollarFinish: '$finish' ;
//KwDollarStop: '$stop' ;


KwAssert: 'assert' ;
KwAssume: 'assume' ;
KwCover: 'cover' ;
//--------


//--------
KwVoid: 'void' ;

KwType: 'type' ;
KwTypeof: 'typeof' ;

//KwAttr: 'attr' ;

KwAlias: 'alias' ;

KwEnum: 'enum' ;

KwClass: 'class' ;
KwPacked: 'packed' ;

KwMixin: 'mixin' ;
KwExtends: 'extends' ;

KwVirtual: 'virtual' ;
KwAbstract: 'abstract' ;
KwDollarIsvtype: '$isvtype' ;

KwBase: 'base' ;
KwStatic: 'static' ;
KwProc: 'proc' ;
KwSelf: 'self' ;
KwSelfT: 'self_t' ;

KwPub: 'pub' ;
KwProt: 'prot' ;
KwPriv: 'priv' ;

//KwInit: 'init' ;
//KwDest: 'dest' ;
//KwNone: 'none' ;

//KwMove: 'move' ;

//KwList: 'list' ;
//KwDict: 'dict' ;
//KwSet: 'set' ;
KwString: 'string' ;

KwFloat: 'float' ;
//KwFile: 'file' ;
//
//KwDelay: 'delay' ;
//--------

//--------
// The non-post/pre underscore parts must start and end with an
// alphanumeric character, and there must be at least two alphanumeric
// characters.
MiscReservedIdent:
	'__' [A-Za-z] ([A-Za-z0-9_]* [A-Za-z0-9])? '__'
	;
//MiscMacroOrDefineIdent:
//	'`' [A-Za-z_] [A-Za-z0-9_]*
//	;

fragment FragBasicIdent: '_'? [A-Za-z] ('_'? [A-Za-z0-9])* '_'?  ;
fragment FragRawIdent: 'r#' [A-Za-z_0-9]+ ;

MiscIdent: 
	FragBasicIdent | FragRawIdent ;
MiscOther: . ;
//--------
