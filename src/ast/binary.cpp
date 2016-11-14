#include "binary.h"

#include "../lex/error.h"
#include "../lex/lexer.h"
#include "../lex/parser.h"

namespace AST
{
  Binary::Binary(const Lexer& lexer, const std::string& text, int lbp):
    Binary(lexer, text, lbp, lbp) {}
  Binary::Binary(const Lexer& lexer, const std::string& text, int lbp, int rbp): Node(lexer, text) {
    mLHS  = nullptr;
    mRHS  = nullptr;
    mLBP  = lbp;
    mRBP  = rbp;
  }

  int Binary::lbp() const {
    return mLBP;
  }

  Node* Binary::led(Parser& parser, Node* lhs) {
    mLHS = lhs;
    mRHS = parser.parse(rbp());
    return this;
  }

  Node* Binary::lhs() const {
    return mLHS;
  }

  Node* Binary::nud(Parser& parser) {
    throw ParseError(parser, "Unexpected binary operator " + text());
  }

  int Binary::rbp() const {
    return mRBP;
  }

  Node* Binary::rhs() const {
    return mRHS;
  }

  void Binary::send(Visitor* visitor) {
    visitor->visit(this);
  }

  static const std::string BINARY("Binary");
  const std::string& Binary::type() const {
    return BINARY;
  }
}
