#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define MSG_LEN 80    /* maximum length of message */

bool is_palindrome(const char *message);
int read_line(char str[], int n);

int main(void)
{
    char msg[MSG_LEN+1];


    printf("Enter a message: ");
    read_line(msg, MSG_LEN);

    if (is_palindrome(msg))
        printf("Not a palindrome\n");
    else
        printf("Palindrome\n");

    return 0;
}

bool is_palindrome(const char *message)
{
    const char *p;

    for (p = message; *p; p++)
        ;

    for (--p; message < p;)
        if (!isalpha(*message))
            message++;
        else if (!isalpha(*p))
            p--;
        else if (tolower(*message++) != tolower(*p--))
            return false;

    return true;
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
