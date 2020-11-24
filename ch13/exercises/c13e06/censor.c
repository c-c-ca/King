#include <stdio.h>
#include <string.h>

void censor(char *str);

int main(void)
{
    char line[] = "food fool";

    censor(line);
    printf("%s\n", line);
    
    return 0;
}

void censor(char *str)
{
    char *p;

    for (p = str; *p; p++)
        if (p > str + 1 && strncmp(p - 2, "foo", 3) == 0)
            strncpy(p - 2, "xxx", 3);
}
