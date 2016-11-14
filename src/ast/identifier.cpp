#include "identifier.h"

#include "../lex/error.h"

namespace AST
{
  Identifier::Identifier(const Lexer& lexer, const std::string& text): Node(lexer, text) {
    // All done.
  }

  AST::Node* Identifier::led(Parser& parser, AST::Node* lhs) {
    throw ParseError(parser, "Unexpected identifier " + text());
  }

  AST::Node* Identifier::nud(Parser& parser) {
    return this;
  }

  void Identifier::send(AST::Visitor* visitor) {
    visitor->visit(this);
  }

  static std::string TYPE("Identifier");
  const std::string& Identifier::type() const {
    return TYPE;
  }
}
