#ifndef CUBIT_MODULE_H
#define CUBIT_MODULE_H

#include <map>
#include <string>

namespace Cubit
{
  class Function;

  class Module {
  protected:
    std::string   mName;
    const Module* mParent;
    // <IMPL>        mLLVM;

    std::map<std::string, const Function*> mFunctions;
    std::map<std::string, const Module*  > mSubmodules;
  public:
    Module(const Module* mParent, const std::string& name);
    ~Module();

    const std::string& name() const;

    void function(const Function* f);
    void submodule(const Module* m);
  };
}

#endif
