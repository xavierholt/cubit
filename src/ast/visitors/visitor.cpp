#include "visitor.h"

#include "../node.h"

namespace AST
{
  void Visitor::knock(AST::Node* node) {
    if(node == nullptr) return;
    node->send(this);
  }

  void Visitor::visit(AST::Binary* node) {
    visit((AST::Node*) node);
  }

  void Visitor::visit(AST::Bracket* node) {
    visit((AST::Node*) node);
  }

  void Visitor::visit(AST::Identifier* node) {
    visit((AST::Node*) node);
  }

  void Visitor::visit(AST::Number* node) {
    visit((AST::Node*) node);
  }

  void Visitor::visit(AST::Prefix* node) {
    visit((AST::Node*) node);
  }

  void Visitor::visit(AST::String* node) {
    visit((AST::Node*) node);
  }

  void Visitor::visit(AST::Symbol* node) {
    visit((AST::Node*) node);
  }
}
