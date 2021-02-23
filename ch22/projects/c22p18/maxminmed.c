#include <stdio.h>
#include <stdlib.h>

#define N 10000
#define MEDIAN(a,n) (n % 2 == 0 ? ((a)[(n)/2-1] + (a)[(n)/2]) / 2 : (a)[(n)/2])

int cmp(const void *p, const void *q);

int main(int argc, char *argv[])
{
	FILE *fp;
	int a[N], i;

	if (argc != 2) {
		fprintf(stderr, "usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < N && fscanf(fp, "%d", &a[i]) == 1; i++)
		;

	qsort(a, i, sizeof(a[0]), cmp);

	printf("Maximum: %d, minimum: %d, median: %d\n", a[i-1], a[0], MEDIAN(a,i));

	fclose(fp);
	return 0;
}

int cmp(const void *p, const void *q)
{
	return *(const int *) p - *(const int *) q;
}
