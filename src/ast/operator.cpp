#include "operator.h"

#include "../lex/lexer.h"
#include "../lex/ops/operator.h"
#include "../lex/parser.h"

#include <iostream>

namespace AST
{
  // Generic operators:
  Operator::Operator(const Lexer& lexer, const ::Operator* o): Node(lexer, o->text()) {
    mOperator = o;
  }

  int Operator::lbp() const {
    return mOperator->lbp();
  }

  int Operator::rbp() const {
    return mOperator->rbp();
  }

  const std::string& Operator::text() const {
    return mOperator->text();
  }


  // Binary operators:
  Binary::Binary(const Lexer& lexer, const ::Operator* o): Operator(lexer, o) {
    mLHS = nullptr;
    mRHS = nullptr;
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
    // if(mText == "\n") {
    //   return parser.parse(rbp());
    // }

    std::cout << "Called nud() for binary operator " << text() << "!\n";
    throw "nope";
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


  // Prefix operators:
  Prefix::Prefix(const Lexer& lexer, const ::Operator* o): Operator(lexer, o) {
    mRHS = nullptr;
  }

  Node* Prefix::led(Parser& parser, Node* lhs) {
    std::cout << "Called led() for prefix operator " << text() << "!\n";
    throw "nope";
  }

  Node* Prefix::nud(Parser& parser) {
    mRHS = parser.parse(rbp());
    return this;
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