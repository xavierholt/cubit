#ifndef CUBIT_LEXERROR_H
#define CUBIT_LEXERROR_H

#include <stdexcept>
#include <string>

class Lexer;
class Parser;

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

class ParseError: public std::exception {
protected:
  std::string mWhat;
public:
  static ParseError expected(const Parser& parser, const std::string& expected);
public:
  ParseError(const Parser& parser, const std::string& what);
  const char* what() const throw();
};

#endif
