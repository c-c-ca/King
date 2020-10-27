#include <stdio.h>

#define N 40

int main(void)
{
    int i, fib_numbers[N] = {0, 1};

    for (i = 2; i < N; i++)
        fib_numbers[i] = fib_numbers[i-1] + fib_numbers[i-2];

    for (i = 0; i < N; i++)
        printf("%d ", fib_numbers[i]);
    printf("\n");

    return 0;
}