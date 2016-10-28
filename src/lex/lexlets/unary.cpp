#include "all.h"
#include "../../ast/unary.h"

AST::Node* OperatorLexlet::unary(Lexer& lexer) const {
  switch(lexer.peek()) {
    case '@':
      if(lexer.take("@")) return new AST::Unary(lexer, "@", 1000);
      break;
    case '$':
      if(lexer.take("$")) return new AST::Unary(lexer, "$", 1000);
      break;
    case ':':
      if(lexer.take("::")) return new AST::Unary(lexer, "::", 1000);
      break;
    case '&':
      if(lexer.take("&")) return new AST::Unary(lexer, "&", 980);
      break;
    case '?':
      if(lexer.take("?")) return new AST::Unary(lexer, "?", 980);
      break;
    case '+':
      if(lexer.take("+")) return new AST::Unary(lexer, "+", 960);
      break;
    case '-':
      if(lexer.take("-")) return new AST::Unary(lexer, "-", 960);
      break;
    case '!':
      if(lexer.take("!")) return new AST::Unary(lexer, "!", 960);
      break;
    case '~':
      if(lexer.take("~")) return new AST::Unary(lexer, "~", 960);
      break;
  }

  return nullptr;
}
