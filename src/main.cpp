#include "compiler_class.hpp"
#include "compiler_error_listener_class.hpp"

int main(int argc, char** argv)
{
	std::string from_stdin(get_stdin_as_str());

	antlr4::ANTLRInputStream input(from_stdin);
	FlingHdlGrammarLexer lexer(&input);
	antlr4::CommonTokenStream tokens(&lexer);
	tokens.fill();

	FlingHdlGrammarParser parser(&tokens);
	parser.removeErrorListeners();
	std::unique_ptr<fling_hdl::CompilerErrorListener>
		compiler_error_listener
		(new fling_hdl::CompilerErrorListener());
	parser.addErrorListener(compiler_error_listener.get());

	fling_hdl::Compiler visitor(parser);
	return visitor.run();
}
