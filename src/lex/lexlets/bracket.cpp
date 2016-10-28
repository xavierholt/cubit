#include "all.h"

#include "../error.h"
#include "../../ast/rbracket.h"
#include "../../ast/lbracket.h"

void BracketLexlet::lex(Lexer& lexer) const {
  switch(lexer.take()) {
  case '(':
    lexer << new AST::LBracket(lexer, "(", ")");
    lexer.clear();
    break;
  case '{':
    lexer << new AST::LBracket(lexer, "{", "}");
    lexer.clear();
    break;
  case '[':
    lexer << new AST::LBracket(lexer, "[", "]");
    lexer.clear();
    break;
  case ']':
    lexer << new AST::RBracket(lexer);
    lexer.clear(Lexer::FVALUE);
    break;
  case '}':
    lexer << new AST::RBracket(lexer);
    lexer.clear(Lexer::FVALUE);
    break;
  case ')':
    lexer << new AST::RBracket(lexer);
    lexer.clear(Lexer::FVALUE);
    break;
  default:
    throw LexError::expected(lexer, "bracket");
  }
}
