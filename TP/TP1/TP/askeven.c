#include <stdio.h>
#include "askeven.h"
#include "iseven.h"

void askEven() {
	int nb;
	scanf_s("%d", &nb);
	if (isEven(nb) {
		if (nb % 2 == 0) {
			printf("Le nombre %d est pair\n", nb);
		}
		else {
			printf("Le nombre %d est impair\n", nb);
		}
	}
	else {
		printf("Le nombre %d n'est pas positif\n", nb);
	}