#include "operator.h"
#include "trie.h"

const Operator* Operator::NEWLINE = new Binary("[ ]",        10);
const Operator* Operator::INDENT  = new Binary("[>]", "[<]", 10);
const Operator* Operator::DEDENT  = new Symbol("[<]");

static Trie* generate() {
  int p = 0;
  Trie* trie = new Trie;

  // Enders:
  trie->add(new Symbol(")"));
  trie->add(new Symbol("}"));
  trie->add(new Symbol("]"));
  trie->add(new Symbol("[<]"));
  trie->add(new Symbol("end"));

  if(Operator::NEWLINE->lbp() != (p += 10)) {
    throw "Bad precedence.";
  }

  // Joins and breaks:
  trie->add(new Binary(";",    p += 10));
  trie->add(new Binary(",",    p += 10));

  p += 10; // Assignments:
  trie->add(new Binary("|=",   p, p - 1));
  trie->add(new Binary("^=",   p, p - 1));
  trie->add(new Binary("&=",   p, p - 1));
  trie->add(new Binary(">>>=", p, p - 1));
  trie->add(new Binary("<<<=", p, p - 1));
  trie->add(new Binary(">>=",  p, p - 1));
  trie->add(new Binary("<<=",  p, p - 1));
  trie->add(new Binary("-=",   p, p - 1));
  trie->add(new Binary("+=",   p, p - 1));
  trie->add(new Binary("\\=",  p, p - 1));
  trie->add(new Binary("%=",   p, p - 1));
  trie->add(new Binary("/=",   p, p - 1));
  trie->add(new Binary("*=",   p, p - 1));
  trie->add(new Binary("**=",  p, p - 1));
  trie->add(new Binary(":=",   p, p - 1));
  trie->add(new Binary("=>",   p, p - 1));
  trie->add(new Binary("=",    p, p - 1));

  // Miscellaneous:
  trie->add(new Binary("~>",   p += 10));
  trie->add(new Binary("->",   p += 10));
  trie->add(new Binary(":",    p += 10));

  // Control-flow conditionals:
  trie->add(new Binary("||",   p += 10));
  trie->add(new Binary("^^",   p += 10));
  trie->add(new Binary("&&",   p += 10));

  p += 10; // Comparisons:
  trie->add(new Binary("!=",   p));
  trie->add(new Binary("==",   p));
  trie->add(new Binary("<=",   p));
  trie->add(new Binary(">=",   p));
  trie->add(new Binary("<",    p));
  trie->add(new Binary(">",    p));

  // Miscellaneous:
  trie->add(new Binary("<=>",  p += 10));
  trie->add(new Binary("<->",  p += 10));

  // Boolean conditionals:
  trie->add(new Binary("|",    p += 10));
  trie->add(new Binary("^",    p += 10));
  trie->add(new Binary("&",    p += 10));

  p += 10; // Shifts and rotates:
  trie->add(new Binary(">>",   p));
  trie->add(new Binary("<<",   p));
  trie->add(new Binary(">>>",  p));
  trie->add(new Binary("<<<",  p));

  p += 10; // Addition and subtraction:
  trie->add(new Binary("-",    p));
  trie->add(new Binary("+",    p));

  p += 10; // Multiplication and division:
  trie->add(new Binary("*",    p));
  trie->add(new Binary("/",    p));
  trie->add(new Binary("%",    p));
  trie->add(new Binary("\\",   p));

  p += 10; // Mathy prefixes:
  trie->add(new Prefix("~",    p));
  trie->add(new Prefix("!",    p));
  trie->add(new Prefix("-",    p));
  trie->add(new Prefix("+",    p));

  p += 10; // Exponentiation:
  trie->add(new Binary("**",   p, p - 1));

  p += 10; // Typecast prefixes:
  trie->add(new Prefix("%",    p));
  trie->add(new Prefix("?",    p));
  trie->add(new Prefix("&",    p));

  p += 10; // Some brackets:
  trie->add(new Binary("[", "]", p, 0));
  trie->add(new Binary("{", "}", p, 0));
  trie->add(new Binary("(", ")", p, 0));
  trie->add(new Prefix("[", "]", p, 0));
  trie->add(new Prefix("{", "}", p, 0));
  trie->add(new Prefix("(", ")", p, 0));

  p += 10; // Access binaries:
  trie->add(new Binary("::",   p));
  trie->add(new Binary(".",    p));
  trie->add(new Binary("$",    p));
  trie->add(new Binary("@",    p));

  p += 10; // Access prefixes:
  trie->add(new Prefix("::",   p));
  trie->add(new Prefix("$",    p));
  trie->add(new Prefix("@",    p));

  return trie;
}

const Trie* Operator::ALL = generate();

Operator::Operator(const char* text, const char* closer, int a, int l, int r) {
  mText   = text;
  mCloser = closer;
  mArity  = a;
  mLBP    = l;
  mRBP    = r;
}

int Operator::arity() const {
  return mArity;
}

bool Operator::binary() const {
  return mArity == 2;
}

const char* Operator::closer() const {
  return mCloser;
}

const Trie* Operator::get(Lexer& lexer) {
  return Operator::ALL->get(lexer);
}

const Trie* Operator::get(const std::string& text) {
  return Operator::ALL->get(text);
}

int Operator::lbp() const {
  return mLBP;
}

bool Operator::prefix() const {
  return mArity == 1;
}

int Operator::rbp() const {
  return mRBP;
}

const std::string& Operator::text() const {
  return mText;
}
