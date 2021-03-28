#include <complex.h>
#include <stdio.h>
#include <tgmath.h>

int main(void)
{
	double a, b;
	double complex x;

	printf("Enter real part: ");
	scanf("%lf", &a);
	printf("Enter imaginary part: ");
	scanf("%lf", &b);

	printf("Argument: %f\n", carg(a + b * I));
	printf("Absolute value: %f\n", sqrt(a * a + b * b));


	return 0;
}
