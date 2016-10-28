#include "rbracket.h"

#include <iostream>

namespace AST
{
  RBracket::RBracket(const Lexer& lexer): Node(lexer) {
    // All done.
  }

  RBracket::RBracket(const Lexer& lexer, const std::string& text): Node(lexer, text) {
    // All done.
  }

  AST::Node* RBracket::led(Parser& parser, AST::Node* lhs) {
    std::cout << "RBracket::led()\n";
    throw "Bad parser.";
  }

  AST::Node* RBracket::nud(Parser& parser) {
    std::cout << "RBracket::nud()\n";
    throw "Bad parser.";
  }

  void RBracket::send(Visitor*) {
    std::cout << "Unreachable!?\n";
    throw "Unreachable!?";
  }

  static std::string TYPE("RBracket");
  const std::string& RBracket::type() const {
    return TYPE;
  }
}
