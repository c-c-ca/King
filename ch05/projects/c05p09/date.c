#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int month1, day1, year1, month2, day2, year2;
    bool first_date_is_earlier;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month1, &day1, &year1);

    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month2, &day2, &year2);

    if (year1 != year2)
        first_date_is_earlier = year1 < year2;
    else if (month1 != month2)
        first_date_is_earlier = month1 < month2;
    else
        first_date_is_earlier = day1 < day2;

    if (first_date_is_earlier)
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",
            month1, day1, year1, month2, day2, year2);
    else
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n",
            month2, day2, year2, month1, day1, year1);

    return 0;
}
