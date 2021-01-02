#include <stdio.h>

#define PRINT_DATE(x) printf("%d-%d-%d", x.year, x.month, x.day)

struct date {
    int month;
    int day;
    int year;
};

int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);

int main(void)
{
    struct date d1, d2;

    printf("Enter month: ");
    scanf("%d", &d1.month);
    printf("Enter day: ");
    scanf("%d", &d1.day);
    printf("Enter year: ");
    scanf("%d", &d1.year);

    printf("Day of year: %d\n", day_of_year(d1));

    printf("Enter month: ");
    scanf("%d", &d2.month);
    printf("Enter day: ");
    scanf("%d", &d2.day);
    printf("Enter year: ");
    scanf("%d", &d2.year);

    printf("Day of year: %d\n", day_of_year(d2));

    if (compare_dates(d1, d2) < 0) {
        PRINT_DATE(d1);
        printf(" is earlier than ");
        PRINT_DATE(d2);
    } else {
        PRINT_DATE(d1);
        printf(" is not earlier than ");
        PRINT_DATE(d2);
    }

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

int compare_dates(struct date d1, struct date d2)
{
    if (d1.year != d2.year)
        return d1.year < d2.year ? -1 : 1;

    if (d1.month != d2.month)
        return d1.month < d2.month ? -1 : 1;

    if (d1.day != d2.day)
        return d1.day < d2.day ? -1 : 1;

    return 0;
}
