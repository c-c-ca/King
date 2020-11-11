#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
void stack_underflow(void);
void stack_overflow(void);

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

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(int i)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = i;
}

int pop(void)
{
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}

void stack_underflow(void)
{
    printf("Stack underflow\n");
    exit(EXIT_FAILURE);
}

void stack_overflow(void)
{
    printf("Expression is too complex\n");
    exit(EXIT_FAILURE);
}
