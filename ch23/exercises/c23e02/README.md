```c
double evaluate_polynomial(double a[], int n, double x)
{
	double value = a[n];

	while (n)
		value = fma(value, x, a[--n]);

	return value;
}
```
