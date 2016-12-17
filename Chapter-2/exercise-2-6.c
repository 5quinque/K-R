#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, int y);

int main() {
	//printf("%d \n", getbits(75, 6, 4));
	printf("%d \n", setbits(75, 6, 4, 5));
	//printf("%d \n", setbits(10, 1, 1, 0));

	return 0;
}

unsigned setbits(unsigned x, int p, int n, int y) {
	int in_p;
	int mask;
	int get_bits;

	get_bits = x >> (p+1-n);
	get_bits = get_bits << (8-4);
	get_bits = get_bits >> (8-y-1);

	mask = (~0 << n);
	mask = mask << (8-y-1);
	
	//return get_bits; // 36
	return mask; // 00111100 = 60

	//   00100100
	// | 00000000 - make leftmost bit
	// | 00000011 - make rightmost bit

	// end result should be 00100111 = 39

	//return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned getbits(unsigned x, int p, int n) {
	return (x >> (p+1-n)) & ~(~0 << n);
	      //
	      //x >> (p+1-n) moves the desired field to the right end of the word
	      //	~0 all 1-bits
	      //        Shifting it left n bit positions with ~0<<n
	      //        ~ makes a mask with ones in the right most n bits
	      //
	      //	getbits(75, 6, 4)
	      //                75 in binary is 0100 1011
	      //
	      //		create a mask that is 4 bits long 
	      //		~0 =	1111 1111
	      //		<<4 =	1111 0000
	      //		~ =	0000 1111
	      //
	      //
	      //		                   .---- position ( From the right )
	      //		                   |
	      //		                   |   .- length
	      //		                   |   |
	      //		shift binary 75 by 6+1-4 = 3
	      //		0100 1011 >>3 0000 1001
	      //
	      //		  0000 1001
	      //		& 0000 1111
	      //		= 0000 1001 
	      //
	      //		0000 1001 = 9
}
