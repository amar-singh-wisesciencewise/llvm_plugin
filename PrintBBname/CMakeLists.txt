add_llvm_library( LLVMPrintBBname MODULE BUILDTREE_ONLY
  PrintBBname.cpp

  DEPENDS
  intrinsics_gen
  PLUGIN_TOOL
  opt
  )
