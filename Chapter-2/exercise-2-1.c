#include <stdio.h>
#include <limits.h>

int main() {
	int i = 0;

	printf("Integer min: %d, max: %d\n", INT_MIN, INT_MAX);
	printf("Characer min: %d, max: %d\n", CHAR_MIN, CHAR_MAX);
	printf("Short min: %d, max: %d\n", SHRT_MIN, SHRT_MAX);
	printf("Long min: %ld, max: %ld\n", LONG_MIN, LONG_MAX);

	printf("Unsigned Integer max: %d\n", UINT_MAX);
	printf("Unsigned Character max: %d\n", UCHAR_MAX;
	printf("Unsigned Short max: %d\n", USHRT_MAX);
	printf("Unsigned Long min: %lu\n", ULONG_MAX);

        return 0;
}

