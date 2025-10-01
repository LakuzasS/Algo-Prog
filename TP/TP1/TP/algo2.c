#include "algo2.h"

int algo2(int x, int y) {
	int a = 1;
	int b = 1;
	int c = 1;
	a = a * x + y;
	b = b * y + x;
	int r = c * (x + y);
	return (a * b) - c;
}