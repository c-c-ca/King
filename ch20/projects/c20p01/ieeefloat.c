#include <stdio.h>

void print_ieee_float(float x);

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
    float x;

    printf("Enter a floating-point value: ");
    scanf("%f", &x);

    print_ieee_float(x);

    return 0;
}

void print_ieee_float(float x)
{
    union IEEE_float u;

    u.x = x;

    printf("fraction: %d, exponent: %d, sign: %d\n",
            u.ieee_float.fraction,
            u.ieee_float.exponent,
            u.ieee_float.sign);
}

