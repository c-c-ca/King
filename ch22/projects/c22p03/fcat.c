/* Concatenates any number of files by writing them to standard output */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    bool can_open = true;
    char **p;
    int ch;

    if (argc <= 1) {
        fprintf(stderr, "usage: fcat file1 [file2 ...]\n");
        exit(EXIT_FAILURE);
    }

    for (p = argv; *++p != NULL;)
        if ((fp = fopen(*p, "r")) == NULL) {
            fprintf(stderr, "Can't open %s\n", *p);
            can_open = false;
        } else {
            while ((ch = getc(fp)) != EOF)
                putchar(ch);
            fclose(fp);
        }

    if (!can_open)
        exit(EXIT_FAILURE);

    return 0;
}
