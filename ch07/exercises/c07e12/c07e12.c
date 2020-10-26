#include <stdio.h>

int main(void)
{
    int i;
    float f;
    double d;

    d = i + f;

    /* 1. i is converted to a float.      */
    /* 2. i + f is converted to a double. */

    return 0;
}