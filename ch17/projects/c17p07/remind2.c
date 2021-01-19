/* Prints a one-month reminder list */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */

struct vstring {
    int len;
    char chars[];       /* flexible array member - C99 only */
};

int read_line(char str[], int n);
void print_vstring(struct vstring *str);

int main(void)
{
    struct vstring *reminders[MAX_REMIND];
    char day_str[3], msg_str[MSG_LEN+1];
    int day, i, j, n, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        if (day == 0)
            break;
        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++)
            if (strncmp(day_str, reminders[i]->chars, reminders[i]->len) < 0)
                break;
        for (j = num_remind; j > i; j--)
            reminders[j] = reminders[j-1];

        n = 2 + strlen(msg_str);
        reminders[i] = malloc(sizeof(struct vstring) + n + 1);
        if (reminders[i] == NULL) {
            printf("-- No space left --\n");
            break;
        }

        reminders[i]->len = n;
        strncpy(reminders[i]->chars, day_str, 2);
        strncat(reminders[i]->chars, msg_str, n - 2);

        num_remind++;
    }

    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++) {
        putchar(' ');
        print_vstring(reminders[i]);
        putchar('\n');
    }

    return 0;
}

void print_vstring(struct vstring *str)
{
    int i = 0;

    while (i < str->len)
        putchar(str->chars[i++]);
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
