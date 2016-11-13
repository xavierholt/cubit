#ifndef CUBIT_AST_NODE_H
#define CUBIT_AST_NODE_H

#include <string>
#include <ostream>

#include "visitor.h"

class Lexer;
class Parser;

namespace AST
{
  class Node {
  protected:
    std::string mText;
    int mRow;
    int mCol;
  public:
    Node(const Lexer& lexer, const std::string& text);

    int row() const;
    int col() const;

    virtual int   lbp()   const;
    virtual Node* led(Parser& parser, Node* lhs);
    virtual Node* nud(Parser& parser);
    virtual int   rbp()   const;
    virtual void  send(Visitor* visitor) = 0;

    virtual const std::string& text() const;
    virtual const std::string& type() const = 0;

    friend std::ostream& operator << (std::ostream& o, const Node& node) {
      return o << node.type() << " (" << node.text() << ") at " << node.row() << ":" << node.col();
    }
  };
}

#endif
