//--------
flingProgram:
	flingDeclPackage
	| flingDeclModule
	| flingImport
	;
//--------

//--------
flingDeclPackage:
	KwPackage flingIdent
	PunctLbrace
		flingDeclPackageItem*
	PunctRbrace
	;

flingDeclPackageItem:
	flingImport
	| flingDeclConst

	| flingDeclAlias

	| flingDeclCompositeType
	| flingDeclEnum

	| flingDeclSubprog

	| flingDeclPackage

	| flingDeclModule
	;

flingImport:
	KwImport flingImportItemList ';'
	;
//--------

//--------
flingDeclParamList:
	PunctCmpLt
		(
			flingDeclParamListItem
			(PunctComma flingDeclParamListItem)*
		)?
	PunctCmpGt
	;

flingDeclParamListItem:
	flingIdentList PunctColon 
	(
		flingTypenmOrModnm (PunctBlkAssign flingExprList)?
		| (KwType | KwModule) (PunctBlkAssign flingTypenmOrModnmList)?
	)
	;

flingDeclArgList:
	PunctLparen
		(
			flingDeclArgListItem
			(PunctComma flingDeclArgListItem)*
		)?
	PunctRparen
	;

flingDeclArgListItem:
	flingIdentList PunctColon
		(
			KwInput
			| KwOutput
			| KwInout
			//| KwModport
			//| KwInterface
		) 
		flingTypenmOrModnm (PunctBlkAssign flingExprList)?
	;
//--------

//--------
flingDeclModule:
	KwModule flingIdent
		flingDeclParamList?
		flingDeclArgList
		flingDeclModuleScope
	;
//--------

//--------
flingDeclModuleScope:
	PunctLbrace
		flingDeclModuleItem*
	PunctRbrace
	;

flingDeclModuleItem:
	flingImport

	| flingDeclConst
	| flingDeclVar
	| flingDeclWire

	| flingWireAssign

	| flingDeclAlias

	| flingDeclCompositeType
	| flingDeclEnum

	| flingDeclSubprog

	| flingDeclModuleGen
	| flingDeclModuleBehav
	;
//--------

//--------
flingDeclModuleGen:
	flingDeclModuleGenIf
	| flingDeclModuleGenSwitchEtc
	| flingDeclModuleGenFor
	;

flingDeclModuleGenIf:
	KwGen KwIf flingExpr flingDeclModuleScope
	(KwElse KwGen KwIf flingExpr flingDeclModuleScope)*
	(KwElse KwGen flingDeclModuleScope)?
	;

flingDeclModuleGenSwitchEtc:
	KwGen (KwSwitch | KwSwitchz) flingExpr
	PunctLbrace
		(
			flingDeclModuleGenSwitchEtcCase*
			flingDeclModuleGenSwitchEtcDefault?
			| flingDeclModuleGenSwitchEtcDefault
			flingDeclModuleGenSwitchEtcCase*
		)?
	PunctRbrace
	;

flingDeclModuleGenSwitchEtcCase:
	KwCase flingExprList flingDeclModuleScope
	;
flingDeclModuleGenSwitchEtcDefault:
	KwDefault flingDeclModuleScope
	;

flingDeclModuleGenFor:
	KwGen
		PunctLbracket flingIdent PunctRbracket
		KwFor flingIdent PunctColon flingExpr
		flingDeclModuleScope
	;
//--------

//--------
flingDeclModuleBehav:
	flingDeclModuleBehavComb
	| flingDeclModuleBehavSeq
	;

flingDeclModuleBehavComb:
	KwComb flingDeclModuleBehavScope
	;
flingDeclModuleBehavSeq:
	KwSeq flingDeclModuleBehavSeqEdgeItem
		(PunctComma flingDeclModuleBehavSeqEdgeItem)*
		flingDeclModuleBehavScope
	;
flingDeclModuleBehavSeqEdgeItem:
	(KwPosedge | KwNegedge) flingExpr
	;

flingDeclModuleBehavScope:
	PunctLbrace
		flingDeclModuleBehavScopeItem*
	PunctRbrace
	;

flingDeclModuleBehavScopeItem:
	flingDeclModuleBehavScope

	| flingDeclModuleBehavScopeItemIf
	| flingDeclModuleBehavScopeItemSwitchEtc
	| flingDeclModuleBehavScopeItemFor
	| flingDeclModuleBehavScopeItemWhile

	| flingDeclModuleBehavScopeItemGen

	| flingAnyBehavScopeItem
	;

flingDeclModuleBehavScopeItemIf:
	KwIf flingExpr flingDeclModuleBehavScope
	(KwElse KwIf flingExpr flingDeclModuleBehavScope)*
	(KwElse flingDeclModuleBehavScope)?
	;

flingDeclModuleBehavScopeItemSwitchEtc:
	(KwSwitch | KwSwitchz) flingExpr
	PunctLbrace
		(
			flingDeclModuleBehavScopeItemSwitchEtcCase*
			flingDeclModuleBehavScopeItemSwitchEtcDefault?

			| flingDeclModuleBehavScopeItemSwitchEtcDefault
			flingDeclModuleBehavScopeItemSwitchEtcCase*
		)?
	PunctRbrace

flingDeclModuleBehavScopeItemSwitchEtcCase:
	KwCase flingExprList flingDeclModuleBehavScope
	;
flingDeclModuleBehavScopeItemSwitchEtcDefault:
	KwDefault flingDeclModuleBehavScope
	;

flingDeclModuleBehavScopeItemFor:
	KwFor flingIdent PunctColon flingExpr
		flingDeclModuleBehavScope
	;

flingDeclModuleBehavScopeItemWhile:
	KwWhile flingExpr flingDeclModuleBehavScope
	;
//--------

//--------
flingDeclModuleBehavScopeItemGen:
	flingDeclModuleBehavScopeItemGenIf
	| flingDeclModuleBehavScopeItemGenSwitchEtc
	| flingDeclModuleBehavScopeItemGenFor
	;

flingDeclModuleBehavScopeItemGenIf:
	KwGen KwIf flingExpr flingDeclModuleBehavScope
	(KwElse KwGen KwIf flingExpr flingDeclModuleBehavScope)*
	(KwElse KwGen flingDeclModuleBehavScope)?
	;

flingDeclModuleBehavScopeItemGenSwitchEtc:
	KwGen (KwSwitch | KwSwitchz) flingExpr
	PunctLbrace
		(
			flingDeclModuleBehavScopeItemGenSwitchEtcCase*
			flingDeclModuleBehavScopeItemGenSwitchEtcDefault?
			| flingDeclModuleBehavScopeItemGenSwitchEtcDefault
			flingDeclModuleBehavScopeItemGenSwitchEtcCase*
		)?
	PunctRbrace
	;

flingDeclModuleBehavScopeItemGenSwitchEtcCase:
	KwCase flingExprList flingDeclModuleBehavScope
	;
flingDeclModuleBehavScopeItemGenSwitchEtcDefault:
	KwDefault flingDeclModuleBehavScope
	;

flingDeclModuleBehavScopeItemGenFor:
	KwGen
		PunctLbracket flingIdent PunctRbracket
		KwFor flingIdent PunctColon flingExpr
		flingDeclModuleBehavScope
	;
//--------

//--------
flingAnyBehavScopeItem:
	flingAnyBehavScopeItemAssign

	| flingDeclConst
	| flingDeclVar

	| flingDeclCompositeType
	| flingDeclEnum

	| flingDeclSubprog

	| flingExprCallSubprog PunctSemicolon
	;

flingAnyBehavScopeItemAssign:
	// Functions actually can't have non-blocking assignments in them, but
	// we'll save that for semantic analysis.
	(flingIdentExpr | flingCatExpr)
		(PunctBlkAssign | PunctNonBlkAssign) flingExpr
		PunctSemicolon
	;
//--------

//--------
flingDeclCompositeType:
	flingDeclCompositeTypeStruct
	//| flingDeclCompositeTypeClass
	;
//--------

//--------
flingDeclCompositeTypeStruct:
	KwStruct flingIdent flingDeclParamList?

	PunctLbrace
		(
			flingDeclCompositeTypeStructItem
			(PunctComma flingDeclCompositeTypeStructItem)*
		)?
	PunctRbrace
	;

flingDeclCompositeTypeStructItem:
	flingImport

	| flingDeclConst
	| flingDeclVarNoInitVal

	| flingDeclAlias

	| flingDeclCompositeType
	| flingDeclEnum

	| flingCompositeTypeStructItemGen
	;
//--------

//--------
flingCompositeTypeStructItemGen:
	flingCompositeTypeStructItemGenIf
	| flingCompositeTypeStructItemGenSwitchEtc
	| flingCompositeTypeStructItemGenFor
	;

flingCompositeTypeStructItemGenIf:
	KwGen KwIf flingExpr flingDeclModuleScope
	(KwElse KwGen KwIf flingExpr flingDeclModuleScope)*
	(KwElse KwGen flingDeclModuleScope)?
	;

flingCompositeTypeStructItemGenSwitchEtc:
	KwGen (KwSwitch | KwSwitchz) flingExpr
	PunctLbrace
		(
			flingCompositeTypeStructItemGenSwitchEtcCase*
			flingCompositeTypeStructItemGenSwitchEtcDefault?
			| flingCompositeTypeStructItemGenSwitchEtcDefault
			flingCompositeTypeStructItemGenSwitchEtcCase*
		)?
	PunctRbrace
	;

flingCompositeTypeStructItemGenSwitchEtcCase:
	KwCase flingExprList flingDeclModuleScope
	;
flingCompositeTypeStructItemGenSwitchEtcDefault:
	KwDefault flingDeclModuleScope
	;

flingCompositeTypeStructItemGenFor:
	KwGen
		PunctLbracket flingIdent PunctRbracket
		KwFor flingIdent PunctColon flingExpr
		flingDeclModuleScope
	;
//--------

//--------
flingDeclEnum:
	KwEnum flingIdent (PunctColon flingTypenmOrModnm)?
	PunctLbrace
		(
			flingDeclEnumItem
			(PunctComma flingDeclEnumItem)*
		)?
	PunctRbrace
	;

flingDeclEnumItem:
	flingIdent (PunctBlkAssign flingExpr)?
	;
//--------

//--------
flingDeclSubprog:
	(
		flingDeclSubprogFuncHeader
		| flingDeclSubprogTaskHeader
	)
		flingDeclSubprogScope
	;
//--------

//--------
flingDeclSubprogFuncHeader:
	KwFunc flingIdent
		flingDeclParamList?
		flingDeclArgList
		PunctColon flingTypenmOrModnm
	;

flingDeclSubprogTaskHeader:
	KwTask flingIdent
		flingDeclParamList?
		flingDeclArgList
	;
//--------

//--------
flingDeclSubprogScope:
	PunctLbrace
		flingDeclSubprogScopeItem*
	PunctRbrace
	;

flingDeclSubprogScopeItem:
	flingDeclSubprogScope

	| flingDeclSubprogScopeItemIf
	| flingDeclSubprogScopeItemSwitchEtc
	| flingDeclSubprogScopeItemFor
	| flingDeclSubprogScopeItemWhile

	| flingDeclSubprogScopeItemGen

	// We need semantic analysis to determine whether or not this item is
	// a non-blocking assignment, which is banned inside of a function.
	| flingAnyBehavScopeItem

	;

flingDeclSubprogScopeItemIf:
	KwIf flingExpr flingDeclSubprogScope
	(KwElse KwIf flingExpr flingDeclSubprogScope)*
	(KwElse flingDeclSubprogScope)?
	;

flingDeclSubprogScopeItemSwitchEtc:
	(KwSwitch | KwSwitchz) flingExpr
	PunctLbrace
		(
			flingDeclSubprogScopeItemSwitchEtcCase*
			flingDeclSubprogScopeItemSwitchEtcDefault?

			| flingDeclSubprogScopeItemSwitchEtcDefault
			flingDeclSubprogScopeItemSwitchEtcCase*
		)?
	PunctRbrace

flingDeclSubprogScopeItemSwitchEtcCase:
	KwCase flingExprList flingDeclSubprogScope
	;
flingDeclSubprogScopeItemSwitchEtcDefault:
	KwDefault flingDeclSubprogScope
	;

flingDeclSubprogScopeItemFor:
	KwFor flingIdent PunctColon flingExpr
		flingDeclSubprogScope
	;

flingDeclSubprogScopeItemWhile:
	KwWhile flingExpr flingDeclSubprogScope
	;
//--------


//--------
flingDeclSubprogScopeItemGen:
	flingDeclSubprogScopeItemGenIf
	| flingDeclSubprogScopeItemGenSwitchEtc
	| flingDeclSubprogScopeItemGenFor
	;

flingDeclSubprogScopeItemGenIf:
	KwGen KwIf flingExpr flingDeclSubprogScope
	(KwElse KwGen KwIf flingExpr flingDeclSubprogScope)*
	(KwElse KwGen flingDeclSubprogScope)?
	;

flingDeclSubprogScopeItemGenSwitchEtc:
	KwGen (KwSwitch | KwSwitchz) flingExpr
	PunctLbrace
		(
			flingDeclSubprogScopeItemGenSwitchEtcCase*
			flingDeclSubprogScopeItemGenSwitchEtcDefault?
			| flingDeclSubprogScopeItemGenSwitchEtcDefault
			flingDeclSubprogScopeItemGenSwitchEtcCase*
		)?
	PunctRbrace
	;

flingDeclSubprogScopeItemGenSwitchEtcCase:
	KwCase flingExprList flingDeclSubprogScope
	;
flingDeclSubprogScopeItemGenSwitchEtcDefault:
	KwDefault flingDeclSubprogScope
	;

flingDeclSubprogScopeItemGenFor:
	KwGen
		PunctLbracket flingIdent PunctRbracket
		KwFor flingIdent PunctColon flingExpr
		flingDeclSubprogScope
	;
//--------

//--------
flingDeclConst:
	KwConst flingIdentList PunctColon flingTypenmOrModnm
		PunctBlkAssign flingExprList PunctSemicolon
	;

flingDeclVarNoInitVal:
	KwVar flingIdentList PunctColon flingTypenmOrModnm PunctSemicolon
	;

flingDeclVar:
	KwVar flingIdentList PunctColon flingTypenmOrModnm
		(PunctBlkAssign flingExprList)? PunctSemicolon
	;

flingDeclWire:
	KwWire flingIdentList PunctColon flingTypenmOrModnm
		(PunctBlkAssign flingExprList)? PunctSemicolon
	;

flingWireAssign:
	KwAssign (flingIdentExpr | flingCatExpr) PunctBlkAssign
		flingExpr PunctSemicolon
	;
//--------

//--------
flingIdent:
	MiscIdent
	;
flingScopedIdent:
	flingIdent (PunctScopeAccess flingIdent)*
	;

flingIdentList:
	flingIdent (PunctComma flingIdent)*
	;

flingExprList:
	flingExpr (PunctComma flingExpr)*
	;
flingTypenmOrModnmList:
	flingTypenmOrModnm (PunctComma flingTypenmOrModnm)*
	;

flingImportItem:
	flingScopedIdent (PunctScopeAccess KwAll)?
	;
flingImportItemList:
	flingImportItem (PunctComma flingImportItemList)*
	;
//--------

// Lexer rules
//--------
LexWhitespace: (' ' | '\t' | '\r' | '\n') -> skip ;

LexLineComment: ('//' ~('\n')+) -> skip ;
//--------

//--------
PunctRangeSeparator: '..' ;
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
	//| FragDecNum '.'
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
PunctLparen: '(' ;
PunctRparen: ')' ;
PunctLbracket: '[' ;
PunctRbracket: ']' ;
PunctLbrace: '{' ;
PunctRbrace: '}' ;
PunctSemicolon: ';' ;
PunctColon: ':' ;
PunctPlusColon: '+:' ;
PunctMinusColon: '-:' ;
PunctComma: ',' ;
//--------

//--------
KwPackage: 'package' ;

KwImport: 'import' ;
KwAll: 'all' ;

KwModule: 'module' ;

KwType: 'type' ;

KwInput: 'input' ;
KwOutput: 'output' ;
KwInout: 'inout' ;

KwFunc: 'func' ;
KwTask: 'task' ;
//KwProc: 'proc' ;

//KwInterface: 'interface' ;
//KwModport: 'modport' ;

//KwParpk: 'parpk' ;
//KwUnparpk: 'unparpk' ;

KwGen: 'gen' ;
KwIf: 'if' ;
KwElse: 'else' ;

KwSwitch: 'switch' ;
KwSwitchz: 'switchz' ;
KwCase: 'case' ;
KwDefault: 'default' ;

KwFor: 'for' ;
KwWhile: 'while' ;

//KwBreak: 'break' ;
//KwContinue: 'continue' ;
//KwReturn: 'return' ;


KwStruct: 'struct' ;
//KwPacked: 'packed' ;
KwEnum: 'enum' ;


KwConst: 'const' ;
KwVar: 'var' ;
KwWire: 'wire' ;

KwAssign: 'assign' ;

KwComb: 'comb' ;
KwSeq: 'seq' ;

KwPosedge: 'posedge' ;
KwNegedge: 'negedge' ;

KwAlias: 'alias' ;

KwMux: 'mux' ;
KwCat: 'cat' ;
KwRepl: 'repl' ;

//KwTypeof: 'typeof' ;
//KwAuto: 'auto' ;

//KwSelfT: 'self_t' ;
//KwRetT: 'ret_t' ;
//--------

//--------
//KwDollarSize: '$size' ;
////KwDollarRange: '$range' ;
//KwDollarHigh: '$high' ;
//KwDollarLow: '$low' ;
//
//KwDollarHighel: '$highel' ;
//KwDollarLowel: '$lowel' ;
//--------

//--------
//KwAssert: 'assert' ;
//KwAssume: 'assume' ;
//KwCover: 'cover' ;
//KwProperty: 'property' ;
//
//KwDollarIsformal: '$isformal' ;
//
//KwDollarStable: '$stable' ;
//KwDollarFell: '$fell' ;
//KwDollarRose: '$rose' ;
//KwDollarPast: '$past' ;
//--------


//--------
//// The non-post/pre underscore parts must start and end with an
//// alphanumeric character, and there must be at least two alphanumeric
//// characters.
//MiscReservedIdent:
//	'__' [A-Za-z] ([A-Za-z0-9_]* [A-Za-z0-9])? '__'
//	;
//MiscMacroOrDefineIdent:
//	'`' [A-Za-z_] [A-Za-z0-9_]*
//	;

fragment FragBasicIdent: '_'* [A-Za-z] ('_'? [A-Za-z0-9])* '_'*  ;
fragment FragRawIdent: 'r#' [A-Za-z_0-9]+ ;

MiscIdent: 
	FragBasicIdent | FragRawIdent ;
MiscOther: . ;
//--------
