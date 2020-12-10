#include <stdio.h>

#define MSG_LEN 80

void encrypt(char *message, int shift);

int main(void)
{
    char message[MSG_LEN];
    int i, n;

    printf("Enter message to be encrypted: ");
    for (i = 0; i < MSG_LEN && (message[i++] = getchar()) != '\n';)
        ;

    printf("Enter shift amount (1-25): ");
    scanf("%d", &n);
        
    printf("Encrypted message: ");
    encrypt(message, n);

    return 0;
}

void encrypt(char *message, int shift)
{
    char ch;

    while ((ch = *message++) != '\n')
        if ('A' <= ch && ch <= 'Z')
            putchar(((ch-'A') + shift) % 26 + 'A');
        else if ('a' <= ch && ch <= 'z')
            putchar(((ch-'a') + shift) % 26 + 'a');
        else
            putchar(ch);
    putchar('\n');

}
