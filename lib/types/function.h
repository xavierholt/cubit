#ifndef CUBIT_FUNCTION_H
#define CUBIT_FUNCTION_H

#include <vector>

namespace Cubit
{
  class Module;
  class Type;

  class Function {
  protected:
    std::string   mName;
    const Module* mParent;

    struct {
      int mFunctionType;
      int mFunction;
    } llvm;

    const Type*              mReturnType;
    std::vector<const Type*> mArgumentTypes;
  public:
    Function(const Module* mParent, const std::string& name);
    ~Function();

    const std::string& name() const;
  };
}

#endif
