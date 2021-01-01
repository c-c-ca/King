#include <stdio.h>

#define PRINT_COMPLEX(x) printf("Value of " #x ": real = %g, imaginary = %g\n", x.real, x.imaginary)

typedef struct complex {
    double real;
    double imaginary;
} Complex;

Complex make_complex(double real, double imaginary);
Complex add_complex(Complex real, Complex imaginary);

int main(void)
{
    Complex c1, c2, c3;

    c1 = make_complex(0.0, 1.0);
    c2 = make_complex(1.0, 0.0);

    c3 = add_complex(c1, c2);

    PRINT_COMPLEX(c1);
    PRINT_COMPLEX(c2);
    PRINT_COMPLEX(c3);

    return 0;
}

Complex make_complex(double real, double imaginary)
{
    Complex c;

    c.real = real;
    c.imaginary = imaginary;

    return c;
}

Complex add_complex(Complex c1, Complex c2)
{
    Complex c3;

    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;

    return c3;
}
