/*
  MyFirstPass create a Function level pass which
  does not disturb the Analyses and just prints the
  Function name
 */

#include "llvm/Transforms/Utils/MyFirstPass.h"

using namespace llvm;

PreservedAnalyses MyFirstPass::run(Function &F,
                                      FunctionAnalysisManager &AM) {
  errs() << F.getName() << "\n";
  return PreservedAnalyses::all();
}
