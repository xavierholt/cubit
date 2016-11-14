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
  static const Operator* INDENT;
  static const Operator* DEDENT;
protected:
  std::string mText;
  const char* mCloser;

  int mArity;
  int mLBP;
  int mRBP;
protected:
  Operator(const char* text, const char* closer, int a, int l, int r);
public:
  int  arity()  const;
  bool binary() const;
  int  lbp()    const;
  bool prefix() const;
  int  rbp()    const;
  bool symbol() const;

  const char*        closer() const;
  const std::string& text()   const;
};

class Binary: public Operator {
public:
  Binary(const char* text, int l):
    Operator(text, nullptr, 2, l, l) {}
  Binary(const char* text, int l, int r):
    Operator(text, nullptr, 2, l, r) {}
  Binary(const char* text, const char* closer, int l):
    Operator(text, closer, 2, l, l) {}
  Binary(const char* text, const char* closer, int l, int r):
    Operator(text, closer, 2, l, r) {}
};

class Prefix: public Operator {
public:
  Prefix(const char* text, int l):
    Operator(text, nullptr, 1, l, l) {}
  Prefix(const char* text, int l, int r):
    Operator(text, nullptr, 1, l, r) {}
  Prefix(const char* text, const char* closer, int l):
    Operator(text, closer, 1, l, l) {}
  Prefix(const char* text, const char* closer, int l, int r):
    Operator(text, closer, 1, l, r) {}
};

class Symbol: public Operator {
public:
  Symbol(const char* text):
    Operator(text, nullptr, 0, 0, 0) {}
};

#endif
