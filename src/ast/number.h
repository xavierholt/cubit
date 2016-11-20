#ifndef CUBIT_AST_NUMBER_H
#define CUBIT_AST_NUMBER_H

#include "node.h"

namespace AST
{
  class Number: public Node {
  public:
    Number(const Lexer& lexer, const std::string& text);

    Node* led(Parser& parser, Node* lhs);
    Node* nud(Parser& parser);

    void send(Visitor* visitor);
    const std::string& type() const;
  };
}

#endif
