#ifndef CUBIT_AST_OPERATOR_H
#define CUBIT_AST_OPERATOR_H

#include "node.h"

class Lexer;
class Operator;
class Parser;

namespace AST
{
  class Operator: public Node {
  protected:
    const ::Operator* mOperator;
  public:
    Operator(const Lexer& lexer, const ::Operator* o);

    int lbp() const;
    int rbp() const;

    const std::string& text() const;
  };

  class Binary: public Operator {
  protected:
    Node* mLHS;
    Node* mRHS;
  public:
    Binary(const Lexer& lexer, const ::Operator* o);

    Node* led(Parser& parser, Node* lhs);
    Node* lhs() const;
    Node* nud(Parser& parser);
    Node* rhs() const;
    void  send(Visitor* visitor);

    const std::string& type() const;
  };

  class Prefix: public Operator {
  protected:
    Node* mRHS;
  public:
    Prefix(const Lexer& lexer, const ::Operator* o);

    Node* led(Parser& parser, Node* lhs);
    Node* nud(Parser& parser);
    Node* rhs() const;
    void  send(Visitor* visitor);

    const std::string& type() const;
  };
}

#endif
