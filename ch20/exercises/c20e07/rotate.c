#include <stdbool.h>
#include <stdio.h>

unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);
int wordlength();

int main(void)
{
    unsigned int i = 0x12345678;

    i = rotate_left(i, 4);
    printf("%x\n", i);

    i = rotate_right(i, 4);
    printf("%x\n", i);

    return 0;
}

int wordlength()
{
    int len;
    unsigned int word;

    for (word = (unsigned int) ~0, len = 0;
         word != 0;
         word >>= 1, len++)
    ;

    return len;
}

unsigned int rotate_right(unsigned int i, int n)
{
    return i >> n | i << wordlength() - n;
}

unsigned int rotate_left(unsigned int i, int n)
{
    return i << n | i >> wordlength() - n;
}
