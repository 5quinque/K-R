#include <stdio.h>
#include <string.h>

void itob(long n, char s[], int b);
void reverse(char s[]);

int main() {
  long n;
  char s[200];

  for (n = 0; n < 200; n++) {
    itob(n, s, 16);
    printf("n: '%d'\ts: '%s'\n", n, s);
  }

  return 0;
}

void itob(long n, char s[], int b) {
  int i, sign;
  int temp;

  if ((sign = n) < 0) /* record sign */
    n = -n;           /* make n positive */
  i = 0;
  do {      /* generate digits in reverse order */
    temp = n % b;
    if (temp < 10) {
      s[i++] = temp + '0';
    } else {
      s[i++] = (temp-10) + 'A';
    }
  } while ((n /= b) > 0);    /* delete it */
  if (sign < 0)
    s[i++] = '-';
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

