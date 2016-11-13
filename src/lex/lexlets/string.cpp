#include "all.h"

#include "../error.h"
#include "../../ast/string.h"

#include <sstream>

void StringLexlet::lex(Lexer& lexer) const {
  std::stringstream text;
  char initial = lexer.take();
  text << initial;

  while(true) {
    int c = lexer.take();
    if(c == initial) {
      text  << (char) c;
      lexer << new AST::String(lexer, text.str());
      lexer.clear(Lexer::FVALUE);
      return;
    }
    else if(c == '\\') {
      char next = lexer.take();
      switch(next) {
        case '0':  text << '\0'; break;
        case 'a':  text << '\a'; break;
        case 'b':  text << '\b'; break;
        case 'e':  text << '\e'; break;
        case 'f':  text << '\f'; break;
        case 'n':  text << '\n'; break;
        case 'r':  text << '\r'; break;
        case 't':  text << '\t'; break;
        case 'v':  text << '\v'; break;
        case '\\': text << '\\'; break;
        case '\'': text << '\''; break;
        case '"':  text << '\"'; break;
        default: throw LexError(lexer, "Unrecognized escape sequence!");
      }
    }
    else if(c == '\0') {
      throw LexError(lexer, "Unterminated string!");
    }
    else {
      text << (char) c;
    }
  }
}
