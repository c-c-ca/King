#include <stdio.h>
#include <stdlib.h>

int cmp(const void *p, const void *q);

int main(void)
{
    int a[100], i;

    for (i = 0; i < 100; i++)
        a[i] = 100 - i;

    qsort(&a[50], 50, sizeof(a[0]), cmp);

    for (i = 0; i < 100; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

int cmp(const void *p, const void *q)
{
    return *(const int *) p - *(const int *) q;
}
