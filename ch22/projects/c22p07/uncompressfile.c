/* Reverses the compression on a run-length encoded file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 20
#define EXT_LEN  3
#define FMT_LEN  10

#define ENCODING "rle"

int main(int argc, char *argv[])
{
	FILE *source_fp, *dest_fp;
	int ch, len;
	char file_name[NAME_LEN+1], file_ext[EXT_LEN+1], fmt_str[FMT_LEN+1];

	if (argc != 2) {
		fprintf(stderr, "usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((source_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	sprintf(fmt_str, "%%%lds.%%3s", strlen(argv[1]) - 4);
	sscanf(argv[1], fmt_str, file_name, file_ext);
	if (strcmp(file_ext, ENCODING) != 0) {
		fprintf(stderr, "Error: %s encoding not recognized\n", file_ext);
		fclose(source_fp);
		exit(EXIT_FAILURE);
	}

	if ((dest_fp = fopen(file_name, "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", file_name);
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
