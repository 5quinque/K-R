#include <stdio.h>
#define MAXLINE 1000
#define MAXCOL 80

char line[MAXLINE];

int getline_ryan(void);
int fold_line(void);

int fold_line() {
	int i;
	int col = 0;
	int new_needed = 0;

	for (i = 0; line[i] != '\0'; ++i) {
		col++;

		if (col == MAXCOL) {
			new_needed = 1;
		}
		if (new_needed && (line[i] == ' ' || line [i] == '\t')) {
			printf("\n");
			col = 0;
			new_needed = 0;
		}
		
		printf("%c", line[i]);
	}
}

int main() {
	int len;

	while ((len = getline_ryan()) > 0) {
		if (len > MAXCOL) {
			fold_line();
		} else {
			printf("%s", line);
		}
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

