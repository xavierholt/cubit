#include "string.h"

#include "../lex/error.h"

namespace AST
{
  String::String(const Lexer& lexer, const std::string& text): Node(lexer, text) {
    // All done.
  }

  AST::Node* String::led(Parser& parser, AST::Node* lhs) {
    throw ParseError(parser, "Unexpected value " + text());
  }

  AST::Node* String::nud(Parser& parser) {
    return this;
  }

  void String::send(AST::Visitor* visitor) {
    visitor->visit(this);
  }

  static std::string TYPE("String");
  const std::string& String::type() const {
    return TYPE;
  }
}
