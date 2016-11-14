#include "value.h"

#include "../lex/error.h"
#include "../lex/parser.h"

namespace AST
{
  Value::Value(const Lexer& lexer, const std::string& text): Node(lexer, text) {
    // All done.
  }

  AST::Node* Value::led(Parser& parser, AST::Node* lhs) {
    throw ParseError(parser, "Unexpected value " + text());
  }

  AST::Node* Value::nud(Parser& parser) {
    return this;
  }
}
