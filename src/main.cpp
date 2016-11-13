#include "ast/node.h"
#include "ast/visitors/tree.h"
#include "lex/lexer.h"
#include "lex/parser.h"

#include <fstream>
#include <iomanip>
#include <iostream>

int main(int argc, char* argv[]) {
  const char* fn = (argc == 2)? argv[1] : "test.txt";
  std::string filename(fn);

  std::ifstream f(filename);
  Lexer lexer(f, filename);
  lexer.lex();

  Tokens tokens = lexer.tokens();

  for(uint i = 0; i < tokens.size(); ++i) {
    AST::Node* node = tokens[i];
    std::cout
      << std::setw(10) << node->text()     << ' '
      << std::setw(10) << node->type()     << ' '
      << std::setw(10) << lexer.filename() << ' '
      << std::setw( 4) << node->row()      << ' '
      << std::setw( 4) << node->col()      << ' '
      << std::setw( 4) << node->lbp()      << ' '
      << std::setw( 4) << node->rbp()      << '\n';
  }
  std::cout << "##############################\n";

  Parser parser(lexer.tokens());
  AST::Node* root = parser.parse();

  AST::TreePrinter printer;
  root->send(&printer);

  return 0;
}
