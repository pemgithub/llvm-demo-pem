#include "functions.h"
#include <stdio.h>

__declspec(dllexport) void mul_f32_LLVM(float &d0, float &s0, float &s1)
{
	d0 = s0 * s1;
}

#ifdef __clang__
int main()
{
	printf("functions.cpp main clang\n");
	return 0;
}
#endif
