#include <stdio.h>

int polynomial(int x);
int main(void)
{
	int x;

	printf("Enter a value for x: ");
	scanf("%d", &x);

	printf("Value of polynomial: %d", polynomial(x));

	return 0;
}

int power(int x, int n);
int polynomial(int x)
{
	const int factors[6] = {-6, 7, -1, -5, 2, 3};
	int i, val = 0;

	for (i = 0; i < 6; i++)
		val += factors[i] * power(x, i);

	return val;
}

int power(int x, int n)
{
	return n == 0 ? 1 : x * power(x, n - 1);
}
