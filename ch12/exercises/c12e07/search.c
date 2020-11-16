#include <stdbool.h>
#include <stdio.h>

bool search(const int a[], int n, int key);

int main(void)
{
    int a[] = {5, 15, 34, 54, 14, 2, 52, 72};

    if (search(a, sizeof(a) / sizeof(a[0]), 54))
        printf("Key found\n");
    else
        printf("Key not found\n");

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
