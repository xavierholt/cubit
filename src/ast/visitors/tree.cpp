#include "tree.h"

#include "../identifier.h"
#include "../bracket.h"
#include "../node.h"
#include "../number.h"
#include "../operator.h"
#include "../string.h"

#include <iostream>

namespace AST
{
  TreePrinter::TreePrinter() {
    mDepth = 0;
  }

  void TreePrinter::print(AST::Node* node, int depth) {
    while(depth --> 0) std::cout << "  ";
    std::cout << node->text() << '\n';
  }

  void TreePrinter::visit(AST::Node* node) {
    if(node == nullptr) return;
    node->send(this);
  }

  void TreePrinter::visit(AST::Binary* node) {
    print(node, mDepth);

    mDepth += 1;
    visit(node->lhs());
    visit(node->rhs());
    mDepth -= 1;
  }

  void TreePrinter::visit(AST::Identifier* node) {
    print(node, mDepth);
  }

  void TreePrinter::visit(AST::LBracket* node) {
    print(node, mDepth);

    mDepth += 1;
    visit(node->lhs());
    visit(node->rhs());
    mDepth -= 1;
  }

  void TreePrinter::visit(AST::Number* node) {
    print(node, mDepth);
  }

  void TreePrinter::visit(AST::Prefix* node) {
    print(node, mDepth);

    mDepth += 1;
    visit(node->rhs());
    mDepth -= 1;
  }

  void TreePrinter::visit(AST::String* node) {
    print(node, mDepth);
  }
}
