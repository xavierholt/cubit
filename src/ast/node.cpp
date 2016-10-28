#include "node.h"

#include "../lex/lexer.h"
#include "../lex/parser.h"

namespace AST
{
  Node::Node(const Lexer& lexer): Node(lexer, lexer.text()) {
    // All done.
  }

  Node::Node(const Lexer& lexer, const std::string& text): mText(text) {
    mRow = lexer.line();
    mCol = lexer.column();
  }

  int Node::col() const {
    return mCol;
  }

  int Node::lbp() const {
    return 0;
  }

  AST::Node* Node::led(Parser& parser, AST::Node* lhs) {
    return this;
  }

  AST::Node* Node::nud(Parser& parser) {
    return this;
  }

  int Node::rbp() const {
    return 0;
  }

  int Node::row() const {
    return mRow;
  }

  const std::string& Node::text() const {
    return mText;
  }
}
