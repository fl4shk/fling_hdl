grammar FlingHdlGrammar;

//--------
// Parser rules
flingProgram:
	flingPackage
	| flingModule
	| flingDeclType
	| flingDeclSubprog
	| flingDeclAlias
	;
//--------

//--------
flingPackage:
	KwPackage flingIdent
	'{'
		flingPackage_Item*
	'}'
	;

flingPackage_Item:
	flingPackage
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
		flingDeclArgList_Item
		(';' flingDeclArgList_Item)*
		';'?
	')'
	;
flingDeclArgList_Item:
	flingIdentList ':'
		(KwInput | KwOutput | KwInout | KwInterface | KwModport)
		flingTypenameOrModname ('=' flingExprList)?
	;
//--------

//--------
flingInstParamList:
	'<'
		(
			flingInstParamList_Pos
			| flingInstParamList_Named
		)
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
		)
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
flingModule:
	KwModule flingIdent flingDeclParamList? flingDeclArgList
		(':' flingImportList)?
	flingModule_Scope
	;

flingModule_Scope:
	'{'
		flingModule_Item*
	'}'
	;

flingModule_Item:
	flingInstModule

	// This is a `proc` call
	| flingExpr_CallSubprog
	| flingGenerate
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
flingGenerate:
	flingGenerate_If
	| flingGenerate_Switch
	| flingGenerate_For
	;

flingGenerate_If:
	KwGenerate KwIf flingExpr flingModule_Scope
	flingGenerate_If_Elif*
	flingGenerate_If_Else?
	;
flingGenerate_If_Elif:
	KwGenerate KwElif flingExpr flingModule_Scope
	;
flingGenerate_If_Else:
	KwGenerate KwElse flingModule_Scope
	;

flingGenerate_Switch:
	KwGenerate KwSwitch flingExpr
	'{'
		(
			flingGenerate_Switch_Default? flingGenerate_Switch_Case*
			| flingGenerate_Switch_Case+ flingGenerate_Switch_Default
		)
	'}'
	;
flingGenerate_Switch_Default:
	KwDefault flingModule_Scope
	;
flingGenerate_Switch_Case:
	flingExprList flingModule_Scope
	;

flingGenerate_For:
	KwGenerate '[' flingIdent ']' KwFor flingIdent ':' flingExpr
		flingModule_Scope
	;
//--------

//--------
flingContAssign:
	flingExpr '=' flingExpr ';'
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
	flingDeclAlias
	| flingDeclVar
	| flingDeclConst
	| flingDeclType

	| flingBehav_Scope

	| flingBehav_If
	| flingBehav_SwitchOrSwitchz
	| flingBehav_For
	| flingBehav_While
	| flingBehav_NonBlkAssign
	| flingBehav_BlkAssign

	// Call a `func` or a `task`
	| flingExpr_CallSubprog
	;

flingBehav_If:
	KwIf flingExpr flingBehav_Scope
	flingBehav_If_Elif*
	flingBehav_If_Else?
	;
flingBehav_If_Elif:
	KwElif flingExpr flingBehav_Scope
	;
flingBehav_If_Else:
	KwElse flingBehav_Scope
	;

flingBehav_SwitchOrSwitchz:
	(KwSwitch | KwSwitchz) flingExpr
	'{'
		(
			flingBehav_SwitchOrSwitchz_Default?
				flingBehav_SwitchOrSwitchz_Case*
			| flingBehav_SwitchOrSwitchz_Case+
				flingBehav_SwitchOrSwitchz_Default
		)
	'}'
	;
flingBehav_SwitchOrSwitchz_Default:
	KwDefault flingBehav_Scope
	;
flingBehav_SwitchOrSwitchz_Case:
	flingExprList flingBehav_Scope
	;

flingBehav_For:
	KwFor flingIdent ':' flingExpr
		flingBehav_Scope
	;

flingBehav_While:
	KwWhile flingExpr flingBehav_Scope
	;

flingBehav_NonBlkAssign:
	flingExpr PunctNonBlkAssign flingExpr ';'
	;
flingBehav_BlkAssign:
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
	flingDeclType_Enum
	| flingDeclType_Class
	| flingDeclType_Mixin
	;
//--------

//--------
flingDeclType_Enum:
	KwEnum flingIdent (':' flingTypenameOrModname_Builtin)?
	'{'
		flingIdentList ','?
	'}'
	;
//--------

//--------
flingDeclType_Class:
	KwBase? KwClass (KwPacked KwSigned?)? flingIdent flingDeclParamList
		flingDeclType_ClassOrMixin_Extends?
	'{'
		flingDeclType_Class_Item*
	'}'
	;

flingDeclType_ClassOrMixin_Extends:
	KwExtends flingTypenameOrModnameList
	;


flingDeclType_Class_Item:
	flingDeclType_ClassOrMixin_Item
	| flingDeclType_ClassOrMixin_AccessSpecifier? KwStatic? flingDeclVar
	;

flingDeclType_ClassOrMixin_Item:
	(
		flingDeclType_ClassOrMixin_AccessSpecifier? KwStatic?
		(flingDeclType | flingDeclAlias | flingDeclConst)
	)
	| flingDeclType_ClassOrMixin_Item_DeclSubprog

	| flingImportList

	;

flingDeclType_ClassOrMixin_AccessSpecifier:
	KwPub | KwProt | KwPriv
	;

flingDeclType_ClassOrMixin_Item_DeclSubprog:
	flingDeclType_ClassOrMixin_AccessSpecifier? (KwVirtual | KwStatic)?
		KwConst? flingDeclSubprog
	| KwAbstract KwVirtual KwConst?
		(flingDeclSubprog_Func_Header | flingDeclSubprog_Task_Header
		| flingDeclSubprog_Proc_Header) ';'
	;

flingDeclType_Mixin:
	KwMixin flingIdent flingDeclParamList
		flingDeclType_ClassOrMixin_Extends?
	'{'
		flingDeclType_ClassOrMixin_Item*
	'}'
	;

//--------

//--------
flingDeclSubprog:
	flingDeclSubprog_Func
	| flingDeclSubprog_Task
	| flingDeclSubprog_Proc
	;

flingDeclSubprog_Func:
	flingDeclSubprog_Func_Header flingBehav_Scope
	;
flingDeclSubprog_Func_Header:
	KwFunc flingIdent flingDeclParamList? flingDeclArgList
		':' flingTypenameOrModname
	;

flingDeclSubprog_Task:
	flingDeclSubprog_Task_Header flingBehav_Scope
	;

flingDeclSubprog_Task_Header:
	KwTask flingIdent flingDeclParamList? flingDeclArgList
	;

flingDeclSubprog_Proc:
	flingDeclSubprog_Proc_Header flingModule_Scope
	;
flingDeclSubprog_Proc_Header:
	KwProc flingIdent flingDeclParamList? flingDeclSubprog_Proc_ArgList
	;
flingDeclSubprog_Proc_ArgList:
	'('
		flingDeclSubprog_Proc_ArgList_Item
		(';' flingDeclSubprog_Proc_ArgList_Item)*
		';'?
	')'
	;
flingDeclSubprog_Proc_ArgList_Item:
	flingIdentList ':' KwConst? KwRef flingTypenameOrModname 
	;
//--------

//--------
flingDeclAlias:
	KwAlias flingIdentList ':'
		(
			flingTypenameOrModname '=' flingExprList
			| (KwType | KwModule) '=' flingTypenameOrModnameList
		)
	';'
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

flingExprList:
	flingExpr (',' flingExpr)*
	;
flingTypenameOrModnameList:
	flingTypenameOrModname (',' flingTypenameOrModname)*
	;

flingImportList:
	KwImport flingScopedIdent (',' flingScopedIdent)*
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
PunctRangeSeparator: '..' ;
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
PunctBitAnd: '&' ;
PunctBitXor: '^' ;

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

KwGenerate: 'generate' ;

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
KwUnsigned: 'unsigned' ;
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

KwDollarDisplay: '$display' ;
KwDollarMonitor: '$monitor' ;
KwDollarFinish: '$finish' ;
KwDollarStop: '$stop' ;


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
KwModport: 'modport' ;

KwVirtual: 'virtual' ;
KwAbstract: 'abstract' ;
KwIsvtype: 'isvtype' ;

KwBase: 'base' ;
KwStatic: 'static' ;
KwProc: 'proc' ;
KwSelf: 'self' ;
KwSelfT: 'self_t' ;

KwPub: 'pub' ;
KwProt: 'prot' ;
KwPriv: 'priv' ;
KwRef: 'ref' ;

KwInit: 'init' ;
KwDest: 'dest' ;
KwNone: 'none' ;

KwMove: 'move' ;

KwList: 'list' ;
KwDict: 'dict' ;
KwSet: 'set' ;
KwString: 'string' ;
KwFloat: 'float' ;
KwFile: 'file' ;

KwDelay: 'delay' ;
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

fragment FragBasicIdent: ([_]? [A-Za-z]) ([_]? [A-Za-z0-9])* [_]?  ;
fragment FragRawIdent: 'r#' [A-Za-z_0-9]+ ;

MiscIdent: 
	FragBasicIdent | FragRawIdent ;
MiscOther: . ;
//--------
