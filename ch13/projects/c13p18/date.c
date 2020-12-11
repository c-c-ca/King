#include <stdio.h>

int main(void)
{
    int month, day, year;
    const char *month_names[] = {"January", "February", "March", "April", "May", "June",
                                 "July", "August", "September", "November", "December"};

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%2d/%2d/%4d", &month, &day, &year);
    printf("You entered the date %s %d, %d", month_names[month-1], day, year);

    return 0;
}
