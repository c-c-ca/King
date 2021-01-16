#include <stdio.h>

int sum(int (*f)(int), int start, int end);
int square(int n);

int main(void)
{
    int i = 1, j = 10;

    printf("Sum of squares %d through %d: %d\n",
            i, j, sum(square, i, j));

    return 0;
}

int sum(int (*f)(int), int start, int end)
{
    int i, total = 0;

    for (i = start; i <= end; i++)
        total += (*f)(i);

    return total;
}

int square(int n)
{
    return n * n;
}
