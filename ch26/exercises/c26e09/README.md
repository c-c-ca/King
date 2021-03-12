```c
double rand_double()
{
	int i;

	while ((i = rand()) == RAND_MAX)
		;

	return (double) i / RAND_MAX;
}
```
