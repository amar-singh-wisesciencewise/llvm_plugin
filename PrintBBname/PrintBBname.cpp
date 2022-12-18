/*
Author: AMAR SINGH
Date: Dec 18, 2022
License: MIT and Apache 2.0
Discription: Demonstration code for Printing the Basic Block Name using Old Pass Manager
Reference: https://llvm.org/docs/WritingAnLLVMPass.html
*/

#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;

namespace {
  /* Our Pass will inherit from FunctionPass */
  struct PrintBBname : public FunctionPass {
    static char ID; /* Pass ID */
    PrintBBname() : FunctionPass(ID) {}

    /* Override the runOnFunction of FunctionPass */
    bool runOnFunction(Function &F) override {
      errs() << F.getName()  << '\n';
      for (Function::iterator bb = F.begin(), e = F.end(); bb != e; bb++)
      {
	errs() << "	 -> " << bb->getName() << '\n';
      }
      errs() << '\n';
      return false; /* No Code Transformation */
    }
  };
}

char PrintBBname::ID = 0;
static RegisterPass<PrintBBname> X("print_bb_name", "Pass to print Basic Block's name");
