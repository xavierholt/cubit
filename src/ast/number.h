#ifndef CUBIT_AST_NUMBER_H
#define CUBIT_AST_NUMBER_H

#include "node.h"

namespace AST
{
  class Number: public Node {
  protected:
    long long int mValue;
  public:
    Number(const Lexer& lexer, const std::string& text);

    void send(Visitor* visitor);
    const std::string& type() const;
    long long int value() const;
  };
}

#endif
