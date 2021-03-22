#include <stdio.h>
#include <time.h>

void read_date(struct tm *tp, const char *msg);

int main(void)
{
	struct tm t1, t2;

	read_date(&t1, "Enter first date (mm/dd/yyyy): ");
	read_date(&t2, "Enter second date (mm/dd/yyyy): ");

	printf("\nDifference between dates: %g sec.\n",
	       difftime(mktime(&t2), mktime(&t1)));

	return 0;
}

void read_date(struct tm *tp, const char *msg)
{
	/* initialize unused members */
	tp->tm_sec = tp->tm_min = tp->tm_hour = 0;
	tp->tm_isdst = -1;

	printf("%s", msg);
	scanf("%d/%d/%d", &tp->tm_mon, &tp->tm_mday, &tp->tm_year);
	tp->tm_mon--;
	tp->tm_year -= 1900;
}
