#include <stdio.h>

int main(void)
{
    int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
    int *high = &a[7], *low = &a[0], *middle;

 /* middle = (low + high) / 2;            WRONG: pointers cannot be divided */
    middle = low + (high - low) / 2;

    printf("%d\n", *middle);              /* prints "54" */
}
