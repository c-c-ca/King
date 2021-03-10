```c
void int_str_printf(char *format, ...)
{
	va_list ap;
	char *p, *q;
	int i, power, temp;

	va_start(ap, format);

	for (p = format; *p != '\0'; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}

		if (*++p == 'd') {
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
		} else if (*p == 's')
			for (q = va_arg(ap, char *); *q != '\0'; q++)
				putchar(*q);
	}

	va_end(ap);
}
```
