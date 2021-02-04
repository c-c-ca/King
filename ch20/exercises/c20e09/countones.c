#include <stdio.h>

int count_ones(unsigned char ch);

int main(void)
{
    printf("%d\n", count_ones(0xf3));
    return 0;
}

#ifdef A
int count_ones(unsigned char ch)
{
    int num_ones = 0;

    for (; ch > 0; ch >>= 1)
        if (ch & 0x01)
            num_ones++;

    return num_ones;
}
#endif

#ifdef B
int count_ones(unsigned char ch)
{
    return ch == 0 ? 0 : count_ones(ch & ch - 1) + 1;
}
#endif
