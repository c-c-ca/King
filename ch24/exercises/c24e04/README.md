### (a)
```c
double try_math_fcn(double (*f)(double), double x, char *msg)
{
	double result;

	errno = 0;
	result = (*f)(x);
	if (errno != 0) {
		perror(msg);
		exit(EXIT_FAILURE);
	}
	return result;
}
```

### (b)
```c
#define TRY_MATH_FCN(f,x) try_math_fcn((f), (x), "Error in call of " #f)
```
