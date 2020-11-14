#include <stdio.h>

#define N 10

int *find_largest(int a[], int n);

int main(void)
{
    int b[N], i, *largest;

    printf("Enter %d numbers: ", N);
    for (i = 0; i < N; i++)
        scanf("%d", &b[i]);

    largest = find_largest(b, N);

    printf("Largest: %d\n", *largest);

    return 0;
}

int *find_largest(int a[], int n)
{
    int i, *p = a;

    for (i = 1; i < n; i++)
        if (a[i] > *p)
            p = &a[i];

    return p;
}
