#ifndef CUBIT_AST_RBRACKET_h
#define CUBIT_AST_RBRACKET_h

#include "node.h"

namespace AST
{
  class RBracket: public Node {
  public:
    RBracket(const Lexer& lexer);
    RBracket(const Lexer& lexer, const std::string& text);

    Node* led(Parser& parser, Node* lhs);
    Node* nud(Parser& parser);
    void  send(Visitor*);

    const std::string& type() const;
  };
}

#endif
