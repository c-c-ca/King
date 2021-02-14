/* Compresses a file using run-length encoding */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ENCODING "rle"
#define NAME_LEN 20

int main(int argc, char *argv[])
{
    FILE *source_fp, *dest_fp;
    char file_name[NAME_LEN+1];
    int ch, last, len;

    if (argc != 2) {
        fprintf(stderr, "usage: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((source_fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    sprintf(file_name, "%s.%s", argv[1], ENCODING);
    if ((dest_fp = fopen(file_name, "wb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", file_name);
	fclose(source_fp);
        exit(EXIT_FAILURE);
    }

    for (len = 0;; len++) {
	    ch = getc(source_fp);
	    if (len > 0 && ch != last) {
		    putc(len, dest_fp);
		    putc(last, dest_fp);
		    len = 0;
	    }

	    if (ch == EOF)
		    break;

	    last = ch;
    }

    fclose(source_fp);
    fclose(dest_fp);
    return 0;
}
