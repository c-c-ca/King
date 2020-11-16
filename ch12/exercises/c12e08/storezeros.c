#include <stdio.h>

void store_zeros(int a[], int n);

int main(void)
{
    int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
    int *p = a, n = sizeof(a) / sizeof(a[n]);

    store_zeros(a, n);

    while (p < a + n)
        printf("%d ", *p++);
    printf("\n");

    return 0;
}


void store_zeros(int a[], int n)
{
    int *p = a;

    while (p < a + n)
        *p++ = 0;
}
