#include <stdio.h>

#define N 5

void print_error(const char *message);

int main(void)
{
    int i;

    for (i = 0; i < N; i++)
        print_error("error message");

    return 0;
}

void print_error(const char *message)
{
    static int n = 1;
    printf("Error %d: %s\n", n++, message);
}
