#include <stdio.h>

#define MSG_LEN 80

void encrypt(char *message, int shift);
int read_line(char str[], int n);

int main(void)
{
    char message[MSG_LEN];
    int i, n;

    printf("Enter message to be encrypted: ");
    read_line(message, MSG_LEN);

    printf("Enter shift amount (1-25): ");
    scanf("%d", &n);
        
    encrypt(message, n);
    printf("Encrypted message: %s", message);

    return 0;
}

void encrypt(char *message, int shift)
{
    for (; *message; message++)
        if ('A' <= *message && *message <= 'Z')
            *message = ((*message-'A') + shift) % 26 + 'A';
        else if ('a' <= *message && *message <= 'z')
            *message = ((*message-'a') + shift) % 26 + 'a';
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
