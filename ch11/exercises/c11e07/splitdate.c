#include <stdio.h>

void split_date(int day_of_year, int year,
                int *month, int *day);

int main(void)
{
    int day_of_year, year, month, day;

    printf("Enter day of year: ");
    scanf("%d", &day_of_year);
    printf("Enter year: ");
    scanf("%d", &year);

    split_date(day_of_year, year, &month, &day);

    printf("Month: %d\n", month);
    printf("Day: %d\n", day);

    return 0;
}

void split_date(int day_of_year, int year,
                int *month, int *day)
{
    int num_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    *day = day_of_year;
    for (*month = 1; *day > num_days[*month-1]; (*month)++) {
        if (year % 4 == 0 && *month == 2)
            if (*day > num_days[*month-1] + 1)
                (*day)--;
            else
                break;
        *day -= num_days[*month-1];
    }
}