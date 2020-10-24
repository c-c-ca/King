/** 
 *  (c) is not equivalent to (a) and (b) because the body
 *  of the do-while statement will always be executed at
 *  least once.
 */

#include <stdio.h>

int main(void)
{
    int i;

    i = 10;
    while (i < 10)
        printf("%d ", i++);  /* branch is not entered */
    printf("\n");

    i = 10;
    for (; i < 10;)
        printf("%d ", i++);  /* branch is not entered */
    printf("\n");

    i = 10;
    do {
        printf("%d ", i++);  /* prints "10" */
    } while (i < 10);
    printf("\n");

    return 0;
}
