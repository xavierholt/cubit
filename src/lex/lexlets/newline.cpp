#include "all.h"

#include "../error.h"
#include "../../ast/binary.h"
#include "../../ast/lbracket.h"
#include "../../ast/rbracket.h"

void NewlineLexlet::lex(Lexer& lexer) const {
  if(!lexer.take('\n')) {
    throw LexError::expected(lexer, "newline");
  }

  int dent = 0;
  while(lexer.take(' ')) ++dent;
  if(lexer.peek('#' )) return;
  if(lexer.peek('\n')) return;
  if(lexer.peek('\0')) return;

  if(dent > lexer.dent()) {
    lexer << new AST::LBracket(lexer, "[>]", "[<]");
    lexer.indent(dent);
    lexer.clear();
  }
  else if(dent == lexer.dent()) {
    lexer << new AST::Binary(lexer, "[ ]", 55, false);
    lexer.clear();
  }
  else {
    while(dent < lexer.dent()) {
      lexer << new AST::RBracket(lexer, "[<]");
      lexer.dedent();
    }

    if(dent != lexer.dent()) {
      throw LexError(lexer, "Unmatched indentation!");
    }

    lexer.clear(Lexer::FVALUE);
  }
}
