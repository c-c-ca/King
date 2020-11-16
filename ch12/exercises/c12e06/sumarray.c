#include <stdio.h>

int sum_array(const int a[], int n);

int main(void)
{
    int a[] = {5, 15, 34, 54, 14, 2, 52, 72};

    printf("%d\n", sum_array(a, sizeof(a) / sizeof(a[0])));

    return 0;
}

int sum_array(const int a[], int n)
{
    int sum;
    const int *p = a;

    sum = 0;
    while (p < a + n)
        sum += *p++;
    
    return sum;
}
