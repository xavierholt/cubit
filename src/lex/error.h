#ifndef CUBIT_LEXERROR_H
#define CUBIT_LEXERROR_H

#include "lexer.h"

#include <iomanip>
#include <stdexcept>
#include <string>
#include <sstream>

class LexError: public std::exception {
protected:
  std::string mWhat;
public:
  static std::string charinfo(char c);
  static LexError expected(const Lexer& lexer, const std::string& expected);
  static std::string prefix(const Lexer& lexer, const std::string& what);
public:
  LexError(const Lexer& lexer, const std::string& what);
  const char* what() const throw();
};

#endif
