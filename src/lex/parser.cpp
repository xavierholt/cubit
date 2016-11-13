#include "parser.h"

#include "../ast/node.h"
#include "lexer.h"

Parser::Parser(Tokens& tokens): mTokens(tokens) {
  mCurrent = 0;
}

AST::Node* Parser::parse(int rbp) {
  AST::Node* node = take()->nud(*this);
  while(rbp < peek()->lbp()) {
    node = take()->led(*this, node);
  }

  return node;
}

AST::Node* Parser::peek() const {
  return mTokens[mCurrent];
}

AST::Node* Parser::take() {
  return mTokens[mCurrent++];
}

AST::Node* Parser::take(const std::string& text) {
  if(peek()->text() == text) return take();
  return nullptr;
}
