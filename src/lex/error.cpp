#include "error.h"

#include "lexer.h"
#include "parser.h"
#include "chars/all.h"
#include "../ast/node.h"

#include <iomanip>
#include <sstream>

// Lex Errors
LexError::LexError(const Lexer& lexer, const std::string& what): mWhat(prefix(lexer, what)) {
  // All done.
}

std::string LexError::charinfo(char c) {
  std::stringstream s;
  s << '\'' << Char::name(c) << "' (0x" << std::hex << std::setfill('0') << std::setw(2) << int(c) << ')';
  return s.str();
}

LexError LexError::expected(const Lexer& lexer, const std::string& expected) {
  std::stringstream s;
  s << "Expected " << expected << " but got " << charinfo(lexer.peek());
  return LexError(lexer, s.str());
}

std::string LexError::prefix(const Lexer& lexer, const std::string& what) {
  std::stringstream s;
  s << "Error at " << lexer.line() << ", " << lexer.column() << ": " << what;
  return s.str();
}

const char* LexError::what() const throw() {
  return mWhat.c_str();
}


// Parse Errors
ParseError ParseError::expected(const Parser& parser, const std::string& expected) {
  std::stringstream s;
  s << "Expected " << expected << " but got " << parser.peek()->text();
  return ParseError(parser, s.str());
}

ParseError::ParseError(const Parser& parser, const std::string& what) {
  std::stringstream s;
  s << "Error at " << parser.peek()->row() << ", " << parser.peek()->col() << ": " << what;
  mWhat = s.str();
}

const char* ParseError::what() const throw() {
  return mWhat.c_str();
}
