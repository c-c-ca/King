```c
void int_printf(char *format, ...)
{
	va_list ap;
	char *p;
	int i, power, temp;

	va_start(ap, format);

	for (p = format; *p != '\0'; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}

		if (*++p != 'd')
			continue;

		if ((i = va_arg(ap, int)) < 0) {
			putchar('-');
			i = -i;
		}

		for (temp = i, power = 1; 
		     temp > 9; 
		     temp /= 10, power *= 10)
			;

		do {
			putchar('0' + i / power);
			i %= power;
			power /= 10;
		} while (i > 0);
	}

	va_end(ap);
}
```
