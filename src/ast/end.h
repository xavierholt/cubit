#ifndef CUBIT_AST_ENDOFINPUT_H
#define CUBIT_AST_ENDOFINPUT_H

#include "node.h"

namespace AST
{
  class EndOfInput: public Node {
  public:
    EndOfInput(const Lexer& lexer);

    void send(Visitor*);

    const std::string& type() const;
  };
}

#endif
