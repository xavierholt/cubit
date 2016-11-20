#include "lexer.h"

#include "chars/all.h"
#include "lexlets/all.h"
#include "../ast/symbol.h"

// Keys are from Char::type(c):
static const Lexlet* LEXLETS[9] = {
  nullptr,
  new CommentLexlet,
  new SpaceLexlet,
  new IdentifierLexlet,
  new NewlineLexlet,
  new OperatorLexlet,
  new StringLexlet,
  new NumberLexlet,
  new InvalidLexlet
};

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
  for(int c = peek(); c != EOF; c = peek()) {
    LEXLETS[Char::type(c)]->lex(*this);
  }
}

int Lexer::line() const {
  return mSavedLine;
}

int Lexer::peek() const {
  return (mLatest < mLength)? mLatest[0] : EOF;
}

bool Lexer::peek(int c) const {
  return (c == peek());
}

int Lexer::take() {
  if(mLatest < mLength) {
    int c = *mLatest;
    mLatest += 1;

    if(c == '\n') {
      mLine   += 1;
      mColumn  = 1;
    }
    else {
      mColumn += 1;
    }

    return c;
  }
  else {
    return EOF;
  }
}

bool Lexer::spaced() {
  return (mFlags & FSPACE);
}

bool Lexer::take(int c) {
  bool m = peek(c);
  if(m) take();
  return m;
}

Tokens& Lexer::tokens() {
  return mTokens;
}

void Lexer::undo() {
  mLatest -= 1;
  mColumn -= 1;
}

bool Lexer::valued() {
  return (mFlags & FVALUE);
}

Lexer& Lexer::operator << (AST::Node* node) {
  mTokens.push_back(node);
  return *this;
}
