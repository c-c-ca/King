/* Swaps two variables without a temporary variable using XOR encryption */

#include <stdio.h>

/* Steps 1/2: x = msg, y = key */
/* Steps 2/3: x = key, y = msg */

#define M(x,y) ((x)^=(y),(y)^=(x),(x)^=(y)) /* swap x and y */

#define PRINT(x) printf("Value of " #x ": %d\n", (x))

int main(void)
{
    unsigned short i = 1, j = 2;

    M(i,j);
    PRINT(i); /* prints "Value of i: 2" */
    PRINT(j); /* prints "Value of j: 1" */

    return 0;
}
