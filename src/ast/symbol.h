#ifndef CUBIT_AST_SYMBOL_H
#define CUBIT_AST_SYMBOL_H

#include "node.h"

class Operator;

namespace AST
{
  class Symbol: public Node {
  public:
    Symbol(const Lexer& lexer, const std::string& text);

    Node* led(Parser& parser, Node* lhs);
    Node* nud(Parser& parser);

    void send(Visitor* visitor);

    const std::string& type() const;
  };
}

#endif
