#include <stdio.h>

int gcd(int m, int n);
int main(void)
{
    int x, y;

    printf("Enter two integers: ");
    scanf("%d%d", &x, &y);
    printf("Greatest common divisor: %d", gcd(x, y));

    return 0;
}

int gcd(int m, int n)
{
    return n == 0 ? m : gcd(n, m % n);
}
