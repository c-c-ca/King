#include <stdio.h>

#define PRINT(x) printf("Value of " #x ": %d\n", x)

int main(void)
{
    enum {NORTH, SOUTH, EAST, WEST} direction;
    int x, y;

    direction = EAST;
    x = y = 0;

    switch (direction) {
        case EAST:  x++; break;
        case WEST:  x--; break;
        case SOUTH: y++; break;
        case NORTH: y--; break;
    }

    PRINT(x);
    PRINT(y);

    return 0;
}
