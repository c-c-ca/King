#include <stdio.h>

int main(void)
{
    enum {FALSE, TRUE} b;
    int i;

    /* a */
    b = FALSE;     /* LEGAL, SAFE */

    /* b */
    b = i;         /* LEGAL, NOT SAFE */

    /* c */
    b++;           /* LEGAL, NOT SAFE */

    /* d */
    i = b;         /* LEGAL, SAFE */

    /* e */
    i = 2 * b + 1; /* LEGAL, SAFE */
}
