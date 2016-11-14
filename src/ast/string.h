#ifndef CUBIT_AST_STRING_H
#define CUBIT_AST_STRING_H

#include "node.h"

namespace AST
{
  class String: public Node {
  public:
    String(const Lexer& lexer, const std::string& text);

    Node* led(Parser& parser, Node* lhs);
    Node* nud(Parser& parser);

    void send(Visitor* visitor);
    const std::string& type() const;
  };
}

#endif
