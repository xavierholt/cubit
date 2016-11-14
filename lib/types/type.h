#ifndef CUBIT_TYPE_H
#define CUBIT_TYPE_H

#include "module.h"

#include <vector>

namespace Cubit
{
  class Type: public Module {
  protected:
    std::vector<const Type*> mMembers;
  public:
    Type(const Module* mParent, const std::string& name);
    ~Type();

    void member(const Type* m);
  };
}

#endif
