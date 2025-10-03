#include "echangenaif.h"

void echangeNaif(int* xa, int* xb) {
    int temp = *xa;
    *xa = *xb;
    *xb = temp;
    print("a = %d, b = %d\n", *a, *b)
}