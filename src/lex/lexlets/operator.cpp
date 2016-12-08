#include "all.h"

#include "../error.h"
#include "../../ast/binary.h"
#include "../../ast/prefix.h"
#include "../../ast/symbol.h"

AST::Node* oplex(Lexer& lexer) {
  switch(lexer.peek()) {
  case ')':
    lexer.take();
    return new AST::Symbol(lexer, ")");
  case '}':
    lexer.take();
    return new AST::Symbol(lexer, "}");
  case ']':
    lexer.take();
    return new AST::Symbol(lexer, "]");
  case ';':
    lexer.take();
    return new AST::Binary(lexer, ";", 20);
  case ',':
    lexer.take();
    return new AST::Binary(lexer, ",", 30);
  case '=':
    lexer.take();
    switch(lexer.peek()) {
    case '>':
      lexer.take();
      return new AST::Binary(lexer, "=>", 40, 39);
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "==", 110);
    default:
      return new AST::Binary(lexer, "=", 40, 39);
    }
  case '<':
    lexer.take();
    switch(lexer.peek()) {
    case '-':
      lexer.take();
      switch(lexer.peek()) {
      case '>':
        lexer.take();
        return new AST::Binary(lexer, "<->", 130);
      default:
        return new AST::Binary(lexer, "<-", 40, 39);
      }
    case '<':
      lexer.take();
      switch(lexer.peek()) {
      case '<':
        lexer.take();
        switch(lexer.peek()) {
        case '=':
          lexer.take();
          return new AST::Binary(lexer, "<<<=", 40, 39);
        default:
          return new AST::Binary(lexer, "<<<", 170);
        }
      case '=':
        lexer.take();
        return new AST::Binary(lexer, "<<=", 40, 39);
      default:
        return new AST::Binary(lexer, "<<", 170);
      }
    case '=':
      lexer.take();
      switch(lexer.peek()) {
      case '>':
        lexer.take();
        return new AST::Binary(lexer, "<=>", 120);
      default:
        return new AST::Binary(lexer, "<=", 110);
      }
    default:
      return new AST::Binary(lexer, "<", 110);
    }
  case ':':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, ":=", 40, 39);
    case ':':
      lexer.take();
      switch(lexer.peek()) {
      case ' ':
      case '\n':
        return new AST::Binary(lexer, "::", 240);
      default:
        if(lexer.spaced())
          return new AST::Prefix(lexer, "::", 250);
        else
          return new AST::Binary(lexer, "::", 240);
      }
    default:
      return new AST::Binary(lexer, ":", 70);
    }
  case '|':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "|=", 40, 39);
    case '|':
      lexer.take();
      return new AST::Binary(lexer, "||", 80);
    default:
      return new AST::Binary(lexer, "|", 140);
    }
  case '^':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "^=", 40, 39);
    case '^':
      lexer.take();
      return new AST::Binary(lexer, "^^", 90);
    default:
      return new AST::Binary(lexer, "^", 150);
    }
  case '&':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "&=", 40, 39);
    case '&':
      lexer.take();
      return new AST::Binary(lexer, "&&", 100);
    case ' ':
    case '\n':
      return new AST::Binary(lexer, "&", 160);
    default:
      if(lexer.spaced())
        return new AST::Prefix(lexer, "&", 220);
      else
        return new AST::Binary(lexer, "&", 160);
    }
  case '>':
    lexer.take();
    switch(lexer.peek()) {
    case '>':
      lexer.take();
      switch(lexer.peek()) {
      case '>':
        lexer.take();
        switch(lexer.peek()) {
        case '=':
          lexer.take();
          return new AST::Binary(lexer, ">>>=", 40, 39);
        default:
          return new AST::Binary(lexer, ">>>", 170);
        }
      case '=':
        lexer.take();
        return new AST::Binary(lexer, ">>=", 40, 39);
      default:
        return new AST::Binary(lexer, ">>", 170);
      }
    case '=':
      lexer.take();
      return new AST::Binary(lexer, ">=", 110);
    default:
      return new AST::Binary(lexer, ">", 110);
    }
  case '-':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "-=", 40, 39);
    case '>':
      lexer.take();
      return new AST::Binary(lexer, "->", 60);
    case ' ':
    case '\n':
      return new AST::Binary(lexer, "-", 180);
    default:
      if(lexer.spaced())
        return new AST::Prefix(lexer, "-", 200);
      else
        return new AST::Binary(lexer, "-", 180);
    }
  case '+':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "+=", 40, 39);
    case ' ':
    case '\n':
      return new AST::Binary(lexer, "+", 180);
    default:
      if(lexer.spaced())
        return new AST::Prefix(lexer, "+", 200);
      else
        return new AST::Binary(lexer, "+", 180);
    }
  case '\\':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "\\=", 40, 39);
    default:
      return new AST::Binary(lexer, "\\", 190);
    }
  case '%':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "%=", 40, 39);
    case ' ':
    case '\n':
      return new AST::Binary(lexer, "%", 190);
    default:
      if(lexer.spaced())
        return new AST::Prefix(lexer, "%", 220);
      else
        return new AST::Binary(lexer, "%", 190);
    }
  case '/':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "/=", 40, 39);
    default:
      return new AST::Binary(lexer, "/", 190);
    }
  case '*':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "*=", 40, 39);
    case '*':
      lexer.take();
      switch(lexer.peek()) {
      case '=':
        lexer.take();
        return new AST::Binary(lexer, "**=", 40, 39);
      default:
        return new AST::Binary(lexer, "**", 210, 209);
      }
    default:
      return new AST::Binary(lexer, "*", 190);
    }
  case '~':
    lexer.take();
    switch(lexer.peek()) {
    case '>':
      lexer.take();
      return new AST::Binary(lexer, "~>", 50);
    default:
      return new AST::Prefix(lexer, "~", 200);
    }
  case '!':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "!=", 110);
    default:
      return new AST::Prefix(lexer, "!", 200);
    }
  case '?':
    lexer.take();
    return new AST::Prefix(lexer, "?", 220);
  case '.':
    lexer.take();
    return new AST::Binary(lexer, ".", 240);
  case '$':
    lexer.take();
    switch(lexer.peek()) {
    case ' ':
    case '\n':
      return new AST::Binary(lexer, "$", 240);
    default:
      if(lexer.spaced())
        return new AST::Prefix(lexer, "$", 250);
      else
        return new AST::Binary(lexer, "$", 240);
    }
  case '@':
    lexer.take();
    switch(lexer.peek()) {
    case ' ':
    case '\n':
      return new AST::Binary(lexer, "@", 240);
    default:
      if(lexer.spaced())
        return new AST::Prefix(lexer, "@", 250);
      else
        return new AST::Binary(lexer, "@", 240);
    }
  default:
    throw LexError::expected(lexer, "operator");
  }

}

void OperatorLexlet::lex(Lexer& lexer) const {
  AST::Node* node = oplex(lexer);
  // node->check_spacing(lexer);

  // if(lexer.valued() && node->arity() == 1) {
  //   // TODO:  Special case for parens?
  //   // TODO:  Fix these numbers.
  //   lexer << new LooseCall(lexer, "[call]", 90, 42);
  // }

  lexer << node;
  lexer.clear();
}
