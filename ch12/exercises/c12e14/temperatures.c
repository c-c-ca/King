#include <stdbool.h>
#include <stdio.h>

#define NUM_DAYS  7
#define NUM_HOURS 24

bool search(const int a[], int n, int key);

int main(void)
{
    int temperatures[NUM_DAYS][NUM_HOURS], (*p)[NUM_HOURS];

    for (p = temperatures; p < temperatures + NUM_DAYS; p++)
        if (search(*p, NUM_HOURS, 32))
            break;

    if (p < temperatures + NUM_DAYS)
        printf("Temperature found\n");
    else
        printf("Temperature not found\n");

    return 0;
}

bool search(const int a[], int n, int key)
{
    const int *p = a;

    while (p < a + n)
        if (*p++ == key)
            return true;
    
    return false;
}
