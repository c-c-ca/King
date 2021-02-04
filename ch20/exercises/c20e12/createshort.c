#include <stdio.h>

unsigned short create_short(unsigned char high_byte,
                            unsigned char low_byte);

int main(void)
{
    unsigned char high_byte = 0x12, low_byte = 0x34;

    printf("%hx\n", create_short(high_byte, low_byte));

    return 0;
}

#ifdef WRONG
/* The arithmetic operators have higher precedence than the bitwise shift operators. */
unsigned short create_short(unsigned char high_byte,
                            unsigned char low_byte)
{
    return high_byte << 8 + low_byte;
}
#endif

#ifdef CORRECT
unsigned short create_short(unsigned char high_byte,
                            unsigned char low_byte)
{
    return (high_byte << 8) + low_byte;
}
#endif
