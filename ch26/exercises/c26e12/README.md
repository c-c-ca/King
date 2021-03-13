```c
time_t time_from_year(int year)
{
	struct tm t;

	t.tm_sec = 0;
	t.tm_min = 0;
	t.tm_hour = 0;
	t.tm_mday = 0;
	t.tm_mon = 1;
	t.tm_year = year - 1900;
	t.tm_isdst = -1;

	return mktime(&t);
}
```
