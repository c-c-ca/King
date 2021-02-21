#include <stdio.h>
#include <stdlib.h>

#define MAX_FLIGHTS 8
#define MAX_LINE    25

#define PRINT_TIME(x)                          \
	printf("%d:%.2d %s",                   \
	       12 - (12 - (x) / 60 % 12) % 12, \
	       (x) % 60,                       \
	       (x) < 720 ? "a.m" : "p.m");

struct flight { int departure_time, arrival_time; } flights[MAX_FLIGHTS];

int num_flights = 0;

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);
void load_flights(const char *filename);

int main(int argc, char *argv[])
{
    int hours, minutes, departure_time, arrival_time;

    if (argc != 2) {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    load_flights(argv[1]);

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);

    find_closest_flight(hours * 60 + minutes, &departure_time, &arrival_time);

    printf("Closest departure time is ");
    PRINT_TIME(departure_time);
    printf(", arriving at ");
    PRINT_TIME(arrival_time);
    printf("\n");

    return 0;
}

void load_flights(const char *filename)
{
	FILE *fp;
	char line[MAX_LINE];
	int dep_hours, dep_minutes, arr_hours, arr_minutes;
	
	if ((fp = fopen(filename, "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", filename);
		exit(EXIT_FAILURE);
	}
	
	for (; num_flights < MAX_FLIGHTS && fgets(line, MAX_LINE, fp) != NULL; num_flights++) {
		if (sscanf(line, "%d:%d%d:%d", &dep_hours, &dep_minutes, &arr_hours, &arr_minutes) != 4) {
		    fprintf(stderr, "Can't read %s\n", filename);
		    exit(EXIT_FAILURE);
		}
		flights[num_flights].departure_time = dep_hours * 60 + dep_minutes;
		flights[num_flights].arrival_time = arr_hours * 60 + arr_minutes;
	}
	
	fclose(fp);
}

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
	int i;

	for (i = 0;
	     i < num_flights - 1 &&
	     desired_time > (flights[i].departure_time + flights[i+1].departure_time) / 2;
	     i++)
		;
	
	*departure_time = flights[i].departure_time;
	*arrival_time = flights[i].arrival_time;
}
