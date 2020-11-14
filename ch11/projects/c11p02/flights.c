#include <stdio.h>

#define NUM_FLIGHTS (sizeof(departures) / sizeof(departures[0]))

int departures[] = {480, 583, 679, 767, 840, 945, 1140, 1305};
int arrivals[] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

void find_closest_flight(int desired_time,
                         int *departure_time,
                         int *arrival_time);
void print_time(int total_min);

int main(void)
{
    int hours, minutes, total_min;
    int departure_time, arrival_time;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);

    total_min = hours * 60 + minutes;

    find_closest_flight(total_min, &departure_time, &arrival_time);

    printf("Closest departure time is ");
    print_time(departure_time);
    printf(", arriving at ");
    print_time(arrival_time);
    printf("\n");

    return 0;
}

void find_closest_flight(int desired_time,
                         int *departure_time,
                         int *arrival_time)
{
    int i;

    for (i = 0;
         i < NUM_FLIGHTS - 1 &&
         desired_time > (departures[i] + departures[i+1]) / 2;
         i++)
        ;

    *departure_time = departures[i];
    *arrival_time = arrivals[i];
}

void print_time(int total_min)
{
    int hr, min;

    hr = 12 - (12 - total_min / 60 % 12) % 12;
    min = total_min % 60;

    printf("%d:%.2d ", hr, min);

    if (total_min < 720)
        printf("a.m.");
    else
        printf("p.m.");
}
