#include <stdio.h>
#define MAXLINE 1000
#define TABSPACE 4
#define INBLANK 1
#define OUTBLANK 0

char line[MAXLINE];

int getline_ryan(void);
int conv_spaces(void);

int conv_spaces() {
	int i, j, spaces;
	int blank_count = 0;
	int state = OUTBLANK;

	for (i = 0; line[i] != '\0'; ++i) {
		if (line[i] != ' ') {
			state = OUTBLANK;

			printf("%c", line[i]);
			printf("BLANK PRE: %d POS: %d\n", blank_count, i);

			if (blank_count > 0) {
				if (i % TABSPACE == 0) {
					spaces = TABSPACE;
				} else {
					if (spaces < 2) {
						spaces = TABSPACE + (i % TABSPACE);
					} else {
						spaces = TABSPACE - (i % TABSPACE);
					}
				}
				//for (j = 0; j < spaces; ++j)
				//	printf("\t");
				printf("%d", spaces);
			}


			blank_count = 0;
		} else if (state == OUTBLANK) {
			state = INBLANK;
			++blank_count;
		}


		//if (line[i] == '\t') {
		//	if (i % TABSPACE == 0) {
		//		spaces = TABSPACE;
		//	} else {
		//		if (spaces < 2) {
		//			spaces = TABSPACE + (i % TABSPACE);
		//		} else {
		//			spaces = TABSPACE - (i % TABSPACE);
		//		}
		//	}
		//	for (j = 0; j < spaces; ++j)
		//		printf(" ");
		//} else {
		//	printf("%c", line[i]);
		//}
	}
}

int main() {
	int len;

	while ((len = getline_ryan()) > 0) {
		conv_spaces();
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

