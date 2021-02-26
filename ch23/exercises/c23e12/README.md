```c
int main(void)
{
	char str[] = "HELLO world";

	printf("%s\n", string_dup("hello world"));

	if (string_icmp("hello world", "helLo WOrld") == 0)
		printf("Words are the same\n");
	else
		printf("Words are NOT the same\n");

	string_set(str, 's');
	printf("%s\n", string_rev(str));

	return 0;
}
```

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

```c
int string_icmp(const char *s1, const char *s2)
{
	char ch1, ch2;

	for (; (ch1 = tolower(*s1)) == (ch2 = tolower(*s2)); s1++, s2++)
		if (ch1 == '\0')
			return 0;

	return ch1 - ch2;
}
```

```c
char *string_lwr(char *s)
{
	char *p;

	for (p = s; *p = tolower(*p); p++)
		;

	return s;
}
```

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

```c
char *string_set(char *s, char ch)
{
	char *p = s;

	while (*p)
		*p++ = ch;

	return s;
}
```
