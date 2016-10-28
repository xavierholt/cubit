#include "unary.h"

#include "../lex/parser.h"

namespace AST
{
  Unary::Unary(const Lexer& lexer, int precedence): Node(lexer) {
    mPrecedence = precedence;
  }

  Unary::Unary(const Lexer& lexer, const std::string& text, int precedence): Node(lexer, text) {
    mPrecedence = precedence;
  }

  AST::Node* Unary::led(Parser& parser, AST::Node* lhs) {
    throw "But I'm a unary operator!";
  }

  AST::Node* Unary::nud(Parser& parser) {
    mRHS = parser.parse(rbp());
    return this;
  }

  int Unary::rbp() const {
    return mPrecedence;
  }

  AST::Node* Unary::rhs() const {
    return mRHS;
  }

  void Unary::send(AST::Visitor* visitor) {
    visitor->visit(this);
  }

  static std::string TYPE("Unary");
  const std::string& Unary::type() const {
    return TYPE;
  }
}
