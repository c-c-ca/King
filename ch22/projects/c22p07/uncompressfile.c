/* Reverses the compression on a run-length encoded file */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int ch, len;

	if (argc != 2) {
		printf("usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "rb")) == NULL) {
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((len = getc(fp)) != EOF) {
		ch = getc(fp);
		while (len--)
			putchar(ch);
	}

	return 0;
}
