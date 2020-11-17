#include <stdio.h>

#define NUM_DAYS  7
#define NUM_HOURS 24

int *find_largest(int a[], int n);

int main(void)
{
    int temperatures[NUM_DAYS][NUM_HOURS], (*p)[NUM_HOURS];

    for (p = temperatures; p < temperatures + NUM_DAYS; p++)
        printf("Week %d: %d\n", p - temperatures + 1, *find_largest(*p, NUM_HOURS));

    return 0;
}

int *find_largest(int a[], int n)
{
    int *p, *largest = a;

    for (p = a + 1; p < a + n; p++)
        if (*p > *largest)
            largest = p;

    return largest;
}
