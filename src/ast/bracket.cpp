#include "bracket.h"

#include "../lex/error.h"
#include "../lex/parser.h"

#include <iostream>

namespace AST
{
  // Left brackets:
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
      throw ParseError::expected(parser, mOther);
    }
  }

  static std::string LBRACKET("LBracket");
  const std::string& LBracket::type() const {
    return LBRACKET;
  }


  // Right brackets:
  RBracket::RBracket(const Lexer& lexer, const std::string& text): Node(lexer, text) {
    // All done.
  }

  AST::Node* RBracket::led(Parser& parser, AST::Node* lhs) {
    throw ParseError(parser, "Unexpected " + text());
  }

  AST::Node* RBracket::nud(Parser& parser) {
    throw ParseError(parser, "Unexpected " + text());
  }

  void RBracket::send(Visitor*) {
    std::cout << "Unreachable!?\n";
    throw "Unreachable!?";
  }

  static std::string RBRACKET("RBracket");
  const std::string& RBracket::type() const {
    return RBRACKET;
  }
}
