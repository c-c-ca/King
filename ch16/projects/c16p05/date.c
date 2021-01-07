#include <stdio.h>
#include <stdbool.h>

#define PRINT_DATE(x) printf("%d/%d/%.2d", (x).month, (x).day, (x).year)

#define PRINT_OUTPUT(x,y)            \
    do {                             \
        PRINT_DATE(x);               \
        printf(" is earlier than "); \
        PRINT_DATE(y);               \
        printf("\n");                \
    } while (0)

struct date { int month, day, year; };

int compare_dates(struct date d1, struct date d2);

int main(void)
{
    struct date d1, d2;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);

    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);

    if (compare_dates(d1, d2) < 0)
        PRINT_OUTPUT(d1, d2);
    else
        PRINT_OUTPUT(d2, d1);

    return 0;
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
