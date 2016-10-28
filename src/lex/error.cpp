#include "error.h"
#include "lexer.h"

#include <iomanip>
#include <sstream>

LexError::LexError(const Lexer& lexer, const std::string& what): mWhat(prefix(lexer, what)) {
  // All done.
}

std::string LexError::charinfo(char c) {
  std::stringstream s;
  s << '\'' << Lexer::cname(c) << "' (0x" << std::hex << std::setfill('0') << std::setw(2) << int(c) << ')';
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
