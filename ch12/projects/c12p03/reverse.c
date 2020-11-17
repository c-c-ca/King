#include <stdio.h>

#define MSG_LEN 80    /* maximum length of message */

int main(void)
{
    char msg[MSG_LEN], *p = msg;

    printf("Enter a message: ");
    while (p - msg < MSG_LEN && (*p = getchar()) != '\n') 
        p++;

    printf("Reversal is: ");
    while (p-- > msg)
        putchar(*p);
    printf("\n");

    return 0;
}
