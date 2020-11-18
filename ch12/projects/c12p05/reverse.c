#include <stdio.h>
#include <ctype.h>

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
    for (; p >= sentence; p = q) {
        while (--p >= sentence && *p != ' ')
            ;
        q = p;

        while (++p < end && *p != ' ')
            putchar(*p);

        while (q >= sentence && *q == ' ')
            putchar(*q--);
    }

    if (end < sentence + SENTENCE_LEN)
        putchar(*end);
    putchar('\n');

    return 0;
}
