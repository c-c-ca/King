#include <stdio.h>

int *find_middle(int a[], int n);

int main(void)
{
    int a[] = {5, 15, 34, 54, 14, 2, 52, 72};

    printf("Middle: %d\n", *find_middle(a, sizeof(a) / sizeof(a[0])));

    return 0;
}

int *find_middle(int a[], int n)
{
    return a + n / 2;
}
