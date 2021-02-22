#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 60

int main(int argc, char *argv[])
{
	FILE *fp;
	char line[MAX_LINE_LEN];
	int area_code, prefix, line_number;

	if (argc != 2) {
		fprintf(stderr, "usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, MAX_LINE_LEN, fp) != NULL)
		if (sscanf(line, "%d.%d.%d", &area_code, &prefix, &line_number) == 3 ||
		    sscanf(line, "(%d)%d-%d", &area_code, &prefix, &line_number) == 3 ||
		    sscanf(line, "%d-%d-%d", &area_code, &prefix, &line_number) == 3 ||
		    sscanf(line, "%3d%3d%4d", &area_code, &prefix, &line_number) == 3)
			printf("(%d) %d-%d\n", area_code, prefix, line_number);
		else
			fprintf(stderr, "Phone number not in the proper format\n");
		
	fclose(fp);
	return 0;
}
