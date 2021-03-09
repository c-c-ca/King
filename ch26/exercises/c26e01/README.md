```c
int max_int(int n, ...)
{
	va_list ap;
	int current, largest = n;

	va_start(ap, n);

	while ((current = va_arg(ap, int)) != 0)
		if (current > largest)
			largest = current;

	va_end(ap);
	return largest;
}
```
