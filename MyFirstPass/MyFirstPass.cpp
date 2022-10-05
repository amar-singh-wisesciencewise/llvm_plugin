/*
Author: AMAR SINGH
Date: Oct 5, 2022, Dushera
License: MIT and Apache 2.0
Discription: Demonstration code for writting LLVM Pass.
Reference: https://llvm.org/docs/WritingAnLLVMPass.html
*/

#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;

namespace {
  /* Our Pass will inherit from FunctionPass */
  struct MyFirstPass : public FunctionPass {
    static char ID; /* Pass ID */
    MyFirstPass() : FunctionPass(ID) {}

    /* Override the runOnFunction of FunctionPass */
    bool runOnFunction(Function &F) override {
      errs().write_escaped(F.getName()) << '\n';
      return false; /* No Code Transformation */
    }
  };
}

char MyFirstPass::ID = 0;
static RegisterPass<MyFirstPass> X("myfirstpass", "My First Pass");
