#include <stdio.h>

int main(void)
{
    printf("%o - %o\n", '\b', '\10');
    printf("%o - %o\n", '\n', '\12');
    printf("%o - %o\n", '\r', '\15');
    printf("%o - %o\n", '\t', '\11');

    return 0;
}