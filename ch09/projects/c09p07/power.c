#include <stdio.h>

int power(int x, int n);
int main(void)
{
	int x, n;

	printf("Enter values for x and n: ");
	scanf("%d%d", &x, &n);

	printf("%d to the power of %d: %d\n", x, n, power(x, n));

	return 0;
}

int power(int x, int n)
{
	int result;

	if (n == 0) return 1;

	if (n % 2 == 1) return x * power(x, n - 1);

	result = power(x, n / 2);
	return result * result;
}
