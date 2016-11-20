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
  static const char FVALUE = 0x01;
  static const char FSPACE = 0x02;
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
  Tokens&            tokens();

  void clear(char flags = 0);
  int  column()     const;
  void dedent();
  int  dent()       const;
  char flags()      const;
  void indent(int dent);
  void lex();
  int  line()       const;
  int  peek()       const;
  bool peek(int c)  const;
  bool spaced()     const;
  int  take();
  bool take(int c);
  void undo();
  bool valued()     const;

  Lexer& operator << (AST::Node*);
};

#endif
