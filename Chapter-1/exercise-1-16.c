#include <stdio.h>
#define MAXLINE 10

int getline_ryan(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
	int len;		/* current line length */
	int max;		/* maxime length seen so far */
	char line[MAXLINE];	/* current input line */
	char longest[MAXLINE];	/* longest line save here */

	max = 0;

	while ((len = getline_ryan(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0) {
		if (max > MAXLINE) {
			printf("Too long to print, longest line was %d characters\n", max);
			printf("%s", longest);
		} else {
			printf("%s", longest);
		}
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
	
}
