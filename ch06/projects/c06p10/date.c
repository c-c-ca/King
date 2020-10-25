#include <stdio.h>

int main(void)
{
    int new_month, new_day, new_year, month, day, year;

    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    for (;;) {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d/%d/%d", &new_month, &new_day, &new_year);

        if (new_month == 0 && new_day == 0 && new_year == 0)
            break;

        if ((new_year < year) ||
            (new_year == year && new_month < month) ||
            (new_year == year && new_month == month && new_day < day)) {
            month = new_month;
            day = new_day;
            year = new_year;
        }
    }

    printf("%d/%d/%.2d is the earliest date", month, day, year);

    return 0;
}
