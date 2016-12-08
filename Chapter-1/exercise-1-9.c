#include <stdio.h>

int main() {
	int c, ls;

	ls = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			ls = 1;
		} else {
			if (ls == 1) {
				ls = 0;
				putchar(' ');
			}
			putchar(c);
		}
	}

	return 0;
}
