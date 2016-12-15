#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, int y);

int main() {
	printf("%d \n", getbits(75, 6, 4));
	printf("%d \n", getbits(4, 2, 1));
	//printf("%d \n", setbits(10, 1, 1, 0));

	return 0;
}

unsigned setbits(unsigned x, int p, int n, int y) {
	x >> (p+1-n);
	//return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned getbits(unsigned x, int p, int n) {
	return (x >> (p+1-n)) & ~(~0 << n);
}
