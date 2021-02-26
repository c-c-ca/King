```c
int count_words(char *sentence)
{
	int count = 0;

	while (strtok(count == 0 ? sentence : NULL, " \t\r\n\v\f") != NULL)
		count++;

	return count;
}
```
