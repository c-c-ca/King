```c
int numchar(const char *s, char ch)
{
	int count = 0;

	for (; (s = strchr(s, ch)) != NULL; s++)
		count++;

	return count;
}
```
