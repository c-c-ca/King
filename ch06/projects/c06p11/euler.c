#include <stdio.h>

int main(void)
{
    int i, j, n, denom;
    float e;

    printf("Enter a number: ");
    scanf("%d", &n);

    e = denom = 1.0f;
    for (i = 1; i <= n; i++)
        e += 1.0f / (denom *= (float) i);

    printf("%f\n", e);

    return 0;
}
