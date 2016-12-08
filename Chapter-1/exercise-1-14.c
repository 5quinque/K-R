#include <stdio.h>

int main() {
	int c, i, j;
	int nchar[24];

	for (i = 0; i < 24; ++i)
		nchar[i] = 0;


	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			;
		} else if (c >= 97 && c <= 121) {
			++nchar[c-97];
		} else {
			++nchar[c-65];
		}


	}

	printf("Histogram: \n");
	for (i = 0; i < 24; ++i) {
		printf("%c : ", i+65);

		for (j = 0; j < nchar[i]; ++j)
	 		printf("=");

		printf("\n");
	}

	return 0;
}
