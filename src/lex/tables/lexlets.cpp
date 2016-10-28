#include "../lexlets/all.h"

const Lexlet* Lexer::LEXLETS[8] = {
  new BracketLexlet,
  new CommentLexlet,
  new SpaceLexlet,
  new IdentifierLexlet,
  new NewlineLexlet,
  new OperatorLexlet,
  new StringLexlet,
  new InvalidLexlet
};
