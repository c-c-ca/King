#include <stdio.h>
#include <string.h>

#define N 10

char *duplicate(const char *p);

int main(void)
{
    char *str;

    str = duplicate("foo");
    printf("%s\n", str);

    return 0;
}

char *duplicate(const char *p)
{
    char *q; /* WRONG: q must be initialized */

    strcpy(q, p);
    return q;
}
