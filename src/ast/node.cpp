#include "node.h"

#include "../lex/lexer.h"

namespace AST
{
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
