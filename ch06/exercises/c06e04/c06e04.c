#include <stdio.h>

int main(void)
{
    int i;

    for (i = 0; i < 10; i++)
        printf("%d ", i);     /* prints "0 .. 9" */
    printf("\n");

    for (i = 0; i < 10; ++i)
        printf("%d ", i);     /* prints "0 .. 9" */
    printf("\n");

    for (i = 0; i++ < 10;)
        printf("%d ", i);     /* prints "1 .. 10" */
    printf("\n");

    return 0;
}
