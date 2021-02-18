#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int line_length(const char *filename, int n);
int main(int argc, char *argv[])
{
	int n;

	if (argc != 3) {
		fprintf(stderr, "usage: %s file n\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	sscanf(argv[2], "%d", &n);

	printf("Line %d in %s is %d characters long\n",
			n, argv[1], line_length(argv[1], n));

	return 0;
}

int line_length(const char *filename, int n)
{
	FILE *fp;
	int ch, len = 0;

	if ((fp = fopen(filename, "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(fp)) != EOF) {
		len++;
		if (ch == '\n')
			if (--n)
				len = 0;
			else
				break;
	}

	fclose(fp);
	return len;
}
