#include <stdio.h>
#define MAXLINE 1000

int getline_ryan(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
	int len;		/* current line length */
	char line[MAXLINE];	/* current input line */

	while ((len = getline_ryan(line, MAXLINE)) > 0)
		printf("%s", line);
	
	return 0;
}

/* getline_ryan: read a line into s, return length */
int getline_ryan(char s[], int lim) {
	int c, i;

	int blank = 0;
	int blank_start = 0;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		if ((c == '\t' || c == ' ') && blank != 1) {
			blank = 1;
			blank_start = i;
		} else if (c != '\t' || c == ' ') {
			blank = 0;
		}

		s[i] = c;
	}


	if (blank == 1) {
		s[blank_start] = '\n';
		s[blank_start+1] = '\0';
	}

	if (i==(lim-1)) {
		while((c = getchar()) != EOF) {
			++i;
		}
	}

	if (c == '\n' && i != 0) {
		s[i] = c;
		++i;
	} else if (c == '\n') {
		s[i] = '\0';
		++i;
	}

	s[i] = '\0';

	return i;
}

