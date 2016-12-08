#include "all.h"

#include "../error.h"
#include "../../ast/binary.h"
#include "../../ast/symbol.h"

void NewlineLexlet::lex(Lexer& lexer) const {
  if(!lexer.take('\n')) {
    throw LexError::expected(lexer, "newline");
  }

  int dent = 0;
  while(lexer.take(' ')) ++dent;

  int c = lexer.peek();
  if(c ==  '#') return;
  if(c == '\n') return;
  if(c ==  EOF) return;

  if(dent > lexer.dent()) {
    lexer << new AST::Binary(lexer, "[>]", 10);
    lexer.indent(dent);
    lexer.clear();
  }
  else if(dent == lexer.dent()) {
    lexer << new AST::Binary(lexer, "[ ]", 10);
    lexer.clear();
  }
  else {
    while(dent < lexer.dent()) {
      lexer << new AST::Symbol(lexer, "[<]");
      lexer.dedent();
    }

    if(dent != lexer.dent()) {
      throw LexError(lexer, "Unmatched indentation!");
    }

    lexer.clear(Lexer::FVALUE);
  }
}
