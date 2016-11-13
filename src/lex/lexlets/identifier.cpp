#include "all.h"

#include "../error.h"
#include "../../ast/identifier.h"

#include <sstream>

void IdentifierLexlet::lex(Lexer& lexer) const {
  if(Lexer::ctype(lexer.peek()) != Lexer::IDENTIFIER) {
    throw LexError::expected(lexer, "identifier");
  }

  std::stringstream text;
  while(Lexer::ctype(lexer.peek()) == Lexer::IDENTIFIER) {
    text << (char) lexer.take();
  }

  if(lexer.take('?')) {
    text << '?';
  }
  else if(lexer.take('!')) {
    text << '!';
  }
  else if(lexer.take('=')) {
    if(lexer.peek(' ')) {
      text << '=';
    }
    else {
      lexer.undo();
    }
  }

  lexer << new AST::Identifier(lexer, text.str());
  lexer.clear(Lexer::FVALUE);
}
