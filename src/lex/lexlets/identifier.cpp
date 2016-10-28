#include "all.h"

#include "../error.h"
#include "../../ast/identifier.h"

void IdentifierLexlet::lex(Lexer& lexer) const {
  if(Lexer::ctype(lexer.peek()) != Lexer::IDENTIFIER) {
    throw LexError::expected(lexer, "identifier");
  }

  while(Lexer::ctype(lexer.peek()) == Lexer::IDENTIFIER) {
    lexer.take();
  }

  lexer.take('?') || lexer.take('!');
  lexer << new AST::Identifier(lexer);
  lexer.clear(Lexer::FVALUE);
}
