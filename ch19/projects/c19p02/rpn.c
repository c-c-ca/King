#include <stdbool.h>
#include <stdio.h>
#include "stackADT.h"

int main(void)
{
    Stack s;
    char ch;
    int op1, op2;

    s = create();

    for (;;) {
        printf("Enter an RPN expression: ");

        do {
            scanf(" %c", &ch);
            if ('0' <= ch && ch <= '9')
                push(s, ch - '0');
            else if (ch == '+' || ch == '-' ||
                     ch == '*' || ch == '/') {
                op2 = pop(s);
                op1 = pop(s);
                switch (ch) {
                    case '+': push(s, op1 + op2); break;
                    case '-': push(s, op1 - op2); break;
                    case '*': push(s, op1 * op2); break;
                    case '/': push(s, op1 / op2); break;
                }
            } else if (ch != '=') {
                destroy(s);
                return 0;
            }
        } while (ch != '=');

        printf("Value of expression: %d\n", pop(s));
        make_empty(s);
    }
}
