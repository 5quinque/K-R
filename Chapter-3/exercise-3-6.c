#include <stdio.h>
#include <string.h>

void itoa(long n, char s[], int w);
void reverse(char s[]);

int main() {
  long n = 123;
  char s[200];

  itoa(n, s, 6);
  
  printf("n: '%d'\ts: '%s'\n", n, s);

  return 0;
}

void itoa(long n, char s[], int w) {
  int i, sign;

  if ((sign = n) < 0) /* record sign */
    n = -n;           /* make n positive */
  i = 0;
  do {      /* generate digits in reverse order */
    s[i++] = n % 10 + '0';    /* get next digit */
  } while ((n /= 10) > 0);    /* delete it */
  if (sign < 0)
    s[i++] = '-';

  while (i < w)
    s[i++] = ' ';

  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int c, i, j;

  for(i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

