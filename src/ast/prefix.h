#ifndef CUBIT_AST_PREFIX_H
#define CUBIT_AST_PREFIX_H

#include "node.h"

class Lexer;
class Parser;

namespace AST
{
  class Prefix: public Node {
  protected:
    Node* mRHS;
    int   mLBP;
  public:
    Prefix(const Lexer& lexer, const std::string& text, int lbp);

    int   lbp() const;
    int   rbp() const;
    Node* rhs() const;

    Node* led(Parser& parser, Node* lhs);
    Node* nud(Parser& parser);

    void  send(Visitor* visitor);

    const std::string& type() const;
  };
}

#endif
