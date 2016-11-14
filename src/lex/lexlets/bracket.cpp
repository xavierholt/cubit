#include "all.h"

#include "../error.h"
#include "../../ast/bracket.h"

void BracketLexlet::lex(Lexer& lexer) const {
  if(Char::type(lexer.peek()) != Char::BRACKET) {
    throw LexError::expected(lexer, "bracket");
  }

  switch(lexer.take()) {
    case '(': lexer << new AST::Bracket(lexer, "(", ")"); break;
    case '{': lexer << new AST::Bracket(lexer, "{", "}"); break;
    case '[': lexer << new AST::Bracket(lexer, "[", "]"); break;
  }

  lexer.clear();
}
