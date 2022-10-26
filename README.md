## MyFirstPass
This Pass is added using the old Pass Manager
1. Copy the MyFirstPass folder inside "llvm-project/llvm/lib/Transforms/" also add "add_subdirectory(MyFirstPass)" inside "llvm-project/llvm/lib/    Transforms/CMakeLists.txt"
2. make or build the LLVM again. It should create a "LLVMMyFirstPass.so" inside "build/lib/"
3. How to load the shared object and execute: /home/amar/AMAR/LLVM/llvm-project/build/bin/opt -load /home/amar/AMAR/LLVM/llvm-project/build/lib/LLVMMyFirstPass.so -myfirstpass -enable-new-pm=0 < prog9.ll > /dev/null

## MyFirstPass - Using the New Pass Manager
This Pass is added using the new Pass Manager
1. Copy the ".cpp" file inside MyFirstPass_new_PM folder to "llvm/lib/Transforms/Utils/MyFirstPass.cpp". Copy the ".h" file inside MyFirstPass_new_PM folder to "llvm/include/llvm/Transforms/Utils/MyFirstPass.h"
2. Add "MyFirstPass.cpp" in "llvm/lib/Transforms/Utils/CMakeLists.txt"
3. Add "FUNCTION_PASS("myfirstpass", MyFirstPass())" in "llvm/lib/Passes/PassRegistry.def"
4. Add "#include "llvm/Transforms/Utils/MyFirstPass.h"" in "llvm/lib/Passes/PassBuilder.cpp"
5. move to build folder and build the llvm again (make)
6. How to use the added pass "build/bin/opt -disable-output ~/AMAR/c/risc_v_programs/prog9.ll -passes=helloworld"
