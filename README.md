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

## PrintBBname - It uses old Pass Manager to print basic blocks name
This Pass is added using the old Pass Manager
1. Copy the PrintBBname folder inside "llvm-project/llvm/lib/Transforms/" also add "add_subdirectory(PrintBBname)" inside "llvm-project/llvm/lib/    Transforms/CMakeLists.txt"
2. make or build the LLVM again. It should create a "LLVMPrintBBname.so" inside "build/lib/"
3. To load the shared object and execute: /home/amar/AMAR/LLVM/llvm-project/build/bin/opt -load /home/amar/AMAR/LLVM/llvm-project/build/lib/LLVMPrintBBname.so -print_bb_name -enable-new-pm=0 < LLVM_IR.ll > /dev/null

## Pass_using_tool - It is out-of-tree plugin code.
This plugin code also generate an executable apart from generating loadable ".so" file.

This plugin is out-of-tree implemetation of Constant Propogation. Out-of-tree means code does not need to been inside llvm-project and just needs the path to llvm build folder.

This is a copied and fixed version of "https://github.com/lac-dcc/llvm-course/tree/master/llvm-passes"

Below steps can be followed to create the executable and run the executable. Please also read README inside the folder.
1. "mkdir build"
2. "LLVM_INSTALL_DIR=/home/amar/AMAR/LLVM/llvm-project/build"
3. "LLVM_OPT=$LLVM_INSTALL_DIR/bin/opt"
4. "cmake -DLLVM_INSTALL_DIR=$LLVM_INSTALL_DIR -G "Unix Makefiles" -B build/ ."
5. "cd build/"
6. "make"
7. "cd bin"
8. "./addconst ../../examples/foo.ll" 
9. "cat out.ll"

