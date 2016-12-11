#include <stdio.h>
#define MAXLINE 1024
#define IN 1
#define OUT 0

char line[MAXLINE];
int state = OUT;
int line_number = 0;
char syntax_open[4] = "\"([{";
char syntax_close[4] = "\")]}";
int syntax = 0;

int getline_ryan(void);
void check_syntax(void);

void check_syntax() {
	int i, j;
	
	line_number++;

	for (i = 0; line[i] != '\0'; ++i) {
		for (j = 0; j < 4; ++j) {
			if (line[i] == syntax_open[j] && state == OUT) {
				syntax = line_number;
				state = IN;
			} else if (line[i] == syntax_close[j] && state == IN) {
				state = OUT;
			}
		}

	}
}

int main() {
	int len;

	while ((len = getline_ryan()) > 0) {
		check_syntax();
	}

	if (state == IN) {
		printf("Error at line: %d\n", syntax);
	} else {
		printf("Syntax looks correct\n");
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

