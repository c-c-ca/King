#include <stdio.h>

#define PRINT(x) printf("Value of " #x ": %d\n", x)

int main(void)
{
    unsigned short i;

    i = 25;         /* i is now 25 (binary 0000000000011001) */

    i ^= 0x0010;    /* i is now  9 (binary 0000000000001001) */
    PRINT(i);       /* prints "Value of i: 9" */

    i ^= 0x0010;    /* i is now 25 (binary 0000000000011001) */
    PRINT(i);       /* prints "Value of i: 25" */

    return 0;
}
