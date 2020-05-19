//--------
flingProgram:
	flingDeclPackageItem*
	MiscEof
	;
//--------

//--------
flingDeclPackage:
	KwPackage MiscIdent
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
	KwImport flingImportItemList PunctSemicolon
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
		| KwRange (PunctBlkAssign flingRangeList)?
		| (KwType | KwModule) (PunctBlkAssign flingTypenmOrModnmList)?
		| (KwFunc | KwTask) (PunctBlkAssign flingSubprogIdentList)?
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
flingInstParamList:
	PunctCmpLt
		(
			flingInstParamListItem
			(PunctComma flingInstParamListItem)*
		)?
	PunctCmpGt
	;
flingInstParamListItem:
	flingInstParamListItemPos
	| flingInstParamListItemNamed
	;
flingInstParamListItemPos:
	// This *may* actually indicate that we are dealing with a type name,
	// module name, subprogram name, or range.
	flingExprOrRange
	;
flingInstParamListItemNamed:
	PunctMemberAccess MiscIdent (PunctMapTo flingInstParamListItemPos)?
	;


flingInstArgList:
	PunctLparen
		(
			flingInstArgListItem
			(PunctComma flingInstArgListItem)*
		)?
	PunctRparen
	;
flingInstArgListItem:
	flingInstArgListItemPos
	| flingInstArgListItemNamed
	;
flingInstArgListItemPos:
	flingExpr
	;
flingInstArgListItemNamed:
	PunctMemberAccess MiscIdent (PunctMapTo flingInstArgListItemPos)?
	;
//--------

//--------
flingDeclModule:
	KwModule MiscIdent
		flingDeclParamList?
		flingDeclArgList
		flingDeclModuleScope
	;

flingDeclModuleScope:
	PunctLbrace
		flingDeclModuleItem*
	PunctRbrace
	;

flingDeclModuleItem:
	flingModinst

	| flingImport

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
flingModinst:
	KwModinst MiscIdent PunctColon flingTypenmOrModnm flingInstArgList
		PunctSemicolon
	;
//--------

//--------
flingDeclModuleGen:
	flingDeclModuleGenIf
	| flingDeclModuleGenSwitchEtc
	| flingDeclModuleGenFor
	;

flingDeclModuleGenIf:
	KwGenIf flingExpr flingDeclModuleScope
	(KwGenElif flingExpr flingDeclModuleScope)*
	(KwGenElse flingDeclModuleScope)?
	;

flingDeclModuleGenSwitchEtc:
	(KwGenSwitch | KwGenSwitchz) flingExpr
	PunctLbrace
		(
			flingDeclModuleGenCase*
			flingDeclModuleGenDefault?
			| flingDeclModuleGenDefault
			flingDeclModuleGenCase*
		)?
	PunctRbrace
	;

flingDeclModuleGenCase:
	KwGenCase flingExprList flingDeclModuleScope
	;
flingDeclModuleGenDefault:
	KwGenDefault flingDeclModuleScope
	;

flingDeclModuleGenFor:
	KwGenFor
		(PunctLbracket MiscIdent PunctRbracket)?
		MiscIdent PunctColon flingRange
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
	(KwElif flingExpr flingDeclModuleBehavScope)*
	(KwElse flingDeclModuleBehavScope)?
	;

flingDeclModuleBehavScopeItemSwitchEtc:
	(KwSwitch | KwSwitchz) flingExpr
	PunctLbrace
		(
			flingDeclModuleBehavScopeItemCase*
			flingDeclModuleBehavScopeItemDefault?

			| flingDeclModuleBehavScopeItemDefault
			flingDeclModuleBehavScopeItemCase*
		)?
	PunctRbrace

flingDeclModuleBehavScopeItemCase:
	KwCase flingExprList flingDeclModuleBehavScope
	;
flingDeclModuleBehavScopeItemDefault:
	KwDefault flingDeclModuleBehavScope
	;

flingDeclModuleBehavScopeItemFor:
	KwFor MiscIdent PunctColon flingRange
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
	KwGenIf flingExpr flingDeclModuleBehavScope
	(KwGenElif flingExpr flingDeclModuleBehavScope)*
	(KwGenElse flingDeclModuleBehavScope)?
	;

flingDeclModuleBehavScopeItemGenSwitchEtc:
	(KwGenSwitch | KwGenSwitchz) flingExpr
	PunctLbrace
		(
			flingDeclModuleBehavScopeItemGenCase*
			flingDeclModuleBehavScopeItemGenDefault?
			| flingDeclModuleBehavScopeItemGenDefault
			flingDeclModuleBehavScopeItemGenCase*
		)?
	PunctRbrace
	;

flingDeclModuleBehavScopeItemGenCase:
	KwGenCase flingExprList flingDeclModuleBehavScope
	;
flingDeclModuleBehavScopeItemGenDefault:
	KwGenDefault flingDeclModuleBehavScope
	;

flingDeclModuleBehavScopeItemGenFor:
	KwGenFor
		(PunctLbracket MiscIdent PunctRbracket)?
		MiscIdent PunctColon flingRange
		flingDeclModuleBehavScope
	;
//--------

//--------
flingAnyBehavScopeItem:
	| flingDeclConst
	| flingDeclVar

	| flingDeclCompositeType
	| flingDeclEnum

	| flingDeclSubprog

	// Functions actually can't have non-blocking assignments in them, but
	// we'll save that for semantic analysis.
	| MiscIdent 
		(
			flingIdentExprSuffix flingAnyBehavScopeItemAssignSuffix
			| flingInstParamList? flingTypenmOrModnmCstmChainItem* 
				flingInstArgList PunctSemicolon
		)
	| flingAssignLhsCatExpr flingAnyBehavScopeItemAssignSuffix
	;

flingAnyBehavScopeItemAssignSuffix:
	// Functions actually can't have non-blocking assignments in them, but
	// we'll save that for semantic analysis.
	(PunctBlkAssign | PunctNonBlkAssign) flingExpr
		PunctSemicolon
	;
//--------

//--------
flingDeclCompositeType:
	flingDeclStruct
	//| flingDeclClass
	;
//--------

//--------
flingDeclStruct:
	KwStruct MiscIdent flingDeclParamList?
		flingDeclStructScope
	;

flingDeclStructScope:
	PunctLbrace
		flingDeclStructScopeItem*
	PunctRbrace
	;

flingDeclStructScopeItem:
	flingImport

	| flingDeclConst
	| flingDeclVarNoDefVal

	| flingDeclAlias

	| flingDeclCompositeType
	| flingDeclEnum

	| flingDeclStructScopeItemGen
	;
//--------

//--------
flingDeclStructScopeItemGen:
	flingDeclStructScopeItemGenIf
	| flingDeclStructScopeItemGenSwitchEtc
	| flingDeclStructScopeItemGenFor
	;

flingDeclStructScopeItemGenIf:
	KwGenIf flingExpr flingDeclStructScope
	(KwGenElif flingExpr flingDeclStructScope)*
	(KwGenElse flingDeclStructScope)?
	;

flingDeclStructScopeItemGenSwitchEtc:
	(KwGenSwitch | KwGenSwitchz) flingExpr
	PunctLbrace
		(
			flingDeclStructScopeItemGenCase*
			flingDeclStructScopeItemGenDefault?
			| flingDeclStructScopeItemGenDefault
			flingDeclStructScopeItemGenCase*
		)?
	PunctRbrace
	;

flingDeclStructScopeItemGenCase:
	KwGenCase flingExprList flingDeclStructScope
	;
flingDeclStructScopeItemGenDefault:
	KwGenDefault flingDeclStructScope
	;

flingDeclStructScopeItemGenFor:
	KwGenFor
		(PunctLbracket MiscIdent PunctRbracket)?
		MiscIdent PunctColon flingRange
		flingDeclStructScope
	;
//--------

//--------
flingDeclEnum:
	KwEnum MiscIdent (PunctColon flingTypenmOrModnm)?
	PunctLbrace
		(
			flingDeclEnumItem
			(PunctComma flingDeclEnumItem)*
		)?
	PunctRbrace
	;

flingDeclEnumItem:
	MiscIdent (PunctBlkAssign flingExpr)?
	;
//--------

//--------
flingDeclSubprog:
	(
		flingDeclFuncHeader
		| flingDeclTaskHeader
	)
		flingDeclSubprogScope
	;
//--------

//--------
flingDeclFuncHeader:
	KwFunc MiscIdent
		flingDeclParamList?
		flingDeclArgList
		PunctColon flingTypenmOrModnm
	;

flingDeclTaskHeader:
	KwTask MiscIdent
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
	(KwElif flingExpr flingDeclSubprogScope)*
	(KwElse flingDeclSubprogScope)?
	;

flingDeclSubprogScopeItemSwitchEtc:
	(KwSwitch | KwSwitchz) flingExpr
	PunctLbrace
		(
			flingDeclSubprogScopeItemCase*
			flingDeclSubprogScopeItemDefault?

			| flingDeclSubprogScopeItemDefault
			flingDeclSubprogScopeItemCase*
		)?
	PunctRbrace

flingDeclSubprogScopeItemCase:
	KwCase flingExprList flingDeclSubprogScope
	;
flingDeclSubprogScopeItemDefault:
	KwDefault flingDeclSubprogScope
	;

flingDeclSubprogScopeItemFor:
	KwFor MiscIdent PunctColon flingRange
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
	KwGenIf flingExpr flingDeclSubprogScope
	(KwGenElif flingExpr flingDeclSubprogScope)*
	(KwGenElse flingDeclSubprogScope)?
	;

flingDeclSubprogScopeItemGenSwitchEtc:
	(KwGenSwitch | KwGenSwitchz) flingExpr
	PunctLbrace
		(
			flingDeclSubprogScopeItemGenCase*
			flingDeclSubprogScopeItemGenDefault?
			| flingDeclSubprogScopeItemGenDefault
			flingDeclSubprogScopeItemGenCase*
		)?
	PunctRbrace
	;

flingDeclSubprogScopeItemGenCase:
	KwGenCase flingExprList flingDeclSubprogScope
	;
flingDeclSubprogScopeItemGenDefault:
	KwGenDefault flingDeclSubprogScope
	;

flingDeclSubprogScopeItemGenFor:
	KwGenFor
		(PunctLbracket MiscIdent PunctRbracket)?
		MiscIdent PunctColon flingRange
		flingDeclSubprogScope
	;
//--------

//--------
flingDeclConst:
	KwConst flingIdentList PunctColon flingTypenmOrModnm
		PunctBlkAssign flingExprList PunctSemicolon
	;

flingDeclVarNoDefVal:
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
	KwAssign (flingAssignLhsIdentExpr | flingAssignLhsCatExpr)
		PunctBlkAssign
		flingExpr PunctSemicolon
	;

flingDeclAlias:
	KwAlias flingIdentList PunctColon
		(
			flingTypenmOrModnm PunctBlkAssign flingExprList
			| KwRange PunctBlkAssign flingRangeList
			| (KwType | KwModule) PunctBlkAssign flingTypenmOrModnmList
			| (KwFunc | KwTask) PunctBlkAssign flingSubprogIdentList
		)
		PunctSemicolon
	;
//--------

//--------
flingScopedIdent:
	MiscIdent (PunctScopeAccess MiscIdent)*
	;

flingIdentList:
	MiscIdent (PunctComma MiscIdent)*
	;

flingSubprogIdentList:
	flingSubprogIdent (PunctComma flingSubprogIdent)*
	;

flingExprList:
	flingExpr (PunctComma flingExpr)*
	;

flingRangeList:
	flingRange (PunctComma flingRange)*
	;
//flingExprOrRangeList:
//	flingExprOrRange (PunctComma flingExprOrRange)*
//	;

flingTypenmOrModnmList:
	flingTypenmOrModnm (PunctComma flingTypenmOrModnm)*
	;

flingImportItem:
	//flingScopedIdent (PunctScopeAccess KwAll)?

	// This needs special handling.
	MiscIdent (PunctScopeAccess MiscIdent)* (PunctScopeAccess KwAll)?
	;
flingImportItemList:
	flingImportItem (PunctComma flingImportItemList)*
	;
//--------

//--------
flingExpr:
	flingMuxExpr 
	;

flingMuxExpr:
	KwMux
	PunctLparen 
		flingExpr PunctComma flingExpr PunctComma flingExpr
	PunctRparen
	| flingLogorExpr
	;

flingLogorExpr:
	flingLogandExpr (PunctLogor flingExpr)?
	;

flingLogandExpr:
	flingCmpEqEtcExpr (PunctLogand flingExpr)?
	;


flingCmpEqEtcExpr:
	flingCmpLtEtcExpr
		(
			(PunctCmpEq | PunctCmpNe | PunctCaseCmpEq | PunctCaseCmpNe)
			flingExpr
		)?
	;

flingCmpLtEtcExpr:
	flingPlusMinusExpr
		(
			(PunctCmpLt | PunctCmpGt | PunctCmpLe | PunctCmpGe)
			flingExpr
		)?
	;

flingPlusMinusExpr:
	flingMulDivModExpr
		(
			(PunctPlus | PunctMinus)
			flingExpr
		)?
	;

flingMulDivModExpr:
	flingBitorBitnorExpr
		(
			(PunctMul | PunctDiv | PunctMod)
			flingExpr
		)?
	;

flingBitorBitnorExpr:
	flingBitandBitnandExpr
		(
			(PunctBitor | PunctBitnor)
			flingExpr
		)?
	;

flingBitandBitnandExpr:
	flingBitxorBitxnorExpr
		(
			(PunctBitand | PunctBitnand)
			flingExpr
		)?
	;

flingBitxorBitxnorExpr:
	flingBitshiftExpr
		(
			(PunctBitxor | PunctBitxnor)
			flingExpr
		)?
	;

flingBitshiftExpr:
	flingUnaryExpr
		(
			(KwLsl | KwLsr | KwAsr)
			flingExpr
		)?
	;

flingUnaryExpr:
	(PunctPlus | PunctMinus
		| PunctBitnot | PunctLognot
		| PunctBitor | PunctBitnor
		| PunctBitand | PunctBitnand
		| PunctBitxor | PunctBitxnor)
		flingExpr

	| flingLowExpr
	;

flingLowExpr:
	LitDecNum
	| LitHexNum
	| LitOctNum
	| LitBinNum

	| KwHighImped (PunctLparen flingExpr PunctRparen)?
	| KwUnkn (PunctLparen flingExpr PunctRparen)?

	| PunctLparen flingExpr PunctRparen

	| flingCallDollarFuncExpr

	// This includes calling functions.  The AST builder will need to
	// determine what kind of AST node this yields.
	| flingIdentExpr

	| flingCatExpr
	| flingReplExpr
	| flingSizedExpr
	;

flingCallDollarFuncExpr:
	(
		KwDollarSize
		| KwDollarHigh
		| KwDollarLow

		| KwDollarUnsigned
		| KwDollarSigned

		| KwDollarIsUnsigned
		| KwDollarIsSigned
	)
		(flingExpr | flingTypenmOrModnm)

	| KwDollarPow PunctLparen flingExpr PunctComma flingExpr PunctRparen
	;

//flingCallSubprogExpr:
//	flingSubprogIdent flingInstArgList
//	;

flingSubprogIdent:
	flingIdentExprStart flingTypenmOrModnmCstmChainItem*
		flingInstParamList?
	;

flingAssignLhsIdentExpr:
	MiscIdent flingIdentExprSuffix
	;
flingAssignLhsCatExpr:
	KwCat
		PunctLparen
			flingAssignLhsIdentExpr
			(PunctComma flingAssignLhsIdentExpr)*
		PunctRparen
	;
flingIdentExprSuffix:
	// Access members or array elements
	(
		PunctMemberAccess MiscIdent
		| PunctLbracket flingExpr PunctRbracket
	)*

	// Access a slice or a single bit of a vector
	(
		// This is used here to keep the grammar LL(1).
		PunctVecDimStart
			(
				flingExpr
					(
						// Indexed part select or a single bit
						(
							(PunctPlusColon | PunctMinusColon)
							flingExpr
						)
						| flingSimpleRangeSuffix
					)?

				| flingNonSimpleRange
			)
		PunctRbracket
	)?
	;

flingIdentExprStart:
	MiscIdent flingInstParamList?
	;

flingIdentExpr:
	MiscIdent flingInstParamList?
		flingTypenmOrModnmCstmChainItem*
		// Call a subprogram, which may be located inside of a package or
		// inside of a type (via an `alias` in the latter's case).
		flingInstArgList?
		flingIdentExprSuffix
	;



// Semantic analysis will need to determine whether or not this is a valid
// LHS for an assignment.
flingCatExpr:
	KwCat PunctLparen flingExprList PunctRparen
	;

flingReplExpr:
	KwRepl PunctLparen flingExpr PunctComma flingExpr PunctRparen
	;
flingSizedExpr:
	KwSized
		PunctLparen 
			(
				LitDecNum
				| LitHexNum
				| LitOctNum
				| LitBinNum
			)
			PunctComma flingExpr 
		PunctRparen
	;
//--------

//--------
flingRange:
	flingNonSimpleRange
	| flingExpr flingSimpleRangeSuffix
	;

flingNonSimpleRange:
	KwDollarRange flingExpr
	| KwRange 
		(
			PunctLparen flingExpr (PunctComma flingExpr)? PunctRparen

			// This is more complex than just a `MiscIdent` (all that's
			// needed for a parameter list) because it includes support for
			// `alias`es contained within custom types and packages.
			| MiscIdent (flingInstParamList?
				flingTypenmOrModnmCstmChainItem*
				PunctScopeAccess MiscIdent)?
		)
	;

flingSimpleRangeSuffix:
	PunctRangeSeparator flingExpr
	;

flingExprOrRange:
	flingExpr flingSimpleRangeSuffix?
	| flingNonSimpleRange
	;
//--------

//--------
flingTypenmOrModnmCstmChainItem:
	PunctScopeAccess flingIdentExprStart
	;
flingTypenmOrModnm:
	(
		flingIdentExprStart
			flingTypenmOrModnmCstmChainItem*
		| (KwUnsigned | KwSigned)? KwLogic 
			// Vector dimensions
			(PunctVecDimStart flingExprOrRange PunctRbracket)?
		| KwInteger
	)
		// Array dimensions
		(PunctLbracket flingExprOrRange PunctRbracket)*
	;
//--------

// Lexer rules
//--------
LexWhitespace: (' ' | '\t' | '\r' | '\n') -> skip ;

LexLineComment: ('//' (~'\n')+) -> skip ;
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
PunctLogor: '||' ;
PunctLogand: '&&' ;

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

PunctBitor: '|' ;
PunctBitnor: '~|' ;

PunctBitand: '&' ;
PunctBitnand: '~&' ;

PunctBitxor: '^' ;
PunctBitxnor: '^~' | '~^' ;

KwLsl: 'lsl' ;
KwLsr: 'lsr' ;
KwAsr: 'asr' ;

PunctBitnot: '~' ;
PunctLognot: '!' ;
//--------

//--------
PunctMapTo: '=>' ;
//--------

//--------
// The hash character looks like something has been sliced.
PunctVecDimStart: '#[' ;
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
KwModinst: 'modinst' ;

KwType: 'type' ;

KwInput: 'input' ;
KwOutput: 'output' ;
KwInout: 'inout' ;

//KwInterface: 'interface' ;
//KwModport: 'modport' ;

KwFunc: 'func' ;
KwTask: 'task' ;
//KwProc: 'proc' ;

//KwParpk: 'parpk' ;
//KwUnparpk: 'unparpk' ;

KwGenIf: 'gen_if' ;
KwGenElif: 'gen_elif' ;
KwGenElse: 'gen_else' ;
KwGenSwitch: 'gen_switch' ;
KwGenSwitchz: 'gen_switchz' ;
KwGenCase: 'gen_case' ;
KwGenDefault: 'gen_default' ;
KwGenFor: 'gen_for' ;

KwIf: 'if' ;
KwElif: 'elif' ;
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
KwSized: 'sized' ;

KwHighImped: 'high_imped' ;
KwUnkn: 'unkn' ;

KwLogic: 'logic' ;
KwUnsigned: 'unsigned' ;
KwSigned: 'signed' ;

KwInteger: 'integer' ;

KwRange: 'range' ;

//KwTypeof: 'typeof' ;
//KwAuto: 'auto' ;

//KwSelfT: 'self_t' ;
//KwRetT: 'ret_t' ;
//--------

//--------
KwDollarSize: '$size' ;
KwDollarRange: '$range' ;
KwDollarHigh: '$high' ;
KwDollarLow: '$low' ;

//KwDollarHighel: '$highel' ;
//KwDollarLowel: '$lowel' ;

KwDollarUnsigned: '$unsigned' ;
KwDollarSigned: '$signed' ;

KwDollarIsUnsigned: '$is_unsigned' ;
KwDollarIsSigned: '$is_signed' ;
//KwDollarIsUnknown: '$is_unknown' ;

KwDollarPow: '$pow' ;
//--------

//--------
//KwAssert: 'assert' ;
//KwAssume: 'assume' ;
//KwCover: 'cover' ;
//KwProperty: 'property' ;
//
//KwDollarIsFormal: '$is_formal' ;
//
//KwDollarStable: '$stable' ;
//KwDollarPast: '$past' ;
//KwDollarRose: '$rose' ;
//KwDollarFell: '$fell' ;
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

//fragment FragBasicIdent: '_'* [A-Za-z] ('_'? [A-Za-z0-9])* '_'*  ;
fragment FragBasicIdent: [A-Za-z_] [A-Za-z_0-9]* ;
fragment FragRawIdent: 'r#' [A-Za-z_0-9]+ ;

MiscIdent: 
	FragBasicIdent | FragRawIdent ;

MiscEof: EOF ;
MiscOther: . ;
//--------
