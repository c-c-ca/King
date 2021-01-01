#include <stdio.h>

#define PRINT_COMPLEX(x) printf("Value of " #x ": real = %g, imaginary = %g\n", x.real, x.imaginary)

struct complex {
    double real;
    double imaginary;
};

struct complex make_complex(double real, double imaginary);
struct complex add_complex(struct complex real, struct complex imaginary);

int main(void)
{
    struct complex c1, c2, c3;

    c1 = make_complex(0.0, 1.0);
    c2 = make_complex(1.0, 0.0);

    c3 = add_complex(c1, c2);

    PRINT_COMPLEX(c1);
    PRINT_COMPLEX(c2);
    PRINT_COMPLEX(c3);

    return 0;
}

struct complex make_complex(double real, double imaginary)
{
    struct complex c;

    c.real = real;
    c.imaginary = imaginary;

    return c;
}

struct complex add_complex(struct complex c1, struct complex c2)
{
    struct complex c3;

    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;

    return c3;
}