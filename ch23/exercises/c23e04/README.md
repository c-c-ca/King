```c
bool legal_identifier(char *s)
{
	if (!isalpha(*s) && *s != '_')
		return false;

	while (*++s)
		if (!isalnum(*s) && *s != '_')
			return false;

	return true;
}
```
