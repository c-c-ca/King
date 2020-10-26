#include <stdio.h>

int main(void)
{
    printf("%x - %x\n", '\b', '\x08');
    printf("%x - %x\n", '\n', '\x0a');
    printf("%x - %x\n", '\r', '\x0d');
    printf("%x - %x\n", '\t', '\x09');

    return 0;
}