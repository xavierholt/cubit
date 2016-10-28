#ifndef CUBIT_AST_UNARY_H
#define CUBIT_AST_UNARY_H

#include "node.h"

namespace AST
{
  class Unary: public Node {
  protected:
    int   mPrecedence;
    Node* mRHS;
  public:
    Unary(const Lexer& lexer, int precedence);
    Unary(const Lexer& lexer, const std::string& text, int precedence);

    Node* led(Parser& parser, Node* lhs);
    Node* nud(Parser& parser);
    int   rbp() const;
    Node* rhs() const;
    void  send(Visitor* visitor);

    const std::string& type() const;
  };
}

#endif
