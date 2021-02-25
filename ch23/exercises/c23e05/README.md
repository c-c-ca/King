```c
long int string_to_hex(char *s)
{
	long int i = 0;

	if (*s == '0' && tolower(*(s + 1)) == 'x')
		s += 2;

	if (*s == '\0')
		return -1;
	
	for (; *s; s++)
		if (isdigit(*s))
			i = fma(i, 16, *s - '0');
		else if (isxdigit(*s))
			i = fma(i, 16, *s - (islower(*s) ? 'a' : 'A' ) + 10);
		else
			return -1;

	return i;
}
```
