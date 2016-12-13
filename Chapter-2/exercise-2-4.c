#include <stdio.h>
#define TRUE 1
#define FALSE 0

void squeeze(char s1[], char s2[]);

int main() {
	char name[40] = "ryan linnit";

	squeeze(name, "ai");

	printf("%s\n", name);
	
}

void squeeze(char s1[], char s2[]) {
	int i, j, k;
	int char_not_exist = TRUE;

	for (i = j = 0; s1[i] != '\0'; i++) {
		char_not_exist = TRUE;
		for (k = 0; s2[k] != '\0'; k++) {
			if (s1[i] == s2[k]) {
				char_not_exist = FALSE;
			}
		}

		if (char_not_exist) {
			s1[j++] = s1[i];
		}
	}
	
	s1[j] = '\0';
}
