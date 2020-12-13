#include <stdio.h>

#define cube(x)     ((x) * (x) * (x))
#define mod4(x)     ((x) % 4)
#define lt100(x, y) ((x) * (y) < 100)

int main(void)
{
    int x = 2, y = 7, z = 50;

    printf("Cube of %d: %d\n", x, cube(x));
    printf("Remainder of %d/4: %d\n", y, mod4(y));
    printf("%d * %d is %sless than 100\n", x, y, lt100(x, y) ? "" : "not ");
    printf("%d * %d is %sless than 100\n", x, z, lt100(x, z) ? "" : "not ");


    return 0;
}
