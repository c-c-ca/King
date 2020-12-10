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
    for (; *message; message++)
        if ('A' <= *message && *message <= 'Z')
            putchar(((*message-'A') + shift) % 26 + 'A');
        else if ('a' <= *message && *message <= 'z')
            putchar(((*message-'a') + shift) % 26 + 'a');
        else
            putchar(*message);
}
