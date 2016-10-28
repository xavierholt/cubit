#include "string.h"

namespace AST
{
  String::String(const Lexer& lexer): Node(lexer) {
    // All done.
  }

  String::String(const Lexer& lexer, const std::string& text): Node(lexer, text) {
    // All done.
  }

  void String::send(AST::Visitor* visitor) {
    visitor->visit(this);
  }

  static std::string TYPE("String");
  const std::string& String::type() const {
    return TYPE;
  }
}
