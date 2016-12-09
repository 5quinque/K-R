#include <stdio.h>
#define MAXLINE 1000

int getline_ryan(char line[], int maxline);
void reverse(char line[], char rev[]);

int main() {
	int len;		/* current line length */
	char line[MAXLINE];	/* current input line */
	char rev[MAXLINE];

	while ((len = getline_ryan(line, MAXLINE)) > 0) {
		reverse(line, rev);
		printf("%s", rev);
	}
	
	return 0;
}

void reverse(char s[], char rev[]) {
	int c, i, j, k;
	c='a';
	k = 0;

	// Find the length of the string
	for (i = 0; i < MAXLINE - 1 && c != EOF && c != '\n'; ++i) {
		c = s[i];
	}

	// Reverse it
	for (j = (i-2); j > -2; --j) {
		rev[k] = s[j];

		++k;
	}

	--k;

	if (s[k] == '\n') {
		rev[k] = s[k];
		++k;
	}

	rev[k] = '\0';

}

/* getline_ryan: read a line into s, return length */
int getline_ryan(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}

	if (i==(lim-1)) {
		while((c = getchar()) != EOF) {
			++i;
		}
	}

	if (c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';

	return i;
}

