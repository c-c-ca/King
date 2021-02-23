```c
double round_nearest(double x, int n)
{
	double power = pow(10.0, n);

	if (x < 0.0)
		return ceil(x * power - 0.5) / power;
	else
		return floor(x * power + 0.5) / power;
}
```
