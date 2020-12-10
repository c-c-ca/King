#include <stdio.h>

#define MSG_LEN 80

void encrypt(char *message, int shift);
int read_line(char str[], int n);

int main(void)
{
    char message[MSG_LEN];
    int i, n;

    printf("Enter message to be encrypted: ");
    read_line(msg, MSG_LEN);

    printf("Enter shift amount (1-25): ");
    scanf("%d", &n);
        
    printf("Encrypted message: ");
    encrypt(message, n);

    return 0;
}

void encrypt(char *message, int shift)
{
    char ch;

    while (ch = *message++)
        if ('A' <= ch && ch <= 'Z')
            putchar(((ch-'A') + shift) % 26 + 'A');
        else if ('a' <= ch && ch <= 'z')
            putchar(((ch-'a') + shift) % 26 + 'a');
        else
            putchar(ch);
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
