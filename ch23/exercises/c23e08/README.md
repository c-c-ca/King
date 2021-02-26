```c
int numchar(const char *s, char ch)
{
	int count = 0;

	while ((s = strchr(s + 1, ch)) != NULL)
		count++;

	return count;
}
```
