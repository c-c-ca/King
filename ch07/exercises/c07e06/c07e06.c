#include <stdio.h>

int main(void)
{
    char days_in_month = 31;
    short days_in_year = 366;
    short minutes_in_day = 60 * 24;
    int seconds_in_day = 60 * minutes_in_day;

    printf("%d\n", days_in_month);
    printf("%d\n", days_in_year);
    printf("%d\n", minutes_in_day);
    printf("%d\n", seconds_in_day);

    return 0;
}