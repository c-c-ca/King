#include <stdio.h>

struct date {
    int month;
    int day;
    int year;
};

int day_of_year(struct date d);

int main(void)
{
    struct date d;

    printf("Enter month: ");
    scanf("%d", &d.month);
    printf("Enter day: ");
    scanf("%d", &d.day);
    printf("Enter year: ");
    scanf("%d", &d.year);

    printf("Day of year: %d\n", day_of_year(d));

    return 0;
}

int day_of_year(struct date d)
{
    int num_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day_count = 0, i;

    for (i = 1; i < d.month; i++)
        day_count += num_days[i-1];

    /* adjust for leap years, assuming they are divisible by 4 */
    if (d.year % 4 == 0 && d.month > 2)
        day_count++;

    return day_count + d.day;
}
