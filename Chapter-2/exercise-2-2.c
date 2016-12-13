#include <stdio.h>

int check_cond(void);
int i;
int c;

int check_cond() {
	if (i < 1000 - 1)
		if ((c = getchar()) != '\n')
			if (c != EOF)
				return 0;

	return 1;
}

int main() {
	char s[1000];

	for (i = 0; check_cond() != 1; ++i) {
		s[i] = c;
	}

	s[i] = '\0';
	printf("%s\n", s);

        return 0;
}


