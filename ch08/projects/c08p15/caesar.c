#include <stdio.h>

#define MAX_MESSAGE 80

int main(void)
{
    char ch, message[MAX_MESSAGE];
    int i, n;

    printf("Enter message to be encrypted: ");
    for (i = 0; i < MAX_MESSAGE && (message[i++] = getchar()) != '\n';)
        ;

    printf("Enter shift amount (1-25): ");
    scanf("%d", &n);
        
    printf("Encrypted message: ");
    for (i = 0; i < MAX_MESSAGE && (ch = message[i++]) != '\n';)
        if ('A' <= ch && ch <= 'Z')
            putchar(((ch-'A') + n) % 26 + 'A');
        else if ('a' <= ch && ch <= 'z')
            putchar(((ch-'a') + n) % 26 + 'a');
        else
            putchar(ch);
    putchar('\n');

    return 0;
}
