### (a)
```c
char *string_dup(const char *s)
{
	char *p, *q;

	if ((p = malloc(sizeof(s))) == NULL) {
		fprintf(stderr, "Error: malloc failed in string_dup\n");
		exit(EXIT_FAILURE);
	}

	for (q = p; *q++ = *s++;)
		;

	return p;
}
```

### (b)
```c
int string_icmp(const char *s1, const char *s2)
{
	char ch1, ch2;

	for (; (ch1 = tolower(*s1)) == (ch2 = tolower(*s2)); s1++, s2++)
		if (ch1 == '\0')
			break;

	return ch1 - ch2;
}
```

### (c)
```c
char *string_lwr(char *s)
{
	char *p = s;

	while (*p = tolower(*p))
		p++;

	return s;
}
```

### (d)
```c
char *string_rev(char *s)
{
	char temp, *p = s, *q = s;

	while (*p)
		p++;

	for (p--; q < p; p--, q++) {
		temp = *q;
		*q = *p;
		*p = temp;
	}

	return s;
}
```

### (e)
```c
char *string_set(char *s, char ch)
{
	char *p = s;

	while (*p)
		*p++ = ch;

	return s;
}
```
