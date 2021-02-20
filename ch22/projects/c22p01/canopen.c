/* Checks whether a file can be opened for reading */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char **p;
    bool can_open = true;

    if (argc <= 1) {
        fprintf(stderr, "usage: canopen filename1 [filename2 ...]\n");
        exit(EXIT_FAILURE);
    }

    for (p = argv; *++p != NULL;)
        if ((fp = fopen(*p, "r")) == NULL) {
            printf("%s can't be opened\n", *p);
            can_open = false;
        } else {
            printf("%s can be opened\n", *p);
            fclose(fp);
        }

    if (!can_open)
        exit(EXIT_FAILURE);

    return 0;
}
