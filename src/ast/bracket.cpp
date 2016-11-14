#include "bracket.h"

#include "../lex/error.h"
#include "../lex/parser.h"

namespace AST
{
  Bracket::Bracket(const Lexer& lexer, const std::string& text, const std::string& other): Node(lexer, text) {
    mOther = other;
  }

  int Bracket::lbp() const {
    return 1000;
  }

  AST::Node* Bracket::led(Parser& parser, AST::Node* lhs) {
    mLHS = lhs;
    mRHS = parser.parse(rbp());
    take(parser);
    return this;
  }

  AST::Node* Bracket::lhs() const {
    return mLHS;
  }

  AST::Node* Bracket::nud(Parser& parser) {
    mLHS = nullptr;
    mRHS = parser.parse(rbp());
    take(parser);
    return this;
  }

  AST::Node* Bracket::rhs() const {
    return mRHS;
  }

  void Bracket::send(Visitor* visitor) {
    visitor->visit(this);
  }

  void Bracket::take(Parser& parser) const {
    if(!parser.take(mOther)) {
      throw ParseError::expected(parser, mOther);
    }
  }

  static std::string BRACKET("Bracket");
  const std::string& Bracket::type() const {
    return BRACKET;
  }
}
