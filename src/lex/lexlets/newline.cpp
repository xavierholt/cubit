#include "all.h"

#include "../error.h"
#include "../ops/operator.h"
#include "../../ast/bracket.h"
#include "../../ast/operator.h"

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
    lexer << new AST::LBracket(lexer, "[>]", "[<]");
    lexer.indent(dent);
    lexer.clear();
  }
  else if(dent == lexer.dent()) {
    lexer << new AST::Binary(lexer, Operator::NEWLINE);
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
