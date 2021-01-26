#include <stdio.h>
#include "stack.h"

int main(void)
{
    Stack s1 = NULL, s2 = NULL;

    make_empty(&s1);
    make_empty(&s2);
    push(&s1, 1);
    push(&s2, 2);
    if (!is_empty(&s1))
        printf("%d\n", pop(&s1));   /* prints "1" */

    return 0;
}
