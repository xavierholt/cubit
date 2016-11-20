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
    return new AST::Binary(lexer, ";", 10);
  case ',':
    lexer.take();
    return new AST::Binary(lexer, ",", 20);
  case '=':
    lexer.take();
    switch(lexer.peek()) {
    case '>':
      lexer.take();
      return new AST::Binary(lexer, "=>", 30, 29);
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "==", 100);
    default:
      return new AST::Binary(lexer, "=", 30, 29);
    }
  case '<':
    lexer.take();
    switch(lexer.peek()) {
    case '-':
      lexer.take();
      switch(lexer.peek()) {
      case '>':
        lexer.take();
        return new AST::Binary(lexer, "<->", 120);
      default:
        return new AST::Binary(lexer, "<-", 30, 29);
      }
    case '<':
      lexer.take();
      switch(lexer.peek()) {
      case '<':
        lexer.take();
        switch(lexer.peek()) {
        case '=':
          lexer.take();
          return new AST::Binary(lexer, "<<<=", 30, 29);
        default:
          return new AST::Binary(lexer, "<<<", 160);
        }
      case '=':
        lexer.take();
        return new AST::Binary(lexer, "<<=", 30, 29);
      default:
        return new AST::Binary(lexer, "<<", 160);
      }
    case '=':
      lexer.take();
      switch(lexer.peek()) {
      case '>':
        lexer.take();
        return new AST::Binary(lexer, "<=>", 110);
      default:
        return new AST::Binary(lexer, "<=", 100);
      }
    default:
      return new AST::Binary(lexer, "<", 100);
    }
  case ':':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, ":=", 30, 29);
    case ':':
      lexer.take();
      switch(lexer.peek()) {
      case ' ':
      case '\n':
        return new AST::Binary(lexer, "::", 230);
      default:
        if(lexer.spaced())
          return new AST::Prefix(lexer, "::", 240);
        else
          return new AST::Binary(lexer, "::", 230);
      }
    default:
      return new AST::Binary(lexer, ":", 60);
    }
  case '|':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "|=", 30, 29);
    case '|':
      lexer.take();
      return new AST::Binary(lexer, "||", 70);
    default:
      return new AST::Binary(lexer, "|", 130);
    }
  case '^':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "^=", 30, 29);
    case '^':
      lexer.take();
      return new AST::Binary(lexer, "^^", 80);
    default:
      return new AST::Binary(lexer, "^", 140);
    }
  case '&':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "&=", 30, 29);
    case '&':
      lexer.take();
      return new AST::Binary(lexer, "&&", 90);
    case ' ':
    case '\n':
      return new AST::Binary(lexer, "&", 150);
    default:
      if(lexer.spaced())
        return new AST::Prefix(lexer, "&", 210);
      else
        return new AST::Binary(lexer, "&", 150);
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
          return new AST::Binary(lexer, ">>>=", 30, 29);
        default:
          return new AST::Binary(lexer, ">>>", 160);
        }
      case '=':
        lexer.take();
        return new AST::Binary(lexer, ">>=", 30, 29);
      default:
        return new AST::Binary(lexer, ">>", 160);
      }
    case '=':
      lexer.take();
      return new AST::Binary(lexer, ">=", 100);
    default:
      return new AST::Binary(lexer, ">", 100);
    }
  case '-':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "-=", 30, 29);
    case '>':
      lexer.take();
      return new AST::Binary(lexer, "->", 50);
    case ' ':
    case '\n':
      return new AST::Binary(lexer, "-", 170);
    default:
      if(lexer.spaced())
        return new AST::Prefix(lexer, "-", 190);
      else
        return new AST::Binary(lexer, "-", 170);
    }
  case '+':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "+=", 30, 29);
    case ' ':
    case '\n':
      return new AST::Binary(lexer, "+", 170);
    default:
      if(lexer.spaced())
        return new AST::Prefix(lexer, "+", 190);
      else
        return new AST::Binary(lexer, "+", 170);
    }
  case '\\':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "\\=", 30, 29);
    default:
      return new AST::Binary(lexer, "\\", 180);
    }
  case '%':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "%=", 30, 29);
    case ' ':
    case '\n':
      return new AST::Binary(lexer, "%", 180);
    default:
      if(lexer.spaced())
        return new AST::Prefix(lexer, "%", 210);
      else
        return new AST::Binary(lexer, "%", 180);
    }
  case '/':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "/=", 30, 29);
    default:
      return new AST::Binary(lexer, "/", 180);
    }
  case '*':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "*=", 30, 29);
    case '*':
      lexer.take();
      switch(lexer.peek()) {
      case '=':
        lexer.take();
        return new AST::Binary(lexer, "**=", 30, 29);
      default:
        return new AST::Binary(lexer, "**", 200, 199);
      }
    default:
      return new AST::Binary(lexer, "*", 180);
    }
  case '~':
    lexer.take();
    switch(lexer.peek()) {
    case '>':
      lexer.take();
      return new AST::Binary(lexer, "~>", 40);
    default:
      return new AST::Prefix(lexer, "~", 190);
    }
  case '!':
    lexer.take();
    switch(lexer.peek()) {
    case '=':
      lexer.take();
      return new AST::Binary(lexer, "!=", 100);
    default:
      return new AST::Prefix(lexer, "!", 190);
    }
  case '?':
    lexer.take();
    return new AST::Prefix(lexer, "?", 210);
  case '.':
    lexer.take();
    return new AST::Binary(lexer, ".", 230);
  case '$':
    lexer.take();
    switch(lexer.peek()) {
    case ' ':
    case '\n':
      return new AST::Binary(lexer, "$", 230);
    default:
      if(lexer.spaced())
        return new AST::Prefix(lexer, "$", 240);
      else
        return new AST::Binary(lexer, "$", 230);
    }
  case '@':
    lexer.take();
    switch(lexer.peek()) {
    case ' ':
    case '\n':
      return new AST::Binary(lexer, "@", 230);
    default:
      if(lexer.spaced())
        return new AST::Prefix(lexer, "@", 240);
      else
        return new AST::Binary(lexer, "@", 230);
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
