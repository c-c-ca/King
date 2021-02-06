#include <stdio.h>

struct IEEE_float {
    unsigned int fraction: 23;
    unsigned int exponent: 8;
    unsigned int sign: 1;
};

int main(void)
{
    struct IEEE_float x;

    x.sign = 0;
    x.exponent = 1;
    x.fraction = 1;

    printf("Sign: %d, Exponent: %d, Fraction: %d\n", 
            x.sign, x.exponent, x.fraction);

    return 0;
}
