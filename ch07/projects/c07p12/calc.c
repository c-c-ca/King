#include <stdio.h>

int main(void)
{
    float f, val;
    char op;

    printf("Enter an expression: ");

    scanf("%f", &val);
    
    while ((op = getchar()) != '\n') {
        scanf("%f", &f);
        switch (op) {
            case '+':
                val += f; break;
            case '-':
                val -= f; break;
            case '*':
                val *= f; break;
            case '/':
                val /= f; break;
        }
    }

    printf("Value of expression: %.1f\n", val);

    return 0;
}