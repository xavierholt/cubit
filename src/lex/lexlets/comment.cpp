#include "all.h"

#include "../error.h"

void CommentLexlet::lex(Lexer& lexer) const {
  if(!lexer.take('#')) {
    throw LexError::expected(lexer, "comment");
  }

  while(true) {
    int c = lexer.peek();
    if(c == '\n') break;
    if(c ==  EOF) break;
    lexer.take();
  }

  char flags = lexer.flags();
  lexer.clear(flags);
}
