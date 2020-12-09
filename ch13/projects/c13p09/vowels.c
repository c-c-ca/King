#include <stdio.h>
#include <ctype.h>

#define SENTENCE_LEN 80

int compute_vowel_count(const char *sentence);
int read_line(char str[], int n);

int main(void)
{
    char sentence[SENTENCE_LEN+1];

    printf("Enter a sentence: ");
    read_line(sentence, SENTENCE_LEN);
    printf("Your sentence contains %d vowels.\n", compute_vowel_count(sentence));

    return 0;
}

int compute_vowel_count(const char *sentence)
{
    int count = 0;

    while (*sentence != '\0')
        switch (tolower(*sentence++)) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                count++; break;
        }

    return count;
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
