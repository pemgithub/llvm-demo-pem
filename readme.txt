# use clang to generate llvm bitcode
clang -O3 -emit-llvm functions.cpp -c -o functions.bc

---
#TODO build D:\PemCode\LLVM-build\llvm
---
https://www.youtube.com/watch?v=RxE5LB16yCg
What about the lli, llc and llvm-dis commands?!!?

# notes
clang is a front-end; llvm x86 is a back-end (llc)

# http://pllab.cs.nthu.edu.tw/cs340402/lectures/lectures_2013/LLVM%20Bitcode%20Introduction.pdf
=> I think what I want to do is:
clang fooLLVM.c -O3 -S -emit-llvm -o fooLLVM.ll => human-readable .ll file
llvm-as: assemble a human-readable .ll file into bitcode
opt: run a series of LLVM-to-LLVM optimizations on a bitcode file
llvm-link: link several bitcode files into one
llc: generate native machine code for a bitcode file
okay but what about the backend?

# summary: the high level flow is:
1) pre-build functions.cpp to LLVM file
2) on exe, stitch functions together, then build to dll
3) exe that dll
... or something similar to this

# build exe: just an incremental step (figure out llvm/clang flow)
clang functions.cpp -o functions.exe
