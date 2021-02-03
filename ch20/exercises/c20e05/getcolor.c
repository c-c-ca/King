#include <stdio.h>

#define MK_COLOR(r,g,b) ((long) (b) << 16 | (g) << 8 | (r))

#define GET_RED(x)   ((x) & 0x00ff)
#define GET_GREEN(x) ((x) >> 8 & 0x00ff)
#define GET_BLUE(x)  ((x) >> 16 & 0x00ff)


int main(void)
{
    long color;

    color = MK_COLOR(70,50,120);

    printf("Red: %d\n", GET_RED(color));
    printf("Green: %d\n", GET_GREEN(color));
    printf("Blue: %d\n", GET_BLUE(color));

    return 0;
}
