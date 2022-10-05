## MyFirstPass
1. Copy the MyFirstPass folder inside "llvm-project/llvm/lib/Transforms/" also add "add_subdirectory(MyFirstPass)" inside "llvm-project/llvm/lib/    Transforms/CMakeLists.txt"
2. make or build the LLVM again. It should create a "LLVMMyFirstPass.so" inside "build/lib/"
3. How to load the shared object and execute: /home/amar/AMAR/LLVM/llvm-project/build/bin/opt -load /home/amar/AMAR/LLVM/llvm-project/build/lib/LLVMMyFirstPass.so -myfirstpass -enable-new-pm=0 < prog9.ll > /dev/null

