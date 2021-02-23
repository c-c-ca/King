#include <math.h>
#include <stdio.h>

int main(void)
{
	float a, b, c, discriminant;

	printf("Enter value of a: ");
	scanf("%f", &a); 

	printf("Enter value of b: ");
	scanf("%f", &b); 

	printf("Enter value of c: ");
	scanf("%f", &c); 

	discriminant = b * b - 4.0 * a * c;

	if (discriminant < 0.0) {
		printf("Roots are complex\n");
		return 0;
	}

	printf("Roots: %f, %f\n",
		(-b + sqrt(discriminant)) / (2.0 * a),
		(-b - sqrt(discriminant)) / (2.0 * a));

	return 0;
}
