#include <stdio.h>
#include <stdlib.h>

void *my_malloc(size_t n);

int main(void)
{
    return 0;
}

void *my_malloc(size_t n)
{
    void *p;

    p = malloc(n);
    if (p == NULL) {
        printf("Error: malloc failed in my_malloc\n");
        exit(EXIT_FAILURE);
    }

    return p;
}
