#include <ctype.h>
#include <stdio.h>

#define SENTENCE_LEN 80

double compute_average_word_length(const char *sentence);
int read_line(char str[], int n);

int main(void)
{
    char sentence[SENTENCE_LEN+1];

    printf("Enter a sentence: ");
    read_line(sentence, SENTENCE_LEN);
    printf("Average word length: %.1f", compute_average_word_length(sentence));

    return 0;
}

double compute_average_word_length(const char *sentence)
{
    char ch;
    int num_words = 0;
    int num_letters = 0;

    while (ch = *sentence++)
        if (ch != ' ') {
            num_letters++;
            if (*sentence == ' ' || *sentence == '\0')
                num_words++;
        }

    return (double) num_letters / num_words;
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
