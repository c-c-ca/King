#include <stdio.h>

#define GENERIC_MAX(type)       \
type type##_max(type x, type y) \
{                               \
    return x > y ? x : y;       \
}

typedef unsigned long ULONG;

int main(void)
{
    GENERIC_MAX(long);
    GENERIC_MAX(ULONG)
}

/**
 * 1. Expansion of GENERIC_MAX(long):
 *
 *    type long_max(long x, long y)
 *    {
 *        return x > y ? x : y;
 *    }
 */

/**
 * 2. Explain why GENERIC_MAX does not work for unsigned long.
 *
 *    The name of the function after stringization contains a space.
 */

/**
 * 3. Explain a technique that could be used with GENERIC_MAX that
 *    would allow us to use unsigned long.
 *
 *    A typedef may be used to define a type for unsigned long
 *    that does not contain a space, such as ULONG.
 */
