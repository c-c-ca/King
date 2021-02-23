#include <stdio.h>
#include <stdlib.h>

#define CR     '\x0d'
#define LF     '\x0a'
#define CTRL_Z '\x1a'

int main(int argc, char *argv[])
{
	FILE *in_fp, *out_fp;
	int ch;

	if (argc != 3) {
		fprintf(stderr, "usage: %s infile outfile\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((in_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((out_fp = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[2]);
		fclose(in_fp);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(in_fp)) != EOF && ch != CTRL_Z)
		if ((ch == CR && (ch = getc(in_fp)) != LF) || putc(ch, out_fp) == EOF) {
			fprintf(stderr, "Error during writing; %s terminated\n", argv[0]);
			exit(EXIT_FAILURE);
		}

	fclose(in_fp);
	fclose(out_fp);
	return 0;
}
