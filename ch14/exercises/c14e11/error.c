#include <stdio.h>

#define ERROR(x,...) fprintf(stderr, x, __VA_ARGS__)

int main(void)
{
    int index = 10;

    ERROR("Range error: index = %d\n", index);

    return 0;
}
