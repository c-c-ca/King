#include <stdio.h>

int main(void)
{
    char c = '\1';
    short s = 2;
    int i = -3;
    long m = 5;
    float f = 6.5f;
    double d = 7.5;

    printf("%d\n", c * i);    /* prints "-3"    - int    */
    printf("%ld\n", s + m);   /* prints "7"     - long   */
    printf("%.2f\n", f / c);  /* prints "6.50"  - float  */
    printf("%.2f\n", d / s);  /* prints "3.75"  - double */
    printf("%.2f\n", f - d);  /* prints "-1.00" - double */
    printf("%d\n", (int) f);  /* prints "6"     - int    */



    return 0;
}