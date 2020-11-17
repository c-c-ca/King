#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 80    /* maximum length of message */

int main(void)
{
    char msg[MAX_LEN], *p, *q;

    p = q = msg;

    printf("Enter a message: ");
    while (p - msg < MAX_LEN && (*p = getchar()) != '\n') 
        if (isalnum(*p))
            p++;

    for (p-- ; p > q; p--, q++)
        if (tolower(*p) != tolower(*q))
            break;

    if (p > q)
        printf("Not a palindrome\n");
    else
        printf("Palindrome\n");

    return 0;
}
