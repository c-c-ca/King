#include <stdio.h>

int gcd(int m, int n);
void reduce(int numerator, int denominator,
            int *reduced_numerator,
            int *reduced_denominator);

int main(void)
{
    int num, denom, reduced_num, reduced_denom;

    scanf("%d/%d", &num, &denom);

    reduce(num, denom, &reduced_num, &reduced_denom);

    printf("In lowest terms: %d/%d\n", reduced_num, reduced_denom);

    return 0;
}

void reduce(int numerator, int denominator,
            int *reduced_numerator,
            int *reduced_denominator)
{
    int divisor;

    divisor = gcd(numerator, denominator);

    *reduced_numerator = numerator / divisor;
    *reduced_denominator = denominator / divisor;
}

int gcd(int m, int n)
{
    return n == 0 ? m : gcd(n, m % n);
}
