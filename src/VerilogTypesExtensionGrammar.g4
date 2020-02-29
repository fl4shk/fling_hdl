grammar VerilogTypesExtensionGrammar;

// Parser rules


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
PunctSigAssign: '<-' ;
PunctBlkAssign: '=' ;
//--------

//--------
PunctLogOr: '||' ;
PunctLogAnd: '&&' ;

PunctCmpEq: '==' ;
PunctCmpNe: '!=' ;
PunctCmpLt: '<' ;
PunctCmpGt: '>' ;
PunctCmpLe: '<=' ;
PunctCmpGe: '>=' ;

PunctPlus: '+' ;
PunctMinus: '-' ;

PunctMulOrPtr: '*' ;
PunctDiv: '/' ;
PunctMod: '%' ;

PunctBitOr: '|' ;
PunctBitAnd: '&' ;
PunctBitXor: '^' ;

PunctBitLsl: '<<' ;
PunctBitLsr: '>>' ;
PunctBitAsr: '>>>' ;

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
PunctStartParam: '#(' ;
PunctLParen: '(' ;
PunctRParen: ')' ;
PunctLBracket: '[' ;
PunctRBracket: ']' ;
PunctLBrace: '{' ;
PunctRBrace: '}' ;
PunctSemicolon: ';' ;
PunctColon: ':' ;
PunctComma: ',' ;
//--------


//--------
KwCond: 'cond' ;
KwElse: 'else' ;
KwMux: 'mux' ;

KwSwitch: 'switch' ;
KwDefault: 'default' ;

KwFor: 'for' ;
KwWhile: 'while' ;

KwBreak: 'break' ;
KwContinue: 'continue' ;
//--------

//--------
KwModule: 'module' ;
KwPackage: 'package' ;

KwInst: 'inst' ;

KwInput: 'input' ;
KwOutput: 'output' ;
KwInout: 'inout' ;

//KwAssign: 'assign' ;
KwInitial: 'initial' ;
KwComb: 'comb' ;

KwSeq: 'seq' ;
KwPosedge: 'posedge' ;
KwNegedge: 'negedge' ;

KwWire: 'wire' ;
KwVar: 'var' ;

KwUsing: 'using' ;

KwLogic: 'logic' ;
KwSigned: 'signed' ;

KwGenerate: 'generate' ;
KwLabel: 'label' ;

KwHighZ: 'high_z' ;
KwCat: 'cat' ;

KwFunc: 'func' ;
KwTask: 'task' ;

KwDollarSize: '$size' ;
KwDollarRange: '$range' ;
KwDollarHigh: '$high' ;
KwDollarLow: '$low' ;
KwDollarFirstel: '$firstel' ;
KwDollarLastel: '$lastel' ;
//--------


//--------
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

KwVoid: 'void' ;
KwAuto: 'auto' ;

KwTokstm: 'tokstm' ;

KwType: 'type' ;
KwTypeof: 'typeof' ;

KwSpec: 'spec' ;

KwClass: 'class' ;
KwMixin: 'mixin' ;
KwExtends: 'extends' ;
KwPacked: 'packed' ;
KwUnpacked: 'unpacked' ;
KwVirtual: 'virtual' ;
KwInit: 'init' ;
KwDest: 'dest' ;
KwProc: 'proc' ;
KwSelf: 'self' ;

KwConst: 'const' ;
KwStatic: 'static' ;
KwGen: 'gen' ;
KwToident: 'toident' ;
KwFromident: 'fromident' ;

KwScope: 'scope' ;

KwList: 'list' ;
KwDict: 'dict' ;
KwSet: 'set' ;
KwStr: 'str' ;
KwFloat: 'float' ;
KwFile: 'file' ;

KwEval: 'eval' ;
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
