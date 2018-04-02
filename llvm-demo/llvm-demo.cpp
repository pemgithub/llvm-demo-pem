// llvm-demo.cpp : Defines the entry point for the console application.
//

#include <stdint.h>
#include <time.h>
#include <iostream>

#include "functions.h"

using namespace std;

class InstrOp
{
public:
	virtual void Execute() = 0;
};

class ExeEngine
{
protected:
	uint32_t numSelects;
	uint32_t numThreads;
	float* dyn;
	uint32_t *dst0;
	uint32_t *src0;
	uint32_t *src1;
public:
	ExeEngine()
	{
		numSelects = 64; // [0] exe, [1] d0, [2] s0, [3] s1, etc
		numThreads = 64;
		dyn = (float *)malloc(numSelects * numThreads * sizeof(float));
		dst0 = new uint32_t[numThreads];
		src0 = new uint32_t[numThreads];
		src1 = new uint32_t[numThreads];
	}
	void ExeCpp()
	{
		
		uint64_t exec = UINT64_MAX;
		if (exec == 0xFFFFFFFFFFFFFFFF) {
			for (uint32_t t = 0; t < numThreads; t++) {
				mul_f32_LLVM(*(float*)&dst0[t], *(float*)&src0[t], *(float*)&src1[t]);
			}
		} else {
			for (uint64_t t = 0; exec != 0; t++, exec >>= 1) {
				mul_f32_LLVM(*(float*)&dst0[t], *(float*)&src0[t], *(float*)&src1[t]);
			}
		}
	}
	void ExeLlvm()
	{
	}
};

int main()
{
	ExeEngine engine;
	clock_t start;
	double duration;
	start = clock();
	for (uint32_t x = 0; x < 100000; ++x) {
		engine.ExeCpp();
	}
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	//cout << duration << endl;
	printf("%7f\n", duration);

	return 0;
}
/*
DONE exe ExeCpp
TODO build functions.cpp with clang or llvm
TODO exe ExeLlvm calls dll?
TODO exe vs2017 calls llvm
*/
