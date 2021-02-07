#include <stdio.h>

#define SHIFT_BIT 1
#define CTRL_BIT  2
#define ALT_BIT   4

int main(void)
{
    int key_code = 8;
    
#ifdef WRONG
    /* The relational operators have higher precedence than bitwise shift operators. */
    if (key_code & (SHIFT_BIT | CTRL_BIT | ALT_BIT) == 0)
        printf("No modifier keys pressed\n");
#endif

#ifdef CORRECT
    if ((key_code & (SHIFT_BIT | CTRL_BIT | ALT_BIT)) == 0)
        printf("No modifier keys pressed\n");
#endif

    return 0;
}
