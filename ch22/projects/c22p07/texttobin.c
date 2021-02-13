#include <stdio.h>

int main(void)
{
    int i;

    while (scanf("%X", &i) != EOF)
        putchar(i);

    return 0;
}
