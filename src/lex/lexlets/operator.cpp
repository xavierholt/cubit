#include "all.h"

#include "../error.h"
#include "../../ast/operator.h"
#include "../ops/operator.h"
#include "../ops/trie.h"

void OperatorLexlet::lex(Lexer& lexer) const {
  const Trie* node = Operator::get(lexer);
  const Operator* binary = node->binary();
  const Operator* prefix = node->prefix();

  if(lexer.flags() & Lexer::FVALUE) {
    if(binary == nullptr) {
      throw LexError::expected(lexer, "binary operator");
    }

    lexer << new AST::Binary(lexer, binary);;
    lexer.clear();
    return;
  }
  else {
    if(prefix == nullptr) {
      throw LexError::expected(lexer, "prefix operator");
    }

    lexer << new AST::Prefix(lexer, prefix);
    lexer.clear();
    return;
  }
}
