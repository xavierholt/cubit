#include "all.h"

#include "../error.h"

void InvalidLexlet::lex(Lexer& lexer) const {
  throw LexError(lexer, "Invalid character in input: " + LexError::charinfo(lexer.peek()));
}
