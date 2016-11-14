#include "trie.h"
#include "operator.h"

#include "../lexer.h"

Trie::Trie(): mChildren() {
  mBinary = nullptr;
  mPrefix = nullptr;
  mSymbol = nullptr;
}

void Trie::add(Operator* op) {
  Trie* trie = this;

  for(unsigned int i = 0; i < op->text().length(); ++i) {
    char chr = op->text()[i];
    auto itr = trie->mChildren.find(chr);
    if(itr == trie->mChildren.end()) {
      trie = trie->mChildren[chr] = new Trie;
    }
    else {
      trie = itr->second;
    }
  }

  if(op->binary()) {
    trie->mBinary = op;
  }
  else if(op->prefix()) {
    trie->mPrefix = op;
  }
  else {
    trie->mSymbol = op;
  }
}

const Operator* Trie::binary() const {
  return mBinary;
}

const Trie* Trie::get(char c) const {
  auto itr = mChildren.find(c);
  return (itr == mChildren.end())? nullptr : itr->second;
}

const Trie* Trie::get(Lexer& lexer) const {
  const Trie* trie = this;

  while(true) {
    const Trie* temp = trie->get(lexer.peek());
    if(temp == nullptr) return trie;
    lexer.take();
    trie = temp;
  }
}

const Trie* Trie::get(const std::string& text) const {
  const Trie* trie = this;

  for(unsigned int i = 0; i < text.length(); ++i) {
    trie = trie->get(text[i]);
    if(trie == nullptr) break;
  }

  return trie;
}

const Operator* Trie::prefix() const {
  return mPrefix;
}

const Operator* Trie::symbol() const {
  return mSymbol;
}
