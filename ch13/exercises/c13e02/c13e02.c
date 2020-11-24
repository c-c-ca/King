#include <stdio.h>

int main(void)
{
    char *p = "abc";

//  putchar(p);  /* WRONG: p is a pointer to a char, not a char */
    putchar(*p); /* CORRECT: prints "a" */
    puts(p);     /* CORRECT: prints "abc" */
//  puts(*p);    /* WRONG: *p is a char, not a pointer to char */

    return 0;
}
