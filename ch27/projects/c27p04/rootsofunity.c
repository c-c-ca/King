#include <complex.h>
#include <stdio.h>
#include <tgmath.h>

int main(void)
{
	int k, n;
	double complex root;

	printf("Enter a value for n: ");
	scanf("%d", &n);

	for (k = 0; k < n; k++) {
		root = exp(2 * M_PI * I * k / n);	
		printf("%.2g + %.2gi\n", creal(root), cimag(root));
	}

	return 0;
}
