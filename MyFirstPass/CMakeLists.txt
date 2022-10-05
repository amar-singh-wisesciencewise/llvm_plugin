add_llvm_library( LLVMMyFirstPass MODULE BUILDTREE_ONLY
  MyFirstPass.cpp

  DEPENDS
  intrinsics_gen
  PLUGIN_TOOL
  opt
  )
