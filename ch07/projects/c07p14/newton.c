#include <stdio.h>
#include <math.h>

int main(void)
{
    double x, y1, y2 = 1.0;

    printf("Enter a positive number: ");
    scanf("%lf", &x);

    do {
        y1 = y2;
        y2 = (y1 + x / y1) / 2.0;
    } while (fabs(y2 - y1) >= 0.00001 * y1);

    printf("Square root: %.5f\n", y2);

    return 0;
}
