#include "parser.h"

#include "error.h"
#include "lexer.h"
#include "../ast/node.h"

Parser::Parser(Tokens& tokens): mTokens(tokens) {
  tokens.push_back(nullptr);
  mCurrent = 0;
}

AST::Node* Parser::parse(int rbp, const char* eat) {
  AST::Node* node = take()->nud(*this);
  while(peek() && rbp < peek()->lbp()) {
    node = take()->led(*this, node);
  }

  if(eat != nullptr) {
    if(!take(eat)) throw ParseError::expected(*this, eat);
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
