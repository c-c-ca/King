#include <stdio.h>

#define NUM_DAYS  7
#define NUM_HOURS 24

int main(void)
{
    int *p, temperatures[NUM_DAYS][NUM_HOURS];
    int i = 3;

    for (p = temperatures[i]; p < temperatures[i] + NUM_HOURS; p++)
        printf("%d\n", *p);

    return 0;
}
