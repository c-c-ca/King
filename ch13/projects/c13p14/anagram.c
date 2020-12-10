#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

#define NUM_LETTERS 26
#define WORD_LEN 20

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
    char word1[WORD_LEN+1], word2[WORD_LEN+1];

    printf("Enter first word: ");
    scanf("%s", word1);

    printf("Enter second word: ");
    scanf("%s", word2);

    if (are_anagrams(word1, word2))
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");

    return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
    int i, letter_counts[NUM_LETTERS] = {0};

    while (*word1)
        letter_counts[toupper(*word1++) - 'A']++;

    while (*word2)
        letter_counts[toupper(*word2++) - 'A']--;

    for (i = 0; i < NUM_LETTERS; i++)
        if (letter_counts[i] != 0)
            return false;

    return true;
}
