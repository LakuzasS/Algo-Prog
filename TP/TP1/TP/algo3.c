#include "algo3.h"

int algo3(int x, int y) {
	int z = algo1(x, y);
	return algo2(x - y, z);
}