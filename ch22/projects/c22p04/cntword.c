/* Counts the number of words in a text file */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    bool in_word = false;
    int ch, count = 0;

    if (argc != 2) {
        fprintf(stderr, "usage: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF)
        if (isspace(ch))
            in_word = false;
        else if (!in_word) {
            in_word = true;
            count++;
        }

    printf("There are %d words in %s\n", count, argv[1]);

    fclose(fp);
    return 0;
}
