#include <stdio.h>

#define MAXLINE 100

void escape(char s[], char t[]);

int main() {

  char s[100];
  char t[100] = "Test string, Tab: '\t'\ntestnewline";

  escape(s, t);

  printf("s: %s\n", s);
  printf("t: %s\n", t);

  return 0;
}

void escape(char s[], char t[]) {
  int s_index;
  int t_index;

  s_index = t_index = 0;

	while (t[t_index] != '\0') {
    switch (t[t_index]) {
    case '\t':
      s[s_index] = '\\';
      s_index++;
      s[s_index] = 't';
      s_index++;
      break;
     case '\n':
      s[s_index] = '\\';
      s_index++;
      s[s_index] = 'n';
      s_index++;
      break;
    default:
      s[s_index] = t[t_index];
      s_index++;
      break;
    }
    t_index++;
  } 
}
