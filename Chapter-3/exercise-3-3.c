#include <stdio.h>
#include <string.h>

#define MAXLINE 100

void expand(char s1[], char s2[]);
int is_alphanum(char c);
int add_characters(char s1[], char s2[], int s1_index, int s2_index);

int main() {
  char s1[MAXLINE] = "-a-f-j0-5U-Z";
  char s2[10 * MAXLINE];

  expand(s1, s2);

  printf("s1: '%s'\n", s1);
  printf("s2: '%s'\n", s2);

  return 0;
}

void expand(char s1[], char s2[]) {
  int s1_index;
  int s2_index;
  int c;

	for (s1_index = 0, s2_index = 0; s1_index <= strlen(s1); s1_index++) {
    if ((s1_index == 0 || s1_index == strlen(s1)) && s1[s1_index] == '-') {
      s2[s2_index] = s1[s1_index];
      s2_index++;
      continue;
    }

    if (is_alphanum(s1[s1_index]) && s1[s1_index + 2] > s1[s1_index] &&
        s1[s1_index + 2] <= 'z' && s1[s1_index+1] == '-') {
      s2_index = add_characters(s1, s2, s1_index, s2_index);
    } else if (s1[s1_index] != '-') {
      s2[s2_index] = s1[s1_index];
      s2_index++;
    }
  }
}

int is_alphanum(char c) {
  return (c >= 'a' && c <= 'z') ||
    (c >= 'A' && c <= 'Z') ||
    (c >= '0' && c <= '9');
}

int add_characters(char s1[], char s2[], int s1_index, int s2_index) {
  int char_inc;
  for (char_inc = 0; char_inc < s1[s1_index + 2] - s1[s1_index]; s2_index++, char_inc++) {
    s2[s2_index] = s1[s1_index] + char_inc;
  }

  return s2_index;
}

