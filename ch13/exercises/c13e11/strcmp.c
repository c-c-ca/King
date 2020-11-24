#include <stdio.h>

int my_strcmp(char *p, char *q);

int main(void)
{
    if (my_strcmp("bar", "baz") < 0)
        printf("Correct\n");
    else
        printf("Wrong\n");

    return 0;
}

int my_strcmp(char *p, char *q)
{
    for (; *p == *q; p++, q++)
        if (*p == '\0')
            return 0;
    return *p - *q;
}
