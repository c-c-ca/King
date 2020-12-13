#include <stdio.h>

#define DOUBLE(x) 2*x
#define DOUBLE2(x) (2*(x))

int main(void)
{
    printf("Value of DOUBLE(1+2): %d\n", DOUBLE(1+2));    /* 4 */
    printf("Value of 4/DOUBLE(2): %d\n", 4/DOUBLE(2));    /* 4 */

    printf("Value of DOUBLE2(1+2): %d\n", DOUBLE2(1+2));  /* 6 */
    printf("Value of 4/DOUBLE2(2): %d\n", 4/DOUBLE2(2));  /* 1 */

    return 0;
}
