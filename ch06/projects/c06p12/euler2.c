#include <stdio.h>

int main(void)
{
    int i;
    float e, denom, epsilon;

    printf("Enter a value for epsilon: ");
    scanf("%f", &epsilon);

    e = denom = 1.0f;
    for (i = 1; 1.0f / (denom *= (float) i) > epsilon; i++)
        e += 1.0f / denom;

    printf("%f\n", e);

    return 0;
}
