#include <stdio.h>

#define N 10

int largest(int n, int a[n]);
int average(int n, int a[n]);
int num_positive(int n, int a[n]);
int main(void)
{
    int i, a[N];

    printf("Enter %d numbers: ", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);

    printf("Largest number: %d\n", largest(N, a));
    printf("Average: %d\n", average(N, a));
    printf("Number of positive elements: %d\n", num_positive(N, a));

    return 0;
}

int largest(int n, int a[n])
{
    int i, max = a[0];

    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

int average(int n, int a[n])
{
    int i, sum = 0;

    for (i = 0; i < n; i++)
        sum += a[i];

    return sum / n;
}

int num_positive(int n, int a[n])
{
    int i, count = 0;

    for (i = 0; i < n; i++)
        if (a[i] > 0)
            count++;

    return count;
}
