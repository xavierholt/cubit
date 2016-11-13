#ifndef CUBIT_OPERATOR_H
#define CUBIT_OPERATOR_H

#include <string>

class Lexer;
class Trie;

class Operator {
public:
  static const Trie* ALL;
  static const Trie* get(Lexer& lexer);
  static const Trie* get(const std::string& text);

  static const Operator* NEWLINE;
protected:
  std::string mName;
  std::string mText;
  int mPrecedence;
  int mAssociativity;
  int mArity;
public:
  Operator(const std::string& text, int a, int p, bool r = false);

  int  arity()  const;
  bool binary() const;
  int  lbp()    const;
  bool prefix() const;
  int  rbp()    const;

  const std::string& text() const;
};

#endif
