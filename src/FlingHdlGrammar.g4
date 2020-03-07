grammar FlingHdlGrammar;

//--------
// Parser rules
hdlProgram:
	hdlModule
	| hdlPackage
	| hdlDeclType
	| hdlDeclSubprogram
	| hdlDeclAlias
	;
//--------

//--------
hdlModule:
	KwModule MiscIdent hdlDeclParamList? hdlDeclArgList
		(':' hdlImportList)?
	hdlModule_Scope
	;

hdlModule_Scope:
	'{'
		hdlModule_Item*
	'}'
	;

hdlModule_Item:
	hdlInstModule

	// This is a `proc` call
	| hdlExpr_CallSubprogram
	| hdlGen
	| hdlContAssign
	| hdlImport

	| hdlBehav
	| hdlDeclWire
	| hdlDeclVar
	| hdlDeclConst

	| hdlDeclType
	| hdlDeclSubprogram
	| hdlDeclAlias
	;
//--------

//--------
hdlInstModule:
	MiscIdent ':' KwModule hdlTypenameOrModname hdlInstArgList ';'
	;
//--------

//--------
hdlGen:
	hdlGenerate_If
	| hdlGenerate_Switch
	| hdlGenerate_For
	;

hdlGenerate_If:
	KwGenerate KwIf hdlExpr hdlModule_Scope
	hdlGenerate_If_Elif*
	hdlGenerate_If_Else?
	;
hdlGenerate_If_Elif:
	KwGenerate KwElif hdlExpr hdlModule_Scope
	;
hdlGenerate_If_Else:
	KwGenerate KwElse hdlModule_Scope
	;

hdlGenerate_Switch:
	KwGenerate KwSwitch hdlExpr
	'{'
		(
			hdlGenerate_Switch_Default? hdlGenerate_Switch_Case*
			| hdlGenerate_Switch_Case+ hdlGenerate_Switch_Default
		)
	'}'
	;
hdlGenerate_Switch_Default:
	KwDefault hdlModule_Scope
	;
hdlGenerate_Switch_Case:
	hdlExpr hdlModule_Scope
	;

hdlGenerate_For:
	KwGenerate '[' MiscIdent ']' KwFor MiscIdent ':' hdlExpr_Range
		hdlModule_Scope
	;
//--------

//--------
hdlContAssign:
	hdlExpr '=' hdlExpr ';'
	;
//--------

//--------
hdlDeclWire:
	hdlIdentList ':' KwWire hdlTypenameOrModname ('=' hdlExprList)? ';'
	;

hdlDeclVar:
	hdlIdentList ':' hdlTypenameOrModname ('=' hdlExprList)? ';'
	;

hdlDeclConst:
	hdlIdentList ':' KwConst hdlTypenameOrModname '=' hdlExprList ';'
	;
//--------

//--------
hdlDeclType:
	hdlDeclType_Enum
	| hdlDeclType_Class
	| hdlDeclType_Mixin
	;
//--------

//--------
hdlDeclSubprogram:
	hdlDeclSubprogram_Func
	| hdlDeclSubprogram_Task
	| hdlDeclSubprogram_Proc
	;
//--------

//--------
hdlDeclAlias:
	KwAlias hdlIdentList ':'
		(
			hdlTypenameOrModname '=' hdlExprList
			| (KwType | KwModule) '=' hdlTypenameOrModnameList
		)
	';'
	;
//--------

//--------
hdlIdentList:
	MiscIdent (',' MiscIdent)*
	;
hdlExprList:
	hdlExpr (',' hdlExpr)*
	;
hdlTypenameOrModnameList:
	hdlTypenameOrModname (',' hdlTypenameOrModname)*
	;

hdlImport_MainContents:
	MiscIdent (PunctScopeAccess MiscIdent)*
	;
hdlImport:
	KwImport hdlImport_MainContents ';'
	;
hdlImportList:
	KwImport hdlImport_MainContents (',' hdlImport_MainContents)*
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
PunctNonblkAssign: ':=' ;
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
PunctMapsTo: '=>' ;
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
PunctParamPack: '...' ;
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
KwEncAs: 'enc_as' ;

KwClass: 'class' ;
KwPacked: 'packed' ;

KwMixin: 'mixin' ;
KwExtends: 'extends' ;
KwModport: 'modport' ;

KwVirtual: 'virtual' ;
KwIsvtype: 'isvtype' ;

KwFinal: 'final' ;
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
KwNull: 'null' ;

KwMove: 'move' ;

//KwGenerate: 'generate' ;

KwList: 'list' ;
KwDict: 'dict' ;
KwSet: 'set' ;
KwStr: 'str' ;
KwFloat: 'float' ;
KwFile: 'file' ;

//KwEval: 'eval' ;
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
