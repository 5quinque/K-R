#include <stdio.h>

#define ARR_SIZE 10

int binsearch(int x, int v[], int n);

int main() {
  int v[ARR_SIZE];
  int i;

  for (i = 0; i < ARR_SIZE; i++)
    v[i] = i;

  for (i = 0; i < ARR_SIZE; i++)
    printf("index of %d in v: %d\n", i, binsearch(i, v, ARR_SIZE));

  /* test a value we know it not in the array */
  printf("index of %d in v: %d\n", ARR_SIZE + 1, binsearch(ARR_SIZE + 1, v, ARR_SIZE));

  return 0;
}

int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;

  while (low <= high && x != v[mid]) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }

  if (x != v[mid])
    return -1;

  return mid; /* no match */
}
