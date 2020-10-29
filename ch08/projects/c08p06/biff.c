#include <stdio.h>
#include <ctype.h>

#define SIZE   100
#define NUM_EM 10

int main(void)
{
    char ch, message[SIZE];
    int i;

    printf("Enter message: ");

    for (i = 0; (ch = getchar()) != '\n' && i < SIZE-1;)
        message[i++] = ch;

    message[i] = '\n';

    printf("In B1FF-speak: ");
    for (i = 0; (ch = toupper(message[i++])) != '\n';)
        switch (ch) {
            case 'A':
                putchar('4'); break;
            case 'B':
                putchar('8'); break;
            case 'E':
                putchar('3'); break;
            case 'I':
                putchar('1'); break;
            case 'O':
                putchar('0'); break;
            case 'S':
                putchar('5'); break;
            default:
                putchar(ch); break;
        }
    printf("!!!!!!!!!!\n");

    return 0;
}