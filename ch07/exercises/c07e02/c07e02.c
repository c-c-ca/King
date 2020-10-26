#include <stdio.h>

int main(void)
{
    printf("%g\n", 010E2);      /* legal - floating point */
    printf("%g\n", 32.1E+5);    /* legal - floating point */
 /* printf("%d\n", 0790);    */ /* illegal                */
 /* printf("%d\n", 100_000); */ /* illegal                */
    printf("%g\n", 3.978e-2);   /* legal - floating point */

    return 0;
}
