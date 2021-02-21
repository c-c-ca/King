#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_EXT ".enc"

int main(void)
{
	FILE *in_fp, *out_fp;
	char filename[FILENAME_MAX+1];
	int ch, n;
	
	printf("Enter name of file to be encrypted: ");
	scanf("%s", filename);

	if ((in_fp = fopen(filename, "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", filename);
		exit(EXIT_FAILURE);
	}
	
	if ((out_fp = fopen(strcat(filename, FILE_EXT), "w")) == NULL) {
		fprintf(stderr, "Can't open %s\n", filename);
		fclose(in_fp);
		exit(EXIT_FAILURE);
	}
	
	printf("Enter shift amount (1-25): ");
	scanf("%d", &n);

	while ((ch = getc(in_fp)) != EOF)
		if ('A' <= ch && ch <= 'Z')
			putc(((ch - 'A') + n) % 26 + 'A', out_fp);
		else if ('a' <= ch && ch <= 'z')
			putc(((ch - 'a') + n) % 26 + 'a', out_fp);
		else
			putc(ch, out_fp);

    fclose(in_fp);
    fclose(out_fp);
    return 0;
}
