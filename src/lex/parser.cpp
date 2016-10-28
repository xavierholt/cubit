#include "parser.h"

#include "../ast/node.h"
#include "lexer.h"

#include <iostream>

Parser::Parser(Tokens& tokens): mTokens(tokens) {
  mCurrent = 0;
}

AST::Node* Parser::parse(int rbp) {
  AST::Node* node = take();
  std::cout << node->text() << " -> nud()\n";
  node = node->nud(*this);
  while(rbp < peek()->lbp()) {
    std::cout << peek()->text() << " -> led(" << node->text() << ")\n";
    node = take()->led(*this, node);
  }

  return node;
}

AST::Node* Parser::peek() const {
  if(mCurrent < mTokens.size()) {
    return mTokens[mCurrent];
  }
  else {
    return nullptr;
  }
}

AST::Node* Parser::take() {
  AST::Node* node = peek();
  mCurrent += (node != nullptr);
  return node;
}

AST::Node* Parser::take(const std::string& text) {
  AST::Node* node = peek();
  if(node && node->text() == text) return take();
  return nullptr;
}
