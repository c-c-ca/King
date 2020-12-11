#include <stdio.h>

#define MSG_LEN 80    /* maximum length of message */

void reverse(char *message);
int read_line(char str[], int n);

int main(void)
{
    char msg[MSG_LEN+1];

    printf("Enter a message: ");
    read_line(msg, MSG_LEN);

    reverse(msg);
    printf("Reversal is: %s\n", msg);

    return 0;
}

void reverse(char *message)
{
    char ch, *p;

    for (p = message; *p; p++)
        ;

    for (; message < --p; message++) {
        ch = *message;
        *message = *p;
        *p = ch;
    }
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
        str[i++] = ch;
    str[i] = '\0';
    return i;
}
