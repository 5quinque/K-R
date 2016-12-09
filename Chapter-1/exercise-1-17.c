#include <stdio.h>
#define MAXLINE 1000

int getline_ryan(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
	int len;		/* current line length */
	char line[MAXLINE];	/* current input line */

	while ((len = getline_ryan(line, MAXLINE)) > 0)
		if (len > 80) {
			printf("%s", line);
		}
	
	return 0;
}

/* getline_ryan: read a line into s, return length */
int getline_ryan(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
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

