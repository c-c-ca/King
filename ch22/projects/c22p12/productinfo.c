#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 60

int main(int argc, char *argv[])
{
	FILE *fp;
	char line[MAX_LINE];
	float price;
	int item, month, day, year;

	if (argc != 2) {
		fprintf(stderr, "usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("\nItem\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
	while (fgets(line, MAX_LINE, fp) != NULL) {
		sscanf(line, "%d,%f,%d/%d/%d", &item, &price, &month, &day, &year);
		printf("%d\t\t$% 7.2f\t%d/%d/%d\n", item, price, month, day, year);
	}

	fclose(fp);
	return 0;
}
