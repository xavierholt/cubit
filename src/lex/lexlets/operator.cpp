#include "all.h"

#include "../error.h"

void OperatorLexlet::lex(Lexer& lexer) const {
  AST::Node* op;
  if(lexer.flags() & Lexer::FVALUE) {
    if((op = binary(lexer))) {
      lexer << op;
      lexer.clear();
      return;
    }

    /* tokens << new Call; <<*/
  }

  if((op = unary(lexer))) {
    lexer << op;
    lexer.clear();
    return;
  }

  throw LexError::expected(lexer, "operator");
}
