/* Performs XOR encryption */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char *argv[])
{
    FILE *input_fp, *output_fp;
    int ch;

    if (argc != 3) {
        fprintf(stderr, "usage: %s input output\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((input_fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((output_fp = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        fclose(input_fp);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(input_fp)) != EOF)
        putc(ch ^ KEY, output_fp);

    fclose(input_fp);
    fclose(output_fp);
    return 0;
}
