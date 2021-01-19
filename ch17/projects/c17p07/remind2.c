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
int compare_vstring(struct vstring *str, char *p);
void copy_vstring(struct vstring *str, char *p);
void cat_vstring(struct vstring *str, char *p, int start);
void copy_vstring(struct vstring *str, char *p);
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
            if (compare_vstring(reminders[i], day_str) < 0)
                break;
        for (j = num_remind; j > i; j--)
            reminders[j] = reminders[j-1];

        n = strlen(msg_str) + 2;
        reminders[i] = malloc(sizeof(struct vstring) + n);
        if (reminders[i] == NULL) {
            printf("-- No space left --\n");
            break;
        }

        reminders[i]->len = n;
        copy_vstring(reminders[i], day_str);
        cat_vstring(reminders[i], msg_str, 2);

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

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
        str[i++] = ch;
    str[i] = '\0';
    return i;
}

void copy_vstring(struct vstring *str, char *p)
{
    int i = 0;

    while (i < str->len)
        str->chars[i++] = *p++;
}

void cat_vstring(struct vstring *str, char *p, int start)
{
    while (start < str->len && *p)
        str->chars[start++] = *p++;
}

int compare_vstring(struct vstring *str, char *p)
{
    int i = 0;

    while (i < str->len && *p)
        if (str->chars[i++] != *p++)
            return str->chars[i] - *p;

    return 0;
}

void print_vstring(struct vstring *str)
{
    int i = 0;

    while (i < str->len)
        putchar(str->chars[i++]);
}
