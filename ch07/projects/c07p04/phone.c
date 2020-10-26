#include <stdio.h>

int main(void)
{
    char ch;

    printf("Enter phone number: ");
    
    while ((ch = getchar()) != '\n')
        if ('A' <= ch && ch <= 'Z')
            putchar('2' + (ch - 'A') / 3);
        else
            putchar(ch);

    putchar('\n');

    return 0;
}