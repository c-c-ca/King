#include <stdio.h>

int main(void)
{
    printf("%d\n", 077);   /* prints "63" */
    printf("%d\n", 0x77);  /* prints "119" */
    printf("%d\n", 0XABC); /* prints "2748" */

    return 0;
}