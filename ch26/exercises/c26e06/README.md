```c
char *max_pair(int num_pairs, ...)
{
	va_list ap;
	char *str, *temp;
	int current, largest;
	
	va_start(ap, num_pairs);

	largest = va_arg(ap, int);
	str = va_arg(ap, char *);
	while (--num_pairs) {
		current = va_arg(ap, int);
		temp = va_arg(ap, char *);
		if (current > largest) {
			largest = current;
			str = temp;
		}
	}

	va_end(ap);

	return str;
}
```
