#ifndef CUBIT_LEX_TRIE_H
#define CUBIT_LEX_TRIE_H

#include <map>
#include <string>

class Lexer;
class Operator;

class Trie {
protected:
  const Operator* mBinary;
  const Operator* mPrefix;
  std::map<char, Trie*> mChildren;
public:
  Trie();

  const Operator* binary() const;
  const Operator* prefix() const;

  void  add(Operator* op);

  const Trie* get(char c) const;
  const Trie* get(Lexer& lexer) const;
  const Trie* get(const std::string& text) const;
};

#endif
