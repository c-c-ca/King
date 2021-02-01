/* Steps 1/2 and Steps 2/3 perform XOR encryption */
/* Step 1/2: x = msg, y = key */
/* Step 2/3: x = key, y = msg */

#include <stdio.h>

#define M(x,y) ((x)^=(y),(y)^=(x),(x)^=(y))    /* swap values for x and y */

#define PRINT(x) printf("Value of " #x ": %d\n", (x))

int main(void)
{
    unsigned short i = 1, j = 2;

    M(i,j);
    PRINT(i); /* prints "Value of i: 2" */
    PRINT(j); /* prints "Value of j: 1" */

    return 0;
}
