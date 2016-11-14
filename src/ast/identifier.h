#ifndef CUBIT_AST_IDENTIFIER_H
#define CUBIT_AST_IDENTIFIER_H

#include "node.h"

namespace AST
{
  class Identifier: public Node {
  public:
    Identifier(const Lexer& lexer, const std::string& text);

    Node* led(Parser& parser, Node* lhs);
    Node* nud(Parser& parser);

    void send(Visitor* visitor);
    const std::string& type() const;
  };
}

#endif
