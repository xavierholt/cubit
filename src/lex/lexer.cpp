#include "lexer.h"

#include "lexlets/all.h"
#include "../ast/end.h"

#include <cstring>

const char* Lexer::cname(char c) {
  if(c < 0 || c > 127) {
    return "???";
  }
  else {
    return CNAMES[(int) c];
  }
}

const char Lexer::ctype(char c) {
  if(c < 0 || c > 127) {
    return INVALID;
  }
  else {
    return CTYPES[(int) c];
  }
}

const Lexlet* Lexer::lexlet(char c) {
  return LEXLETS[(int) ctype(c)];
}

Lexer::Lexer(std::istream& input, const std::string& filename): mFilename(filename), mTokens() {
  input.seekg(0, input.end);
  size_t length = input.tellg();
  input.seekg(0, input.beg);

  char* buffer = new char[length + 1];
  input.read(buffer, length);
  buffer[length] = '\0';

  mBuffer      = buffer;
  mAnchor      = buffer;
  mLatest      = buffer;
  mLength      = buffer + length;
  mLine        = 1;
  mColumn      = 1;
  mSavedLine   = 1;
  mSavedColumn = 1;

  mDents.push_back(0);
}

Lexer::~Lexer() {
  delete [] mBuffer;
}

void Lexer::clear(char flags) {
  mAnchor      = mLatest;
  mSavedLine   = mLine;
  mSavedColumn = mColumn;
  mFlags       = flags;
}

int Lexer::column() const {
  return mSavedColumn;
}

void Lexer::dedent() {
  mDents.pop_back();
}

int Lexer::dent() const {
  return mDents.back();
}

const std::string& Lexer::filename() const {
  return mFilename;
}

char Lexer::flags() const {
  return mFlags;
}

void Lexer::indent(int dent) {
  mDents.push_back(dent);
}

void Lexer::lex() {
  while(!peek('\0')) {
    const Lexlet* l = lexlet(peek());
    l->lex(*this);
  }

  *this << new AST::EndOfInput(*this);
}

int Lexer::line() const {
  return mSavedLine;
}

char Lexer::peek() const {
  return *mLatest;
}

bool Lexer::peek(char c) const {
  return (*mLatest == c);
}

char Lexer::take() {
  char c = *mLatest;
  mLatest += (mLatest < mLength);

  if(c == '\n') {
    mLine  += 1;
    mColumn = 1;
  }
  else {
    mColumn += 1;
  }

  return c;
}

bool Lexer::take(char c) {
  bool m = peek(c);
  if(m) take();
  return m;
}

bool Lexer::take(const char* s) {
  int  l = strlen(s);
  bool m = (strncmp(s, mLatest, l) == 0);
  if(m) {
    mColumn += l;
    mLatest += l;
  }

  return m;
}

std::string Lexer::text() const {
  return std::string(mAnchor, mLatest);
}

Tokens& Lexer::tokens() {
  return mTokens;
}

Lexer& Lexer::operator << (AST::Node* node) {
  mTokens.push_back(node);
  return *this;
}