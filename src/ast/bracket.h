#ifndef CUBIT_AST_LBRACKET_h
#define CUBIT_AST_LBRACKET_h

#include "node.h"

namespace AST
{
  class LBracket: public Node {
  protected:
    Node*       mLHS;
    Node*       mRHS;
    std::string mOther;
  public:
    LBracket(const Lexer& lexer, const std::string& text, const std::string& other);

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

  class RBracket: public Node {
  public:
    RBracket(const Lexer& lexer, const std::string& text);

    Node* led(Parser& parser, Node* lhs);
    Node* nud(Parser& parser);
    void  send(Visitor*);

    const std::string& type() const;
  };
}

#endif
