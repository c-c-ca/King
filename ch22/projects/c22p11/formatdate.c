#include <stdio.h>
#include <stdlib.h>

const char *month_names[] = {"January", "February", "March", 
	                     "April", "May", "June",
			     "July", "August", "September", 
			     "October", "November", "December"};

int main(int argc, char *argv[])
{
	int day, month, year;

	if (argc != 2) {
		fprintf(stderr, "usage %s date\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (sscanf(argv[1], "%d/%d/%d", &month, &day, &year) == 3 ||
	    sscanf(argv[1], "%d-%d-%d", &month, &day, &year) == 3)
		if (1 <= month && month <= 12) {
			printf("%s %d, %d\n", month_names[month-1], day, year);
			return 0;
		} else {
			fprintf(stderr, "Error: illegal date\n");
			exit(EXIT_FAILURE);
		}

	fprintf(stderr, "Date not in the proper form\n");
	exit(EXIT_FAILURE);
}
