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
    int remainder;

    while (n != 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    return m;
}
