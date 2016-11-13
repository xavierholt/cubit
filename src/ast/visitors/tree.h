#ifndef CUBIT_AST_TREEPRINTER_H
#define CUBIT_AST_TREEPRINTER_H

#include "../visitor.h"

namespace AST
{
  class TreePrinter: public AST::Visitor {
  protected:
    int mDepth;
  public:
    TreePrinter();

    void print(AST::Node* node, int depth);

    void visit(AST::Node*       node);
    void visit(AST::Binary*     node);
    void visit(AST::Identifier* node);
    void visit(AST::LBracket*   node);
    void visit(AST::Prefix*     node);
    void visit(AST::String*     node);
  };
}

#endif
