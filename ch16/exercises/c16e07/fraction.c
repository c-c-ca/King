#include <stdio.h>

#define PRINT_FRACTION(x) printf("%d / %d\n", x.numerator, x.denominator)

struct fraction {
    int numerator;
    int denominator;
};

int gcd(int m, int n);
struct fraction reduce_fraction(struct fraction f);
struct fraction add_fraction(struct fraction f1, struct fraction f2);
struct fraction subtract_fraction(struct fraction f1, struct fraction f2);
struct fraction multiply_fraction(struct fraction f1, struct fraction f2);
struct fraction divide_fraction(struct fraction f1, struct fraction f2);

int main(void)
{
    struct fraction f, g, h;

    f.numerator = 1;
    f.denominator = 2;

    g.numerator = 3;
    g.denominator = 4;

    h = add_fraction(f, g);
    PRINT_FRACTION(h);

    h = subtract_fraction(f, g);
    PRINT_FRACTION(h);

    h = multiply_fraction(f, g);
    PRINT_FRACTION(h);

    h = divide_fraction(f, g);
    PRINT_FRACTION(h);

    return 0;
}

int gcd(int m, int n)
{
    return n == 0 ? m : gcd(n, m % n);
}

struct fraction reduce_fraction(struct fraction f)
{
    struct fraction g;
    int divisor;

    divisor = gcd(f.numerator, f.denominator);
    g.numerator = f.numerator / divisor;
    g.denominator = f.denominator / divisor;

    return g;
}

struct fraction add_fraction(struct fraction f1, struct fraction f2)
{
    struct fraction f3;

    f3.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    f3.denominator = f1.denominator * f2.denominator;

    return reduce_fraction(f3);
}

struct fraction subtract_fraction(struct fraction f1, struct fraction f2)
{
    struct fraction f3 = f2;
    
    f3.numerator *= -1;

    return add_fraction(f1, f3);
}

struct fraction multiply_fraction(struct fraction f1, struct fraction f2)
{
    struct fraction f3 = f1;

    f3.numerator *= f2.numerator;
    f3.denominator *= f2.denominator;

    return reduce_fraction(f3);
}

struct fraction divide_fraction(struct fraction f1, struct fraction f2)
{
    struct fraction f3;

    f3.numerator = f2.denominator;
    f3.denominator = f2.numerator;

    return multiply_fraction(f1, f3);
}
