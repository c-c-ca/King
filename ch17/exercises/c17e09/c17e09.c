#include <stdio.h>

#define PRINT(x) printf("Value of " #x ": %d\n", (x))

int main(void)
{
    struct { int a; } x = { 42 };

    PRINT(x.a);       /* applies selection operator to access member a on x */
    PRINT((&x)->a);   /* accesses a on x through indirection on a pointer to x and selection */

    return 0;
}
