/* Reverses a series of numbers using (pointer version) */

#include <stdio.h>

#define N 10

int main(void)
{
    int a[N], *p = a;

    printf("Enter %d numbers: ", N);
    while (p < a + N)
        scanf("%d", p++);

    printf("In reverse order:");
    while (p > a)
        printf(" %d", *--p);
    printf("\n");

    return 0;
}
