#include <stdio.h>

#define PRINT(x) printf("Value of " #x ": %g\n", x)

int main(void)
{
    struct {
        double imaginary;
        double real;
    } c1 = { 0.0, 1.0 }, 
      c2 = { 1.0, 0.0 }, 
      c3;

    c1 = c2;

    c3.imaginary = c1.imaginary + c2.imaginary;
    c3.real = c1.real + c2.real;

    PRINT(c3.imaginary);
    PRINT(c3.real);

    return 0;
}
