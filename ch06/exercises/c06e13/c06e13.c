#include <stdio.h>

int main(void)
{
    int m, n;

    m = 10;
    for (n = 0; m > 0; m /= 2, n++)
        ;

    return 0;
}
