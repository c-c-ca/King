#include <stdio.h>
#include <ctype.h>

#define WORD_LEN 20

void capitalize(char str[]);
void capitalize(char *p);

int main(void)
{
    char word[WORD_LEN];

    printf("Enter a word: ");
    scanf("%s", word);

    capitalize(word);

    printf("Capitalized: %s\n", word);

    return 0;
}

/* (a) */
void capitalize(char str[])
{
    int i = 0;

    while ((str[i] = toupper(str[i])))
        i++;
}

/* (b) */
void capitalize(char *p)
{
    while ((*p = toupper(*p)))
        p++;
}
