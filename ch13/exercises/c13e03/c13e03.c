#include <stdio.h>

#define MAX_LEN 20

int main(void)
{
    int i, j;
    char s[MAX_LEN];

    scanf("%d%s%d", &i, s, &j);

    printf("%d\n", i); /* prints "12" */
    printf("%s\n", s); /* prints "abc34" */
    printf("%d\n", j); /* prints "56" */

    return 0;
}
