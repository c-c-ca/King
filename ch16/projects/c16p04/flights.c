#include <stdio.h>

#define FLIGHT_COUNT (sizeof(times) / sizeof(times[0]))

#define PRINT_TIME(x)                         \
    printf("%d:%.2d %s",                      \
            12 - ((12 - (x) / 60 % 12) % 12), \
            (x) % 60,                         \
            (x) < 720 ? "a.m." : "p.m.");

struct flight { int departure_time, arrival_time; };

const struct flight times[] = {{480, 616},
                               {583, 712},
                               {679, 811},
                               {767, 900},
                               {840, 968},
                               {945, 1075},
                               {1140, 1280},
                               {1305, 1438}};

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int main(void)
{
    int hours, minutes, total_minutes;
    int departure_time, arrival_time;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);

    total_minutes = hours * 60 + minutes;

    find_closest_flight(total_minutes, &departure_time, &arrival_time);

    printf("Closest departure time is ");
    PRINT_TIME(departure_time);
    printf(", arriving at ");
    PRINT_TIME(arrival_time);
    printf("\n");
}

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
    int i;

    for (i = 0;
         i < FLIGHT_COUNT - 1 &&
         desired_time > (times[i].departure_time + times[i+1].departure_time) / 2;
         i++)
        ;

    *departure_time = times[i].departure_time;
    *arrival_time = times[i].arrival_time;
}
