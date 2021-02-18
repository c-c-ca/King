/* Counts periods in a file */

#include <stdio.h>
#include <stdlib.h>

int count_periods(const char *filename);
int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	printf("Number of periods in %s: %d\n", argv[1], count_periods(argv[1]));

	return 0;
}

int count_periods(const char *filename)
{
	FILE *fp;
	int ch, n = 0;

	if ((fp = fopen(filename, "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(fp)) != EOF)
		if (ch == '.')
			n++;

	fclose(fp);
	return n;
}
