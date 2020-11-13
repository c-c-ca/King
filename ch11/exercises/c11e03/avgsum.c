#include <stdio.h>

#define N 10

void avg_sum(double a[], int n, double *avg, double *sum);

int main(void)
{
    int i;
    double b[N], avg, sum;

    printf("Enter %d numbers: ", N);
    for (i = 0; i < N; i++)
        scanf("%lf", &b[i]);

    avg_sum(b, N, &avg, &sum);

    printf("Average: %.1f\n", avg);
    printf("Sum: %.1f\n", sum);

    return 0;
}

void avg_sum(double a[], int n, double *avg, double *sum)
{
    int i;

    *sum = 0.0;
    for (i = 0; i < n; i++)
        *sum += a[i];
    *avg = *sum / n;
}
