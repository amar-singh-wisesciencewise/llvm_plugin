#ifndef LLVM_TRANSFORMS_UTILS_MYFIRSTPASS_H
#define LLVM_TRANSFORMS_UTILS_MYFIRSTPASS_H

#include "llvm/IR/PassManager.h"

namespace llvm {

class MyFirstPass : public PassInfoMixin<MyFirstPass> {
public:
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);
};

} // namespace llvm

#endif // LLVM_TRANSFORMS_UTILS_MYFIRSTPASS_H
