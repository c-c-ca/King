#include <stdio.h>

int main(void)
{
    printf("%d\n", 'A');        /* legal */
    printf("%d\n", 0b1000001);  /* legal */
    printf("%d\n", 0101);       /* legal */
    printf("%d\n", 0x41);       /* legal */

    return 0;
}
