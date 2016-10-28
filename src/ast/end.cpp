#include "end.h"

namespace AST
{
  EndOfInput::EndOfInput(const Lexer& lexer): Node(lexer, "[end]") {
    // All done.
  }

  void EndOfInput::send(Visitor*) {
    throw "Unreachable!?";
  }

  static std::string TYPE("End");
  const std::string& EndOfInput::type() const {
    return TYPE;
  }
}
