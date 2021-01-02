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
    struct fraction f1 = {1, 2}, f2 = {3, 4}, f3;

    f3 = add_fraction(f1, f2);
    PRINT_FRACTION(f3);

    f3 = subtract_fraction(f1, f2);
    PRINT_FRACTION(f3);

    f3 = multiply_fraction(f1, f2);
    PRINT_FRACTION(f3);

    f3 = divide_fraction(f1, f2);
    PRINT_FRACTION(f3);

    return 0;
}

int gcd(int m, int n)
{
    return n == 0 ? m : gcd(n, m % n);
}

struct fraction reduce_fraction(struct fraction f)
{
    int divisor = gcd(f.numerator, f.denominator);

    return (struct fraction) {f.numerator / divisor, f.denominator / divisor};
}

struct fraction add_fraction(struct fraction f1, struct fraction f2)
{
    return reduce_fraction((struct fraction) {
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

struct fraction subtract_fraction(struct fraction f1, struct fraction f2)
{
    return reduce_fraction((struct fraction) {
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

struct fraction multiply_fraction(struct fraction f1, struct fraction f2)
{
    return reduce_fraction((struct fraction) {
            f1.numerator * f2.numerator,
            f1.denominator * f2.denominator
    });
}

struct fraction divide_fraction(struct fraction f1, struct fraction f2)
{
    return reduce_fraction((struct fraction) {
            f1.numerator * f2.denominator,
            f1.denominator * f2.numerator
    });
}
