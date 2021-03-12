```c
void display(int n, ...)
{
	va_list ap;

	va_start(ap, n);

	while (n--)
		printf(n > 0 ? "%s " : "%s\n", va_arg(ap, char *));

	va_end(ap);
}
```
