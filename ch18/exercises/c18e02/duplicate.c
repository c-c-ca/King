#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicate(const char *s);

int main(void)
{
    return 0;
}

char *duplicate(const char *s)
{
    char *temp = malloc(strlen(s));

    if (temp == NULL)
        return NULL;

    strcpy(temp, s);
    return temp;
}
