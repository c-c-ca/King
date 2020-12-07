#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = argc;

    while (--i)
        printf("%s ", argv[i]);
    printf("\n");

    return 0;
}
