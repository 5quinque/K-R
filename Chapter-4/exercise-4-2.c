#include <stdio.h>
#include <math.h>
#include <ctype.h>

double atof(char s[]);

int main(void) {
  char s[] = "123.45e-6";
  char t[] = "46.321";
  char u[] = "123.45e+6";

  printf("String, %s - Float, %f\n", s, atof(s));
  printf("String, %s - Float, %f\n", t, atof(t));
  printf("String, %s - Float, %f\n", u, atof(u));
}

double atof(char s[]) {
  double val, power, dec;
  int i, sign;
  int sci = 0;

  for (i = 0; isspace(s[i]); i++) /* Skip white spaces */
    ;

  sign = (s[i] == '-') ? -1 : 1;

  if (s[i] == '+' || s[i] == '-')
    i++;

  for (val = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
  }
  if (s[i] == '.')
    i++;

  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  val = sign * val / power;

  if (s[i] == 'e') {
    sci = 1;
    i++;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
      i++;
    } else {
      return -1;
    }
  }

  for (dec = 0.0; isdigit(s[i]); i++) {
    dec = 10.0 * dec + (s[i] - '0');
  }

  if (sci) {
    return val * pow(10, sign * dec);
  } else {
    return val;
  }
}

