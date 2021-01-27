#include <stdbool.h>
#include <stdio.h>
#include "stackADT.h"

int main(void)
{
    char ch;
    bool is_nested_properly = true;
    Stack s = create();

    printf("Enter parentheses and/or braces: ");
    while ((ch = getchar()) != '\n')
        if (ch == '(' || ch == '{')
            push(s, ch);
        else if ((ch == ')' && pop(s) != '(') ||
                 (ch == '}' && pop(s) != '{')) {
            is_nested_properly = false;
            break;
        }
    
    if (is_nested_properly && is_empty(s))
        printf("Parentheses/braces are nested properly\n");
    else
        printf("Parentheses/braces are not nested properly\n");

    destroy(s);
        
    return 0;
}
