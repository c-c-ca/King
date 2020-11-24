#include <stdio.h>
#include <string.h>

#define N 20

int main(void)
{
    char str[N];

    strcpy(str, "tire-bouchon");
    strcpy(&str[4], "d-or-wi");
    strcat(str, "red?");

    printf("%s\n", str); /* prints "tired-or-wired?" */

    return 0;
}
