#include "number.h"

#include "../lex/error.h"

namespace AST
{
  Number::Number(const Lexer& lexer, const std::string& text): Node(lexer, text) {
    mValue = std::stoll(text.c_str());
  }

  AST::Node* Number::led(Parser& parser, AST::Node* lhs) {
    throw ParseError(parser, "Unexpected number " + text());
  }

  AST::Node* Number::nud(Parser& parser) {
    return this;
  }

  void Number::send(AST::Visitor* visitor) {
    visitor->visit(this);
  }

  static std::string TYPE("Number");
  const std::string& Number::type() const {
    return TYPE;
  }
}
