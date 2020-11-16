#include <stdio.h>

#define N 5

double inner_product(const double *a, const double *b,
                     int n);

int main(void)
{
    double a[N] = {4.1, 5.6, 10.2, -3.1, 19.0};
    double b[N] = {0.2, -2.5, 3.3, 7.4, 13.2};

    printf("Inner product: %.1f\n", inner_product(a, b, N));

    return 0;
}

double inner_product(const double *a, const double *b,
                     int n)
{
    int sum = 0.0;

    while (n--)
        sum += *a++ * *b++;

    return sum;
}
