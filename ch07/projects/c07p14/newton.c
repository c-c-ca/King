#include <stdio.h>
#include <math.h>

int main(void)
{
    double x, y, guess = 1.0;

    printf("Enter a positive number: ");
    scanf("%lf", &x);

    do {
        y = guess;
        guess = (y + x / y) / 2.0;
    } while (fabs(guess - y) >= 0.00001 * y);

    printf("Square root: %.5f\n", guess);

    return 0;
}
