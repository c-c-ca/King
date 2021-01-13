#include <stdio.h>

int main(void)
{
    struct {
        union {
            char a, b;
            int c;
        } d;
        int e[5];
    } f, *p = &f;

    /* a */
//  p->b = ' ';      /* WRONG */

    /* b */
    p->e[3] = 10;    /* CORRECT */

    /* c */
    (*p).d.a = '*';  /* CORRECT */

    /* d */
//  p->d->c = 20;    /* WRONG */

    return 0;
}
