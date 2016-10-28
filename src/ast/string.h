#ifndef CUBIT_AST_STRING_H
#define CUBIT_AST_STRING_H

#include "node.h"

namespace AST
{
  class String: public Node {
  public:
    String(const Lexer& lexer);
    String(const Lexer& lexer, const std::string& text);

    void send(Visitor* visitor);

    const std::string& type() const;
  };
}

#endif
