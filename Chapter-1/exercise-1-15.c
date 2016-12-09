#include <stdio.h>

float conv_to_fahr(float celsius);

int main() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;

	printf("Celsius - Fahrenheit\n");

	while (celsius <= upper) {
		printf("%3.0f %16.1f\n", celsius, conv_to_fahr(celsius));
		celsius = celsius + step;
	}

	return 0;
}

float conv_to_fahr(float celsius) {
	float fahr = (5.0 / 9.0) * (celsius + 32.0);

	return fahr;
}
