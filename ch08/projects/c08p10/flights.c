#include <math.h>
#include <stdio.h>

#define NUM_FLIGHTS (sizeof(departures) / sizeof(departures[0]))

int main(void)
{
    const int departures[] = {480, 583, 679, 767, 840, 945, 1140, 1305},
              arrivals[] = {616, 712, 811, 900, 968, 1075, 1280, 1438};
    int i, hours, minutes, minutes_since_midnight;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);

    minutes_since_midnight = hours * 60 + minutes;

    for (i = 0; 
         i < NUM_FLIGHTS - 1 && 
         minutes_since_midnight > (departures[i] + departures[i+1]) / 2;
         i++)
        ;
 
    printf("Closest departure time is %d:%.2d ",
        12 - (12 - departures[i] / 60 % 12) % 12, departures[i] % 60);
    if (departures[i] < 720)
        printf("a.m.");
    else
        printf("p.m.");

    printf(", arriving at %d:%.2d ",
        12 - (12 - arrivals[i] / 60 % 12) % 12, arrivals[i] % 60);
    if (arrivals[i] < 720)
        printf("a.m.\n");
    else
        printf("p.m.\n");

    return 0;
}
