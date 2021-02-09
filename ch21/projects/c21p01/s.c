#include <stddef.h>
#include <stdio.h>

struct s {
    char a;
    int b[2];
    float c;
};

#define PRINT_MEMBER(x,y)        \
    printf("  " #y "%8d%8d\n",   \
            sizeof(((x *)0)->y), \
            offsetof(x, y));

int main(void)
{

    printf("member   size   offset\n");

    PRINT_MEMBER(struct s, a);
    PRINT_MEMBER(struct s, b);
    PRINT_MEMBER(struct s, c);

    printf("\ntotal size: %d\n", sizeof(struct s));

    return 0;
}
