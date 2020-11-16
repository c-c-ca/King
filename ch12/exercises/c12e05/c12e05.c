#include <stdio.h>

int main(void)
{
    int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
    int *p;

    p = a;

/*  printf("%d\n", p == a[0]);       illegal: mismatched types */
    printf("%d\n", p == &a[0]);   /* true */
    printf("%d\n", *p == a[0]);   /* true */
    printf("%d\n", p[0] == a[0]); /* true */
}
