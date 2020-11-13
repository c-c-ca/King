#include <stdio.h>

void split_time(long total_sec, int *hr, int *min, int *sec);

int main(void)
{
    long total_sec;
    int hr, min, sec;

    printf("Enter the number of seconds since midnight: ");
    scanf("%ld", &total_sec);

    split_time(total_sec, &hr, &min, &sec);

    printf("Hour: %d\n", hr);
    printf("Minute: %d\n", min);
    printf("Second: %d\n", sec);

    return 0;
}

/**********************************************************
 * read_cards: Stores the number of hours, minutes, and   *
 *             seconds since midnight in the objects      *
 *             pointed to by hr, min, and sec.            *
***********************************************************/
void split_time(long total_sec, int *hr, int *min, int *sec)
{
    *hr = total_sec / 3600;
    *min = total_sec / 60 % 60;
    *sec = total_sec % 60;
}
