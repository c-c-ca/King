#include <stdio.h>

#define PRINT_TIME(x) \
    printf("time: hours = %d, minutes = %d, seconds = %d\n", \
            x.hours, x.minutes, x.seconds)

struct time { int hours, minutes, seconds; };

struct time split_time(long total_seconds);

int main(void)
{
    long total_seconds;
    struct time t;

    printf("Enter number of seconds: ");
    scanf("%d", &total_seconds);

    t = split_time(total_seconds);

    PRINT_TIME(t);

    return 0;
}

struct time split_time(long total_seconds)
{
    struct time t;

    t.hours = total_seconds / 3600;
    total_seconds %= 3600;

    t.minutes = total_seconds / 60;
    total_seconds %= 60;

    t.seconds = total_seconds;

    return t;
}
