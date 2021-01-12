#include <stdio.h>
#include <stdlib.h>

int *create_array(int n, int initial_value);

int main(void)
{
    return 0;
}


int *create_array(int n, int initial_value)
{
    int i, *a = malloc(n * sizeof(int));

    if (a == NULL)
        return NULL;

    for (i = 0; i < n; i++)
        a[i] = initial_value;

    return a;
}
