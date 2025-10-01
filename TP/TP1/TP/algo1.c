#include "algo1.h"

int algo1(int a, int b) {
	int r = 0;
	a += 1;
	b *= a;
	r = b - a;
	return r;
}