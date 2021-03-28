#include <complex.h>
#include <stdio.h>
#include <tgmath.h>

int main(void)
{
	double absolute_value, argument;

	printf("Enter absolute value: ");
	scanf("%lf", &absolute_value);
	printf("Enter argument: ");
	scanf("%lf", &argument);

	printf("%g + %gi\n", 
	       absolute_value * cos(argument),
	       absolute_value * sin(argument));

	return 0;
}
