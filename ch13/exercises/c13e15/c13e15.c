#include <stdio.h>

int f(char *s, char *t);

int main(void)
{
    printf("%d\n", f("abcd", "babc")); /* prints "3" */
    printf("%d\n", f("abcd", "bcd"));  /* prints "0" */
    return 0;
}

/* 
 * Returns the number of characters shared by both s and t
 * preceding the first character unique to s.
 */
int f(char *s, char *t)
{
    char *p1, *p2;

    for (p1 = s; *p1; p1++) {
        for (p2 = t; *p2; p2++)
            if (*p1 == *p2) break;
        if (*p2 == '\0') break;
    }
    return p1 - s;
}
