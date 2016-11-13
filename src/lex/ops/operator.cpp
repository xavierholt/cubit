#include "operator.h"
#include "trie.h"

const Operator* Operator::NEWLINE = new Operator("[ ]", 2, 10);

static Trie* generate() {
  int p = 10;
  Trie* trie = new Trie;

  // Joins and breaks:
  // Operator::NEWLINE = new Operator("\n",   2, p += 10);
  // trie->add(new Operator("\n",   2, p += 10));
  trie->add(new Operator(";",    2, p += 10));
  trie->add(new Operator(",",    2, p += 10));

  p += 10; // Assignments:
  trie->add(new Operator("|=",   2, p, true));
  trie->add(new Operator("^=",   2, p, true));
  trie->add(new Operator("&=",   2, p, true));
  trie->add(new Operator(">>>=", 2, p, true));
  trie->add(new Operator("<<<=", 2, p, true));
  trie->add(new Operator(">>=",  2, p, true));
  trie->add(new Operator("<<=",  2, p, true));
  trie->add(new Operator("-=",   2, p, true));
  trie->add(new Operator("+=",   2, p, true));
  trie->add(new Operator("\\=",  2, p, true));
  trie->add(new Operator("%=",   2, p, true));
  trie->add(new Operator("/=",   2, p, true));
  trie->add(new Operator("*=",   2, p, true));
  trie->add(new Operator("**=",  2, p, true));
  trie->add(new Operator(":=",   2, p, true));
  trie->add(new Operator("=>",   2, p, true));
  trie->add(new Operator("=",    2, p, true));

  // Miscellaneous:
  trie->add(new Operator("~>",   2, p += 10));
  trie->add(new Operator("->",   2, p += 10));
  trie->add(new Operator(":",    2, p += 10));

  // Control-flow conditionals:
  trie->add(new Operator("||",   2, p += 10));
  trie->add(new Operator("^^",   2, p += 10));
  trie->add(new Operator("&&",   2, p += 10));

  p += 10; // Comparisons:
  trie->add(new Operator("!=",   2, p));
  trie->add(new Operator("==",   2, p));
  trie->add(new Operator("<=",   2, p));
  trie->add(new Operator(">=",   2, p));
  trie->add(new Operator("<",    2, p));
  trie->add(new Operator(">",    2, p));

  // Miscellaneous:
  trie->add(new Operator("<=>",  2, p += 10));
  trie->add(new Operator("<->",  2, p += 10));

  // Boolean conditionals:
  trie->add(new Operator("|",    2, p += 10));
  trie->add(new Operator("^",    2, p += 10));
  trie->add(new Operator("&",    2, p += 10));

  p += 10; // Shifts and rotates:
  trie->add(new Operator(">>",   2, p));
  trie->add(new Operator("<<",   2, p));
  trie->add(new Operator(">>>",  2, p));
  trie->add(new Operator("<<<",  2, p));

  p += 10; // Addition and subtraction:
  trie->add(new Operator("-",    2, p));
  trie->add(new Operator("+",    2, p));

  p += 10; // Multiplication and division:
  trie->add(new Operator("*",    2, p));
  trie->add(new Operator("/",    2, p));
  trie->add(new Operator("%",    2, p));
  trie->add(new Operator("\\",   2, p));

  p += 10; // Mathy prefixes:
  trie->add(new Operator("~",    1, p));
  trie->add(new Operator("!",    1, p));
  trie->add(new Operator("-",    1, p));
  trie->add(new Operator("+",    1, p));

  // Exponentiation:
  trie->add(new Operator("**",   2, p += 10, true));

  p += 10; // Typecast prefixes:
  trie->add(new Operator("%",    1, p));
  trie->add(new Operator("?",    1, p));
  trie->add(new Operator("&",    1, p));

  p += 10; // Access binaries:
  trie->add(new Operator("::",   2, p));
  trie->add(new Operator(".",    2, p));
  trie->add(new Operator("$",    2, p));
  trie->add(new Operator("@",    2, p));

  p += 10; // Access prefixes:
  trie->add(new Operator("::",   1, p));
  trie->add(new Operator("$",    1, p));
  trie->add(new Operator("@",    1, p));

  return trie;
}

const Trie* Operator::ALL = generate();

Operator::Operator(const std::string& text, int a, int p, bool r) {
  mText          = text;
  mArity         = a;
  mPrecedence    = p;
  mAssociativity = r;
}

int Operator::arity() const {
  return mArity;
}

bool Operator::binary() const {
  return mArity == 2;
}

const Trie* Operator::get(Lexer& lexer) {
  return Operator::ALL->get(lexer);
}

const Trie* Operator::get(const std::string& text) {
  return Operator::ALL->get(text);
}

int Operator::lbp() const {
  return mPrecedence;
}

bool Operator::prefix() const {
  return mArity == 1;
}

int Operator::rbp() const {
  return mPrecedence - mAssociativity;
}

const std::string& Operator::text() const {
  return mText;
}
