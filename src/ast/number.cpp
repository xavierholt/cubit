#include "number.h"

namespace AST
{
  Number::Number(const Lexer& lexer, const std::string& text): Node(lexer, text) {
    mValue = std::stoll(text.c_str());
  }

  void Number::send(AST::Visitor* visitor) {
    visitor->visit(this);
  }

  static std::string TYPE("Number");
  const std::string& Number::type() const {
    return TYPE;
  }

  long long int Number::value() const {
    return mValue;
  }
}
