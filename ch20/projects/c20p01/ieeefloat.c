#include <stdio.h>

union IEEE_float {
    struct {
        unsigned int fraction: 23;
        unsigned int exponent: 8;
        unsigned int sign: 1;
    } ieee_float;
    float x;
};

union IEEE_float create_IEEE_float(unsigned int fraction,
                                   unsigned int exponent,
                                   unsigned int sign);

int main(void)
{
    union IEEE_float u = create_IEEE_float(0, 128, 1);

    printf("%.1f\n", u.x);

    return 0;
}

union IEEE_float create_IEEE_float(unsigned int fraction,
                                   unsigned int exponent,
                                   unsigned int sign)
{
    union IEEE_float u;

    u.ieee_float.fraction = fraction;
    u.ieee_float.exponent = exponent;
    u.ieee_float.sign = sign;

    return u;
}

