#include <stdio.h>

int main(void)
{
    int i, j, n, denom;
    float e;

    printf("Enter a number: ");
    scanf("%d", &n);

    e = 1.0f;
    for (i = 1; i <= n; i++) {
        for (j = denom = 1; j <= i; j++)
            denom *= j;
        e += 1.0f / (float) denom;
    }

    printf("%f\n", e);

    return 0;
}