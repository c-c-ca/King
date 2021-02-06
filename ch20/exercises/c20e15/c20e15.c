#include <stdio.h>

int main(void)
{
#ifdef WRONG
    struct {
        int flag: 1;  /* the highest order bit of an int may  */
    } s;              /* be treated as a sign bit             */
#endif

#ifdef CORRECT
    struct {
        unsigned int flag: 1; /* unsigned ints do not have a sign bit */
    } s;
#endif

    s.flag = 1;
    printf("%d\n", s.flag);

    return 0;
}
