/* Structures and their members do not share the same namespace */

#include <stdio.h>

#define PRINT(x) printf("Value of " #x ": %d\n", x)

int main(void)
{
    struct { int x, y; } x;
    struct { int x, y; } y;

    x.x = 0;
    x.y = 1;

    y.x = 2;
    y.y = 3;

    PRINT(x.x);
    PRINT(x.y);

    PRINT(y.x);
    PRINT(y.y);

    return 0;
}
