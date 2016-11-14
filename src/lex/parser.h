#ifndef CUBIT_PARSER_H
#define CUBIT_PARSER_H

#include <string>
#include <vector>

namespace AST {
  class Node;
}

class Parser {
protected:
  std::vector<AST::Node*>& mTokens;
  unsigned int mCurrent;
public:
  Parser(std::vector<AST::Node*>& tokens);

  AST::Node* parse(int rbp = 0, const char* eat = nullptr);
  AST::Node* peek() const;
  AST::Node* take();
  AST::Node* take(const std::string& text);
};

#endif
