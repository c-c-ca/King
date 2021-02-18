### (a)
```c
char *fget_string(char *s, int n, FILE *stream)
{
	int ch, len = 0;

	while (len < n - 1 && (ch = fgetc(stream)) != EOF)
		if ((s[len++] = ch) == '\n')
			break;

	if (len == 0 || ferror(stream))
		return NULL;

	s[len] == '\0';
	return s;
}
```

### (b)
```c
int fput_string(const char *s, FILE *stream)
{
	while (*s)
		if (fputc(*s++, stream) == EOF)
			return EOF;

	return 0;
}
```
