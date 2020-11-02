/* Calculates the number of digits in an integer */

#include <stdio.h>

int num_digits(long n);
int main(void)
{
    long n;

    printf("Enter a nonnegative integer: ");
    scanf("%ld", &n);
    printf("The number has %d digit(s).\n", num_digits(n));

    return 0;
}

int num_digits(long n)
{
    int digits = 0;

    do {
        n /= 10;
        digits++;
    } while (n != 0);

    return digits;
}
