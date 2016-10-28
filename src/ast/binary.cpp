#include "binary.h"

#include "../lex/lexer.h"
#include "../lex/parser.h"

namespace AST
{
   Binary::Binary(const Lexer& lexer, int p, bool a): Node(lexer) {
    mPrecedence    = p;
    mAssociativity = a;
  }

  Binary::Binary(const Lexer& lexer, const std::string& text, int p, bool a): Node(lexer, text) {
    mPrecedence    = p;
    mAssociativity = a;
  }

  int Binary::lbp() const {
    return mPrecedence;
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
    if(mText == "\n") {
      return parser.parse(rbp());
    }
    else {
      throw "But I'm a binary operator!";
    }
  }

  int Binary::rbp() const {
    return mPrecedence + mAssociativity;
  }

  Node* Binary::rhs() const {
    return mRHS;
  }

  void Binary::send(Visitor* visitor) {
    visitor->visit(this);
  }

  static std::string TYPE("Binary");
  const std::string& Binary::type() const {
    return TYPE;
  }
}
