#ifndef CUBIT_LEXER_H
#define CUBIT_LEXER_H

#include <istream>
#include <string>
#include <vector>

namespace AST {
  class Node;
}

class Lexlet;
typedef std::vector<int> Dents;
typedef std::vector<AST::Node*> Tokens;

class Lexer {
public:
  static const char BRACKET    = 0;
  static const char COMMENT    = 1;
  static const char SPACE      = 2;
  static const char IDENTIFIER = 3;
  static const char NEWLINE    = 4;
  static const char OPERATOR   = 5;
  static const char QUOTE      = 6;
  static const char INVALID    = 7;

  static const Lexlet* LEXLETS[8];
  static const char    CTYPES[128];
  static const char    CNAMES[128][4];

  static const char FVALUE = 0x01;
  static const char FSPACE = 0x02;

  static const char*   cname(char c);
  static const char    ctype(char c);
  static const Lexlet* lexlet(char c);
protected:
  std::string mFilename;
  Tokens      mTokens;
  Dents       mDents;
  char        mFlags;

  const char* mBuffer;
  const char* mAnchor;
  const char* mLatest;
  const char* mLength;

  int mLine;
  int mColumn;
  int mSavedLine;
  int mSavedColumn;
public:
  Lexer(std::istream& input, const std::string& filename);
  ~Lexer();

  const std::string& filename() const;
  std::string        text()     const;
  Tokens&            tokens();

  void clear(char flags = 0);
  int  column()     const;
  void dedent();
  int  dent()       const;
  char flags()      const;
  void indent(int dent);
  void lex();
  int  line()       const;
  char peek()       const;
  bool peek(char c) const;
  char take();
  bool take(char c);
  bool take(const char* c);

  Lexer& operator << (AST::Node*);
};

#endif
