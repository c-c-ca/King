#include <stdio.h>

void swap(int *p, int *q);

int main(void)
{
    int i = 0, j = 1;

    printf("Before: %d %d\n", i, j);
    swap(&i, &j);
    printf("After: %d %d\n", i, j);
}

/* exchanges values of i and j */
void swap(int *p, int *q)
{
    int temp;

    temp = *p;
    *p = *q;
    *q = temp;
}
