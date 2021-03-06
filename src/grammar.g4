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
			flingDeclParamSublist
			(PunctComma flingDeclParamSublist)*
		)?
	PunctCmpGt
	;

flingDeclParamSublist:
	flingIdentList PunctColon 
	(
		flingTypenm (PunctBlkAssign flingExprList)?
		| KwRange (PunctBlkAssign flingRangeList)?
		| KwType (PunctBlkAssign flingTypenmList)?
		| KwModule (PunctBlkAssign flingModnmList)?
		| (KwFunc | KwTask) (PunctBlkAssign flingSubprogIdentList)?
	)
	;

flingDeclArgList:
	PunctLparen
		(
			flingDeclArgSublist
			(PunctComma flingDeclArgSublist)*
		)?
	PunctRparen
	;

flingDeclArgSublist:
	flingIdentList PunctColon
		(
			KwInput
			| KwOutput
			| KwInout
			//| KwModport
			//| KwInterface
		)
		flingTypenm (PunctBlkAssign flingExprList)?
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
	KwModinst MiscIdent PunctColon flingModnm flingInstArgList
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
	// we'll save the ban on that for semantic analysis.
	| flingAnyBehavScopeItemStWithIdent
	| flingAnyBehavScopeItemStWithCat
	;

flingAnyBehavScopeItemStWithIdent:
	MiscIdent 
		(
			// behavioral assignment
			flingIdentExprSuffix? flingAnyBehavScopeItemAssignSuffix

			// function call
			| flingInstParamList? flingTypenmCstmChainItem*
				flingInstArgList
		)
		PunctSemicolon
	;

flingAnyBehavScopeItemStWithCat:
	flingAssignLhsCatExpr flingAnyBehavScopeItemAssignSuffix PunctSemicolon
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
	KwStruct (KwPacked KwSigned?)? MiscIdent flingDeclParamList?
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
	KwEnum MiscIdent (PunctColon flingTypenm)?
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
		PunctColon flingTypenm
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
	KwConst flingIdentList PunctColon flingTypenm
		PunctBlkAssign flingExprList PunctSemicolon
	;

flingDeclVarNoDefVal:
	KwVar flingIdentList PunctColon flingTypenm PunctSemicolon
	;

flingDeclVar:
	KwVar flingIdentList PunctColon flingTypenm
		(PunctBlkAssign flingExprList)? PunctSemicolon
	;

flingDeclWire:
	KwWire flingIdentList PunctColon flingTypenm
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
			flingTypenm PunctBlkAssign flingExprList
			| KwRange PunctBlkAssign flingRangeList
			| KwType PunctBlkAssign flingTypenmList
			| KwModule PunctBlkAssign flingModnmList
			| (KwFunc | KwTask) PunctBlkAssign flingSubprogIdentList
		)
		PunctSemicolon
	;
//--------

//--------
flingIdentList:
	MiscIdent (PunctComma MiscIdent)*
	;

flingSubprogIdentList:
	flingIdentExprStart (PunctComma flingIdentExprStart)*
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

flingTypenmList:
	flingTypenm (PunctComma flingTypenm)*
	;
flingModnmList:
	flingModnm (PunctComma flingModnm)*
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
	flingLitNumExpr

	| flingLitHighImpedExpr
	| flingLitUnknExpr
	| flingParenExpr

	| flingCallDollarFuncExpr

	// This includes calling functions.  The AST builder will need to
	// determine what kind of AST node this yields.
	| flingIdentExpr

	| flingCatExpr
	| flingReplExpr
	| flingSizedExpr
	;

flingLitNumExpr:
	LitDecNum
	| LitHexNum
	| LitOctNum
	| LitBinNum
	;

flingLitHighImpedExpr:
	KwHighImped (PunctLparen flingExpr PunctRparen)?
	;

flingLitUnknExpr:
	KwUnkn (PunctLparen flingExpr PunctRparen)?
	;

flingParenExpr:
	PunctLparen flingExpr PunctRparen
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
		(flingExpr | flingTypenm)

	| KwDollarPow PunctLparen flingExpr PunctComma flingExpr PunctRparen
	;

//flingCallSubprogExpr:
//	flingSubprogIdent flingInstArgList
//	;

//flingSubprogIdent:
//	flingIdentExprStart
//	;

flingAssignLhsIdentExpr:
	MiscIdent flingIdentExprSuffix?
	;
flingAssignLhsCatExpr:
	KwCat
		PunctLparen
			flingAssignLhsIdentExpr
			(PunctComma flingAssignLhsIdentExpr)*
		PunctRparen
	;
flingIdentExprSuffix:
	(
		// Access members or array elements
			(
				PunctMemberAccess MiscIdent
				| PunctLbracket flingExpr PunctRbracket
			)*

			// Access a slice or a single bit of a vector
			(
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
			)

		| // Access members or array elements
			(
				PunctMemberAccess MiscIdent
				| PunctLbracket flingExpr PunctRbracket
			)+
	)
	;

flingIdentExprStart:
	MiscIdent flingInstParamList?
		(PunctScopeAccess MiscIdent flingInstParamList)*
	;

flingIdentExpr:
	flingIdentExprStart
		// Call a subprogram, which may be located inside of a package or
		// inside of a type (via an `alias` in the latter's case).
		flingInstArgList?
		flingIdentExprSuffix?
	;



flingCatExpr:
	KwCat PunctLparen flingExprList PunctRparen
	;

flingReplExpr:
	KwRepl PunctLparen flingExpr PunctComma flingExpr PunctRparen
	;
flingSizedExpr:
	KwSized
		PunctLparen 
			flingLitNumExpr PunctComma flingExpr 
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
			// needed for a range that's from parameter list or is a local
			// alias) because it includes support for `alias`es contained
			// within custom types and packages.
			| MiscIdent (flingInstParamList?
				flingTypenmCstmChainItem*
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
flingTypenmCstmChainItem:
	PunctScopeAccess MiscIdent flingInstParamList?
	;
flingTypenm:
	(
		flingIdentExprStart
		| KwLogic (KwUnsigned | KwSigned)? 
			// Vector dimensions
			(PunctVecDimStart flingExprOrRange PunctRbracket)?
		| KwInteger
	)
		// Array dimensions
		(PunctLbracket flingExprOrRange PunctRbracket)*
	;

flingModnm:
	//flingScopedIdent
	flingIdentExprStart
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
KwPacked: 'packed' ;
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
