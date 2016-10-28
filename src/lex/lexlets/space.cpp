#include "all.h"

#include "../error.h"

void SpaceLexlet::lex(Lexer& lexer) const {
  if(!lexer.take(' ')) {
    throw LexError::expected(lexer, "space");
  }

  char flags = lexer.flags() | Lexer::FSPACE;
  while(lexer.take(' '));
  lexer.clear(flags);
}
