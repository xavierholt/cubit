#include "prefix.h"

#include "../lex/error.h"
#include "../lex/lexer.h"
#include "../lex/parser.h"

namespace AST
{
  Prefix::Prefix(const Lexer& lexer, const std::string& text, int lbp): Node(lexer, text) {
    mRHS = nullptr;
    mLBP = lbp;
  }

  int Prefix::lbp() const {
    return mLBP;
  }

  Node* Prefix::led(Parser& parser, Node* lhs) {
    throw ParseError(parser, "Unexpected prefix operator " + text());
  }

  Node* Prefix::nud(Parser& parser) {
    mRHS = parser.parse(rbp());
    return this;
  }

  int Prefix::rbp() const {
    return mLBP;
  }

  Node* Prefix::rhs() const {
    return mRHS;
  }

  void Prefix::send(Visitor* visitor) {
    visitor->visit(this);
  }

  static const std::string PREFIX("Prefix");
  const std::string& Prefix::type() const {
    return PREFIX;
  }
}
