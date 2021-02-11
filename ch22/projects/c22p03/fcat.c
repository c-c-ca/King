/* Concatenates any number of files by writing them to standard output */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    bool cannot_open = false;
    char ch, **p;

    if (argc <= 1) {
        printf("usage: fcat filename1 [filename2 ...]\n");
        exit(EXIT_FAILURE);
    }

    for (p = argv; *++p != NULL;)
        if ((fp = fopen(*p, "r")) == NULL) {
            printf("%s can't be opened\n", *p);
            cannot_open = true;
        } else
            while ((ch = getc(fp)) != EOF)
                putchar(ch);

    if (cannot_open)
        exit(EXIT_FAILURE);

    fclose(fp);
    return 0;
}
