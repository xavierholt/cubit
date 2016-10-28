#ifndef CUBIT_AST_BINARY_H
#define CUBIT_AST_BINARY_H

#include "node.h"

namespace AST
{
  class Binary: public Node {
  protected:
    int   mPrecedence;
    int   mAssociativity;
    Node* mLHS;
    Node* mRHS;
  public:
    Binary(const Lexer& lexer, int p, bool a = false);
    Binary(const Lexer& lexer, const std::string& text, int p, bool a = false);

    int   lbp() const;
    Node* led(Parser& parser, Node* lhs);
    Node* lhs() const;
    Node* nud(Parser& parser);
    int   rbp() const;
    Node* rhs() const;
    void  send(Visitor* visitor);

    const std::string& type() const;
  };
}

#endif
