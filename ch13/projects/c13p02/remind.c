/* Prints a one-month reminder list */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */

int num_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool illegal_date(int month, int day);
int day_of_year(int month, int day);
int read_line(char str[], int n);

int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN+1];
    char day_str[6], time_str[13], msg_str[MSG_LEN+1], period1_str[3], period2_str[3];
    int month1, month2, day1, day2, hour1, hour2, minute1, minute2;
    int i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter month, day, time, and reminder: ");
        scanf("%2d", &month1);
        if (month1 == 0)
            break;
        scanf("/%2d %2d:%2d %2s", &day1, &hour1, &minute1, period1_str);
        if (illegal_date(month1, day1)) {
            printf("Reminder ignored; illegal date\n");
            continue;
        }

        sprintf(day_str, "%2d/%-2d", month1, day1);
        sprintf(time_str, "%3d:%0.2d %2s", hour1, minute1, period1_str);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++) {
            sscanf(reminders[i], "%2d/%2d %2d:%2d %2s", &month2, &day2, &hour2, &minute2, period2_str);

            if (day_of_year(month1, day1) < day_of_year(month2, day2))
                break;
            if (day_of_year(month1, day1) > day_of_year(month2, day2))
                continue;

            if (strcmp(period1_str, period2_str) < 0)
                break;

            if (hour1 < hour2)
                break;
            if (hour1 > hour2)
                continue;

            if (minute1 < minute2)
                break;
        }
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);

        strcpy(reminders[i], day_str);
        strcat(reminders[i], time_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nDay       Time    Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);

    return 0;
}

bool illegal_date(int month, int day)
{
    return month < 1 || month > 12 || day < 1 || day > num_days[month-1];
}

int day_of_year(int month, int day)
{
    int day_count = 0, i;

    for (i = 1; i < month; i++)
        day_count += num_days[i-1];

    return day_count + day;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
        str[i++] = ch;
    str[i] = '\0';
    return i;
}
