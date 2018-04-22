#include <stdio.h>

int lower(int c);

int main() {
  int c;

  for (c = 'A'; c <= 'Z'; c++)
    printf("Lower of %c:  %c\n", c, lower(c));

  return 0;
}

int lower(int c) {
  return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}

