#include <complex.h>
#include <stdio.h>
#include <tgmath.h>

#define PRINT_COMPLEX(x) printf(#x " = %g %c %gi\n",      \
		                creal(x),                 \
		                cimag(x) < 0 ? '-' : '+', \
		                fabs(cimag(x)))

#define PRINT_REAL(x) printf(#x " = %g\n", creal(x))

int main(void)
{
	double a, b, c, discriminant;
	double complex discriminant_sqrt, root1, root2;

	printf("Enter a value for a: ");
	scanf("%lf", &a);
	printf("Enter a value for b: ");
	scanf("%lf", &b);
	printf("Enter a value for c: ");
	scanf("%lf", &c);

	discriminant = b * b - 4 * a * c;
	discriminant_sqrt = csqrt(discriminant);
	root1 = (-b + discriminant_sqrt) / (2 * a);
	root2 = (-b - discriminant_sqrt) / (2 * a);

	if (discriminant < 0) {
		PRINT_COMPLEX(root1);
		PRINT_COMPLEX(root2);
	} else {
		PRINT_REAL(root1);
		PRINT_REAL(root2);
	}

	return 0;
}
