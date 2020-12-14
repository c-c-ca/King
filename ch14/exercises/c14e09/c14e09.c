#include <stdio.h>

#define CHECK(x,y,n) (           \
        0 <= (x) && (x) < (n) && \
        0 <= (y) && (y) < (n)    \
)

#define MEDIAN(x,y,z) (             \
    (x) > (y) ?                     \
        (x) > (z) ?                 \
            (y) > (z) ? (y) : (z) : \
            (x) :                   \
        (y) > (z) ?                 \
            (x) > (z) ? (x) : (z) : \
            (y)                     \
)

#define POLYNOMIAL(x) (         \
        3*(x)*(x)*(x)*(x)*(x) + \
        2*(x)*(x)*(x)*(x) -     \
        5*(x)*(x)*(x) -         \
        (x)*(x) +               \
        7*(x) -                 \
        6                       \
)

int main(void)
{
    int n = 10, x = 3, y = 9, z = 13;

    printf("CHECK(%d,%d,%d): %d\n", x, y, n, CHECK(x,y,n));
    printf("MEDIAN(%d,%d,%d): %d\n", x, y, z, MEDIAN(x,y,z));
    printf("POLYNOMIAL(%d): %d\n", x, POLYNOMIAL(x));

    return 0;
}
