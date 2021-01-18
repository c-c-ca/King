#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

char *words[MAX_WORDS];

int compare_strings(const void *p, const void *q);
int read_line(char str[], int n);
    
int main(void)
{
    char word[MAX_WORD_LEN+1];
    int i, len, num_words = 0;

    for (;;) {
        if (num_words == MAX_WORDS) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter word: ");
        if ((len = read_line(word, MAX_WORDS)) == 0)
            break;
        
        if ((words[num_words] = malloc(len + 1)) == NULL) {
            printf("-- No space left --\n");
            break;
        }

        strcpy(words[num_words], word);
        num_words++;
    }

    qsort(words, sizeof(words[0]), num_words, compare_strings);

    printf("In sorted order:");
    for (i = 0; i < num_words; i++)
        printf(" %s", words[i]);
    printf("\n");
}

int compare_strings(const void *p, const void *q)
{
    return strcmp(*(char **)p, *(char **)q);
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
