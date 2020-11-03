#include <stdio.h>

#define N 10

void selection_sort(int a[], int n);
int main(void)
{
    int a[N], i;

    printf("Enter %d numbers to be sorted: ", N);
    for (i = 0; i < N; i++)
        scanf("%d ", &a[i]);

    selection_sort(a, N);

    printf("In sorted order: ");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

void selection_sort(int a[], int n)
{
    int i, temp, high = 0;

    if (n <= 1) return;

    for (i = 1; i < n; i++)
        if (a[i] > a[high])
            high = i;

    temp = a[n-1];
    a[n-1] = a[high];
    a[high] = temp;

    selection_sort(a, n - 1);
}