#include <stdbool.h>
#include <stdio.h>

int word_length();
unsigned int reverse_bits(unsigned int i);

int main(void)
{
    unsigned int i = 0x12345678;

    printf("%x\n", reverse_bits(i));

    return 0;
}

int word_length()
{
    int len;
    unsigned int word;

    for (word = (unsigned int) ~0, len = 0;
         word > 0;
         word >>= 1, len++)
    ;

    return len;
}

unsigned int reverse_bits(unsigned int n)
{
    unsigned int i = 0;
    int num_bits = word_length();

    while (num_bits--) {
        i <<= 1;
        i |= 0x0001 & n;
        n >>= 1;
    }

    return i;
}
