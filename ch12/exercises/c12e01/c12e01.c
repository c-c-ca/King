#include <stdio.h>

int main(void)
{
    int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
    int *p = &a[1], *q = &a[5];

    printf("%d\n", *(p+3));   /* prints "14" */
    printf("%d\n", *(q-3));   /* prints "34" */
    printf("%d\n", q - p);    /* prints "4" */
    printf("%d\n", p < q);    /* prints "1" */
    printf("%d\n", *p < *q);  /* prints "0" */
}
