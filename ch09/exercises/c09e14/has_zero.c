#include <stdbool.h>
#include <stdio.h>

#define N 10

bool has_zero(int a[], int n);
int main(void)
{
    int a[N] = {4, 1, 6, 7, 2, 0, 13, 5, 21 ,3};

    if (has_zero(a, N))
        printf("Has zero\n");
    else
        printf("Has no zeros\n");

    return 0;
}

bool has_zero(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        if (a[i] == 0)
            return true;
    
    return false;
}