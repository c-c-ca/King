#include <math.h>
#include <stdio.h>

int main(void)
{
	float principal, rate;
	int num_years;

	printf("Enter original amount: ");
	scanf("%f", &principal);

	printf("Enter interest rate: ");
	scanf("%f", &rate);

	printf("Enter number of years: ");
	scanf("%d", &num_years);

	printf("Value of a $%.2f deposit after %d years "
	       "at a %.1f%% interest rate: $%.2f\n",
		principal, num_years, rate,
		principal * exp(rate / 100.0 * num_years));

	return 0;
}
