#include <stdio.h>

int main(void)
{
    int i, j;

    for (i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1)
        printf("%d ", i);  /* prints "5 4 3 2" */

    printf("\n");

    return 0;
}
