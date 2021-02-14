/* Reverses the compression on a run-length encoded file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXT_LEN  4
#define ENCODING "rle"

int main(int argc, char *argv[])
{
	FILE *source_fp, *dest_fp;
	int ch, len, n;

	if (argc != 2) {
		fprintf(stderr, "usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((source_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	n = strlen(argv[1]);
	if (n < EXT_LEN || strcmp(&argv[1][n - EXT_LEN + 1], ENCODING) != 0) {
		fprintf(stderr, "Error: encoding not recognized\n");
		fclose(source_fp);
		exit(EXIT_FAILURE);
	}

	argv[1][n - EXT_LEN] = '\0';
	if ((dest_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		fclose(source_fp);
		exit(EXIT_FAILURE);
	}

	while ((len = getc(source_fp)) != EOF) {
		ch = getc(source_fp);
		while (len--)
			putc(ch, dest_fp);
	}

	fclose(source_fp);
	fclose(dest_fp);
	return 0;
}
