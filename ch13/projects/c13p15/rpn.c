#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
#define EXP_LEN    40

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
int evaluate_RPN_expression(const char *expression);
int read_line(char str[], int n);

int main(void)
{
    char expression[EXP_LEN];

    for (;;) {
        printf("Enter an RPN expression: ");
        read_line(expression, EXP_LEN);
        printf("Value of expression: %d\n", evaluate_RPN_expression(expression));
    }
}

int evaluate_RPN_expression(const char *expression)
{
    int op1, op2, val;

    do {
        if ('0' <= *expression && *expression <= '9')
            push(*expression - '0');
        else if (*expression == '+' || *expression == '-' ||
                 *expression == '*' || *expression == '/') {
            op2 = pop();
            op1 = pop();
            switch (*expression) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        } else if (*expression == ' ')
            continue;
        else
            exit(EXIT_FAILURE);
    } while (*++expression != '=');

    val = pop();
    make_empty();

    return val;
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

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
        str[i++] = ch;
    str[i] = '\0';
    return i;
}
