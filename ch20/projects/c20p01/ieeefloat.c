#include <stdio.h>

int main(void)
{
    union {
        struct {
            unsigned int fraction: 23;
            unsigned int exponent: 8;
            unsigned int sign: 1;
        } ieee_float;
        float value;
    } x;

    x.ieee_float.fraction = 4788176;
    x.ieee_float.exponent = 128;
    x.ieee_float.sign = 0;

    printf("%f\n", x.value);

    return 0;
}
