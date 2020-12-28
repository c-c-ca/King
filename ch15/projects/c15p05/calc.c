#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
    char ch;
    int op1, op2;

    for (;;) {
        printf("Enter an RPN expression: ");

        do {
            scanf(" %c", &ch);
            if ('0' <= ch && ch <= '9')
                push(ch - '0');
            else if (ch == '+' || ch == '-' ||
                     ch == '*' || ch == '/') {
                op2 = pop();
                op1 = pop();
                switch (ch) {
                    case '+': push(op1 + op2); break;
                    case '-': push(op1 - op2); break;
                    case '*': push(op1 * op2); break;
                    case '/': push(op1 / op2); break;
                }
            } else if (ch != '=')
                exit(EXIT_SUCCESS);
        } while (ch != '=');

        printf("Value of expression: %d\n", pop());
        make_empty();
    }
}
