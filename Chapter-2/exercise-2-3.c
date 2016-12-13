#include <stdio.h>

int is_hex_char(char c);
int htoi(char s[]);

int main() {
	printf("%d \n", htoi("0Xabc"));
	printf("%d \n", htoi("abc"));

	return 0;
}

/* converts a string of hexadecimal digits (including an optional 0x or 0X) into it equivalent integer value */
int htoi(char s[]) {
	int i, n;
	char t;

	n = 0;
	for (i = 0; is_hex_char(s[i]) != 1; ++i) {
		t = tolower(s[i]);

		if (t == '0' || t == 'x') {
			continue;
		}

		if (isdigit(t)) {
			n = 16 * n + (t - '0');
		} else {
			n = 16 * n + 10 + (t - 'a');
		}
	}

	return n;
}

int is_hex_char(char c) {
	if (c  >= '0' && c <= '9')
		return 0;
	if (c >= 'A' && c <= 'Z')
		return 0;
	if (c >= 'a' && c <= 'z')
		return 0;

	return 1;
}

