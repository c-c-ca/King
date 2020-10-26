#include <stdio.h>

#define DEPARTURE_1   ( 8 * 60)
#define DEPARTURE_2   ( 9 * 60 + 43)
#define DEPARTURE_3   (11 * 60 + 19)
#define DEPARTURE_4   (12 * 60 + 47)
#define DEPARTURE_5   (14 * 60)
#define DEPARTURE_6   (15 * 60 + 45)
#define DEPARTURE_7   (19 * 60)
#define DEPARTURE_8   (21 * 60 + 45)

#define MID_POINT_12  ((DEPARTURE_1 + DEPARTURE_2) / 2)
#define MID_POINT_23  ((DEPARTURE_2 + DEPARTURE_3) / 2)
#define MID_POINT_34  ((DEPARTURE_3 + DEPARTURE_4) / 2)
#define MID_POINT_45  ((DEPARTURE_4 + DEPARTURE_5) / 2)
#define MID_POINT_56  ((DEPARTURE_5 + DEPARTURE_6) / 2)
#define MID_POINT_67  ((DEPARTURE_6 + DEPARTURE_7) / 2)
#define MID_POINT_78  ((DEPARTURE_7 + DEPARTURE_8) / 2)

int main(void)
{
    int hours, minutes, minutes_since_midnight;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);

    minutes_since_midnight = hours * 60 + minutes;

    if (minutes_since_midnight <= MID_POINT_12)
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
    else if (minutes_since_midnight <= MID_POINT_23)
        printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
    else if (minutes_since_midnight <= MID_POINT_34)
        printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
    else if (minutes_since_midnight <= MID_POINT_45)
        printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
    else if (minutes_since_midnight <= MID_POINT_56)
        printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
    else if (minutes_since_midnight <= MID_POINT_67)
        printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
    else if (minutes_since_midnight <= MID_POINT_78)
        printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
    else
        printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");

    return 0;
}