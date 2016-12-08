#include <stdio.h>

#define IN 1    /* Inside a word */
#define OUT 0   /* Outside a word */

int main() {
	int c, state, i, j;
	int wordlength = 0;
	int ndigit[10];

        state = OUT;

	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			++ndigit[wordlength-1];
			wordlength = 0;
		} else {
			++wordlength;
		}

                if (state == OUT) {
                        state = IN;
                }

	}

	printf("Histogram: \n");
	for (i = 0; i < 10; ++i) {
		printf("%d : ", i+1);

		for (j = 0; j < ndigit[i]; ++j)
	 		printf("=");

		printf("\n");
	}

	return 0;
}
