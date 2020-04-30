# fling_hdl
This is a project to create a C++ like hardware description language.  It
is being written in C++ and uses ANTLR4 as the parser generator.

The end goal is for the compiler to spit out semi-readable Verilog 2001,
which is a very well-supported HDL for synthesis and simulation alike.

The language itself is inspired mainly by C++, Rust, VHDL 2008, and
SystemVerilog.  It is an object-oriented hardware description language with
a powerful compile-time language built in. 

Although not currently on the table, a simulator for the entire language
may be developed at some point.
