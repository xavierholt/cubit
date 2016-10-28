#include "lbracket.h"

#include "../lex/parser.h"

#include <iostream>

namespace AST
{
  LBracket::LBracket(const Lexer& lexer, const std::string& text, const std::string& other): Node(lexer, text) {
    mOther = other;
  }

  int LBracket::lbp() const {
    return 1000;
  }

  AST::Node* LBracket::led(Parser& parser, AST::Node* lhs) {
    mLHS = lhs;
    mRHS = parser.parse(rbp());
    take(parser);
    return this;
  }

  AST::Node* LBracket::lhs() const {
    return mLHS;
  }

  AST::Node* LBracket::nud(Parser& parser) {
    mLHS = nullptr;
    mRHS = parser.parse(rbp());
    take(parser);
    return this;
  }

  AST::Node* LBracket::rhs() const {
    return mRHS;
  }

  void LBracket::send(Visitor* visitor) {
    visitor->visit(this);
  }

  void LBracket::take(Parser& parser) const {
    if(!parser.take(mOther)) {
      std::cout << "Unmatched bracket!\n";
      throw "Unmatched bracket!";
    }
  }

  static std::string TYPE("LBracket");
  const std::string& LBracket::type() const {
    return TYPE;
  }
}
