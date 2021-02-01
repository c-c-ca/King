#include <stdio.h>

int main(void)
{
    unsigned short i, j, k;

#ifdef A
    i = 8;    /* i is now   8 (binary 0000000000001000) */
    j = 9;    /* j is now   9 (binary 0000000000001001) */
              /* 1 + j is  10 (binary 0000000000001010) */
              /* i >> 10 is 0 (binary 0000000000000000) */
              /* 0 >> 1 is  0 (binary 0000000000000100) */
    printf("%d", i >> 1 + j >> 1); /* prints "0" */
#endif

#ifdef B
    i = 1;    /* i is now     1 (binary 0000000000000001) */
              /* ~i is    65534 (binary 1111111111111110) */
              /* i & ~i       0 (binary 0000000000000000) */
    printf("%d", i & ~i); /* prints "0" */
#endif

#ifdef C
    i = 2;    /* i is now      2 (binary 0000000000000010) */
    j = 1;    /* j is now      1 (binary 0000000000000001) */
    k = 0;    /* k is now      0 (binary 0000000000000000) */
              /* ~i is     65533 (binary 1111111111111101) */
              /* ~i & j is     1 (binary 0000000000000001) */
              /* ~i & j ^ k is 1 (binary 0000000000000001) */
    printf("%d", ~i & j ^ k); /* prints "1" */
#endif

#ifdef D
    i = 7;    /* i is now      7 (binary 0000000000000111) */
    j = 8;    /* j is now      8 (binary 0000000000001000) */
    k = 9;    /* k is now      9 (binary 0000000000001001) */
              /* j & k is      8 (binary 0000000000001000) */
              /* i ^ j & k is 15 (binary 0000000000001111) */
    printf("%d", i ^ j & k); /* prints "15" */
#endif

    return 0;
}
