#include "all.h"

#include "../error.h"

void CommentLexlet::lex(Lexer& lexer) const {
  if(!lexer.take('#')) {
    throw LexError::expected(lexer, "comment");
  }

  while(true) {
    if(lexer.peek('\n')) break;
    if(lexer.peek('\0')) break;
    lexer.take();
  }

  char flags = lexer.flags();
  lexer.clear(flags);
}
