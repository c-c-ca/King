#include <stdio.h>
#include <time.h>

#define SECONDS_PER_DAY 86400

void read_date(struct tm *ptr, const char *msg);

int main(void)
{
	struct tm t1, t2;

	read_date(&t1, "Enter first date (mm/dd/yyyy): ");
	read_date(&t2, "Enter second date (mm/dd/yyyy): ");

	printf("\nDifference between dates: %g days\n",
	       difftime(mktime(&t2), mktime(&t1)) / SECONDS_PER_DAY);

	return 0;
}

void read_date(struct tm *ptr, const char *msg)
{
	/* initialize unused members */
	ptr->tm_sec = ptr->tm_min = ptr->tm_hour = 0;
	ptr->tm_isdst = -1;

	printf("%s", msg);
	scanf("%d/%d/%d", &ptr->tm_mon, &ptr->tm_mday, &ptr->tm_year);
	ptr->tm_mon--;
	ptr->tm_year -= 1900;
}
