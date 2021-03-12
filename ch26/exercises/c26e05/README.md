```c
char *vstrcat(const char *first, ...)
{
	char *p, *str;
	int len;
	va_list ap;

	va_start(ap, first);

	for (len = strlen(first);
	     (p = va_arg(ap, char *)) != NULL;
	     len += strlen(p))
		;

	va_end(ap);

	if ((str = malloc(len + 1)) == NULL)
		return NULL;

	va_start(ap, first);

	for (strcpy(str, first);
	     (p = va_arg(ap, char *)) != NULL;
	     strcat(str, p))
		;

	va_end(ap);

	return str;
}
```
