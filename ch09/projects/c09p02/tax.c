#include <stdio.h>

float income_tax(float amount);
int main(void)
{
    float amount, tax;

    printf("Enter an amount of taxable income: ");
    scanf("%f", &amount);
    printf("Tax due: $%.2f\n", income_tax(amount));

    return 0;
}

float income_tax(float amount)
{
    int tax;

    if (amount > 7000.00f)
        tax = 230.00f + 0.06f * (amount - 7000.00f);
    else if (amount > 5250.00f)
        tax = 142.50f + 0.05f * (amount - 5250.00f);
    else if (amount > 3750.00f)
        tax = 82.50f + 0.04f * (amount - 3750.00f);
    else if (amount > 2250.00f)
        tax = 37.50f + 0.03f * (amount - 2250.00f);
    else if (amount > 750.00f)
        tax = 7.50f + 0.02f * (amount - 750.00f);
    else
        tax = 0.01f * amount;

    return tax;
}
