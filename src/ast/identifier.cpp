#include "identifier.h"

namespace AST
{
  Identifier::Identifier(const Lexer& lexer, const std::string& text): Node(lexer, text) {
    // All done.
  }

  void Identifier::send(AST::Visitor* visitor) {
    visitor->visit(this);
  }

  static std::string TYPE("Identifier");
  const std::string& Identifier::type() const {
    return TYPE;
  }
}
