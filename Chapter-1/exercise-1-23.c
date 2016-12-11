#include <stdio.h>
#define MAXLINE 1024
#define IN 1
#define OUT 0

char line[MAXLINE];
int state = OUT;

int getline_ryan(void);
void remove_comment(void);

void remove_comment() {
	int i;

	for (i = 0; line[i] != '\0'; ++i) {
		if (state == OUT) {
			if (line[i] == '/' && line[i+1] == '*') {
				state = IN;
			} else {
				printf("%c", line[i]);
			}
		} else if (line[i] == '/' && line [i-1] == '*') {
			state = OUT;
		}
	}
}

int main() {
	int len;

	while ((len = getline_ryan()) > 0) {
		remove_comment();
	}
	
	return 0;
}

/* getline_ryan: read a line into s, return length */
int getline_ryan() {
	int c, i;

	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}

	if (i == (MAXLINE - 1)) {
		while((c = getchar()) != EOF) {
			++i;
		}
	}

	if (c == '\n') {
		line[i] = c;
		++i;
	}

	line[i] = '\0';

	return i;
}

