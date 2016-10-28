#include "all.h"
#include "../../ast/binary.h"

AST::Node* OperatorLexlet::binary(Lexer& lexer) const {
  switch(lexer.peek()) {
    case '@':
      if(lexer.take("@")) return new AST::Binary(lexer, "@", 990);
      break;
    case '$':
      if(lexer.take("$")) return new AST::Binary(lexer, "$", 990);
      break;
    case '.':
      if(lexer.take(".")) return new AST::Binary(lexer, ".", 990);
      break;
    case ':':
      if(lexer.take("::")) return new AST::Binary(lexer, "::", 990);
      if(lexer.take(":=")) return new AST::Binary(lexer, ":=", 800);
      if(lexer.take(":")) return new AST::Binary(lexer, ":", 830);
      break;
    case '*':
      if(lexer.take("**=")) return new AST::Binary(lexer, "**=", 800);
      if(lexer.take("**")) return new AST::Binary(lexer, "**", 970);
      if(lexer.take("*=")) return new AST::Binary(lexer, "*=", 800);
      if(lexer.take("*")) return new AST::Binary(lexer, "*", 950);
      break;
    case '/':
      if(lexer.take("/=")) return new AST::Binary(lexer, "/=", 800);
      if(lexer.take("/")) return new AST::Binary(lexer, "/", 950);
      break;
    case '%':
      if(lexer.take("%=")) return new AST::Binary(lexer, "%=", 800);
      if(lexer.take("%")) return new AST::Binary(lexer, "%", 950);
      break;
    case '\\':
      if(lexer.take("\\=")) return new AST::Binary(lexer, "\\=", 800);
      if(lexer.take("\\")) return new AST::Binary(lexer, "\\", 950);
      break;
    case '+':
      if(lexer.take("+=")) return new AST::Binary(lexer, "+=", 800);
      if(lexer.take("+")) return new AST::Binary(lexer, "+", 940);
      break;
    case '-':
      if(lexer.take("->")) return new AST::Binary(lexer, "->", 820);
      if(lexer.take("-=")) return new AST::Binary(lexer, "-=", 800);
      if(lexer.take("-")) return new AST::Binary(lexer, "-", 940);
      break;
    case '<':
      if(lexer.take("<<<=")) return new AST::Binary(lexer, "<<<=", 800);
      if(lexer.take("<<<")) return new AST::Binary(lexer, "<<<", 930);
      if(lexer.take("<->")) return new AST::Binary(lexer, "<->", 890);
      if(lexer.take("<=>")) return new AST::Binary(lexer, "<=>", 880);
      if(lexer.take("<<=")) return new AST::Binary(lexer, "<<=", 800);
      if(lexer.take("<<")) return new AST::Binary(lexer, "<<", 930);
      if(lexer.take("<=")) return new AST::Binary(lexer, "<=", 870);
      if(lexer.take("<")) return new AST::Binary(lexer, "<", 870);
      break;
    case '>':
      if(lexer.take(">>>=")) return new AST::Binary(lexer, ">>>=", 800);
      if(lexer.take(">>>")) return new AST::Binary(lexer, ">>>", 930);
      if(lexer.take(">>=")) return new AST::Binary(lexer, ">>=", 800);
      if(lexer.take(">>")) return new AST::Binary(lexer, ">>", 930);
      if(lexer.take(">=")) return new AST::Binary(lexer, ">=", 870);
      if(lexer.take(">")) return new AST::Binary(lexer, ">", 870);
      break;
    case '&':
      if(lexer.take("&&")) return new AST::Binary(lexer, "&&", 860);
      if(lexer.take("&=")) return new AST::Binary(lexer, "&=", 800);
      if(lexer.take("&")) return new AST::Binary(lexer, "&", 920);
      break;
    case '^':
      if(lexer.take("^^")) return new AST::Binary(lexer, "^^", 850);
      if(lexer.take("^=")) return new AST::Binary(lexer, "^=", 800);
      if(lexer.take("^")) return new AST::Binary(lexer, "^", 910);
      break;
    case '|':
      if(lexer.take("||")) return new AST::Binary(lexer, "||", 840);
      if(lexer.take("|=")) return new AST::Binary(lexer, "|=", 800);
      if(lexer.take("|")) return new AST::Binary(lexer, "|", 900);
      break;
    case '=':
      if(lexer.take("==")) return new AST::Binary(lexer, "==", 870);
      if(lexer.take("=>")) return new AST::Binary(lexer, "=>", 800);
      if(lexer.take("=")) return new AST::Binary(lexer, "=", 800);
      break;
    case '!':
      if(lexer.take("!=")) return new AST::Binary(lexer, "!=", 870);
      break;
    case '~':
      if(lexer.take("~>")) return new AST::Binary(lexer, "~>", 810);
      break;
    case ',':
      if(lexer.take(",")) return new AST::Binary(lexer, ",", 790);
      break;
    case ';':
      if(lexer.take(";")) return new AST::Binary(lexer, ";", 780);
      break;
    case '\n':
      if(lexer.take("\n")) return new AST::Binary(lexer, "\n", 770);
      break;
  }

  return nullptr;
}
