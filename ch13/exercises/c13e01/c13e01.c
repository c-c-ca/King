#include <stdio.h>

int main(void)
{
    printf("%c", '\n'); /* CORRECT */
//  printf("%c", "\n"); /* WRONG: second argument does not match format specifier */
//  printf("%s", '\n'); /* WRONG: second argument does not match format specifier */
    printf("%s", "\n"); /* CORRECT */
//  printf('\n');       /* WRONG: first argument should be of type char[] or *char */
    printf("\n");       /* CORRECT */
    putchar('\n');      /* CORRECT */
//  putchar("\n");      /* WRONG: first argument should be of type char */
//  puts('\n');         /* WRONG: first argument should be of type char[] or *char */
//  puts("\n");         /* WRONG: writes two newline characters instead of one */
    puts("");           /* CORRECT */

    return 0;
}
