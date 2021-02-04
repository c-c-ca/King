#include <stdio.h>

unsigned int f(unsigned int i, int m, int n);

int main(void)
{
    printf("%x\n", f(0x1234, 7, 4));
    return 0;
}

/* f: gets last n bits starting at position m */
unsigned int f(unsigned int i, int m, int n)
{
    /* ~(~0 << n) is a mask used to retrieve the last n bits */
    return (i >> (m + 1 - n)) & ~(~0 << n);
}
