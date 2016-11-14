#ifndef CUBIT_AST_BINARY_H
#define CUBIT_AST_BINARY_H

#include "node.h"

class Lexer;
class Parser;

namespace AST
{
  class Binary: public Node {
  protected:
    Node* mLHS;
    Node* mRHS;
    int   mLBP;
    int   mRBP;
  public:
    Binary(const Lexer& lexer, const std::string& text, int lbp);
    Binary(const Lexer& lexer, const std::string& text, int lbp, int rbp);

    int   lbp() const;
    Node* lhs() const;
    int   rbp() const;
    Node* rhs() const;

    Node* led(Parser& parser, Node* lhs);
    Node* nud(Parser& parser);

    void  send(Visitor* visitor);

    const std::string& text() const;
    const std::string& type() const;
  };
}

#endif
