#include "askeven.h"

void askEven() {
	int nb, go = 0;
	do {
		printf("Entrez un nombre svp (0 pour arreter)\n");
		int r = scanf_s("%d", &nb);
		if (r != 1) {
			printf("Erreur de saisie\n");
			scanf_s("%*[^\n]");
			nb = -1;
		}
		else
			if (0 == nb) {
				go = 0;
			}
			else {
				go = 1;
			}
		if (nb > 0) {
			if (isEven(nb)) {
				printf("Le nombre %d est pair\n", nb);
			}
			else {
				printf("Le nombre %d est impair\n", nb);
			}
		}
	} while (go);
}