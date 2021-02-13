/* Compresses a file using run-length encoding */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE * fp;
    int ch, last, len;

    if (argc != 2) {
        fprintf(stderr, "usage: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    for (len = 0;; len++) {
	    ch = getc(fp);
	    if (len > 0 && ch != last) {
		    putchar(len);
		    putchar(last);
		    len = 0;
	    }

	    if (ch == EOF)
		    break;

	    last = ch;
    }

    fclose(fp);
    return 0;
}
