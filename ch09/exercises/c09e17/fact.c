#include <stdio.h>

int fact(int n);
int main(void)
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Factorial of %d: %d\n", n, fact(n));

    return 0;
}

int fact(int n)
{
    int i, result = 1;

    for (i = 2; i <= n; i++)
        result *= i;

    return result;
}
