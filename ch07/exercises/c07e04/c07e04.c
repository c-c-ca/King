#include <stdio.h>

int main(void)
{
    char c;
    int i;

    i = 0;
    c = 'a';
    i += c;         /* legal   */

    c = 2 * c - 1;  /* legal   */

    putchar(c);     /* legal   */

//  printf(c);      /* illegal */

    return 0;
}
