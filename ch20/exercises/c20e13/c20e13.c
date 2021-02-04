#include <stdio.h>

int main(void)
{
    int n = 0x1010;

    printf("%x\n", n);

    n &= n - 1; /* sets the least significant 1 bit to 0 */

    printf("%x\n", n);

    return 0;
}
