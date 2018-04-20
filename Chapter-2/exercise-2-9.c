#include <stdio.h>

/*
 * x &= (x-1) deletes the rightmost 1-bit in x. Explain why
 *
 * When `x-1`  all bits from the rightmost 1-bit change, e.g
 *
 * 10101010101000
 * 10101010100111
 *
 * 10
 * 01
 *
 * 1000
 * 0111
 *
 * 010100
 * 010011
 *
 * `&` will clear all these changed bits
 *
 */

int bitcount(unsigned x);

int main() {
  int i;

  for (i = 0; i < 32; i++)
    printf("Bitcount of 18: %d\n", bitcount(i));

  return 0;
}

int bitcount(unsigned x) {
  int b;

  for (b = 0; x != 0; x &= (x-1))
    b++;

  return b;
}
