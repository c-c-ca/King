#include <stdio.h>
#include <ctype.h>

#define SENTENCE_LEN 100

int main(void)
{
    char sentence[SENTENCE_LEN], *p, *start, *stop, *end;

    printf("Enter a sentence: ");
    for (p = sentence;
         p < sentence + SENTENCE_LEN && (*p = getchar()) != '\n';
         p++)
        ;

    if ((end = p) < sentence + SENTENCE_LEN || !isalnum(*(p - 1)))
        end--;

    printf("Reversal of sentence: ");
    for (stop = end; stop > sentence; stop = start - 1) {
        /* find start of current word */
        for (p = stop - 1; p > sentence && *(p - 1) != ' '; --p)
            ;
        start = p;

        /* print current word */
        while (p < stop)
            putchar(*p++);

        if (start > sentence)
            putchar(' ');
    }

    if (end < sentence + SENTENCE_LEN)
        putchar(*end);
    putchar('\n');

    return 0;
}
