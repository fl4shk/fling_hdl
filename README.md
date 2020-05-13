# fling_hdl
This is a project to create a C++ like hardware description language.  It
is being written in C++ and uses a hand-written recursive descent parser.
As such, the grammar for the language is LL(1).

The initial end goal is for the compiler to spit out semi-readable,
behavioral Verilog 2001.  This will most likely be used as the main way to
debug the compiler in general.  Eventually, support for spitting out some
of the open HDL IRs may be added, such as RTLIL.

The language itself is inspired mainly by C++, Rust, VHDL 2008, and
SystemVerilog.  Eventually it may be an object-oriented language should
that be deemed a good idea.

Although not currently on the table, a simulator for the entire language
may be developed at some point.
