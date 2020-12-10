#include <stdio.h>

#define MAX_WORDS 30
#define WORD_LEN  20

int main(void)
{
    char ch, sentence[MAX_WORDS][WORD_LEN+1];
    int i, j;
    
    printf("Enter a sentence: ");
    for (i = j = 0; i < MAX_WORDS && (ch = getchar()) != '.' && ch != '!' && ch != '?';)
        if (ch == ' ' && j > 0) {
            sentence[i++][j] = '\0';
            j = 0;
        } else if (j < WORD_LEN)
            sentence[i][j++] = ch;
    sentence[i][j] = '\0';

    printf("Reversal of sentence:");
    while (i >= 0)
        printf(" %s", sentence[i--]);
    printf("%c\n", ch);

    return 0;
}
