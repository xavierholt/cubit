#ifndef CUBIT_LEXLETS_H
#define CUBIT_LEXLETS_H

#include "../lexer.h"

class Lexlet {
  virtual void lex(Lexer& lexer) const = 0;
  friend class Lexer;
};

class BracketLexlet: public Lexlet {
  void lex(Lexer& lexer) const;
};

class CommentLexlet: public Lexlet {
  void lex(Lexer& lexer) const;
};

class IdentifierLexlet: public Lexlet {
  void lex(Lexer& lexer) const;
};

class InvalidLexlet: public Lexlet {
  void lex(Lexer& lexer) const;
};

class NewlineLexlet: public Lexlet {
  void lex(Lexer& lexer) const;
};

class OperatorLexlet: public Lexlet {
  void       lex(Lexer& lexer) const;
  AST::Node* binary(Lexer& lexer) const;
  AST::Node* unary(Lexer& lexer) const;
};

class SpaceLexlet: public Lexlet {
  void lex(Lexer& lexer) const;
};

class StringLexlet: public Lexlet {
  void lex(Lexer& lexer) const;
};

#endif
