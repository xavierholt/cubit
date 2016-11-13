#include "all.h"

#include "../error.h"
#include "../chars/all.h"
#include "../../ast/identifier.h"

#include <sstream>

void IdentifierLexlet::lex(Lexer& lexer) const {
  if(Char::type(lexer.peek()) != Char::IDENTIFIER) {
    throw LexError::expected(lexer, "identifier");
  }

  std::stringstream text;
  for(int c = lexer.peek(); Char::flags(c); c = lexer.peek()) {
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
