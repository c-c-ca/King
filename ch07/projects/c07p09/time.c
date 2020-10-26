#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int hours, minutes;
    char ch;

    printf("Enter a 12-hour time: ");
    scanf("%d:%d %c", &hours, &minutes, &ch);

    if (tolower(ch) == 'p') {
        if (hours < 12)
            hours += 12;
    } else if (hours == 12)
        hours = 0;

    printf("Equivalent 24-hour time %d:%d\n", hours, minutes);

    return 0;
}