#ifndef CUBIT_AST_VISITOR_H
#define CUBIT_AST_VISITOR_H

namespace AST
{
  class Binary;
  class Bracket;
  class Identifier;
  class Node;
  class Number;
  class Prefix;
  class String;
  class Symbol;

  class Visitor {
  public:
    virtual void knock(AST::Node* node);
    virtual void visit(AST::Node* node) = 0;

    virtual void visit(AST::Binary*     node);
    virtual void visit(AST::Bracket*    node);
    virtual void visit(AST::Identifier* node);
    virtual void visit(AST::Number*     node);
    virtual void visit(AST::Prefix*     node);
    virtual void visit(AST::String*     node);
    virtual void visit(AST::Symbol*     node);
  };
}

#endif
