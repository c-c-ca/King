#include <stdio.h>

int main(void)
{
    int i;

    i = 10;
    while (i >= 1) {
        printf("%d ", i++);  /* prints "10 5 3 2 1 1 1 .. " */
        i /= 2;
    }

    printf("\n");

    return 0;
}
