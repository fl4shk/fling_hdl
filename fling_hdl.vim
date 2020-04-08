" Vim syntax file
" Language: Fling HDL
" Maintainer: Andrew Clark (FL4SHK)
" Latest Revision: Apr 8, 2020

if exists("b:current_syntax")
    finish
endif

let b:current_syntax = "fling_hdl"


syn match fling_hdl_line_comment "//.*$" 

syn region  fling_hdl_literal_string     start=+L\="+ skip=+\\\\\|\\"+ end=+"+ contains=fling_hdl_special_char,@Spell extend

syn match   fling_hdl_char  "L\='[^\\]'"
syn match   fling_hdl_char  "L'[^']*'" contains=fling_hdl_special
syn match   fling_hdl_special_error   "L\='\\[^'\"?\\abfnrtv]'"
syn match   fling_hdl_special_char "L\='\\['\"?\\abfnrtv]'"
syn match   fling_hdl_special_char display "L\='\\\o\{1,3}'"
syn match   fling_hdl_special_char display "'\\x\x\{1,2}'"
syn match   fling_hdl_special_char display "L'\\x\x\+'"
syn match   fling_hdl_special    display contained "\\\(x\x\+\|\o\{1,3}\|.\|$\)"
syn match   fling_hdl_special    display contained "\\\(u\x\{4}\|U\x\{8}\)"

"syn region fling_hdl_attribute start=+#\[+ end=+\]+
"syn region fling_hdl_attribute start=+L\=#\[+ end=+\]#+


syn match fling_hdl_lit "\(\([0-9][0-9_]*\.\(\[0-9][0-9_]*\)\?\|\.[0-9][0-9_]*\)\([eE][+-]\?[0-9][0-9_]*\)\?\([fdlFDL]\?\)\?\)"

syn match fling_hdl_lit "\<\([0-9][0-9_]*\)\>"


"syn match fling_hdl_frag_float_frac "\(\zs?\.\zs\)\|\(\zs\)" contains=fling_hdl_lit_dec_num,fling_hdl_lit_dec_num,fling_hdl_lit_dec_num
"syn match fling_hdl_frag_float_exp_part "[eE][+-]?\zs" contains=fling_hdl_lit_dec_num
"syn match fling_hdl_frag_float_suffix "[fdlFDL]"
"syn match fling_hdl_lit_float_num "\(\zs\zs?\zs?\)\|\(\zs\zs\zs?\)" contains=fling_hdl_frag_float_frac,fling_hdl_frag_float_exp_part,fling_hdl_frag_float_suffix,fling_hdl_lit_dec_num,fling_hdl_frag_float_exp_part,fling_hdl_frag_float_suffix
"syn match fling_hdl_lit_float_num +\\zs?\.\\zs+ contains=fling_hdl_lit_dec_num,fling_hdl_lit_dec_num
"syn match fling_hdl_lit_float_num +\zs+ contains=fling_hdl_lit_dec_num


syn match fling_hdl_lit "\<\(0x[0-9a-fA-F][0-9a-fA-F_]*\)\>"
syn match fling_hdl_lit "\<\(0o[0-7][0-7_]*\)\>"
syn match fling_hdl_lit "\<\(0b[0-1][0-1_]*\)\>"

"--------
syn keyword fling_hdl_stmt lsl lsr asr
"--------

"--------
syn keyword fling_hdl_stmt if elif else mux
syn keyword fling_hdl_stmt switch switchz default
syn keyword fling_hdl_stmt for while
syn keyword fling_hdl_stmt break continue
"--------

"--------
syn keyword fling_hdl_stmt module package
syn keyword fling_hdl_stmt input output inout interface
syn keyword fling_hdl_stmt gen

syn keyword fling_hdl_stmt initial comb seq posedge negedge

syn keyword fling_hdl_stmt func task import all
"--------

"--------
syn keyword fling_hdl_type wire logic
syn keyword fling_hdl_stmt const
syn keyword fling_hdl_type unsigned signed integer size_t

syn keyword fling_hdl_type u8 i8 u16 i16 u32 i32 u64 i64 u128 i128
"--------

"--------
syn keyword fling_hdl_stmt defer return
syn keyword fling_hdl_type ret_t auto range
"--------

"--------
syn keyword fling_hdl_lit high_z unk_x
syn keyword fling_hdl_func sized cat repl
syn keyword fling_hdl_stmt as
"--------

"--------
syn keyword fling_hdl_func $size $range $high $low $firstel $lastel
syn keyword fling_hdl_func $signed $unsigned $pow $clog2
"syn keyword fling_hdl_func $display $monitor $finish $stop
"--------

"--------
syn keyword fling_hdl_stmt assert assume cover
"--------

"--------
syn keyword fling_hdl_type void type typeof
syn keyword fling_hdl_stmt alias
"--------

"--------
syn keyword fling_hdl_type enum class mixin
syn keyword fling_hdl_stmt packed extends

syn keyword fling_hdl_stmt virtual abstract
syn keyword fling_hdl_func $isvtype

syn keyword fling_hdl_stmt base static proc self
syn keyword fling_hdl_type self_t

syn keyword fling_hdl_stmt pub prot priv

syn keyword fling_hdl_type string float file
"--------


"--------
hi def link fling_hdl_line_comment Comment
hi def link fling_hdl_literal_string Number

hi def link fling_hdl_lit Number

hi def link fling_hdl_stmt Statement
hi def link fling_hdl_type Type
hi def link fling_hdl_func Function
"--------
