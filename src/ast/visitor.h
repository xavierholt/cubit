#ifndef CUBIT_AST_VISITOR_H
#define CUBIT_AST_VISITOR_H

namespace AST
{
  class Binary;
  class Identifier;
  class LBracket;
  class Node;
  class String;
  class Unary;

  class Visitor {
  public:
    virtual void visit(AST::Node* node) = 0;

    virtual void visit(AST::Binary* node) {
      visit((AST::Node*) node);
    }

    virtual void visit(AST::Identifier* node) {
      visit((AST::Node*) node);
    }

    virtual void visit(AST::LBracket* node) {
      visit((AST::Node*) node);
    }

    virtual void visit(AST::String* node) {
      visit((AST::Node*) node);
    }

    virtual void visit(AST::Unary* node) {
      visit((AST::Node*) node);
    }
  };
}

#endif
