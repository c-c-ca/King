#include <stdio.h>

int main(void)
{
    float f = 1.1e10f, frac_part;

    frac_part = f - (int) f;

    printf("%f\n", f);
    printf("%f\n", frac_part);

    return 0;
}
