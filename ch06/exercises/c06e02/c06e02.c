#include <stdio.h>

int main(void)
{
    int i;

    i = 9384;
    do {
        printf("%d ", i);  // prints "9384 938 93 9"
        i /= 10;
    } while (i > 0);

    printf("\n");

    return 0;
}
