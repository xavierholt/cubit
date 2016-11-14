#include "Int.h"

namespace Cubit
{
  namespace Types
  {
    class I32: public Type {

    };

    I32::I32(): Type(Module::ROOT, "I32") {
      ...
      mLLVM = llvm::IntegerType::get(context, 32);

      function("+", this, [this]);
      function("-", this, [this]);
    }
  }
}
