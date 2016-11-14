#include "symbol.h"

#include "../lex/error.h"
#include "../lex/parser.h"

namespace AST
{
  Symbol::Symbol(const Lexer& lexer, const std::string& text): Node(lexer, text) {
    // All done.
  }

  AST::Node* Symbol::led(Parser& parser, AST::Node* lhs) {
    throw ParseError(parser, "Unexpected symbol " + text());
  }

  AST::Node* Symbol::nud(Parser& parser) {
    throw ParseError(parser, "Unexpected symbol " + text());
  }

  void Symbol::send(Visitor*) {
    throw "Unreachable!?";
  }

  static std::string SYMBOL("Symbol");
  const std::string& Symbol::type() const {
    return SYMBOL;
  }
}
