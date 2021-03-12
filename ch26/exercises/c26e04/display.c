#include <stdio.h>
#include <stdarg.h>

void display(int n, ...);

int main(void)
{
	display(4, "Special", "Agent", "Dale", "Cooper");
	return 0;
}

void display(int n, ...)
{
	va_list ap;

	va_start(ap, n);

	while (n--)
		printf("%s%c", va_arg(ap, char *), n > 0 ? ' ' : '\n');

	va_end(ap);
}
