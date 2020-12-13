#include <stdio.h>
#include <string.h>

#define N 10
#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))


int main(void)
{
    char s[N];
    int i;

    strcpy(s, "abcd");
    i = 0;
    putchar(TOUPPER(s[++i])); /* prints "D" */

    strcpy(s, "0123");
    i = 0;
    putchar(TOUPPER(s[++i])); /* prints "2" */

    return 0;
}
