#ifndef CUBIT_AST_BRACKET_H
#define CUBIT_AST_BRACKET_H

#include "node.h"

namespace AST
{
  class Bracket: public Node {
  protected:
    Node*       mLHS;
    Node*       mRHS;
    std::string mOther;
  public:
    Bracket(const Lexer& lexer, const std::string& text, const std::string& other);

    int   lbp() const;
    Node* led(Parser& parser, Node* lhs);
    Node* lhs() const;
    Node* nud(Parser& parser);
    Node* rhs() const;
    void  send(Visitor* visitor);

    const std::string& type() const;

  protected:
    void take(Parser& parser) const;
  };
}

#endif
