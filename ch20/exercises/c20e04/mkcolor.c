#include <stdio.h>

#define MK_COLOR(r,g,b) ((long) (b) << 16 | (g) << 8 | (r))

int main(void)
{
    printf("%x\n", MK_COLOR(255,255,255));
    return 0;
}
