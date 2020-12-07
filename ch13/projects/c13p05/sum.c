#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i = argc, total = 0;

    while (--i)
        total += atoi(argv[i]);
    printf("Total: %d\n", total);

    return 0;
}
