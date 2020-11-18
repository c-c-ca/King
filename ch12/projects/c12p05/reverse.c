#include <stdio.h>

#define SENTENCE_LEN 100

int main(void)
{
    char sentence[SENTENCE_LEN], *p, *q, *end;

    printf("Enter a sentence: ");
    for (p = sentence;
         p < sentence + SENTENCE_LEN &&
         (*p = getchar()) != '.' && *p != '?' && *p != '!';
         p++)
        ;
    end = p;

    printf("Reversal of sentence: ");
    while (p > sentence) {
        /* find beginning of word */
        while (p > sentence && *(p - 1) != ' ')
            p--;

        /* print word */
        for (q = p; q < end && *q != ' '; q++)
            putchar(*q);

        /* find end of next word */
        while (p > sentence && *(p - 1) == ' ')
            putchar(*--p);
    }

    if (end < sentence + SENTENCE_LEN)
        putchar(*end);
    putchar('\n');

    return 0;
}
