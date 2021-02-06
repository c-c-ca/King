#include <stdio.h>

union IEEE_float {
    struct {
        unsigned int fraction: 23;
        unsigned int exponent: 8;
        unsigned int sign: 1;
    } ieee_float;
    float x;
};

int main(void)
{
    union IEEE_float u;

    u.ieee_float.fraction = 4788176;
    u.ieee_float.exponent = 128;
    u.ieee_float.sign = 0;

    printf("%f\n", u.x); /* prints "3.141590" */

    return 0;
}
