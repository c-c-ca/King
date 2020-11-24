#include <stdio.h>

#define SENTENCE_LEN 50

int count_spaces(const char *p);
int read_line(char str[], int n);

int main(void)
{
    char sentence[SENTENCE_LEN];

    printf("Enter a sentence: ");
    read_line(sentence, SENTENCE_LEN);

    printf("Number of spaces: %d\n", count_spaces(sentence));
    return 0;
}

int count_spaces(const char *s)
{
    int count = 0;

    while (*s)
        if (*s++ == ' ')
            count++;
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
