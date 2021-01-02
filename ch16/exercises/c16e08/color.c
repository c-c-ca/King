#include <stdio.h>

#define PRINT_COLOR(x)                                 \
    printf("color: red = %d, green = %d, blue = %d\n", \
            x.red, x.green, x.blue)

struct color {
    int red;
    int green;
    int blue;
};

const struct color MAGENTA_A = {255, 0, 255};
const struct color MAGENTA_B = {.red = 255, .blue = 255};

int main(void)
{
    PRINT_COLOR(MAGENTA_A);
    PRINT_COLOR(MAGENTA_B);
    
    return 0;
}
