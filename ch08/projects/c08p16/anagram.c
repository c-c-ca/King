#include <stdio.h>
#include <ctype.h>

#define NUM_LETTERS 26

int main(void)
{
    char ch;
    int i, letter_counts[NUM_LETTERS] = {0};

    printf("Enter first word: ");
    while (isalpha(ch = getchar()))
        letter_counts[tolower(ch) - 'a']++;

    printf("Enter second word: ");
    while (isalpha(ch = getchar()))
        letter_counts[tolower(ch) - 'a']--;

    for (i = 0; i < NUM_LETTERS; i++)
        if (letter_counts[i] != 0)
            break;

    if (i == NUM_LETTERS)
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");

    return 0;
}
