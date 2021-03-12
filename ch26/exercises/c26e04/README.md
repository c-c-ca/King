```c
void display(int n, ...)
{
	va_list ap;

	va_start(ap, n);

	while (n--)
		printf("%s%c", va_arg(ap, char *), n > 0 ? ' ' : '\n');

	va_end(ap);
}
```
