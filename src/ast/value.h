#ifndef CUBIT_AST_VALUE_H
#define CUBIT_AST_VALUE_H

#include "node.h"

namespace AST
{
  class Value: public Node {
  public:
    Value(const Lexer& lexer, const std::string& text);

    Node* led(Parser& parser, Node* lhs);
    Node* nud(Parser& parser);
  };
}

#endif
