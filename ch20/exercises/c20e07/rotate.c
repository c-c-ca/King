#include <stdbool.h>
#include <stdio.h>

unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);

int main(void)
{
    unsigned int i = 0x12345678;

    i = rotate_left(i, 4);
    printf("%x\n", i);

    i = rotate_right(i, 4);
    printf("%x\n", i);

    return 0;
}

unsigned int rotate_left(unsigned int i, int n)
{
    return i << n | i >> sizeof(unsigned int) * 8 - n;
}

unsigned int rotate_right(unsigned int i, int n)
{
    return i >> n | i << sizeof(unsigned int) * 8 - n;
}
