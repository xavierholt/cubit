#include "all.h"

#include "../error.h"
#include "../chars/all.h"
#include "../../ast/number.h"

#include <sstream>

void NumberLexlet::lex(Lexer& lexer) const {
  if(Char::type(lexer.peek()) != Char::NUMBER) {
    throw LexError::expected(lexer, "number");
  }

  std::stringstream text;
  for(int c = lexer.peek(); Char::flags(c); c = lexer.peek()) {
    if(c != '_') text << (char) lexer.take();
  }

  std::string   str  = text.str();
  unsigned char flag = Char::DEC;
  unsigned char mask = 0xff;
  unsigned int  offs = 0;

  if(str[0] == '0' && str.length() > 1) {
    if(!(Char::FLAGS[(int) str[1]] & Char::DEC)) {
      if(str.length() == 2) {
        throw LexError(lexer, "Unfinished prefix: " + str);
      }

      switch(str[1]) {
        case 'b': flag = Char::BIN; break;
        case 'o': flag = Char::OCT; break;
        case 'd': flag = Char::DEC; break;
        case 'x': flag = Char::HEX; break;
        default: throw LexError(lexer, "Invalid prefix: " + str.substr(0, 2));
      }

      offs = 2;
    }
  }

  while(offs < str.length()) {
    mask &= Char::FLAGS[(int) str[offs]];
    offs += 1;
  }

  if((mask & flag) == flag) {
    lexer << new AST::Number(lexer, str);
    lexer.clear(Lexer::FVALUE);
    return;
  }
  else {
    throw LexError(lexer, "Invalid number: " + str);
  }
}